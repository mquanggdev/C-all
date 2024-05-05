#include<bits/stdc++.h>
using namespace std;
/* Biểu thức lớn nhất : cho dãy a liên tiếp có n phần tử => có n - 1 khoảng trắng , cho k dấu + và n - 1 - k dấu trừ , nhiệm vụ của bạn là đặt các dấu vào chỗ trắng sao cho khi đặt thì ta nhận về được một biểu thức có giá trị lớn nhất 
*/
int main()
{
    int n, k ;
    cin >> n >> k ;
    long long a[n] ;
    for ( int i = 0 ; i < n ; i++){
         cin >> a[i] ;
    }
    sort(a + 1,a + n, greater<int>()); // bởi vì mặc định số đầu tiên luôn mang dấu cộng nên ta chỉ được phép sort từ i + 1 ;
    long long ans = a[0] ;
    for (int i = 1 ; i < n ; i ++){
        if ( i <= k) ans += a[i];
        else ans -= a[i] ;
    }
    cout << ans << endl ;
    return 0;
}
/*
6 3
9560 5571 9008 3649 1473 3782
22799
*/