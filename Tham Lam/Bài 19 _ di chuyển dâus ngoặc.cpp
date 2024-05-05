#include<bits/stdc++.h>
using namespace std;
/*
Bài 19 _ Di chuyển dấu ngoặc : Cho xâu S chỉ bao gồm các kí tự '(' hoặc ')' . S có độ dài là số chẵn có giá trị là N . Xâu S gồm N / 2 kí tự mở ngoặc và N / 2 kí tự đóng ngoặc. Ở mỗi thao tác các bạn được lựa chọn  gồm 1 kí tự bất kỳ của S để đưa về vị trí đầu tiên hoặc vị trí cuối cùng của dãy . Các bạn hãy xác định số thao tác tối thiểu để thực hiện một xâu ký tự hợp lệ 
*/
int main()
{
    string s ; cin >> s ;
    stack<int> st ;
    int cnt = 0 ;
    for ( int i = 0 ; i < s.size() ; i++){
        if ( s[i] == '('){
            st.push(i) ;
        }
        else {
            if(st.empty()) cnt ++;
            else {
                st.pop();
            }
        }
    }
    cout << cnt ;
    return 0;
}