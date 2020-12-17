#include <iostream>
#include <concepts>
#include <unordered_set>
//The C++ 20 standard has already defined two concepts for equality comparing:
//* std::equality_comparable: corresponds to my concept Equal
//* std::equality_comparable_with: allows the comparison of values of different type; e.g.: 1.0 == 1.0f

// Of course, the concept Ordering is already part of the C++20 standard.

// std::three_way_comparable: corresponds to my concept Ordering
// std::three_way_comparable_with: allows the comparison of values of different type; e.g.: 1.0 < 1.0f

// //Concepts TS
// template<typename T>
// concept bool Equal(){
//     return requires(T a, T b) {
//         { a == b } -> bool;
//         { a != b } -> bool;
//    };
// }

//c++20 standard
// wrong way
// the concept Equal should not check if the equal and unequal operator returns a bool 
// but something which is implicitly or explicitly convertible to a bool.
// template<typename T>
// concept Equal =
//     requires(T a, T b) {
//         { a == b } -> bool;
//         { a != b } -> bool;
// };

//right way
template<typename T>
concept Equal =
    requires(T a, T b) {
        { a == b } -> std::convertible_to<bool>;
        { a != b } -> std::convertible_to<bool>;
};

template <typename T>
concept Ordering =
    Equal<T> &&
    requires(T a, T b) {
        { a <= b } -> std::convertible_to<bool>;
        { a < b } -> std::convertible_to<bool>;
        { a > b } -> std::convertible_to<bool>;
        { a >= b } -> std::convertible_to<bool>;
    };

// c++20 implement
//template <class From, class To>
// concept convertible_to =
//   std::is_convertible_v<From, To> &&
//   requires(From (&f)()) {
//     static_cast<To>(f());
//   };

// wrong way
// The concept Equal requires that a and b have the same type but, 
// the function areEqual allows that fir and sec could be different types that both support the concept Equal
// bool areEqual(Equal auto fir, Equal auto sec) {                       
//   return fir == sec;
// }

//right way
template<Equal T>
bool areEqual(T a, T b) {                     // (1)            
  return a == b;
}

template <Ordering T>
T getSmaller(T a, T b) {
    return (a < b) ? a : b;
}


/*
struct WithoutEqual{
  bool operator==(const WithoutEqual& other) = delete;
};

struct WithoutUnequal{
  bool operator!=(const WithoutUnequal& other) = delete;
};
*/

int main()
{
//   std::cout << std::boolalpha << std::endl;
  
//   std::cout << "areEqual(1, 5): " << areEqual(1, 5) << std::endl;
  
//   /*
  
//   bool res = areEqual(WithoutEqual(),  WithoutEqual());
  
//   bool res2 = areEqual(WithoutUnequal(),  WithoutUnequal());
  
//   */
  
//   std::cout << std::endl;


    std::cout << std::boolalpha << std::endl;

    std::cout << "areEqual(1, 5): " << areEqual(1, 5) << std::endl;

    std::cout << "getSmaller(1, 5): " << getSmaller(1, 5) << std::endl;

    std::unordered_set<int> firSet{1, 2, 3, 4, 5};
    std::unordered_set<int> secSet{5, 4, 3, 2, 1};

    std::cout << "areEqual(firSet, secSet): " << areEqual(firSet, secSet) << std::endl;

    // auto smallerSet = getSmaller(firSet, secSet);

    std::cout << std::endl;

  return 1;
}