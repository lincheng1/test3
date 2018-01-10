#include "Filefile.h"
#include <QFileDialog>
#include <QFile>
#include <ui_Filefile.h>
#include <qtextcodec>
#include <QFileInfo>   //��ȡ�ļ���Ϣ
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


	//���ļ�
	connect(ui.readButton, &QPushButton::clicked, this, &Filefile::readFile);
	//д�ļ�
	connect(ui.writeButton, &QPushButton::clicked, this, &Filefile::writeFile);

	//����д�ļ����������ļ�
	writeData();
	readData();
	
	//��ť���ͼƬ
	QIcon icon;
	icon.addFile(tr("../png/a.png"));
	ui.writeButton->setIcon(icon);

	//��ť���ͼƬ
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
			//����һ���
#if 0
            //���ļ���Ĭ���Ǳ�utf8����
			QByteArray arry=file.readAll();
			//��ʾ���༭��
			QTextCodec *codec;
			codec = QTextCodec::codecForName("GBK");
			////Ҫ��ʵ�����ģ�����ΪUTF-8
			QString str = codec->toUnicode(arry);
			ui.textEdit->setText(str);
#endif
			//һ��һ�еĶ�
#if 1
			QByteArray line;
			while (file.atEnd() == false)
			{
				line += file.readLine();	
			}
			QTextCodec *codec;
			codec = QTextCodec::codecForName("GBK");
			////Ҫ��ʵ�����ģ�����ΪUTF-8
			QString str = codec->toUnicode(line);
			ui.textEdit->setText(str);
#endif
		}
		//�ر��ļ�
		file.close();
		QFileInfo info(path);
		qDebug() << "�ļ�����:" << info.fileName();

	}
}

void Filefile::writeFile()
{
	QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");
	if (path.isEmpty()==false)
	{
		//�����ļ�����
		QFile file(path);
		//��ֻд��ʽ��
		bool isok = file.open(QIODevice::WriteOnly);
		if (isok==true)
		{
			//��ȡ�༭������
			QString str = ui.textEdit->toPlainText();
#if 0
			//д�ļ�  QStringת��ΪQByteArray
			file.write(str.toUtf8());
#endif
#if 0
			//д�ļ� QStringת��ΪC++ stringת��Ϊchar *
			file.write(str.toStdString().data());
#endif
#if 1
			//ת��Ϊ���ر���
			file.write(str.toLocal8Bit());
#endif
		}
		file.close();
	}
}


void Filefile::writeData()
{
	//�����ļ�����
	QFile file("../test.txt");
	//��ֻд��ʽ��
	bool isok = file.open(QIODevice::WriteOnly);
	if (isok==true)
	{
		//���������������ļ�����
		QDataStream stream(&file);
		//����������д���ݣ��൱�����ļ���д����
		stream <<QString("��ã����ǲ�һ��" )<<250;
	}
	file.close();

}


void Filefile::readData()
{
	//�����ļ�����
	QFile file("../test.txt");
	//��ֻд��ʽ��
	bool isok = file.open(QIODevice::ReadOnly);
	if (isok == true)
	{
		//���������������ļ�����
		QDataStream stream(&file);

		//��������������ݣ��൱�����ļ��ж�����
		
		//����ʱ�򣬰�д��˳��ȡ����
		QString str;
		int a;
		stream >> str >> a;


		qDebug()<< str.toUtf8().data() << a;   //�е�С���⣬û�д�ӡ�����ġ�
		//qDebug() << str<< a;

		
	}
	file.close();

}

