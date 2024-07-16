#include "kecocokan.h"
#include "ui_kecocokan.h"

#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

kecocokan::kecocokan(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kecocokan)
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

    kecocokan::loadDataKecocokan();
    QSqlQuery sql;
    sql.prepare("SELECT * FROM kecocokan");
    sql.exec();
}

void kecocokan::setIdAlternatif(int idAlternatif)
{
    this->idAlternatif = idAlternatif;
}

int kecocokan::getIdAlternatif()
{
    return this->idAlternatif;
}

void kecocokan::setScore(int score)
{
    this->score = score;
}

int kecocokan::getScore()
{
    return this->score;
}

void kecocokan::setPercentage(QString percentage)
{
    this->percentage = percentage;
}

QString kecocokan::getPercentage()
{
    return this->percentage;
}

void kecocokan::loadDataKecocokan()
{
    crudkecocokan = new QSqlQueryModel(this);
    crudkecocokan->setQuery("SELECT * FROM kecocokan");
    crudkecocokan->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    crudkecocokan->setHeaderData(1, Qt::Horizontal, QObject::tr("ID ALTWRNATIF"));
    crudkecocokan->setHeaderData(2, Qt::Horizontal, QObject::tr("SKOR"));
    crudkecocokan->setHeaderData(3, Qt::Horizontal, QObject::tr("PERSENTASE"));
    ui->tableView->setModel(crudkecocokan);
    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(1,50);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,70);
    ui->tableView->show();
}

kecocokan::~kecocokan()
{
    delete ui;
}

void kecocokan::on_pushButton_clicked()
{
    QSqlQuery sql;
    sql.prepare("INSERT INTO kecocokan (id_alternatif, score, percentage) "
                "VALUES (:id_alternatif, :score, :percentage)");
    sql.bindValue(":id_alternatif", ui->iDAlternatifLineEdit->text());
    sql.bindValue(":score", ui->skorLineEdit->text());
    sql.bindValue(":percentage", ui->persentaseLineEdit->text());

    if(sql.exec()){
        qDebug()<<"Data berhasil disimpan";
        kecocokan::loadDataKecocokan();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void kecocokan::on_pushButton_2_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("UPDATE kecocokan SET id_alternatif=:id_alternatif, score=:score, percentage=:percentage WHERE id=:id");
    sql.bindValue(":id", ui->tableView->model()->index(baris,0).data().toString());
    sql.bindValue(":id_alternatif", ui->iDAlternatifLineEdit->text());
    sql.bindValue(":score", ui->skorLineEdit->text());
    sql.bindValue(":percentage", ui->persentaseLineEdit->text());

    if(sql.exec()){
        qDebug()<<"Data berhasil diubah";
        kecocokan::loadDataKecocokan();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void kecocokan::on_pushButton_3_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("DELETE FROM kecocokan WHERE id=:id");
    sql.bindValue(":id", ui->tableView->model()->index(baris,0).data().toString());

    if(sql.exec()){
        qDebug()<<"Data berhasil dihapus";
        kecocokan::loadDataKecocokan();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void kecocokan::on_tableView_activated(const QModelIndex &index)
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();
    ui->iDAlternatifLineEdit->setText(ui->tableView->model()->index(baris,1).data().toString());
    ui->skorLineEdit->setText(ui->tableView->model()->index(baris,2).data().toString());
    ui->persentaseLineEdit->setText(ui->tableView->model()->index(baris,3).data().toString());
}

