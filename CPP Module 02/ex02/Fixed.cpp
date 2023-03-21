/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:52:44 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/21 15:44:12 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    fixedPoint = 0;
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixedPoint = other.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &outs, const Fixed &fixed)
{
    outs << fixed.toFloat();
    return outs;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return this->fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->fixedPoint = raw;
}

Fixed::Fixed(const int num)
{
    // std::cout << "Int constructor called" << std::endl;
    fixedPoint = num << bits;
}

Fixed::Fixed(const float num)
{
    // std::cout << "Float constructor called" << std::endl;
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

//comparison operators:

bool Fixed::operator>(const Fixed &f) const
{
    return this->getRawBits() > f.getRawBits();
}

bool Fixed::operator<(const Fixed &f) const
{
    return this->getRawBits() < f.getRawBits();
}

bool Fixed::operator>=(const Fixed &f) const
{
    return this->getRawBits() >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed &f) const
{
    return this->getRawBits() <= f.getRawBits();
}

bool Fixed::operator==(const Fixed &f) const
{
    return this->getRawBits() == f.getRawBits();
}

bool Fixed::operator!=(const Fixed &f) const
{
    return this->getRawBits() != f.getRawBits();
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed &f) const
{
    return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed &f) const
{
    return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed &f) const
{
    return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) const
{
    if (f.toInt() != 0)
        return Fixed(this->getRawBits() / f.getRawBits());
    else
    {
        std::cout << "error: devision by zero" << std::endl;
        return (Fixed(0));
    }
}

// increment/decrement operators

Fixed Fixed::operator++()
{
    this->fixedPoint++;
    return *this;
}
Fixed Fixed::operator--()
{
    this->fixedPoint--;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed f(*this);
    this->fixedPoint--;
    return f;
}
Fixed Fixed::operator++(int)
{
    Fixed f(*this);
    this->fixedPoint++;
    return f;
}

// static member functions

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    return (f1 > f2 ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    return (f1 < f2 ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    return (f1 > f2 ? f1 : f2);
}

