var random_data = new Array();
var dataset_size = 10;
var i = 0
while (i < dataset_size) {
    random_data.push( Math.floor( Math.random() * dataset_size ) );
    i += 1;
}

// random_data = [4,7,6,1,3,8,4,5,6,6];
console.log(random_data);


var tree_node = function() {
  color = "black";
  key = null;
  parent = null;
  left = null;
  right = null;
};

var rootNode = new tree_node();
var node = rootNode;
rootNode.color = "black";
var bh = null;//getBlackHeight(rootNode);
// console.log("bh: " + bh);
// bh = getBlackHeight(rootNode.left);
// console.log("bh: " + bh);
var j = 0;

function buildTree (node, parent) {
  if (j < random_data.length) {
    if (node.key == null) {
      node.key = random_data[j];
      node.left = new tree_node();
      node.left.parent = node;
      node.right = new tree_node();
      node.right.parent = node;
      node.parent = parent;
      node.color = "black";
      j++;
      checkColor(parent);
      buildTree(rootNode, null);
    }
    else if (random_data[j] <= node.key) {
      checkColor(parent);
      buildTree(node.left, node);
    }
    else if (random_data[j] > node.key) {
      checkColor(parent);
      buildTree(node.right, node);
    }
  }
  else {
    return;
  }
}

function checkColor(node){
  if (node != null) {
    if (node.left.color == "black" && node.right.color == "black") {
      node.color = "red";
    }
    if (node == rootNode) {
      node.color = "black";
    }
    if (node.key == null) {
      node.color = "black";
    }
  }
}

function checkRedBlackProps(node) {
  if (node == null) {
    return;
  }

  if (node.left != null) {
    var left_bh = getBlackHeight(node.left);
  }
  if (node.right != null) {
    var right_bh = getBlackHeight(node.right);
  }


  // if(node.left != null && node.right != null){
  //   if (getBlackHeight(node.left) > getBlackHeight(node.right) + 2) {
  //     rotateRight(node);
  //     checkColor(node);
  //   }
  //   else if (getBlackHeight(node.left) < getBlackHeight(node.right)) {
  //     rotateLeft(node);
  //     checkColor(node);
  //   }
  // }
}

function traverseTree(node) {
  if (node.key != null) {
    traverseTree(node.left);
    console.log("color: " + node.color + " " + node.key);
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

function getBlackHeight(node) {
  if (node == null) {
    //console.log("null " + node);
    return -1;
  }
  else if (node.color == "black") {
    var left_bh = getBlackHeight(node.left);
    var right_bh = getBlackHeight(node.right);
    if (left_bh >= right_bh) {
      return left_bh + 1;
    }
    else {
      return right_bh + 1;
    }
  }
  else {
    var left_bh = getBlackHeight(node.left);
    var right_bh = getBlackHeight(node.right);
    if (left_bh >= right_bh) {
      return left_bh;
    }
    else {
      return right_bh;
    }
  }
}


buildTree(rootNode);
checkRedBlackProps(rootNode);
traverseTree(rootNode);
bh = getBlackHeight(rootNode);
console.log("bh: " + bh);
console.log("root node: " + rootNode.key);
