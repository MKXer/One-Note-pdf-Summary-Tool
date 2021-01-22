#include "SourceFormatter.h"
#include <QtWidgets/QApplication>
#include <QClipboard>
#include <QMimeData>
#include "SourceHighlighter.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SourceFormatter w;
     w.show();

    return a.exec();
}
