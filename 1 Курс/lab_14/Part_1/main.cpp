#include <fstream>
#include <iostream>
#include <string>

int cleanFileFromDigits(const std::string &inPath, const std::string &outPath) {
  std::ifstream inFile(inPath);
  std::ofstream outFile(outPath);

  if (!inFile.is_open() || !outFile.is_open())
    return -1;

  int deletedCount = 0;
  std::string line;

  while (std::getline(inFile, line)) {
    std::string cleaned = "";
    for (char c : line) {
      if (c >= '0' && c <= '9') {
        deletedCount++;
      } else {
        cleaned += c;
      }
    }
    outFile << cleaned << "\n";
  }

  inFile.close();
  outFile.close();

  return deletedCount;
}

int main() {
  std::string inPath, outPath;

  std::cout << "Введите путь к файлу:" << std::endl;
  std::getline(std::cin, inPath);

  std::cout << "Введите путь к очищенному файлу:" << std::endl;
  std::getline(std::cin, outPath);

  int deleted = cleanFileFromDigits(inPath, outPath);

  if (deleted < 0) {
    std::cerr << "Ошибка: файл не найден." << std::endl;
  } else {
    std::cout << "Количество удаленных элементов: " << deleted << std::endl;
  }

  return 0;
}
