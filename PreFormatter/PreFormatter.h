#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PreFormatter.h"
#include <QFileDialog>

class PreFormatter : public QMainWindow
{
    Q_OBJECT

public:
    PreFormatter(QWidget *parent = Q_NULLPTR);


    void extract();
    const QString openFileDialog();
    const QString chooseFile();


private:
    Ui::PreFormatterClass ui;
};
