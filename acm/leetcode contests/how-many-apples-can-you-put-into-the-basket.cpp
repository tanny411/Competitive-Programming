class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        int sum=0,i;
        sort(arr.begin(),arr.end());
        for (i=0;i<arr.size();i++){
            if(sum+arr[i]<=5000) sum+=arr[i];
            else break;
        }
        return i;
    }
};