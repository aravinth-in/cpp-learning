// Refactoring to Achieve Loose Coupling

#include <iostream>
#include <string>

// Step 1: Use Interfaces
class ILogger{
public:
    virtual void log(const std::string& message) const = 0;
    virtual ~ILogger() = default;
};

// Step 2: Implement the Interface
class Logger: public ILogger {
public:
    void log(const std::string& message) const override {
        std::cout << "Log: " << message << std::endl;
    }
};

// Step 3: Use Dependency Injection
class DataService{
private:
    const ILogger& logger;
public:
    DataService(const ILogger& logger) : logger(logger){}

    void fetchData(){
        logger.log("Fetching data");
        // Fetch data logic
        std::cout << "Data fetched" << std::endl;
    }
};


int main(){ 
    Logger logger;
    DataService dataService(logger);
    dataService.fetchData();

    return 0;
}

/*
OUTPUT
Log: Fetching data
Data fetched
*/