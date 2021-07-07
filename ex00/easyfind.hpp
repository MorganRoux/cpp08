
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>

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
	typename T::iterator it;
	for(it = t.begin(); it!=t.end(); it++)
    {
        if (*it == i)
		{
			std::cout << "Found !" << std::endl;
			return (true);
		}
    }
	throw NotFoundException();
	return(false);
}

#endif
