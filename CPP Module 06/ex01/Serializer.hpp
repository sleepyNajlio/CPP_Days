/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:43:50 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/22 23:04:21 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

struct Data
{
	std::string str;
};

class Serializer
{
	public:
		Serializer();
		Serializer(Serializer const & other);
		~Serializer();
		Serializer & operator=(Serializer const & other);
		static uintptr_t serialize(Data *ptr);
		static Data	*deserialize(uintptr_t raw);
};