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
    Ui::JurassicSCADA ui;

private slots:
    void on_btnOne_clicked();
    void on_btnTwo_clicked();
};
