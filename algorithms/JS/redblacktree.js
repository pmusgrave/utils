// red black trees
// this still needs a lot of improvement
// to do:
// change method of building tree initially to an append node or insert method
// change checking red black properties to be recursive - it is not currently
//    so it only balances the root node
//    store height of each node as part of the tree_node object
//    and update it whenever a change is made
var random_data = new Array();
var dataset_size = 10;
var i = 0
// while (i < dataset_size) {
//     random_data.push( Math.floor( Math.random() * dataset_size ) );
//     i += 1;
// }

// random_data = [4,7,6,1,3,8,4,5,6,6];
random_data = [5,7,6,9,9,5,6,8,9,3];
console.log(random_data);

module.exports = {
  tree_node : function() {
    color = "black";
    key = null;
    parent = null;
    left = null;
    right = null;
  },

  buildTree : function (node, parent) {
  // this would be better as "appendNode" that works one item at a time
  // will change later
    if (j < random_data.length) {
      if (node.key == null) {
        node.key = random_data[j];
        node.left = new this.tree_node();
        node.left.parent = node;
        node.right = new this.tree_node();
        node.right.parent = node;
        node.parent = parent;
        node.color = "black";
        j++;
        this.checkColor(parent);
        this.buildTree(rootNode, null);
      }
      else if (random_data[j] <= node.key) {
        this.checkColor(parent);
        this.buildTree(node.left, node);
      }
      else if (random_data[j] > node.key) {
        this.checkColor(parent);
        this.buildTree(node.right, node);
      }
    }
    else {
      return;
    }
  },

  checkColor : function (node){
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
  },

  checkRedBlackProps : function (node) {
    if (node == null) {
      return;
    }


    if (node.left != null) {
      var left_bh = this.getBlackHeight(node.left);
    }
    else {
      return;
    }

    if (node.right != null) {
      var right_bh = this.getBlackHeight(node.right);
    }
    else {
      return;
    }

    while(right_bh > left_bh + 1 || left_bh > right_bh + 1){
      console.log(left_bh + ' ' + right_bh);

      if (left_bh > right_bh + 1) {
        console.log('rotating right');
        rootNode = this.rotateRight(node);
        this.checkColor(node);
        return;
      }
      if (right_bh > left_bh + 1) {
        console.log('rotating left');
        rootNode = this.rotateLeft(node);
        this.checkColor(node);
        return;
      }
      left_bh = this.getBlackHeight(node.left);
      right_bh = this.getBlackHeight(node.right);
    }
  },

  traverseTree : function (node) {
    if (node.key != null) {
      this.traverseTree(node.left);
      console.log("color: " + node.color + " " + node.key);
      this.traverseTree(node.right);
    }
    else {
      return;
    }
  },

  rotateRight : function (node) {
    newRoot = node.left;
    newRoot.parent = node.parent;
    node.parent = newRoot;
    node.left = newRoot.right;
    newRoot.right = node;
    return newRoot;
  },

  rotateLeft : function (node) {
    newRoot = node.right;
    newRoot.parent = node.parent;
    node.parent = newRoot;
    node.right = newRoot.left;
    newRoot.left = node;
    return newRoot;
  },

  getBlackHeight : function (node) {
    if (node == null) {
      //console.log("null " + node);
      return -1;
    }
    else if (node.color == "black") {
      var left_bh = this.getBlackHeight(node.left);
      var right_bh = this.getBlackHeight(node.right);
      if (left_bh >= right_bh) {
        return left_bh + 1;
      }
      else {
        return right_bh + 1;
      }
    }
    else {
      var left_bh = this.getBlackHeight(node.left);
      var right_bh = this.getBlackHeight(node.right);
      if (left_bh >= right_bh) {
        return left_bh;
      }
      else {
        return right_bh;
      }
    }
  }
}

var rootNode = new module.exports.tree_node();
var node = rootNode;
rootNode.color = "black";
var bh = null;//getBlackHeight(rootNode);
// console.log("bh: " + bh);
// bh = getBlackHeight(rootNode.left);
// console.log("bh: " + bh);
var j = 0;

module.exports.buildTree(rootNode);
module.exports.traverseTree(rootNode);
console.log("root node: " + rootNode.key);
bh = module.exports.getBlackHeight(rootNode);
console.log("bh: " + bh);
console.log("checking red black properties");
module.exports.checkRedBlackProps(rootNode);
module.exports.checkColor(rootNode);
//rootNode = rotateLeft(rootNode);
module.exports.traverseTree(rootNode);
bh = module.exports.getBlackHeight(rootNode);
console.log("bh: " + bh);
console.log("root node: " + rootNode.key);

left_bh = module.exports.getBlackHeight(rootNode.left);
console.log("left bh: " + left_bh);

right_bh = module.exports.getBlackHeight(rootNode.right);
console.log("bh: " + right_bh);
