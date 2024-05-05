#include<bits/stdc++.h>
using namespace std;
/*
Bài 16 : Điện thoại cục gạch : cho xâu s gồm các phím trên điện thoại , mỗi phím chỉ được ấn một lần , hãy in ra tất cả các xâu có thể tạo thành bằng cách ấn những chữ số đó : vd : 23 -> ad , ae , af , bd ,be,bf , cd , ce , cf .
*/
string s ;
char x[100]; // lưu các kí tự
string solve(int i){
    if ( i == 2) return "abc";
    if ( i == 3) return "def";
    if ( i == 4) return "ghi";
    if ( i == 5) return "jkl";
    if ( i == 6) return "mno";
    if ( i == 7) return "pqrs";
    if ( i == 8) return "tuv";
    return "wxyz";

}
void in(int i){
    for ( int u = 0 ; u <= i ; u++){
        cout << x[u] ;
    }
    cout << " " ;
}
void ql(int i){
    string res = solve(s[i] - '0');
    for ( char it : res) {
        x[i] = it ;
        if ( i == s.length() - 1){
            in(i);
        }
        else ql(i + 1) ;
    }
}
int main()
{
    cin >> s ;
    ql(0);
    return 0 ;
}
/*
23
ad ae af bd be bf cd ce cf
*/