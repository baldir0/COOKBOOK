#ifndef MENUWIDGET_H
#define MENUWIDGET_H

// Widgets Lib
#include <QScrollArea>
#include <QLineEdit>
#include <QWidget>

// JSON Lib
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QByteArray>

// File Lib
#include <QFile>

// Class
#include "menuelementwidget.h"

// Layout Lib
#include <QVBoxLayout>

// Other
#include <QVector>

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);

    // Main Variables
    QVBoxLayout *box;
    QVBoxLayout *listLayout;
    QScrollArea *listArea;
    QWidget *listAreaContainer;

    // Signals
signals:
    void triggered(QString);
private:
    void loadRecipes();

private slots:
    void S_recipeClicked(QString path);
};

#endif // MENUWIDGET_H
