class Solution {
public: 
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        }); 

        int cur = tasks[0][1]; // 12
        int t = cur - tasks[0][0]; 
        for(int j = 1; j < tasks.size(); ++j){
            vector<int> i = tasks[j];
            if(t < i[1]){
                int x = i[1] - t ;
                t +=x ; 
                cur +=x; 
                t -= i[0]; 
            }else{
                t -= i[0]; 
            }
        }

        return cur; 
    }
};
