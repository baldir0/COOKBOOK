#ifndef MENUELEMENTWIDGET_H
#define MENUELEMENTWIDGET_H

#include <QWidget>

// Widgets Lib
#include <QLabel>

// Layouts
#include <QHBoxLayout>

class MenuElementWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuElementWidget(QWidget *parent = nullptr, QString recipePath = "", QString imagePath = "", QString title = "Default Title");
    ~MenuElementWidget();

    QString getRecipePath();

signals:
    void triggered(QString); // Element Clicked trigger

private:
    QString *recipePath; // Path to Recipe

    QLabel *imageLabel; // Label for element image
    QLabel *titleLabel; // Label for element text

    QHBoxLayout *layout; // Base layout for element

protected:
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // MENUELEMENTWIDGET_H
