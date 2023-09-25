#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

std::string formatColumn(const std::string text, int width)
{
    if ((int)text.length() > width)
        return text.substr(0, width - 1) + ".";
    else
    {
        std::stringstream ss;
        ss << std::right << std::setw(width) << text;
        return ss.str();
    }
}

std::string getInfo(std::string prompt)
{
    std::string name;

    std::cout << prompt;
    std::cin >> name;
    while (!name.empty() && (name[0] == ' ' || name[0] == '\t' || name[0] == '\n'))
        name.erase(0, 1);
    while (!name.empty() && (name.back() == ' ' || name.back() == '\t' || name.back() == '\n'))
        name.pop_back();
    return name;
}

void    displayContacts(PhoneBook phonebook)
{
    Contact contact;
    std::string col1 = "Index";
    std::string col2 = "First Name";
    std::string col3 = "Last Name";
    std::string col4 = "Nick Name";

    std::cout << "|" << formatColumn(col1, 10)
              << "|" << formatColumn(col2, 10)
              << "|" << formatColumn(col3, 10)
              << "|" << formatColumn(col4, 10) << "|" << std::endl;
    for (int i = 0; i <= phonebook.getIndex(); i++)
    {
        contact = phonebook.searchContact(i);
        std::cout << "|" << formatColumn(std::to_string(contact.getIndex()), 10)
              << "|" << formatColumn(contact.getFirstName(), 10)
              << "|" << formatColumn(contact.getLastName(), 10)
              << "|" << formatColumn(contact.getNickName(), 10) << "|" << std::endl;
    }
}

int main(void)
{
    PhoneBook phonebook;
    Contact contact;
    std::string action;
    std::string firstName;
    std::string lastName;
    std::string nickName;

    phonebook.setIndex();
    while (true)
    {
        std::cout << "Choose amnd type an option:  ADD,   SEARCH,   EXIT" << std::endl;
        std::cin >> action;
        if (action == "ADD")
        {
            firstName = getInfo("Enter First Name:    ");
            lastName = getInfo("Enter Last Name:    ");
            nickName = getInfo("Enter Nick Name:    ");
            contact.setFirstName(firstName);
            contact.setLastName(lastName);
            contact.setNickname(nickName);
            phonebook.addContact(contact);
        }
        else if (action == "SEARCH")
            displayContacts(phonebook);
        else if (action == "EXIT")
            break ;
        else
            std::cout << "Invalid Option!" << std::endl;
    }
    return (0);
}