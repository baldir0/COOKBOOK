#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initWindowSettings(); // init window settings

    centralWidget = new QWidget(); // create new widget
    this->setCentralWidget(centralWidget); // set central widget to new created widget

    // Menu
    createActions(); // create menu actions
    createMenu(); // create menu

    layout = new QVBoxLayout(); // Central Widget Layout

    menuWidget = new MenuWidget; // Menu Widget
    layout->addWidget(menuWidget); // Add Menu Widget to central layout
    connect(menuWidget, SIGNAL(triggered(QString)), this, SLOT(S_showRecipe(QString))); // Connect Signal to Slot

    centralWidget->setLayout(layout); // Set Central Widget Layout
}

MainWindow::~MainWindow()
{
    // Free allocated memory
    delete centralWidget;
    delete layout;
    delete menuWidget;
    delete recipeWidget;
    delete menu;
    delete newRecipe;
    delete editRecipe;
    delete about;
}

/**
 * Setup Window default settings
 * @brief initWindowSettings
 */
void MainWindow::initWindowSettings() {
    this->setMinimumSize(this->minW, this->minH);
    this->setBaseSize(this->baseW, this->baseH);
}

/**
 * Generate Menu Bar
 * Options:
 *  - New Recipe
 *  - Edit Recipe
 *  - Info
 */
void MainWindow::createActions() {
    newRecipe = new QAction("Add Recipe");
    connect(newRecipe, SIGNAL(triggered()), this, SLOT(S_newRecipe()));

    editRecipe = new QAction("Edit Recipe");
    editRecipe->setEnabled(false);
    connect(editRecipe, SIGNAL(triggered()), this, SLOT(S_editRecipe()));

    about = new QAction("About");
    connect(about, SIGNAL(triggered()), this, SLOT(S_about()));
}

void MainWindow::createMenu() {
    menu = menuBar()->addMenu("Menu");

    menu->addAction(newRecipe);
    menu->addAction(editRecipe);
    menu->addSeparator()->setText(tr("Info"));
    menu->addAction(about);
}

// SLOTS
void MainWindow::S_newRecipe() {
    qDebug() << "New Recipe Triggered";
}

void MainWindow::S_editRecipe() {
    qDebug() << "Edit Recipe";
}

void MainWindow::S_about(){
    qDebug() << "About";
}

void MainWindow::S_backButton() {
    layout->removeWidget(recipeWidget);
    delete recipeWidget;
    menuWidget = new MenuWidget();
    connect(menuWidget, SIGNAL(triggered(QString)), this, SLOT(S_showRecipe(QString)));
    layout->addWidget(menuWidget);

    // Lock Edit Button
    editRecipe->setEnabled(false);
}

void MainWindow::S_showRecipe(QString path) {
    layout->removeWidget(menuWidget);
    delete menuWidget;
    recipeWidget = new RecipeWidget(nullptr, path);
    connect(recipeWidget->getBackButton(), SIGNAL(clicked()), this, SLOT(S_backButton()));
    layout->addWidget(recipeWidget);

    // Unlock Edit Button
    editRecipe->setEnabled(true);
}
