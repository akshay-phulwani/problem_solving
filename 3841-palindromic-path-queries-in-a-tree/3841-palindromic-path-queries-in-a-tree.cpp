class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> tin(n), tout(n), depth(n);
        int timer = 0;

        vector<tuple<int, int, bool>> stk;
        stk.push_back({0, -1, false});

        while (!stk.empty()) {
            auto [u, p, exit] = stk.back();
            stk.pop_back();

            if (exit) {
                tout[u] = timer;
                continue;
            }

            up[0][u] = (p == -1 ? 0 : p);
            for (int j = 1; j < LOG; j++)
                up[j][u] = up[j - 1][up[j - 1][u]];

            tin[u] = ++timer;
            stk.push_back({u, p, true});

            for (int i = (int)g[u].size() - 1; i >= 0; i--) {
                int v = g[u][i];
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                stk.push_back({v, u, false});
            }
        }

        vector<int> bit(n + 2);

        auto add = [&](int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto rangeXor = [&](int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        };

        auto get = [&](int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        auto mask = [](char c) {
            return 1 << (c - 'a');
        };

        for (int u = 0; u < n; u++)
            rangeXor(tin[u], tout[u], mask(s[u]));

        auto ancestor = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[v] <= tout[u];
        };

        auto lca = [&](int u, int v) {
            if (ancestor(u, v)) return u;
            if (ancestor(v, u)) return v;

            for (int j = LOG - 1; j >= 0; j--) {
                if (!ancestor(up[j][u], v))
                    u = up[j][u];
            }
            return up[0][u];
        };

        vector<bool> ans;

        for (auto& q : queries) {
            string type;
            int u;
            char c;
            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;
                int delta = mask(s[u]) ^ mask(c);
                rangeXor(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int path = get(tin[u]) ^ get(tin[v]) ^ mask(s[w]);

                ans.push_back((path & (path - 1)) == 0);
            }
        }

        return ans;
    }
};