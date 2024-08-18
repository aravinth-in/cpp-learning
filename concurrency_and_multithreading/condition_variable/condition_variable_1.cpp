#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// Condition Variable: A synchronization primitive that allows threads to wait until a particular condition is met.
// Usage: Typically used with a mutex to protect shared data and a condition variable to signal changes in the state of the data.

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Thread " << id << " has acquired the lock and is going to be in waiting state." << std::endl;

    // Each thread locks the mutex mtx and then calls cv.wait(lock, []{ return ready; });
    // Since ready is initially false, each thread releases the mutex mtx and enters a waiting state.
    cv.wait(lock, []{ return ready; });

    // All awakened threads (t1, t2, t3, etc.) attempt to re-acquire the lock.
    // The order in which the threads re-acquire the lock is not deterministic and depends on the thread scheduling by the operating system.
    std::cout << "Thread " << id << " is now executing after being awakened." << std::endl;
}

void set_ready() {
    std::unique_lock<std::mutex> lock(mtx);
    ready = true;
    cv.notify_all(); // Notify all waiting threads
}

int main() {
    std::thread threads[10];
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(print_id, i);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    set_ready();

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}
