#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, m;
int lv[333]; string name[333];
vector<vector<int>> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> lv[i] >> name[i];
    for(int i=1; i<=n; i++){
        int idx = -1;
        for(int j=0; j<v.size(); j++) if(v[j].size() < m && abs(lv[v[j][0]] - lv[i]) <= 10){ idx = j; break; }
        if(idx == -1){ v.emplace_back(); v.back().push_back(i); }
        else v[idx].push_back(i);
    }
    for(auto i : v){
        if(i.size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";
        sort(all(i), [&](int a, int b){ return name[a] < name[b]; });
        for(auto j : i) cout << lv[j] << " " << name[j] << "\n";
    }
}