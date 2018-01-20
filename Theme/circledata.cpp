#include "circledata.h"
#include<qwt_round_scale_draw.h>

CircleData::CircleData(QWidget* parent):
    QFrame(parent)
{
    setAutoFillBackground(true);

    setPalette(colorTheme(QColor(Qt::darkGray).dark(150)));

    QGridLayout* layout = new QGridLayout(this);
    layout->setSpacing(5);
    layout->setMargin(0);

    press = createDial(40.0,480.0);
    press->setLabel("压力(KPa)");
    layout->addWidget(press,0,0);
    water = createDial(40.0,480.0);
    water->setLabel("水位(m)");
    layout->addWidget(water,0,1);
    flow1 = createDial(40.0,480.0);
    flow1->setLabel("流量1(m³/s)");
    layout->addWidget(flow1,0,2);
    flow2 = createDial(40.0,480.0);
    flow2->setLabel("流量2(m³/s)");
    layout->addWidget(flow2,0,3);

    for(int i=0;i<layout->columnCount();i++)
        layout->setColumnStretch(i,1);
}

QPalette CircleData::colorTheme(const QColor& base)
{
    QPalette palette;
/*    palette.setColor( QPalette::Base, base);
    palette.setColor( QPalette::Window, base.dark( 150 ) );
    palette.setColor( QPalette::Mid, base.dark( 110 ) );
    palette.setColor( QPalette::Light, base.light( 170 ) );
    palette.setColor( QPalette::Dark, base.dark( 170 ) );
    palette.setColor( QPalette::Text, base.dark( 200 ).light( 800 ) );
    palette.setColor( QPalette::WindowText, base.dark( 200 ) );
*/
    return palette;
}


Dial* CircleData::createDial(double stepSize,double scale)
{
    Dial* temp = new Dial(this);
    temp->setScaleStepSize(stepSize);
    temp->setScale(0.0,scale);
    temp->scaleDraw()->setPenWidth(2);

    temp->setReadOnly(true);
    temp->setLineWidth(4);
    temp->setFrameShadow(QwtDial::Sunken);

    return temp;
}
