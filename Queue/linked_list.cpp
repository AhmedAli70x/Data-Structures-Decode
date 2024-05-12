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
        
    }
};

  int main() {
    linkedList *list = new linkedList();
    
    list->inserLast(1);
    list->inserLast(2);
    list->inserLast(3);
    
    list->printList();
    
    list->insertAfter( list->find(2), 98);
    
     list->printList();
     
    list->insertBefore( list->find(1), 55);
     list->printList();
     
    list->deleteNode( list->find(1));
     list->printList();
     
     cout << "head is " << list->head->data<<"\n";
}