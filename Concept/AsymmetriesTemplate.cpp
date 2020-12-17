// // lambdaCpp11.cpp

// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <array>
// #include <vector>

// template <typename Cont, typename Pred>
// void sortDescending(Cont& cont, Pred pred){
//     std::sort(cont.begin(), cont.end(), pred);
// }

// template <typename Cont>
// void printMe(const Cont& cont){
//     for (auto c: cont) std::cout << c << " ";
//     std::cout << std::endl;
// }

// int main(){

//     std:: cout << std::endl;
    
//     std::array<int, 10> myArray{5, -10, 3, 2, 7, 8, 9, -4, 3, 4};
//     std::vector<double> myVector{5.1, -10.5, 3.1, 2.0, 7.2, 8.3};
//     std::vector<std::string> myVector2{"Only", "for", "testing", "purpose"};
    
//     sortDescending(myArray, [](int fir, int sec){ return fir > sec; });           // (1)
//     sortDescending(myVector, [](double fir, double sec){ return fir > sec; });    // (2)
//     sortDescending(myVector2, [](const std::string& fir, const std::string& sec){ // (3)
//        return fir > sec; 
//     });

//     printMe(myArray);
//     printMe(myVector);
//     printMe(myVector2);
    
//     std::cout << std::endl;
    
// }


// // lambdaCpp14.cpp

// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <array>
// #include <vector>

// template <typename Cont>
// void sortDescending(Cont& cont){
//     std::sort(cont.begin(), cont.end(), [](auto fir, auto sec){   // (1)
//         return fir > sec; 
//     });
// }

// template <typename Cont>
// void printMe(const Cont& cont){
//     for (auto c: cont) std::cout << c << " ";
//     std::cout << std::endl;
// }

// int main(){

//     std:: cout << std::endl;
    
//     std::array<int, 10> myArray{5, -10, 3, 2, 7, 8, 9, -4, 3, 4};
//     std::vector<double> myVector{5.1, -10.5, 3.1, 2.0, 7.2, 8.3};
//     std::vector<std::string> myVector2{"Only", "for", "testing", "purpose"};
    
//     sortDescending(myArray);      // (2)
//     sortDescending(myVector);     // (2)
//     sortDescending(myVector2);    // (2)

//     printMe(myArray);
//     printMe(myVector);
//     printMe(myVector2);
    
//     std::cout << std::endl;
    
// }


// // genericLambdaTemplate.cpp c++17

// #include <iostream>
// #include <string>

// function return can define to auto.
// function parameter can define to auto.
// auto addLambda = [](auto fir, auto sec){ return fir + sec; }; // (1)

// template <typename T, typename T2>                            // (2)
// auto addTemplate(T fir, T2 sec){ return fir + sec; }

// int main(){

//     std::cout << std::boolalpha << std::endl;

//     std::cout << addLambda(1, 5) << " " << addTemplate(1, 5) << std::endl;
//     std::cout << addLambda(true, 5) << " " << addTemplate(true, 5) << std::endl;
//     std::cout << addLambda(1, 5.5) << " " << addTemplate(1, 5.5) << std::endl;
    
//     const std::string fir{"ge"};
//     const std::string sec{"neric"};
//     std::cout << addLambda(fir, sec) << " " << addTemplate(fir, sec) << std::endl;

//     std::cout << std::endl;

//     return 1;
// }

// placeholdersDraft.cpp

#include <iostream>
#include <type_traits>
#include <vector>

//Where can I use my concept? Concepts can be used where auto is usable.
template<typename T>                                   // (1)
concept Integral = std::is_integral<T>::value;

Integral auto getIntegral(int val){                    // (2)
    return val;
}

int main(){

    std::cout << std::boolalpha << std::endl;
 
    std::vector<int> vec{1, 2, 3, 4, 5};
    for (Integral auto i: vec) std::cout << i << " ";  // (3)
 
    Integral auto b = true;                            // (4)
    std::cout << b << std::endl;

    Integral auto integ = getIntegral(10);             // (5)
    std::cout << integ << std::endl;

    auto integ1 = getIntegral(10);                     // (6)
    std::cout << integ1 << std::endl;

    std::cout << std::endl;

    return 1;
}