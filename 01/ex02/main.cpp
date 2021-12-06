#include <iostream>

int
main()
{
  std::string string = "HI THIS IS BRAIN";
  std::string* stringPTR = &string;
  std::string& stringREF = string;

  std::cout << "This is the address of string: " << &string << std::endl;

  std::cout << "This is the address of string using stringPTR: " << stringPTR
	    << std::endl;
  std::cout << "This is the address of string using  stringREF: " << &stringREF
	    << std::endl;

  std::cout << "This is the string using stringPTR: " << *stringPTR
	    << std::endl;
  std::cout << "This is the string using stringREF: " << stringREF << std::endl;
}