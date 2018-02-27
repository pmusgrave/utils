// converts an array to a singly linked list
var arr = [0,1,2,3,4,5,6,7,8,9];

module.exports = {
  Linked_list_node : function() {
    this.key = null;
    this.next = null;
  },

  List : function() {
    this.head = new module.exports.Linked_list_node();
    this.tail = null;
  },

  linkedlistify : function (node, index) {
    if (index >= arr.length - 1) {
      node.key = arr[index];
      node.next = null;
      L.tail = node;
    }
    else {
      node.key = arr[index];
      node.next = this.linkedlistify(new module.exports.Linked_list_node(), index + 1);
    }
    return node;
  },

  traverseList : function (node) {
    if(node.next == null) {
      console.log(node.key);
      return;
    }
    else {
      console.log(node.key);
      this.traverseList(node.next);
    }
  },

  searchList : function (node, searchKey) {
    if (node.key == searchKey) {
      console.log("Key found");
      console.log(node);
      return node;
    }
    else if (node.next == null){
      console.log("Key not found");
      return null;
    }
    else {
      this.searchList(node.next, searchKey);
    }
  },

  insertNode : function (newNode,tail) {
    tail.next = newNode;
    tail = newNode;
  },

  removeNode : function(node, node_to_remove) {
    if (node != null) {
      if(node.next === node_to_remove) {
        node.next = node.next.next;
        return;
      }
      else {
        this.removeNode(node.next, node_to_remove);
        return;
      }
    }
  },
}


var L = new module.exports.List();
L.head.next = L.tail;
module.exports.linkedlistify(L.head, 0);
module.exports.traverseList(L.head);
var node_to_remove = module.exports.searchList(L.head, 4);
console.log(node_to_remove);
module.exports.removeNode(L.head, node_to_remove);
module.exports.traverseList(L.head);
