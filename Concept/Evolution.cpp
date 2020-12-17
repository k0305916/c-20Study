// evolution

// c++14
// // addLambdaGeneric.pp

// #include <iostream>

// auto addLambda = [](auto fir, auto sec){ return fir + sec; }; 

// template <typename T, typename T2>                            
// auto addTemplate(T fir, T2 sec){ return fir + sec; }


// int main(){
    
//     std::cout << addLambda(2000, 11.5);    // 2011.5
//     std::cout << addTemplate(2000, 11.5);  // 2011.5
    
// }


//c++20
#include <concepts>
#include <iostream>

auto addUnconstrained(auto fir, auto sec){
     return fir + sec;
}

std::floating_point auto addConstrained(std::integral auto fir, 
                                        std::floating_point auto sec){
     return fir + sec;
}

int main(){
    
    std::cout << addUnconstrained(2000, 11.5); // 2011.5
    std::cout << addConstrained(2000, 11.5);   // 2011.5
    
}