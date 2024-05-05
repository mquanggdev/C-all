#include<bits/stdc++.h>
using namespace std;
/*
bài 24 : String game : 2 người chơi game với quy tắc đưcọ chọn 1 trong 2 nước : nước 1 là : chọn 1 ký tứ và xóa cái ký tự đó khỏi xâu : nước 2 : sắp xếp xâu mà nếu sắp xếp được thành đối xứng là win : A là người đi trước , hỏi A có win game không biết cả 2 đều chơi tối ưu
-> điều kiện win của bài này là : thằng nào còn lại toàn kí tự có lẻ lần mà cũng là số lẻ thì thằng đó win
-> Bài này thì có 2 trường hợp -> thằng nào muốn thắng thì bài thằng đó phải chứa lẻ 
=> nó phải đánh làm sao thằng thứ hai phải rơi vào chẵn thì đến lượt nó nó mới đổi về lẻ được => thằng nào đánh trước sẽ cố gắng đẩy thằng thứ 2 vào thế bị dính chẵn 

mà dạng bài này thì 2 thằng logic như nhau nên cách đánh là giống nhau
=> thằng đánh trước đã ăn bài , nếu mà dãy có sự xuất hiện những kí tự lẻ là lẻ lần thì thằng 1 luôn win, ngược lại là thằng 2
*/
int main()
{
    string s ; cin >> s ;
    int d[256] = {0} ;
    for ( char x : s){
        d[x] ++ ;
    }
    int so_luong_tan_xuat_le = 0 ;
    for ( int i = 0 ; i < 256 ;i ++){
        if(dp[i] % 2 == 1) so_luong_tan_xuat_le ++;
    }
    if( so_luong_tan_xuat_le == 0 || so_luong_tan_xuat_le % 2 == 1){
        cout << 1 ;
    }
    else cout << 2 ;
    return 0;
}