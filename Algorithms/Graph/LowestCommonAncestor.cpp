// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/607/week-5-june-29th-june-30th/3797/
// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T;
int n;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode *root, vector<int> &path, int k)
    {
        // base case
        if (root == NULL) return false;

        // Store this node in path vector. The node will be removed if
        // not in path from root to k
        path.push_back(root->val);

        // See if the k is same as root's val
        if (root->val == k)
            return true;

        // Check if k is found in left or right sub-tree
        if ( (root->left && findPath(root->left, path, k)) ||
             (root->right && findPath(root->right, path, k)) )
            return true;

        // If not present in subtree rooted with root, remove root from
        // path[] and return false
        path.pop_back();
        return false;
    }

    // Returns LCA if node n1, n2 are present in the given binary tree,
    // otherwise return -1
    int findLCA(TreeNode *root, int n1, int n2)
    {
        // to store paths to n1 and n2 from the root
        vector<int> path1, path2;

        // Find paths from root to n1 and root to n1. If either n1 or n2
        // is not present, return -1
        if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
              return -1;

        /* Compare the paths to get the first different value */
        int i;
        for (i = 0; i < path1.size() && i < path2.size() ; i++)
            if (path1[i] != path2[i])
                break;
        return path1[i-1];
    }
    
    // Find a node with value
    // Function to traverse the tree in preorder
    // and check if the given node exists in it
    TreeNode* ifNodeExists(struct TreeNode* node, int key)
    {
        if (node == NULL)
            return NULL;

        if (node->val == key)
            return node;

        /* then recur on left sutree */
        auto res1 = ifNodeExists(node->left, key);
        // node found, no need to look further
        if(res1) return res1;

        /* node is not found in left,
        so recur on right subtree */
        auto res2 = ifNodeExists(node->right, key);

        return res2;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = findLCA(root, p->val, q->val);
        
        auto ans = ifNodeExists(root, val);
        
        return ans;
        
    }
};

int main() {

    return 0;
}
