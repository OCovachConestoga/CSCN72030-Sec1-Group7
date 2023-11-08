#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_JurassicSCADA.h"

class JurassicSCADA : public QMainWindow
{
    Q_OBJECT

public:
    JurassicSCADA(QWidget *parent = nullptr);
    ~JurassicSCADA();

private:
    Ui::JurassicSCADAClass ui;
};
