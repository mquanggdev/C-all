#include<bits/stdc++.h>
using namespace std;
/*Bài 1 : Số Fibonacci : Tìm số fibo thứ x :
Dãy fibonacci là dãy như sau : 1 , 1 , 2 , 3 , 5 ,8 ,13 , 21 , ......   */
int Fibonacci(int n){
    if (n == 0 || n == 1){
        return n ;
    }
    else return Fibonacci(n - 1) + Fibonacci(n - 2); // Công thức truy hồi của dãy 
}
int main(){
    int x ; cin >> x ;
    cout << "Fibonacci number at position "<<x<<" is: " ;
    cout << Fibonacci(x) ;
    return 0;
}