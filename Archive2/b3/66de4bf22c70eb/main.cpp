#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

typedef std::string string_t;

std::vector<std::pair<string_t, string_t>> m_results {
    { "hello", "world" },
	{ "hello", "peopl" },
	{ "gdbye", "evry1" },
	{ "hello", "evry1" }
};

std::vector<string_t> bar(const string_t& index)
{
	std::vector<string_t> results;
	std::for_each(
		m_results.begin(), m_results.end(),
		[&index, &results](decltype(*m_results.cbegin())& i)
  	  	{
  	  		if(index == i.first) results.push_back(i.second);
    	}
    );
    
    return results;
}

std::vector<string_t> foo(const string_t& index)
{
	std::vector<string_t> results;
    std::transform(
    	m_results.begin(), m_results.end(),
        std::back_inserter(results),
		[&index](decltype(*m_results.cbegin())& i) -> string_t
		{
			if(i.first == index) return i.second;
			return string_t();
		}
    );
    
    results.erase(std::remove(
			results.begin(),
			results.end(),
			string_t("")
		), results.end());
    
    return results;
}

int main()
{
	for(auto& i : foo("hello"))
		std::cout << i << ' ';

	std::cout << std::endl;

	for(auto& i : bar("hello"))
		std::cout << i << ' ';
	
	return 0;
}
