#include<bits/stdc++.h>
using namespace std;
/*
CÂU 24 : cho string t , tìm tất cả cấu hình chứa in hoa in thường !
*/
string s ;
char x[1001];
void in(){
    for (int i = 0 ; i < s.size() ; i++ ){
        cout << x[i];
    }
    cout << endl;
}
void ql(int i){
    if ( i == s.size()){
        in();
        return;
    }
    if (isalpha(s[i])){
        x[i] = tolower(s[i]) ;
        ql(i + 1) ;
        x[i] = toupper(x[i]);
        ql(i + 1) ;
    }
    else {
        x[i] = s[i] ;
        ql(i + 1) ;
    }
}
int main()
{
    cin >> s ;
    ql(0);
    return 0 ;
}
/*
28TEACH

28teach
28teacH
28teaCh
28teaCH
28teAch
28teAcH
28teACh
28teACH
28tEach
28tEacH
28tEaCh
28tEaCH
28tEAch
28tEAcH
28tEACh
28tEACH
28Teach
28TeacH
28TeaCh
28TeaCH
28TeAch
28TeAcH
28TeACh
28TeACH
28TEach
28TEacH
28TEaCh
28TEaCH
28TEAch
28TEAcH
28TEACh
28TEACH
*/