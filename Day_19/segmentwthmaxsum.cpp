#include <bits/stdc++.h>
using namespace std;

#define int long long

class Node{
public:
    int total, prefix, suffix, best;
    Node(int val = 0){
        total = val;
        prefix = suffix = best = max(0LL, val);
    }
};

class SegmentTree{
public:
    int n;
    vector<Node> tree;

    SegmentTree(vector<int> &nums){
        this->n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n-1);
    }

    void build(vector<int> &nums, int ind, int l, int r){
        if(l == r){
            tree[ind] = Node(nums[l]); return;
        }
        int mid = (l + r) / 2;
        build(nums, 2 * ind, l, mid);
        build(nums, 2 * ind + 1, mid + 1, r);
        tree[ind] = merge(tree[2 * ind], tree[2 * ind + 1]);
    }

    Node merge(Node &left, Node &rght){
        Node res;
        res.total = left.total + rght.total;
        res.prefix = max(left.prefix, left.total + rght.prefix);
        res.suffix = max(rght.suffix, rght.total + left.suffix);
        res.best = max({left.best, rght.best, left.suffix + rght.prefix});
        return res;
    }

    void update(int pos, int val) {
        updateUtil(1, 0, n - 1, pos, val);
    }

    void updateUtil(int id, int l, int r, int pos, int val) {
        if (l == r) {
            tree[id] = Node(val);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) updateUtil(2 * id, l, mid, pos, val);
        else updateUtil(2 * id + 1, mid + 1, r, pos, val);
        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }

    int getMaxSubarraySum() {
        return tree[1].best;
    }
};


int32_t main() {

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(auto &it : nums) cin>>it;

    SegmentTree st(nums);
    cout<<st.getMaxSubarraySum()<<"\n";

    for(int i = 0; i < m; i++){
        int ind, val;
        cin >> ind >> val;

        st.update(ind, val);
        cout<<st.getMaxSubarraySum()<<"\n";
    }


    return 0;
}