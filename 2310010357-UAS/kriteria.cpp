#include "kriteria.h"
#include "ui_kriteria.h"

#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

kriteria::kriteria(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kriteria)
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

    kriteria::loadDataKriteria();
    QSqlQuery sql;
    sql.prepare("SELECT * FROM kriteria");
    sql.exec();
}

void kriteria::setNmKriteria(QString nmKriteria)
{
    this->nmKriteria = nmKriteria;
}

QString kriteria::getNmKriteria()
{
    return this->nmKriteria;
}

void kriteria::setSlug(QString slug)
{
    this->slug = slug;
}

QString kriteria::getSlug()
{
    return this->slug;
}

kriteria::~kriteria()
{
    delete ui;
}

void kriteria::on_pushButton_clicked()
{
    QSqlQuery sql;
    sql.prepare("INSERT INTO kriteria (nama_kriteria, slug) "
                "VALUES (:nama_kriteria, :slug)");
    sql.bindValue(":nama_kriteria", ui->namaKriteriaLineEdit->text());
    sql.bindValue(":slug", ui->slugLineEdit->text());

    if(sql.exec()){
        qDebug()<<"Data berhasil disimpan";
        kriteria::loadDataKriteria();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void kriteria::on_pushButton_2_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("UPDATE kriteria SET nama_kriteria=:nama_kriteria, slug=:slug WHERE id=:id");
    sql.bindValue(":id", ui->tableView->model()->index(baris,0).data().toString());
    sql.bindValue(":nama_kriteria", ui->namaKriteriaLineEdit->text());
    sql.bindValue(":slug", ui->slugLineEdit->text());

    if(sql.exec()){
        qDebug()<<"Data berhasil diubah";
        kriteria::loadDataKriteria();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void kriteria::on_pushButton_3_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("DELETE FROM kriteria WHERE id=:id");
    sql.bindValue(":id", ui->tableView->model()->index(baris,0).data().toString());

    if(sql.exec()){
        qDebug()<<"Data berhasil dihapus";
        kriteria::loadDataKriteria();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void kriteria::on_tableView_activated(const QModelIndex &index)
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();
    ui->namaKriteriaLineEdit->setText(ui->tableView->model()->index(baris,1).data().toString());
    ui->slugLineEdit->setText(ui->tableView->model()->index(baris,2).data().toString());
}

void kriteria::loadDataKriteria(){
    crudkriteria = new QSqlQueryModel(this);
    crudkriteria->setQuery("SELECT * FROM kriteria");
    crudkriteria->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    crudkriteria->setHeaderData(1, Qt::Horizontal, QObject::tr("NAMA KRITERIA"));
    crudkriteria->setHeaderData(2, Qt::Horizontal, QObject::tr("SLUG"));
    ui->tableView->setModel(crudkriteria);
    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,70);
    ui->tableView->show();
}

void kriteria::ubahKriteria(QString namaKriteria, QString slug)
{

}

