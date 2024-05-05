#include<bits/stdc++.h>
using namespace std;
/*Bài Thu thập Số : được cung cấp một mảng chứa mỗi số từ 1 -> n đúng 1 lần ; nhiệm vụ của bạn là thu nhập các số từ 1 đến n theo thứ tự tăng dần . Trên mỗi vòng , bạn đi qua mảng từ trái sang phải và thu nhập càng nhiều số càng tốt . Tổng sô vòng là bao nhiêu
tức là duyệt từ đầu đến cuối , v1 : tìm thằng 1 , nếu mà thằng 2 nó đứng trước thằng 1 thì ta phải bắt thằng 2 nó ở vòng sau , còn nếu vị trí của thằng 2 đứng sau số 1 thì ta có thể bắt nó luôn trong một vòng
*/
int main()
{
    int n , a[n] , pos[1001];
    cin >> n ;
    for ( int i = 0 ; i < n ; i++ ){
        cin >> a[i] ;
        pos[a[i]] = i + 1 ; // mảng pos này nó sẽ cho biết các số trên sẽ nằm ở vị trí bao nhiêu để khi mà tìm kiếm ta sẽ biết
    }
    int ans = 1 ;
    for ( int i = 2 ; i < n ; i++){
        if ( pos[i] < pos[i-1]) ++ ans ; // ví dụ nếu vị trí pos[2] < pos[1] tức là thằng số 2 nó đứng sau số 1 thì phải mất thêm 1 vòng để bắt được thằng 2 , do ta không thể quay ngược lại vòng được
    }
    cout << ans ;
    return 0 ;
}
/*
5 
4 2 1 5 3
3
*/