#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <QCommonStyle>
#include <QComboBox>
#include <QWidget>
#include <QDebug>

#include "history.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_goButton_clicked();

    void on_searchBox_returnPressed();

    void on_webBroswer_loadStarted();

    void on_webBroswer_loadFinished(bool arg1);

    void on_actionExit_triggered();

    void on_actionAbout_Qt_triggered();

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

    void on_actionAbout_FLWB_triggered();

private:
    Ui::MainWindow *ui;

    QCommonStyle mStyle;
    QVariantMap mNewHistory;
    History* mHistory;

    void startPage();
    void setDefaultUI();
};
#endif // MAINWINDOW_H
