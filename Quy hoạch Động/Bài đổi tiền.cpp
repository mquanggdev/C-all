#include<bits/stdc++.h>
using namespace std;
/*Bài 15 : Coin Problem: Ngân Hàng X có N tờ tiền có mệnh giá khác nhau được lưu vào mảng C , bạn hãy tìm cách đổi số tiền là S sao cho số tờ tiền cần dùng là ít nhất.Có thể sử dụng mệnh giá không giới hạn lần :
Khá giống subset sum nhưng được lặp lại */
/*
// khi mà dùng đến tờ tiền i thì xét xem trước đó mệnh giá mà khi lấy mệnh giá hiện tại trừ đi giá trị tờ tiền mà tồn tại số tờ tiền đổi rồi thì nó cập nhật lại : Ví dụ với đề bài như sau
S = 9  có các tờ tiền là 2 3  7 
thì đang xét đến tờ tiền 3 và mệnh giá đang xét là 8 thì thấy với mệnh giá 8 thì đang có 4 tờ tiền 2 cộng lại 
nó lấy 8 - 3 = 5 -> với mệnh giá 5 thì kỷ lục số tờ được chọn nhỏ nhất là bao nhiêu? trong trường hợp này là = 2 thì tức là nếu nó lấy đồng tiền số 3 này đổi thì với mệnh giá 8 nó sẽ chỉ mất 2 đồng tiền đã đổi ra mệnh giá 5 và một đồng tiền mệnh giá 3 nữa thôi thì sẽ đủ mệnh giá 8 và nó chỉ mất có 3 đồng tiền để đổi thay vì 4 đồng tiền như trước => nó cập nhật lại !.
*/
int n , S ;
int C[1001];
int a[101] ;
int main()
{
    cin >> n >> S ;
    C[0] = 0 ;
    for ( int i = 1 ; i < 1001 ; i++){
        C[i] = 1001;
    }
    for ( int i = 1; i <= n ; i++ ){
        cin >> a[i] ;
    }
    for (int i = 1 ; i <= n ; i++ ){
        for ( int j = a[i] ; j <= S ; j++ ){
              C[j] = min( C[j] , C[j - a[i]] + 1) ; 
        }
    }
    cout << C[S] ;
    return 0 ;
}