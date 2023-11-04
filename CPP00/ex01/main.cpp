#include "PhoneBook.hpp"

static std::string    getAction()
{
    std::string action;

    if (std::cin.eof() != 1)
        std::cout << "Awesome PhoneBook> ";
    if (!std::getline(std::cin, action) && std::cin.eof())
    {
        std::cin.clear();
        std::cin.ignore();
        return ("EXIT");
    }
    while (!action.empty() && (action[0] == ' ' || action[0] == '\t' || action[0] == '\n'))
        action.erase(0, 1);
    while (!action.empty() && (action[action.size() - 1] == ' ' || action[action.size() - 1] == '\t' || action[action.size() - 1] == '\n'))
        action.erase(action.size() - 1);
    if (action.empty())
        return getAction();
    return (action);
}

int main(void)
{
    PhoneBook phonebook;
    Contact contact;
    std::string action;

    std::cout << "Welcome to My Awesome Phonebook" << std::endl;
    std::cout << "Available options:  ADD,   SEARCH,   EXIT" << std::endl;
    while (true)
    {
        action = getAction();
        if (action == "ADD")
            phonebook.addContact();
        else if (action == "SEARCH")
        {
            phonebook.displayContacts();
            if (phonebook.getSize() > 0)
                phonebook.getContact();
        }
        else if (action == "EXIT")
            break ;
        else
            std::cout << "Invalid Option!" << std::endl;
    }
    return (0);
}
