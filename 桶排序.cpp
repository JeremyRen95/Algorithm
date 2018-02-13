/*
  对0~9内的一堆数字进行从小到大排序 例如{6,5,7,3,2,6,5,8,9,7}
  此程序运用桶排序进行解决
*/
#include "iostream"

using namespace std;

int a[10] = {6,5,7,3,2,6,5,8,9,7}; //需要排序的一堆数据

int* sorting(int* aa,int length){
    int *sort_array = new int [10];
        for(int i=0;i<10;i++){
        sort_array[i] = 0;
    }
    for(int i=0;i<length;i++){
        sort_array[aa[i]] += 1;
    }
    return sort_array;
}

int main(){
    int* ret;
    ret = sorting(a,10);

    for(int i=0;i<10;i++){
        while(ret[i] != 0){
            cout << i << ' ';
            ret[i] -= 1;
        }
    }

    return 0;
}
