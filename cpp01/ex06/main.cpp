/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:45:21 by aakouhar          #+#    #+#             */
/*   Updated: 2024/11/12 13:35:10 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl obj;

    if (ac != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (1);
    }
    obj.complain(av[1]);
    return (0);
}