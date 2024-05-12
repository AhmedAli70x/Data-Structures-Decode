class linkedlistNode {
    data;
    next;
    constructor(_data) {
        this.data = _data;
        this.next = null;
    } 
}

class linkedlistIterator {
    currentNode;
    constructor(node){
        this.currentNode = node;
    }
    data(){
        if (this.currentNode==null) return null;
        return this.currentNode.data;
    }
    next(){
    if (this.currentNode != null){
        this.currentNode = this.currentNode.next;
    } return this;
    }
    
    current(){
        return this.currentNode;
    }
    
}

class linkedList{
    head;
    tail;
    constructor(){
        this.head = null;
        this.tail = null;
        this.length = 0;
        
    }
    
    begin(){
        const itr = new linkedlistIterator(this.head);
        return itr;
    }
    
    printList(){
        var printData = "";
        for(var itr=this.begin(); itr.current() != null; itr.next()){
            
            printData += itr.data() + " -> ";
        }
        
        console.log(printData);
    }
    
    find(_data){
        for(var itr=this.begin(); itr.current() !=null; itr.next()){
            if (itr.data() == _data){
                return itr.current();
            }
        }
        return null;
        
    }
    findParent(node){
        for(var itr=this.begin(); itr.current() !=null; itr.next()){
            if (itr.current().next == node){
                return itr.current();
            }
        }
        return null;
        
    }
    
    insertLast(_data){
        var newNode = new linkedlistNode(_data);
  
        if (this.head == null){
            this.head = newNode;
            this.tail = newNode;
        }   else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.length++;
    }
    
    insertAfter(node_data, _data ){
        var node = this.find(node_data);
        var newNode = new linkedlistNode(_data);
        newNode.next = node.next;
        node.next = newNode;
        
        if (newNode.next == null){
            this.tail = newNode;
        }
        this.length++;
    }
    insertBefore(node_data, _data ){
        const node = this.find(node_data);
        var newNode = new linkedlistNode(_data);
        newNode.next=node
        var parent = this.findParent(node);
        ;
        if (parent == null){
            this.head=newNode;
        }
        else {
            parent.next=newNode;
        }
        this.length++;
    }
    
    deleteNode(node_data){
        var node = this.find(node_data);
        if (node == null) return;
        if (this.head == this.tail){
            this.head == null;
            this.tail == null;
        } else if (this.head ==node){
            this.head = node.next;
        } else {
            var parent = this.findParent(node);
            if(this.tail = node){
                parent.next = null;
                this.tail = parent;
            }
            else {
                patent.next = node.next;
            }
            
        }
        this.length--;
    }
    size(){
        return this.length;
    }
    
    insertFirst(_data){
        var newNode = new linkedlistNode(_data);
        
        if(this.head == null) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            newNode.next = this.head;
            this.head = newNode;
        }
        
        this.length++;
    }
    
    deleteHead(){
        if(this.head == null) return;
        this.head = this.head.next;
        this.length--;
        
    }
    
}


module.exports = {
    linkedList: linkedList,
    linkedlistNode: linkedlistNode,
    linkedlistIterator: linkedlistIterator
  };


