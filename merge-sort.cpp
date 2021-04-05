/* MergeSort_hpp */
#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class MergeSort {
public:
    void sort(vector<int>& arr, int len);
};

#endif /* MergeSort_hpp */


#include "MergeSort.hpp"
void subSort(vector<int>& arr, int left, int right, vector<int>& temp);
void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp);

void MergeSort::sort(vector<int>& arr, int len) {
    if (len < 2) {
        return;
    }
    vector<int> temp(arr);//这里是做了优化，在递归方法外面创建一个专门用于存放每次递归是存放临时有序子数组的数组
    subSort(arr, 0, int(len-1), temp);
}

void subSort(vector<int>& arr, int left, int right, vector<int>& temp){
    if (left < right) {
        int mid = (left + right)/2;
        subSort(arr, left, mid, temp);//左序列归并排序，使得左序列有序
        subSort(arr, mid+1, right, temp);//右序列归并排序，使得右序列有序
        merge(arr, left, mid, right, temp);//将两个有序子数组做合并操作
    }
    
}

/*MergeSort.cpp*/
void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp){
    int i = left;//左序列指针
    int j = mid + 1;//有序列指针
    int p = 0;//临时数组指针
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[p++] = arr[i++];
        }else {
            temp[p++] = arr[j++];
        }
    }
    //将左边剩余元素填充到temp中
    while (i <= mid) {
        temp[p++] = arr[i++];
    }
    //将右序列剩余元素填充进temp
    while (j <= right) {
        temp[p++] = arr[j++];
    }
    p = 0;
    //将temp中的元素全部拷贝到原数组中
    while(left <= right) {
        arr[left++] = temp[p++];
    }
}



/*main*/
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
        vector<int> arr4= {7, 5, 3, 2, 4, 9, 1, 8, 6, 0};
    cout << "arr4: " << endl;
    for (int i = 0; i < 10 ; i++) {
        cout << arr4[i] <<" ";
    }
    cout << endl;
    MergeSort mergeSort = MergeSort();
    mergeSort.sort(arr4, 10);
    cout << "merge sorted arr4: " << endl;
    for (int item : arr4) {
        cout << item <<" ";
    }
    cout << endl;

}