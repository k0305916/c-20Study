// The class template std::atomic_ref applies atomic operations to the referenced non-atomic object.
// Accessing a subobject of the referenced object with an atomic_ref is not thread-safe.
#include <iostream>


struct Counters {
    int a;
    int b;
};

int main(){
    Counter counter;


    std::atomic_ref<Counters> cnt(counter);

    return 1;
}

// With C++20 we get two new smart pointers: std::atomic<std::shared_ptr<T>> and std::atomic<std::weak_ptr<T>>.
// For provide thread-safe operation.