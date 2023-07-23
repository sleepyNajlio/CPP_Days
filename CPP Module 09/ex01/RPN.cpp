/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:38:03 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/21 00:42:47 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string expression) : expression(expression) {
}

RPN::RPN(RPN const &rpn) {
    *this = rpn;
}

RPN &RPN::operator=(RPN const &rpn) {
    this->expression = rpn.expression;
    this->stack = rpn.stack;
    return (*this);
}

RPN::~RPN() {}

int mystoi(char str)
{
    std::stringstream ss(str);
    int num;
    ss >> num;
    return (num);
}

bool is_operator(char token)
{
    if (token == '+' || token == '-' || token == '*' || token == '/')
        return (true);
    return (false);
}

void RPN::calculate()
{
    std::stringstream ss(this->expression);
    char token;
    
    if (this->expression.empty())
    {
        std::cout << "Empty expression" << std::endl;
        return ;
    }
    while (ss >> token)
    {
        if (std::isdigit(token))
            this->stack.push(token - '0');
        else if (is_operator(token))
        {
            if (this->stack.size() < 2)
            {
                std::cout << "Not enough operands" << std::endl;
                return ;
            }
            double a = this->stack.top();
            this->stack.pop();
            double b = this->stack.top();
            this->stack.pop();
            if (token == '+')
                this->stack.push(b + a);
            else if (token == '-')
                this->stack.push(b - a);
            else if (token == '*')
                this->stack.push(b * a);
        else if (token == '/')
        {
            if (a == 0)
            {
                std::cout << "Invalid operation" << std::endl;
                return ;
            } 
                this->stack.push(b / a);
            
        }
        }
        else
        {
            std::cout << "Invalid token" << std::endl;
            return ;
        }
        
    }
    // if (ss.fail())
    // {
        
    //     std::cout << "Invalid token" << std::endl;
    //     return ;
    // }
    if (this->stack.size() == 1)
            std::cout << "result: " << this->stack.top() << std::endl;
        else
            std::cout << "incomplete expression" << std::endl;
}
