#include <iostream>

class Megaphone
{
public:
    std::string output;

    void feedback_noise()
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }

    void increase_volume( int numInputs, char *input[])
    {
        int i = 1;
        while (i < numInputs - 1)
        {
        	output.append(to_upper(input[i]));
        	output.append(" ");
            ++i;
        }
        output.append(to_upper(input[i]));
        std::cout << output << std::endl;
    }
private:

    bool is_lower(char c)
    {
        return (c >= 'a' && c <= 'z');
    }

    std::string ltrim(const std::string &s)
    {
        const std::string whitespace = " \n\r\t\f\v";
        size_t start = s.find_first_not_of(whitespace);
        return (start == std::string::npos) ? "" : s.substr(start);
    }

    std::string rtrim(const std::string &s)
    {
        const std::string whitespace = " \n\r\t\f\v";
        size_t end = s.find_last_not_of(whitespace);
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }

    std::string trim(const std::string &s) {
        return rtrim(ltrim(s));
    }

    std::string to_upper(std::string str)
    {
        str = trim(str);
        std::string uppercase_str = str;
        int offset = 32;
        int i = 0;
        while (uppercase_str[i] != '\0')
        {
            if (is_lower(uppercase_str[i]))
            {
                uppercase_str[i] -= offset;
            }
            ++i;
        }
        return (uppercase_str);
    }
};

int main(int argc, char** argv)
{
    Megaphone megaphone;

    if (argc == 1)
        megaphone.feedback_noise();
    else
    {
        megaphone.increase_volume(argc, argv);
    }
	return 0;
}