#include<bits/stdc++.h>
using namespace std;
/*Bài tìm mảng con có tổng bằng x , các phần tử là nguyên dương , nếu có phần tử âm thì nó lại khác(xem lại)
ý tưởng : đối với mỗi chỉ số i trong mảng => xác định xem có tồn tại 1 dãy con kết thúc tại chỉ số i có tổng bằng X hay không
*/
void truonghopam() {
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
      if ( mp.count(sum - x)){ // map nó sẽ lưu lại các tổng cộng dồn , nếu nó tìm thấy có tồn tại 1 tổng k sao cho k = sum - x thì tức là tồn tại 1 cửa sổ chứa các số đó
          ans += mp[sum - x] ; // nó sẽ cộng bằng số lần mà tìm thấy phafn tử k = sum - x thì tức là tồn tại bấy nhiêu cửa sổ có tổng bằng x
      }
      if (sum == x) ++ ans ;
      mp[sum]++ ; // vì có số âm nên có rất nhiều sum có tổng trùng nhau
    }
    cout << ans ;
}
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
      if ( mp.count(sum - x)){ // map nó sẽ lưu lại các tổng cộng dồn , nếu nó tìm thấy có tồn tại 1 tổng k sao cho k = sum - x thì tức là tồn tại 1 cửa sổ chứa các số đó
        ans++ ;
      }
      if (sum == x) ++ ans ;
      mp[sum] = 1 ;
    }
    cout << ans ;
    return 0 ;
}
/*
5 7
2 4 1 2 7
3
*/