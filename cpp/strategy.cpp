#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Pros of Strategy Pattern:
// 1. Different algorithms can be swapped easily.
// 2. Sorter does not need if/else or switch for every sorting mode.
// 3. New strategies can be added without changing Sorter.
// 4. Client code chooses behavior at runtime.
// 5. Works well with lambdas in modern C++.

// Cons of Strategy Pattern:
// 1. std::function may add small runtime overhead.
// 2. For very simple programs, this can be over-engineering.
// 3. The strategy signature fixes the parameter type to vector<int>&.
// 4. Debugging can be slightly harder because behavior is indirect.
// 5. If performance is critical, templates may be preferred over std::function.


struct Sorter{
    using Strategy = std::function<void(std::vector<int>&)>;
    Strategy strategy;

    Sorter(Strategy s) : strategy(std::move(s)){}
    void sort(std::vector<int>& v){strategy(v);}
};

int main(){
    std::vector<int> data = {5, 2, 8, 1, 9};

    Sorter asc([](auto& v){std::sort(v.begin(), v.end());});
    Sorter desc([](auto& v){std::sort(v.rbegin(), v.rend());});

    asc.sort(data);
    for(int x : data){std::cout << x << " ";}
    std::cout << std::endl;
    desc.sort(data);
    for(int x : data){std::cout << x << " ";}
    std::cout << std::endl;

    return 0;
}
