#include<bits/stdc++.h>
using namespace std;
/*Bài tìm cặp số có tổng < k : cho mảng a gồm n phần tử và số nguyên dương k . Đếm số lượng cặp số a[i] , a[j] có tổng bằng k : -> sử dụng tìm kiếm nhị phân
*/
int bn(int a[] , int n , int k){
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; i++){
        auto it = lower_bound(a + i + 1 , a + n , k - a[i]) ;
        it-- ;
        int idx = it - a ;
        cnt += idx - i;
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
/*/*
4 5
2 2 2 2
6
*/
