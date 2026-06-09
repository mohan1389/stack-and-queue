// BRUTEFORCE: TC - O(n * m) + O(m) + O(m)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> nge(m,-1);
        vector<int>ans(n,0);
        stack<int> s;
        int k = 0;

        for(int i= m-1; i>=0; i--){
            while(!s.empty() && s.top()<=nums2[i]) s.pop();
            if(!s.empty()) nge[i] = s.top();
            //else nge[i] = s.top();

            s.push(nums2[i]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i] == nums2[j]){
                    ans[k] = nge[j];
                    k++;
                }
            }
        }

        return ans;
    }
};
