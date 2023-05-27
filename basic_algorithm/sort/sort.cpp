#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;

/** 冒泡排序，每轮确定最后一个值
 *  input:  1   3   5   2   4
 *  len=5   i代表轮次   i=[0->3]=[0->4)=[0->len-1)
 *  i=2     j每轮元素   j=[0->1]=[0->2)=[0->len-1-i)
 */
void Sort::bubbleSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        bool flag = false;          // 用来记录某一轮中是否有交换，如果没有，说明已经排好序了，后面不必再进行
        for (int j = 0; j < len - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = true;        // 更新标志位
            }
        }
        if (flag == false) break;   // 该轮次没有交换过，此时已经排好序了，直接退出
    }
}

/** 选择排序，每轮确定第一个值
 *  input:  1   3   5   2   4
 *  len=5   i代表被比较的基数   i=[0->3]=[0->4)=[0->len-1)
 *  i=2     j代表依次比较的数   j=[3->4]=[3->5)=[i+1->len)
*/
void Sort::selectionSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (nums[i] > nums[j]) swap(nums[i], nums[j]);
        }
    }
}

/** 插入排序，每轮排序好前 i 个数
 *  input:  1   3   5   2   4       固定的数 2 和变化的数 1 3 5 比较，并插入
 *  len=5   i为比较时固定的数，     i=[1->4]=[0->5)=[1->len)
 *  i=2     j为比较时变化的数，     j=[2->0]=[i-1->0]
*/
void Sort::insertionSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
        int tmp = nums[i], j;
        for (j = i - 1; j >= 0; --j ) {
            if (nums[j] > tmp) nums[j + 1] = nums[j];
            else break;
        }
        nums[j + 1] = tmp;
    }
}

/** 希尔排序，相当于是多次插入排序，不过之前的+1变为了+gap
 *  2, 5, 1, 3, 4 ,6，9，1   8个数：gap为4->2    7个数：gap为3->1
 *  gap间隔     4， 2
 *  i为固定的数：4
 *  j为变化的数：2
*/
void Sort::shellSort(vector<int> &nums) {
    int len = nums.size(), gap = len / 2;                       // len=8 gap=4
    while (gap > 0) {
        for (int i = gap; i < len; i += gap) {                  // i=[4]
            int tmp = nums[i], j;                               // tmp=nums[4]
            for (j = i - gap; j >= 0; j -= gap) {               // j=[0]
                if (nums[j] > tmp) nums[j + gap] = nums[j];     // 比较时大于tmp，往后挪一位
                else break;
            }
            nums[j + gap] = tmp;                                // 将固定的数放在空缺位置
        }
        gap /= 2;
    }
}

/** 归并排序，分为三个阶段：分解，解决，合并
 *  2, 5, 1, 3, 4 ,6，9，1
 *  与合并有序链表这个算法题类似
*/
void Sort::mergeSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;              // left=0 right=7  mid=3
    int mid = (left + right) / 2;
    mergeSort(nums, left, mid);             // (0,3)
    mergeSort(nums, mid + 1, right);        // (4,7)
    static vector<int> tmp;                 // 主要为了递归时，减少内存开销
    tmp.clear();
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] > nums[j]) tmp.push_back(nums[j++]);
        else tmp.push_back(nums[i++]);
    }
    while (i <= mid) tmp.push_back(nums[i++]);
    while (j <= right) tmp.push_back(nums[j++]);
    for (int num : tmp) {
        nums[left++] = num;
    }
}

/** 快速排序
 *       le ba                 ri
 *       1  3  2  4  11  10  7  5  4  6        //base=3
 *             j     i
*/
void Sort::quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int i = left - 1, j = right + 1, base = nums[left + rand() % (right - left + 1)];
    while (i < j) {
        while (nums[++i] < base);   // 精准找到大于 base 的数
        while (nums[--j] > base);   // 精准找到小于 base 的数
        if (i < j) {
            swap(nums[i], nums[j]);
        } else {
            quickSort(nums, left, j);
            quickSort(nums, j + 1, right);
        }
    }
}

/** 堆排序*/
void Sort::heapSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = len / 2 - 1; i >= 0; --i) {        // 从最后一个父节点开始处理
        push_down(nums, i, len - 1);
    }
    for (int i = len - 1; i > 0; --i) {
        swap(nums[0], nums[i]);
        push_down(nums, 0, i - 1);
    }
}

void push_down(vector<int> &heap, int start, int end) {
    int father = start, son = 2 * father + 1;               // 数组从 0 开始，父节点f，左子树 2*f+1，右子树 2*f+2
    while (son <= end) {
        if (son + 1 <= end && heap[son] < heap[son + 1]) {  // 右子树存在，选择最大的节点
            son++;
        }
        if (heap[father] > heap[son]) return;               // 如果父节点小，就不需要调整了
        else {
            swap(heap[father], heap[son]);                  // 进行调整
            father = son;
            son = 2 * father + 1;
        }
    }
}

/** 计数排序 */
void Sort::countingSort(vector<int> &nums) {
    int len = nums.size();
    vector<int> cnt(100, 0);
    for (int i = 0; i < len; ++i) {
        cnt[nums[i]]++;
    }
    for (int i = 0, k = 0; i < 100; ++i) {
        while (cnt[i] != 0) {
            nums[k++] = i;
            cnt[i]--;
        }
    }
}

/** 基数排序 */
void Sort::radixSort(vector<int> &nums) {
    int len = nums.size();
    vector<vector<int>> cnt(10);
    for (int i = 0; i < 3; ++i) {   // 个位，百位，千位
        for (int j = 0; j < 10; ++j) {
            cnt[j].clear();         // 先清空
        }
        for (int j = 0; j < len; ++j) {         // 仅在百位上，对所有数进行排序
            cnt[get(nums[j], i)].push_back(nums[j]);
        }
        for (int j = 0, k = 0; j < 10; ++j) {   // 将排序后的数依次重新摆放
            for (int x : cnt[j]) {
                nums[k++] = x;
            }
        }
    }
}

int get(int x, int i) {     // 0代表个位，1代表10位，2代表百位
    while (i--) x /= 10;
    return x % 10;
}

/** 打印数组 */
void Sort::printNums(vector<int> &nums) {
    cout << "the current array is : ";
    for (auto num : nums) cout << num << " ";
    cout << endl;
}