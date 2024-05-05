#include<bits/stdc++.h>
using namespace std;
/*Bài tính tổ hợp chập k của n phần tử :
Bài toán cơ sở : C(n,0) = 1 và C(n,n) = 1 ;
Công thức truy hồi : C(n,k) = C(n-1,k-1) + C(n-1,k) ;
Dựa vào công thức truy hồi mà hàm có thể đệ quy đến khi về bài toán cơ sở rồi mới lật ngược lại!
*/
int Combination(int n , int k){
    if (k == 0 || k == n){
        return 1 ;
    }
    else {
        return Combination(n - 1, k - 1) + Combination(n - 1, k);       
    }
}
int main()
{
    cout << "Please enter n and k : \n" ;
    int n ; int k ;
    cin >> n >> k;
    cout << "The combination is: "<<Combination(n,k)<<endl;
    return 0;
}
/*input :
12 2 
ouput :
66
*/