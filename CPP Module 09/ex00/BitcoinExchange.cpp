/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 04:44:16 by nloutfi           #+#    #+#             */
/*   Updated: 2023/07/22 23:05:43 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int mystoi(std::string str)
{
    std::stringstream ss(str);
    int num;
    ss >> num;
    return (num);
}

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    std::string key;
    float value;

    if (file.is_open())
    {
        std::getline(file, key);
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

bool check_feb(std::string day, std::string year)
{
    if (mystoi(year) % 4 == 0)
    {
        if (mystoi(day) > 29 || mystoi(day) < 1)
            return (false);
    }
    else
    {
        if (mystoi(day) > 28 || mystoi(day) < 1)
            return (false);
    }
    return (true);
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
    if (mystoi(year) > 2023 || mystoi(year) < 2009)
        return (false);
    if (mystoi(month) > 12 || mystoi(month) < 1)
        return (false);
    if (mystoi(day) > 31 || mystoi(day) < 1)
        return (false);
    if (mystoi(month) == 2)
        return (check_feb(day, year));
    return (true);
}



bool check(std::string date,char delim, float value)
{
    if (!check_date(date))
        return (false);
    if (delim != '|')
        return (false);
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
        std::cout << date << " => " << value << " = " << it->second * value << std::endl;
    }
    //finds the closest (lower) date
    else
    {
        it = rates.lower_bound(date);
        std::cout << date << " => " << value << " = " << (--it)->second * value << std::endl;
    }
}

bool check_val(float value)
{
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (true);
    }
    else if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (true);
    }
    return (false);
}

void   BitcoinExchange::parse_file(std::string file)
{
    std::ifstream infile(file);
    std::string line;

    
    if (!infile.is_open())
    {
        std::cout << "Cannot open file" << std::endl;
        return ;
    }
    //read first line
    std::getline(infile, line);
    if (line.empty())
    {
        std::cout << "empty file" << std::endl;
        return ;
    }
    //read rest of file
    while (std::getline(infile, line))
    {
        std::string date, rest;
        char delim;
        float value;
        std::stringstream ss(line);
        
        ss >> date >> delim >> value;
        if (ss.fail())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        
        ss >> rest;
        if (check_val(value))
            continue ;
        if (check(date, delim, value) && rest.empty())
        {
            get_rate(this->rates, date, value);
        }
        else
            std::cout << "Error: bad input => " << line << std::endl;
        
        
    }
    infile.close();
}


