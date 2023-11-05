#include "Sed.hpp"

Sed::Sed() {}

Sed::Sed(char *f_name)
{
    file.open(f_name);
}

Sed::~Sed()
{
    file.close();
}

void Sed::replace(char *to_replace, char *replace_with)
{
    int word_len;
    int start;
    unsigned long end;

    word_len = strlen(to_replace);
    while (std::getline (file, _str))
    {
        start = 0;
        if (!_ss.str().empty())
            _ss << "\n";
        end = _str.find(to_replace, start);
        while (end != std::string::npos)
        {
            _ss << _str.substr(start, end-start);
            start = end + word_len;
            _ss << replace_with;
            end = _str.find(to_replace, start);
        }
        if ((int)_str.length() > start)
            _ss << _str.substr(start, _str.length()-start);
    }
    _newFile.open("new_file");
    _newFile << _ss.str();
    _newFile.close();
}