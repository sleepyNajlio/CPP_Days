/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:42:42 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/22 23:04:51 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	
	Data* data = new Data;
	data->str = "Hello World";
	std::cout << "Data: " << data << std::endl;
	std::cout << "str   : " << data->str << std::endl;

	uintptr_t uptr;
	uptr = Serializer::serialize(data);
	std::cout << "uintptr : " << uptr << std::endl;

	data = Serializer::deserialize(uptr);

	std::cout << "Data: " << data << std::endl;
	std::cout << "str   : " << data->str << std::endl;
}