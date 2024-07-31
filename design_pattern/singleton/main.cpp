#include <iostream>
#include <thread>

#include "configuration_manager.hpp"

// Initialize static members
ConfigurationManager* ConfigurationManager::configurationManagerInstance = nullptr;
std::mutex ConfigurationManager::mtx;
std::once_flag ConfigurationManager::initInstanceFlag;

void updateConfig(){
    auto configManager = ConfigurationManager::getInstance();
    configManager->setValue("app_mode", "production");
    std::cout << "Updated app_mode to production in thread " << std::this_thread::get_id() << std::endl;
}

void readConfig(){
    auto configManager = ConfigurationManager::getInstance();
    std::cout << "db_host: " << configManager->getValue("db_host") << " in thread " << std::this_thread::get_id() << std::endl;
    std::cout << "db_port: " << configManager->getValue("db_port") << " in thread " << std::this_thread::get_id() << std::endl;
    std::cout << "app_mode: " << configManager->getValue("app_mode") << " in thread " << std::this_thread::get_id() << std::endl;
}


int main(){
    std::thread t1(updateConfig);
    std::thread t2(readConfig);
    std::thread t3(readConfig);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

/*
OUTPUT
ConfigurationManager initialized with default settings.
db_host: localhost in thread 0x16f9c3000
db_host: Updated app_mode to production in thread 0x16f937000
localhost in thread 0x16fa4f000
db_port: db_port: 3306 in thread 0x16fa4f000
app_mode: production in thread 0x16fa4f000
3306 in thread 0x16f9c3000
app_mode: production in thread 0x16f9c3000
*/

/*
NOTE
-singleton instance is designed to exist for the entire duration of the program, its destructor is only called when the program terminates
*/