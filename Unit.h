#pragma once
#include <memory>
#include <vector>

class Unit
{
  public:
    using Flags = unsigned int;

  public:
    virtual ~Unit() = default;
    virtual void add(const std::shared_ptr<Unit> &, Flags)
    {
        throw std::runtime_error("Not supported");
    }
    virtual std::string compile(unsigned int level = 0) const = 0;

  protected:
    virtual std::string generateShift(unsigned int level) const
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for (unsigned int i = 0; i < level; ++i)
        {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

class ClassUnit : public Unit
{
  public:
    enum AccessModifier
    {
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;

  public:
    explicit ClassUnit(const std::string &name) : m_name(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    virtual void add(const std::shared_ptr<Unit> &unit, Flags flags) = 0;
    virtual std::string compile(unsigned int level = 0) const = 0;

  private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

class MethodUnit : public Unit
{
  public:
    enum Modifier
    {
    };

  public:
    MethodUnit(const std::string &name, const std::string &returnType, Flags flags)
        : m_name(name), m_returnType(returnType), m_flags(flags)
    {
    }
    virtual void add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0)
    {
        m_body.push_back(unit);
    }
    virtual std::string compile(unsigned int level = 0) const = 0;

  private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

class PrintOperatorUnit : public Unit
{
  public:
    explicit PrintOperatorUnit(const std::string &text) : m_text(text)
    {}
    virtual std::string compile(unsigned int level = 0) const = 0;
  private:
    std::string m_text;
};
