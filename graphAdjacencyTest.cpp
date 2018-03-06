#include <iostream >
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M, x, y;
    cin >> N >> M;
    vector <int> adj[N+1];
    for(int i = 0; i< M; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int q;

    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> x >> y;
        if(find(adj[x].begin(), adj[x].end(), y) != adj[x].end() || find(adj[y].begin(), adj[y].end(), x) != adj[y].end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
