#include "phonebook.hpp"
#include "contact.hpp"

static std::string    getAction()
{
    std::string action;
    std::string cleanedActionStr("");

    std::cout << "Awesome PhoneBook> ";
    std::getline(std::cin, action);
    while (!action.empty() && (action[0] == ' ' || action[0] == '\t' || action[0] == '\n'))
        action.erase(0, 1);
    while (!action.empty() && (action.back() == ' ' || action.back() == '\t' || action.back() == '\n'))
        action.pop_back();
    if (action.empty())
        return getAction();
    for (int i = 0; i < (int)action.size() ; ++i)
        cleanedActionStr.push_back(toupper(action[i]));
    return (cleanedActionStr);
}

int main(void)
{
    PhoneBook phonebook;
    Contact contact;
    std::string action;

    phonebook.setIndex();
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
    std::cout <<"Awesome PhoneBook Closed";
    return (0);
}