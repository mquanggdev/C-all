#include<bits/stdc++.h>
using namespace std;
/*
Bài 1 : Xâu con chung dài nhất : Cho 2 xâu S và T , Hãy tìm xâu con chung dài nhất của S và T . Các ký tự không nhất thiết phải liền kề nhau . 

ý tưởng : Ta cũng sẽ dùng một mảng đánh dấu F[i][j] để lưu lại đồ dài của xâu chung dài nhất khi so sánh i ký tự đầu của dãy S và j ký tự đầu của dãy T. 

Khi mà xét đến một ký tự mới thì ra cần xem xét : nếu 2 ký tự khác nhau thì cập nhật độ dài lớn nhất của 1 trong 2 xâu đã so sánh trước đó , còn nếu giống nhau thì phải lấy độ dài của xâu mà 2 phần tử trước đó đã so sánh : Ví dụ như sau
a b z u v t
a d x u z v

so i = 1, j = 1 thấy a = a -> F[1][1] = F[0][0] + 1  = 1 -> đã có độ dài max
i = 1  , j = 2 thấy a != d -> F[1][2] = max ( F[0][2] , F[1][1]) = 1 ,
..
i = 3  ,j = 5 thấy z = z -> F[3][5] = F[2][4] + 1 = 2 -> cập nhật lại :  bởi vì nếu i - 1 và j -1 ký tự trước đã tìm ra được max độ dài thì thêm 2 thằng z này vô thì độ dài nó mới tăng lên 
i =3  , j = 6 thấy Z != v -> F[3][6] = max (F[2][6] , F[3][5]) = 2 , bời vì do 2 kỹ tự tiếp theo khác nhau nên phải so i - 1 ký tự dãy S vớ j ký tự dãy T hoặc ngược lại thì nó mới ra đúng , vì lúc này F[2][6] nó chỉ tìm thấy mỗi a là xâu dài nhất , nhưng F[3][5] nó lại tìm thấy xâu  a,z mới là dài nhất thì ta phải cập nhật cái nào lớn hơn 
*/
string S , T ;
int F[1001][1001] ; // lưu độ dài xâu dài nhất khi so i ký tự với j ký tự đầu tiên -> F[n][m] là đáp án
int main()
{
    cin >> S >> T ;
    S = "0" + S ;
    T = "0" + T ;
    // khởi tạo : tức là ta chọn một phần tử bất kỳ trên dãy S và không chọn trên dãy T và ngược lại thì độ dài xâu dài nhất ta có thể tìm thấy ở đây chỉ bằng 0;
    for ( int i = 0 ; i <= T.size() ; i++){
        F[0][i] = 0 ;
    }
    for ( int i = 0 ; i <= S.size() ; i++){
        F[i][0] = 0 ;
    }
    for ( int i = 1 ; i < S.size() ; i++){
        for ( int j = 1; j < T.size() ; j++){
            if ( S[i] == T[j]){
                F[i][j]  = F[i - 1][j - 1] + 1 ; // nếu so sánh i - 1 ký tự và j - 1 ký tự trước đó đã tìm được độ dài lớn nhất thì khi thêm thằng i và j tiếp theo thì độ dài max sẽ tăng lên 1
            }
            else {
                F[i][j] = max ( F[i - 1][j] , F[i][j - 1] ) ; // bởi vì nếu khác nhau thì ta phải so sánh về đằng trước , nếu đằng trước của 1 trong hai dãy đã tồn tại độ dài max thì phải lấy cái độ dài đấy
            }
        }
    }
    cout << F[S.size()-1][T.size() -1 ] ;
    return 0;
}
/*
ZHFTDFHF
TFISHROV
3
*/