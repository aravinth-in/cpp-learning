#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<int> counter(0);

void increment(int numIncrements) {
    for (int i = 0; i < numIncrements; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
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

    int value = counter.load();
    std::cout << "Counter value after increments: " << value << std::endl;

    int oldValue = counter.exchange(value + 500); // Exchange the value atomically
    std::cout << "Old counter value: " << oldValue << ", new counter value: " << counter.load() << std::endl;

    int expected = 10500;
    if (counter.compare_exchange_strong(expected, 20000)) {
        std::cout << "Compare and exchange succeeded, new counter value: " << counter.load() << std::endl;
    } else {
        std::cout << "Compare and exchange failed, expected: " << expected << ", actual: " << counter.load() << std::endl;
    }

    return 0;
}
