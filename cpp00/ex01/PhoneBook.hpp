#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int index;
public:
    PhoneBook();
    Contact GetContact(int i) const; //getter!!
    void SetContact(const Contact& UserInput); //setter
    void SearshCommand(PhoneBook& UserPhone);
    void AddCommand(PhoneBook& UserPhone);
};
#endif