#include <stdio.h>

//フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
    
    int i, j, pivot, r, z, b;
    
    if(n > 0){
    pivot = A[0];
    i = 1;
    j = 1;
    r = n-1;
  while(i < n){
    if(A[i] < pivot){
      int z = A[j];
      A[j] = A[i];
      A[i] = z;
      j++;
    }
    i = i+1;
}
    i = n-1;
    while(i > 0){
    if(A[i] > pivot){
        z = A[r];
        A[r] = A[i];
        A[i] = z;
        r = r-1;
    }
    i = i-1;
    }
    
    b = A[0];
    A[0] = A[j-1];
    A[j-1] = b;
    
    quick_sort(A, j-1);
    quick_sort(A+r+1,n-1-r);
    }
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
