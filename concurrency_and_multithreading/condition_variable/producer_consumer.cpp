#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> buffer;
const unsigned int maxBufferSize = 2;
bool done = false;
int itemsProduced = 0;

void producer(int id) {
    for (int i = 0; i < 4; ++i) {
        std::unique_lock<std::mutex> lck(mtx);
        std::cout << "Producer " << id << " is going to be in wait state" << std::endl;
        cv.wait(lck, [] { return buffer.size() < maxBufferSize; });
        buffer.push(i);
        itemsProduced++;
        std::cout << "Producer " << id << " produced " << i << std::endl;
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::unique_lock<std::mutex> lck(mtx);
    done = true;
    std::cout << "Producer " << id << " is done producing" << std::endl;
    cv.notify_all();
}

void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        // The following condition is commented out to demonstrate the consumer's wait state behavior
        //if (buffer.empty() && !done) {
            std::cout << "Consumer " << id << " is going to be in wait state" << std::endl;
        //}
        cv.wait(lck, [] { return !buffer.empty() || done; });
        if (!buffer.empty()) {
            int item = buffer.front();
            buffer.pop();
            std::cout << "Consumer " << id << " consumed " << item << std::endl;
            cv.notify_all();
        } else if (done && buffer.empty() && itemsProduced == 8) {
            std::cout << "Consumer " << id << " is done consuming" << std::endl;
            break;
        }
        else {
            std::cout << "Consumer " << id << ": Buffer is empty and done is false, continuing to wait." << std::endl;
        }
    }
}

int main() {
    std::thread producers[2];
    std::thread consumers[2];

    for (int i = 0; i < 2; ++i) {
        producers[i] = std::thread(producer, i);
        consumers[i] = std::thread(consumer, i);
    }

    for (int i = 0; i < 2; ++i) {
        producers[i].join();
        consumers[i].join();
    }

    std::cout << "All threads have finished execution" << std::endl;

    return 0;
}
