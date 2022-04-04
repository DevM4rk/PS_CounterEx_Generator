#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int num[10][7] = {
    {1,1,1,0,1,1,1}, // 0
    {0,0,1,0,0,1,0}, // 1
    {1,0,1,1,1,0,1}, // 2
    {1,0,1,1,0,1,1}, // 3
    {0,1,1,1,0,1,0}, // 4
    {1,1,0,1,0,1,1}, // 5
    {1,1,0,1,1,1,1}, // 6
    {1,0,1,0,0,1,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
};

int n,k,p,ans;
string x;

void dfs(int idx, int cnt, string s){  //k, p check
    
    if(idx == k){
        if(s == x || stoi(s) > n || stoi(s) == 0) return; // 시작층과 같은경우. n을 넘는 경우, 0층인 경우
        //cout << s << endl;
        ans++;
        return;
    }

    for(int i=0; i<10; i++){
        
        int diff=0, nx = s[idx]-'0';
        for(int j=0; j<7; j++){
            if(num[nx][j] != num[i][j]) diff++;
        }

        if(cnt - diff >= 0){
            string str = s;
            str[idx] = i + '0';
            
            dfs(idx+1 ,cnt-diff, str);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k >> p >> x;

    dfs(0,p, x);

    cout << ans;
}
/*8:32 ~ 9:19
 _   1
| | 2 3
 -   4
| | 5 6
 -   7
*/