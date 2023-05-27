#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;

int main() {
    int len, num;
    vector<int> nums;
    cout << "Please enter the array length: ";
    cin >> len;
    cout << "Please enter the arrry num: ";
    for (int i = 0; i < len; ++i) {
        cin >> num;
        nums.push_back(num);
    }
    Sort sort;
    // sort.bubbleSort(nums);
    // sort.selectionSort(nums);
    // sort.insertionSort(nums);
    // sort.shellSort(nums);
    // sort.mergeSort(nums, 0, len - 1);
    // sort.quickSort(nums, 0, len - 1);
    // sort.heapSort(nums);
    // sort.countingSort(nums);
    sort.radixSort(nums);
    sort.printNums(nums);

    return 0;
}
