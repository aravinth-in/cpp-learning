#include <iostream>
#include <map>
#include <mutex>
#include <string>

class ConfigurationManager{
private:
    static ConfigurationManager* configurationManagerInstance;
    static std::mutex mtx;
    static std::once_flag initInstanceFlag;
    std::map<std::string, std::string> config;

    ConfigurationManager(){
        config["db_host"] = "localhost";
        config["db_port"] = "3306";
        config["db_user"] = "root";
        config["db_password"] = "password";
        std::cout << "ConfigurationManager initialized with default settings." << std::endl;
    }

    ~ConfigurationManager() {
        std::cout << "ConfigurationManager instance destroyed." << std::endl;
    }

public:
    // Delete copy constructor and assignment operator to prevent copying
    ConfigurationManager(const ConfigurationManager&) = delete;
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;

    static ConfigurationManager* getInstance(){
        std::call_once(initInstanceFlag, [](){
            configurationManagerInstance = new ConfigurationManager();
        });
        return configurationManagerInstance;
    }

    void setValue(const std::string &key, const std::string &value){
        std::lock_guard<std::mutex> lock(mtx);
        config[key] = value;
    }

    std::string getValue(const std::string &key){
        std::lock_guard<std::mutex> lock(mtx);
        return config[key];
    }
};
