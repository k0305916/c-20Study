// Template Requirements are verified

// // c++11
// // This technique is called SFINAE and stands for Substitution Failure Is Not An Error. 
// #include <type_traits>

// template<typename T,
//          typename std::enable_if<std::is_integral<T>::value, T>:: type = 0>
// T moduloOf(T t) {
//     return t % 5;
// }

// int main() {

//     auto res = moduloOf(5.5);

// }

// // c++20
// #include <concepts>

// std::integral auto moduloOf(std::integral auto t) {
//     return t % 5;
// }

// int main() {

//     auto res = moduloOf(5);
//     // auto res = moduloOf(5.5);               // throw error

// }

// Definition of Templates radically improved
// example: abbreviated function templates.cpp


// Semantic Categories
// template<typename T>
// concept Addable = has_plus<T>;    // bad; insufficient

// template<Addable N> auto algo(const N& a, const N& b) // use two numbers
// {
//     // ...
//     return a + b;
// }

// int x = 7;
// int y = 9;
// auto z = algo(x, y);   // z = 16

// std::string xx = "7";
// std::string yy = "9";
// auto zz = algo(xx, yy);   // zz = "79"

// I assume Addable behaves not like expected. The function template algo should accept arguments which model numbers and not just support the + operator. Consequentially, two strings can be used as arguments. This is bad because addition is commutative, but not string concatenation: "7" + "9" != "9" + "7".

// The solution is quite simple. Define the concept Number. Number is a semantic category such as Equal, Callable, Predicate, or Monad are.