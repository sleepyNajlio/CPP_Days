/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:17:05 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/24 05:39:59 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	const WrongCat *wwc = new WrongCat();
	
	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wa->getType() << " " << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	std::cout << wwc->getType() << " " << std::endl;
	std::cout << std::endl;
	meta->makeSound(); //animal sound (default)
	j->makeSound(); //Dog sound
	i->makeSound();  //will output the cat sound!
	wa->makeSound();
	wc->makeSound();
	wwc->makeSound();
	std::cout << std::endl;
	delete meta;delete i; delete j;
	delete wa; delete wc; delete wwc;
	return 0;
}