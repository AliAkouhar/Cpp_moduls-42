/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:54:45 by aakouhar          #+#    #+#             */
/*   Updated: 2024/10/31 15:07:43 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str;
    std::string& stringREF = str;
    std::string* stringPTR;
    
    stringPTR = &str;    
    str = "HI THIS IS BRAIN";

    std::cout << "the memory address of str-->            " << &str << std::endl;
    std::cout << "the memory address of strinfREF-->      " << &stringREF << std::endl;
    std::cout << "the memory address held by stringPTR--> " << stringPTR << std::endl;

    std::cout << "The value of the string variable-->  " << str << std::endl;
    std::cout << "The value pointed to by stringPTR--> " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF--> " << stringREF << std::endl;
    
}