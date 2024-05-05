#include<bits/stdc++.h>
using namespace std;
/*Bài tìm cặp số có tổng bằng K : cho mảng a gồm n phần tử và số nguyên dương k . Đếm số lượng cặp số a[i] , a[j] có tổng bằng k : -> sử dụng tìm kiếm nhị phân
ý tưởng : Đầu tiên ta cần sắp xếp dãy theo thứ tự tăng dần , với mỗi a[i] thì ta phải đi tìm tất cả những phần tử mà = k - a[i] : bằng cách dùng lower và upper , mục đích làm như vậy là để không bị lặp cặp số rồi ta cộng tất cả những cặp đó lại :
độ phức tạp khi làm như vậy chỉ là O(nlogn) = duyet n lần và logn lần tìm kiếm!
*/
int bn(int a[] , int n , int k){
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; i++){
        auto it = lower_bound(a + i + 1 , a + n , k - a[i]) ;
        auto it1 = upper_bound(a + i + 1 , a + n , k - a[i]) ;
        cnt += it1 - it ;
    }
    return cnt ;
}
int main()
{
    int n , k;
    int a[1001] ;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    sort(a , a + n);
    cout << bn(a,n,k);
    return 0;
}
/*
4 4
2 2 2 2
6
*/