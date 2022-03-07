#include<iostream>

using namespace std;

// 冒泡排序
void bubbleSort(int* nums, int len){
    int index = len - 1;
    bool flag = false;   // 如果不再发生元素交换，说明数组已经有序，则flag=true
    while(!flag){
        flag = true;    // 假设有序
        for(int i = 0; i < index; i++){
            if(nums[i] > nums[i+1]){
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;

                flag = false;
            }
        }
        index -= 1; // 每一轮都找到一个最大的数
    }
}

// 选择排序
void selectSort(int* nums, int len){
    for(int i = 0; i < len; i++){
        int lowest_index = i;
        for(int j = i + 1; j < len; j++){
            if(nums[j] < nums[lowest_index])
                lowest_index = j;
        }

        if(lowest_index != i){
            int temp = nums[i];
            nums[i] = nums[lowest_index];
            nums[lowest_index] = temp;
        }
    }
}

int main(){ 
    int numbers[] = {3, 4, 1, 6, 7, 8, 9};
    const int length = sizeof(numbers) / sizeof(numbers[0]);
    
    selectSort(numbers, length);

    for(int i = 0; i < length; i++){
        cout << numbers[i] << " ";
        cout << endl;
    }

    return 0;
}