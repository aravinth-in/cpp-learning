#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};


class LockFreeStack {
public:
    LockFreeStack() : head(nullptr) {}

    void push(int value) {
        Node* new_node = new Node(value);
        new_node->next = head.load(std::memory_order_relaxed);
        // Initial State, stack is empty, head is nullptr.
        // Thread 1: Pushes Node with Value 1
        // Set new_node->next: new_node->next = head (which is nullptr).
        new_node->next = head.load(std::memory_order_relaxed);
        
        // Attempt to set head: head.compare_exchange_weak(new_node->next, new_node).
        // head is nullptr, which matches new_node->next, head is set to new_node.
        // The stack now looks like: 1 -> nullptr.

        // Attempt to set head to new_node with release on success and relaxed on failure.
        // Release ensures that prior writes are visible to other threads.
        while (!head.compare_exchange_weak(new_node->next, new_node, std::memory_order_release, std::memory_order_relaxed)) {
            // Retry if head has changed, using relaxed memory order to minimize overhead.
            // Note : The order in which elements are pushed onto the stack may not match the order in which threads attempt to push them.
        }
        std::cout << "Pushed: " << value << std::endl;
    }

    bool pop(int& value) {
        Node* old_head = head.load(std::memory_order_relaxed);
        
        // Attempt to set head to old_head->next with acquire on success and relaxed on failure.
        // Acquire ensures that subsequent reads see the updated state.
        while (old_head && !head.compare_exchange_weak(old_head, old_head->next, std::memory_order_acquire, std::memory_order_relaxed)) {
            // Retry if head has changed, using relaxed memory order to minimize overhead.
        }
        if (old_head) {
            value = old_head->data;
            delete old_head;
            std::cout << "Popped: " << value << std::endl;
            return true;
        }
        return false;
    }

private:
    std::atomic<Node*> head;
};

void push_elements(LockFreeStack& stack, int start, int end) {
    
    for (int i = start; i < end; ++i) {
        stack.push(i);
    }
}

void pop_elements(LockFreeStack& stack, int num_elements) {
    int value;
    for (int i = 0; i < num_elements; ++i) {
        if (!stack.pop(value)) {
            std::cout << "Stack is empty" << std::endl;
        }
    }
}

int main() {
    LockFreeStack stack;

    std::thread t1(push_elements, std::ref(stack), 0, 10);
    std::thread t2(push_elements, std::ref(stack), 10, 20);
    std::thread t3(pop_elements, std::ref(stack), 15);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
