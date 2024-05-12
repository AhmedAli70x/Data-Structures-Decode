// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


    
class linkedListNode
{ public:
    int data;
    linkedListNode *next;
    
    linkedListNode ( int _data){
        
        this->data = _data;
        this->next = NULL;
    }
};


class linkedListIterator {
    
    private:
        linkedListNode *currentNode;
        
    public:
    linkedListIterator(){ currentNode = NULL;}
    linkedListIterator(linkedListNode *node){ currentNode = node;}
    
    int data(){
        return this->currentNode->data;
    }
    linkedListIterator next(){
        this->currentNode = this->currentNode->next;
        return *this;
    }
    
    linkedListNode *current(){
        return this->currentNode;
    }
    
    
    
};
class linkedList{
    private:
       int  length;
    public: 
        linkedListNode *head = NULL;
        linkedListNode *tail = NULL;
        
        linkedListIterator begin(){
            linkedListIterator itr(this->head);
            return itr;
        }
        
        void printList(){
            for (linkedListIterator itr=this->begin(); itr.current()!= NULL; itr.next()){
                cout << itr.data() << " - > ";
            }
            cout << "\n";
        }
         
        
    void inserLast(int _data){
        linkedListNode *newNode = new linkedListNode(_data);
        
        if (this->head ==NULL){
            
            this->head = newNode;
            this->tail = newNode;
        }
        
        else{
            this->tail->next = newNode;
            this->tail = newNode;
            
        };
        this->length++;
    };
    
    linkedListNode *find(int _data){
    for (linkedListIterator itr=this->begin(); itr.current()!= NULL; itr.next()){
        if (itr.data() == _data){
            return itr.current();
        }
            }
                
        return NULL;
    }
    
    linkedListNode *findParent(linkedListNode *node){
    for (linkedListIterator itr=this->begin(); itr.current()!= NULL; itr.next()){
        if (itr.current()->next == node){
            return itr.current();
        }
            }
                
        return NULL;
    }
    
    void insertAfter(linkedListNode *node, int _data){
        
        linkedListNode *newNode = new  linkedListNode(_data);
        newNode->next = node->next;
        node->next = newNode;
        
        if (newNode->next ==NULL){
            this->tail = newNode;
        }
        this->length++;
    }
        
    void insertBefore(linkedListNode *node, int _data){
        
        linkedListNode *newNode = new  linkedListNode(_data);
        newNode->next = node;
        linkedListNode *parent = this->findParent(node);
        
        if (parent ==NULL){
            this->head = newNode;
        }
        else {
            parent->next = newNode;
        }
        
        this->length++;
    };
    
    void deleteNode(linkedListNode *node){
  
        if(this->head == this->tail){
            this->head=NULL;
            this->tail= NULL;
        }
        else if (this->head==node){
            this->head = node->next;
        }
        else{
            linkedListNode *parentNode=this->findParent(node);
        
            if(this->tail ==node){
                this->tail = parentNode;
            }
            else{
                parentNode->next ==node->next;
            }
        }
        
        delete node;
        this->length--;
    }


      void deleteHead(){
        if(this->head == NULL) return;
        this->head = this->head->next;
        this->length--;
        
    }

    int size(){
        return this->length;
    }
};

class Queue{
    private:
        linkedList *data_list;

    public:
        Queue()
        { data_list = new linkedList(); }

        void enqueue(int _data){
            this->data_list->inserLast(_data);
        }

        int dequeue(int _data){//link pop
            int node_data = this->data_list->head->data;
            this->data_list->deleteHead();
            return node_data;
        }

        int peek(){
            if(this->data_list->head == NULL) return 0;
            return this->data_list->head->data;
        }

    bool isEmpty(){
        if(this->data_list->size() == 0)
        return true;
    else
        return false;
    };
    
    int size(){
        return this->data_list->size();
    }
    void  print(){
        return this->data_list->printList();
    }
};

  int main() {
    Queue *queue = new Queue();
    
    cout << "isEmpty " << queue->isEmpty()<<"\n";

    queue->enqueue(1);

    queue->enqueue(2);
    queue->enqueue(3);
    queue->print();
    cout << "isEmpty " << queue->isEmpty()<<"\n";
    queue->dequeue(3);
    queue->print();
     
  
}