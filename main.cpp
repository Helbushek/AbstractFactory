#include <iostream>
#include "CodeGenerator.h"

void devide(int length, std::string name)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << "=";
    }
    std::cout << "\n" + name + " code: \n";
    for (int i = 0; i < length; ++i)
    {
        std::cout << "=";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[])
{
    devide(50, "C++");
    std::cout << CppCodeGenerator::generateProgram() << std::endl;
    devide(50, "C#");
    std::cout << CsCodeGenerator::generateProgram() << std::endl;
    devide(50, "Java");
    std::cout << JavaCodeGenerator::generateProgram() << std::endl;
    return 0;
}
