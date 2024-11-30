/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:46:25 by aakouhar          #+#    #+#             */
/*   Updated: 2024/11/02 17:45:17 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& nameB) : weaponB(NULL), name(nameB) {}

void HumanB::attack() const
{
    std::cout << name
          <<  " attacks with their "
          << weaponB->getType()
          << std::endl;
}

void HumanB::setWeapon(Weapon& _weapon)
{
    weaponB = &(_weapon);
}