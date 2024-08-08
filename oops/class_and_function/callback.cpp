#include <iostream>
#include <functional>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>

// Scenario 1: Button Click Event using Function Pointer Callback

// Define a callback type
typedef void (*EventCallback)();

class Button {
private:
    EventCallback onClick;

public:
    void setOnClick(EventCallback callback) {
        onClick = callback;
    }

    void click() {
        if (onClick) {
            onClick();
        }
    }
};

void onButtonClick() {
    std::cout << "Button clicked!" << std::endl;
}

// Scenario 2: Asynchronous Operation using std::function Callback

void asyncOperation(std::function<void(int)> callback) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate long operation
    callback(42); // Call the callback with the result
}

void onOperationComplete(int result) {
    std::cout << "Operation completed with result: " << result << std::endl;
}

// Scenario 3: Custom Sort using std::function Callback

void customSort(std::vector<int>& vec, std::function<bool(int, int)> compare) {
    std::sort(vec.begin(), vec.end(), compare);
}

bool descending(int a, int b) {
    return a > b;
}

// Scenario 4: Processing Elements using std::function Callback

void processElements(const std::vector<int>& vec, std::function<void(int)> callback) {
    for (int elem : vec) {
        callback(elem);
    }
}


int main() {
    // Scenario 1
    std::cout << "Scenario 1: Button Click Event" << std::endl;
    Button button;
    button.setOnClick(onButtonClick);
    button.click();

    // Scenario 2
    std::cout << "\nScenario 2: Asynchronous Operation" << std::endl;
    std::cout << "Starting async operation..." << std::endl;
    std::thread t(asyncOperation, onOperationComplete);
    t.join(); // Wait for the thread to finish

    // Scenario 3
    std::cout << "\nScenario 3: Custom Sort" << std::endl;
    std::vector<int> numbers = {1, 4, 2, 8, 5, 7};
    customSort(numbers, descending);
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Scenario 4
    std::cout << "\nScenario 4: Processing Elements" << std::endl;
    std::vector<int> moreNumbers = {1, 2, 3, 4, 5};
    processElements(moreNumbers, [](int elem) {
        std::cout << "Processing element: " << elem << std::endl;
    });

    return 0;
}


/*
OUTPUT
Scenario 1: Button Click Event
Button clicked!

Scenario 2: Asynchronous Operation
Starting async operation...
Operation completed with result: 42

Scenario 3: Custom Sort
8 7 5 4 2 1 

Scenario 4: Processing Elements
Processing element: 1
Processing element: 2
Processing element: 3
Processing element: 4
Processing element: 5
*/