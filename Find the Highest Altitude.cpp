class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // vector<int> res={0};
        // for(int i = 0; i < gain.size(); i++){
        //     res.push_back(res[i] + gain[i]);
        // }

        // int mx = INT_MIN;
        // for(int i = 0; i < res.size(); i++){
        //     mx = max(mx, res[i]);
        // }
        // return mx;

        int mx = 0;
        int mxAlt = 0;
        for(int i = 0; i < gain.size(); i++){
            mxAlt += gain[i];
            mx = max(mx,mxAlt);
        }
        return mx;
    }
};
