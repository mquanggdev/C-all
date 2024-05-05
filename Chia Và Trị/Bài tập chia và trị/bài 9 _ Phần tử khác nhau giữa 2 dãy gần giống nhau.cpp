#include<bits./stdc++.h>
using namespace std;
/*
Bài 9 : Phần tử khác nhau : cho hai dãy tăng dần a và b gần giống nhau chỉ khác một vị trí , hãy tìm vị trí của phần tử đó ( độ phức tạp ologn )
ý tưởng : do là hai dãy tăng dần nên ta có thể sử dụng tìm kiếm nhị phân để giải quyết.
so sánh phần tử ở giữa nếu cứ khác nhau sẽ return luôn vị trí đó , còn không thì sẽ tìm về vế trước , bởi vì phía trước được sắp xếp tăng dần gần giống nhau.
*/
int solve(int sumA[] , int sumB[] , int l , int r ){
    if ( l > r ) return -1;
    int mid = ( l + r ) / 2 ;
    if ( sumA[mid] != sumB[mid]){
        int t = solve(sumA,sumB,l, mid - 1) ;
        if(t != -1) return t ;
        return mid ;
    }
    return solve(sumA , sumB , mid + 1 , r) ; 
}

int main()
{
   int n ; cin >> n ;
   int a[n + 1] , b[n] ;
   int sumA[n+1] = {0};
   int sumB[n] = {0};
   for ( int i = 1 ; i <= n ; i++){
    cin >> a[i] ;
    sumA[i] += a[i]  + sumA[i - 1];
   }
   for ( int i = 1 ; i <= n - 1 ; i++ ){
    cin >> b[i] ;
    sumB[i] += b[i] + sumB[i - 1];  
   }
//    for(auto x : sumA) cout << x << " ";
//    cout << endl;
//    for(auto x : sumB)  cout << x << " ";
//     return 0;
   int res = solve(sumA,sumB , 1 , n);
   if (res == -1) cout <<  n << endl;
   else cout << res << endl;
}
/*

*/