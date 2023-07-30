class Solution {
public:
int getPos(vector<int>& in,int st,int end,int k){
    for(int i=st;i<=end;i++)
    if(in[i]==k)return i;
    return -1;
}
TreeNode*help(vector<int>& in,vector<int>& post,int &indx,int st,int end){
    if(indx==-1 || st>end)return NULL;
    int ele=post[indx--];
    TreeNode*root=new TreeNode(ele);
    int pos=getPos(in,st,end,ele);
    root->right=help(in,post,indx,pos+1,end);
    root->left=help(in,post,indx,st,pos-1);
    return root;
}
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        int st=0,end=n-1,indx=n-1;
    return help(in,post,indx,st,end);
    }
};
