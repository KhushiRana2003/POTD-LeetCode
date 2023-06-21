// class Solution {
// public:
//     long long getCost(vector<int>&nums, vector<int>& cost, long long median){
//         long long currAns = 0;
//         for(int i = 0; i < nums.size(); i++){
//             int diff = abs(nums[i]-median);
//             currAns = 1LL*diff*cost[i];
//         }
//         return currAns;
//     }
//     long long minCost(vector<int>& nums, vector<int>& cost) {
//         long long ans = 0;
//         int n = nums.size();

//         vector<pair<int,int>> v;

//         for(int i = 0; i < nums.size(); i++){
//             v.push_back({nums[i],cost[i]});
//         }

//         int totalN = 0;
//         sort(v.begin(),v.end());
//         for(int i = 0; i < n; i++){
//             totalN += 1L*v[i].second;
//         }

//         long long median, count = 0;
//         for(int i = 0; i < n && count < (totalN+1)/2; i++){
//             count += 1L*v[i].second;
//             median = v[i].first;
//         }
//         return getCost(nums,cost,median);
//     }
// };

class Solution {
public:

    long long getCost(vector<int>&nums, vector<int>& cost, long long median){

        long long ans = 0;

         for(int i=0;i<nums.size();i++)
           ans += abs(1ll*nums[i]-median)*(1ll*cost[i]);

         return ans;  
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        // long long tot = 0;
        // long long sum = 0;
        // int n = nums.size();

        // vector<pair<int,int>> vec;

        // for(int i=0;i<nums.size();i++)
        //     vec.push_back({nums[i],cost[i]});

        // sort(vec.begin(),vec.end());

        // for(int i=0;i<n;i++)
        // sum += vec[i].second;

        // long long median;
        // int i=0;

        // while(tot < (sum+1)/2 && i<n){

        //      tot += 1ll*vec[i].second;
        //      median = vec[i].first;
        //      i++;
        // }    
        
        
        // return calc(nums,cost,median);

        long long ans = 0;
        int l = nums[0], h = nums[0];

        for(auto n : nums){
            l = min(l,n);
            h = max(h,n);

            while(l < h){
                int mid = l + (h-l)/2;
                long long curr1 = getCost(nums,cost,mid);
                long long curr2 = getCost(nums,cost, mid+1);

                ans = min(curr1,curr2);

                if(curr1 > curr2){
                    l = mid+1;
                }
                else{
                    h = mid;
                }
            }
        }
        return ans;
    }
};
