#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* minValue(TreeNode *root) {
        while (root->left != nullptr)
            root = root->left;
        return root;
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right)
            return minValue(p->right);
        TreeNode *succ = nullptr;
        while (root) {
            if (p->val < root->val) {
                succ = root;
                root = root->left;
            } else if (p->val > root->val) {
                root = root->right;
            } else
                break;
        }
        return succ;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);
    Solution sol;
    cout << sol.inorderSuccessor(root, root->left->left)->val;
    return 0;
}
