#include<bits/stdc++.h>
using namespace std;
/*Thuật toán sắp xếp chèn : insertion sort : Thuật toán này hoạt động bằng cách duyệt qua mảng và chèn phần tử hiện tại về đúng vị trí của nó ( trường hợp này là sắp xếp tăng dần !)
Độ phức tạp o(n^2) -> trường hợp tốt nhất thì có độ phức tạp o(n);
-> Cách xây dựng bài toán đúng với định nghĩa của nó , khi ta mà chèn được phần tử nào đó thì tức là từ vị trí phần tử đó trở về trước thì đã được sắp xếp tăng dần nên ta cứ so sánh lùi dần thì sẽ biết được vị trí chính xác của phần tử đó !
*/
void insertionSort(int a[] , int n){
    for ( int i = 1 ; i < n ; i ++){
        int x = a[i] ; // đánh dấu phần tử đang được xét
        int pos = i - 1 ; // lưu vị trí của phần tử đứng trước nó 
        while ( pos >= 0 && x < a[pos]){ // điều kiện x < a[pos] tức là ta sẽ só sánh nó với các phần tử đứng trước , nếu còn nhỏ hơn sẽ thực hiện trọng ngoặc 
             a[pos + 1] = a[pos] ; //cái này sẽ thay thế một mảng con từ phần tử đang xét trở về trước , đơn giản như sau : 4 5 2 1 3 7 8 , vị trí đang xét là x = 2 -> mảng sau khi hoàn thành vòng while -> 4 4 5 1 3 7 8
             pos -- ; 
        }
        // khi vòng while dừng thì vị trí cần thay thế nó sẽ giảm 1 vị trí so với vị trí đúng nên cần cộng thêm 1 ở dưới -> áp dụng với cả trường hợp dừng do điều kiện pos >= 0 ;
        a[pos + 1] = x ; // lức này mảng sẽ là 2 4 5 1 3 7 8 -> kết thúc một lần duyệt
    }
}
int main()
{
    int n ; cin >> n ;
    int a[1001] ;
    for ( int i = 0 ; i < n ; i ++ ){
        cin >> a[i] ;
    }
    insertionSort(a,n);
    for  ( int i = 0 ; i < n ; i ++ ) cout << a[i] << " " ;
    return 0;
}
/*
7
4 5 2 1 3 7 8 
1 2 3 4 5 7 8
*/