/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:00:19 by aakouhar          #+#    #+#             */
/*   Updated: 2024/10/30 14:23:35 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *horde = zombieHorde(20 , "Zombie");
    int i;

    i = 0;
    while(i < 20)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}
