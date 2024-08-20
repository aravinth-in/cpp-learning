#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

/*
Atomic operations are indivisible steps(operation that runs to completion without being interrupted, ensuring consistency) 
crucial for avoiding race conditions in concurrent programming.
Memory ordering ensures consistent operation order across threads. std::atomic enforces this.
Atomic operations can avoid the overhead of locks, offering faster, lock-free data structures.
*/


//int counter = 0;
std::atomic<int> counter(0);

void increment(int numIncrements) {
    for (int i = 0; i < numIncrements; ++i) {
        // counter++; // Atomic increment operation, equivalent to counter.fetch_add(1), but with the default memory ordering of std::memory_order_seq_cst
        counter.fetch_add(1, std::memory_order_relaxed); // Explicit atomic addition with relaxed memory order
    }
}

int main() {
    const int numThreads = 10;
    const int numIncrements = 1000;

    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(increment, numIncrements);
    }

    for (auto& t : threads) {
        t.join();
    }

    // std::cout << "Final counter value: " << counter << std::endl;
    std::cout << "Final counter value: " << counter.load() << std::endl;
    
    return 0;
}
