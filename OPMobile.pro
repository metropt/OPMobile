contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/OPMobile/bin
    INSTALLS += target
}

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog

HEADERS += \
    stickitem.h \
    joystick.h \
    cccom.h

SOURCES += \
    stickitem.cpp \
    joystick.cpp \
    main.cpp \
    cccom.cpp

CONFIG += mobility
MOBILITY += feedback

QT += core gui network svg

RESOURCES += \
    images.qrc

include(deployment.pri)
qtcAddDeployment()
