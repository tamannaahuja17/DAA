#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int insertSort(int arr[], int size) {
    int key, j;
    int count = 0;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
            count++;
        }
        arr[j + 1] = key;
    }
    return count;
}
int main() {
    int size, cmp;
    int *arr;
    ofstream file;
    file.open("inSortData.csv", ios::out);
    for (int i = 0; i < 100; i++) {
        size = (rand() % 1000) + 30;
        arr = new int[size];
        for (int j = 0; j < size; j++) {
            arr[j] = (rand() % 100);
        }
        cmp = insertSort(arr, size);
        cout << "Size = " << size << " | Comparisons = " << cmp << endl;
        file << size << "," << cmp << "\n";
    }
    file.close();
    return 0;
}
