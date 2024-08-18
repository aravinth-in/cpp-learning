#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Thread " << id << " has acquired the lock and is going to be in waiting state." << std::endl;

    // Each thread locks the mutex mtx and then calls cv.wait(lock, []{ return ready; });
    // Since ready is initially false, each thread releases the mutex mtx and enters a waiting state.

    // auto timeout_time = std::chrono::steady_clock::now() + std::chrono::seconds(2);
    // if(cv.wait_until(lock, timeout_time, []{ return ready; })) {

    if(cv.wait_for(lock, std::chrono::seconds(2), []{ return ready; })) {
        std::cout << "Thread " << id << " is now executing after being awakened." << std::endl;
    } else {
        std::cout << "Thread " << id << " timed out." << std::endl;
    }

    // All awakened threads (t1, t2, t3, etc...) attempt to re-acquire the lock.
    // The order in which the threads re-acquire the lock is not deterministic and depends on the thread scheduling by the operating system.
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
