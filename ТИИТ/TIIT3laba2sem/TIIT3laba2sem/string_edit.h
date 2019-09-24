#pragma once
#include <string>
#include <vector>
namespace tiit 
{
	void clean(std::string& str)
	{
		str.erase(str.begin());
		str.erase(prev(str.end()));
		const auto end = str.end();
		auto it = str.begin();
		while (it != end) 
		{
			it = std::find(it, end, ' ');
			if (it == end) 
			{
				break;
			}
			str.erase(it);
			it;
		}
	}

	bool consists(const std::vector<char>& vector, char ch) 
	{
		return std::find(vector.begin(), vector.end(), ch) == vector.end() ? false : true;
	}

	std::vector<std::string> split(const std::string& str)
	{
		std::vector<std::string> result;
		std::vector<char> open_symbols{ '<','{','[' };
		std::vector<char> close_symbols{ '>','}',']' };
		size_t counter = 0;
		auto pos = str.begin();
		if (str == "") 
		{
			result.push_back(str);
			return result;
		}
		for (auto it = str.begin(); it != str.end(); it++) 
		{
			if (*it == ',' && counter == 0) 
			{
				result.push_back(std::string(pos, it));
				pos = next(it);
			}
			else if (consists(open_symbols, *it)) 
			{
				counter++;
			}
			else if (consists(close_symbols, *it)) 
			{
				counter--;
				if (counter == 0) {
					result.push_back(std::string(pos, next(it)));
					if (next(it) != str.end()) 
					{
						pos = next(++it);
					}
				}
			}
			else if (it == prev(str.end())) 
			{
				result.push_back(std::string(1, *it));
			}
		}
		return result;
	}

	std::vector<std::string> modify(std::string& str) 
	{
		clean(str);
		return split(str);
	}
	template<typename T>
	void PrintVector(const std::vector<T>& vect) 
	{
		std::cout << "{";
		if (vect.size() == 0) 
		{
			std::cout << "}";
			return;
		}
		for (auto it = vect.begin(); it != vect.end(); it++) 
		{

			if (it != prev(vect.end()))
			{
				std::cout << *it << ", ";
			}
			else {
				std::cout << *it << "}";
			}
		}
	}
}