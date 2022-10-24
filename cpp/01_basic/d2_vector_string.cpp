#include<iostream>
#include<vector>
#include<string.h>
#include<string>

// 使用vector 装 字符串 数组
int main(){
    char tmp[20]; //临时字符数组
    std::vector<std::string> names;

    // 输入
    while(true){
        printf("Pls input a name (0 to end input):");
        scanf("%s", tmp);
        if( strcmp(tmp, "0")==0) break;
        names.push_back(tmp);
    }

    // 打印
    for(int i=0; i<names.size(); i++){
        printf("names[%d]=%s <= %p\n", i, names[i].c_str(), names[i].c_str()); //为什么地址不一样呢？正好差了10
    }
    printf("\n");

    //使用迭代器打印
    for(auto be=names.cbegin(); be<names.cend(); ++be){
        std::cout << *be << " | " << &*be << std::endl;
    }
    printf("\n");

    std::string &s1=names[0];
    std::cout << s1 << " | " << &s1 << std::endl; 
    std::cout << s1 << " <= " << (void *)s1.c_str() << std::endl;

    return 0;
}