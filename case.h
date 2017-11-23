#ifndef CASE_H
#define CASE_H

#include <QColor>
#include <QRect>
#include <QPainter>

class Case : public QRect
{
public:
    Case(int,int,int);
    void draw(QPainter *painter, QColor);

private:
    int size;
    int xPos;
    int yPos;
};

#endif // CASE_H
