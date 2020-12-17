# Example

~~~c++
template<typename It>
concept LegacyRandomAccessIterator =
  LegacyBidirectionalIterator<It> &&        // (1)
  std::totally_ordered<It> &&
  requires(It i, typename std::incrementable_traits<It>::difference_type n) {
    { i += n } -> std::same_as<It&>;        // (2)
    { i -= n } -> std::same_as<It&>;
    { i +  n } -> std::same_as<It>;
    { n +  i } -> std::same_as<It>;
    { i -  n } -> std::same_as<It>;
    { i -  i } -> std::same_as<decltype(n)>;
    {  i[n]  } -> std::convertible_to<std::iter_reference_t<It>>;
  };
  ~~~

# Overloading
std::advance(iter, n) puts its iterator iter n position further. Depending on the iterator, the implementation can use pointer arithmetic or just go n times further. In the first case, the execution time is constant; in the second case, the execution time depends on the stepsize n. Thanks to concepts, you can overload std::advance on the iterator category.
~~~c++
template<InputIterator I>
void advance(I& iter, int n){...}

template<BidirectionalIterator I>
void advance(I& iter, int n){...}

template<RandomAccessIterator I>
void advance(I& iter, int n){...}

// usage

std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
auto vecIt = vec.begin();
std::advance(vecIt, 5);       //  RandomAccessIterator

std::list<int> lst{1, 2, 3, 4, 5, 6, 7, 8, 9};
auto lstIt = lst.begin();
std::advance(lstIt, 5);       //  BidirectionalIterator

std::forward_list<int> forw{1, 2, 3, 4, 5, 6, 7, 8, 9};
auto forwIt = forw.begin();
std::advance(forwIt, 5);      //  InputIterator
~~~

# Specialisations
Concepts also support template specialisations.

~~~c++
template<typename T>
class MyVector{};

template<Object T>
class MyVector{};

MyVector<int> v1;     // Object T
MyVector<int&> v2;    // typename T
~~~

* MyVector<int&> goes to the unconstrained template parameter.

* MyVector<int> goes to the constrained template parameter.


# Language-related concepts
* same_as
* derived_from
* convertible_to
* common_reference_with: common_reference_with<T, U> must be well-formed and T and U must be convertible to a reference type C
* common_with: similar to common_reference_with but the common type C has not to be a reference type
* assignable_from
* swappable
* 
## Arithmetic
* integral
* signed_integral
* unsigned_integral
* floating_point

# Comparison concepts
* boolean: specifies if a type T is usable as a truth value; interestingly, pointers, smart pointers, types with an explicit conversion operator to bool are not boolean types.
* equality_comparable
* totally_ordered

# Object concepts
* movable
* copyable
* semiregular
* regular

~~~c++
template<class T>
concept movable = is_object_v<T> && move_constructible<T> && assignable_from<T&, T> && swappable<T>;

template<class T>
concept copyable = copy_constructible<T> && movable<T> && assignable_from<T&, const T&>;

template<class T>
concept semiregular = copyable<T> && default_constructible<T>;

template<class T>
concept regular = semiregular<T> && equality_comparable<T>;
~~~

# Callable concepts
* invocable
* regular_invocable: F models invocable and equality-preserving, and does not modify the function arguments; equality-preserving means the F produces the same output when giving the same input
* predicate: F models a predicate if F models invocable and returns a boolean

# iterators library
* input_iterator
* output_iterator
* forward_iterator
* bidirectional_iterator
* random_access_iterator
* contiguous_iterator

![Sample](Concept/../images/IteratorCategories.png)

# Algorithm concepts
* permutable: reordering of elements in place is possible
* mergeable: merging sorted sequences into an output sequence is possible
* sortable: permuting a sequence into an ordered sequence is possible

# Numeric library
The numeric library has the concept of a *uniform_random_bit_generator*. A  uniform_random_bit_generator g of type G has to return unsigned integers so that each value is equally probable. Additionally, the uniform random bit generator g of type G has to support the member functions G::min, and G::max.