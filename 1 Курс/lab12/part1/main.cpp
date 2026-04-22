#include <iostream>
#include <map>
#include <vector>
using namespace std;

// НОД двух чисел по алгоритму Евклида
int gcd(int a, int b) {
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

// НОД всей строки
int rowGCD(const vector<int> &row) {
  int result = (row[0] < 0) ? -row[0] : row[0];
  for (int i = 1; i < (int)row.size(); i++) {
    result = gcd(result, row[i]);
  }
  return result;
}

int main() {
  int m, n;

  cout << "Ключ = НОД строки, значение = строка" << endl;
  cout << "Map сортируется по убыванию НОД" << endl;

  cout << "\nВведите количество строк матрицы: ";
  cin >> m;
  cout << "Введите количество столбцов матрицы: ";
  cin >> n;

  if (m <= 0 || n <= 0) {
    cout << "Ошибка: размеры должны быть больше 0" << endl;
    return 1;
  }

  // Ввод матрицы
  vector<vector<int>> matrix(m, vector<int>(n));

  cout << "\nВводите элементы построчно" << endl;
  cout << "Каждую строку вводите через пробел и нажимайте Enter" << endl;

  for (int i = 0; i < m; i++) {
    cout << "Строка " << i + 1 << " (" << n << " чисел): ";
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  // Вывод исходной матрицы с НОД каждой строки
  cout << "\nИсходная матрица" << endl;
  for (int i = 0; i < m; i++) {
    cout << "Строка " << i + 1 << ": ";
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j];
      if (j < n - 1)
        cout << "  ";
    }
    cout << "   (НОД = " << rowGCD(matrix[i]) << ")" << endl;
  }

  // Заполняем map: ключ = НОД строки, убывание через greater<int>
  map<int, vector<vector<int>>, greater<int>> myMap;
  for (int i = 0; i < m; i++) {
    int key = rowGCD(matrix[i]);
    myMap[key].push_back(matrix[i]);
  }

  // Вывод map
  cout << "\nMap (по убыванию НОД)" << endl;
  for (auto &entry : myMap) {
    cout << "\nНОД = " << entry.first << "  (" << entry.second.size()
         << " строк с таким НОД):" << endl;
    for (auto &row : entry.second) {
      cout << "  [ ";
      for (int i = 0; i < (int)row.size(); i++) {
        cout << row[i];
        if (i < (int)row.size() - 1)
          cout << ", ";
      }
      cout << " ]" << endl;
    }
  }

  return 0;
}
