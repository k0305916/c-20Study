#include <iostream>
#include <type_traits>

//Arithmetic essential means that T is either integral or floating-point.
template <typename T>
concept Arithmetic = std::is_arithmetic<T>::value;

template <Arithmetic... Args>
bool all(Args... args) {return (... && args);}

template <Arithmetic... Args>
bool any(Args... args) {return (... || args);}

template <Arithmetic... Args>
bool none(Args... args) {return !(... || args);}

int main(){
    std::cout << std::boolalpha << std::endl;
    std::cout << "all(5, true, 5.5, false): " << all(5, true, 5.5, false) << std::endl;
    std::cout << "any(5, true, 5.5 false): " << any(5, true, 5.5, false) << std::endl;
    std::cout << "none(5, true, 5.5, false): " << none(5, true, 5.5, false) << std::endl;

    return 1;
}

//More Requirements
// template <SequenceContainer S,   
//           EqualityComparable<value_type<S>> T>
// Iterator_type<S> find(S&& seq, const T& val){
//     ...
// }