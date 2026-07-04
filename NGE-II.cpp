// BRUTEFORCE 
// TC: O(N^2) | SC: O(N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n,-1);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<=i+n-1; j++){
                int ind = j % n;

                if(nums[ind] > nums[i]){
                    nge[i] = nums[ind];
                    break;
                }
            }
        }
        return nge;
    }
};


//OPTIMAL
// TC: O(2N) + O(2N) ---------> outer loop + inner loop
// SC: O(2N) + O(2N) ---------> stack + nge array
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> nge(n);

        for(int i=2*n-1; i>=0; i--){

            while(!s.empty() && s.top() <= nums[i%n]) s.pop();

            if(s.empty()) nge[i%n] = -1;
            else nge[i%n] = s.top();

            s.push(nums[i%n]);
        }

        return nge;
    }
};
