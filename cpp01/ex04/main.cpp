/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:05:15 by aakouhar          #+#    #+#             */
/*   Updated: 2024/11/06 14:40:41 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void    ft_replace(std::ofstream& file2, std::string& orig, std::string& repl, std::string& input)
{
    int i;
    std::string Minput;

    i = 0;
    while (input[i])
    {
        if (input.substr(i, orig.length()) == orig)
        {
            Minput += repl;
            i = i + orig.length();
        }
        else 
        {
            Minput += input[i];
            i++;
        }
    }
    file2 << Minput;
}

int main(int ac, char **av)
{
    std::string filename;
    std::string secondfile;
    std::string input;
    std::string orig;
    std::string repl;
    std::ifstream   file;
    std::ofstream   file2;
    bool FirstLine;
    if (ac < 4)
    {
       std::cerr << "enter 3 paramaters\n";
       return (1);
    }
    filename = av[1];
    orig = av[2];
    repl = av[3];
    if (orig.empty() || repl.empty())
    {
        std::cout << "empty string!!\n";
        return (1);
    }
    file.open(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "an error occured when opining file\n";
        return (1);
    }
    secondfile = filename + ".replace";
    file2.open(secondfile.c_str());
    if (!file2.is_open())
    {
        std::cout << "an error occured when opining file\n";
        file.close();
        return (1);
    }
    FirstLine = true;
    while (std::getline(file, input))
    {
        if (!FirstLine)
            file2 << "\n";
        ft_replace(file2, orig, repl, input);
        FirstLine = false;
    }
}
