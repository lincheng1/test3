#include "Filefile.h"
#include <QFileDialog>
#include <QFile>
#include <ui_Filefile.h>
#include <qtextcodec>
#include <QFileInfo>   //获取文件信息
#include <QDebug>
#include <QDataStream>
#include <QTextStream>

#include <QPixmap>

#include <QIcon>
#include <QStrin g>
Filefile::Filefile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	//读文件
	connect(ui.readButton, &QPushButton::clicked, this, &Filefile::readFile);
	//写文件
	connect(ui.writeButton, &QPushButton::clicked, this, &Filefile::writeFile);

	//流读写文件，二进制文件
	writeData();
	readData();
	
	//按钮添加图片
	QIcon icon;
	icon.addFile(tr("../png/a.png"));
	ui.writeButton->setIcon(icon);

	//按钮添加图片
	QPixmap icon1(tr("../png/b.png"));
	ui.readButton->setIcon(icon1);
	//ui.readButton->setFixedSize(icon1.size());

}


void Filefile::readFile()
{
	QString path = QFileDialog::getOpenFileName(this, "open", "../", "TXT(*.txt)");
	if (!path.isEmpty())
	{
		QFile file(path);
		bool isok=file.open(QIODevice::ReadOnly);
		if (isok==true)
		{
			//整体一块读
#if 0
            //读文件，默认是别utf8编码
			QByteArray arry=file.readAll();
			//显示到编辑区
			QTextCodec *codec;
			codec = QTextCodec::codecForName("GBK");
			////要想实现中文，必须为UTF-8
			QString str = codec->toUnicode(arry);
			ui.textEdit->setText(str);
#endif
			//一行一行的读
#if 1
			QByteArray line;
			while (file.atEnd() == false)
			{
				line += file.readLine();	
			}
			QTextCodec *codec;
			codec = QTextCodec::codecForName("GBK");
			////要想实现中文，必须为UTF-8
			QString str = codec->toUnicode(line);
			ui.textEdit->setText(str);
#endif
		}
		//关闭文件
		file.close();
		QFileInfo info(path);
		qDebug() << "文件名字:" << info.fileName();

	}
}

void Filefile::writeFile()
{
	QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");
	if (path.isEmpty()==false)
	{
		//创建文件对象
		QFile file(path);
		//已只写方式打开
		bool isok = file.open(QIODevice::WriteOnly);
		if (isok==true)
		{
			//获取编辑区内容
			QString str = ui.textEdit->toPlainText();
#if 0
			//写文件  QString转化为QByteArray
			file.write(str.toUtf8());
#endif
#if 0
			//写文件 QString转化为C++ string转化为char *
			file.write(str.toStdString().data());
#endif
#if 1
			//转化为本地编码
			file.write(str.toLocal8Bit());
#endif
		}
		file.close();
	}
}


void Filefile::writeData()
{
	//创建文件对象
	QFile file("../test.txt");
	//已只写方式打开
	bool isok = file.open(QIODevice::WriteOnly);
	if (isok==true)
	{
		//创建数据流，和文件关联
		QDataStream stream(&file);
		//往数据流里写数据，相当于往文件中写数据
		stream <<QString("你好，我们不一样" )<<250;
	}
	file.close();

}


void Filefile::readData()
{
	//创建文件对象
	QFile file("../test.txt");
	//已只写方式打开
	bool isok = file.open(QIODevice::ReadOnly);
	if (isok == true)
	{
		//创建数据流，和文件关联
		QDataStream stream(&file);

		//往数据流里读数据，相当于往文件中读数据
		
		//读的时候，按写的顺序取数据
		QString str;
		int a;
		stream >> str >> a;


		qDebug()<< str.toUtf8().data() << a;   //有点小问题，没有打印出中文。
		//qDebug() << str<< a;

		
	}
	file.close();

}

