/********************************************************************************
** Form generated from reading UI file 'mastevalgui.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTEVALGUI_H
#define UI_MASTEVALGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mastevalGUI
{
public:
    QWidget *centralWidget;
    QPushButton *FileIn;
    QPushButton *FileOut;
    QLineEdit *TimeIn;
    QPushButton *Go;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mastevalGUI)
    {
        if (mastevalGUI->objectName().isEmpty())
            mastevalGUI->setObjectName(QStringLiteral("mastevalGUI"));
        mastevalGUI->resize(400, 300);
        centralWidget = new QWidget(mastevalGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FileIn = new QPushButton(centralWidget);
        FileIn->setObjectName(QStringLiteral("FileIn"));
        FileIn->setGeometry(QRect(70, 50, 75, 23));
        FileOut = new QPushButton(centralWidget);
        FileOut->setObjectName(QStringLiteral("FileOut"));
        FileOut->setGeometry(QRect(180, 50, 75, 23));
        TimeIn = new QLineEdit(centralWidget);
        TimeIn->setObjectName(QStringLiteral("TimeIn"));
        TimeIn->setGeometry(QRect(70, 100, 141, 20));
        Go = new QPushButton(centralWidget);
        Go->setObjectName(QStringLiteral("Go"));
        Go->setGeometry(QRect(80, 170, 75, 23));
        mastevalGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mastevalGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        mastevalGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mastevalGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mastevalGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mastevalGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mastevalGUI->setStatusBar(statusBar);

        retranslateUi(mastevalGUI);

        QMetaObject::connectSlotsByName(mastevalGUI);
    } // setupUi

    void retranslateUi(QMainWindow *mastevalGUI)
    {
        mastevalGUI->setWindowTitle(QApplication::translate("mastevalGUI", "mastevalGUI", Q_NULLPTR));
        FileIn->setText(QApplication::translate("mastevalGUI", "Rohdatei", Q_NULLPTR));
        FileOut->setText(QApplication::translate("mastevalGUI", "Ausgabedatei", Q_NULLPTR));
        TimeIn->setText(QApplication::translate("mastevalGUI", "Zeit (dd.mm.yyyy hh:mm)", Q_NULLPTR));
        Go->setText(QApplication::translate("mastevalGUI", "Erstellen", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mastevalGUI: public Ui_mastevalGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTEVALGUI_H
