#ifndef IFLOW_HPP
#define IFLOW_HPP

#include "ISystem.hpp"

class IFlow
{
public:
    virtual ~IFlow() {}
    virtual double getValue() const = 0;
    virtual ISystem& getSource() = 0;
    virtual ISystem& getTarget() = 0;
    virtual double execute() = 0;
};

#endif // IFLOW_HPP

