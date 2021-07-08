/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:00:44 by mroux             #+#    #+#             */
/*   Updated: 2021/07/08 09:15:28 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

class Span
{
public:
	class ArrayFullException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Array full");
		}
	};
	class NotEnoughItems : public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Array full");
		}
	};

	Span(unsigned int);
	~Span();
	Span(Span const &);
	Span &operator=(Span const &);
	void addNumber(int i) throw(ArrayFullException);
	template <template <class T, class Allocator = std::allocator<T> > class Container>
	void addNumber(Container<int> v) throw(ArrayFullException);
	long shortestSpan() const throw(NotEnoughItems);
	long longestSpan() const throw(NotEnoughItems);

protected:
	Span();
	std::vector<int> _v;
	unsigned int _maxElmt;
};

template <template <class T, class Allocator = std::allocator<T> > class Container>
void Span::addNumber(Container<int> v) throw(ArrayFullException)
{
	for (typename Container<int>::iterator it = v.begin(); it != v.end(); it++)
		addNumber(*it);
}

#endif
