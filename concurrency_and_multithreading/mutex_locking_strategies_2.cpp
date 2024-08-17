#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void defer_lock_example() {
    // Creates a unique_lock that does not lock the mutex mtx upon construction.
    // The lock can be acquired later using lock() method.
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    std::cout << "Defer lock: Doing some work before locking the mutex" << std::endl;
    lock.lock();
    std::cout << "Defer lock: Mutex is now locked" << std::endl;
    std::cout << "Defer lock: Doing some work with the mutex locked" << std::endl;
}

void try_to_lock_example() {
    // Creates a unique_lock that tries to lock the mutex mtx upon construction.
    // If the mutex is already locked, the lock will not be acquired.
    std::unique_lock<std::mutex> lock(mtx, std::try_to_lock);
    if (lock.owns_lock()) {
        std::cout << "Try to lock: Mutex is locked" << std::endl;
        std::cout << "Try to lock: Doing some work with the mutex locked" << std::endl;
    } else {
        std::cout << "Try to lock: Failed to lock the mutex" << std::endl;
    }
}

void adopt_lock_example() {
    mtx.lock();
    std::cout << "Adopt lock: Mutex is manually locked" << std::endl;
    // Creates a unique_lock that assumes the mutex mtx is already locked by the current thread.
    // This is useful when the mutex is locked before the unique_lock is created.
    std::unique_lock<std::mutex> lock(mtx, std::adopt_lock);
    std::cout << "Adopt lock: Doing some work with the mutex locked" << std::endl;
}

void adopt_lock_guard_example() {
    mtx.lock();
    std::cout << "Adopt lock_guard: Mutex is manually locked" << std::endl;
    // Creates a lock_guard that assumes the mutex mtx is already locked by the current thread.
    // This is useful when the mutex is locked before the lock_guard is created.
    std::lock_guard<std::mutex> lock(mtx, std::adopt_lock);
    std::cout << "Adopt lock_guard: Doing some work with the mutex locked" << std::endl;
}

int main() {
    std::thread t1(defer_lock_example);
    std::thread t2(try_to_lock_example);
    std::thread t3(adopt_lock_example);
    std::thread t4(adopt_lock_guard_example);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}


/*
Lock Types and Their Effects
| Type            | Used with               | Effect(s)                                                                                                                           |
|-----------------|-------------------------|-------------------------------------------------------------------------------------------------------------------------------------|
| unique_lock     | mutex, shared_mutex     | Locks the mutex `mtx` immediately upon construction.                                                                                |
| lock_guard      | mutex                   | Locks the mutex `mtx` immediately upon construction.                                                                                |
| shared_lock     | shared_mutex            | Allows multiple threads to acquire the lock concurrently for read-only access.                                                      |
| defer_lock_t    | unique_lock             | Does not lock the mutex `mtx` upon construction. The lock can be acquired later using `lock()` method.                              |
| try_to_lock_t   | unique_lock             | Tries to lock the mutex `mtx` upon construction. If the mutex is already locked, the lock will not be acquired.                     |
| adopt_lock_t    | unique_lock, lock_guard | Assumes the mutex `mtx` is already locked by the current thread. Useful when the mutex is locked before the lock object is created. |
*/
