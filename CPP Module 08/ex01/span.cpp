/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:51:23 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/13 06:44:36 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : n(0)
{
}

Span::Span(unsigned int n) : n(n)
{
}

Span::Span(Span const & src)
{
    *this = src;
}

Span::~Span()
{
}

Span & Span::operator=(Span const & rhs)
{
    this->n = rhs.n;
    this->v = rhs.v;
    return *this;
}

void Span::addNumber(int n)
{
    if (this->v.size() == this->n)
        throw Span::NoSpaceException();
    this->v.push_back(n);
}

int Span::shortestSpan()
{
    if (this->v.size() < 2)
        throw Span::NoSpanException();
    std::vector<int> v2 = this->v;
    std::sort(v2.begin(), v2.end());
    int min = v2[1] - v2[0];
    for (unsigned int i = 2; i < v2.size(); i++)
    {
        if (v2[i] - v2[i - 1] < min)
            min = v2[i] - v2[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (this->v.size() < 2)
        throw Span::NoSpanException();
    std::vector<int> v2 = this->v;
    std::sort(v2.begin(), v2.end());
    return v2[v2.size() - 1] - v2[0];
}

int genRandom()
{
    return rand();
}

void Span::addRange(int n)
{
    if (this->v.size() + n > this->n)
        throw Span::NoSpaceException();
    std::vector<int> v2(n);
    srand(time(NULL));
    std::generate(v2.begin(), v2.end(), genRandom);
    this->v.insert(this->v.end(), v2.begin(), v2.end());
}

const char* Span::NoSpaceException::what() const throw()
{
    return "No space left";
}

const char* Span::NoSpanException::what() const throw()
{
    return "No span to find";
}

void Span::print_v()
{
    for (unsigned int i = 0; i < this->v.size(); i++)
        std::cout << this->v[i] << std::endl;
}