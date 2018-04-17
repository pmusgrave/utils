typedef enum {FALSE=0, TRUE=1} bool;

// Define a node structure.
typedef struct node {
  int val;
  struct node* next;
  struct node* prev;
} node_t;

node_t* make_list_node(int val);
node_t* insert(int val, node_t* head);
void delete_node(node_t* node);
bool find_val(int val, node_t* root);
void delete_linked_list(node_t* root);
void print_linked_list(node_t* root);
