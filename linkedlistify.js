// converts an array to a singly linked list
var arr = [0,1,2,3,4,5,6,7,8,9];

var Linked_list_node = function() {
  this.key = null;
  this.next = null;
}

var List = function() {
  this.head = new Linked_list_node();
  this.tail = null;
}

function linkedlistify (node, index) {
  if (index >= arr.length - 1) {
    node.key = arr[index];
    node.next = null;
    L.tail = node;
  }
  else {
    node.key = arr[index];
    node.next = linkedlistify(new Linked_list_node(), index + 1);
  }
  return node;
}

function traverseList (node) {
  if(node.next == null) {
    console.log(node.key);
    return;
  }
  else {
    console.log(node.key);
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

var L = new List();
L.head.next = L.tail;
linkedlistify(L.head, 0);
console.log(L.tail);
insertNode( {key: 42, next: null} , L.tail);
console.log(L.tail);
