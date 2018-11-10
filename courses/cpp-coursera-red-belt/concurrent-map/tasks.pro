TEMPLATE = app
CONFIG += console c++1z -pthread
LIBS += -pthread
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp 

HEADERS += \
    test_runner.h \
    profile.h \


