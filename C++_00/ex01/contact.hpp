#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
    private:
        int index;
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        //Constrcutor
        Contact();
        //Destructor
        ~Contact();

        //Getters
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        int         getIndex();

        //Setters
        void        setFirstName(std::string name);
        void        setLastName(std::string name);
        void        setNickname(std::string name);
        void        setPhoneNumber(std::string number);
        void        setDarkestSecret(std:: string secret);
        void        setIndex(int idx);
};

#endif