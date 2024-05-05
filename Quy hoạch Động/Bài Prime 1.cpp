#include<bits/stdc++.h>
using namespace std;
int prime[1001] ;
int F[1001] ;
void sang(){
    for (int i = 0 ; i <= 1000 ; i++){
        prime[i] = 1 ;
    }
    prime[0] = prime[1] = 0 ;
    for ( int i = 2 ; i <= sqrt(1000) ; i++ ){
        if ( prime[i]){
            for ( int j = i * i ; j <= 1000 ; j += i){
                prime[j] = 0 ;
            }
        }
    }
}
int main()
{
    sang() ;
    for ( int i = 1 ; i <= 1000 ; i++){
        if ( prime[i]){
            F[i] = F[i - 1] + 1; 
        }
        else F[i] = F[i - 1];
    }
    int t ; cin >> t ;
    while ( t--){
        int n ;
        cin >> n ;
        cout << F[n] << endl;
    }
    return 0 ;
}
/*
5
39
68
26
87
6

12
19
9
23
3

*/