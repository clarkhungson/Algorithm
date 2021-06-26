#include <bits/stdc++.h>
#define N 100

int parent[N], rank[N];

void init() {
    for (int i=0; i<N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (rank[u] == rank[v]) rank[u]++;
    if (rank[u] < rank[v]) parent[u] = v;
    else parent[v] = u;
}

int main() {
    return 0;
}
