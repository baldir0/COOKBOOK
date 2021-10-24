#include "menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent) : QWidget(parent)
{
    box = new QVBoxLayout(this); // Main Layout

    listArea = new QScrollArea(this); // Scroll Area
    listArea->setWidgetResizable(true);
    listArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    listAreaContainer = new QWidget(); // Container For Scroll Area
    listArea->setWidget(listAreaContainer);

    listLayout = new QVBoxLayout(listAreaContainer); // Layout for listAreaContainer

    // Load Recipes
    loadRecipes();

    // Add Scroll Area to main layout
    box->addWidget(listArea);
    setLayout(box);
}

/**
* Load Recipes from file "menu.json"
* menu.json structure:
*   text - text to display
*   img_path - path to image
*   recipe_path - path to recipe file
* @brief MenuWidget::loadRecipes
*/
void MenuWidget::loadRecipes() {
    QFile *file = new QFile(":/main/res/menu.json"); // Init File
    file->open(QIODevice::ReadOnly); // Open File

    QJsonParseError parseError; // Init Parse Error Variable
    QJsonDocument json = QJsonDocument::fromJson(QByteArray(file->readAll())); // Json Document Init
    file->close(); // Close File

    if (parseError.error != QJsonParseError::NoError) {
        // File Load Failed
        return;
    }

    //Create and add elemetns to vector
    for (const QJsonValue &val : json.object()) {
        MenuElementWidget *element = new MenuElementWidget(listAreaContainer, val["recipe_path"].toString(), val["img_path"].toString(), val["text"].toString());
        element->setMaximumHeight(256);
        element->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
        element->setStyleSheet("border: 1px solid black");
        element->setCursor(Qt::PointingHandCursor);

        // On Click
        connect(element, SIGNAL(triggered(QString)), this, SLOT(S_recipeClicked(QString)));

        listLayout->addWidget(element); // Add Elements to Layout
    }
}

void MenuWidget::S_recipeClicked(QString path){
    emit triggered(path);
}
