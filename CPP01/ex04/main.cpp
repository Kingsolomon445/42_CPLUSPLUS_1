#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

int is_found(std::string haystack, std::string needle)
{
    for (int i = 0; i < (int)needle.length(); i++)
    {
        if (needle[i] != haystack[i])
            return 0;
    }
    return (1);
}

int get_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

int main(int argc, char *argv[])
{
    std::string str;
    std::stringstream ss;
    std::string word;
    int word_len;

    if (argc < 4)
    {
        std::cout << "Incomplete args" << std::endl;
        return (1);
    }

    std::ifstream file(argv[1]);
    std::ofstream newFile("newFile");
    word_len = get_strlen(argv[2]);
    while (getline (file, str))
    {
        if (!ss.str().empty())
            ss << "\n";
        for (int i = 0; i < (int)str.length(); i++)
        {
            if (is_found(&str[i], argv[2]))
            {
                ss << argv[3];
                i += word_len - 1;
            }
            else
                ss << str[i];
        }
        std::cout << "I got a line" << std::endl;
    }
    std::cout << ss.str() << std::endl;
    newFile << ss.str();
    return 0;
}