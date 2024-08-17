#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx1;
std::mutex mtx2;

void thread1() {
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Thread 1 locked mtx1" << std::endl;

    mtx2.lock();
    std::cout << "Thread 1 locked mtx2" << std::endl;

    std::cout << "Thread 1 is working" << std::endl;

    mtx2.unlock();
    std::cout << "Thread 1 unlocked mtx2" << std::endl;

    mtx1.unlock();
    std::cout << "Thread 1 unlocked mtx1" << std::endl;
}

void thread2() {
    mtx2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Thread 2 locked mtx2" << std::endl;

    mtx1.lock();
    std::cout << "Thread 2 locked mtx2" << std::endl;

    std::cout << "Thread 2 is working" << std::endl;

    mtx1.unlock();
    std::cout << "Thread 2 unlocked mtx1" << std::endl;

    mtx2.unlock();
    std::cout << "Thread 2 unlocked mtx2" << std::endl;
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
