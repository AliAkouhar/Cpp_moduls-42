#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
    private:
        std::string FirstName, LastName, PhoneNumber, NickName, DarkestSecret;
    public:
    //Getters
        std::string GetFirstName() const;
        std::string GetLastName() const;
        std::string GetPhoneNumber() const;
        std::string GetDarkestSecret() const;
        std::string GetNickName() const;
    //Setters
        void SetFirstName(const std::string& First) ;
        void SetLastName(const std::string& Last);
        void SetPhoneNumber(const std::string& Number);
        void SetDarkestSecret(const std::string& Secret);
        void SetNickName(const std::string& Nick);
};

#endif