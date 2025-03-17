#include "Character.hpp"

// Garbage* Character::collect;
// Garbage* Character::tmp_collect;
// int Character::count = 0;

// Character::Character(std::string name) : _name(name)
// {
//     count++;
//     for (int i = 0; i < 4; i++)
//         inventory[i] = NULL;
// }
// void Character::free_collector(){

//     Garbage *tt;
//     while (tmp_collect)
//     {
//         tt = tmp_collect;
//         tmp_collect = tmp_collect->next;
//         delete tt;
//     }
// }

// Character::~Character()
// {
//     count--;
//     for (int i = 0; i < 4; i++)
//     {
//         if (inventory[i])
//         delete inventory[i];
//     }
//     // std::cout << "here" << "\n";

//     if (count == 0)
//         free_collector();
// }

// Character::Character(const Character& other)
// {
//     *this = other;
//     count++;
// }

// Character& Character::operator=(const Character& other)
// {
//     if (this != &other)
//     {
//         for (int i = 0; i < 4; i++)
//         {
//             if (inventory[i])
//             {
//                 delete inventory[i];
//                 inventory[i] = other.inventory[i]->clone();
//             }
//         }
//     }
//     return *this;
// }

// std::string const& Character::getName() const{
//     return _name;
// }

// void Character::remove_it_from_garbage(Garbage*& collect, AMateria* addr)
// {
//     Garbage* prev = NULL;
//     Garbage* current = collect;

//     while (current)
//     {
//         if (current->addr == addr)
//         {
//             if (prev)
//                 prev->next = current->next;
//             else
//                 collect = current->next; // Update head if the first node is being removed

//             delete current;
//             return;
//         }
//         prev = current;
//         current = current->next;
//     }
// }


// std::string Character::getMateria(int idx)
// {
//     return inventory[idx]->getType();
// }

// void Character::equip(AMateria* m)
// {

//     int i = 0;
//     while(i < 4)
//     {
//         if (!inventory[i])
//         {
//             inventory[i] = m;
//             break ;
//         }
//         i++;
//     }
// }

// int Character::check_garbage(Garbage *list, AMateria* adr)
// {
//     while(list)
//     {
//         if (adr == list->addr)
//             return 0;
//     }
//     return 1;
// }

// void Character::unequip(int idx)
// {ollect;
// int Character::count = 0;
//         {
//             collect = new Garbage(inventory[idx]);
//             tmp_collect = collect;
//         }
//         else if (check_garbage(collect, inventory[idx]))
//         {
//         std::cout << "wselt\n";
//             collect->next = new Garbage(inventory[idx]);
//             collect = collect->next;
//         }
//         inventory[idx] = NULL;
//     }
//     else
//         std::cout << "Invalid index\n";
// }

// void Character::use(int idx, ICharacter& target)
// {
//     if (idx >= 0 && idx < 4 && inventory[idx])
//         inventory[idx]->use(target);
// }

Garbage* Character::collect;
Garbage* Character::tmp_collect;
int Character::count = 0;

std::string const& Character::getName() const {
    return _name;
}
void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == m)
            return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL){
            inventory[i] = m;
            return ;
        }
    }
}

int Character::check_garbage(Garbage *list, AMateria* adr)
{
    while (list)
    {
        if (list->addr == adr)
            return (0);
        list = list->next;
    }
    return (1);
}

int Character::checkMateria(Garbage **tmp, AMateria *adr)
{
    Garbage* list = *tmp;
    while (list)
    {
        if (list->addr == adr)
        {
            list->addr = NULL;
            return (0);
        }
        list = list->next;
    }
    return (1);
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 )
        return;
    if (!collect)
    {
        collect = new Garbage (inventory[idx]);
        std::cout << inventory[idx]->getType() << std::endl;
        tmp_collect = collect;
    }
    else if (check_garbage(tmp_collect, inventory[idx]))
    {
        collect->next = new Garbage(inventory[idx]);
        collect = collect->next;
        std::cout << "oliiii\n";
    }
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        count++;
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                checkMateria(&tmp_collect, inventory[i]);
                delete inventory[i];
                inventory[i] = other.inventory[i]->clone();
            }
        }
    }
    return *this;
// } std::cout << tmp_collect << "\n"
}
Character::Character(std::string name) : _name(name)
{
    count++;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& other)
{
    *this = other;
}
Character::~Character()
{
    count--;
    for (int i = 0; i < 4; i++)
    {
        checkMateria(&tmp_collect, inventory[i]);
        delete inventory[i];
    }
    std::cout << "here" << "\n";

    if (count == 0)
    {
        std::cout << "m here\n";
        free_collector();
    }
}

void Character::free_collector(){

    Garbage *tt;
    
    while (tmp_collect)
    {
        tt = tmp_collect;
        tmp_collect = tmp_collect->next;
        delete tt;
    }
}