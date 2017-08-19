var bst = require('./binarysearchtree.js');

//var rootNode = new bst.Tree_node();
//var node = rootNode;

function rotateRight(node) {
  newRoot = node.left;
  newRoot.parent = node.parent;
  node.parent = newRoot;
  node.left = newRoot.right;
  newRoot.right = node;
  return newRoot;
}

function rotateLeft(node) {
  newRoot = node.right;
  newRoot.parent = node.parent;
  node.parent = newRoot;
  node.right = newRoot.left;
  newRoot.left = node;
  return newRoot;
}

//bst.buildTree(bst.rootNode);
//bst.traverseTree(bst.rootNode);
console.log("root before rotation: " + bst.rootNode.key);
bst.rootNode = rotateRight(bst.rootNode);
console.log("root after rotation: " + bst.rootNode.key)
