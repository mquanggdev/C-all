#include<bits/stdc++.h>
using namespace std;
/*Bài đếm mảng con có tổng chia hết cho K
ý tưởng : cũng dùng mảng cộng dồn để lưu tổng của từng vị trí và sẽ đi tìm chỉ số i mà tại đó ta có sum - sum chia hết cho 3
ví dụ sum của chỉ số 5 là  10 / 3 dư 1
      sum của chỉ số 3 là 7 chia 3 cũng dư 1 thì sum[5] - sum[3] sẽ là cái cửa sổ có tổng chia hết cho 3
*/
int main()
{
    int n,x, a[110] ;
    cin >> n >> x  ;
    for ( int i = 0 ; i < n ; i++ ){
        cin >> a[i] ;
    }
    map<int,int> mp ;
    int sum = 0 ;
    int ans = 0 ;
    // dung mảng cộng dồn
    for ( int i = 0 ; i < n ; i++){
      sum += a[i] ;
      sum = (sum % n + n) % n ; // để tránh trường hợp số bị âm // sum %= n ;
      if ( mp.count(sum)){ // map nó sẽ lưu lại các tổng cộng dồn , nếu nó tìm thấy có tồn tại 1 tổng k sao cho k = sum - x thì tức là tồn tại 1 cửa sổ chứa các số đó
        ans += mp[sum] ;
      }
      if (sum == 0) ++ ans ;
      mp[sum] ++ ;
    }
    cout << ans ;
    return 0 ;
}
/*
5 
4 2 1 5 3
3
*/