#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
    private:
        int index;
        std::string firstName;
        std::string lastName;
        std::string nickName;

    public:
        //Constrcutor
        Contact();
        //Destructor
        ~Contact();

        //Getters
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        int         getIndex();

        //Setters
        void        setFirstName(std::string name);
        void        setLastName(std::string name);
        void        setNickname(std::string name);
        void        setIndex(int idx);
};

#endif