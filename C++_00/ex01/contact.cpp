#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName()
{
    return _firstName;
}

std::string Contact::getLastName()
{
    return _lastName;
}

std::string Contact::getNickName()
{
    return _nickName;
}

std::string Contact::getPhoneNumber()
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return _darkestSecret;
}

int Contact::getIndex()
{
    return _index;
}

void    Contact::setFirstName(std::string name)
{
    _firstName = name;
}

void    Contact::setLastName(std::string name)
{
    _lastName = name;
}

void    Contact::setNickname(std::string name)
{
    _nickName = name;
}

void    Contact::setPhoneNumber(std::string number)
{
    _phoneNumber = number;
}

void    Contact::setDarkestSecret(std::string secret)
{
    _darkestSecret = secret;
}

void    Contact::setIndex(int idx)
{
    _index = idx;
}