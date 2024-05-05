#include<bits/stdc++.h>
using namespace std;
/*
    Thuật toán sắp xếp nổi bọt ( Bubble sort ) : thuật toán này thì ngược lại với thuật toán sắp xếp chọn , sau mỗi lần lặp nó sẽ cố gắng đưa phần tử lớn nhất về cuối dãy .
    -> Cách xây dựng khá đơn giản : ta chỉ cần so sánh hai phần tử liên tiếp nhau và đưa chúng về đúng vị trí !
    Độ phức tạp : o(n) ;
*/
void BubbleSort(int a[] , int n) {
    for ( int i = 0 ; i < n - 1 ; i++) {
        bool haveSwap = false ;
        for (int j = 0 ; j < n - i - 1 ; j++){ // sau mỗi vòng lặp thì các vị trí phía cuối đã được sắp xếp rồi nên không cần nữa nên mới có điều kiện n - i - 1 ;
            if (a[j] > a[j + 1]){
                swap(a[j],a[j+1]);
                haveSwap = true ;
            }
        }
        if ( haveSwap == false ) break ;  // nếu mà sau khi lặp không có hành động sắp xếp nào xảy ra thì return ;
    }
}
int main()
{
    int n ; cin >> n ;
    int a[1001] ;
    for ( int i = 0 ; i < n ; i++) cin >> a[i] ;
    BubbleSort(a,n);
    for ( int i = 0 ; i < n ; i++) cout << a[i] << " " ;
    return 0; 
}
/*
7
4 5 1 3 2 7 6
1 2 3 4 5 6 7 
*/