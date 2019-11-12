QT -= gui
QT += network

CONFIG += console
CONFIG += c++11 console
CONFIG -= app_bundle

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
        main.cpp \
        server.cpp \
        socketServer.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \ \
    TreesHandlers/AATree.h \
    TreesHandlers/BTreeAdmins.h \
    TreesHandlers/BTreeClients.h \
    TreesHandlers/BinarySearchTree.h \
    TreesHandlers/NewAVLTree.h \
    TreesHandlers/NewRBTree.h \
    globalTrees.h \
    helpers/ArticulationPoints.h \
    helpers/Dijkstra.h \
    helpers/Kruskal.h \
    helpers/Neighbor.h \
    helpers/PrimGraph.h \
    helpers/citiesList.h \
    helpers/citiesNode.h \
    helpers/clientProductStackNode.h \
    helpers/clientQueue.h \
    helpers/clientQueueNode.h \
    helpers/exceptionsHandler.h \
    helpers/helpers.h \
    helpers/quickSortHelper.h \
    helpers/salesList.h \
    helpers/salesNode.h \
    helpers/stringSpliter.h \
    modules/modules.h \
    nodeTypes/AANode.h \
    nodeTypes/BNodeAdmin.h \
    nodeTypes/BNodeClient.h \
    nodeTypes/BSNode.h \
    nodeTypes/BaseBinaryNode.h \
    nodeTypes/NewAVLNode.h \
    nodeTypes/NewRBNode.h \
    server.h \
    socketServer.h

DISTFILES += \
    data/Administradores.txt \
    data/Ciudades.txt \
    data/Clientes.txt \
    data/Conexiones.txt \
    data/Inventario.txt \
    data/MarcasProductos.txt \
    data/Pasillos.txt \
    data/ProductosPasillos.txt \
    data/Ptos de articulacion.txt
