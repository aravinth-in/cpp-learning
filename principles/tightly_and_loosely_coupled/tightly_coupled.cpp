#include <iostream>
#include <string>

class Logger {
public:
    void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};

class DataService {
private:
    Logger logger;
public:
    void fetchData() {
        logger.log("Fetching data");
        // Fetch data logic
        std::cout << "Data fetched" << std::endl;
    }
};

int main() {
    DataService dataService;
    dataService.fetchData();
    return 0;
}
