#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
int processed = 0;

void worker(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Thread " << id << " has acquired the lock and is in waiting state." << std::endl;
    cv.wait(lock, []{ return ready; });

    std::cout << "Thread " << id << " is processing." << std::endl;
    processed++;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "Thread " << id << " has finished processing." << std::endl;
}

void notify_threads() {
    std::cout << "Notifier thread: Sleeping for 1 second before starting notifications." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    for (int i = 0; i < 3; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = true;
            std::cout << "Notifier thread: Setting ready to true and notifying one thread." << std::endl;
        }
        cv.notify_one(); // Notify one waiting thread
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Small delay to observe the effect
    }
    std::cout << "Notifier thread: Finished notifying threads." << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(worker, i);
    }
    
    std::thread notifier(notify_threads);
    
    for (auto& thread : threads) {
        thread.join();
    }
    notifier.join();

    std::cout << "All threads have finished processing. Total processed: " << processed << std::endl;

    return 0;
}
