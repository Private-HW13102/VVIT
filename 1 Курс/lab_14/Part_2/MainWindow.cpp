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
    QString fileName = QFileDialog::getOpenFileName(this, "Введите путь к файлу", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        ui->inPathEdit->setText(fileName);
    }
}

void MainWindow::on_processButton_clicked() {
    QString inPath = ui->inPathEdit->text();
    QString charStr = ui->charEdit->text();
    
    if (inPath.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Пожалуйста, введите путь к файлу.");
        return;
    }
    
    if (charStr.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Пожалуйста, введите целевой символ.");
        return;
    }
    
    QChar target = charStr.at(0);
    int result = analyzeFileSequences(inPath, target);
    
    if (result < 0) {
        ui->statusLabel->setText("Ошибка. Не удалось прочитать файл.");
        ui->statusLabel->setStyleSheet("color: red;");
    } else {
        ui->resultEdit->setText(QString::number(result));
        ui->statusLabel->setText("Анализ завершен.");
        ui->statusLabel->setStyleSheet("color: green;");
    }
}

void MainWindow::on_exitButton_clicked() {
    close();
}
