#include<bits/stdc++.h>
using namespace std;
/*
Bài 28 _ Select Array : cho một mảng có n số nguyên chỉ bao gồm các số từ 1 dến m và độ lệch giữa hai phần tử liền kề không được vượt quá 1 đơn vị. Bài toán đặt ra đó là cho bạn một mảng trong đó một số giá trị trong mảng chưa được xác định giá trị , nhiệm vụ của bạn là đếm số mảng phù hợp với mô tả . Nếu có số 0 thì số 0 đó có thể thay thế bất kỳ giá trị nào trong mảng từ 1 -> m ;


tư tưởng bài này : đầu tiên chọn ra một mảng để lưu số cạch chọn ở một vị trí i tương ứng với các số từ 1 -> m ;
thì khi chọn một vị trí , ví dụ  với m = 3 => chỉ chọn từ 1-> 3 vị trí 1 : 
+ nếu a[1] là số cố định thì vị trí 1 sẽ chỉ chọn được số a[1] -> đánh dấu chỉ có 1 cách chọn cho vị trí số 1 
+ nếu a[1] = 0 thì sẽ có những cách chọn như F[1][1] , F[1][2] , F[1][3] -> đánh dấu lại tất cả đều bằng 1 vì tại vị trí 1 thì cũng chỉ chọn được 1 cách tương ứng với các giá trị 1 2 3 ;
tiếp theo vị trí 2:
+ nếu a[2] là một số cố định thì chẳng hạn như số 3 thì giá trị ta chỉ có thể chọn bằng 3 : vậy cái ta cần tìm là với giá trị bằng 3 thì sẽ có bao nhiêu cách để đặt được thằng 3 vào vị trí 2 :=> F[3][3] = F[2][3] + F[2][2] -> bởi vì chỉ nếu vị trí số 2 là số 3 thì các giá trị mà ô phía trước có thể nhận cũng chỉ là 2 và 3 để hiệu không vượt quá 1 :
+ nếu a[2] = 0 ; thì nó cũng sẽ xét các giá trị từ 1 cho đến 3 để xem với từng giá trị thì sẽ có bao nhiêu cách chọn để đặt giá trị đó vào đúng vị trí thứ 2 ; giả dụ đến giá trị = 1 thì F[2][1] = F[1][1] + F[1][2] là hết 

bằng cách đó thì tại mỗi vị trí ta sẽ có 2 nhận xét -> ở vị trí đó là số cố định hay số 0 và xét xem số cách để đặt được 1 giá trị từ 1 -> m vào vị trí đó 
lưu ý ở vị trí cuối cùng : Nếu vị trí cuối cùng là một số cố định thì đáp án sẽ là F[n][a[n]] , nếu là số vô định thì đáp án sẽ là F[n][a[j]] với j chạy từ 1 -> m  ; -> để tổng quát thì ta cứ làm một vòng for(j) để tính tổng các F[n][a[j]] bởi vì nếu vị trí cuối là cố định thì chỉ có vị trí có 1 cách chọn còn lại bằng 0 nên cộng vào đáp án không thay đổi
*/
int n , m  ;
int F[1001][1001] ; // mảng lưu số cách chọn ở vị trí i các phần tử từ 1 -> m ;
int a[1001] ;
int main(){
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
    }
    if (a[1] != 0){
        F[1][a[1]] = 1 ;
    }
    else {
        for ( int i = 1; i <= m ; i++) F[1][i] = 1 ;
    }
    for ( int i = 2 ; i <= n ;i++ ){
            if ( a[i] == 0){
                for ( int j = 1 ; j <= m ; j++ ){
                    F[i][j] = F[i - 1][j - 1] + F[i - 1][j] + F[i - 1][j + 1] ;
                }
            }
            else {
                F[i][a[i]] = F[i - 1][a[i] - 1] + F[i - 1][a[i]] + F[i - 1][a[i] + 1] ;
            }
    }
    int res = 0 ;
    for ( int j = 1 ; j <= m ; j++) {
        res += F[n][j] ;
    }
    cout << res ;
    return 0;
}
/*
3 5
2 0 2
3
*/