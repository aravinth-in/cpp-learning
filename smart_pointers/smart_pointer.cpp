#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
    void doSomething() { std::cout << "Doing something\n"; }
};

void rawPointerExample() {
    std::cout << "Raw Pointer Example:\n";
    Resource* res = new Resource(); // Manual allocation
    res->doSomething();
    delete res; // Manual deallocation
    std::cout << "Resource manually deleted\n";
}

void uniquePointerExample() {
    std::cout << "Unique Pointer Example:\n";
    std::unique_ptr<Resource> res = std::make_unique<Resource>(); // Automatic allocation and deallocation
    res->doSomething();
    // No need to manually delete the resource
}

void sharedPointerExample() {
    std::cout << "Shared Pointer Example:\n";
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>(); // Shared ownership
    std::cout << "res1 use_count: " << res1.use_count() << "\n";

    {
        std::shared_ptr<Resource> res2 = res1; // Another shared ownership
        res2->doSomething();
        std::cout << "res2 use_count: " << res1.use_count() << "\n";
        std::cout << "res2 goes out of scope\n";
    } // res2 goes out of scope, but resource is not destroyed because res1 still owns it

    std::cout << "res1 use_count after res2 scope: " << res1.use_count() << "\n";
    res1->doSomething();
    std::cout << "res1 goes out of scope\n";
}

void weakPointerExample() {
    std::cout << "Weak Pointer Example:\n";
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>(); // Shared ownership
    std::cout << "res1 use_count: " << res1.use_count() << "\n";

    std::weak_ptr<Resource> weakRes = res1; // Non-owning reference

    if (auto res2 = weakRes.lock()) { // Convert weak_ptr to shared_ptr if resource is still available
        res2->doSomething();
        std::cout << "res2 use_count: " << res2.use_count() << "\n";
    } else {
        std::cout << "Resource no longer available\n";
    }

    std::cout << "res1 use_count after res2 scope: " << res1.use_count() << "\n";
    std::cout << "res1 goes out of scope\n";
}

int main() {
    rawPointerExample();
    std::cout << "\n";

    uniquePointerExample();
    std::cout << "\n";

    sharedPointerExample();
    std::cout << "\n";

    weakPointerExample();
    std::cout << "\n";

    return 0;
}


/*
OUTPUT
Raw Pointer Example:
Resource acquired
Doing something
Resource destroyed
Resource manually deleted

Unique Pointer Example:
Resource acquired
Doing something
Resource destroyed

Shared Pointer Example:
Resource acquired
res1 use_count: 1
Doing something
res2 use_count: 2
res2 goes out of scope
res1 use_count after res2 scope: 1
Doing something
res1 goes out of scope
Resource destroyed

Weak Pointer Example:
Resource acquired
res1 use_count: 1
Doing something
res2 use_count: 2
res1 use_count after res2 scope: 1
res1 goes out of scope
Resource destroyed
*/