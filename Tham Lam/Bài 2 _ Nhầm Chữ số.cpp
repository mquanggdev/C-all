#include<bits/stdc++.h>
using namespace std;
/*
bài 2 : Nhầm chữ số : có 2 số nguyên A và B , cần thực hiện phép cộng giữa hai số . Tèo không bao giờ tính toán sai
nhưng hay viết nhầm số : lỗi duy nhất là hay viết nhầm 5 thành 6 hoặc ngược lại. hãy tính tổng nhỏ nhất và lớn nhất 
mà tèo nhận được từ 2 số A và B
*/
int main()
{
    int n , m  ;
    cin >> n >> m ;
    int max_value = 0 ;
    int min_value = 0 ;
    string s1 = to_string(n);
    string s2 = to_string(m) ;
    for (char &x : s1){
        if (x == '6' ){
            x = '5' ;
        }
    }
    for (char& x: s2){
        if (x == '6'){
            x = '5' ;
        }
    }
    min_value = stoi(s1) + stoi(s2);
    for (char &x : s1){
        if (x == '5' ){
            x = '6' ;
        }
    }
    for (char& x: s2 ){
        if (x == '5'){
            x = '6' ;
        }
    }
    max_value = stoi(s1) + stoi(s2);
    cout << max_value << " " << min_value << endl;
    cout << s1 << "  " << s2 << endl;
    return 0;
}
/*
891
746
1637 1636
*/