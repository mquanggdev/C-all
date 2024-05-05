/* ĐỆ QUY */
#include<bits/stdc++.h>
using namespace std;
// Đệ quy hoạt động dựa trên nguyên tác LIFO : last in first out . phải có 2 yếu tô đó là điều kiện dừng và công thức truy hổi 
// ta phải tìm bài toán con nhỏ nhất rồi dựa vào công thức truy hồi để tìm ra từng bài toán lớn hơn.


int tong(int n) // tính tổng n số hạng từ 1 - > n
{
    if ( n == 1){
        return 1;
    }
    else return  n + tong(n - 1);
}
int luythua( int n){
    if ( n == 0 ){ // điều kiện dừng
        return 1;
    }
    else return n * luythua( n - 1 );
}
int fibo(int n) { // tìm số fibonaci thứ n 
    if ( n <= 1) return n;
    else return fibo(n - 1) + fibo(n - 2) ; // nên hạn chế sử dụng đệ quy để tính fibo
}
int nCk(int n , int k) { // tổ hợp chập k của n 
    if ( k == 0 || n == k ) return 1;
    else return nCk(n - 1, k - 1) + nCk(n - 1 , k) ; // đây là công thức tính tổ hợp chập k của n với n và k bất kì mà k thuộc trường hợp nhỏ nhất 
}
int gcd(int a , int b){
    if ( b == 0) return a;
    else return gcd(b , a % b );
}
int binarypow(int a , int b){// lũy thừa nhị phân 
    if ( b == 0 ) return 1;
    int x = binarypow(a,b/2); // trong trường hợp b mà khác 0 gán cho biến x = a^(b/2) để kiểm tra nếu b mà chẵn thì a^b sẽ = a^(b/2) * a^(b/2) hay bằng x * x còn nếu b mà lẻ nó sẽ tách 1 số a ra để cho b chẵn thì lúc tính ta phải nhân lại a trả nó
    if (b % 2 == 0) return x * x;
    else return a * x * x ;
}
int palin( int a[] , int l , int r) { // kiểm tra tính đối xứng của 1 mảng
    if ( l >= r ) return 1;
    if ( a[l] != a[r] ) return 0;
    else return palin(a,l+1,r);
}
int main()
{
    return 0;
}
