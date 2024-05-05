#include<bits/stdc++.h>
using namespace std;
/* Bài toán N quân hậu : Cho bàn cờ có kích thước n * n , Vấn đề đặt ra rằng có n quân hậu , bạn cần đếm xem số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kỳ thì chúng không ăn nhau!

ý tưởng cho bài toán : khi đặt một quân hậu thì ta mặc nhiên cái hàng đặt quân hậu đó ta sẽ không thể đặt thêm con hâu, cột cũng vậy và cả hai đường chéo vì sẽ bị ăn nên khi ta đặt một con hậu thì ta sẽ đánh dấu tất cả những ô thuộc hàng đó , cột đó , và 2 đường chéo xuôi và ngược là lãnh địa của con hậu đó để khi đặt con tiếp theo thì né nó ra

ta sẽ tạo ra biến x[i] để lưu cột j ở hàng i => x[i] = j là một vị trí
*/
int n , X[1001] , ans  = 0  ;
int cot[1001] , xuoi[1001] ,nguoc[1001]; // lần lượt lưu cột , đường chéo xuôi ,  ngược
void ql(int i){
    for ( int j = 1 ; j <= n ; j ++){
        if ( cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0 ){ // chỗ này phải hiểu rằng khi ta tăng đồng thời chỉ số cột và chỉ số hàng lên thì theo đường chéo xuôi khi tăng i thì chỉ số đường chéo tăng theo , nhưng khi tăng j thì chỉ số đường chéo giảm , và bằng một vài ví dụ ta tìm được công thức cho chỉ số của đưỡng chéo xuôi , ngược cũng tương tự! 
            X[i] = j  ;
            cot[j] = 1 ; xuoi[i - j + n] = 1 ; nguoc[i + j - 1] = 1 ;
            if ( i == n){
                ans++ ;
                for ( int row = 1 ; row <= n ; row ++){
                    for ( int col = 1 ; col <= n ; col ++){
                        if ( X[row] == col){
                            cout <<"#";
                        }
                        else cout << "." ;
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else {
                ql(i + 1);
            }
             cot[j] = 0 ; xuoi[i - j + n] = 0 ; nguoc[i + j - 1] = 0 ;
        }
    }
}
int main()
{
    cin >> n ;
    ql(1);
    cout << ans << endl;
    return 0 ;
}