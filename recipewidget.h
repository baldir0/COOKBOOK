#ifndef RECIPEWIDGET_H
#define RECIPEWIDGET_H
// Widget Lib
#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>

// Layout Lib
#include <QVBoxLayout>
#include <QHBoxLayout>

// File Lib
#include <QFile>

// Json Lib
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QByteArray>

// Debug Lib
#include <QDebug>

class RecipeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RecipeWidget(QWidget *parent = nullptr, QString path = "");


    // Getter For Back Button
    QPushButton *getBackButton();
signals:


private:

    QLabel *title;  // Title Label
    QLabel *description;    // Description Label
    QLabel *ingredients;    // Ingredients Label
    QLabel *steps;  // Steps Label
    QVBoxLayout *images;    // Images Layout

    QVBoxLayout *box;   // Main Box Layout
    QVBoxLayout *recipeLayout;  //  Recipe Layout

    QScrollArea *recipeArea;    // Area For Recipe

    QWidget *recipeAreaContainer;   // Widget Container For Scroll Area

    QPushButton *backButton;
    /**
     * Load Recipe From File
     * @brief loadRecipe
     * @param path - path to recipe file
     * @return {bool} - true if loadedm false if not
     */
    bool loadRecipe(QString path);

    /**
     * Load Title From Recipe File
     * @brief loadTitle
     * @param title
     */
    void loadTitle(QString title);

    /**
     * Set Title In Label
     * @brief loadDescription
     * @param description
     */
    void loadDescription(QString description);

    /**
     * Set Ingredients In Label
     * @brief loadIngredients
     * @param ingredients
     */
    void loadIngredients(QJsonArray ingredients);

    /**
     * Set Steps In Label
     * @brief loadSteps
     * @param steps
     */
    void loadSteps(QJsonArray steps);

    /**
     * Set Images in layout
     * @brief loadImages
     * @param images
     */
    void loadImages(QJsonArray images);
};

#endif // RECIPEWIDGET_H
