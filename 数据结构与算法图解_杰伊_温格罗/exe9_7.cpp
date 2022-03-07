#include<iostream>
using namespace std;

int binarySearch(int* nums, int target, int low, int high){
    int middle = (low + high) / 2;
    if(target == nums[middle]){     // 找到目标，返回索引
        return middle;
    }
    if(low >= high){    // 没有找到，返回-1
        return -1;
    }else if(target > nums[middle]){
        return binarySearch(nums, target, middle + 1, high);
    }else if(target < nums[middle]){
        return binarySearch(nums, target, low, middle - 1);
    }
    return -1;
}

int main(){
    int nums[] = {1, 2, 3, 4, 5};

    int index = binarySearch(nums, 6, 0, 5);
    cout << index << endl;

    return 0;
}