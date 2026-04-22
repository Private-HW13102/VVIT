#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <random>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_btnExit_clicked() { close(); }

void MainWindow::on_btnSolve_clicked() {
  // Read data
  bool okN, okMin, okMax;
  int n = ui->editSize->text().toInt(&okN);
  int minVal = ui->editMin->text().toInt(&okMin);
  int maxVal = ui->editMax->text().toInt(&okMax);

  if (!okN || !okMin || !okMax || n <= 0) {
    QMessageBox::warning(this, "Ошибка", "Введите корректные целые числа!");
    return;
  }

  // Generating random massive
  std::vector<int> original;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(minVal, maxVal);

  ui->listOriginal->clear();
  for (int i = 0; i < n; ++i) {
    int val = dist(gen);
    original.push_back(val);
    ui->listOriginal->addItem(QString::number(val));
  }

  // Logic
  int firstPos = -1, lastPos = -1;
  for (int i = 0; i < (int)original.size(); ++i) {
    if (original[i] > 0) {
      if (firstPos == -1)
        firstPos = i;
      lastPos = i;
    }
  }

  ui->listResult->clear();

  // Data test
  if (firstPos == -1 || firstPos == lastPos) {
    ui->statusLabel->setText("❌ Нужно хотя бы два положительных числа");
    return;
  }

  // Sum between numbers
  long long sumBetween = 0;
  for (int i = firstPos + 1; i < lastPos; ++i) {
    sumBetween += original[i];
  }

  if (sumBetween <= 0) {
    ui->statusLabel->setText(
        QString("Сумма (%1) не положительна").arg(sumBetween));
    return;
  }

  // Creating new massive
  int count = 0;
  for (int x : original) {
    if (x < sumBetween) {
      ui->listResult->addItem(QString::number(x));
      count++;
    }
  }

  ui->statusLabel->setText(QString("✅ Сумма = %1. Найдено элементов: %2")
                               .arg(sumBetween)
                               .arg(count));
}
