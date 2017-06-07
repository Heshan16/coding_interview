/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
	if(!pRoot1 || !pRoot2)
            return false;
        if(pRoot1->val==pRoot2->val && check(pRoot1,pRoot2))
            return true;
        return HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    }
    bool check(TreeNode *pRoot1,TreeNode *pRoot2) {
        if(!pRoot2)
            return true;
        else if(!pRoot1)
            return false;
    	return (pRoot1->val==pRoot2->val) && check(pRoot1->left,pRoot2->left) && check(pRoot1->right,pRoot2->right);    
    }
};
