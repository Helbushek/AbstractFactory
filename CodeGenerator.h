#pragma once
#include <string.h>
#include "Unit.h"
#include "CppUnit.h"
#include "CsUnit.h"
#include "JavaUnit.h"

class CodeGenerator
{
  public:
    virtual std::string generateCode() = 0;
};

class CppCodeGenerator : CodeGenerator
{
  public:
    static std::string generateProgram()
    {
        CppClassUnit myClass("MyClass");
        myClass.add(std::make_shared<CppMethodUnit>("testFunc1", "void", 0), CppClassUnit::PUBLIC);
        myClass.add(std::make_shared<CppMethodUnit>("testFunc2", "void", CppMethodUnit::STATIC), CppClassUnit::PRIVATE);
        myClass.add(std::make_shared<CppMethodUnit>("testFunc3", "void", CppMethodUnit::VIRTUAL | CppMethodUnit::CONST),
                    CppClassUnit::PUBLIC);
        auto method = std::make_shared<CppMethodUnit>("testFunc4", "void", CppMethodUnit::STATIC);
        method->add(std::make_shared<CppPrintOperatorUnit>(R"(Hello, world!\n)"));
        myClass.add(method, CppClassUnit::PROTECTED);
        return myClass.compile();
    }
};

class CsCodeGenerator : CodeGenerator
{
  public:
    static std::string generateProgram()
    {
        CsClassUnit myClass("MyClass");
        myClass.add(std::make_shared<CsMethodUnit>("testFunc1", "void", 0), CsClassUnit::PUBLIC);
        myClass.add(std::make_shared<CsMethodUnit>("testFunc2", "void", CsMethodUnit::STATIC), CsClassUnit::PRIVATE);
        myClass.add(std::make_shared<CsMethodUnit>("testFunc3", "void", CsMethodUnit::VIRTUAL), CsClassUnit::PUBLIC);
        auto method = std::make_shared<CsMethodUnit>("testFunc4", "void", CsMethodUnit::STATIC);
        method->add(std::make_shared<CsPrintOperatorUnit>(R"(Hello, world!\n)"));
        myClass.add(method, CsClassUnit::PROTECTED);
        return myClass.compile();
    }
};

class JavaCodeGenerator : CodeGenerator
{
  public:
    static std::string generateProgram()
    {
        JavaClassUnit myClass("MyClass");
        myClass.isAbstract = false;
        myClass.add(
            std::make_shared< JavaMethodUnit >( "testFunc1", "void", 0 ),
            JavaClassUnit::PUBLIC
            );
        myClass.add(
            std::make_shared< JavaMethodUnit >( "testFunc2", "void", JavaMethodUnit::STATIC ),
            JavaClassUnit::PUBLIC
            );
        myClass.add(
            std::make_shared< JavaMethodUnit >( "testFunc3", "void", JavaMethodUnit::FINAL ),
            JavaClassUnit::PUBLIC
            );
        auto method = std::make_shared< JavaMethodUnit >( "testFunc4", "void",
                                                     JavaMethodUnit::STATIC );
        method->add( std::make_shared< JavaPrintOperatorUnit >( R"(Hello, world!\n)" ) );
        myClass.add( method, JavaClassUnit::PROTECTED );
        return myClass.compile();
    }
};
