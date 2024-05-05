#include<bits/stdc++.h>
using namespace std;
/*
Bài 4 : Dãy con có tổng bằng S : CHo mảng A gồm n phần tử , và số nguyên dương S , Nhiệm vụ của bạn là xác định xem có thể tạo một tập con các phần tử trong mảng có tổng bằng S hay không ? Mỗi phần tử chỉ được dùng 1 lần!
 1 <= N <= 200 ; 1 <= S <= 50000 ; 1 <= A[i] <= 500 ;
*/
/*
Tư tưởng bài toán : Do dãy có thể lên đến 200 phần tử nên ta phải dùng quy hoạch động để tối ưu bài toán
Để tìm ra được có tổng bằng Thằng S hay không thì ta cần duyệt từ 0 -> S: và phải duyệt ngược lại
do nếu mà F[B - a[i]]  = 1 tức là có tồn tại 1 thằng nào đó trong dãy A mà khi cộng thêm A[i] thì nó tạo ra B thì ta đánh dấu F[B] = 1 để biểu thị rằng ta đã có một cái dãy con có tổng bằng B rồi

vì vậy bài toán con nhỏ nhất là F[0] = 1 do có tồn tại dãy con rỗng có tổng bằng 0
ví dụ với bài toán nhỏ sau đây : n = 4 , A[] = 1 3 7 5 , S = 12
i : đại diện cho các số từ 0 -> S = 12 ;
F : đại diện cho mảng đánh dấu

i = 0 1 2 3 4 5 6 7 8 9 10 11 12
F = 1 0 0 0 0 0 0 0 0 0 0 0 0 0

Ban đầu ta sẽ có mảng như trên :
duyệt từ cuối lại thấy F[12 - a[1] = 1] = F[11] = 0 -> không có tổng nào trước đó cộng vào bằng 11 để khi cộng với 1 = 12 ;
duyệt liên tục tới khi F[1 - a[1]] = F[0] = 1 -> có 1 cái dãy con có tổng bằng 1 -> đó là 1 mính số 1 -> đánh dấu lại F[1] = 1 ;
 khi đó dãy sẽ là

i = 0 1 2 3 4 5 6 7 8 9 10 11 12
F = 1 1 0 0 0 0 0 0 0 0 0 0 0 0

tiếp theo duyệt đến a[2] = 3 , và cũng duyệt i từ cuối lại.

F[12 - a[2]] = F[9] = 0 -> không tồn tại tổng nào trước đó có tổng bằng 9
..
F[4 - a[2]] = F[1] = 1 -> vậy là có tổng 1 trước đó và lúc này nếu nó cộng với a[2] thì sẽ = 4 -> đó là dãy 1 3 -> đánh dấu F[4] = 1 , Nhận thấy cũng có F[3 - a[2]] = F[0] = 1 , cũng có dãy có tổng bằng 3 đó là riêng số 3 : vì vậy cũng đánh dấu F[3] = 1 ;

=> lúc này dãy là  : 
i = 0 1 2 3 4 5 6 7 8 9 10 11 12
F = 1 1 0 1 1 0 0 0 0 0 0 0 0 0
cứ như thế đến khi duyệt hết dãy A ta sẽ tìm ra có dãy nào có tổng bằng S hay không
*/
int F[1001] = {0} ;
int S ;
void qhd(int a[],int n){
    for ( int j = 0 ; j < n ; j++){
        for ( int i = S ; i >= 0 ; i--){
            if ( F[i - a[j]] == 1){
             F[i] = 1 ;
        }
    }
    }
   
}
int main()
{
    int n ; cin >> n ;
     cin >> S ;
    int a[n] ;
    for ( auto &x : a) cin >> x ;
    F[0] = 1 ;
    qhd(a,n) ;
    if(F[S] == 1) cout << "1" << endl ; 
    else cout << "0" ;
    return 0;
}
/*
8 92
69 16 82 170 31 24 45 112
1
*/