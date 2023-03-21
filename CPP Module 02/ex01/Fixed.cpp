/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:52:44 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/21 03:04:51 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixedPoint = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixedPoint = other.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return this->fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPoint = raw;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPoint = num << bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    fixedPoint = static_cast<int> (std::roundf(num * (1 << bits)));
}

float Fixed::toFloat() const
{
    return static_cast<float>(this->fixedPoint / static_cast<float>(1 << this->bits));
}

int Fixed::toInt() const
{
    return this->fixedPoint >> this->bits;
}