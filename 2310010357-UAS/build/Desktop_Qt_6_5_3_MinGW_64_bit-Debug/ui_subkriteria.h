/********************************************************************************
** Form generated from reading UI file 'subkriteria.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBKRITERIA_H
#define UI_SUBKRITERIA_H

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

class Ui_subkriteria
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *namaSubKriteriaLabel;
    QLineEdit *namaSubKriteriaLineEdit;
    QLabel *iDKriteriaLabel;
    QLineEdit *iDKriteriaLineEdit;
    QPushButton *pushButton;
    QTableView *tableView;

    void setupUi(QDialog *subkriteria)
    {
        if (subkriteria->objectName().isEmpty())
            subkriteria->setObjectName("subkriteria");
        subkriteria->resize(350, 300);
        pushButton_2 = new QPushButton(subkriteria);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(140, 100, 80, 18));
        pushButton_3 = new QPushButton(subkriteria);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 100, 80, 18));
        formLayoutWidget = new QWidget(subkriteria);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(80, 10, 191, 76));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        namaSubKriteriaLabel = new QLabel(formLayoutWidget);
        namaSubKriteriaLabel->setObjectName("namaSubKriteriaLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, namaSubKriteriaLabel);

        namaSubKriteriaLineEdit = new QLineEdit(formLayoutWidget);
        namaSubKriteriaLineEdit->setObjectName("namaSubKriteriaLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, namaSubKriteriaLineEdit);

        iDKriteriaLabel = new QLabel(formLayoutWidget);
        iDKriteriaLabel->setObjectName("iDKriteriaLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, iDKriteriaLabel);

        iDKriteriaLineEdit = new QLineEdit(formLayoutWidget);
        iDKriteriaLineEdit->setObjectName("iDKriteriaLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, iDKriteriaLineEdit);

        pushButton = new QPushButton(subkriteria);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 100, 80, 18));
        tableView = new QTableView(subkriteria);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 130, 331, 151));

        retranslateUi(subkriteria);

        QMetaObject::connectSlotsByName(subkriteria);
    } // setupUi

    void retranslateUi(QDialog *subkriteria)
    {
        subkriteria->setWindowTitle(QCoreApplication::translate("subkriteria", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("subkriteria", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("subkriteria", "Hapus", nullptr));
        namaSubKriteriaLabel->setText(QCoreApplication::translate("subkriteria", "Nama Sub Kriteria", nullptr));
        iDKriteriaLabel->setText(QCoreApplication::translate("subkriteria", "ID Kriteria", nullptr));
        pushButton->setText(QCoreApplication::translate("subkriteria", "Simpan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class subkriteria: public Ui_subkriteria {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBKRITERIA_H
