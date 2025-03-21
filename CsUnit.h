#pragma once
#include "Unit.h"

class CsClassUnit : public Unit
{
  public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        INTERNAL,
        PROTECTED_INTERNAL
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;

  public:
    explicit CsClassUnit(const std::string &name) : m_name(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    void add(const std::shared_ptr<Unit> &unit, Flags flags)
    {
        int accessModifier = PRIVATE;
        if (flags < ACCESS_MODIFIERS.size())
        {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }
    std::string compile(unsigned int level = 0) const
    {
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
        {
            if (m_fields[i].empty())
            {
                continue;
            }
            for (const auto &f : m_fields[i])
            {
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }

  private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};
const std::vector<std::string> CsClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private"};

class CsMethodUnit : public Unit
{
  public:
    enum Modifier
    {
        STATIC = 1,
        VIRTUAL = 1 << 1
    };

  public:
    CsMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
        : m_name(name), m_returnType(returnType), m_flags(flags)
    {
    }
    void add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0)
    {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const
    {
        std::string result;
        if( m_flags & STATIC ) {
            result += "static ";
        } else if( m_flags & VIRTUAL ) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
  private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class CsPrintOperatorUnit : public Unit {
  public:
    explicit CsPrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
  private:
    std::string m_text;
};
