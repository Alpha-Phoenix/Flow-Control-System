TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall

SOURCES += main.cpp \
    Flow.cpp \
    Model.cpp \
    System.cpp

HEADERS += \
    ISystem.hpp \
    IFlow.hpp \
    IModel.hpp \
    Flow.hpp \
    Model.hpp \
    System.hpp
