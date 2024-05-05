#include<bits/stdc++.h>
using namespace std;
/* Bài Xâu Fibo : Cho 2 ký tự A và B hãy tìm ký tự thứ K của Xâu fibo thứ N : Biết Xâu fibo được sinh ra như sau :
F[n] = F[n-2] + F[n -1];
*/
long long F[1001];
char Find(int n , int k){
    if (n == 1) return 'A' ;
    if ( n == 2 ) return 'B';
    if (k <= F[n - 2]){
        return Find(n - 2 , k); // thực tế do là ký tự nên độ dài của chuỗi tiếp theo bằng chính độ dài của hai chuỗi đằng trước cộng lại nên cái vị trí K của ta cần tìm nó sẽ nằm 1 trong 2 mảng F[n -2] hoặc  F[n -1 ] trước đó , nên ta chỉ cần chia làm 2 mảng ra đến trường hợp nhỏ nhất thì sẽ tìm ra được
    }
    else {
        return Find(n - 1, k - F[n - 2]); // lưu ý rằng xâu F[n - 1] sẽ được ghép và sau F[n -2] nên nếu K thuộc mảng F[n - 1] thì ta phải lấy K trừ đi đọ dài chuỗi F[n - 2] thì sẽ ra vị trí có kỹ tự trùng với ký tự ở vị trí K
    }
}
int main()
{
    F[0] = 0 ;
    F[1] = 1 ;
    for( int j = 2 ; j <= 92 ; j ++){
        F[j] = F[j - 2] + F[j - 1];
    }
    long long n , k ; cin >> n >> k ;
    cout << Find(n , k) << endl;
    return 0 ;
}
/*
9 4 
A
*/