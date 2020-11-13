#include <iostream>
#include <string>

//1.
// Allow [=, this] as lambda capture and deprecate implicit capture of this via [=]
// The implicit [=] capture by copy inside the struct Lambda causes in C++20 a deprecation warning.
struct Lambda
{
    auto foo(){
        return [=]{std::cout << s << std::endl;};
    }

    std::string s;
};

struct LambdaCpp20{
    auto foo(){
        return [=, this] {std::cout << s << std::endl;};
    }

    std::string s;
};

//2. Template lambdas
template<typename T>
T operator(T x) const {
    return x;
}

//3.
auto foo = []<typename T>(std::vector<T> const& vec){
    //do vector specific stuff.
}