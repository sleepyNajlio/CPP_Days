/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:10:48 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/22 23:17:11 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <typeinfo>


class Base
{
	public:
		virtual ~Base();
};

class A : public Base 
{
};
class B : public Base 
{
};
class C : public Base
{
};

Base* generate(void);
void identify(Base* p);	
void identify(Base& p);