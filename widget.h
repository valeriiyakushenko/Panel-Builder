#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void calculate_panels();
    void show_panels(int number, double large, double small, double width, double angle);

private:
    Ui::Widget *ui;

    QPushButton *calculate_button;
    QLineEdit *base_large;
    QLineEdit *base_small;
    QLineEdit *width_lineEdit;
    QLineEdit *gap_lineEdit;
    QLineEdit *count_lineEdit;
    QTableWidget *table;

    QVBoxLayout *rightLayout;
    QVBoxLayout *leftLayout;
    QHBoxLayout *mainLayout;

};

#endif
