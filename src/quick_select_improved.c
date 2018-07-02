#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int i, j, l, pivot, r, z, b;

// 先頭の要素をピボットとする
    b = A[n/2];
    A[n/2] = A[0];
    A[0] = b;
    
    pivot = A[0];
    
    if(n == 1)return pivot;
    
    for(i = j =1; i < n; i++){
        if(A[i] < pivot){
            z = A[i];
            A[i] = A[j];
            A[j] = z;
            j = j + 1;
        }
    }
    
    for(l = r = n-1; l > 0; l = l-1){
        if(A[l] > pivot){
            z = A[l];
            A[l] = A[r];
            A[r] = z;
            r = r - 1;
        }
    }
       
    b = A[0];
    A[0] = A[j-1];
    A[j-1] = b;
  
  if(j-1 <= k && k <= r)return pivot;
  else if(k <= j-2)return quick_select(A, j-1, k);
  else return quick_select(A+r+1, n-1-r, k-r-1);
  
  }

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
