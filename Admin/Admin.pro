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
    adminSocket.cpp \
    check/check.cpp \
    dataBase/checkbrand.cpp \
    dataBase/checkdatabase.cpp \
    dataBase/checkprod.cpp \
    eliminations.cpp \
    eliminations/deleteaisle.cpp \
    eliminations/deletebrand.cpp \
    eliminations/deleteclient.cpp \
    eliminations/deleteproduct.cpp \
    graphresults.cpp \
    insertions.cpp \
    insertions/newaisle.cpp \
    insertions/newbrand.cpp \
    insertions/newclient.cpp \
    insertions/newproduct.cpp \
    main.cpp \
    mainwindow.cpp \
    mapgraph.cpp \
    menu.cpp \
    modifications.cpp \
    modifications/modbasicproduct.cpp \
    modifications/modtax.cpp \
    modifications/pricemod.cpp \
    reports.cpp \
    reports/brandlist.cpp \
    reports/generateall.cpp \
    reports/mostprodaisle.cpp \
    reports/prodlist.cpp \
    reports/showbrands.cpp \
    restock/restock.cpp

HEADERS += \
    adminSocket.h \
    check/check.h \
    dataBase/checkbrand.h \
    dataBase/checkdatabase.h \
    dataBase/checkprod.h \
    eliminations.h \
    eliminations/deleteaisle.h \
    eliminations/deletebrand.h \
    eliminations/deleteclient.h \
    eliminations/deleteproduct.h \
    globalAdmin.h \
    graphresults.h \
    helpers/helpers.h \
    insertions.h \
    insertions/newaisle.h \
    insertions/newbrand.h \
    insertions/newclient.h \
    insertions/newproduct.h \
    mainwindow.h \
    mapgraph.h \
    menu.h \
    modifications.h \
    modifications/modbasicproduct.h \
    modifications/modtax.h \
    modifications/pricemod.h \
    reports.h \
    reports/brandlist.h \
    reports/generateall.h \
    reports/mostprodaisle.h \
    reports/prodlist.h \
    reports/showbrands.h \
    restock/restock.h

FORMS += \
    check/check.ui \
    dataBase/checkbrand.ui \
    dataBase/checkdatabase.ui \
    dataBase/checkprod.ui \
    eliminations.ui \
    eliminations/deleteaisle.ui \
    eliminations/deletebrand.ui \
    eliminations/deleteclient.ui \
    eliminations/deleteproduct.ui \
    graphresults.ui \
    insertions.ui \
    insertions/newaisle.ui \
    insertions/newbrand.ui \
    insertions/newclient.ui \
    insertions/newproduct.ui \
    mainwindow.ui \
    mapgraph.ui \
    menu.ui \
    modifications.ui \
    modifications/modbasicproduct.ui \
    modifications/modprice.ui \
    modifications/modtax.ui \
    reports.ui \
    reports/brandlist.ui \
    reports/generateall.ui \
    reports/mostprodaisle.ui \
    reports/prodlist.ui \
    reports/showbrands.ui \
    restock/restock.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
