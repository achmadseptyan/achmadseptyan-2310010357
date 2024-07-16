#ifndef KRITERIA_H
#define KRITERIA_H

#include <QDialog>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QString>

namespace Ui {
class kriteria;
}

class kriteria : public QDialog
{
    Q_OBJECT

public:
    explicit kriteria(QWidget *parent = nullptr);
    void loadDataKriteria();
    void simpanKriteria(QString namaKriteria, QString slug);
    void ubahKriteria(QString namaKriteria, QString slug);
    ~kriteria();

    void setNmKriteria(QString nmKriteria);
    QString getNmKriteria();

    void setSlug(QString slug);
    QString getSlug();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::kriteria *ui;

    QString nmKriteria, slug;

    QSqlDatabase koneksi;
    QSqlQueryModel *crudkriteria;
};

#endif // KRITERIA_H
