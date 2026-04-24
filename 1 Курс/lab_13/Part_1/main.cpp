#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string composeNewWord(const std::string &w1, const std::string &w2,
                           const std::string &w3) {
  std::string result = "";
  if (w1.length() >= 1)
    result += w1[0];
  if (w2.length() >= 2)
    result += w2[1];
  if (w3.length() >= 3)
    result += w3[2];
  return result;
}

int main() {
  std::string w1, w2, w3;

  std::cout << "Lab 13, General Task 1 (Variant 8)" << std::endl;
  std::cout << "Enter 3 words separated by space:" << std::endl;

  if (!(std::cin >> w1 >> w2 >> w3)) {
    std::cerr << "Error: You must enter at least 3 words." << std::endl;
    return 1;
  }

  std::string result = composeNewWord(w1, w2, w3);
  std::cout << "Resulting word: " << result << std::endl;

  return 0;
}
