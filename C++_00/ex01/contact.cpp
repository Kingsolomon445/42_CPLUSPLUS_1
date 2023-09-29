#include "contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{
    
}

std::string Contact::getFirstName()
{
    return this->firstName;
}

std::string Contact::getLastName()
{
    return this->lastName;
}

std::string Contact::getNickName()
{
    return this->nickName;
}

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}

int Contact::getIndex()
{
    return this->index;
}

void    Contact::setFirstName(std::string name)
{
    this->firstName = name;
}

void    Contact::setLastName(std::string name)
{
    this->lastName = name;
}

void    Contact::setNickname(std::string name)
{
    this->nickName = name;
}

void    Contact::setPhoneNumber(std::string number)
{
    this->phoneNumber = number;
}

void    Contact::setDarkestSecret(std::string secret)
{
    this->darkestSecret = secret;
}

void    Contact::setIndex(int idx)
{
    this->index = idx;
}