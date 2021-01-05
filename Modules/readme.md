# Modules
Modules promise a lot: compile-time improvement, isolation of macros, the abolition of header files, and ugly workarounds.

## Multiple Definition of Symbols
ODR stands for the One Definition Rule and says in the case of a function.

* A function can have not more than one definition in any translation unit.
* A function can have not more than one definition in the program.
* Inline functions with external linkage can be defined in more than one translation. The definitions have to satisfy the requirement that each definition has to be the same.

## Advantages of Modules
* Modules are only imported once and are literally for free.
* It makes no difference in which order you import a module.
* Identical symbols with modules are very unlikely.
* Modules enable you to express the logical structure of your code. You can explicitly specify names that should be exported or not. Additionally, you can bundle a few modules into a bigger module and provide them to your customer as a logical package.
* **Thanks to modules, there is no need to separate your source code into an interface and an implementation part.**
  * How to implement this feature?


## Module Declaration Files
Did you noticed the strange name of the module: math.ixx.

* cl.exe (Microsoft) uses the required extension *ixx*. The ixx stands for a module interface source.
* Clang uses the extension *cppm*. cppm stands presumably for a cpp module declaration. **Wrong!!! The documentation to Clang is misleading. Stop using the cppm extension until you read my next post. Use the extension cpp. I assume you don't want to make the same Odyssey such as me.**  -> .pcm
* I don't know of a GCC extension.


## Guideline for a Module Structure
~~~c++
module;                      // global module fragment

#include <headers for libraries not modularized so far>

export module math;          // module declartion 

import <importing of other modules> 

<non-exported declarations>  // names with only visibiliy inside the module

export namespace math {

    <exported declarations>  // exported names 

}
~~~

### Module Interface Unit
~~~c++
// mathInterfaceUnit.ixx

module;                   

import std.core;                            

export module math;       

export namespace math {

    int add(int fir, int sec);
 
    int getProduct(const std::vector<int>& vec);

}
~~~

### Module Implementation Unit
~~~c++
// mathImplementationUnit.cpp

module math;

import std.core;

int add(int fir, int sec){
    return fir + sec;
}

int getProduct(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}
~~~

### Main Program
~~~c++
// client3.cpp

import std.core;

import math;

int main() {
    
    std::cout << std::endl;   
   
    std::cout << "math::add(2000, 20): " << math::add(2000, 20) << std::endl;
    
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "math::getProduct(myVec): " << math::getProduct(myVec) << std::endl;
    
    std::cout << std::endl;
   
}
~~~

### Building the Executable
cl.exe /std:c++latest /c /experimental:module mathInterfaceUnit.ixx /EHsc /MD      // (1)
cl.exe /std:c++latest /c /experimental:module mathImplementationUnit.cpp /EHsc /MD // (2)
cl.exe /std:c++latest /c /experimental:module client3.cpp /EHsc /MD                // (3)
cl.exe client3.obj mathInterfaceUnit.obj mathImplementationUnit.obj                // (4)

1. Creates the object file mathInterfaceUnit.obj and the module interface file math.ifc.
2. Creates the object file mathImplementationUnit.obj.
3. Creates the object file client3.obj.
4. Creates the executable client3.exe.


**[C++20: Further Open Questions to Modules](https://www.modernescpp.com/index.php/c-20-open-questions-to-modules)**