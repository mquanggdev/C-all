#include<bits/stdc++.h>
using namespace std;
/* 
bài toán tạo chuỗi từ ma trận chữ và số :
Cho ma trận n hàng và m cột , trên mỗi ô có chứa chữ số in hoa hoặc ký tự số . Một từ có thể được xây dựng từ các chữ cái của ô liền kề theo thứ tự , trong đó các ô liền kề nằm cạnh nhau theo chiều ngang hoặc dọc. Không được sử dụng cùng một ô chữ cái nhiều lần . Hãy xác định xem có thể tạo thành từ S cho trước không
*/
int n , m , check = 0 ;
string  s ;
char a[1001][1001] ;
int cnt[1001][1001] = {0};
pair<int,int> path[4] = {{-1,0} , {1,0} , {0,-1} , {0,1}} ; // bốn biến tượng chưng cho 4 hướng di chuyển tiếp theo
void Try(int i ,int j , int pos){
    if ( s.size() == pos){ // nếu mà đã đến điểm đích thì nó in ra
        check = 1 ;
        return;
    }

    for ( int k = 0 ; k < 4; k ++){

        int iNext = i + path[k].first ;
        int jNext = j + path[k].second ;

        if (iNext >= 1 && iNext <= n && jNext >= 1 && jNext <= n && cnt[iNext][jNext] == 0 && a[iNext][jNext] == s[pos] ){
            cnt[iNext][jNext] = 1 ;
            Try(iNext,jNext,pos+1) ;
            cnt[iNext][jNext] = 0 ;
        }
    }
}
int main()
{
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ ){
        for ( int j = 1 ; j <= m ; j++ ){
            cin >> a[i][j] ;
        }
    }
    cin >> s ;
     for ( int i = 1 ; i <= n ; i++ ){
        for ( int j = 1 ; j <= m ; j++ ){
           if(a[i][j] == s[0]){
              cnt[i][j] = 1 ;
              Try(i,j,1);
              cnt[i][j] = 0 ;
           }
        }
    }
    if (check == 0) cout << "NO" << endl;
    else cout << "YES\n" ;
    return 0 ;
}
/*
4 4 
A C A C
2 8 B 5
1 T E 5
A B C H
28TECH 
YES
*/