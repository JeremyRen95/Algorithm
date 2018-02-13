/*
  此程序利用快速排序算法对一堆不相等乱序的数进行从小到大排序，测试数据{5,8,6,1,7,17,12,9,11,10}
*/
#include "iostream"

using namespace std;

int a[10] = {5,8,6,1,7,17,12,9,11,10}; //测试数据

void quick_sort_iteration(int* bb,int arrstart,int arrend);

int* quick_sort(int* aa,int length){
    int* sort_array = new int [length];
    for (int i=0;i<length;i++){  //复制数组数据
        sort_array[i] = aa[i];
    }
    quick_sort_iteration(sort_array,0,length-1);

    return sort_array;
}

void quick_sort_iteration(int* bb,int arrstart,int arrend){
    if(arrend < 0 | arrstart > 9 | arrstart >= arrend){ //递归终止条件
        return ;
    }
    int index = arrstart-1;
    int small = arrstart-1;
    for(int i=arrstart;i<arrend;i++){
        if(bb[arrend] > bb[i]){
            if(small != index){
                int temp;
                temp = bb[small+1];
                bb[small+1] = bb[i];
                bb[i] = temp;
            }
            small += 1;
        }
        index += 1;
    }
    if(small != index){
        int temp;
        temp = bb[arrend];
        bb[arrend] = bb[small+1];
        bb[small+1] = temp;
    }
    quick_sort_iteration(bb,arrstart,small);
    quick_sort_iteration(bb,small+2,arrend);
}

int main(){
    int* ret;
    ret = quick_sort(a,10);

    for(int i=0;i<10;i++){
        cout << ret[i] << ' ';
    }
    return 0;
}

