#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_btnExit_clicked() { close(); }

void MainWindow::on_btnSolve_clicked() {
  ui->listOriginal->clear();
  ui->listResult->clear();

  // Читаем размер матрицы
  bool okM;
  int m = ui->editSize->text().toInt(&okM);
  if (!okM || m < 2 || m > 10) {
    ui->statusLabel->setText("❌ Введите размер матрицы от 2 до 10");
    return;
  }

  // Генерируем матрицу m×m случайными числами [-20, 50]
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(-20, 50);

  std::vector<std::vector<int>> matr(m, std::vector<int>(m));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < m; ++j)
      matr[i][j] = dist(gen);

  // Выводим исходную матрицу
  for (int i = 0; i < m; ++i) {
    QString row = QString("Строка %1: [ ").arg(i);
    for (int j = 0; j < m; ++j) {
      row += QString("%1").arg(matr[i][j], 5);
      if (j < m - 1)
        row += ",";
    }
    row += " ]";
    ui->listOriginal->addItem(row);
  }

  // Побочная диагональ: i + j == m - 1
  // Под побочной диагональю: i + j > m - 1
  int count = 0;
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i + j > m - 1 && matr[i][j] > 0) {
        sum += matr[i][j];
        count++;
      }
    }
  }

  if (count == 0) {
    ui->listResult->addItem(
        "Нет положительных элементов под побочной диагональю.");
    ui->listResult->addItem("Новая матрица не создаётся.");
    ui->statusLabel->setText(
        "❌ Условие не выполнено: нет положительных под побочной диагональю");
    return;
  }

  // Создаём новую матрицу L: каждый элемент + sum
  std::vector<std::vector<int>> newMatr(m, std::vector<int>(m));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < m; ++j)
      newMatr[i][j] = matr[i][j] + sum;

  // Выводим новую матрицу
  for (int i = 0; i < m; ++i) {
    QString row = QString("Строка %1: [ ").arg(i);
    for (int j = 0; j < m; ++j) {
      row += QString("%1").arg(newMatr[i][j], 5);
      if (j < m - 1)
        row += ",";
    }
    row += " ]";
    ui->listResult->addItem(row);
  }

  ui->statusLabel->setText(
      QString("✅ Под побочной диагональю: %1 положит. элемент(ов), сумма = "
              "%2. Каждый элемент увеличен на %2.")
          .arg(count)
          .arg(sum));
}
