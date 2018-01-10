/********************************************************************************
** Form generated from reading UI file 'Filefile.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEFILE_H
#define UI_FILEFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilefileClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *readButton;
    QPushButton *writeButton;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *FilefileClass)
    {
        if (FilefileClass->objectName().isEmpty())
            FilefileClass->setObjectName(QStringLiteral("FilefileClass"));
        FilefileClass->resize(600, 400);
        gridLayout = new QGridLayout(FilefileClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(204, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        readButton = new QPushButton(FilefileClass);
        readButton->setObjectName(QStringLiteral("readButton"));

        gridLayout->addWidget(readButton, 0, 1, 1, 1);

        writeButton = new QPushButton(FilefileClass);
        writeButton->setObjectName(QStringLiteral("writeButton"));

        gridLayout->addWidget(writeButton, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(204, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        textEdit = new QTextEdit(FilefileClass);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 4);


        retranslateUi(FilefileClass);

        QMetaObject::connectSlotsByName(FilefileClass);
    } // setupUi

    void retranslateUi(QWidget *FilefileClass)
    {
        FilefileClass->setWindowTitle(QApplication::translate("FilefileClass", "Filefile", Q_NULLPTR));
        readButton->setText(QApplication::translate("FilefileClass", "readflie", Q_NULLPTR));
        writeButton->setText(QApplication::translate("FilefileClass", "writefile", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilefileClass: public Ui_FilefileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEFILE_H
