#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include "contact.hpp"

class PhoneBook
{
    private:
        int     index;
        Contact contacts[8];

    public:
        PhoneBook();
        ~PhoneBook();

        void    setIndex();
        int     getIndex();
        void    incrementIndex();
        void    addContact(Contact contact);
        Contact    searchContact(int idx);
};

#endif