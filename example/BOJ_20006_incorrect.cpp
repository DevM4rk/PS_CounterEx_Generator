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

struct info{
    int cnt, top, bot;
    vector<pair<string, int>> player;
};

map<int, info> room;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int p,m,l; cin >> p >> m;
    string n;
    for(int i=0; i<p; i++){
        cin >> l >> n;

        bool roomIn=false;
        for(auto &[k,v] : room){
            if(v.bot <= l && l <= v.top && v.cnt < m){
                roomIn=true;
                v.cnt++;
                v.player.push_back({n,l});
                break;
            }
        }

        if(!roomIn){
            room[i].bot = l-10;
            room[i].top = l+10;
            room[i].cnt++;
            room[i].player.push_back({n,l});
        }       
    }

    for(auto &[k,v] : room){
        if(v.cnt==m)
            cout << "Started!\n";
        else
            cout << "Waiting!\n";

        for(auto [na,lv] : v.player)
            cout << lv << " " << na << "\n";
    }
}