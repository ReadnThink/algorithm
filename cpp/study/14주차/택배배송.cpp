#include <bits/stdc++.h>
const int INF = 987654321;
const int MX = 50001;
using namespace std;
int n,m,dist[MX];
vector<pair<int,int>> adj[MX];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
// queue<pair<int,int>> q;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int a,b,c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
}

int dikstra(){
    fill(dist, dist+MX, INF);
    q.push({0,1});
    dist[1] = 0;

    while(q.size()){
        int weight = q.top().first; 
        int node = q.top().second; 
        q.pop();

        if(dist[node] != weight) continue;

        for(auto next : adj[node]){
            int n_node = next.first;
            int n_wight = next.second;

            if(dist[n_node] > dist[node] + n_wight){
                dist[n_node] = dist[node] + n_wight;
                q.push({dist[n_node], n_node});
            }
        }
    }
    
    return dist[n];
}   

int main(){
    input();
    int ret = dikstra();
    cout << ret << '\n';
}