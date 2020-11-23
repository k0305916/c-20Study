#include <iostream>
#include <span>
#include <vector>


template <typename T>
void copy_n(const T* p, T* q, int n){
    std::cout << "copy_n" << std::endl;
}

// A std::span can be initialized with a C-array, , and a std::vector (1), and a std::array (2).
template <typename T>
void copy(std::span<T> src, std::span<T> des){
    std::cout << "copy" << std::endl;
}

int main(){
    int arr1[] = {1,2,3};
    int arr2[] = {3,4,5};

    copy_n(arr1,arr2,3);

    // If you use a pointer to initialise a std::span<T>, you have to provide the size for the constructor.
    // copy(std::span(arr1), std::span(arr2));
    auto sss = std::span(arr1,3);
    auto sss1 = std::span(arr2,3);

    copy(sss, sss1);

    std::vector<int> vec1{1,2,3};
    std::vector<int> vec2{2,3};

    // std::span<T> automatically deduces the size of the plain array or the std::vector.
    copy(std::span(vec1), std::span(vec2));
    return 1;
}

