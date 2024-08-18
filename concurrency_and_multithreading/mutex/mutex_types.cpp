#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <vector>


void basic_mutex(std::mutex& mtx) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "std::mutex: Locked by thread " << std::this_thread::get_id() << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "std::mutex: Unlocked by thread " << std::this_thread::get_id() << "\n";
}

void timed_mutex(std::timed_mutex& tmtx) {
    // Attempt to acquire the lock within 100 milliseconds
    if (tmtx.try_lock_for(std::chrono::milliseconds(100))) {
        std::cout << "std::timed_mutex: Locked by thread " << std::this_thread::get_id() << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        tmtx.unlock();
        std::cout << "std::timed_mutex: Unlocked by thread " << std::this_thread::get_id() << "\n";
    } else {
        std::cout << "std::timed_mutex: Failed to lock by thread " << std::this_thread::get_id() << "\n";
    }
}

void nestedLockFunction(std::recursive_mutex& rmtx) {
    rmtx.lock();
    std::cout << "nestedLockFunction: Locked by thread " << std::this_thread::get_id() << "\n";
    rmtx.unlock();
    std::cout << "nestedLockFunction: Unlocked by thread " << std::this_thread::get_id() << "\n";
}

void recursive_mutex(std::recursive_mutex& rmtx) {
    rmtx.lock();
    std::cout << "recursive_mutex: Locked by thread " << std::this_thread::get_id() << "\n";
    nestedLockFunction(rmtx); // Calls another function that needs the same lock
    rmtx.unlock();
    std::cout << "recursive_mutex: Unlocked by thread " << std::this_thread::get_id() << "\n";
}

void shared_mutex_reader(std::shared_mutex& sharedMtx, const std::vector<int>& sharedData) {
    // Use std::shared_lock to allow multiple threads to read the shared data concurrently
    std::shared_lock<std::shared_mutex> lock(sharedMtx);
    std::cout << "Read lock acquired by thread " << std::this_thread::get_id() << "\n";
    for (const auto& data : sharedData) {
        std::cout << data << " ";
    }
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // For demonstration
    std::cout << "Read lock released by thread " << std::this_thread::get_id() << "\n";
}

void shared_mutex_writer(std::shared_mutex& sharedMtx, std::vector<int>& sharedData, int value) {
    // Use std::unique_lock to ensure exclusive access to the shared data for writing
    std::unique_lock<std::shared_mutex> lock(sharedMtx);
    std::cout << "Write lock acquired by thread " << std::this_thread::get_id() << "\n";
    sharedData.push_back(value);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // For demonstration
    std::cout << "Write lock released by thread " << std::this_thread::get_id() << "\n";
}

int main() {
    std::mutex mtx;
    std::timed_mutex tmtx;
    std::recursive_mutex rmtx;
    std::shared_mutex smtx;
    std::vector<int> sharedData;

    std::thread t1(basic_mutex, std::ref(mtx));
    std::thread t2(timed_mutex, std::ref(tmtx));
    std::thread t3(recursive_mutex, std::ref(rmtx));

    t1.join();
    t2.join();
    t3.join();

    std::thread t4(shared_mutex_writer, std::ref(smtx), std::ref(sharedData), 42);
    t4.join(); // Ensure t4 completes before starting t5
    std::thread t5(shared_mutex_reader, std::ref(smtx), std::ref(sharedData));
    t5.join(); // Ensure t5 completes before starting t6
    std::thread t6(shared_mutex_writer, std::ref(smtx), std::ref(sharedData), 84);
    t6.join(); // Ensure t6 completes before starting t7s
    std::thread t7(shared_mutex_reader, std::ref(smtx), std::ref(sharedData));
    t7.join(); // Ensure t7 completes before proceeding

    return 0;
}
