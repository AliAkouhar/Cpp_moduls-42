/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:23 by aakouhar          #+#    #+#             */
/*   Updated: 2024/11/04 12:28:14 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& nameA, Weapon& obj) 
    : WeaponA(obj)
    , name(nameA)
    {}
void HumanA::attack()
{
    std::cout << name
              <<  " attacks with their "
              << WeaponA.getType()
              << std::endl;
}