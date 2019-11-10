#include <QCoreApplication>
#include "globalTest.h"
#include <iostream>
using namespace std;

testClass test1 = *new testClass(5);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout<<test1.getData1()<<endl;

    return a.exec();
}
