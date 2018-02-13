/*
 此程序采用冒泡程序对一堆整数进行从大到小排序，测试数据{6,5,7,3,2,6,5,8,9,7}
*/
#include "iostream"

using namespace std;

int a[10] = {6,5,7,3,2,6,5,8,9,7};

int* sorting(int* aa,int length){
    int* sort_array = new int [length]; //为了不改变原有数组重新建立数组
    for(int i=0;i<length;i++){
        sort_array[i] = aa[i];  //复制数组
    }
    //需要n-1次总体冒泡
    for(int i=1;i<length;i++){
        for(int j=0;j<length-i;j++){
            if(sort_array[j+1]>sort_array[j]){
                int temp;
                temp = sort_array[j];
                sort_array[j] = sort_array[j+1];
                sort_array[j+1] = temp;
            }
        }
    }
    return sort_array;
}

int main(){
    int* ret;
    ret = sorting(a,10);

    for(int i=0;i<10;i++){
        cout << ret[i] << ' ';
    }

    return 0;
}
