#ifndef ISYSTEM_HPP
#define ISYSTEM_HPP

class ISystem
{
public:
    virtual ~ISystem() {}
    virtual const double& getValue() const = 0;
    virtual void setValue(const double &) = 0;

    virtual ISystem& operator= (const ISystem &other) = 0;

    friend double operator+ (const ISystem &system, const double &value);
    friend double operator+ (const double &value, const ISystem &system);

    friend double operator- (const ISystem &system, const double &value);
    friend double operator- (const double &value, const ISystem &system);

    friend double operator* (const ISystem &system, const double &value);
    friend double operator* (const double &value, const ISystem &system);

    friend double operator/ (const ISystem &system, const double &value);
    friend double operator/ (const double &value, const ISystem &system);
};

#endif // ISYSTEM_HPP

