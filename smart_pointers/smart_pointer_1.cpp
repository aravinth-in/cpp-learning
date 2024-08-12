#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

class DatabaseConnection {
public:
    DatabaseConnection(const std::string& dbName) : dbName(dbName) {
        std::cout << "Connecting to database: " << dbName << "\n";
    }

    ~DatabaseConnection() {
        std::cout << "Disconnecting from database: " << dbName << "\n";
    }

    void query(const std::string& sql) {
        std::lock_guard<std::mutex> lock(mutex_);
        std::cout << "Executing query on " << dbName << ": " << sql << "\n";
    }

private:
    std::string dbName;
    std::mutex mutex_;
};

class Client {
public:
    // The dbConnection shared_ptr is copied into the dbConnection parameter, increasing the reference count by 1
    Client(std::shared_ptr<DatabaseConnection> dbConnection, const std::string& name)
        : dbConnection(dbConnection), name(name) {
        // The dbConnection shared_ptr is copied into the member variable dbConnection, increasing the reference count by 1
        std::cout << "Client " << name << " created. Database connection use_count: " << dbConnection.use_count() << "\n";
    }

    ~Client() {
        std::cout << "Client " << name << " destroyed. Database connection use_count: " << dbConnection.use_count() << "\n";
    }

    void performQuery(const std::string& sql) {
        std::cout << "Client " << name << " is performing a query. Database connection use_count: " << dbConnection.use_count() << "\n";
        dbConnection->query(sql);
    }

private:
    std::shared_ptr<DatabaseConnection> dbConnection;
    std::string name;
};

std::mutex globalMutex;

void simulateClientActivity(std::shared_ptr<DatabaseConnection> dbConnection, const std::string& clientName) {
    std::lock_guard<std::mutex> lock(globalMutex);
    std::cout << "Simulating client activity for " << clientName << ". Database connection use_count: " << dbConnection.use_count() << "\n";
    Client client(dbConnection, clientName);
    std::cout << "After Client Creation " << clientName << ". Database connection use_count: " << dbConnection.use_count() << "\n";
    client.performQuery("SELECT * FROM users");
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate some delay
    client.performQuery("UPDATE users SET name = 'John Doe' WHERE id = 1");
    // The Client object client goes out of scope and is destroyed. This decreases the reference count by 1.
    // The std::shared_ptr<DatabaseConnection> parameter dbConnection also goes out of scope and is destroyed. This decreases the reference count by 1 again.
}

int main() {
    std::shared_ptr<DatabaseConnection> dbConnection = std::make_shared<DatabaseConnection>("example_db");
    // The dbConnection shared_ptr is created here, reference count is 1
    std::cout << "Main function: Database connection use_count after creation: " << dbConnection.use_count() << "\n";

    std::vector<std::thread> clientThreads;
    for (int i = 1; i <= 5; ++i) {
        // The dbConnection shared_ptr is copied into each thread, increasing the reference count by 1 for each thread
        clientThreads.emplace_back(simulateClientActivity, dbConnection, "Client" + std::to_string(i));
    }

    for (auto& thread : clientThreads) {
        thread.join();
    }

    // After all threads are joined, the reference count should be back to 1
    std::cout << "Main function: Database connection use_count after threads: " << dbConnection.use_count() << "\n";

    return 0;
}