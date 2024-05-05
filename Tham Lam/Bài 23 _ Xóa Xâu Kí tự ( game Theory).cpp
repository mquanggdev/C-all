#include<bits/stdc++.h>
using namespace std;
/*
Bài 23 : Xóa Xâu kí tự : (Game Theory) : Tí và tèo chơi một trò chơi với xâu nhị phân S chỉ bao gồm các số 0 và 1 . ở mỗi bước đi 2 bạn đều có thể chọn một xâu con liên tiếp các ký tự giống nhau ở xâu S và xóa nó đi khỏi xâu . Sau khi xóa thì 2 xâu hai bên xâu đó sẽ chập lại làm 1 . Tí là người đi trước ? Hỏi Tí sẽ ăn được nhiều nhất bao nhiêu số 1.Biết rằng cả 2 bạn đều chơi tối ưu(sẽ ăn dãy nào nhiều 1 trước nhất)
*/
int main()
{
    string s ; cin >> s ;
    s = s + "0" ;
    int cur_length = 0;
    vector<int> v;
    for ( char x : s){
        if ( x == '1') cur_length++;
        else {
            if(cur_length > 0){
                v.push_back(cur_length);
                cur_length = 0 ;
            }
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    int ans = 0 ;
    for ( int i = 0 ; i < v.size() ; i += 2){
        ans += v[i];
    }
    cout << ans ;
    return 0;
}
/*
111100001111111001
8
*/