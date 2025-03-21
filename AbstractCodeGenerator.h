#pragma once
#include "CodeGenerator.h"

class AbstractCodeGenerator
{
  private:
    CodeGenerator *generator;

  public:
    AbstractCodeGenerator()
    {
    }
    AbstractCodeGenerator(CodeGenerator *generator)
    {
        setCodeGenerator(generator);
    }
    ~AbstractCodeGenerator()
    {
        if (generator != nullptr)
        {
            delete generator;
        }
    }
    void setCodeGenerator(CodeGenerator *generator)
    {
        this->generator = generator;
    }
    std::string generate()
    {
        generator->generateProgram();
        return generator->generateCode();
    }
};
