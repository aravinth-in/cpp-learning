#include <iostream>
#include <thread>
#include <mutex>


void threadFunction1(std::mutex& mtx1, std::mutex& mtx2) {
    // Lock both mtx1 and mtx2 without risk of deadlock
    std::lock(mtx1, mtx2);
    // Create lock_guard to automatically release the mutex when it goes out of scope
    // std::adopt_lock tells std::lock_guard to assume the mutex is already locked
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock); 
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    std::cout << "Thread 1 has locked both mutexes" << std::endl;
}

void threadFunction2(std::mutex& mtx1, std::mutex& mtx2) {
    std::lock(mtx1, mtx2);
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    std::cout << "Thread 2 has locked both mutexes" << std::endl;
}

int main() {
    std::mutex mtx1, mtx2;

    std::thread t1(threadFunction1, std::ref(mtx1), std::ref(mtx2));
    std::thread t2(threadFunction2, std::ref(mtx1), std::ref(mtx2));

    t1.join();
    t2.join();

    return 0;
}
