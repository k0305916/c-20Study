#include <iostream>
#include <thread>


int main(){
    std::cout << std::endl;
    std::cout << std::boolalpha;
    std::thread thr{[]{ std::cout << "Joinable std::thread" << std::endl; }};
    std::cout << "thr.joinable(): " << thr.joinable() << std::endl;

    // From the c++ language support, apple clang++ does not support this feature.
    // gcc 10/MSVC 19 provide this feature.
    // std::jthread thr{[]{ std::cout << "Joinable std::jthread" << std::endl; }};
    // std::cout << "thr.joinable(): " << thr.joinable() << std::endl;

    std::cout << std::endl;
}