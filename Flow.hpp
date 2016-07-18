#ifndef FLOW_HPP
#define FLOW_HPP

#include "IFlow.hpp"
#include "ISystem.hpp"

class Flow : public IFlow
{
public:
    Flow(double (* const& expression)(), ISystem* const &source, ISystem* const &target);
    virtual ~Flow() override;
    virtual double getValue() const override;
    virtual ISystem& getSource() override;
    virtual ISystem& getTarget() override;
    virtual double execute() override;
protected:
private:
    ISystem *source;
    ISystem *target;
    double value;
    double (*expression)();
};

#endif // FLOW_HPP
