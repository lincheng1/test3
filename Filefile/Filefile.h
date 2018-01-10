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
    //读txt文件
	void readFile();
	//写保存txt文件
	void writeFile();

	//流写数据
	void writeData();
	//流读数据
	void readData();

};
