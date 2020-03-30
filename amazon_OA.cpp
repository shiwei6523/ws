//
//  amazon_OA.cpp
//  tt
//
//  Created by WEI SHI on 10/14/19.
//  Copyright © 2019 WEI SHI. All rights reserved.
//

#include <stdio.h>




    if(nums.size() < 2)
        return 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int left = 0, right = n - 1;
    int count = 0;
    unordered_set<int> set;
    while(left < right){
        if(nums[left] + nums[right] == target){
            if(!set.count(nums[left])){
                count++;
                set.insert(nums[left]);
            }
            left++;
            right--;
        }
        else if(nums[left] + nums[right] < target)
            left++;
        else
            right--;
    }
    return count;
}
// O(N)
int TwoSumUniquePairs2(vector<int>& nums,int target){
    unordered_set<int> set, visited;
    int count = 0;
    for(auto num: nums){
        if(set.count(target - num) && !visited.count(num)){
            count++;
            visited.insert(num);
            visited.insert(target - num);
        }
        else if(!set.count(num))
            set.insert(num);
    }
    return count;
}
 
 
unordered_map<string, vector<string>> favoriteGenres(unordered_map<string, vector<string>>& users, unordered_map<string, vector<string>>& genres){
    unordered_map<string, vector<string>> res;
    if(users.empty())
        return res;
    unordered_map<string, string> songToGenre;//song to genre
    for(auto genre: genres){
        if(genre.second.empty())
            continue;
        for(auto song: genre.second)
            songToGenre[song] = genre.first;
    }
    unordered_map<string, unordered_map<string, int>> userToGenre;//key1: user, key2:genre, value2:times
    for(auto user: users){
        if(user.second.empty()){
            res[user.first] = {};
            continue;
        }
    for(auto song:user.second)
        userToGenre[user.first][songToGenre[song]]++;
    }
 
    for(auto ele: userToGenre){
        int maxCount = 0;
        for(auto count: ele.second){
            maxCount = max(maxCount,count.second);
        }
        if(maxCount == 0)
            res[ele.first] = {};
        else{
            for(auto count: ele.second){
                if(count.second == maxCount)
                    res[ele.first].push_back(count.first);
            }
        }
    }
    return res;
 }
 
 Node* randomList(Node* head){
    if(head == nullptr)
        return nullptr;
    Node* newHead, *l1, *l2;
    for(l1 = head; l1 != nullptr; l1 = l1->next->next){
        l2 = new Node(l1->val);
        l2->next = l1 ->next;
        l1->next = l2;
    }
    newHead = head->next;
    for(l1 = head; l1 != nullptr; l1 = l1->next->next){
        if(l1->random != nullptr)
            l1->next->random = l1->random->next;
    }
    for(l1 = head; l1 != nullptr; l1 = l1->next){
        l2 = l1->next;
        l1->next = l2->next;
        if(l2->next != nullptr)
            l2->next = l2->next->next;
    }
    return newHead;
 }
 
 ListNode* mergeTwo(ListNode* l1, ListNode* l2){
    if(l1 == nullptr)
        return l2;
    if(l2 == nullptr)
        return l1;
    if(l1->val <= l2->val){
        l1->next = mergeTwo(l1->next, l2);
        return l1;
    }
    else{
        l2->next=  mergeTwo(l1,l2->next);
        return l2;
    }
 }
 
 bool isSame(TreeNode* s, TreeNode* t){
    if(s== nullptr && t == nullptr)
        return true;
    if(s == nullptr || t == nullptr)
        return false;
    if(s->val != t->val)
        return false;
    else
        return isSame(s->left,t->left)&& isSame(s->right, t->right);
 }
 
 bool isSubtree(TreeNode* s, TreeNode* t){
    if(s == nullptr)
        return false;
    if(t == nullptr)
        return true;
    if(isSame(s,t))
        return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
 }
 
 void DFS32(int cur, int &time, vector<vector<int>>& adj, vector<bool>& visited,vector<int>& low, vector<int>& discovery, vector<int>& parent, set<vector<int>> set,vector<vector<int>>& res){
    visited[cur] = true;
    time++;
    low[cur] = time;
    discovery[cur] = time;
    for(auto next: adj[cur]){
        if(!visited[next]){
            parent[next] = cur;
            DFS32(next,time, adj, visited, low, discovery,parent, set, res);
            low[cur] = min(low[cur], low[next]);
            if(low[next] > discovery[cur]){
                if(set.count({cur,next}))
                    res.push_back({cur, next});
                else if(set.count({next,cur}))
                    res.push_back({next,cur});
            }
        }
        else if(next != parent[cur])
        low[cur] = min(low[cur],discovery[next]);
    }
    return;
 }
 
 vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> res;
    vector<bool> visited(n+1, false);
    vector<int> low(n+1, -1), discovery(n+1,-1);
    vector<int> parent(n+1, -1);
    vector<vector<int>> adj(n+1,vector<int>());
    set<vector<int>> set;
    for(auto conn:connections){
        adj[conn[0]].push_back(conn[1]);
        adj[conn[1]].push_back(conn[0]);
        set.insert(conn);
    }
    int time = 0;
    for(int i = 1; i <= n; i++){
    if(!visited[i]){
        DFS32(i,time,adj,visited,low, discovery,parent, set, res);
    }
 }
 return res;
 }

 
*/
