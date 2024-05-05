#include<bits/stdc++.h>
using namespace std;
/*
Bài đếm mảng con có nhiều nhất k số khác nhau :Cho mảng n số nguyên , nhiệm vụ của bạn là tính mảng con liên tiếp có nhiều nhất k giá trị khác nhau
. dùng 2 con trỏ : ý tưởng : ta sẽ dùng 2 chỉ số l và r : đầu tiên khởi tạo l = 0 và một cái map để lưu số phần tử khác nhau trong một dãy từ l -> r ;
dùng vòng for để duyệt từ 0 -> n kiểm tra chừng nào mà map.size còn nhỏ hơn 3 thì nó sẽ tăng r  đồng thời tăng biến ans lên  rồi nếu mà số phần tử trong map > 3 nó sẽ thực hiện tăng chỉ số l lên để thu hẹp cửa sổ lại  , ở bước thu hẹp này khá khó thiết kế bởi ta phải giảm số lần xuất hiện của nó về 0 rồi mới xóa nó đi được bởi nhiều khi trong dãy sẽ có nhiều phần tử giống nhau và khi tăng l gặp qua nó nó vẫn sẽ tính là một phần tử khác nhau trong map.
*/
int main()
{
    int n , k , a[1001];
    cin  >> n >> k;
    map<int,int> mp ;
    int l = 0 ; 
    int ans = 0;
    for(int i = 0 ;i <n ;i++)
        {
            cin>>a[i] ;
        }
    for ( int r = 0 ; r < n ; r ++){
        mp[a[r]]++ ;
        while(mp.size() > k){ // chỗ này chẳng hạn có dãy 3 3 1 2 4 4 2 ... khi mà r = 4 thì trong map sẽ có 4 phần tử khác nhau nhưng thực tế là có 5 phần tử vì 3 xuất hiện 2 lần nên nếu ta xóa 3 đi chẳng hạn thì nó chỉ xóa 1 số 3 và trong dãy vẫn còn 3 1 2 4 tức là vẫn 4 phần tử khác nhau -> không tăng l được , nên điều kiện tiên quyết là phải giảm hết số lần xuất hiện của a[l] đi rồi xóa nó đi mới tăng l lên được
            mp[a[l]]-- ;
            if ( mp[a[l]] == 0){
                mp.erase(a[l]) ;
            }
            ++l ;
        }
        ans += r - l + 1 ;
    }
    cout << ans ;
    return 0;
}