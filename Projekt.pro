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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/release/ -larmadillo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/debug/ -larmadillo
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/ -larmadillo

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/release/ -lblas
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/debug/ -lblas
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/ -lblas

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/release/ -llapack
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/debug/ -llapack
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/ -llapack

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/release/ -lcblas
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/debug/ -lcblas
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/ -lcblas
