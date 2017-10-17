NODE *lowestCommonAncestor(int x,int y,NODE *root){
	if(root->data<x)return lowestCommonAncestor(x,y,root->right);
	if(root->data>y)return lowestCommonAncestor(x,y,root->left);
	return root;
}