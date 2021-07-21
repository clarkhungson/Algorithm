// https://codejam.lge.com/contest/problem/672/4
// https://www.geeksforgeeks.org/iterative-segment-tree-range-maximum-query-with-node-update/
// build: 

// 
/*

g++ -o BorrowingBoxes BorrowingBoxes.cpp -std=c++11 && BorrowingBoxes


7
3 1
2 3 7 5
7 3 8 17
3 3
2 3 7 5
7 3 8 17
4 7
2 3 7 10
7 3 8 11
4 8
2 3 7 10
7 3 8 11
10 20
1 17 31 23
7 4 8 41
6 1000000000
123456 1 1 180001
654321 1000000000 1 180161
6 1000000000
123456 1 1 180001
2021 1000000000 1 180161


*/

#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <deque>

// vector<vector<int64_t>> dp;

void construct_segment_tree(vector<int64_t>& segtree,
                            vector<int64_t>& a, vector<int64_t>& b, int n)
{
    // assign values to leaves of the segment tree
    for (int i = 0; i < n; i++)
        segtree[n + i] = a[i] * b[i];
 
    /* assign values to internal nodes
    to compute maximum in a given range */
    for (int i = n - 1; i >= 1; i--)
        segtree[i] = max(segtree[2 * i],
                         segtree[2 * i + 1]);

    // dp.clear();
    // dp.resize(n, vector<int64_t>(n, -1));
}
 
void update(vector<int64_t>& segtree, int pos, int value,
            int n)
{
    // change the index to leaf node first
    pos += n;
 
    // update the value at the leaf node
    // at the exact index
    segtree[pos] = value;
 
    while (pos > 1) {
 
        // move up one level at a time in the tree
        pos >>= 1;
 
        // update the values in the nodes in
        // the next higher level
        segtree[pos] = max(segtree[2 * pos],
                           segtree[2 * pos + 1]);
    }
}
 
int64_t range_query(const vector<int64_t>& segtree, int left, int
                                                    right,
                int n)
{
    /* Basically the left and right indices will move
        towards right and left respectively and with
        every each next higher level and compute the
        maximum at each height. */
    // change the index to leaf node first
    left += n;
    right += n;
 
    // initialize maximum to a very low value
    int64_t ma = INT_MIN;
 
    while (left < right) {
 
        // if left index in odd
        if (left & 1) {
            ma = max(ma, segtree[left]);
 
            // make left index even
            left++;
        }
 
        // if right index in odd
        if (right & 1) {
 
            // make right index even
            right--;
 
            ma = max(ma, segtree[right]);
        }
 
        // move to the next higher level
        left /= 2;
        right /= 2;
    }
    return ma;
}





// ---------------------------



// A utility function to get the
// middle index of given range.
int getMid(int s, int e)
{
    return s + (e - s) / 2;
}
 
/*  A recursive function to get the sum of
    values in given range of the array.
    The following are parameters for this
    function.
 
    st       -> Pointer to segment tree
    node     -> Index of current node in
                the segment tree .
    ss & se  -> Starting and ending indexes
                of the segment represented
                by current node, i.e., st[node]
    l & r    -> Starting and ending indexes
                of range query */
int64_t MaxUtil(int64_t* st, int64_t ss, int64_t se, int l,
            int r, int64_t node)
{
    // If segment of this node is completely
    // part of given range, then return
    // the max of segment
    if (l <= ss && r >= se)
        return st[node];
 
    // If segment of this node does not
    // belong to given range
    if (se < l || ss > r)
        return -1;
 
    // If segment of this node is partially
    // the part of given range
    int64_t mid = getMid(ss, se);
     
    return max(MaxUtil(st, ss, mid, l, r,
                       2 * node + 1),
               MaxUtil(st, mid + 1, se, l,
                       r, 2 * node + 2));
}
 
/* A recursive function to update the nodes
   which have the given index in their range.
   The following are parameters st, ss and
   se are same as defined
   above index -> index of the element
   to be updated.*/
// void updateValue(int arr[], int* st, int ss, int se,
//                  int index, int value, int node)
// {
//     if (index < ss || index > se)
//     {
//         cout << "Invalid Input" << endl;
//         return;
//     }
     
//     if (ss == se)
//     {  
//         // update value in array and in segment tree
//         arr[index] = value;
//         st[node] = value;
//     }
//     else {
//             int mid = getMid(ss, se);
             
//             if (index >= ss && index <= mid)
//                 updateValue(arr, st,
//                             ss, mid, index,
//                             value, 2 * node + 1);
//             else
//                 updateValue(arr,
//                             st, mid + 1, se,
//                             index,
//                             value, 2 * node + 2);
             
//             st[node] = max(st[2 * node + 1],
//                        st[2 * node + 2]);
//     }
//     return;
// }
 
