#include "Flow.hpp"

Flow::Flow(double (* const& expression)(), ISystem* const &source = nullptr, ISystem* const &target = nullptr) :
    source(source), target(target), value(0), expression(expression)
{
}

Flow::~Flow()
{
    delete this->source;
    delete this->target;
    this->source = nullptr;
    this->target = nullptr;
}

double Flow::getValue() const
{
    return this->value;
}

ISystem &Flow::getSource()
{
    return *this->source;
}

ISystem &Flow::getTarget()
{
    return *this->target;
}

double Flow::execute()
{
    double result = this->expression();
    this->value = result;
    return this->value;
}

