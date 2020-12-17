// conceptsArithmeticTS.cpp

#include <type_traits>
#include <iostream>

// template<typename T>
// concept bool Arithmetic(){
//     return std::is_arithmetic<T>::value;
// }

// clang++ 并不支持这种写法。。。。。
// gcc 支持
template<typename T> 
concept Arithmetic = std::is_arithmetic<T>::value; 

Arithmetic auto sub(Arithmetic auto fir, Arithmetic auto sec){
    return fir - sec;
}

int main(){

    std::cout << std::endl;

    // std::cout << "sub(6, 5): " << sub(6, 5) << std::endl;      // (1)
    // std::cout << "sub(5.5, 5): " << sub(5.5, 5) << std::endl;  // (2)

    std::cout << std::endl;

}