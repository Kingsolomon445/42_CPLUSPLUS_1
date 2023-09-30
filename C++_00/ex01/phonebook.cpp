#include "phonebook.hpp"

//CONSTRUCTOR
PhoneBook::PhoneBook () : _size(0), _index(0){ }
//DESTRUCTOR
PhoneBook::~PhoneBook(){ }


// STATIC FUNCTIONS DEFINITIONS
std::string PhoneBook::getInfo(std::string prompt)
{
    std::string info;

    std::cout << prompt;
    std::getline(std::cin, info);
    while (!info.empty() && (info[0] == ' ' || info[0] == '\t' || info[0] == '\n'))
        info.erase(0, 1);
    while (!info.empty() && (info.back() == ' ' || info.back() == '\t' || info.back() == '\n'))
        info.pop_back();
    if (info.empty())
    {
        std::cout << "Fields cannot be empty!" << std::endl;
        return getInfo(prompt);
    }
    return info;
}

std::string PhoneBook::formatColumn(const std::string text, int width)
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



// MEMBER FUNCTIONS DEFINITIONS
int PhoneBook::getSize()
{
    return _size;
}

void    PhoneBook::addContact()
{
    Contact contact;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    firstName = getInfo("Enter First Name:    ");
    lastName = getInfo("Enter Last Name:    ");
    nickName = getInfo("Enter Nick Name:    ");
    phoneNumber = getInfo("Enter Phone Number:    ");
    darkestSecret = getInfo("Enter Darkest Secret:    ");
    contact.setFirstName(firstName);
    contact.setLastName(lastName);
    contact.setNickname(nickName);
    contact.setPhoneNumber(phoneNumber);
    contact.setDarkestSecret(darkestSecret);
    contact.setIndex(_index);
    _contacts[_index] = contact;
    std::cout << "Sucessfully added new contact" << std::endl;
    _index++;
    if (_index == 8)
        _index = 0;
    if (_size < 8)
        _size++;
}


void    PhoneBook::getContact()
{
    std::string info;
    int idx;

    info = getInfo("Enter contact index:   ");
    for (size_t i = 0; i < info.length(); i++)
        {
            if (!std::isdigit(info[i]))
            {
                std::cout << "Index must be in digits!" << std::endl;
                return getContact();
            }
        }
    try
    {
        idx = std::stoi(info);
        if (idx < 0 || idx >= _size)
            throw std::out_of_range("Please enter a number in range 0 - " + std::to_string(_size - 1));
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Invalid input: " << e.what() << std::endl;
        return getContact();
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
        return getContact();
    }
    std::cout << "Contact:";
    std::cout << "First Name:" << _contacts[idx].getFirstName() << std::endl;
    std::cout << "Last Name:" << _contacts[idx].getLastName() << std::endl;
    std::cout << "Nick Name:" << _contacts[idx].getNickName() << std::endl;
    std::cout << "Phone Number:" << _contacts[idx].getFirstName() << std::endl;
    std::cout << "Darkest Secret:" << _contacts[idx].getFirstName() << std::endl;
    
}

void    PhoneBook::displayContacts()
{
    Contact contact;
    std::string col1 = "Index";
    std::string col2 = "First Name";
    std::string col3 = "Last Name";
    std::string col4 = "Nick Name";
    std::string line(45, '-');

    std::cout << line << std::endl;
    std::cout << "|" << this->formatColumn(col1, 10)
              << "|" << this->formatColumn(col2, 10)
              << "|" << this->formatColumn(col3, 10)
              << "|" << this->formatColumn(col4, 10) << "|" << std::endl;
    std::cout << line << std::endl;
    if (_size == 0)
        std::cout << "|" << formatColumn("There are no contacts to display", 43) << "|" << std::endl;
    for (int i = 0; i < _size; i++)
    {
        contact = _contacts[i];
        std::cout << "|" << formatColumn(std::to_string(contact.getIndex()), 10)
              << "|" << formatColumn(contact.getFirstName(), 10)
              << "|" << formatColumn(contact.getLastName(), 10)
              << "|" << formatColumn(contact.getNickName(), 10) << "|" << std::endl;
    }
    std::cout << line << std::endl;
}

