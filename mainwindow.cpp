#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "buffer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);
    slider = new QSlider(this);
        bar = new QProgressBar(this);

        slider->setOrientation(Qt::Horizontal);

        ui->statusBar->addPermanentWidget(slider);
        ui->statusBar->addPermanentWidget(bar);
      connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
      connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
      connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

     connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
     connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    on_actionStop_triggered();


    player->setMedia(QUrl::fromLocalFile(filename));

   on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{

    player->play();
    ui->statusBar->showMessage("Reproduciendose");
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusBar->showMessage("pausa...");

}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusBar->showMessage("detenido");
}

void MainWindow::on_actionBuffer_triggered()
{
 buffer b;
 b.setModal(true);
 b.exec();
}
