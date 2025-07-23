#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    class Node{
        public:
        ll total, prefix, suffix, best;
        Node(ll val = 0){
            total = val;
            prefix = suffix = best = max(0LL, val);
        }
    };

    class SegmentTree{
    public:
        ll n;
        vector<Node> tree;

        SegmentTree(vector<ll> &nums){
            this->n = nums.size();
            tree.resize(4 * n);
            build(nums, 1, 0, n-1);
        }

        void build(vector<ll> &nums, ll ind, ll l, ll r){
            if(l == r){
                tree[ind] = Node(nums[l]); return;
            }
            ll mid = (l + r) / 2;
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

        void update(ll pos, ll val) {
            updateUtil(1, 0, n - 1, pos, val);
        }

        void updateUtil(ll id, ll l, ll r, ll pos, ll val) {
            if (l == r) {
                tree[id] = Node(val);
                return;
            }
            ll mid = (l + r) / 2;
            if (pos <= mid) updateUtil(2 * id, l, mid, pos, val);
            else updateUtil(2 * id + 1, mid + 1, r, pos, val);
            tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
        }

        ll getMaxSubarraySum() {
            return tree[1].best;
        }
    };
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<long long> res(n);
        vector<long long> arr(n, 0);
        SegmentTree st(arr);

        for (int i = n - 1; i >= 0; --i) {
            int idx = removeQueries[i];
            st.update(idx, nums[idx]);
            res[i] = st.getMaxSubarraySum();
        }

        return res;
    }
};

int main() {

    return 0;
}