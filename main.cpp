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
    AbstractCodeGenerator& acg = AbstractCodeGenerator::Instance();
    std::shared_ptr<CodeGenerator> cpp = std::make_shared<CppCodeGenerator>("MyClass");
    std::shared_ptr<CodeGenerator> cs = std::make_shared<CsCodeGenerator>("MyClass");
    std::shared_ptr<CodeGenerator> java = std::make_shared<JavaCodeGenerator>("MyClass");


    devide(50, "C++");
    acg.setCodeGenerator(cpp);
    std::cout << acg.generate();

    devide(50, "C#");
    acg.setCodeGenerator(cs);
    std::cout << acg.generate();

    devide(50, "Java");
    acg.setCodeGenerator(java);
    std::cout << acg.generate();

    return 0;
}
