TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    armadillotest.cpp \
    manualimpltest.cpp \
    exprtempltypesizetest.cpp \
    exprtemplsizetest.cpp \
    noexprtempltest.cpp \
    smallvectorstest.cpp

HEADERS += \
    ExprTemplTypeSize/vector.h \
    NoExprTempl/vector.h \
    ExprTemplSize/vector.h
