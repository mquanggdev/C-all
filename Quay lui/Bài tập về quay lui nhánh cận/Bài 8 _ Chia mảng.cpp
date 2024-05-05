#include<bits/stdc++.h>
using namespace std;
/* Bài 8 : Chia mảng : cho mảng các số nguyên A gồm n phần tử . Hãy chia mảng số nguyên A thành K tập con khác rỗng sao cho tổng các phần tử của mỗi tập con đều bằng nhau . Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong tất cả tập con . 
vd : a = 2 1 4 5 6 , K = 3 ->> {2,4} , {1,5} , {6} : ta nhận thấy trong 1 tập con thì vẫn có thứ tự đếm tiến nên ta vẫn dùng theo cách cũ được , tuy nhiên phải lưu ý chỗ điều kiện để in ra .
*/
int n , a[1001] ,  k , x[50] , ok = 0 , s;
bool used[50] ;

void ql(int i , int bd , int sum , int cnt) {
     if(cnt == k){
        ok = 1 ;
        return ;
         } 
    for ( int j = bd ; j <= n ; j++){
        if ( !used[j] && sum + a[j] <= s ){
            x[i] = j ; 
            used[j] = true ; 
            if (sum + a[j] == s){
                ql(i + 1, 1 , 0 , cnt + 1) ; // chỗ này phải cho biến bd về 1 bởi vì khi mà hoàn thành xong cấu hình thứ 1 chẳng hạn thì ta phải quay lại từ đầu thì mới bắt tiếp được phần tử cho tập thứ 2
            }
            else ql(i + 1, j + 1, sum + a[j] , cnt) ;
            used[j] = false ;
        }
    }
}

int main()
{
      cin >> n  >> k;
    for ( int i = 1 ; i <= n ; i++ ){
        cin >> a[i] ;
        s += a[i] ;
    }
    if ( s % k != 0) cout << 0 ;
    else{
         s = s / k ;
         ql(1,1,0,0);
         cout << ok ;
    }
    return 0 ;
}
/*
5 3 
2 1 4 5 6
*/