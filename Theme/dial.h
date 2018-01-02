#ifndef DIAL_H
#define DIAL_H

#include<QString>
#include<qwt_dial.h>

class Dial : public QwtDial
{
    Q_OBJECT
public:
    Dial(QWidget* widget = NULL);

    void setLabel(const QString& label_);
    const QString& getLabel() const;

protected:
    virtual void drawScaleContents( QPainter *painter,const QPointF &center, double radius ) const;

private:
    QString label;
};

#endif // DIAL_H
