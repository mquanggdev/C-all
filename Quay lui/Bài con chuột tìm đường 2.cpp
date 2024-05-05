#include<bits/stdc++.h>
using namespace std;
/* Bài toán con chuôt đi trong mê cung : cho ma trận NxN được biểu diễn bởi các số 0 và 1  ,con chuột đi theo số 1 , tìm đường đi cho con chuột từ điểm 00 tới điểm nn , nếu mà đi xuống in ra D , đi bên phải in ra R , L và T thì tương tự
Hãy in ra tất cả con đường có thể đi được của con chuột
*/
int n , a[1001][1001] , check = 0;
pair<int,int> path[4] = {{-1,0} , {1,0} , {0,-1} , {0,1}} ; // bốn biến tượng chưng cho 4 hướng di chuyển tiếp theo
string S = "TDLR" ; // các ký tự tương ứng với 4 hành động trên .
string s = "" ;
void Try(int i ,int j){
    if ( i == n && j == n){ // nếu mà đã đến điểm đích thì nó in ra
        check = 1 ;
        cout << s << endl;
        return;
    }

    for ( int k = 0 ; k < 4; k ++){
        int iNext = i + path[k].first ;
        int jNext = j + path[k].second ;

        if (iNext <= n && jNext <= n && a[iNext][jNext] == 1){
            a[iNext][jNext] = 0 ;
            s += S[k] ;
            Try(iNext,jNext) ;
            s.pop_back() ;
            a[iNext][jNext] = 1 ;
        }
    }
}
int main()
{
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ){
        for ( int j = 1 ; j <= n ; j++ ){
            cin >> a[i][j] ;
        }
    }
    Try(1,1) ;
    return 0 ;
}
/*
4
1 1 1 1
1 1 0 1
1 1 1 1
0 1 1 1
DDDRRR
DRRDDR
DRRDRD
DRRRDD
RDRDDR
RDRDRD
RDRRDD
*/