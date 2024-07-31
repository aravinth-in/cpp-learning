#include <iostream>
#include <mutex>

class Singleton{
    private:
    static Singleton* instance;
    static std::once_flag initializeInstanceFlag;

    Singleton(){};

    static void initializeSingleton(){
        instance = new Singleton();
    }

    public:
    static Singleton* getInstance(){
        std::call_once(initializeInstanceFlag, initializeSingleton);  
        return instance;
    }

    void showMessage(){
        std::cout << "Singleton instance" << std::endl;
    }
    
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::once_flag Singleton::initializeInstanceFlag;

int main(){
    Singleton* singletonObj = Singleton::getInstance();
    singletonObj->showMessage();

    return 0;
}

/*
OUTPUT
Singleton instance
*/
