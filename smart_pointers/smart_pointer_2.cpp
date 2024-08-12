#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main() {
    std::shared_ptr<Resource> sp1 = std::make_shared<Resource>();
    std::cout << "sp1 use count: " << sp1.use_count() << "\n"; // Output: 1
    // Strong reference count (_Uses): 1
    // Weak reference count (_Weaks): 1 (for the control block)

    std::weak_ptr<Resource> wp1 = sp1;
    std::cout << "sp1 use count after weak_ptr: " << sp1.use_count() << "\n"; // Output: 1
    // Strong reference count (_Uses): 1
    // Weak reference count (_Weaks): 2 (1 for the control block + 1 for wp1)

    if (auto sp2 = wp1.lock()) {
        std::cout << "sp2 use count: " << sp2.use_count() << "\n"; // Output: 2
        // Strong reference count (_Uses): 2 (sp1 + sp2)
        // Weak reference count (_Weaks): 2
    }

    std::cout << "sp1 use count before reset: " << sp1.use_count() << "\n"; // Output: 1
    sp1.reset();
    std::cout << "sp1 use count after reset: " << sp1.use_count() << "\n"; // Output: 0
    // Strong reference count (_Uses): 0 (resource is destroyed)
    // Weak reference count (_Weaks): 1 (for wp1)

    if (auto sp3 = wp1.lock()) {
        std::cout << "sp3 use count: " << sp3.use_count() << "\n"; // This line won't be executed
    } else {
        std::cout << "Resource has been destroyed\n"; // Output: Resource has been destroyed
    }

    return 0;
}


/*
Control Block:
When you create a std::shared_ptr, a control block is also created. The control block contains:
- Strong Reference Count (_Uses): The number of std::shared_ptr instances owning the resource. 
- Weak Reference Count (_Weaks): The number of std::weak_ptr instances referencing the control block, plus one for the control block itself.

The control block manages the lifetime of the resource and keeps track of how many std::shared_ptr and std::weak_ptr instances reference it. 
When the last std::shared_ptr is destroyed, the resource is destroyed. 
When the last std::weak_ptr is destroyed, the control block is destroyed.
*/