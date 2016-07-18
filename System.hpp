#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "ISystem.hpp"

class System : public ISystem
{
public:
    System(const int &initialValue);
    System(const ISystem &other);
    virtual ~System() override;
    virtual const double& getValue() const override;
    virtual void setValue(const double &value) override;

    virtual ISystem& operator= (const ISystem &other) override;

    friend double operator+ (const ISystem &system, const double &value);
    friend double operator+ (const double &value, const ISystem &system);

    friend double operator- (const ISystem &system, const double &value);
    friend double operator- (const double &value, const ISystem &system);

    friend double operator* (const ISystem &system, const double &value);
    friend double operator* (const double &value, const ISystem &system);

    friend double operator/ (const ISystem &system, const double &value);
    friend double operator/ (const double &value, const ISystem &system);
private:
    double value;
};

#endif // SYSTEM_HPP
