#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_btnExit_clicked() { close(); }

void MainWindow::on_btnClear_clicked() {
  ui->textInput->clear();
  ui->listResult->clear();
  ui->statusLabel->setText("Введите числа и нажмите «Решить»");
}

void MainWindow::on_btnSolve_clicked() {
  ui->listResult->clear();

  // Читаем числа из текстового поля — каждое на новой строке
  QString text = ui->textInput->toPlainText().trimmed();
  if (text.isEmpty()) {
    QMessageBox::warning(this, "Ошибка", "Введите хотя бы одно число!");
    return;
  }

  QStringList lines = text.split(u'\n', Qt::SkipEmptyParts);
  std::vector<double> v;
  for (const QString &line : lines) {
    bool ok;
    double val = line.trimmed().toDouble(&ok);
    if (ok)
      v.push_back(val);
  }

  if (v.empty()) {
    QMessageBox::warning(this, "Ошибка", "Не удалось прочитать числа!");
    return;
  }

  // Ищем первый и последний положительные элементы
  int firstPos = -1, lastPos = -1;
  for (int i = 0; i < (int)v.size(); ++i) {
    if (v[i] > 0) {
      if (firstPos == -1)
        firstPos = i;
      lastPos = i;
    }
  }

  // Нужно хотя бы два разных положительных элемента
  if (firstPos == -1 || firstPos == lastPos) {
    ui->statusLabel->setText(
        "❌ Нужно хотя бы два различных положительных числа");
    return;
  }

  // Сумма элементов МЕЖДУ первым и последним положительными
  double sumBetween = 0.0;
  for (int i = firstPos + 1; i < lastPos; ++i) {
    sumBetween += v[i];
  }

  if (sumBetween <= 0) {
    ui->statusLabel->setText(QString("Сумма между ними = %1 (не положительна). "
                                     "Новая структура не создаётся.")
                                 .arg(sumBetween));
    return;
  }

  // Создаём новую структуру: элементы < sumBetween
  int count = 0;
  for (double x : v) {
    if (x < sumBetween) {
      ui->listResult->addItem(QString::number(x));
      count++;
    }
  }

  ui->statusLabel->setText(
      QString("✅ Сумма = %1 | Первый полож.: позиция %2 | Последний полож.: "
              "позиция %3 | Найдено элементов: %4")
          .arg(sumBetween)
          .arg(firstPos)
          .arg(lastPos)
          .arg(count));
}
