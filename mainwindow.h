#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Class
#include "menuwidget.h"
#include "recipewidget.h"
#include "newrecipewidget.h"

// Layout Lib
#include <QVBoxLayout>

// Menu Lib
#include <QMenuBar>
#include <QMenu>
#include <QAction>

// Debug Lib
#include <QDebug>



class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    // Menu Slots
    void S_newRecipe();
    void S_editRecipe();
    void S_about();

    void S_backButton();
    void S_showRecipe(QString path);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Window Variables
    int minH = 600, // minimal Height
    minW = 800; // minimal Width
    int baseH = 600, // base Height
    baseW = 800; // base Width

    QWidget *centralWidget;
    QVBoxLayout *layout;

    MenuWidget *menuWidget;
    RecipeWidget *recipeWidget;

    // Window Functions

    /**
     * Setup Window default settings
     * @brief initWindowSettings
     */
    void initWindowSettings();

    // Menu
    //QMenuBar *menuBar;
    QMenu *menu;

    // Menu Actions
    QAction *newRecipe;
    QAction *editRecipe;
    QAction *about;
    /**
     * Generate Menu Bar
     * Options:
     *  - New Recipe
     *  - Edit Recipe
     *  - Info
     */
    void createActions();
    void createMenu();

};
#endif // MAINWINDOW_H
