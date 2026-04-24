#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Logic.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_solveButton_clicked() {
    QString text = ui->textInput->toPlainText();
    QString charStr = ui->charInput->text();
    
    if (charStr.isEmpty()) {
        ui->statusLabel->setText("Error: Enter target character!");
        ui->statusLabel->setStyleSheet("color: red;");
        return;
    }
    
    QChar target = charStr.at(0);
    int result = findMaxSequence(text, target);
    
    ui->resultOutput->setText(QString::number(result));
    ui->statusLabel->setText("Search completed successfully.");
    ui->statusLabel->setStyleSheet("color: green;");
}

void MainWindow::on_clearButton_clicked() {
    ui->textInput->clear();
    ui->charInput->clear();
    ui->resultOutput->clear();
    ui->statusLabel->setText("Fields cleared.");
    ui->statusLabel->setStyleSheet("color: black;");
}
