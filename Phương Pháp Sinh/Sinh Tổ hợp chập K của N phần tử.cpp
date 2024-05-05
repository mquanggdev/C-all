#include<bits/stdc++.h>
using namespace std;
/*Sinh tổ hợp : Liệt kê tất cả các tổ hợp chập k của n ;
*/
int n , a[1001] , ok  , k;
void init(){
    for ( int i = 1 ; i <= k ; i++){
        a[i] = i  ;
    }
}
void CombinationGen() {
    int i = k ;
    while ( a[i] == n - k + i && i >= 0){ // nếu mà số ở vị trí i đã đạt được giá trị max thì giảm vị trí đi
        --i ;
    }
    if ( i == 0){
        ok = 0 ;
    }
    else {
        a[i]++ ; // tăng giá trị của phần tử tại vị trí chưa đạt max lên 
        for ( int j = i + 1 ; j <= k ; j++){ // cái này sinh ra bởi nếu ví dụ số ở vị trí 2 trong tổ hợp chập 3 chưa max thì khi sinh đến tổ hợp của vị trí đó thì phần tử sau nó ở vị trí 3 cũng sẽ chưa max và ta phải tăng nó lên
            a[j] = a[j-1] + 1;
        }
    }
}
int main()
{
    cin >> n ;
    cin >> k;
    init() ;
    ok = 1 ;
    while(ok){
        for ( int i = 1 ; i <= k ; i++){
            cout << a[i] << " " ;
        }
        cout << endl;
        CombinationGen() ;
    }
    return 0;
}