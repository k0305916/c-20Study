// With C++20, we get new attributes [[likely]] and [[unlikely]]. Both attributes allow it to give the optimiser a hint, whether path of execution is more or less likely.
#include <iostream>
#include <vector>
#include <cmath>

int main(){
    std::vector<int> v{1,2,5};
    auto sum = 0.0;
    for(size_t i = 0; i<v.size();++i){
        if(v[i] < 0) [[likely]] sum -= sqrt(-v[i]);
        else sum+std::sqrt(v[i]);
    }
}