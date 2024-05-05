#include<bits/stdc++.h>
using namespace std;
/*
Bài 22 : tích của 3 số : cho số nguyên dương N . nhiệm vụ của bạn là kiểm tra xem có thể viết N = a* b * c hay không trong đó a , b , c là 3 số nguyên dương lớn hơn hoặc bằng 2 khác nhau
*/
int check(int n){
    int cnt_e = 0 ;
    int cnt_p = 0 ;
    for ( int i = 2 ; i <= sqrt(n) ; i++ ){
        if ( n % i == 0){
            cnt_p ++ ;
            while ( n % i == 0){
                cnt_e ++;
                n /= i ;
            }
        }
    }
    if ( n != 1) {
        cnt_e++;
        cnt_p++;
    }
    if ( cnt_p >= 3 || cnt_p == 2 && cnt_e >= 4 || cnt_p == 1 && cnt_e >= 6 ) return 1;
    return 0;
}
int main()
{
    int n ; cin >> n ;
    return 0;
}