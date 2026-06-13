class Solution {
    void InOrder(Node* root,vector<int>& v){
        //InOrder =  left -> root -> right;
        if(root==NULL) return;
        stack<Node*> st;
        Node* node = root;
        while(!st.empty() || node != NULL){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                Node* temp = st.top(); st.pop();
                v.push_back(temp->data);
                node = temp->right;
            }
        }
    }
    void convert(Node* root ,vector<int>& v , int& index ){
            if(root==NULL) return;
            convert(root->left,v,index);
            convert(root->right,v,index);
            root->data = v[index];
            index++;
    }
  public:
    void convertToMaxHeapUtil(Node* root) {
        vector<int> arr;
        InOrder(root,arr);
        int index = 0;
        convert(root,arr,index);
    }
};
