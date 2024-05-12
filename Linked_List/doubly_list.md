## Insert Last
####  Assumptoptions

### Inputs:
- node
- new data

### Processes
- validations
- node is not null

- Insert
    - create new node for "data"
    - if the tail is null
        - make list tail and head = newNode
    - else
        - make the the newNode back = the tail
        - the tail next = newNode
        - make list Tail = the newNode

- Outputs:
    - Nothing

### Outputs


******

## Delete Node
####  Assumptoptions

### Inputs:
- node

### Processes
- validations
- node is not null

- if node is head and tail
    - head and tail = null

- If node is head
    - the node next back = NULL
    - the list head = node next

- If node is tail
    - the node back next = NULL
    - the list tail = node 

- if node in between nodes
    - the prev node next points to the node next
    - the next node back point to the node back

- delete node.

 

- Outputs:
    - Nothing

### Outputs