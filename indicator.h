#ifndef INDICATOR_H
#define INDICATOR_H
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QPainterPath>
#include <QSize>
#include <QColor>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QMetaType>
#include <QPen>
#include <QMessageBox>
#include <QDialog>
#include <QColorDialog>


enum class STATE
{
    Off,
    On,
    Error
};

Q_DECLARE_METATYPE(STATE)

class Indicator : public QWidget
{
    Q_ENUM(STATE)
    Q_OBJECT

    STATE m_state;
    QSize m_widget_size;
    QPoint  m_indicator_point;
    QPoint m_txt_point;
    int m_width;
    int m_height;
    QPen m_frame;
    QPen m_text_pen;
    QString m_name;
    QColor m_color_On;
    QColor m_color_Off;
    QColor m_color_Error;
    QColor m_color_text;
    QString m_inform_message_indicate;
    QString m_error_message_indicate;

    Q_PROPERTY(STATE state READ state WRITE setState NOTIFY changeState);
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY changeName);
    Q_PROPERTY(QColor color_On READ color_On WRITE setColor_On NOTIFY changeColorState)
    Q_PROPERTY(QColor color_Off READ color_Off WRITE setColor_Off NOTIFY changeColorState)
    Q_PROPERTY(QColor color_Error READ color_Error WRITE setColor_Error NOTIFY changeColorState)
    Q_PROPERTY(QPen frame READ frame WRITE setFrame NOTIFY changeFrame);
    Q_PROPERTY(QColor color_text READ color_text WRITE setColor_text NOTIFY changeColorText);

public:
    explicit Indicator(QWidget *parent = nullptr);

    void setInformMessage(const QString& message);
    void setErrorMessage(const QString& message);

signals:
    void changeState();
    void changeColorText();
    void changeFrame();
    void changeColorState();
    void changeName();

public slots:

    void updateStatePainter();

    void setColor_text(const QColor& color_text);
    QColor color_text() const;

    void setFrame(const QPen& frame);
    QPen frame() const;

    void setColor_On(const QColor& color_On);
    QColor color_On() const;

    void setColor_Off(const QColor& color_Off);
    QColor color_Off() const;

    void setColor_Error(const QColor& color_Error);
    QColor color_Error() const;

    STATE state() const;
    void setState(const STATE& state);

    QString name() const;
    void setName(const QString& name);

private:
    void dafaultInitialisation();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

};

#endif // INDICATOR_H
