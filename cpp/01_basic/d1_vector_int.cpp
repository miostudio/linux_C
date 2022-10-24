#include<iostream>
#include<vector>
#include<algorithm> //sort 函数需要的头文件

int main(){
    int height=0;  //存放键盘输入的身高
    std::vector<int> vheight; //声明存放身高的容器

    while(true){
        printf("Plse input a height, int type(0 - end input)");
        scanf("%d", &height);
        if(height ==0) break;
        vheight.push_back(height); //新数据追加到容器
    }

    // 排序前
    for(int i=0; i<vheight.size(); i++){
        printf("vheight[%d]=%d\n", i, vheight[i]);
    }


    //排序
    sort(vheight.begin(), vheight.end());

    printf("\n");

    //排序后
    for(int i=0; i<vheight.size(); i++){
        printf("vheight[%d]=%d\n", i, vheight[i]);
    }

    //vheight.clear(); //清空容器，可选
}