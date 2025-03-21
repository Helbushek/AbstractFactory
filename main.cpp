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
    CppCodeGenerator cpp("MyClass");
    cpp.generateProgram();
    std::cout << cpp.generateCode();

    devide(50, "C#");
    CsCodeGenerator cs("MyClass");
    cs.generateProgram();
    std::cout << cs.generateCode();

    devide(50, "Java");
    JavaCodeGenerator java("MyClass");
    java.generateProgram();
    std::cout << java.generateCode();
    return 0;
}
