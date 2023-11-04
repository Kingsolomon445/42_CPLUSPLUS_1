#include "PhoneBook.hpp"

//CONSTRUCTOR
PhoneBook::PhoneBook () : _size(0), _index(0){ }
//DESTRUCTOR
PhoneBook::~PhoneBook(){ }


// STATIC FUNCTIONS DEFINITIONS
std::string PhoneBook::getInfo(std::string prompt)
{
    std::string info;

    std::cout << prompt;
    if (!std::getline(std::cin, info) && std::cin.eof())
    {
        std::cin.clear();
        std::cin.ignore();
        return ("");
    }
    while (!info.empty() && (info[0] == ' ' || info[0] == '\t' || info[0] == '\n'))
        info.erase(0, 1);
    while (!info.empty() && (info[info.size() - 1] == ' ' || info[info.size() - 1] == '\t' || info[info.size() - 1] == '\n'))
        info.erase(info.size() - 1);
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
    if (firstName.empty())
        return ;
    lastName = getInfo("Enter Last Name:    ");
    if (lastName.empty())
        return ;
    nickName = getInfo("Enter Nick Name:    ");
    if (nickName.empty())
        return ;
    phoneNumber = getInfo("Enter Phone Number:    ");
    if (phoneNumber.empty())
        return ;
    darkestSecret = getInfo("Enter Darkest Secret:    ");
    if (darkestSecret.empty())
        return ;
    contact.setFirstName(firstName);
    contact.setLastName(lastName);
    contact.setNickname(nickName);
    contact.setPhoneNumber(phoneNumber);
    contact.setDarkestSecret(darkestSecret);
    contact.setIndex(_index);
    _contacts[_index] = contact;
    _index++;
    if (_index == 8)
        _index = 0;
    if (_size < 8)
        _size++;
    std::cout << "Sucessfully added new contact" << std::endl;
}


void    PhoneBook::getContact()
{
    std::string info;
    std::stringstream ss;
    int idx;

    info = getInfo("Enter contact index:   ");
    if (info == "")
        return ;
    for (size_t i = 0; i < info.length(); i++)
        {
            if (!std::isdigit(info[i]))
            {
                std::cout << "Index must be in positive digits!" << std::endl;
                return getContact();
            }
        }
    try
    {
        ss << info;
        ss >> idx;
        idx--;
        ss.str("");
        ss.clear();
        ss << _size;
        if (idx < 0 || idx >= _size)
            throw std::out_of_range("Please enter a number in range 1 - " + ss.str());
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
    std::cout << "Contact:" << std::endl;
    std::cout << "   First Name:" << _contacts[idx].getFirstName() << std::endl;
    std::cout << "   Last Name:" << _contacts[idx].getLastName() << std::endl;
    std::cout << "   Nick Name:" << _contacts[idx].getNickName() << std::endl;
    std::cout << "   Phone Number:" << _contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "   Darkest Secret:" << _contacts[idx].getDarkestSecret() << std::endl;
    
}

void    PhoneBook::displayContacts()
{
    Contact contact;
    std::string col1 = "Index";
    std::string col2 = "First Name";
    std::string col3 = "Last Name";
    std::string col4 = "Nick Name";
    std::string line(45, '-');
    std::stringstream ss;

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
        ss << contact.getIndex() + 1;
        std::cout << "|" << formatColumn(ss.str(), 10)
              << "|" << formatColumn(contact.getFirstName(), 10)
              << "|" << formatColumn(contact.getLastName(), 10)
              << "|" << formatColumn(contact.getNickName(), 10) << "|" << std::endl;
        ss.str("");
        ss.clear();
    }
    std::cout << line << std::endl;
}

