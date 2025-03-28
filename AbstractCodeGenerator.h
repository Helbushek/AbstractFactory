#pragma once
#include "CodeGenerator.h"

class AbstractCodeGenerator
{
  private:
    std::shared_ptr<CodeGenerator> generator;
    AbstractCodeGenerator(){};
    AbstractCodeGenerator &operator=(AbstractCodeGenerator &other) = delete;
    AbstractCodeGenerator(AbstractCodeGenerator &other) = delete;

  public:
    static AbstractCodeGenerator &Instance()
    {
        static AbstractCodeGenerator instance;
        return instance;
    }

    void setCodeGenerator(std::shared_ptr<CodeGenerator>& generator)
    {
        this->generator = generator;
    }
    std::string generate()
    {
        generator->generateProgram();
        return generator->generateCode();
    }
};
