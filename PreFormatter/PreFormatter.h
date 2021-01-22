#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PreFormatter.h"

class PreFormatter : public QMainWindow
{
    Q_OBJECT

public:
    PreFormatter(QWidget *parent = Q_NULLPTR);

private:
    Ui::PreFormatterClass ui;
};
