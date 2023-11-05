#ifndef SED_H
# define SED_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

class Sed
{
    private:
        std::string _str;
        std::ofstream _newFile;
        std::stringstream _ss;

    public:
        Sed();
        Sed(char *f_name);
        ~Sed();

        std::ifstream file;
        void replace(char *to_replace, char *replace_with);
};

#endif