/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:24:37 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/21 00:10:48 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <sstream>

class RPN 
{
    private:
        std::string expression;
        std::stack<int> stack;
    public:
        RPN();
        RPN(std::string expression);
        RPN(RPN const &rpn);
        RPN &operator=(RPN const &rpn);
        ~RPN();
        void calculate();
};