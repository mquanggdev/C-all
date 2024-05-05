#include<bits/stdc++.h>
using namespace std;
/*Thuật toán sắp xếp trộn (Merge Sort) : thuật toán sắp xếp trộn hai dãy đã được sắp xếp thành một dãy đã được sắp xếp
Thuật toán này hoạt động theo nguyên tắc chia để trị  
Đầu tiên ta cần chuẩn bị một thuật toán để trộn dãy 
tiếp theo ta cần chia nhỏ dãy đã cho thành nhiều dãy nhỏ hơn thông qua hàm đệ quy ,
Bài toán con nhỏ nhất chính là ghép hai số theo thứ tự tăng dần (giảm dần)
*/
void merge(int a[] , int l , int r , int m ){
    vector<int> x(a + l , a + m + 1 ) ;
    vector<int> y(a + m + 1 , a + r + 1);

    int i = 0 ;
    int j = 0 ;
    while ( i < x.size() && j < y.size() ){
        if ( x[i] <= y[j] ){
            a[l] = x[i] ;
            l++;
            i++;
        }
        else {
            a[l] = y[j] ;
            j++;
            l++;
        }
    }
    // Trong trường hợp còn sót phần tử chưa được điền hết!
    while (i < x.size()){
        a[l] = x[i] ;
        l++;
        i++;
    }
    while(j < y.size()){
        a[l] = y[j] ;
        j++;
        l++;
    }
}


// Hàm sắp xếp trộn
void mergeSort(int a[] , int l , int r ){
    if ( l >= r ) return ;
    int m = (l + r) / 2 ;
    // chia nhỏ mảng ra thành các mảng con nhỏ hơn đến khi mỗi mảng chỉ còn một phần tử
    mergeSort(a , l , m) ; 
    mergeSort(a , m + 1 , r) ;
    merge(a, l , r , m) ; // hợp nhất các mảng con lại với nhau
}
int main()
{
    int n ; cin >> n ;
    int a[n] ;
    for ( int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    mergeSort(a,0,sizeof(a)/sizeof(a[0])-1); // mergeSort(a,0,n-1) ;
    for ( int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
    return 0;
}
/*
7
4 5 1 3 2 7 6
1 2 3 4 5 6 7
*/