#include<bits/stdc++.h>
using namespace std;
/*
Thuật toán Sinh : Sinh Nhị Phân : Bản chất của thuật toán này là ta coi việc khi xuất hiện mỗi tổ hợp vơi O lần ẩn và với 1 là hiện . Từ đó ta có thể làm nhiều bài toán khác nhau !

ý tưởng : với xâu nhị phân có độ dài n , thì ta sẽ duyệt từ cuối lại với chỉ số i = n , nếu cứ gặp thằng 1 thì ta chuyển thành 0 và giảm i đi , còn nếu gặp số 0 thì biến thành 1 và kết thúc vòng lặp , đến khi cả mảng chỉ chứa 1 thì kết thúc ! 

*/
int  a[101] , n , ok;
void init(){
    for ( int i = 1 ; i <= n ; i++){
        a[i] = 0;
    }
}
void BinaryGen(){
    int i = n ;
    // vòng while này có nhiệm vụ là sẽ khi mà gặp số 1 là nó sẽ chuyển thành số 0 (chẳng hạn số là 0111 , vào lần đầu kiểm tra thấy i = 4 và a[4] = 1 nên nó sẽ chuyển hết các số 1 thành 0 và đi xuống dưới , còn nếu số là 1110 thì nó sẽ k rơi vào vòng lặp này)
    while ( i >= 1 && a[i] == 1){
        a[i] = 0;
        --i ;
    }
    // cái này thì ngược lại với cái trên
    if (i == 0){ ok = 0; } // nếu ok = 0 tức là đã kết thúc hết quá trình sinh
    else {
        a[i] = 1 ;
    }
}
int main()
{
    cin >> n ;
    init() ;
    ok = 1 ;
    while (ok){
        for ( int j = 1 ; j <= n ; j ++){
            cout << a[j] ;
        }
        cout << endl;
        BinaryGen() ;
    }
    return 0;

}