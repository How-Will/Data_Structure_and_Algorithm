#include<iostream>
using namespace std;

const int default_size = 100;

class OrderedArr{
public:
    OrderedArr(int sz = default_size);   // 构造函数
    OrderedArr(const OrderedArr& set);    // 拷贝构造函数
    ~OrderedArr(){   // 析构函数
        delete [] data;
    }

    int* getData(int i) const{    // 读取数组中第i个元素的值，返回指向该元素的指针
        return (i > 0 && i <= last + 1) ? &data[i - 1] : nullptr;
    }
    int Search(int x) const;   // 搜寻x在集合中的位置，返回表项序号
    bool Insert(int x);        // 插入x
    bool Delete(int x); // 删除集合中的元素x
    void Show(){    // 显示集合中的元素
        for(int i = 0; i <= last; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
private:
    int* data;  // 存储数组
    int last; // 当前已存表项的最后位置(从0开始)
    int max_size;   // 集合中最多可以存放的元素个数
    void bubbleSort(){
        for(int i = 0; i <= last; i++){
            for(int j = i + 1; j <= last; j++){
                if(data[i] > data[j]){
                    int temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }
};

OrderedArr::OrderedArr(int sz){     // 构造函数
    if(sz > 0){
        last = -1;
        max_size = sz;
        data = new int[sz];
        if(data == nullptr){
            cerr << "内存分配失败" << endl;
            exit(1);
        }
    }   
}

OrderedArr::OrderedArr(const OrderedArr& set){  // 拷贝构造函数
    last = set.last;
    max_size = set.max_size;
    data = new int[max_size];
    if(data == nullptr){
        cerr << "存储分配错误" << endl;
        exit(1);
    }
    for(int i = 1; i <= last + 1; ++i){
       data[i - 1] = *set.getData(i);
    }
}

int OrderedArr::Search(int x) const{    // 搜寻x在集合中的位置
    // 搜索函数：在集合中顺序搜索与x匹配的元素，找到将该元素的是第几个元素通过pos返回
    // 没有找到返回false，表示搜索失败
    int beg = 0; 
    int end = last;
    int middle = (beg + end) / 2;
    while(beg < end){
        if(x < data[middle]){
            end = middle;
        }else if(x > data[middle]){
            beg = middle;
        }else{
            // 找到目标元素
            return middle + 1;
        }
        middle = (beg + end) / 2;
    }
    return 0;
}   

bool OrderedArr::Delete(int x){
    // 删除函数：删除集合中的元素x
    int pos = Search(x);
    if(pos == 0)
        return false;   // 没有找到该元素，返回失败
    else{
        // 将元素前移,删除目标元素
        for(int i = pos; i <= last; i++){
            data[i - 1] = data[i];
        }
        data[last] = 0;
        last -= 1;  
    }
    return true;
}

bool OrderedArr::Insert(int x){
    // 插入函数，保证插入到正确的位置
    if(last + 1 <= max_size){
        data[last + 1] = x;
        last += 1;
        bubbleSort();
        return true;
    }
    return false;
}


int main(){
    OrderedArr arr(10);

    arr.Insert(1);
    arr.Insert(7);
    arr.Insert(3);
    arr.Insert(4);
    arr.Insert(5);
    arr.Insert(1);

    cout << "pos: " << arr.Search(3) << endl;


    arr.Show();

    return 0;
}