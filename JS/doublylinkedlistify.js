// converts an array to a doubly linked list
var arr = [0,1,2,3,4,5,6,7,8,9];

module.exports = {
  Linked_list_node : function() {
    this.key = null;
    this.next = null;
    this.prev = null;
  },

  List : function() {
    this.head = new module.exports.Linked_list_node();
    this.tail = null;
  },

  doublylinkedlistify : function (array) {
    if (array.length == 0) {
      console.log("array error");
      return;
    }

    var L = new module.exports.List();
    L.head.key = array[0];
    L.head.prev = null;
    L.head.next = null;
    L.tail = L.head;

    var prev = new module.exports.Linked_list_node();
    prev = L.head;
    var current = new module.exports.Linked_list_node();

    for (var i = 1; i < array.length; i++) {
      current = new module.exports.Linked_list_node();
      prev.next = current;
      current.key = array[i];
      current.prev = prev;
      current.next = null;

      prev = current;
      current = current.next;
    }
    L.tail = current;
    return L;
  },

  traverseList : function (node) {
    if(node.next == null) {
      console.log(node);
      return;
    }
    else {
      console.log(node);
      module.exports.traverseList(node.next);
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
      searchList(node.next, searchKey);
    }
  },

  insertNode : function (newNode,tail) {
    tail.next = newNode;
    tail = newNode;
  },

  removeNode : function (node, node_to_remove) {
    if (node != null) {
      if(node.next === node_to_remove) {
        node.next = node.next.next;
        return;
      }
      else {
        removeNode(node.next, node_to_remove);
        return;
      }
    }
  }
}

var list = module.exports.doublylinkedlistify(arr);
module.exports.traverseList(list.head);
// var node_to_remove = searchList(L.head, 4);
// console.log(node_to_remove);
// removeNode(L.head, node_to_remove);
// traverseList(L.head);
