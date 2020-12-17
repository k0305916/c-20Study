// #include <iostream>
// #include <concepts>

// A SemiRegular type has to support the rule of six: and has to be swappable. 

// Default constructor: X()
// Copy constructor: X(const X&)
// Copy assignment: operator=(const X&)
// Move constructor: X(X&&)
// Move assignment: operator=(X&&)
// Destructor: ~X()
// swappable: swap(X&, Y&)


// template<typename T>
// struct isSemiRegular: std::integral_constant<bool,
//                                       std::is_default_constructible<T>::value &&
//                                       std::is_copy_constructible<T>::value &&
//                                       std::is_copy_assignable<T>::value &&
//                                       std::is_move_constructible<T>::value &&
//                                       std::is_move_assignable<T>::value &&
//                                       std::is_destructible<T>::value &&
//                                       std::is_swappable<T>::value >{};


// template<typename T>
// concept SemiRegular = isSemiRegular<T>::value;


// Regular
// Only one little step and I'm done with the concept Regular. Additionally, to the concept SemiRegular the concept Regular requires that the type is equality comparable. I already defined in my last post the concept Equal. 
// template<typename T>
// concept Equal =
//     requires(T a, T b) {
//         { a == b } -> std::convertible_to<bool>;
//         { a != b } -> std::convertible_to<bool>;
// };

// template<typename T>
// concept Regular = Equal<T> && 
//                   SemiRegular<T>;


// The concepts regular and semiregular in C++20
// template<class T>
// concept movable = is_object_v<T> && move_constructible<T> &&
// assignable_from<T&, T> && swappable<T>;

// template<class T>
// concept copyable = copy_constructible<T> && movable<T> && assignable_from<T&, const T&>;

// template<class T>
// concept semiregular = copyable<T> && default_constructible<T>;

// template<class T>
// concept regular = semiregular<T> && equality_comparable<T>;


#include <concepts>
#include <vector>
#include <utility>

template<typename T>
struct isSemiRegular: std::integral_constant<bool,
                                      std::is_default_constructible<T>::value &&
                                      std::is_copy_constructible<T>::value &&
                                      std::is_copy_assignable<T>::value &&
                                      std::is_move_constructible<T>::value &&
                                      std::is_move_assignable<T>::value &&
                                      std::is_destructible<T>::value &&
                                      std::is_swappable<T>::value >{};


template<typename T>
concept SemiRegular = isSemiRegular<T>::value;

template<typename T>
concept Equal =
    requires(T a, T b) {
        { a == b } -> std::convertible_to<bool>;
        { a != b } -> std::convertible_to<bool>;
};

template<typename T>                              // (1)
concept Regular = Equal<T> && 
                  SemiRegular<T>;

template <Regular T>                              // (2)
void behavesLikeAnInt(T) {
    // ...
}

template <std::regular T>                         // (3)
void behavesLikeAnInt2(T) {
    // ...
}

struct EqualityComparable { };                    // (4)                                          
bool operator == (EqualityComparable const&, EqualityComparable const&) { return true; }

struct NotEqualityComparable { };                 // (5)

int main() {

    int myInt{};
    behavesLikeAnInt(myInt);
    behavesLikeAnInt2(myInt);

    std::vector<int> myVec{};
    behavesLikeAnInt(myVec);
    behavesLikeAnInt2(myVec);

    EqualityComparable equComp;
    behavesLikeAnInt(equComp);
    behavesLikeAnInt2(equComp);

    NotEqualityComparable notEquComp;             
    behavesLikeAnInt(notEquComp);                  // (6)
    behavesLikeAnInt2(notEquComp);                 // (7)
    
}