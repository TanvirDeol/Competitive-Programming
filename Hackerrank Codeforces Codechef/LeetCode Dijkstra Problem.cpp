#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int>  pi;
#define mp make_pair
#define vec vector


class Solution {
public:

    vec<int> dijkstra(vec<vec<pi> >adj, int src, int N) {
        priority_queue<pi> pq;
        vec<int> dist(N, INT_MAX);
        pq.push({ 0,src });
        dist[src] = 0;
        while (!pq.empty()) {
            int cur = pq.top().second;
            pq.pop();
            vector<pi> ::iterator i;
            for (i = adj[cur].begin(); i < adj[cur].end(); i++) {
                int n = i->first;
                int len = i->second;
                if (dist[n] > dist[cur] + len) {
                    dist[n] = dist[cur] + len;
                    pq.push(mp(dist[n], n));
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pi> cities;
        vec<vec<pi>> graph(n, vector<pi>());
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(mp(edges[i][1], edges[i][2]));
            graph[edges[i][1]].push_back(mp(edges[i][0], edges[i][2]));
        }
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            vec<int> res = dijkstra(graph, i, n);
            int x = 0;
            for (int j = 0; j < res.size(); j++) {
                if (res[j] <= distanceThreshold) { x++; }
            }
            if (x < min)min = x;
            cities.push_back({ x,i });
        }
        sort(cities.begin(), cities.end());
        int idx = 0;
        for (int i = 0; i < cities.size(); i++) {
            if (cities[i].first > min)break;
            idx = cities[i].second;
        }

        return idx;
    }

};
int main()
{
    return 0;
}
