#pragma once
#include <string.h>
#include "Unit.h"
#include "CppUnit.h"
#include "CsUnit.h"
#include "JavaUnit.h"

class CodeGenerator
{
  protected:
    Unit *myClass;

  public:
    virtual std::string generateCode() = 0;
    virtual void generateProgram() = 0;

};

class CppCodeGenerator : CodeGenerator
{
  public:
    CppCodeGenerator(std::string className)
    {
        myClass = new CppClassUnit(className);
    }
    virtual std::shared_ptr<Unit> add(std::string name, std::string return_type, CppClassUnit::Flags flags,
                                      CppClassUnit::AccessModifier mods = CppClassUnit::PRIVATE)
    {
        auto obj = std::make_shared<CppMethodUnit>(name, return_type, flags);
        myClass->add(obj, mods);
        return obj;
    }

    virtual std::shared_ptr<Unit> addPrintToChild(std::shared_ptr<Unit> child, std::string text) {
        auto obj = std::make_shared<CppPrintOperatorUnit>(text);
        child->add(obj, 0);
        return obj;
    }

    std::string generateCode()
    {
        return myClass->compile();
    }

    void generateProgram() {
        add("testFunc1", "void", 0, CppClassUnit::PUBLIC);
        add("testFunc2", "void", CppMethodUnit::STATIC, CppClassUnit::PRIVATE);
        add("testFunc3", "void", CppMethodUnit::VIRTUAL | CppMethodUnit::CONST, CppClassUnit::PUBLIC);
        auto method1 = add("testFunc4", "void", CppMethodUnit::STATIC, CppClassUnit::PROTECTED);
        addPrintToChild(method1, R"(Hello, world!\n)");
    }
};

class CsCodeGenerator : CodeGenerator
{
  public:
    CsCodeGenerator(std::string className)
    {
        myClass = new CsClassUnit(className);
    }
    virtual std::shared_ptr<Unit> add(std::string name, std::string return_type, CsClassUnit::Flags flags,
                                      CsClassUnit::AccessModifier mods = CsClassUnit::PRIVATE)
    {
        auto obj = std::make_shared<CsMethodUnit>(name, return_type, flags);
        myClass->add(obj, mods);
        return obj;
    }

    virtual std::shared_ptr<Unit> addPrintToChild(std::shared_ptr<Unit> child, std::string text) {
        auto obj = std::make_shared<CsPrintOperatorUnit>(text);
        child->add(obj, 0);
        return obj;
    }

    std::string generateCode()
    {
        return myClass->compile();
    }

    void generateProgram() {
        add("testFunc1", "void", 0, CsClassUnit::PUBLIC);
        add("testFunc2", "void", CsMethodUnit::STATIC, CsClassUnit::PRIVATE);
        add("testFunc3", "void", CsMethodUnit::VIRTUAL, CsClassUnit::PUBLIC);
        auto method2 = add("testFunc4", "void", CsMethodUnit::STATIC, CsClassUnit::PROTECTED);
        addPrintToChild(method2, R"(Hello, world!\n)");
    }
};

class JavaCodeGenerator : CodeGenerator
{
  public:
    JavaCodeGenerator(std::string className)
    {
        myClass = new JavaClassUnit(className);
    }
    virtual std::shared_ptr<Unit> add(std::string name, std::string return_type, JavaClassUnit::Flags flags,
                                      JavaClassUnit::AccessModifier mods = JavaClassUnit::PRIVATE)
    {
        auto obj = std::make_shared<JavaMethodUnit>(name, return_type, flags);
        myClass->add(obj, mods);
        return obj;
    }

    virtual std::shared_ptr<Unit> addPrintToChild(std::shared_ptr<Unit> child, std::string text) {
        auto obj = std::make_shared<JavaPrintOperatorUnit>(text);
        child->add(obj, 0);
        return obj;
    }

    std::string generateCode() {
        return myClass->compile();
    }

    void generateProgram()
    {
        add("testFunc1", "void", 0, JavaClassUnit::PUBLIC);
        add("testFunc2", "void", JavaMethodUnit::STATIC, JavaClassUnit::PUBLIC);
        add("testFunc3", "void", JavaMethodUnit::ABSTRACT, JavaClassUnit::PUBLIC);
        auto method = add("testFunc4", "void", JavaMethodUnit::STATIC, JavaClassUnit::PROTECTED);
        addPrintToChild(method, R"(Hello, world!\n)");
    }
};
