//
//  nutanix_oa.cpp
//  tt
//
//  Created by WEI SHI on 10/18/19.
//  Copyright © 2019 WEI SHI. All rights reserved.
//
/*

bool pizzaTreats(vector<int>& nums){
    if(nums.empty())
        return true;
    int left = 0;
    for(auto num: nums){
        if(num - left < 0)
            return false;
        if((num - left) % 2 == 0)
            left = 0;
        else
            left = 1;
    }
    return left == 0;
}
 
 int brokenCal(int x, int y){
    if(y <= x)
        return x-y;
    if(y % 2 == 0)
        return brokenCal(x, y/2) + 1;
    else
        return brokenCal(x, y+1) + 1;
 }
 
 int paintFence(int n, vector<int>& nums){
    vector<int> arr;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1)
            arr.push_back(i);
    }
    if(arr.size() < 2)
        return 0;
    int res = 1;
    for(int i = 0; i < arr.size() -1; i++){
        res = res *(arr[i+1] - arr[i]);
    }
    return res;
 }
 
 void DFS12345(vector<vector<char>>& grid,int i, int j, int m, int n, vector<bool> visited,vector<int>parent,bool &res){
    visited[i*n + j] = true;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x >= 0 && x < m && y >=0 && y < n && grid[x][y] == grid[i][j]){
            if(visited[x*n +y] == true && parent[i*n + j] != x*n+y){
                res = true;
                return ;
            }
            else if(visited[x*n +y] == false){
                parent[x*n + y] = i*n + j;
                DFS12345(grid, x, y, m, n, visited, parent,res);
            }
        }
    }
    visited[i*n + j] = false;
 }
 bool hasLoops(vector<vector<char>>& grid){
    int m = grid.size(), n = grid[0].size();
    vector<bool> visited(m*n, false);
    vector<int> parent(m*n, -1);
    bool res = false;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            res = false;
            DFS12345(grid,i,j,m,n, visited, parent, res);
            if(res == true)
                return true;
        }
    return false;
 }
 
 
 int beautifulRow(vector<int>& nums){
    if(nums.size() <= 2)
        return 0;
    int n = nums.size();
    vector<int> fromLeft(n,1),fromRight(n,1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i])
                fromLeft[i] = max(fromLeft[i],fromLeft[j] + 1);
        }
    }
    for(int i = n-2; i >= 0; i--)
        for(int j = n-1; j > i; j--){
            if(nums[j] < nums[i] )
                fromRight[i] = max(fromRight[i],fromRight[j] + 1);
        }
    int maxVal = 0;
    for(int i = 0; i < n; i++)
        maxVal = max(maxVal, fromLeft[i] + fromRight[i] - 1);
    return n - maxVal;
 
 }
 
 int countEmail(vector<int>& emails){
    if(emails.empty())
        return 0;
    int count = 0;
    int n = emails.size();
    int left = 0;
    while(left < n && emails[left] == 0)
        left ++;
    if(left == n)
    return 0;
    
 int read = 1;
 for(int i = index; i < n-1; i++){
 if(emails[i] == 1){
 count++;
 read = 1;
 }
 else{
 if(read == 1){
 count++;
 read = 0;
 }
 
 }
 }
 return count;
 }

 
 
 int weightString( string s, int p, int w, int t){
 if(s.empty())
 return 0;
 int n = s.size();
 vector<int> dp(n+1,0);
 dp[1] = w;
 for(int i = 2; i <= n; i++){
 if(s[i-1] != s[i-2]){
 dp[i] = max(dp[i],max(dp[i-1] + w, dp[i-2] + p));
 }
 else
 dp[i] = max(dp[i],max(dp[i-1] + w, dp[i-2] + p -t));
 }
 return dp[n];
 }

 
 int countDeciNumber(int num){
 vector<int> nums;
 queue<int> queue;
 queue.push(1);
 while(!queue.empty()){
 int size = queue.size();
 for(int i = 0; i < size; i++){
 auto cur = queue.front();
 queue.pop();
 nums.push_back(cur);
 int temp = cur*10;
 if(temp <= num)
 queue.push(temp);
 temp = cur*10 + 1;
 if(temp <= num)
 queue.push(temp);
 }
 }
 
 vector<int> dp(num+1, num + 1);
 dp[0] = 0;
 for(auto n:nums)
 cout<<n<<endl;
 for(int i = 1; i <= num; i++){
 for(int j = 0; j < nums.size() && nums[j] <= i; j++){
 dp[i] = min(dp[i],dp[i - nums[j]] + 1);
 }
 }
 return dp[num];
 
 }
 
 
 int jump(vector<int>& nums) {
    int n = nums.size();
    if(n <2)
        return 0;
    int count = 0, maxReach = nums[0],currentMax = 0;
    for(int i = 0 ; i < n -1; i++){
        currentMax = max(currentMax, i + nums[i]);
        if(i == maxReach){
            count ++;
            maxReach = currentMax;
        }
    }
    return count+1;
 }
 
 int jump(vector<int>& nums) {
    int n = nums.size();
    vector<bool>canJump(n,false);
    canJump[0] = true;
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i ;j++){
        if(canJump[j] && nums[j] >= i-j){
            canJump[i] = true;
            dp[i] = min(dp[i],dp[j] +1);
        }
    }
    return dp[n-1];
 }
*/
