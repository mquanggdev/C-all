#include<bits/stdc++.h>
using namespace std;
/* Bài toán Người Du Lịch : Cho ma trận nXn mô tả đường đi giữa i và j thành phố và khoảng cách của chúng , tìm đường đi ngắn nhất để đi từ thành phố 1 rồi quay lại thành phố 1
*/
int n , a[1001][1001];
int visited[1001];
int X[1001];
int res = INT_MAX;
int amin = INT_MAX;
int sum = 0;
void init(){
    cin >> n ;
    for ( int i = 1 ; i <= n ; i ++ ){
        for ( int j = 1 ; j <= n ; j++){
            cin >> a[i][j] ;
            if(a[i][j] != 0) amin = min(amin,a[i][j]);
        }
    }
}
void ql(int i){
    for ( int j = 1 ; j <= n ; j++){
        if (visited[j] == 0){
            X[i] = j ; // lưu vị trí của đường đi , tức thành phố ở lượt thứ i đi qua sẽ có vị trí là j
            visited[j] = 1 ;
              sum += a[X[i-1]][X[i]];
            if ( i == n){
                res = min(sum + a[X[i]][1] ,res);
            }
            else if(sum + (n - i + 1)*amin < res){ // nhánh cận chỗ này là nó kiếm tra mà nếu mà sum + (n - 1 + 1) quãng đường còn lại * khoảng cách tối thiểu giữa hai quãng đường có thể có mà nhỏ hơn res thì nó mới quay lui.
                ql(i + 1);
            }
            sum -= a[X[i-1]][X[i]];
            visited[j] = 0;
        }
    }
}

int main()
{
    init();
    X[1] = 1 ; visited[1] = 1;
    ql(2);
    cout << res << endl;
    return 0 ;
}
/*
4
0 85 26 81
85 0 77 97
26 77 0 26
81 97 26 0
234
*/