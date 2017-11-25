#ifndef CASE_H
#define CASE_H

#include <QColor>
#include <QRect>
#include <QPainter>

class Case : public QRect
{
public:
    Case(int size,int x,int y);
    void draw(QPainter *painter, QColor);

private:
    int size;
    int xPos;
    int yPos;
};

#endif // CASE_H
