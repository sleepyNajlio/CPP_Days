/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 04:43:57 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/16 08:10:52 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>

class BitcoinExchange 
{
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & src);
        ~BitcoinExchange();
        BitcoinExchange & operator=(BitcoinExchange const & rhs);
        void parse_file(std::string file);
        void exchange(std::ifstream &infile) const;
    private:
        std::map<std::string, float> rates;
};