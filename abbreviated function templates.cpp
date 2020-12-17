// genericLambdaFunction.cpp

#include <iostream>
#include <string>

// auto addLambda = [](auto fir, auto sec){ return fir + sec; }; // (1)

// // 很奇怪也。。。。我不是在PAL中使用了auto来定义返回值嘛？？？需要c++17de支持？
// // 可是我这都设置成了c++2a了。。。为什么还报错？不懂。。。
// // 印象中，不是在PAL中已经成功使用了嘛？？？？？
// // 额。。。需要check下。。。。
// // -------
// // 哦。。。。原来是只能在lambda中使用。。。。。我去。。。。不能在function中使用。。。。
// auto addFunction(auto fir, auto sec){ return fir + sec; }     // (2)

// int main(){

//     std::cout << std::boolalpha << std::endl;

//     std::cout << addLambda(1, 5) << " " << addFunction(1, 5) << std::endl;
//     std::cout << addLambda(true, 5) << " " << addFunction(true, 5) << std::endl;
//     std::cout << addLambda(1, 5.5) << " " << addFunction(1, 5.5) << std::endl;
    
//     const std::string fir{"ge"};
//     const std::string sec{"neric"};
//     std::cout << addLambda(fir, sec) << " " << addFunction(fir, sec) << std::endl;

//     std::cout << std::endl;

// }

// conceptsIntegralVariationsDraft.cpp

#include <type_traits>
#include <iostream>

template<typename T>                                  // (1)
concept Integral = std::is_integral<T>::value;       

template<typename T>                                  // (2)
requires Integral<T>
T gcd(T a, T b){
    if( b == 0 ) return a;
    else return gcd(b, a % b);
}

template<typename T>                                  // (3)
T gcd1(T a, T b) requires Integral<T>{
    if( b == 0 ){ return a; }
    else return gcd(b, a % b);
}

template<Integral T>                                  // (4)
T gcd2(T a, T b){
    if( b == 0 ){ return a; }
    else return gcd(b, a % b);
}

Integral auto gcd3(Integral auto a, Integral auto b){ // (5)
    if( b == 0 ){ return a; }
    else return gcd(b, a % b);
}

auto gcd4(auto a, auto b){                            // (6)
    if( b == 0 ){ return a; }
    return gcd(b, a % b);
}

template<typename T> 
concept Arithmetic = std::is_arithmetic<T>::value; 

Arithmetic auto sub(Arithmetic auto fir, Arithmetic auto sec){
    return fir - sec;
}

int main(){

    std::cout << std::endl;

    std::cout << "gcd(100, 10)= "  <<  gcd(100, 10)  << std::endl;
    std::cout << "gcd1(100, 10)= " <<  gcd1(100, 10)  << std::endl;
    std::cout << "gcd2(100, 10)= " <<  gcd2(100, 10)  << std::endl;
    std::cout << "gcd3(100, 10)= " <<  gcd3(100, 10)  << std::endl;
    std::cout << "gcd4(100, 10)= " <<  gcd3(100, 10)  << std::endl; 

    std::cout << std::endl;

}

// Let me describe in a few words the already known stuff for my previous posts to concepts. Line 1 defines the concept Integral. gcd - gcd2 (lines 2 - 4) use the concept in various ways. gcd used the requires clause, gcd1 the so-called trailing requires clause, and gcd2 constrained template parameters.

// With gcd3, the syntactic sugar starts. The function declaration Integral auto gcd3(Integral auto a, Integral auto b), requires from its type parameters that they support the concept Integral. This syntactic form is the new way to use a concept and to get a function template that is equivalent to the previous versions gcd - gcd2.

// The syntactic form of gcd3 and gcd4 is called abbreviated function templates. 

//****************
// Using an unconstrained placeholder (auto) in a function declaration generates a function template. The following two functions add are equivalent:

// template<typename T, typename T2>
// auto add(T fir, T2 sec){
//     return fir + sec;
// }

// auto add(auto fir, auto sec){
//     return fir + sec;
// }

//The key observation is, that both arguments can have different types. The same holds for concepts.