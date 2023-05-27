#ifndef SORT_H
#define SORT_H

#include <vector>
using namespace std;

class Sort {
public:
    void bubbleSort(vector<int> &nums);
    void selectionSort(vector<int> &nums);
    void insertionSort(vector<int> &nums);
    void shellSort(vector<int> &nums);
    void printNums(vector<int> &nums);
    void mergeSort(vector<int> &nums, int left, int right);
    void quickSort(vector<int> &nums, int left, int right);
    void heapSort(vector<int> &nums);
    void countingSort(vector<int> &nums);
    void radixSort(vector<int> &nums);
};

void push_down(vector<int> &heap, int start, int end);
int get(int x, int i);

#endif