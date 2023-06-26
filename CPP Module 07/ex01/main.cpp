/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:22:34 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/24 01:38:13 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class whatever
{
    private:
        int x;
    public:
        whatever() : x(0) {}
        whatever(int x) : x(x) {}
        int getX() const {return x;}
        whatever &operator=(whatever const *x)
        {
            this->x = x->getX();
            return *this;
        }
};

std::ostream &operator<<(std::ostream &o, whatever const &x)
{
    o << x.getX();
    return o;
}

int main()
{
    int *array = new int[5];
    for (int i = 0; i < 5; i++)
        array[i] = i;
    iter(array, 5, print);
    std::string *array2 = new std::string[5];
    for (int i = 0; i < 5; i++)
        array2[i] = "string" + std::to_string(i);
    iter(array2, 5, print);
    whatever array3[5];
    for (int i = 0; i < 5; i++)
        array3[i] = new whatever(i + 42);
    iter(array3, 5, print);
}