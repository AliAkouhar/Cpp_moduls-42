#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0){}

void PhoneBook::SetContact(const Contact& UserInput)
{
    if (index >= 8)
        index = 0;
    contacts[index] = UserInput;
    index++;
}

Contact PhoneBook::GetContact(int i) const{return contacts[i];}//make sure after that checking the status of i