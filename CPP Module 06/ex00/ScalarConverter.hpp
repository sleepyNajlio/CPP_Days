/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:42:58 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/21 23:02:34 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class Scalar 
{
	public:
		Scalar();
		Scalar(Scalar const & other);
		virtual ~Scalar();
		Scalar & operator=(Scalar const & rhs);
		static void convert(std::string str);
};