/********************************************************************************
** Form generated from reading UI file 'kriteria.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KRITERIA_H
#define UI_KRITERIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kriteria
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *namaKriteriaLabel;
    QLineEdit *namaKriteriaLineEdit;
    QLabel *slugLabel;
    QLineEdit *slugLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableView *tableView;

    void setupUi(QDialog *kriteria)
    {
        if (kriteria->objectName().isEmpty())
            kriteria->setObjectName("kriteria");
        kriteria->resize(350, 300);
        formLayoutWidget = new QWidget(kriteria);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(90, 10, 171, 76));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        namaKriteriaLabel = new QLabel(formLayoutWidget);
        namaKriteriaLabel->setObjectName("namaKriteriaLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, namaKriteriaLabel);

        namaKriteriaLineEdit = new QLineEdit(formLayoutWidget);
        namaKriteriaLineEdit->setObjectName("namaKriteriaLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, namaKriteriaLineEdit);

        slugLabel = new QLabel(formLayoutWidget);
        slugLabel->setObjectName("slugLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, slugLabel);

        slugLineEdit = new QLineEdit(formLayoutWidget);
        slugLineEdit->setObjectName("slugLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, slugLineEdit);

        pushButton = new QPushButton(kriteria);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 100, 80, 18));
        pushButton_2 = new QPushButton(kriteria);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(140, 100, 80, 18));
        pushButton_3 = new QPushButton(kriteria);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 100, 80, 18));
        tableView = new QTableView(kriteria);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 130, 331, 151));

        retranslateUi(kriteria);

        QMetaObject::connectSlotsByName(kriteria);
    } // setupUi

    void retranslateUi(QDialog *kriteria)
    {
        kriteria->setWindowTitle(QCoreApplication::translate("kriteria", "Dialog", nullptr));
        namaKriteriaLabel->setText(QCoreApplication::translate("kriteria", "Nama Kriteria", nullptr));
        slugLabel->setText(QCoreApplication::translate("kriteria", "Slug", nullptr));
        pushButton->setText(QCoreApplication::translate("kriteria", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("kriteria", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("kriteria", "Hapus", nullptr));
    } // retranslateUi

};

namespace Ui {
    class kriteria: public Ui_kriteria {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KRITERIA_H
