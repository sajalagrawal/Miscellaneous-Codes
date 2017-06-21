//https://stackoverflow.com/questions/3020070/how-to-find-sum-of-nodes-value-for-given-depth-in-binary-tree


sum(Node, Level){
  if (Level == 0) 
    return Node.value;
  else 
    return sum(Node.left, Level-1) + sum(Node.right, Level-1);
}
