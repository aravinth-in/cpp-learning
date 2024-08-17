#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void incrementCounter() {
    for (int i = 0; i < 2; ++i) {
        // std::lock_guard: A simple mechanism to manage a mutex lock. It locks the mutex when created and unlocks it when destroyed.
        // std::lock_guard<std::mutex> lock(mtx);

        // std::unique_lock: More flexible than std::lock_guard, allows manual lock and unlock. If not manually unlocked, it will automatically unlock when it goes out of scope.
        std::unique_lock<std::mutex> lock(mtx);
        ++counter;
    }
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    // join(): The join method waits for the thread to finish its execution.
    // detach(): The detach method allows the thread to run independently from the main thread.
    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
