#include<bits/stdc++.h>
using namespace std;
/*
bài 1 : đổi tiền : tại ngân hàng có các mệnh giá 1 , 2 , 5 , 10 , 20, 50 , 100 , 200 , 500 , 1000 . Tổng số tiền có giá trị là n . hãy xác định xem có ít nhất bao nhiêu tờ tiền sau khi đổi tiền ?
*/
int main()
{
    int n ; cin >> n ;
    vector<int> a = {1,2,5,10,20,50,100,200,500,1000};
    int ans = 0 ;
    for ( int i = a.size() - 1 ; i >= 0 ; i--){
        ans += (n / a[i]) ;
        n %= a[i] ;
    }
    cout << ans << endl ;
    return 0;
}
/*
138
6
*/