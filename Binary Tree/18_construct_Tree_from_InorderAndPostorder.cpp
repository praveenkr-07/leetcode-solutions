class Solution {
    TreeNode* build(vector<int>& in, int inLo , int inHi ,  vector<int>& post , int postLo , int postHi,unordered_map<int,int>& mp){

        if(inLo>inHi) return NULL;
        TreeNode* root = new TreeNode(post[postHi]);
        if(inLo == inHi ) return root;
        int i = mp[post[postHi]];
        int leftCount = i - inLo;

        root->right  = build(in , i+1,inHi ,post ,  postLo +leftCount, postHi -1 , mp );

        root->left = build(in , inLo, i-1 , post , postLo ,postLo + leftCount -1 ,mp);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        unordered_map<int,int> mp;
        for(int i = 0; i<n;i++) mp[in[i]] = i;
        
        return build(in,0,n-1,post,0,n-1,mp);
        
    }
};