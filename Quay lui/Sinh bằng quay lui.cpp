#include<bits/stdc++.h>
using namespace std;
/*Quay lui : là phương pháp dùng đệ quy để giải quyết bài toán , ví dụ đối với bài toán sinh xâu nhị phân : nó phải dựa vào cấu hình đằng trước để sinh ra cấu hình đằng sau , nhưng với quay lui nó sẽ dùng phép gán tuần tự từ 1 -> n và khi chạm đến n là lúc mà tất cả cấu hình được hình thành -> nó sẽ nhanh hơn thuật toán siinh một chút */
 int n ;
 int X[101] ;
void QL(int i){
    for ( int j = 0 ; j <= 1 ; j++){
        X[i] = j ; // gán số 0 hoặc 1 cho X[1] ; mỗi một X[i] đại diện cho 1 vị trí bit trong cấu hình và nó được nhận 2 giá trị 0 và 1 nên nếu n = 4 thì khi nào nó xây dựng và gán cho X[4] được 1 trong 2 giá trị 0 và 1 thì nó sẽ kết thúc và từ X[4] nó sẽ xây dựng được cấu hình ngược lại
        if ( i == n){ // nếu cấu hình được hoàn thiện
        for ( int k = 1 ; k <= n ; k ++ ){
            cout << X[k] ; // xây dựng lên cấu hình
        }
        cout << endl;
    }
    else QL(i+1) ; 
   }
}
/*Tiếp tục với bài toán Sinh Tổ hợp chập k của n phần tử :
Có hai thứ ta cần xác định : giá trị nhỏ nhất và giá trị lớn nhất mà phần tử có thể nhận được
giá trị lớn nhất của một phần tử có thể nhận là : n - k + i : theo công thức tính ví dụ n = 5 k = 3 thì giá trị lớn nhất mà phần tử nằm ở vị trí i = 3 đó chính là 5 : ví dụ 1 2 5 
giá trị nhỏ nhất mà một phần tử có thể nhận là : X[i - 1] + 1 do tổ hợp là tăng dần vd 1 2 5 thì giá trị nhỏ nhất ở vị trí 2 đó chính là 2 do =  1 + 1
*/
int m , k , T[1001] ;
void QLTH(int i){
    for ( int j = T[i - 1] + 1 ; j <= m - k + i ; j++){ //  vd n = 5 , k = 3 :gía trị mà T[1] có thể nhận : 1 -> 3 , T[2]: 2 -> 4 , T[3] = 3 -> 5 
        T[i] = j ;
       if (i == k ){ // nếu mà đã xây dựng chạm đến phần tử cuối cùng trong 1 cấu hình
        for ( int t = 1 ; t <= k ; t++){
            cout << T[t] << " " ; // in ngược lại
        }
        cout << endl;
       }
       else {
        QLTH(i+1);
        }
    }
}
/* Tiếp tục với SInh Hoán Vị
*/
int h , M[1001] , used[1001] ; // cần tạo thêm mảng used bởi vì trong hoán vị ví dụ 12345 thì nếu ta chọn X[i] = 1 thì những x khác không được chứa 1 nữa
void QLHoanVI(int i){
    for (int j = 1; j <= h ; j++ ){
        if (used[j] == 0){
            M[i] = j ;
            used[j] = 1 ;
            if ( i == h){
                for ( int j = 1 ; j <= h ; j++ ){
                    cout << M[j]  ;
                }
                cout << endl ;
            }
            else QLHoanVI(i + 1);
            used[j] = 0 ; // phải trả lại 0 cho thằng j bởi vì khi nó quay lui lại nó cần rẽ sang nhánh khác , chỗ này vô cùng quan trọng , là bước mấu chốt quay lui trong bài này
        }
    }
}
int main(){
    cin >> h ;
    QLHoanVI(1) ;
    return 0;
}
/*
4
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111


TỔ hợp:
5 3
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5


hoanvi
3
123
132
213
231
312
321
*/