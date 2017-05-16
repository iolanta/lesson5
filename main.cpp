#include <iostream>
#include "task2.h"

int main()
{
    std::string str = "<(((>]";
    std::cout << "before: " << str << std::endl;
    corrects_brackets(str);
    std::cout << "after: " << str << std::endl;
}
