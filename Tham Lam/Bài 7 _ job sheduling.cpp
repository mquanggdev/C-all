#include<bits/stdc++.h>
using namespace std;
/*
Bài 7 : Job sheduling : -> bài kinh điển về tham lam : cho hệ gồm N hành động . Mỗi hành động được biểu diễn như một đôi tương ứng với thời gian bắt đầu và thời gian kết thúc của mỗi hành động . Hãy tìm phuong án thực hiện nhiều nhất các hành động có thể , biết rằng 2 hành động phải được thực hiện một cách độc lập . 2 hành động được gọi là độc lập nếu thời gian kết thúc của hành động thứ 1 nhỏ hơn thời gian bắt đầu của hoạt động thứ 2 
*/
int main()
{
    int n ; cin >> n ;
    vector<pair<int,int>> vp ;
    for (auto &{x,y} : vp){
        cin >> x >> y ;
    }
    sort(vp.begin(),vp.end(),[] (pair<int,int> x , pair<int,int> y){
        return x.second < y.second ; // sắp xếp tăng dần theo thời gian kết thúc
    });
    int ans = 1 ;
    int last = vp[0].second ;
    for ( int i = 1 ; i < n ; i++ ){
        if ( vp[i].first > last ){ // nếu mà thời gian kết thúc của thằng đằng trước mà nhỏ hơn thời gian bắt đầu của thằng sau -> tức công việc sẽ được tiếp tục -> gán lại thằng last cho giờ kết thúc của thằng sau!
            last = vp[i].second ;
            ++ans ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}