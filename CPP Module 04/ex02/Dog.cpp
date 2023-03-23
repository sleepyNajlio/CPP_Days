/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:07:54 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/23 06:17:57 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor Called" << std::endl;
	this->setType("Dog");
	this->doggoBrain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor Called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->setType("Dog");
	return *this;
}

Dog::~Dog()
{
	delete this->doggoBrain;
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "barf barf" << std::endl;
}