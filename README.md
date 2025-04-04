﻿# Abstract Factory

 ## Main Idea

 Abstract Factory is wrapping solution around ready-to-use code located in [here](https://disk.yandex.ru/i/dtd6RCsC1FCtcg). The main purpose of this solution is to make code-generation easily expandable, according to solid principles.

 ## Solution

 To achieve set goals, code uses abstract factory pattern to make generating certain code with generators that can be passed to abstract generator. 
 Source code contains C++ code generator, that contains:

## Class (MyClass):
### public section:
- void testFunc1()
- virtual void testFunc3()
### protected section:
- static void testFunc4() - prints "Hello, world!\n" to console
### private section:
- static void testFunc2()

## MyClass UML:
![image](https://github.com/user-attachments/assets/2c8e95fe-5866-4d1a-a96c-22163f8d99a7)

To create code, source uses Units logic. Unit is syntaxis unit that answers to what type of object or method unit is, what protection level and modifiers it has.
Unit is responsible for containing child units inside itself and giving them proper tabulation. 

### 3 realisations of base Unit class are:
- ClassUnit: responsible for creating classes
- MethodUnit: responsible for creating methods insode of class or as separate function
- PrintOperatorUnit: responsible for outputing given string to console

## Architecture

![Abstract Factory](https://github.com/Helbushek/AbstractFactory/blob/main/abstractFactory.drawio.svg)

Solution architecture is built on creating inheritants from 3 unit classes for each implementing language (can be more if needed) and creating generator inheritant that will reload 2 functions: 
- void generateProgram(): builds program using add() method of base Unit class
- std::string generateCode(): calls for compile method (or other path of generating std::string representation of generated class)

### AbstractCodeGenerator

Main base class that is used by context. Context can assign any code generator that implements base CodeGenerator to AbstractCodeGenerator.  

## Complete solution UML:

![UML](https://github.com/Helbushek/AbstractFactory/blob/main/abstractFactoryUML.drawio.svg)
