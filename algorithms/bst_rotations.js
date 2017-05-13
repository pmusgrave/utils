var random_data = new Array();
var dataset_size = 10;
var i = 0
while (i < dataset_size) {
    random_data.push( Math.floor( Math.random() * dataset_size ) );
    i += 1;
}

console.log(random_data);


var tree_node = function() {
  key = null;
  parent = null;
  left = null;
  right = null;
};

var rootNode = new tree_node();
var prev = null;
var node = rootNode;
var j = 0;

function buildTree (node, parent) {
  if (j < random_data.length) {
    if (node.key == null) {
      node.key = random_data[j];
      node.left = new tree_node();
      node.right = new tree_node();
      node.parent = parent;
      j++;
      buildTree(rootNode, null);
    }
    else if (random_data[j] <= node.key) {
      buildTree(node.left, node);
    }
    else if (random_data[j] > node.key) {
      buildTree(node.right, node);
    }
  }
  else {
    return;
  }
}

function traverseTree(node) {
  if (node.key != null) {
    traverseTree(node.left);
    console.log(node.key);
    traverseTree(node.right);
  }
  else {
    return;
  }
}

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

buildTree(rootNode);
traverseTree(rootNode);
console.log("root before rotation: " + rootNode.key);
rootNode = rotateRight(rootNode);
console.log("root after rotation: " + rootNode.key)
