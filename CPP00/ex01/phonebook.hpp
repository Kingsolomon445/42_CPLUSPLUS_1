#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();

        int     getSize();
        void    addContact();
        void    getContact();
        void    displayContacts();


    private:
        int     _size;
        int     _index;
        Contact _contacts[8];

        static std::string getInfo(std::string prompt);
        static std::string formatColumn(const std::string text, int width);
};

#endif