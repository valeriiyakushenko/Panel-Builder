#include "widget.h"

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(1030, 400);
    this->setWindowTitle("Panel Calculator");

    calculate_button = new QPushButton("Calculate");

    base_large = new QLineEdit(this);
    base_large->setPlaceholderText("Large base");

    base_small = new QLineEdit(this);
    base_small->setPlaceholderText("Small base");

    width_lineEdit = new QLineEdit(this);
    width_lineEdit->setPlaceholderText("Width");

    gap_lineEdit = new QLineEdit(this);
    gap_lineEdit->setPlaceholderText("Gap");

    count_lineEdit = new QLineEdit(this);
    count_lineEdit->setPlaceholderText("Count");

    table = new QTableWidget(this);
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"Panel №", "Large base", "Small base", "Width", "Angle"});

    leftLayout = new QVBoxLayout;
    leftLayout->addWidget(base_large);
    leftLayout->addWidget(base_small);
    leftLayout->addWidget(width_lineEdit);
    leftLayout->addWidget(gap_lineEdit);
    leftLayout->addWidget(count_lineEdit);
    leftLayout->addWidget(calculate_button);

    rightLayout = new QVBoxLayout;
    rightLayout->addWidget(table);

    mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(leftLayout, 1);
    mainLayout->addLayout(rightLayout, 1);

    connect(calculate_button, &QPushButton::clicked, this, &Widget::calculate_panels);

}

void Widget::calculate_panels()
{
    bool correct;
    double a = base_large->text().toDouble(&correct);
    double b = base_small->text().toDouble(&correct);
    double width = width_lineEdit->text().toDouble(&correct);
    double gap = gap_lineEdit->text().toDouble(&correct);
    int count = count_lineEdit->text().toDouble(&correct);

    if (!correct) {
        return;
    }

    table->setRowCount(0);
    table->setRowCount(count);

    double panel_width = (width - (gap * (count - 1))) / count;
    double angle = atan(width / (a - b)) * 180.0 / M_PI;

    for (int i = 0; i < count; i++) {
        b = a - (panel_width / tan(angle * M_PI / 180.0));
        show_panels(i, a, b, panel_width, angle);
        a = b - (gap / tan(angle * M_PI / 180.0));
    }


}

void Widget::show_panels(int number, double large, double small, double width, double angle)
{
    table->setItem(number, 0, new QTableWidgetItem(QString::number(number + 1)));
    table->setItem(number, 1, new QTableWidgetItem(QString::number(large)));
    table->setItem(number, 2, new QTableWidgetItem(QString::number(small)));
    table->setItem(number, 3, new QTableWidgetItem(QString::number(width)));
    table->setItem(number, 4, new QTableWidgetItem(QString::number(angle)));
}

Widget::~Widget()
{
}
