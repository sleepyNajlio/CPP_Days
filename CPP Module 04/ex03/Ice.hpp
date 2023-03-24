/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:43:05 by nloutfi           #+#    #+#             */
/*   Updated: 2023/03/24 02:52:41 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();
		AMateria *clone() const;
		void use(ICharacter& target);
};
