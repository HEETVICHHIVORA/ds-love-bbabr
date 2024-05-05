class Solution {
public:
    int cost = INT_MAX;

    int getMinCost(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
        if (i >= days.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int c1 = costs[0] + getMinCost(days, costs, i + 1, dp);

        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) {
            j++;
        }
        int c2 = costs[1] + getMinCost(days, costs, j, dp);

        int k = i;
        while (k < days.size() && days[k] < days[i] + 30) {
            k++;
        }
        int c3 = costs[2] + getMinCost(days, costs, k, dp);

        return dp[i] = min(c1, min(c2, c3));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return getMinCost(days, costs, 0, dp);
    }
};