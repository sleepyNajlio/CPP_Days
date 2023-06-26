/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 08:42:11 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/25 09:26:05 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const & src);
        ~Array();
        Array & operator=(Array const & other);
        unsigned int size() const;
        T & operator[](int i);
};

template <typename T>
Array<T>::Array()
{
    this->_size = 0;
    this->array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->_size = n;
    this->array = new T[n];
}

template <typename T>
Array<T>::Array(Array const & src)
{
    *this = src;
}

template <typename T>
Array<T>::~Array()
{
    delete [] this->array;
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & other)
{
    if (this != &other)
    {
        this->_size = other._size;
        this->array = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->array[i] = other.array[i];
    }
    return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}

template <typename T>
T & Array<T>::operator[](int i)
{
    if (i < 0 || i >= (int)this->_size)
        throw std::out_of_range("index is out of bounds");
    return this->array[i];
}