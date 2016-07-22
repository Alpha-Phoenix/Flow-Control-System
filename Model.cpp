#include "Model.hpp"
#include "System.hpp"
#include "FLow.hpp"
#include <vector>
#include <algorithm>
std::vector<IModel*> Model::models;

Model::Model()
{
}

Model::~Model()
{
    if (models.empty()) return;
    for (auto it = models.begin(); it != models.end(); it++) {
        Model *model = static_cast<Model*>(*it);
        if (model == this) {
            models.erase(it);
            for (auto flow : model->flows)
                delete flow;
            model->flows.clear();

            for (auto system : model->systems)
                delete system;
            model->systems.clear();
            break;
        }
    }
}


void Model::run(const int &steps)
{
    for (IModel *iModel : Model::models) {
        Model *model = static_cast<Model*>(iModel);
        for (register int i = 0; i < steps; i++) {
            for (IFlow* flow : model->flows)
                flow->execute();
            for (IFlow* flow : model->flows) {
                if (&flow->getSource())
                    flow->getSource().setValue(flow->getSource().getValue() - flow->getValue());
                if (&flow->getTarget())
                    flow->getTarget().setValue(flow->getTarget().getValue() + flow->getValue());
            }
        }
        for (auto flow : model->flows)
            flow->execute();
    }
}

IModel& IModel::createModel()
{
    return Model::createModel();
}

IModel& Model::createModel()
{
    IModel *model = new Model();
    Model::models.push_back(model);
    return *model;
}

ISystem &Model::createSystem(IModel &modelContainer, const int &initialValue = 0)
{
    ISystem *system = new System(initialValue);
    static_cast<Model&>(modelContainer).systems.push_back(system);
    return *system;
}

IFlow &Model::createFlow(double (* const& expression)(), IModel &modelContainer, ISystem* const &source = nullptr, ISystem* const &target = nullptr)
{
    IFlow *flow = new Flow(expression, source, target);
    static_cast<Model&>(modelContainer).flows.push_back(flow);
    return *flow;
}

void Model::destroy()
{
    delete this;
}

