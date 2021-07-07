/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:04:36 by mroux             #+#    #+#             */
/*   Updated: 2021/07/08 00:14:18 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <string>
# include <stack>
# include <iterator>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		virtual ~MutantStack();
		MutantStack(MutantStack const&);
		MutantStack&		operator=(MutantStack const&);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
    	iterator end();

	protected:
};

template<class T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
}

template<class T>
MutantStack<T>::~MutantStack()
{
}

template<class T>
MutantStack<T>::MutantStack(MutantStack const& cl) : std::stack<T>(cl)
{
}

template<class T>
MutantStack<T>&				MutantStack<T>::operator=(MutantStack<T> const& cl)
{
	std::stack<T>::operator=(cl);
	return (*this);
}

template<class T>
typename MutantStack<T>::iterator 	MutantStack<T>::begin()
{
	return this->c.begin();
}

template<class T>
typename MutantStack<T>::iterator 	MutantStack<T>::end()
{
	return this->c.end();
}



#endif
