#ifndef KECOCOKAN_H
#define KECOCOKAN_H

#include <QDialog>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QString>

namespace Ui {
class kecocokan;
}

class kecocokan : public QDialog
{
    Q_OBJECT

public:
    explicit kecocokan(QWidget *parent = nullptr);
    void loadDataKecocokan();
    void simpanKecocokan(QString idAlternatif, QString score, QString percentage);
    void ubahKecocokan(QString idAlternatif, QString score, QString percentage);
    ~kecocokan();

    void setIdAlternatif(int idAlternatif);
    int getIdAlternatif();

    void setScore(int score);
    int getScore();

    void setPercentage(QString percentage);
    QString getPercentage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::kecocokan *ui;

    int idAlternatif, score;
    QString percentage;

    QSqlDatabase koneksi;
    QSqlQueryModel *crudkecocokan;
};

#endif // KECOCOKAN_H
