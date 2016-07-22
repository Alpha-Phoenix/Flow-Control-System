#include <iostream>
#include <cassert>
#include <cmath>

#include "IModel.hpp"

using namespace std;

void exponencialTest() {
    IModel &growModel = IModel::createModel();
    static ISystem &pop1 = growModel.createSystem(growModel, 100);
    static ISystem &pop2 = growModel.createSystem(growModel, 0);
    IFlow &flow = growModel.createFlow([]() -> double {return (0.01 * pop1.getValue());}, growModel, &pop1, &pop2);
    growModel.run(100);
    assert((abs(pop1 - 36.6032)) <= 0.0001);
    assert((abs(flow.getValue() - 0.366032)) <= 0.0001);
    assert((abs(pop2 - 63.3968)) <= 0.0001);
    growModel.destroy();
}

void logisticTest() {
    IModel &logisticModel = IModel::createModel();
    static ISystem &p1 = logisticModel.createSystem(logisticModel, 100);
    static ISystem &p2 = logisticModel.createSystem(logisticModel, 10);

    IFlow &logistic = logisticModel.createFlow(
                []() -> double {
                    return (0.01 * p2 * (1 - p2 / 70));
                }, logisticModel, &p1, &p2);

    logisticModel.run(100);

    assert((abs(p1 - 88.2167)) <= 0.0001);
    assert((abs(logistic.getValue() - 0.150046)) <= 0.0001);
    assert((abs(p2 - 21.7834)) <= 0.0001);
    logisticModel.destroy();
}

void customTest() {
    IModel &customModel = IModel::createModel();

    static ISystem &Q1 = customModel.createSystem(customModel, 100);
    static ISystem &Q2 = customModel.createSystem(customModel, 0);
    static ISystem &Q3 = customModel.createSystem(customModel, 100);
    static ISystem &Q4 = customModel.createSystem(customModel, 0);
    static ISystem &Q5 = customModel.createSystem(customModel, 0);

    customModel.createFlow([]() -> double {return 0.01*Q1;}, customModel, &Q1, &Q2);
    customModel.createFlow([]() -> double {return 0.01*Q1;}, customModel, &Q1, &Q3);
    customModel.createFlow([]() -> double {return 0.01*Q2;}, customModel, &Q2, &Q5);
    customModel.createFlow([]() -> double {return 0.01*Q2;}, customModel, &Q2, &Q3);
    customModel.createFlow([]() -> double {return 0.01*Q3;}, customModel, &Q3, &Q4);
    customModel.createFlow([]() -> double {return 0.01*Q4;}, customModel, &Q4, &Q1);

    customModel.run(100);

    assert((abs(Q1 - 31.8513)) <= 0.0001);
    assert((abs(Q2 - 18.4003)) <= 0.0001);
    assert((abs(Q3 - 77.1143)) <= 0.0001);
    assert((abs(Q4 - 56.1728)) <= 0.0001);
    assert((abs(Q5 - 16.4612)) <= 0.0001);

    customModel.destroy();
}

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







    IModel &logisticModel = IModel::createModel();
    static ISystem &p1 = logisticModel.createSystem(logisticModel, 100);
    static ISystem &p2 = logisticModel.createSystem(logisticModel, 10);

    IFlow &logistic = logisticModel.createFlow(
                []() -> double {
                    return (0.01 * p2 * (1 - p2 / 70));
                }, logisticModel, &p1, &p2);

    logisticModel.run(100);

    assert((abs(p1 - 88.2167)) <= 0.0001);
    assert((abs(logistic.getValue() - 0.150046)) <= 0.0001);
    assert((abs(p2 - 21.7834)) <= 0.0001);
    logisticModel.destroy();







    IModel &customModel = IModel::createModel();

    static ISystem &Q1 = customModel.createSystem(customModel, 100);
    static ISystem &Q2 = customModel.createSystem(customModel, 0);
    static ISystem &Q3 = customModel.createSystem(customModel, 100);
    static ISystem &Q4 = customModel.createSystem(customModel, 0);
    static ISystem &Q5 = customModel.createSystem(customModel, 0);

    customModel.createFlow([]() -> double {return 0.01*Q1;}, customModel, &Q1, &Q2);
    customModel.createFlow([]() -> double {return 0.01*Q1;}, customModel, &Q1, &Q3);
    customModel.createFlow([]() -> double {return 0.01*Q2;}, customModel, &Q2, &Q5);
    customModel.createFlow([]() -> double {return 0.01*Q2;}, customModel, &Q2, &Q3);
    customModel.createFlow([]() -> double {return 0.01*Q3;}, customModel, &Q3, &Q4);
    customModel.createFlow([]() -> double {return 0.01*Q4;}, customModel, &Q4, &Q1);

    customModel.run(100);

    assert((abs(Q1 - 31.8513)) <= 0.0001);
    assert((abs(Q2 - 18.4003)) <= 0.0001);
    assert((abs(Q3 - 77.1143)) <= 0.0001);
    assert((abs(Q4 - 56.1728)) <= 0.0001);
    assert((abs(Q5 - 16.4612)) <= 0.0001);

    customModel.destroy();
    // Resolver os problemas de alocação
    //exponencialTest();
    //logisticTest();
    //customTest();
    return 0;
}

