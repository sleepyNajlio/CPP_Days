/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 04:44:16 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/16 08:30:37 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    std::string key;
    float value;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::getline(ss, key, ',');
            ss >> value;
            rates.insert(std::pair<std::string, float>(key, value));
            ss.clear();
        }
        file.close();
    }
    else
        std::cout << "Data Missing" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & other)
{
    if (this != &other)
    {
        this->rates = other.rates;
    }
    return (*this);
}

bool check_date(std::string date)
{
    std::string year, month, day;
    std::stringstream ss(date);
    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    ss >> day;
    if (year.size() != 4 || month.size() != 2 || day.size() != 2)
        return (false);
    if (std::stoi(month) > 12 || std::stoi(month) < 1)
        return (false);
    if (std::stoi(day) > 31 || std::stoi(day) < 1)
        return (false);
}



bool check(std::string date, char delim, float value)
{
    if (delim != '|' && !check_date(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    }
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (false);
    }
    else if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (false);
    }
    else
        return (true);
}

void get_rate(std::map<std::string, float> &rates, std::string date, float value)
{
    std::map<std::string, float>::iterator it;
    std::string year, month, day;
    std::stringstream ss(date);
    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    ss >> day;
    
    it = rates.find(date);
    if (it != rates.end())
    {
        std::cout << "Exchange rate for " << date << " is " << it->second * value << std::endl;
    }
    else
    {
        rates.insert(std::pair<std::string, float>(key, value));
    }
}

void   BitcoinExchange::parse_file(std::string file)
{
    std::ifstream infile(file);
    std::string line, date, rest;
    char delim;
    float value;
    std::stringstream ss;
    
    if (!infile.is_open())
    {
        std::cout << "Cannot open file" << std::endl;
        return ;
    }
    
    std::getline(infile, line);
    if (line.empty())
    {
        std::cout << "empty file" << std::endl;
        return ;
    }
    while (std::getline(infile, line))
    {
        ss << line;
        
        ss >> date >> value >> rest;
        if (!ss.fail() && !rest.empty())
        {
            if (check(date, delim, value))
            {
                get_rate(this->rates, date, value);
            }
        }
    }
    
    infile.close();
}

void BitcoinExchange::exchange(std::ifstream &infile) const
{
    
}
