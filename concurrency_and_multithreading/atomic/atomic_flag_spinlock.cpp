#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

class Spinlock {
public:
    // ATOMIC_FLAG_INIT initializes the atomic_flag to false, indicating that the lock is initially free.
    Spinlock() : flag(ATOMIC_FLAG_INIT) {}

    void lock() {
        while (flag.test_and_set(std::memory_order_acquire)) {
            // test_and_set sets the flag to true and returns the previous value.
            // If the previous value was true, it means the lock is already held by another thread,
            // so we keep spinning (busy-wait) until the flag is cleared (i.e., the lock is released).
        }
    }

    void unlock() {
        flag.clear(std::memory_order_release);
        // clear sets the flag to false, releasing the lock.
        // memory_order_release ensures that all memory writes in the critical section
        // are visible to other threads that acquire the lock afterwards.
    }

private:
    std::atomic_flag flag;
};

// Shared data
std::atomic<int*> atomic_ptr;
Spinlock spinlock;

void increment_shared_data() {
    for (int i = 0; i < 2; ++i) {
        spinlock.lock();
        (*atomic_ptr)++;
        spinlock.unlock();
    }
}

int main() {
    int shared_data = 0;
    atomic_ptr.store(&shared_data);

    std::vector<std::thread> threads;
    for (int i = 0; i < 2; ++i) {
        threads.emplace_back(increment_shared_data);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final shared data value: " << shared_data << std::endl;

    return 0;
}
