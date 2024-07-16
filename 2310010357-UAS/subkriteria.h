#ifndef SUBKRITERIA_H
#define SUBKRITERIA_H

#include <QDialog>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QString>

namespace Ui {
class subkriteria;
}

class subkriteria : public QDialog
{
    Q_OBJECT

public:
    explicit subkriteria(QWidget *parent = nullptr);
    void loadDataSub();
    void simpanSubKriteria(QString namaSubKriteria, QString idKriteria);
    void ubahSubKriteria(QString namaSubKriteria, QString idKriteria);
    ~subkriteria();

    void setNmSubKriteria(QString nmSubKriteria);
    QString getNmSubKriteria();

    void setIdKriteria(int idKriteria);
    int getIdKriteria();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::subkriteria *ui;

    QString nmSubKriteria;
    int idKriteria;

    QSqlDatabase koneksi;
    QSqlQueryModel *crudsubkriteria;
};

#endif // SUBKRITERIA_H
