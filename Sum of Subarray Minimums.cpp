// BRUTEFORCE
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            int mini = arr[i];
            for(int j=i; j<n; j++){
                mini = min(arr[j],mini);
                sum = (sum + mini) % int(1e9 + 7);
            }
        }

        return sum;
    }
};



OPTIMAL
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> prev(n), next(n);
        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = (ans + (1LL * arr[i] * left % MOD) * right) % MOD;
        }

        return ans;
    }
};
