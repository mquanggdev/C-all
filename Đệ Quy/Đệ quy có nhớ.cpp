#include<bits/stdc++.h>
using namespace std;
/*Đệ quy có nhớ : Đơn giản là ta sẽ dùng biến để lưu lại thông tin về đáp án của những bài toán con ngay trong lần giải đầu tiên , rồi dựa vào đó mỗi lần ta cần ta chỉ cần lấy ra chứ không phải đệ quy lại từ đầu nữa 
ưu điểm của thuật toán này là nó sẽ nhanh hơn so với đệ quy thông thường
*/
/*
Dưới đây là ví dụ để tính số fibonacci thứ n 
*/
long long fibo[1001] ;
long long fib(int n) {
    if (!fibo[n]) { // tức là nếu chưa từng tồn tại số fibo n trước đó thì ta sẽ tính nó bằng cách tính cái số fibo trước nó
        fibo[n] = fib(n - 1) + fib(n - 2); // hai số này là hai số liên trước nó!
 }
      return fibo[n] ;
}
int main()
{
    int n ; cin >> n ;
    fibo[1] = 1;
    fibo[2] = 1;
    cout << fib(n) ;
    return 0;
}
/*
12
144
*/