#include<bits/stdc++.h>
using namespace std;
/*Bài 12 : Sô may mắn
-> càng nhiều số 7 thì tổng chữ số càng lớn nhưng giá trị số sẽ nhỏ -> tham lam từ 7 trở xuống ->*/
int main()
{
    int n ; cin >> n;
    for ( int y = n / 7 ; y >= 0 ; -- y){
        int x  = (n - 7 * y)/4 ;
        if ( 4 * x + y * 7 == n){
        for (int i = 1; i <= x ; i++){ cout << "4" ;}
        for (int j = 1 ; j <= y ; j++){ cout << "7" ;}
         return 0 ;
        }
    }
    cout << "-1" ;
}
/*
16
4444
*/