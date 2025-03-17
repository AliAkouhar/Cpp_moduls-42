#include "Contact.hpp"


//Implimentation of Getters
std::string Contact::GetFirstName() const{
    return (FirstName);
}

std::string Contact::GetLastName() const{
    return (LastName);
}

std::string Contact::GetNickName() const{
    return (NickName);
}

std::string Contact::GetDarkestSecret() const{
    return (DarkestSecret);
}

std::string Contact::GetPhoneNumber() const{
    return (PhoneNumber);
}
//Implimentation of Setters

void Contact::SetFirstName(const std::string& First)
{
    FirstName = First;
}

void Contact::SetLastName(const std::string& Last)
{
    LastName = Last;
}


void Contact::SetNickName(const std::string& Nick)
{
    NickName = Nick;
}
void Contact::SetPhoneNumber(const std::string& Number)
{
    PhoneNumber = Number;
}
void Contact::SetDarkestSecret(const std::string& Secret)
{
    DarkestSecret = Secret;
}

