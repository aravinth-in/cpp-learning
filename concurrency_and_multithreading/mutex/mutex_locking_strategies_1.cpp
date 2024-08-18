#include <iostream>
#include <thread>
#include <mutex>

// Ensures that the mutex is locked for the duration of the scoped block.
// Locks only one mutex, unlike std::scoped_lock which can lock multiple mutexes.
void lock_guard_example(std::mutex& mtx) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "std::lock_guard: Mutex is locked for the duration of this block.\n";
}

// Provides more flexibility than std::lock_guard, allowing deferred locking, timed locking, and manual unlocking.
void unique_lock_example(std::timed_mutex& mtx) {
    std::unique_lock<std::timed_mutex> lock(mtx);
    std::cout << "std::unique_lock: Mutex is locked for the duration of this block.\n";
    lock.unlock(); // Manual unlocking
    std::cout << "std::unique_lock: Mutex is manually unlocked.\n";
    lock.lock(); // Manual locking
    std::cout << "std::unique_lock: Mutex is manually locked again.\n";
}

// Locks multiple mutexes at once without the risk of deadlock.
void scoped_lock_example(std::mutex& mtx1, std::mutex& mtx2) {
    std::scoped_lock lock(mtx1, mtx2);
    std::cout << "std::scoped_lock: Both mutexes are locked for the duration of this block.\n";
}

// Locks multiple mutexes simultaneously to avoid deadlock.
void lock_example(std::mutex& mtx1, std::mutex& mtx2) {
    std::lock(mtx1, mtx2);
    std::cout << "std::lock: Both mutexes are locked.\n";
    mtx1.unlock();
    mtx2.unlock();
    std::cout << "std::lock: Both mutexes are unlocked.\n";
}

// Attempts to lock multiple mutexes without blocking.
void try_lock_example(std::mutex& mtx1, std::mutex& mtx2) {
    if (std::try_lock(mtx1, mtx2) == -1) {
        std::cout << "std::try_lock: Both mutexes are locked.\n";
        mtx1.unlock();
        mtx2.unlock();
        std::cout << "std::try_lock: Both mutexes are unlocked.\n";
    } else {
        std::cout << "std::try_lock: Failed to lock both mutexes.\n";
    }
}

// Demonstrates basic locking, trying to lock without blocking, and unlocking a mutex.
void mutex_member_functions_example(std::mutex& mtx) {
    mtx.lock();
    std::cout << "std::mutex::lock: Mutex is locked.\n";
    mtx.unlock();
    std::cout << "std::mutex::unlock: Mutex is unlocked.\n";

    if (mtx.try_lock()) {
        std::cout << "std::mutex::try_lock: Mutex is locked without blocking.\n";
        mtx.unlock();
        std::cout << "std::mutex::unlock: Mutex is unlocked.\n";
    } else {
        std::cout << "std::mutex::try_lock: Failed to lock mutex without blocking.\n";
    }
}

int main() {
    std::mutex mtx1, mtx2;
    std::timed_mutex tmtx;

    std::thread t1(lock_guard_example, std::ref(mtx1));
    std::thread t2(unique_lock_example, std::ref(tmtx));
    std::thread t3(scoped_lock_example, std::ref(mtx1), std::ref(mtx2));
    std::thread t4(lock_example, std::ref(mtx1), std::ref(mtx2));
    std::thread t5(try_lock_example, std::ref(mtx1), std::ref(mtx2));
    std::thread t6(mutex_member_functions_example, std::ref(mtx1));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    return 0;
}
