#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cout << "Введите количество элементов вектора: ";
  cin >> n;

  if (n <= 0) {
    cout << "Ошибка: размер должен быть больше 0" << endl;
    return 1;
  }

  // Заполнение вектора
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cout << "v[" << i + 1
         << "] = "; // показываем номер с 1, чтобы отсчет шел не с нуля
    cin >> v[i];
  }

  // Вывод исходного вектора
  cout << "\nИсходный вектор:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "  Место " << i + 1 << ": " << v[i] << endl;
  }

  // Проверка условия: последний элемент равен первому
  cout << "\nПроверка условия: первый элемент = " << v[0]
       << ", последний = " << v[n - 1] << endl;

  if (v[0] == v[n - 1]) {
    cout << "Условие выполнено!" << endl;

    // Чётные места — это места 2, 4, 6, ...
    // В массиве это индексы 1, 3, 5, ...
    vector<int> result;
    for (int i = 1; i < n; i += 2) {
      result.push_back(v[i]);
    }

    if (result.empty()) {
      cout << "Нет элементов на чётных местах (вектор слишком короткий)"
           << endl;
    } else {
      cout << "\nНовый вектор (элементы на чётных местах 2, 4, 6...):" << endl;
      for (int i = 0; i < (int)result.size(); i++) {
        cout << "  " << result[i];
      }
      cout << endl;
      cout << "Размер нового вектора: " << result.size() << endl;
    }

  } else {
    cout << "Условие не выполнено — новый вектор не создаётся" << endl;
  }

  return 0;
}
