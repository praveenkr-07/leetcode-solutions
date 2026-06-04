
class Solution {
    
    bool isLeaf(Node *root){
        if(root!= NULL && root->left == NULL && root->right==NULL) return true;
        return false;
    }
    
    
    void leftBoundary(Node* root , vector<int> &ans){
        Node* temp = root->left;
        while(temp){
            if(!isLeaf(temp)){
                ans.push_back(temp->data);
            }
            if(temp->left) temp=temp->left;
            else temp=temp->right;
        }
    }
    
    void leafNode(Node* root , vector<int> &ans){
        if(root==NULL) return;
        
        if(isLeaf(root)){
            ans.push_back(root->data);
        }
        leafNode(root->left,ans);
        leafNode(root->right,ans);
    }
    
    void rightBoundary(Node* root , vector<int> &ans){
        Node* temp = root->right;
        vector<int> v;
        while(temp){
            if(!isLeaf(temp)){
                v.push_back(temp->data);
            }
            if(temp->right) temp=temp->right;
            else temp=temp->left;
        }
        
        for(int i = v.size()-1 ; i>=0 ;i--){
            ans.push_back(v[i]);
        }
        
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        
        // if only one node in the tree 
        if(root!= NULL && root->left == NULL && root->right==NULL)  return {root->data} ;
        
        vector<int> ans;
        // for 1st node of tree 
        ans.push_back(root->data);
        
        //left boundary
        
        leftBoundary(root , ans);
        
        // leaf 
        leafNode(root , ans);
        
        
        // right boundary
        rightBoundary(root , ans);
        
        return ans;

    }
};