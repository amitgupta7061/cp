#include <bits/stdc++.h>
using namespace std;


class SegmentTree{

    class Node{
    public:
        int val;
        Node(int val = 0){
            this->val = val;
        }
    };

    int n;
    vector<Node> tree;

    SegmentTree(vector<int> &nums){
        this->n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void build(vector<int> &nums, int ind, int l, int r){
        if(l == r){
            tree[ind] = Node(nums[l]); return;
        }

        int mid = l + (r - l) / 2;
        build(nums, 2 * ind, l, mid);
        build(nums, 2 * ind + 1, mid + 1, r);
        tree[ind] = merge(tree[2 * ind], tree[2 * ind + 1]);
    }

    Node merge(Node &left, Node &rght){
        
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(auto &it : nums) cin >> it;



    return 0;
}