/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 07:49:37 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/14 01:30:22 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << "<<<<<<<<<<<<<<<MutantStack:>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        std::cout << std::endl;
    }

    {
        std::cout << "<<<<<<<<<<<<<<<List:>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
        
        std::list<int> lstack;
        lstack.push_back(5);
        lstack.push_back(17);
        std::cout << "top: " << lstack.back() << std::endl;
        lstack.pop_back();
        std::cout << "size: " << lstack.size() << std::endl;
        lstack.push_back(3);
        lstack.push_back(5);
        lstack.push_back(737);
        lstack.push_back(0);
        std::list<int>::iterator it = lstack.begin();
        std::list<int>::iterator ite = lstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(lstack);
        std::cout << std::endl;
    }
    return 0;
}