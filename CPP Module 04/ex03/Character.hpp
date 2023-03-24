/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:51:17 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/24 04:56:07 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
class ICharacter;

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *Inventory[4];
		int invSize;
	public:
		Character();
		Character(std::string _name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};