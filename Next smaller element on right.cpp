// OPTIMAL
// TC: O(n) + O(n) 
// SC: O(n) + O(n) -------> stack + nse array

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i]<=st.top()) st.pop();

            if(st.empty()) nse[i] = -1;
            else nse[i] = st.top();

            st.push(arr[i]);
        }

        return nse;
    }
};
