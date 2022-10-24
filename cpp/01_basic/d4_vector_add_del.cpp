#include<iostream>
#include<vector>
using namespace std;

// vector的操作
void print(vector<int> v1){
    cout << "[";
    for(auto i: v1)
        cout << i << ", ";
    cout << "]" << endl;
}

int main(){
    vector<int> iVec={-1,1,2,3,4,5};
    print(iVec);

    //增加一个元素
    iVec.push_back(100); //末尾增加
    print(iVec);

    iVec.insert(iVec.begin()+1, 200); // 在下标1(第2个元素)之前添加
    print(iVec);

    //删除一个元素
    iVec.erase(iVec.begin()+2); //删除下标是2的元素
    print(iVec);

    iVec.pop_back(); //删除最后一个元素
    print(iVec);

    printf("size: %ld\n", iVec.size());
    if(iVec.empty()){ //判断容器是否为空
        cout << "1 empty now" << endl;
    }else{
        cout << "1 not empty" << endl;
    }
    iVec.clear(); //清空容器的全部元素
    printf("size: %ld\n", iVec.size());
    if(iVec.empty()){
        cout << "2 empty now" << endl;
    }else{
        cout << "2 not empty" << endl;
    }

    return 0;
}