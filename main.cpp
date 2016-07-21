#include <iostream>
#include <cassert>
#include <cmath>

#include "IModel.hpp"

using namespace std;

int main()
{
    IModel &growModel = IModel::createModel();
    static ISystem &pop1 = growModel.createSystem(growModel, 100);
    static ISystem &pop2 = growModel.createSystem(growModel, 0);
    IFlow &flow = growModel.createFlow([]() -> double {return (0.01 * pop1.getValue());}, growModel, &pop1, &pop2);
    growModel.run(100);
    assert((abs(pop1 - 36.6032)) <= 0.0001);
    assert((abs(flow.getValue() - 0.366032)) <= 0.0001);
    assert((abs(pop2 - 63.3968)) <= 0.0001);
    growModel.destroy();

    // Resolver os problemas de alocação
    return 0;
}

