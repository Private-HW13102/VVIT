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

  std::cout << "Lab 14, General Task 1 (Variant 8)" << std::endl;
  std::cout << "Enter input file path:" << std::endl;
  std::getline(std::cin, inPath);

  std::cout << "Enter output file path:" << std::endl;
  std::getline(std::cin, outPath);

  int deleted = cleanFileFromDigits(inPath, outPath);

  if (deleted < 0) {
    std::cerr << "Error: Could not process files." << std::endl;
  } else {
    std::cout << "Digits removed: " << deleted << std::endl;
  }

  return 0;
}
