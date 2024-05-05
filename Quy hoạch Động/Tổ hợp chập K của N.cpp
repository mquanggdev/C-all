#include<bits/stdc++.h>
using namespace std;
/*Bài 31 : Tổ hợp chập K của n : Tìm tổ hợp chập K của n chia dư cho 1e9 + 7

bài này cũng có thể áp dụng quy hoạch động : _ Nguyên lý của nó dựa trên quy tắc Pascal -> thằng tam giác pascal này với mỗi phần tử đều là tổ hợp nCk. và ta có thể áp dụng nó vào để tìm
Tư tưởng : tư tưởng của bài toán là ta đi xây dựng một tam giác pascal sẵn với công thức 
nCk = n-1Ck-1 + n-1Ck -> hãy nhớ là phần tử bên dưới sẽ bằng 2 phần tử bên trên cộng lại 
với bài toán con nhỏ nhất là nếu k = 0 thì in 1 , k= n cũng in 1 : 
*/

long long C[1001][1001] ;// tổ hợp chập j của i

int main()
{
    for ( int i = 0 ; i <= 1000 ; i++){
        for ( int j = 0 ; j <= i ; j++){
            //C[i][j]
            if ( j == 0 || i == j){
                C[i][j] = 1;
            }
            else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007 ;
            }
        }
    }
    int t ; cin >> t ;
    while ( t--){
        int n , k ;
        cin >> n >> k ;
        cout << C[n][k] << endl;
    }
    return 0;
}
/*
5
9 0
13 8
16 7
9 9
7 6

1
1287
11440
1
7


*/