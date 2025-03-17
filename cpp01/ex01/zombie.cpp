/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:00:25 by aakouhar          #+#    #+#             */
/*   Updated: 2024/10/30 15:20:52 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(const std::string& zombieName)
{
    name = zombieName;
}

Zombie::Zombie() : name("unnamed"){}

Zombie::~Zombie()
{
    std::cout << name << "is destroyed" << std::endl;
}

void Zombie::announce(void) const{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}