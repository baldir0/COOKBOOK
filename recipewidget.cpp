#include "recipewidget.h"

RecipeWidget::RecipeWidget(QWidget *parent, QString path) : QWidget(parent)
{
    box = new QVBoxLayout(this);
    recipeArea = new QScrollArea(this);
    recipeAreaContainer = new QWidget();
    recipeLayout = new QVBoxLayout(recipeAreaContainer);

    backButton = new QPushButton("BACK");

    recipeAreaContainer->setStyleSheet("border: 1px solid black;");
    recipeArea->setAlignment(Qt::AlignCenter);

    if (!loadRecipe(path)) {
        qDebug() << "Failed To load Recipe";
    }

    recipeArea->setWidget(recipeAreaContainer);
    recipeAreaContainer->setLayout(recipeLayout);

    box->addWidget(recipeArea);
    box->addWidget(backButton);

    setLayout(box);
}

QPushButton *RecipeWidget::getBackButton() {
    return this->backButton;
}

bool RecipeWidget::loadRecipe(QString path) {

    QFile *file = new QFile(path); // Init File
    file->open(QIODevice::ReadOnly); // Open File

    if (!file->isOpen()) return false;

    QJsonParseError parseError; // Init Parse Error Variable
    QJsonDocument json = QJsonDocument::fromJson(QByteArray(file->readAll())); // Json Document Init
    file->close(); // Close File
    if (parseError.error != QJsonParseError::NoError) {
        return false;
    }

    loadTitle(json.object()["title"].toString());
    loadDescription(json.object()["description"].toString());

    QLabel *ingredients_Text = new QLabel("Ingredients: ");
    ingredients_Text->setStyleSheet("font-weight: bold;"
                                    "font-size: 28px;");
    recipeLayout->addWidget(ingredients_Text);
    loadIngredients(json.object()["ingredients"].toArray());

    QLabel *steps_Text = new QLabel("Steps: ");
    steps_Text->setStyleSheet("font-weight: bold;"
                              "font-size: 28px;");
    recipeLayout->addWidget(steps_Text);
    loadSteps(json.object()["steps"].toArray());

    loadImages(json.object()["images"].toArray());

    return true;
}

void RecipeWidget::loadTitle(QString title) {
    this->title = new QLabel(title);
    this->title->setWordWrap(true);
    this->title->setAlignment(Qt::AlignCenter);
    this->title->setStyleSheet("font-size: 48px;"
                               "font-weight: bold");
    recipeLayout->addWidget(this->title);
}

void RecipeWidget::loadDescription(QString description) {
    this->description = new QLabel(description);
    this->description->setWordWrap(true);
    this->description->setStyleSheet("font-size: 24px;");
    recipeLayout->addWidget(this->description);
}

void RecipeWidget::loadIngredients(QJsonArray ingredients) {
    QString text = "";
    for (const QJsonValue &val : ingredients) {
        text += val.toString() + '\n';
    }
    this->ingredients = new QLabel(text);
    this->ingredients->setWordWrap(true);
    this->ingredients->setStyleSheet("font-size: 24px");
    recipeLayout->addWidget(this->ingredients);
}

void RecipeWidget::loadSteps(QJsonArray ingredients) {
    QString text = "";
    for (const QJsonValue &val : ingredients) {
        text += val.toString() + '\n';
    }
    this->steps = new QLabel(text);
    this->steps->setWordWrap(true);
    this->steps->setStyleSheet("font-size: 24px");
    recipeLayout->addWidget(this->steps);
}

void RecipeWidget::loadImages(QJsonArray images) {
    this->images = new QVBoxLayout;
    for (const QJsonValue &val : images) {
        QLabel *img = new QLabel();
        img->setPixmap(QPixmap(val.toString()));
        this->images->addWidget(img);
    }
    this->images->setAlignment(Qt::AlignCenter);
    recipeLayout->addLayout(this->images);
}


