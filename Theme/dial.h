#ifndef DIAL_H
#define DIAL_H

#include<QString>
#include<qwt_dial.h>
#include<QMouseEvent>

#include"global.h"

class Dial : public QwtDial
{
    Q_OBJECT
public:
    Dial(QWidget* widget = NULL);

    void setLabel(const QString& label_);
    const QString& getLabel() const;

    void alarm();
    void setRange(int low,int hight);
    void setFixCurrentMessageCallBack(const FixCurrentMessageCallBack& callBack_)
    {callBack = callBack_;}

protected:
    virtual void drawScaleContents( QPainter *painter,const QPointF &center, double radius ) const;
    virtual void mousePressEvent(QMouseEvent* event);
private:
    QString label;
    FixCurrentMessageCallBack callBack;
};

#endif // DIAL_H
