#include<bits/stdc++.h>
using namespace std;
/**
 * Equal set : Nhiệm vụ của bạn là đếm số cách các số 1 , 2 ,...n có thể chia thành hai tập hợp có tổng bằng nhau . Các phần tử trong tập không xét đến thứ tự . Ví dụ , nếu n = 7 , có bốn nhiệm : {1,3,4,6} va {2,5,7} ,
 * {1,2,5,6} và {3,4,7,} 
 * 1,2,4,7 và 3 5 6 
 * 1,6,7 và 2 3 4 5 
*/
int F[1001]; // tại giá trị j thì có F[j] cách chia số
int main(){
    int n ; cin >> n ;
    int s = n * ( n + 1) / 2;
    if ( s % 2 == 0){
        s /= 2 ;
        F[0] = 1 ;
        // bat su kien F[s] chua so 7 
        // lay no hoac khong lay
        int res ;
        for ( int i  = 1 ; i <= n ; i++ ){
            for ( int j = s ; j >= 1 ; j-- ){
                if ( j >= i){
                    F[j] = F[j] + F[j - i]; // 
                    if ( j == s && i == n) res = F[j - i] ;
                }
            }
        }
        cout << res ;
    }
    else cout << "0" ;
    return 0;
}