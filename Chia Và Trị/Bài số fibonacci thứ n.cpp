#include<bits/stdc++.h>
using namespace std;
/*Số Fibonaci thứ N : Bài này là bài điển hình về cách dùng để ra độ phức tạp nhỏ : áp dụng 2 kiến thức ma trận với lũy thừa nhị phân
Kỹ thuật nhân ma trận fibo : nếu ta lũy thừa ma trận  1 1 lên n lần thì sẽ ra được một ma trận fibo :  f(n + 1) f(n)
                                                      1 0                                              f(n)     f(n-1)
như vậy tìm số fibo thứ n chỉ cần nhân ma trân lên n lần 
Và để làm được điều này mà không bị độ phức tạp lớn nếu gặp trường hợp n lên 10^10 chẳng hạn
thì ta dùng lũy thừa nhị phân  
*/
long long mod = 100000007 ;
struct matran{
    long long a[2][2] ;
    friend matran operator * (matran x , matran y){
        matran kq ;
        for ( int i = 0 ; i < 2 ; i ++){
            for ( int j = 0 ; j < 2 ; j++){
                kq.a[i][j] = 0 ;
                for (int k = 0 ; k < 2 ; k ++){
                    kq.a[i][j] += (x.a[i][k] * y.a[k][j]) ;
                    kq.a[i][j] %= mod;
                }
            }
        }
        return kq ;
    }
};
matran binpow(matran x , long long n){
    if ( n == 1) return x ;
    matran X  = binpow(x , n / 2 ) ; // X^n = X^(n/2) * .....
    if ( n % 2 == 1){
        return X * X * x ;
    }
    else {
        return X * X ;
    }
}
int main(){
    matran x ;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[1][0] = 1;
    x.a[1][1] = 0;
    long long n ; cin >> n ;
    matran kq = binpow(x , n) ;
    cout << kq.a[0][1] << endl;

    return 0 ;
}