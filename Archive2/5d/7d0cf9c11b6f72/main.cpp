#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
    std::vector<std::string> vec{"A", "B", "C", "U", "U", "D", "U", "U", "U", "U", "E"};
    
    auto it = search_n(vec.begin(), vec.end(), 3, "U");
    
    if(it == vec.end()) {
        // 3 consecutive Us do no exist
        return -1;
    }
    
    it = vec.insert(it, "U'");
    vec.erase(std::next(it), std::next(it, 4));
    
    for(auto const& v : vec) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

