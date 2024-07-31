#include <iostream>
#include <mutex>

class Singleton{
    private:
    static Singleton* instance;
    static std::mutex mtx;

    Singleton(){};

    public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            std::lock_guard<std::mutex> lock(mtx);
                if(instance == nullptr){
                    instance = new Singleton();
                }
        }
        
        return instance;
    }

    void showMessage(){
        std::cout << "Singleton instance" << std::endl;
    }
    
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main(){
    Singleton* singletonObj = Singleton::getInstance();
    singletonObj->showMessage();
    return 0;
}

/*
OUTPUT
Singleton instance
*/
