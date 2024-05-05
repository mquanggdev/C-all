#include<bits/stdc++.h>
using namespace std;
/*
Bài 17 : Parentheses : Bạn hãy sinh ra các cặp biểu thức dấu ngoặc hợp lệ từ các cặp dấu ngoặc "()" , "[]" , "{}" có độ dài N . Kết quả được in theo thứ tự tăng dần , nếu không tồn tại in ra biểu thức not found
*/
// option = 1 : chưa đúng , option = 2 : hoàn toàn đúng
// tức là thằng điều kiện option nó chỉ kiểm tra xem câu hình đúng hay chưa , nếu sai thì nó đã return ngay ở trên , còn chưa đúng thì nó vẫn ql tiếp , và khi i = n - 1 thì nó sẽ cho option lên 2 , tức là lúc này bắt buộc là phải đúng rồi , nếu sai nó cũng sẽ return bên trên , nếu không có dòng này thì ngay từ đầu ví dụ n = 4 và đến (() thì nó đã tính là sai rồi , chứ chưa phải chưa đúng
int n ;
char x[1001];
int check(char a[] , int i , int option){
    cout <<"i: " <<  i << " " <<"option: "<< option << " " << endl ;
    stack<char> st ;
    for ( int j = 0  ; j <= i ; j++ ){
        if (a[j] == '(' || a[j] =='[' || a[j] == '{' ) {
            st.push(a[j]);
        }
        else{
            if(st.empty()) return 0;
                
                char x = st.top();
                if ( (a[j] == ')' && x == '(') || (a[j] == ']' && x == '[') || (a[j] == '}' && x == '{') ){
                    st.pop();
                }
                else {
                    return 0;
                }
        }

    }
    if(option == 1) return 1 ;
    return st.empty();
}
void in(){
    for ( int i = 0 ; i < n ; i++ ){
        cout << x[i] ;
    }
    cout << " ";
}
void ql(int i){
    in();
    if ( i == n ){
        if ( check(x , n - 1, 2) ){
            in();
        }
        return ;
    }
    string list = "()[]{}";
    for ( char c : list){
        x[i] = c ;
        if ( check(x,i,1)){
        ql(i + 1) ;
    }
 }
    
}
int main()
{ 
    cin >> n ;
    if ( n % 2 == 1){
        cout << "Not Found!" ;
    }
    else ql(0) ;
    return 0 ;
}
/*
4
(()) ()() ()[] (){} ([]) ({}) [()] [[]] []() [][] []{} [{}] {()} {[]} {{}} {}() {}[] {}{}
*/
/*2
() [] {}
 i: 0 option: 1
( i: 1 option: 1
(( i: 1 option: 2
i: 1 option: 1
() i: 1 option: 2
() i: 1 option: 1
([ i: 1 option: 2
i: 1 option: 1
i: 1 option: 1
({ i: 1 option: 2
i: 1 option: 1
i: 0 option: 1
i: 0 option: 1
[} i: 1 option: 1
[( i: 1 option: 2 
i: 1 option: 1
i: 1 option: 1
[[ i: 1 option: 2
i: 1 option: 1
[] i: 1 option: 2
[] i: 1 option: 1
[{ i: 1 option: 2
i: 1 option: 1
i: 0 option: 1
i: 0 option: 1
{} i: 1 option: 1
{( i: 1 option: 2
i: 1 option: 1
i: 1 option: 1
{[ i: 1 option: 2
i: 1 option: 1 
i: 1 option: 1
{{ i: 1 option: 2
i: 1 option: 1
{} i: 1 option: 2
{} i: 0 option: 1
*/