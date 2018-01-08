#include<QPainter>
#include<qwt_dial_needle.h>
#include<qwt_round_scale_draw.h>

#include "dial.h"

Dial::Dial(QWidget* widget) :
    QwtDial(widget),
    label("km/h")
{
    QwtRoundScaleDraw *scaleDraw = new QwtRoundScaleDraw();
    scaleDraw->setSpacing(8);
    scaleDraw->enableComponent(QwtAbstractScaleDraw::Backbone, false);
    scaleDraw->setTickLength(QwtScaleDiv::MinorTick, 0);
    scaleDraw->setTickLength(QwtScaleDiv::MediumTick, 4);
    scaleDraw->setTickLength( QwtScaleDiv::MajorTick, 8);
    setScaleDraw(scaleDraw);

    setWrapping(false);
    setReadOnly(true);

    setOrigin(135.0);
    setScaleArc(0.0,270.0);

    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::red,QColor( Qt::gray ).light( 130 ));
    setNeedle( needle );
}

void Dial::setLabel(const QString &label_)
{
    label = label_;
    update();
}

const QString&  Dial::getLabel() const
{
    return label;
}

void Dial::drawScaleContents( QPainter *painter,const QPointF &center, double radius ) const
{
    QRectF rect(0.0, 0.0, 2.0 * radius, 2.0 * radius - 10.0 );
    rect.moveCenter( center );

    const QColor color = palette().color( QPalette::Text );
    painter->setPen( color );

    const int flags = Qt::AlignBottom | Qt::AlignHCenter;
    painter->drawText( rect, flags, label);
}

void Dial::mousePressEvent(QMouseEvent *event)
{
    if(callBack)
        callBack();
}

void Dial::alarm()
{}

void Dial::setRange(int low,int hight)
{
    setScaleStepSize((int)(hight - low) / 12);
    setScale(low,hight);
}
