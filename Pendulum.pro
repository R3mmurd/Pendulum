QMAKE_CXX = clang++

CONFIG += c++14

QT +=  core widgets

TEMPLATE += app

TARGET = pendulum

HEADERS += \
    pendulum.H \
    panel.H

SOURCES += \
    pendulum.C \
    panel.C \
    main.C
