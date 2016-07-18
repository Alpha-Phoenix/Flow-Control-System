#ifndef IMODEL_HPP
#define IMODEL_HPP

#include "IFlow.hpp"
#include "ISystem.hpp"

class IModel
{
public:
    virtual ~IModel() {}
    virtual void run(const int &) = 0;
    static IModel& createModel();
    virtual ISystem& createSystem(IModel&, const int &) = 0;
    virtual IFlow& createFlow(double (* const& expression)(), IModel&, ISystem* const &source, ISystem* const &target) = 0;
};

#endif // IMODEL_HPP

