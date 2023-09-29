#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"

class PhoneBook
{
    private:
        int     index;
        int     size;
        Contact contacts[8];

    public:
        PhoneBook();
        ~PhoneBook();

        void    setIndex();
        void    setSize();
        int     getIndex();
        int     getSize();
        void    addContact();
        void    getContact();
        std::string getInfo(std::string prompt);
        static std::string formatColumn(const std::string text, int width);
        void    displayContacts();
};

#endif