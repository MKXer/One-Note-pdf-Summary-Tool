#include "PreFormatter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    PreFormatter w;
    
    w.show();


    return a.exec();
}
