#include <iostream>
#include <ranges>
#include <vector>
#include <map>

// GCC10.2 do not support now?
int main() {

    // std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
  
    // auto results = numbers | std::views::filter([](int n){ return n % 2 == 0; })
    //                        | std::views::transform([](int n){ return n * 2; });
                           
    // for (auto v: results) std::cout << v << " ";     // 4 8 12



    std::map<std::string,int>freqWord{ {"witch",25}, {"wizard",33}, {"tale",45},{"dog",4}, {"cat",34}, {"fish",23} };

    for(const auto&name: std::views::keys(freqWord)) { std::cout<<name<<""; }

}