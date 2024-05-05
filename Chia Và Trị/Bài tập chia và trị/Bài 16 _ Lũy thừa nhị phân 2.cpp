#include<bits./stdc++.h>
using namespace std;
/*
Bài 16 _ Lũy thừa ma trận 2 : Cho ma trận kích thước nxn . nhiệm vụ của bạn là hãy tính ma trận đó mũ k lên và tính tổng
của cột cuối cùng. đáp số hãy in ra sau khi chia du cho 1e + 7
*/
long long mod = 1e9 + 7;
int n ;
 int k ;
struct Matrix{
    int F[10][10] ;
    friend Matrix operator * (const Matrix &A, const Matrix &B){
        Matrix c ;
        for ( int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n ; j++){
                c.F[i][j] = 0 ;
                for ( int m = 0 ; m < n ; m++){
                c.F[i][j] += A.F[i][m] * B.F[m][j];
                c.F[i][j] %= mod ;
            }
            }
        }
        return c ;
    }
};
Matrix powMod(Matrix a , int k){
    if ( k == 1){
        return a ;
    }
    Matrix x = powMod(a , k / 2) ;
    if ( k % 2 == 0 ){
        return x * x;
    }
     return x * x * a ; 
}
int main()
{
    cin >> n ; 
    cin >> k ;
    Matrix a ;
    for( int i = 0 ; i < n ; i++){
        for ( int j = 0 ; j < n ; j++){
            cin >> a.F[i][j] ;
         }
    }
    Matrix res = powMod(a,k) ;
    int sum = 0;
    for ( int i = 0 ; i < n ; i++ ){
        sum  += res.F[i][n - 1] ;
        sum %= mod ;
    }
    cout << sum ;
    return 0;
}
/*
2 2 
216 71
923 906

966031
*/