#include<bits/stdc++.h>
using namespace std;
/* 
Thuật toán sắp xếp chọn (selection sort) : Thuật toán này nó sẽ duyệt qua mảng so sánh phần tử hiện tại với các phần tử trog mảng để tìm ra  phần tử nhỏ nhất và đưa về đầu dãy.
Độ phức tạp của thuật toán là o(n^2) ;
*/
void selectionSort(int a[] , int n){
    for ( int i = 0 ; i < n - 1 ; i ++){
        int min_index = i; // đánh dấu chỉ số phần tử hiện tại làm phần tử có giá trị nhỏ nhất
        for ( int j = i + 1 ; j < n ; j++){
            if (a[j] < a[min_index]){ // bước này rất quan trọng bởi bởi vì ta chỉ đánh dấu vị trí có phần tử nhỏ nhất trong dãy chứ không được đổi trực tiếp .
                min_index = j ; 
            }
        }
        swap(a[min_index],a[i]);
    }
    
}
int main()
{
    int n ; cin >> n;
    int a[1001] ;
    for ( int i = 0 ; i < n ; i ++){
        cin >> a[i] ;
    }
    selectionSort(a,n);
    for (int i = 0 ; i < n ; i++){
        cout << a[i] << " " ;
    }
    return 0;
}
/*
10
1 4 2 3 5 8 7 9 6 10
1 2 3 4 5 6 7 8 9 10
*/