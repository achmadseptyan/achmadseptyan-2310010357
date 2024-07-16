#include "subkriteria.h"
#include "ui_subkriteria.h"

#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

subkriteria::subkriteria(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::subkriteria)
{
    ui->setupUi(this);

    koneksi = QSqlDatabase::addDatabase("QODBC");
    koneksi.setDatabaseName("septyan");
    koneksi.setUserName("root");
    koneksi.setPassword("");

    if(koneksi.open()){
        qDebug()<<"Database terkoneksi";
    }else{
        qDebug()<<koneksi.lastError().text();
    }

    subkriteria::loadDataSub();
    QSqlQuery sql;
    sql.prepare("SELECT * FROM sub_kriteria");
    sql.exec();
}

void subkriteria::setNmSubKriteria(QString nmSubKriteria)
{
    this->nmSubKriteria = nmSubKriteria;
}

QString subkriteria::getNmSubKriteria()
{
    return this->nmSubKriteria;
}

void subkriteria::setIdKriteria(int idKriteria)
{
    this->idKriteria = idKriteria;
}

int subkriteria::getIdKriteria()
{
    return this->idKriteria;
}

void subkriteria::loadDataSub()
{
    crudsubkriteria = new QSqlQueryModel(this);
    crudsubkriteria->setQuery("SELECT * FROM sub_kriteria");
    crudsubkriteria->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    crudsubkriteria->setHeaderData(1, Qt::Horizontal, QObject::tr("NAMA"));
    crudsubkriteria->setHeaderData(2, Qt::Horizontal, QObject::tr("ID KRITERIA"));
    ui->tableView->setModel(crudsubkriteria);
    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,70);
    ui->tableView->show();
}

void subkriteria::ubahSubKriteria(QString namaSubKriteria, QString idKriteria)
{

}

subkriteria::~subkriteria()
{
    delete ui;
}

void subkriteria::on_pushButton_clicked()
{
    QSqlQuery sql;
    sql.prepare("INSERT INTO sub_kriteria (nama, id_kriteria) "
                "VALUES (:nama, :id_kriteria)");
    sql.bindValue(":nama", ui->namaSubKriteriaLineEdit->text());
    sql.bindValue(":id_kriteria", ui->iDKriteriaLineEdit->text());

    if(sql.exec()){
        qDebug()<<"Data berhasil disimpan";
        subkriteria::loadDataSub();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void subkriteria::on_pushButton_2_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("UPDATE sub_kriteria SET nama=:nama, id_kriteria=:id_kriteria WHERE id=:id");
    sql.bindValue(":id", ui->tableView->model()->index(baris,0).data().toString());
    sql.bindValue(":nama", ui->namaSubKriteriaLineEdit->text());
    sql.bindValue(":id_kriteria", ui->iDKriteriaLineEdit->text());

    if(sql.exec()){
        qDebug()<<"Data berhasil diubah";
        subkriteria::loadDataSub();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void subkriteria::on_pushButton_3_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("DELETE FROM sub_kriteria WHERE id=:id");
    sql.bindValue(":id", ui->tableView->model()->index(baris,0).data().toString());

    if(sql.exec()){
        qDebug()<<"Data berhasil dihapus";
        subkriteria::loadDataSub();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void subkriteria::on_tableView_activated(const QModelIndex &index)
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();
    ui->namaSubKriteriaLineEdit->setText(ui->tableView->model()->index(baris,1).data().toString());
    ui->iDKriteriaLineEdit->setText(ui->tableView->model()->index(baris,2).data().toString());
}

