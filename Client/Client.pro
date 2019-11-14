QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    check/check.cpp \
    clientSocket.cpp \
    graphresults.cpp \
    main.cpp \
    mainwindow.cpp \
    mapgraph.cpp \
    menu.cpp \
    popup.cpp \
    purchase.cpp \
    reports/reports.cpp \
    reports/showbrands.cpp \
    reports/showprod.cpp \
    unloggedMenu/unloggedmenu.cpp

HEADERS += \
    check/check.h \
    clientSocket.h \
    globalClient.h \
    graphresults.h \
    helpers/helpers.h \
    mainwindow.h \
    mapgraph.h \
    menu.h \
    popup.h \
    purchase.h \
    reports/reports.h \
    reports/showbrands.h \
    reports/showprod.h \
    unloggedMenu/unloggedmenu.h

FORMS += \
    check/check.ui \
    graphresults.ui \
    mainwindow.ui \
    mapgraph.ui \
    menu.ui \
    popup.ui \
    purchase.ui \
    reports/reports.ui \
    reports/showbrands.ui \
    reports/showprod.ui \
    unloggedMenu/unloggedmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Test.qrc
