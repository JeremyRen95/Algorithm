/*
  ����һ�����������֣�������������������б������������ݼ�Ϊ{1��2��3}
*/
#include "iostream"

using namespace std;

int a[4] = {1,2,3,6};

void dfs_iter(int*assem,int* book,int* aa,int length,int step);

void dfs(int* aa,int length){
    int* book = new int[length];
    int* assem = new int[length];

    for(int i=0;i<length;i++){
        book[i] = 0;
        assem[i] = 0;
    }

    dfs_iter(assem,book,aa,length,0);

    delete[] book;
    delete[] assem;
}

void dfs_iter(int* assem,int* book,int* aa,int length,int step){
    if(length == step){ //��ֹ����
        for(int i=0;i<step;i++){
            cout << assem[i] << ' ';
        }
        cout << endl;
        return ;
    }
    for(int i=0;i<length;i++){
        if(book[i] == 0){
            assem[step] = aa[i];
            book[i] = 1; //����Ѿ��ù�
            dfs_iter(assem,book,aa,length,step+1);
            book[i] = 0;
        }
    }

    return ;
}

int main(){
    dfs(a,4);

    return 0;
}
