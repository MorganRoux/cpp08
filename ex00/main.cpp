#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vi;
	std::string a = "7";
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	std::cout << 2 << std::endl;
	try
	{
		easyfind(vi, 2);
	}
	catch (NotFoundException e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << 4 << std::endl;
	try
	{
		easyfind(vi, 4);
	}
	catch (NotFoundException e)
	{
		std::cout << e.what() << std::endl;
	}
}
