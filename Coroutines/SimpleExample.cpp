#include <iostream>
#include <vector>

// // functionEvolution.cpp

// int func1() {
//     return 1972;
// }

// int func2(int arg) {
//     return arg;
// }

// double func2(double arg) {
//     return arg;
// }

// template <typename T>
// T func3(T arg) {
//     return arg;
// }

// struct FuncObject4 {
//     int operator()() { // (1)
//         return 1998;
//     }
// };

// auto func5 = [] {
//     return 2011;
// };

// auto func6 = [] (auto arg){
//     return arg;
// };

// int main() {

//     func1();        // 1972

//     func2(1998);    // 1998
//     func2(1998.0);  // 1998.0
//     func3(1998);    // 1998
//     func3(1998.0);  // 1998.0
//     FuncObject4 func4;
//     func4();        // 1998

//     func5();        // 2011

//     func6(2014);    // 2014
//     func6(2014.0);  // 2014

// }   


// A Lazy Generator
generator<int> generatorForNumbers(int begin, int inc = 1) {
  
  for (int i = begin;; i += inc) {
    co_yield i;
  }
  
}

int main() {

    std::cout << std::endl;

    const auto numbers= generatorForNumbers(-10);                   // (2)
  
    for (int i= 1; i <= 20; ++i) std::cout << numbers << " ";       // (4)
  
    std::cout << "\n\n";

    // This does not hold for line (3) since there is no end condition. Consequentially, the expression runs forever.
    for (auto n: generatorForNumbers(0, 5)) std::cout << n << " ";  // (3)

    std::cout << "\n\n";

}