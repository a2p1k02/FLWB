#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mHistory = new History(this);
    setDefaultUI();
    startPage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDefaultUI()
{
    ui->menubar->hide();
    ui->backButton->setIcon(mStyle.standardIcon(QStyle::SP_ArrowBack));
    ui->forwardButton->setIcon(mStyle.standardIcon(QStyle::SP_ArrowForward));
    ui->refreshButton->setIcon(mStyle.standardIcon(QStyle::SP_BrowserReload));
    ui->goButton->setIcon(mStyle.standardIcon(QStyle::SP_DialogApplyButton));
}

void MainWindow::startPage()
{
    ui->webBroswer->load(QString("https://google.com/"));
}

void MainWindow::on_goButton_clicked()
{
    ui->webBroswer->load(ui->searchBox->text());

    mNewHistory.insert(QDateTime().currentDateTime().toString("dd.MM.yyyy hh:mm:ss"), ui->searchBox->text());
    mHistory->writeHistory(mNewHistory);
}

void MainWindow::on_searchBox_returnPressed()
{
    on_goButton_clicked();
}

void MainWindow::on_webBroswer_loadStarted()
{
    ui->statusBar->showMessage("Loading...");
}

void MainWindow::on_webBroswer_loadFinished(bool arg1)
{    
    arg1 ? ui->statusBar->showMessage("Finished!"),
            ui->searchBox->setText(ui->webBroswer->url().toString()) : ui->statusBar->showMessage("Load error");
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Alt)
        ui->menubar->show();
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Alt)
        ui->menubar->hide();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionAbout_FLWB_triggered()
{
    QMessageBox::about(this, tr("About FLWB"),
                        tr("<p><center>FLWB is Open Source Lightweight Web Broswer was made with GPL V3 License by a2p1k02"
                        "</center></p><br><a link href='https://github.com/a2p1k02/FLWB'><center>Source Code</center></a>"));
}



