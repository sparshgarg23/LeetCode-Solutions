// Time:  O(nlogn + nlogk) = O(nlogn), k is the length of the result.
// Space: O(1)

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> result;

        sort(envelopes.begin(), envelopes.end(),  // O(nlogn)
            [](const int& a, const int& b) {
                if (a[0] == b[0]) {
                    return a[1]> b[1];
                }
                return a[0] < b[0];
            });
        for (const auto& envelope : envelopes) {
            const auto target = envelope.second;
            auto it = lower_bound(result.begin(), result.end(), target);  // O(logk)
            if (it == result.end()) {
                result.emplace_back(target);
            } else {
                *it = target;
            }
        }

        return result.size();
    }
};
