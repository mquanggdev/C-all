#include<bits/stdc++.h>
/*
Bài 9 : Máy ATM : một máy ATM hiện có n tờ tiền có giá trị t1 ,.. tn . Hãy tìm cách trả ít tờ tiền nhất với số tiền đúng bằng S (các tờ tiền có giá trị bất kỳ và có thể trùng nhau , mỗi tờ tiền chỉ được dùng một lần )
-> không lặp lại bất kỳ cấu hình nào
ý tưởng : ở đây thì ta vẫn làm theo cách vị trí : tức là đếm tiến theo vị trí :
*/
using namespace std;
int n , s  , a[105] , cnt = 0 , x[105] ;
int res = 1e9;
void Dem(int i ,int start ,int sum){
    for ( int j = start ; j <= n ; j++){ // j này vẫn sẽ lưu vị trí của các phần tử nằm trong dãy 
        if ( sum + a[j] <= s){
            x[i] = j ; // gán vị trí của phần tử đấy cho x[i]
             cout << "sum = " << sum + a[j] << ", i = " << i << ", res = " << res << ", x[" << i << "] = " << x[i] << endl;
            if(sum + a[j] == s){
                res = min(res,i) ;
            }
            else {
                Dem(i + 1, start + 1 , sum + a[j]) ;
            }
        }
    }
}
int main()
{
    cin >> n >> s ;
    for ( int i = 1 ; i <= n ; i++ ){
        cin >> a[i] ;
    }
    sort(a + 1 , a +  n + 1 , greater<int>()) ;
    Dem(1,1,0) ;
    cout << res ;
    return 0 ;
}
/*
6 30
10 4 10 5 8 8
4
// đây là mô tả mỗi lần đệ quy
sum = 10, i = 1, res = 1000000000, x[1] = 1
sum = 20, i = 2, res = 1000000000, x[2] = 2
sum = 28, i = 3, res = 1000000000, x[3] = 3
sum = 28, i = 3, res = 1000000000, x[3] = 4
sum = 25, i = 3, res = 1000000000, x[3] = 5
sum = 29, i = 4, res = 1000000000, x[4] = 6
sum = 24, i = 3, res = 1000000000, x[3] = 6
sum = 18, i = 2, res = 1000000000, x[2] = 3
sum = 26, i = 3, res = 1000000000, x[3] = 4
sum = 30, i = 4, res = 1000000000, x[4] = 6
sum = 23, i = 3, res = 4, x[3] = 5
sum = 27, i = 4, res = 4, x[4] = 6
sum = 22, i = 3, res = 4, x[3] = 6
sum = 18, i = 2, res = 4, x[2] = 4
sum = 23, i = 3, res = 4, x[3] = 5
sum = 27, i = 4, res = 4, x[4] = 6
sum = 22, i = 3, res = 4, x[3] = 6
sum = 15, i = 2, res = 4, x[2] = 5
sum = 19, i = 3, res = 4, x[3] = 6
sum = 14, i = 2, res = 4, x[2] = 6
sum = 10, i = 1, res = 4, x[1] = 2
sum = 18, i = 2, res = 4, x[2] = 3
sum = 26, i = 3, res = 4, x[3] = 4
sum = 30, i = 4, res = 4, x[4] = 6
sum = 23, i = 3, res = 4, x[3] = 5
sum = 27, i = 4, res = 4, x[4] = 6
sum = 22, i = 3, res = 4, x[3] = 6
sum = 18, i = 2, res = 4, x[2] = 4
sum = 23, i = 3, res = 4, x[3] = 5
sum = 27, i = 4, res = 4, x[4] = 6
sum = 22, i = 3, res = 4, x[3] = 6
sum = 15, i = 2, res = 4, x[2] = 5
sum = 19, i = 3, res = 4, x[3] = 6
sum = 14, i = 2, res = 4, x[2] = 6
sum = 8, i = 1, res = 4, x[1] = 3
sum = 16, i = 2, res = 4, x[2] = 4
sum = 21, i = 3, res = 4, x[3] = 5
sum = 25, i = 4, res = 4, x[4] = 6
sum = 20, i = 3, res = 4, x[3] = 6
sum = 13, i = 2, res = 4, x[2] = 5
sum = 17, i = 3, res = 4, x[3] = 6
sum = 12, i = 2, res = 4, x[2] = 6
sum = 8, i = 1, res = 4, x[1] = 4
sum = 13, i = 2, res = 4, x[2] = 5
sum = 17, i = 3, res = 4, x[3] = 6
sum = 12, i = 2, res = 4, x[2] = 6
sum = 5, i = 1, res = 4, x[1] = 5
sum = 9, i = 2, res = 4, x[2] = 6
sum = 4, i = 1, res = 4, x[1] = 6
Result: 4
*/