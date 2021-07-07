/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:00:41 by mroux             #+#    #+#             */
/*   Updated: 2021/07/07 22:58:41 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-------- Span.cpp----------

#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N) : _maxElmt(N)
{
}

Span::~Span()
{
}

Span::Span(Span const &cl)
{
	operator=(cl);
}

Span &Span::operator=(Span const &cl)
{
	_v.clear();
	_maxElmt = cl._maxElmt;

	for (unsigned int i = 0; i < _maxElmt; i++)
		_v.push_back(cl._v[i]);

	return (*this);
}

void	Span::addNumber(int i) throw(ArrayFullException)
{
	if (_v.size() == _maxElmt)
		throw ArrayFullException();
	_v.push_back(i);
}

void	Span::addNumber(std::vector<int> v) throw(ArrayFullException)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		addNumber(*it);
}

long Span::shortestSpan() const throw(NotEnoughItems)
{
	if (_v.size() <= 1)
		throw NotEnoughItems();
	long minSpan = __LONG_MAX__;
	std::vector<int> v1 = _v;

	for (std::vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
	{
		for (std::vector<int>::iterator it2 = it1 + 1; it2 != v1.end(); it2++)
		{
			if (abs(*it2 - *it1) < minSpan)
				minSpan = abs(*it2 - *it1);
		}
	}
	return (minSpan);
}

long Span::longestSpan() const throw(NotEnoughItems)
{
	if (_v.size() <= 1)
		throw NotEnoughItems();
	long maxSpan = *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
	return (maxSpan);
}
