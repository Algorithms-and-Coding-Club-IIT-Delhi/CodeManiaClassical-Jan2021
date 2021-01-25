#include <bits/stdc++.h>

#include "testlib.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<pii> vpi;
bool desc_sort(const int& lhs, const int& rhs) { return lhs > rhs; }
bool desc_pii_sort(const pii& lhs, const pii& rhs) { return lhs > rhs; }
bool second_sort(const pii& lhs, const pii& rhs) {
    pii a, b;
    a.first = lhs.second;
    a.second = lhs.first;
    b.first = rhs.second;
    b.second = rhs.first;
    return a < b;
}

vector<vector<int>> adj;
vector<vector<int>> isl;
vector<bool> vis;
vector<int> id;

void dfs(int v) {
    vis[v] = 1;
    isl.back().push_back(v);
    id[v] = isl.size() - 1;
    for (int u : adj[v]) {
        if (!vis[u]) dfs(u);
    }
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int n, m;
    n = inf.readInt();
    m = inf.readInt();
    int a[n + 1];
    for (int i = 1; i <= n; i++) a[i] = inf.readInt();
    pii edges[m + 1];
    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);
    id.assign(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        edges[i].first = inf.readInt();
        edges[i].second = inf.readInt();
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    int freshers[n + 1];
    for (int i = 1; i <= n; i++) freshers[i] = ouf.readInt();
    vector<bool> freqq(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (freshers[i] < 1 || freshers[i] > n)
            quitf(_wa,
                  "You are assigning some group a city with a number not from "
                  "1 to n. Invalid City. BSW Fails Again :(. ");
        else if (freqq[freshers[i]])
            quitf(_wa,
                  "You are assigning the same city to two groups. That is not "
                  "possible. The City overcrowds and the all the freshers die. "
                  "BSW Fails Again :(");
        freqq[freshers[i]] = true;
    }
    int soln[n + 1];
    for (int i = 1; i <= n; i++) soln[i] = ans.readInt();

    int i;

    for (i = 1; i <= n; i++) {
        if (!vis[i]) {
            isl.push_back({});
            dfs(i);
        }
    }

    long long ouranswer = 0, theiranswer = 0;

    vector<long long> our, their;
    our.assign(isl.size(), 0);
    their = our;
    for (i = 1; i <= n; i++) {
        their[id[freshers[i]]] += a[i];
        our[id[soln[i]]] += a[i];
    }

    for (i = 0; i < isl.size(); i++) {
        theiranswer += (long long)their[i] * ((long long)their[i] - 1ll);
        ouranswer += our[i] * (our[i] - 1);
    }

    if (ouranswer == theiranswer) {
        quitf(_ok, "Correct Output. You have saved the Freshers");
    } else if (ouranswer < theiranswer) {
        quitf(_fail, "Please Hold On. Let's Verify the Formal Proof");
    } else {
        quitf(_wa, "Freshers are left lonely :(, BSW fails again");
    }
}
