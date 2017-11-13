#ifndef CASE_H
#define CASE_H

#include <QWidget>

class Case : public QWidget
{
    Q_OBJECT
public:
    explicit Case(QWidget *parent = nullptr);

private:
    QColor *color;

signals:

public slots:
};

#endif // CASE_H
