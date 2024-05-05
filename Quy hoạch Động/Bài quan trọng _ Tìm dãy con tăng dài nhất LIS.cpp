#include<bits/stdc++.h>
/* Bài dãy con tăng dài nhất : LIS -> nên xem lại nhiều

cách 1 : (On^2) : tư tưởng cũng là xây dựng lên mảng F[i] : dãy con dài nhất tăng dần kết thúc ở chỉ số i
-> điều khác biệt ở bài này : do là dãy tăng dần nên từ i đổ về trước , ta bắt buộc phải tìm được thamwngf F[j] nào đó mà tại đó a[j] < a[i] thì ta mới bắt đầu cập nhật độ dài : bởi vì là dãy tăng dần nên ở chỉ số i thì những thằng lớn hơn a[i] sẽ không được tính 

*/

using namespace std;
int a[1001];
int F[1001] ;
int n ;
 int max_value = INT_MIN ;
void solve(){
    for ( int i = 1; i <= n ; i++) {
        F[i] = 1 ;
    }
   
    for ( int i = 2 ; i <= n ; i++){
        for ( int j = 1 ; j < i ; j++){
            if(a[j] < a[i]){
                F[i] = max(F[i],F[j]+1);
                if ( max_value < F[i]){
                    max_value = F[i] ;
                }
            }
        }
    }
}
int main() {
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ){
        cin >> a[i] ;
    }
    solve() ; 
    cout << max_value ;
    return 0;
}
/*
14
128 104 53 876 660 961 754 775 290 231 224 915 392 994
6
*/