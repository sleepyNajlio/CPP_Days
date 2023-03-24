/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:36:11 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/24 18:15:10 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
// #include "Leak_Hunter/leak_hunter.h"

void mat()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("fchfg");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	ICharacter* empty = 0;
	std::cout<< "0" << std::endl;
	me->use(0, *bob);
	std::cout<< "1" << std::endl;
	me->use(1, *bob);
	std::cout<< "2" << std::endl;
	me->use(2, *bob);
	std::cout<< "3" << std::endl;
	me->unequip(3);
	me->use(3, *bob);
	std::cout<< "empty" << std::endl;
	me->use(1, *empty);
	
	delete tmp;
	delete bob;
	delete me;
	delete src;
}


int main()
{

	mat();
	std::cout << std::endl;
	// system("leaks Materials");
	return 0;
}