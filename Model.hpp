#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>

#include "IModel.hpp"
#include "IFlow.hpp"

class Model : public IModel
{
public:
    Model();
    virtual ~Model() override;
    virtual void run(const int &steps) override;
    static IModel& createModel();
    virtual ISystem& createSystem(IModel &modelContainer, const int &initialValue) override;
    virtual IFlow& createFlow(double (* const& expression)(), IModel &modelContainer, ISystem* const &source, ISystem* const &target) override;
private:
    std::vector<IFlow*> flows;
    std::vector<ISystem*> systems;
    static std::vector<IModel*> models;
};

#endif // MODEL_HPP
