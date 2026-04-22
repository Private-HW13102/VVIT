#include <iostream>
#include <list>
#include <random>
#include <ctime>

using namespace std;

void printList(const string& name, const list<int>& lst) {
    cout << name << ": ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    int n;
    cout << "Введите размер списка: ";
    cin >> n;

    list<int> originalList;
    list<int> evenList;   
    list<int> oddList;    

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-100, 100);

    for (int i = 0; i < n; ++i) {
        originalList.push_back(dis(gen));
    }

    printList("Исходный список", originalList);

    for (int num : originalList) {
        if (num % 2 == 0) {
            evenList.push_back(num);
        } else {
            oddList.push_back(num);
        }
    }

    printList("Список с чётными числами", evenList);
    printList("Список с нечётными числами", oddList);

    return 0;
}
