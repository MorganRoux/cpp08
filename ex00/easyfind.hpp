
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class	NotFoundException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return "Value not found";
		}
	};

template<typename T>
bool easyfind(T& t, int i) throw(NotFoundException)
{
	if (std::find(t.begin(), t.end(), i) == t.end())
		throw NotFoundException();
	return(true);
}

#endif
