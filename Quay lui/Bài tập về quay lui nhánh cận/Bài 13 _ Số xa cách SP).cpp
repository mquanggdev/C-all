#include<bits/stdc++.h>
/* Bài 13 : số xa cách SPO : cho số nguyên dương n(2 < n < 10) . Một số nguyên dương k có N chữ số được gọi là số xa cách nếu thỏa mãn K không chứa chữ số 0 . Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng một lần . Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1
--> Nhận thấy bài này chính là sinh hoán vị có điều kiện là hai phần tử cạnh nhau thì không được có hiệu bằng 1 và không được tùng lặp nhau 
*/
using namespace std;
int n , a[1001] , x[50] , used[50];
// void init(){
//     cin >> n ;
//     for ( int i = 1 ; i <= n ; i++ ){
//         cin >> a[i] ;
//     }
// }
void in(){
    for ( int u = 1 ; u <= n ; u ++){
        cout << x[u];
    }
    cout << endl ;
}
void ql(int i){
    for( int j = 1 ; j <= n ; j++ ){
        if ( !used[j] && abs((j - x[i - 1])) != 1){ // nhánh cận chỗ này là nếu kiểm tra số tiếp theo thêm vào cấu hình mà trừ đi số đằng trước cấu hình mà != 1 thì ta mới thực hiện 
            x[i] = j ;
            used[j] = true ;
            if ( i == n){
                in() ;
            }
            else ql(i + 1) ;
            used[j] = false ;
        }
    }
}
int main()
{
    cin >> n ;
    x[0] = -1 ; // trong trường hợp ql[1] chẳng may j - x[i - 1] thì vô tình không thể gán cho j = 1 , như thế là không hợp lệ 
    ql(1) ;
    return 0 ;
}
/*
4
2413
3142
*/