// Return max of elements in range from
// index l (query start) to r (query end).
int64_t getMax(int64_t* st, int n, int l, int r)
{
    // Check for erroneous input values
    if (l < 0 || r > n - 1 || l > r)
    {
        printf("Invalid Input,");
        return -1;
    }

    // if (dp[l][r] != -1) {
    //     return dp[l][r];
    // }

    // dp[l][r] = MaxUtil(st, 0, n - 1, l, r, 0);

    // return dp[l][r];
 
    return MaxUtil(st, 0, n - 1, l, r, 0);
}
 
// A recursive function that constructs Segment
// Tree for array[ss..se]. si is index of
// current node in segment tree st
int64_t constructSTUtil(vector<int64_t>& arr, int64_t ss, int64_t se,
                    int64_t* st, int64_t si)
{
    // If there is one element in array, store
    // it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then
    // recur for left and right subtrees and
    // store the max of values in this node
    int mid = getMid(ss, se);
     
    st[si] = max(constructSTUtil(arr, ss, mid, st,
                                 si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se,
                                 st, si * 2 + 2));
     
    return st[si];
}
 
/* Function to construct segment tree
   from given array.
   This function allocates memory for
   segment tree.*/
int64_t* constructST(vector<int64_t> arr, int n)
{
    // Height of segment tree
    int x = (int)(ceil(log2(n)));
 
    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;
 
    // Allocate memory
    int64_t* st = new int64_t[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0);

    // dp.clear();
    // dp.resize(n, vector<int64_t>(n, -1));
 
    // Return the constructed segment tree
    return st;
}



// ----------------------------






void cal(int n, int x, vector<int64_t>& H, vector<int64_t>& W) {
    int64_t ans = -1;

    vector<int64_t> V(n, 0);
    // for (int i = 0; i < n; i++) {
    //     V[i] = H[i] * W[i];
    // }

    // cout << "-> V:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << V[i] << " ";
    // }
    // cout << endl;

    // cout << "-> H:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << H[i] << " ";
    // }
    // cout << endl;



    // int64_t* st = constructST(V, n);
 
    // Print max of values in array
    // from index 1 to 3
    // cout << "Max of values in given range = "
    //      << getMax(st, n, 1, 3) << endl;




	
    /* Construct the segment tree by assigning
    the values to the internal nodes*/
    vector<int64_t> segtree(2 * n);
    construct_segment_tree(segtree, H, W, n);

    vector<int64_t> mm(n, 0);
    mm[n - 1] = H[n - 1] * W[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        mm[i] = H[i] * W[i];
        if (mm[i] < mm[i + 1]) {
            mm[i] = mm[i + 1];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int j = upper_bound(H.begin() + i + 1, H.end(), H[i] + x) - H.begin() - 1;
        if (j == i) {
            continue;
        }

        if (ans < mm[i] + H[i] * W[i]) {
            if (j == n - 1) {
                int64_t val = mm[i + 1] + H[i] * W[i];
                ans = max(ans, val);
            } else if (mm[i + 1] >= mm[j + 1]) {
                int64_t val = mm[i + 1] + H[i] * W[i];
                ans = max(ans, val);
            } else {
                int64_t val = range_query(segtree, i + 1, j + 1, n);
                val += H[i] * W[i];
                // int64_t val = getMax(st, n, i + 1, j) + V[i];
                // if (ans < val) {
                //     ans = val;
                // }
                ans = max(ans, val);
            }
            
        }
        // cout << "i: " << i << ", j: " << j << ", range_query(segtree, i, j + 1, n): " << range_query(segtree, i + 1, j + 1, n) << endl;
    }
    cout << ans << endl;
}

void cal2(int n, int x, vector<int64_t>& H, vector<int64_t>& W) {
    int64_t ans = -1;

    // vector<int64_t> V(n, 0);
    // for (int i = 0; i < n; i++) {
    //     V[i] = H[i] * W[i];
    // }

    // cout << "-> V:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << V[i] << " ";
    // }
    // cout << endl;

    // cout << "-> H:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << H[i] << " ";
    // }
    // cout << endl;

    deque<int64_t> dq;

    int j = 1;
    for (int i = 0; i < n - 1; i++) {
        while (H[j] <= H[i] + x && j < n) {
            while (!dq.empty() && H[dq.back()] * W[dq.back()] <= H[j] * W[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        while(!dq.empty() && dq.front() <= i) {
            dq.pop_front();
        }
        if (!dq.empty()) {
            ans = max(ans, H[dq.front()] * W[dq.front()] + H[i] * W[i]);
            // cout << "i: " << i << ", ans : " << ans << endl;
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int64_t hs, ha, hb, hc;
        int64_t ws, wa, wb, wc;
        cin >> hs >> ha >> hb >> hc;
        cin >> ws >> wa >> wb >> wc;

        vector<int64_t> H(n), W(n);
        H[0] = hs % hc + 1;
        W[0] = ws % wc + 1;
        for (int i=1; i<=n-1; i++) {
            H[i] = H[i-1] + 1 + (H[i-1] * ha + hb) % hc;
            W[i] = (W[i-1] * wa + wb) % wc + 1;
        }

        // Insert code here

        cal2(n, x, H, W);

        // End of insertion
    }
    return 0;
}
