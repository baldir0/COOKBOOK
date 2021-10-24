#include "menuelementwidget.h"

MenuElementWidget::MenuElementWidget(QWidget *parent,  QString recipePath, QString imagePath, QString title) : QWidget(parent)
{
    layout = new QHBoxLayout();
    setLayout(layout);

    QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Size Policy Variable

    // Set Recipe Path
    this->recipePath = new QString(recipePath);

    imageLabel = new QLabel();  // init image label
    titleLabel = new QLabel();  // init title label

    // Setup image Label
    imageLabel->setPixmap(QPixmap(imagePath));
    imageLabel->setBaseSize(256,256);
    imageLabel->setMaximumSize(256,256);
    imageLabel->setScaledContents(true);
    imageLabel->setSizePolicy(policy);

    // Setup title label
    titleLabel->setText(title);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px");
    titleLabel->setSizePolicy(policy);

    // Add Labels To layout
    layout->addWidget(imageLabel);
    layout->addWidget(titleLabel);
}

MenuElementWidget::~MenuElementWidget() {
    delete recipePath;
    delete imageLabel;
    delete titleLabel;
    delete layout;
}

/**
 * Getter - Recipe Path
 * @brief MenuElementWidget::getRecipePath
 * @return Recipe Path
 */
QString MenuElementWidget::getRecipePath(){
    return *this->recipePath;
}

// On mouse button release event
void MenuElementWidget::mouseReleaseEvent(QMouseEvent *event){
    emit triggered(*this->recipePath);
}
