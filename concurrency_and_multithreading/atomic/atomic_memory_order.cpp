#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<int> data(0);
std::atomic<bool> ready(false);

void producer() {
    // Relaxed: No synchronization or ordering constraints. The store can be reordered with other operations.
    data.store(42, std::memory_order_relaxed);
 
    // Release: Ensures that all previous writes (to 'data') are visible to other threads before the write to 'ready'.
    ready.store(true, std::memory_order_release);
    std::cout << "Producer: Data produced and ready flag set." << std::endl;
}

void consumer() {
    // Acquire: Ensures that subsequent reads (of 'data') are not moved before the load of 'ready'.
    while (!ready.load(std::memory_order_acquire)) {
    }

    // Consume: Ensures that dependent reads (of 'data') are not moved before the load of 'data'.
    std::cout << "Consumer: Data consumed: " << data.load(std::memory_order_consume) << std::endl;
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();

    // Sequentially consistent: Ensures a total ordering of operations. All threads see the same order of operations.
    int value = data.load(std::memory_order_seq_cst);
    std::cout << "Main: Data value after consumer: " << value << std::endl;

    // Acquire-release: Ensures that the operation is both acquire and release. It synchronizes with both preceding and subsequent operations.
    int oldValue = data.exchange(value + 10, std::memory_order_acq_rel);
    std::cout << "Main: Old data value: " << oldValue << ", new data value: " << data.load(std::memory_order_relaxed) << std::endl;

    return 0;
}


/*
Memory Order            Ensures
-----------------------------------------------
memory_order_relaxed    No synchronization or ordering constraints
memory_order_release    All previous writes are visible before the write to the atomic variable
memory_order_acquire    Subsequent reads are not moved before the load
memory_order_consume    Dependent reads are not moved before the load
memory_order_seq_cst    Total ordering of operations
memory_order_acq_rel    Both acquire and release semantics
*/
