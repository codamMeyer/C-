#include "megaphone.hpp"

#include <cstring>
#include <iostream>

Megaphone::Megaphone(std::ostream &output):output(output){}

void Megaphone::feedback_noise()
{
    output << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}

void Megaphone::increase_volume( int numInputs, const char *input[])
{
    int i = 1;

    while (i < numInputs - 1)
    {
        output << to_upper(input[i]) << " ";
        ++i;
    }
    output << to_upper(input[i]) << std::endl;
}

std::string Megaphone::ltrim(const std::string &str)
{
    const std::string whitespace = " \n\r\t\f\v";
    const size_t start = str.find_first_not_of(whitespace);
    return (start == std::string::npos) ? "" : str.substr(start);
}   

std::string Megaphone::rtrim(const std::string &str)
{
    const std::string whitespace = " \n\r\t\f\v";
    const size_t end = str.find_last_not_of(whitespace);
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string Megaphone::trim(const std::string &str) {
    return rtrim(ltrim(str));
}

std::string Megaphone::to_upper(std::string str)
{
    const int offset = 32;
    std::string uppercase_str = trim(str);
    
    for (int i = 0; uppercase_str[i] != '\0'; ++i)
    {
        if (islower(uppercase_str[i]))
        {
            uppercase_str[i] -= offset;
        }
    }
    return (uppercase_str);
}