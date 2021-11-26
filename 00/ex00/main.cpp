#include "megaphone.hpp"

int main(int argc, const char** argv)
{
    Megaphone megaphone(std::cout);

    if (argc == 1)
        megaphone.feedback_noise();
    else
    {
        megaphone.increase_volume(argc, argv);
    }
	return 0;
}