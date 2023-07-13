/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:49:39 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/13 06:38:35 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <random>

class Span {
    private:
        unsigned int n;
        std::vector<int> v;
    public:
        Span();
        Span(unsigned int n);
        Span(Span const & src);
        ~Span();
        Span & operator=(Span const & rhs);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void addRange(int n);
        void print_v();
        class NoSpaceException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class NoSpanException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
