var l = require('./linkedlistify.js');
var data = process.argv[2];

var list = new l.List();
list.head.next = list.tail;
l.linkedlistify(list.head, 0);
l.traverseList(list.head);
var node_to_remove = l.searchList(list.head, 4);
console.log(node_to_remove);
l.removeNode(list.head, node_to_remove);
l.traverseList(list.head);
