#include "System.hpp"

System::System(const int &initialValue) : value(initialValue)
{

}

System::System(const ISystem &other)
{
    this->value = static_cast<const System&>(other).value;
}

System::~System()
{

}

const double &System::getValue() const
{
    return this->value;
}

void System::setValue(const double &value)
{
    this->value = value;
}

ISystem& System::operator= (const ISystem &other) {
    if(&other == this)
        return *this;
    *this = other;
    return *this;
}

double operator+ (const ISystem &system, const double &value) {
    const System &s = static_cast<const System&>(system);
    return s.value + value;
}

double operator+ (const double &value, const ISystem &system) {
    const System &s = static_cast<const System&>(system);
    return value + s.value;
}

double operator- (const ISystem &system, const double &value) {
    const System &s = static_cast<const System&>(system);
    return s.value - value;
}

double operator- (const double &value, const ISystem &system) {
    const System &s = static_cast<const System&>(system);
    return value - s.value;
}

double operator* (const ISystem &system, const double &value) {
    const System &s = static_cast<const System&>(system);
    return s.value * value;
}

double operator* (const double &value, const ISystem &system) {
    const System &s = static_cast<const System&>(system);
    return value * s.value;
}

double operator/ (const ISystem &system, const double &value) {
    const System &s = static_cast<const System&>(system);
    return s.value / value;
}

double operator/ (const double &value, const ISystem &system) {
    const System &s = static_cast<const System&>(system);
    return value / s.value;
}
