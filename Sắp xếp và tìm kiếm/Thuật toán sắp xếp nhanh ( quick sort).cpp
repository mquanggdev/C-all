#include<bits/stdc++.h>
using namespace std;
/*
Thuật toán sắp xếp quick sort : Thuật toán này khá giống thuật toán merge sort bởi nó cũng hoạt động theo quy tắc chia để trị , nhưng quick sort thì nó sẽ chia mảng thành hai phần , 1 phần gồm các phần tử lớn hơn pivot(chốt) , một phần gồm các phần tử nhỏ hơn pivot , rồi lại gọi đệ quy dến hai mảng đó 
-> vì vậy nó cũng cần một hàm để phần đoạn riêng : và trong đó ta có hai phân hoạch như sau :
 + phân hoạch lomuto , và phân hoạch hoare 
 1 : Lomuto : khá giống với cách giải thích quicksort phía trên 
 2 : Hoare: đọc thêm
*/


/*Phân hoạch lomuto*/
int Partition(int a[] , int l , int r ){
    int pivot = a[r] ;
    int i = l - 1 ;
    for ( int j = l ; j < r ; j++){
        if ( a[j] <= pivot ){ // thằng nào nhỏ hơn cho về đầu dãy 
            i++ ; // lúc mà i++ lên tức là a[i] đang lớn hơn pivot và được bỏ qua khi nãy nên là khi đẩy i lên thì ta sẽ có a[i] > pivot và a[j] < pivot , ta cần đổi chỗ 2 thằng này 
            swap(a[i],a[j]) ; 
        }
    }
    i++ ; // đây là vị trí của pivot sau khi vòng for kia lặp xong
    swap(a[i] , a[r]) ; // chuyển pivot sang
    return i ;
}

void QuickSort(int a[] , int l , int r ){
    if (l >= r) return  ;
    int p = Partition(a,l,r) ;
    QuickSort(a , l , p - 1 ) ; // để trừ vị trí p ra
    QuickSort(a , p + 1 , r ) ;
}
int main()
{
    int a[1001]; 
    int n; cin >> n;
    for ( int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    QuickSort(a , 0 , n - 1);
    for ( int i = 0 ; i < n ; i++) cout << a[i] << " " ;
    return 0;
    
}
/**
 7
10 80 30 90 50 70 60
*/