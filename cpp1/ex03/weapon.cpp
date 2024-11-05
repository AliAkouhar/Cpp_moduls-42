/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:06:05 by aakouhar          #+#    #+#             */
/*   Updated: 2024/11/02 15:13:20 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string WeaponType) : type(WeaponType) {}


void Weapon::setType(const std::string& typeName)
{
    type = typeName;
}

const std::string& Weapon::getType() const
{
    return (type);
}