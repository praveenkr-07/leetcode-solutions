class Solution {
    TreeNode* build(vector<int>& pre, int preLo , int preHi , vector<int>& in , int inLo , int inHi){
        if(preLo>preHi ) return NULL;
        TreeNode* root = new TreeNode(pre[preLo]);
       + if(preLo==preHi) return root;
        
        int i = inLo;
        while(i<=inHi){
            if(pre[preLo] == in[i]) break;
            i++;
        }
        int leftCount =  i - inLo;
        int rightCount =  inHi - i;
        root->left = build(pre , preLo+1 , preLo+leftCount , in , inLo , i-1);
        root->right = build(pre , preLo+leftCount+1 , preHi , in , i+1 , inHi);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return build(pre,0,n-1,in,0,n-1);
    }
}; 