#pragma once

#include <QtWidgets/QWidget>
#include "ui_Filefile.h"

class Filefile : public QWidget
{
    Q_OBJECT

public:
    Filefile(QWidget *parent = Q_NULLPTR);

private:
    Ui::FilefileClass ui;
private slots:
    //��txt�ļ�
	void readFile();
	//д����txt�ļ�
	void writeFile();

	//��д����
	void writeData();
	//��������
	void readData();

};
