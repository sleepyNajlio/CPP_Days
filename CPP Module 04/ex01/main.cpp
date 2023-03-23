/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:17:05 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/23 06:35:41 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	int size = 10;
	Animal *animals[size];
	
	std::cout << std::endl;
	for (int i = 0; i < (size / 2) ; i++)
	{
		animals[i] = new Cat();
	}
	std::cout << std::endl;
	for (int j = size / 2; j < size; j++)
		animals[j] = new Dog();
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];
	return 0;
}