// builds a binary search tree out of an array of random data
var random_data = new Array();
var dataset_size = 10;
var i = 0
while (i < dataset_size) {
    random_data.push( Math.floor( Math.random() * dataset_size ) );
    i += 1;
}

console.log('Random data: ' + random_data);

var Tree_node = function() {
  this.key = null;
  this.parent = null;
  this.left = null;
  this.right = null;
}

var rootNode = new Tree_node();
var prev = null;
var node = rootNode;
var j = 0;

module.exports = {
  Tree_node: Tree_node,
  rootNode: rootNode,

  buildTree : function (node, parent) {
    if (j < random_data.length) {
      if (node.key == null) {
        node.key = random_data[j];
        node.left = new this.Tree_node();
        node.right = new this.Tree_node();
        node.parent = parent;
        j++;
        this.buildTree(rootNode, null);
      }
      else if (random_data[j] <= node.key) {
        this.buildTree(node.left, node);
      }
      else if (random_data[j] > node.key) {
        this.buildTree(node.right, node);
      }
    }
    else {
      return;
    }
  },

  traverseTreeInOrder : function (node) {
    if (node.key != null) {
      this.traverseTreeInOrder(node.left);
      console.log(node.key);
      this.traverseTreeInOrder(node.right);
    }
    else {
      return;
    }
  },

  traverseTreePreOrder : function (node) {
    if (node.key != null) {
      console.log(node.key);
      this.traverseTreePreOrder(node.left);
      this.traverseTreePreOrder(node.right);
    }
    else {
      return;
    }
  },

  traverseTreePostOrder : function (node) {
    if (node.key != null) {
      this.traverseTreePostOrder(node.left);
      this.traverseTreePostOrder(node.right);
      console.log(node.key);
    }
    else {
      return;
    }
  },


}

console.log('Traversing tree in order: ');
module.exports.buildTree(rootNode, null);
module.exports.traverseTreeInOrder(rootNode);
