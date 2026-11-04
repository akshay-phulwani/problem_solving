
class Solution {
public:
    using ll = long long;

    multiset<ll> low, high;
    ll sumLow = 0, sumHigh = 0;

    void add(ll x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }

        balance();
    }

    void remove(ll x) {
        if (low.count(x)) {
            low.erase(low.find(x));
            sumLow -= x;
        } else {
            high.erase(high.find(x));
            sumHigh -= x;
        }

        balance();
    }

    void balance() {
        while (low.size() > high.size() + 1) {
            ll x = *low.rbegin();
            low.erase(prev(low.end()));
            sumLow -= x;
            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < high.size()) {
            ll x = *high.begin();
            high.erase(high.begin());
            sumHigh -= x;
            low.insert(x);
            sumLow += x;
        }
    }

    ll getCost() {
        ll median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<ll> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x)
                remove(nums[i - x]);

            if (i >= x - 1)
                cost[i - x + 1] = getCost();
        }

        const ll INF = 1e18;

        vector<vector<ll>> dp(
            n + 1, vector<ll>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
