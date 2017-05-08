// converts an array to a singly linked list
var arr = [0,1,2,3,4,5,6,7,8,9];

var Linked_list_node = function() {
  this.key = null;
  this.next = null;
  this.prev = null;
}

var List = function() {
  this.head = new Linked_list_node();
  this.tail = null;
}

function doublylinkedlistify (array) {
  if (array.length == 0) {
    console.log("array error");
    return;
  }

  var L = new List();
  L.head.key = array[0];
  L.head.prev = null;
  L.head.next = null;
  L.tail = L.head;

  var prev = new Linked_list_node();
  prev = L.head;
  var current = new Linked_list_node();

  for (var i = 1; i < array.length; i++) {
    current = new Linked_list_node();
    prev.next = current;
    current.key = array[i];
    current.prev = prev;
    current.next = null;

    prev = current;
    current = current.next;
  }
  L.tail = current;
  return L;
}

function traverseList (node) {
  if(node.next == null) {
    console.log(node);
    return;
  }
  else {
    console.log(node);
    traverseList(node.next);
  }
}

function searchList(node, searchKey) {
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
}

function insertNode(newNode,tail) {
  tail.next = newNode;
  tail = newNode;
}

function removeNode(node, node_to_remove) {
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

var list = doublylinkedlistify(arr);
traverseList(list.head);
// var node_to_remove = searchList(L.head, 4);
// console.log(node_to_remove);
// removeNode(L.head, node_to_remove);
// traverseList(L.head);
