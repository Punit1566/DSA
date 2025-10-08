class Solution {
public:
    static bool compRoom(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
    static bool compQuery(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }

    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(), rooms.end(), compRoom);
        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), compQuery);

        set<int> st;
        vector<int> ans(queries.size(), -1);
        int j = 0, n = rooms.size();

        for (auto& q : queries) {
            int prefId = q[0];
            int minSize = q[1];

            while (j < n && rooms[j][1] >= minSize) {
                st.insert(rooms[j][0]);
                j++;
            }

            if (st.empty()) continue;

            auto it = st.lower_bound(prefId);
            int bestId = -1;
            int bestDiff = INT_MAX;

            if (it != st.end()) {
                bestId = *it;
                bestDiff = abs(*it - prefId);
            }

            if (it != st.begin()) {
                --it;
                int diff = abs(*it - prefId);
                if (diff < bestDiff || (diff == bestDiff && *it < bestId)) {
                    bestId = *it;
                    bestDiff = diff;
                }
            }

            ans[q[2]] = bestId;
        }

        return ans;
    }
};
