#include<iostream>
using namespace std;

const int default_size = 100;
class MySet{
public:
    MySet(int sz = default_size);   // 构造函数
    MySet(const MySet& set);    // 拷贝构造函数
    ~MySet(){   // 析构函数
        delete [] data;
    }

    int* getData(int i) const{    // 读取集合中第i个元素的值，返回指向该元素的指针
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
};

MySet::MySet(int sz){
    // 构造函数,通过指定参数sz定义数组的长度
    if(sz > 0){
        last = -1;  // 表示不存在元素
        max_size = sz;
        data = new int[sz];
        if(data == nullptr){
            cerr << "存储分配错误" << endl;
            exit(1);
        }
    }
}

MySet::MySet(const MySet& set){
    // 拷贝构造函数，用参数表中给出的已有集合初始化新建的集合
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

int MySet::Search(int x) const{
    // 搜索函数：在集合中顺序搜索与x匹配的元素，找到后返回该元素的是第几个元素
    // 没有找到返回0，表示搜索失败
    for(int i = 0; i <= last; i++){
        if(data[i] == x)
            return i + 1;
    }
    return 0;
}   

bool MySet::Insert(int x){
    // 插入函数：在集合中插入元素x，在最后一个位置插入
    if(Search(x) == 0 && last + 1 <= max_size){ // 集中没有找到相同元素，并且空间足够大，则可以插入
        data[last + 1] = x;
        last += 1;
        return true;
    }
    return false;
}

bool MySet::Delete(int x){
    // 删除函数：删除集合中的元素x
    int pos = Search(x);
    if(pos == 0)
        return false;   // 没有找到该元素，返回失败
    else{
        // 将元素前移
        for(int i = pos; i <= last; i++){
            data[i - 1] = data[i];
        }
        data[last] = 0;
        last -= 1;  
    }
    return true;
}

int main(){
    MySet set(10);  // 集合中可以存储10个元素
    set.Insert(1);
    set.Insert(2);
    set.Insert(3);
    set.Insert(4);

    set.Delete(4);  

    cout << "pos: " << set.Search(3) << endl;

    set.Insert(5);
    set.Insert(3);

    set.Show();

    return 0;
}