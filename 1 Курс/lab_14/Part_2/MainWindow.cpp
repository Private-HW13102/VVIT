#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "FilesLogic.h"
#include <QFileDialog>
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

void MainWindow::on_selectInButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select input file", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        ui->inPathEdit->setText(fileName);
    }
}

void MainWindow::on_processButton_clicked() {
    QString inPath = ui->inPathEdit->text();
    QString charStr = ui->charEdit->text();
    
    if (inPath.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select an input file.");
        return;
    }
    
    if (charStr.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a target character.");
        return;
    }
    
    QChar target = charStr.at(0);
    int result = analyzeFileSequences(inPath, target);
    
    if (result < 0) {
        ui->statusLabel->setText("Error: File reading failed.");
        ui->statusLabel->setStyleSheet("color: red;");
    } else {
        ui->resultEdit->setText(QString::number(result));
        ui->statusLabel->setText("Analysis successful.");
        ui->statusLabel->setStyleSheet("color: green;");
    }
}

void MainWindow::on_exitButton_clicked() {
    close();
}
