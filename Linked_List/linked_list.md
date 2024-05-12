## Insert After
####  Assumptoptions

### Inputs:
- node
- new data

### Processes
- validations
- node is not null

- Insert
    - create new node for "data"
    - make "new node" next pointer is the same same as  "node" next 
    - make the "node" next point = the new created node
    - if the "new node" next is null, this means that hte node was tail >> make the list tail point to new node

- Outputs:
    - Nothing

### Outputs


*******************
## Insert Before
####  Assumptoptions

### Inputs:
- node
- new data

### Processes
- validations
- node is not null

- Insert
    - create new node for "data"
    - make the new node next points to the "node"
    - find the parent of the node
    - if the parent is null 
        - make the new node as head
    - else
        - make the parent next points to the "new node"

### Outputs:
    - Nothing


*******************
## Delete node 
####  Assumptoptions

### Inputs:
- node


### Processes
- validations
- node is not null

- Insert
    -  if node is head and tail
        - make list head and tail is null
    - else if node is head only
        - make the list head is the head next
    
    - else 
        - find the parent 
        - if node is tail 
            - make list tail is the parent
        else
        - make the parent next = node next

    - in all cases
        - delete node

### Outputs:
    - Nothing

 


*******************