#ifndef LABELCLIQUABLE_H
#define LABELCLIQUABLE_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

class LabelCliquable : public QLabel
{
    Q_OBJECT
public:
    explicit LabelCliquable(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent * ev);


signals:
    void Mouse_Pressed();
};

#endif // LABELCLIQUABLE_H
