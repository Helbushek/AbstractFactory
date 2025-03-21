#include <iostream>
#include "AbstractCodeGenerator.h"
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
    AbstractCodeGenerator acg;
    CodeGenerator *cpp = new CppCodeGenerator("MyClass");
    CodeGenerator *cs = new CsCodeGenerator("MyClass");
    CodeGenerator *java = new JavaCodeGenerator("MyClass");


    devide(50, "C++");
    acg.setCodeGenerator(cpp);
    std::cout << acg.generate();

    devide(50, "C#");
    acg.setCodeGenerator(cs);
    std::cout << acg.generate();

    devide(50, "Java");
    acg.setCodeGenerator(java);
    std::cout << acg.generate();

    delete cpp;
    delete cs;
    delete java;
    return 0;
}
