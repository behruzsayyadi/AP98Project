/********************************************************************************
** Form generated from reading UI file 'RegisterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_lastName;
    QLabel *label_id;
    QLineEdit *lineEdit_phoneNumber;
    QLineEdit *lineEdit_firstName;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_lastName;
    QDateEdit *birthDateEdit;
    QLabel *label_birthDate;
    QLabel *label_phoneNumber;
    QLabel *label_firstName;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QString::fromUtf8("RegisterDialog"));
        RegisterDialog->resize(400, 300);
        widget = new QWidget(RegisterDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 50, 261, 221));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(-1, -1, -1, 50);
        label_lastName = new QLabel(widget);
        label_lastName->setObjectName(QString::fromUtf8("label_lastName"));

        gridLayout->addWidget(label_lastName, 2, 1, 1, 1);

        label_id = new QLabel(widget);
        label_id->setObjectName(QString::fromUtf8("label_id"));

        gridLayout->addWidget(label_id, 3, 1, 1, 1);

        lineEdit_phoneNumber = new QLineEdit(widget);
        lineEdit_phoneNumber->setObjectName(QString::fromUtf8("lineEdit_phoneNumber"));

        gridLayout->addWidget(lineEdit_phoneNumber, 5, 0, 1, 1);

        lineEdit_firstName = new QLineEdit(widget);
        lineEdit_firstName->setObjectName(QString::fromUtf8("lineEdit_firstName"));

        gridLayout->addWidget(lineEdit_firstName, 0, 0, 1, 1);

        lineEdit_id = new QLineEdit(widget);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        gridLayout->addWidget(lineEdit_id, 3, 0, 1, 1);

        lineEdit_lastName = new QLineEdit(widget);
        lineEdit_lastName->setObjectName(QString::fromUtf8("lineEdit_lastName"));

        gridLayout->addWidget(lineEdit_lastName, 1, 0, 2, 1);

        birthDateEdit = new QDateEdit(widget);
        birthDateEdit->setObjectName(QString::fromUtf8("birthDateEdit"));

        gridLayout->addWidget(birthDateEdit, 4, 0, 1, 1);

        label_birthDate = new QLabel(widget);
        label_birthDate->setObjectName(QString::fromUtf8("label_birthDate"));

        gridLayout->addWidget(label_birthDate, 4, 1, 1, 1);

        label_phoneNumber = new QLabel(widget);
        label_phoneNumber->setObjectName(QString::fromUtf8("label_phoneNumber"));

        gridLayout->addWidget(label_phoneNumber, 5, 1, 1, 1);

        label_firstName = new QLabel(widget);
        label_firstName->setObjectName(QString::fromUtf8("label_firstName"));

        gridLayout->addWidget(label_firstName, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label_lastName->setBuddy(lineEdit_lastName);
        label_id->setBuddy(lineEdit_id);
        label_birthDate->setBuddy(birthDateEdit);
        label_phoneNumber->setBuddy(lineEdit_phoneNumber);
        label_firstName->setBuddy(lineEdit_firstName);
#endif // QT_CONFIG(shortcut)

        retranslateUi(RegisterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RegisterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RegisterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        label_lastName->setText(QCoreApplication::translate("RegisterDialog", "\331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214", nullptr));
        label_id->setText(QCoreApplication::translate("RegisterDialog", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        lineEdit_phoneNumber->setText(QCoreApplication::translate("RegisterDialog", "09", nullptr));
        lineEdit_firstName->setText(QString());
        lineEdit_id->setText(QCoreApplication::translate("RegisterDialog", "10", nullptr));
        lineEdit_lastName->setText(QString());
        label_birthDate->setText(QCoreApplication::translate("RegisterDialog", "\330\252\330\247\330\261\333\214\330\256 \330\252\331\210\331\204\330\257", nullptr));
        label_phoneNumber->setText(QCoreApplication::translate("RegisterDialog", "\330\264\331\205\330\247\330\261\331\207 \331\205\331\210\330\250\330\247\333\214\331\204", nullptr));
        label_firstName->setText(QCoreApplication::translate("RegisterDialog", "\331\206\330\247\331\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
