#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isMinHeap(const vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        //У элемента с индексом i сыновьями являются элементы с индексами 2i и 2i+1 (если такие элементы существуют).
        //Инедксация с 1
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // Проверяем, что левый потомок существует и его приоритет не больше текущего элемента
        if (leftChild < n && arr[leftChild] < arr[i]) {
            return false;
        }

        // Проверяем, что правый потомок существует и его приоритет не больше текущего элемента
        if (rightChild < n && arr[rightChild] < arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        input >> arr[i];
    }

    if (isMinHeap(arr, n)) {
        output << "Yes" << endl;
    } else {
        output << "No" << endl;
    }

    input.close();
    output.close();

    return 0;
}
