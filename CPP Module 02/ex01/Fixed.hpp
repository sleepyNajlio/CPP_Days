/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:29:26 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/21 02:49:29 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPoint;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const Fixed &other);
        Fixed(const float num);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif