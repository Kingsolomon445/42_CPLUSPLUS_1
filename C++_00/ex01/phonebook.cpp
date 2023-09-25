#include "phonebook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

int PhoneBook::getIndex()
{
    return this->index;
}

void    PhoneBook::setIndex()
{
    this->index = 0;
}

void    PhoneBook::incrementIndex()
{
    this->index++;
}


void    PhoneBook::addContact(Contact contact)
{
    this->contacts[this->index] = contact;
    this->incrementIndex();
}

Contact    PhoneBook::searchContact(int idx)
{
    return this->contacts[idx];
}

