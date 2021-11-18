#ifndef MEGAPHONE_H
# define MEGAPHONE_H
# include <iostream>

class Megaphone
{
public:
    Megaphone(std::ostream &output):output(output){}
    void feedback_noise();
    void increase_volume( int numInputs, char *input[]);
private:
    bool is_lower(char c);
    std::string ltrim(const std::string &s);
    std::string rtrim(const std::string &s);
    std::string trim(const std::string &s);
    std::string to_upper(std::string str);
    std::ostream &output;
};

#endif