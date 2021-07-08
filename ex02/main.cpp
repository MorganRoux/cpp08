/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:06:16 by mroux             #+#    #+#             */
/*   Updated: 2021/07/08 09:47:07 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <deque>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(36);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "------" << std::endl;
	for (MutantStack<int>::iterator it1 = mstack.begin(); it1 != mstack.end(); ++it1)
	{
		for (MutantStack<int>::iterator  it2 = it1; it2 != mstack.end(); ++it2)
			std::cout << *it1 << " - " << *it2 << " = " << *it1 - *it2 << std::endl;
	}

	std::cout << "------" << std::endl;
	std::stack<int> s(mstack);
	std::cout << s.top() << std::endl;

	return 0;
}
