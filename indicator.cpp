#include "indicator.h"

Indicator::Indicator(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    m_indicator_point=QPoint{0,0};
    m_widget_size.setWidth(55);
    m_widget_size.setHeight(65);
    setBaseSize(m_widget_size);
    m_width=m_widget_size.width()-3;
    m_height=m_widget_size.height()-15;
    m_txt_point=QPoint(5,65);
    dafaultInitialisation();
}

void Indicator::setInformMessage(const QString& message)
{
    m_inform_message_indicate=message;
}

void Indicator::setErrorMessage(const QString& message)
{
    m_error_message_indicate=message;
}

void Indicator::updateStatePainter()
{
    update();
}
void Indicator::setColor_text(const QColor& color_text)
{
    m_color_text=color_text;
}

QColor Indicator::color_text() const
{
    return m_color_text;
}

void Indicator::setFrame(const QPen& frame)
{
    m_frame=frame;
}

QPen Indicator::frame() const
{
    return m_frame;
}

void Indicator::setColor_On(const QColor& color_On)
{
    m_color_On=color_On;
}

QColor Indicator::color_On() const
{
    return m_color_On;
}

void Indicator::setColor_Off(const QColor& color_Off)
{
    m_color_Off=color_Off;
}

QColor Indicator::color_Off() const
{
    return m_color_Off;
}

void Indicator::setColor_Error(const QColor& color_Error)
{
    m_color_Error=color_Error;
}

QColor Indicator::color_Error() const
{
    return m_color_Error;
}

STATE Indicator::state() const
{
    return m_state;
}

void Indicator::setState(const STATE& state)
{
    m_state=state;
}

QString Indicator::name() const
{
    return m_name;
}

void Indicator::setName(const QString& name)
{
    m_name=name;
}

void Indicator::dafaultInitialisation()
{
    m_color_On=Qt::green;
    m_color_Off=Qt::gray;
    m_color_Error=Qt::red;
    m_color_text=Qt::white;
    m_inform_message_indicate="Все исправно";
    m_error_message_indicate="Здесь будет представлен алгоритм исправления ошибки";
    m_state={STATE::Off};// выключена по умолчанию
    m_frame.setColor(Qt::white);// рамка виджета
    m_frame.setWidth(2);
    m_frame.setStyle(Qt::SolidLine);
    m_name="";
}
void Indicator::setGradient(QPainter& painter,const QPainterPath& path,const QColor& color)
{
    QRadialGradient radial_1(QPoint(20,20),20);
    radial_1.setColorAt(0,Qt::white);
    radial_1.setColorAt(1,color);//цвет к которому будет применен градиент
    painter.fillPath(path,radial_1);//отрисовка и заливка виджета
    painter.setPen(m_color_text);
    painter.drawText(m_txt_point,m_name);//установка текста на виджете
}
void Indicator::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(m_frame);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawEllipse(m_indicator_point.x()+1,m_indicator_point.y()+1,m_width,m_height);// нач точка виджета всего и указали ращмеры лампы + рамка толстая
    QPainterPath path;
    path.addEllipse(m_indicator_point.x()+2,m_indicator_point.y()+2,m_width-2,m_height-2); // отступ для отрисовки рамки
    painter.setPen(QPen(QColor(255,255,255),1));
    painter.setFont(QFont("Veranda",10));

    switch(m_state)
    {
    case STATE::On:
    {
        setGradient(painter,path,m_color_On);
        break;
    }
    case STATE::Error:
    {
        setGradient(painter,path,m_color_Error);
        break;
    }
    case STATE::Off:
    {
        setGradient(painter,path,m_color_Off);
        break;
    }
    }
}

void Indicator::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(m_state==STATE::On)
    {

        QMessageBox::information(this,"Информация об ошибке",m_name+"\n"+m_inform_message_indicate);
        event->accept();
    }
    else if(m_state==STATE::Error)
    {
        QMessageBox::critical(this,"Информация об ошибке",m_name+"\n"+m_error_message_indicate);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void Indicator::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        m_color_On=QColorDialog::getColor(m_color_On,nullptr,"Выберите цвет состояния On",QColorDialog::ShowAlphaChannel);
        m_color_Off=QColorDialog::getColor(m_color_Off,nullptr,"Выберите цвет состояния Off",QColorDialog::ShowAlphaChannel);
        m_color_Error=QColorDialog::getColor(m_color_Error,nullptr,"Выберите цвет состояния Error",QColorDialog::ShowAlphaChannel);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
