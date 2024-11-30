/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:00:31 by aakouhar          #+#    #+#             */
/*   Updated: 2024/10/30 15:17:58 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
class Zombie{
    private:
        std::string name;
    public:
        void setName(const std::string& ZombieName);
        // Zombie(std::string ZombieName);
        Zombie();
        ~Zombie();
        void announce(void) const;
};
Zombie* zombieHorde( int N, std::string name );
#endif