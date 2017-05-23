
// Breadth first search using an undirected graph as a test case
var vertex = function (key, adjList) {
  this.key = key;
  this.adj = adjList;
  this.color = "white";
  this.distance = Infinity;
};

var graph = [];

graph.push(new vertex(0,[1,4]));
graph.push(new vertex(1,[0,5]));
graph.push(new vertex(2,[3,5,6]));
graph.push(new vertex(3,[2,6,7]));
graph.push(new vertex(4,[0]));
graph.push(new vertex(5,[1,2,6]));
graph.push(new vertex(6,[2,3,5,7]));
graph.push(new vertex(7,[3,6]));

// In this test case, the keys correspond to "graph" indices,
// but this will not be true in general. I'm implementing
// a search algorithm to find the graph object from a given key.
// Vertices will be sorted by their keys to make searching fast.

function findGraphObject(graph, key) {
  var min_index = 0;
  var max_index = graph.length;
  var found_index = null;
  while ((max_index - min_index) > 1) {
      if (key == graph[min_index].key) {
          found_index = min_index
          break
      }

      if ((max_index - min_index) == 2) {
          search_index = min_index + 1
      }
      else {
          search_index = Math.floor( (max_index-min_index) / 2 ) + min_index
      }
      //console.log("index: " + search_index);

      if (key == graph[search_index].key) {
          found_index = search_index
          break
      }
      else if (key < graph[search_index].key) {
          max_index = search_index
      }
      else if (key > graph[search_index].key) {
          min_index = search_index
      }
  }
  return found_index;
}

var queue = [];
var starting_position = 0;
queue.push(graph[findGraphObject(graph, starting_position)]);

while (queue.length > 0) {
  for (var i = 0; i < queue[0].adj.length; i++) {
    var nextAdj = graph[findGraphObject(graph, queue[0].adj[i])];
    if (nextAdj.color == "white") {
      queue.push(nextAdj);
      nextAdj.color = "grey";
      if (nextAdj.distance == Infinity){
        nextAdj.distance = 1;
      }
      else {
        nextAdj.distance = queue[0].distance + 1;
      }
    }
  }
  console.log(queue[0].key);
  queue[0].color = "black";
  queue.shift();
}
