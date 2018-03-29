#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n): parent(n), rank(n,1) {
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }

    int find(int n) {
        if (parent[n] == n)
            return n;
        
        parent[n] = find(parent[n]);
        return parent[n];
    }

    void merge(int a, int b) {
        a=find(a);
        b=find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b])
            parent[a] = b;
        else
            parent[b] = a;

        if (rank[a] == rank[b])
            rank[parent[a]]++;
    }

};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    DisjointSet ds(n+1);

    int query, a, b;
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &query, &a, &b);
        if (!query)
            ds.merge(a, b);
        else {
            if (ds.find(a) == ds.find(b))
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}