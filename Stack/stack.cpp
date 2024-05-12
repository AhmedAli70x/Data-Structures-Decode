// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Stack{
    private:
    int *data_list;
    int top_index;
    int initial_size;
    int current_size;
    
    public:
     Stack(){
         this->initial_size = 3;
         this->data_list = new int[this->initial_size];
         this->current_size = this->initial_size;
         this->top_index = -1;
     }
     void resizeOrnot(){
         if(this->top_index< this->current_size -1) return;
         int *newArray = new int[this->current_size + this->initial_size];
         cout << "Stack will be resized \n";
         std:copy(this->data_list, this->data_list+this->current_size, newArray);
         this->current_size +=this->initial_size;
         
         delete[] this->data_list;
         this->data_list= newArray;
  
     }
     
     void push(int _data){
         this->resizeOrnot();
         this->data_list[++this->top_index] = _data;
     }
     
     int peek(){
        if(this->top_index ==-1) return 0;
        return this->data_list[this->top_index];
     }
     
     int pop(){
        if(this->top_index ==-1) return 0;
        int head_data = this->data_list[this->top_index] = 0;
        this->data_list[this->top_index]=0;
        this-top_index--;
        return head_data;
     }
     bool isEmpty(){
         return this->top_index >=0;
     }
     int size(){
         return this->top_index+1;
     }
     
     void print(){
         for(int i=this->top_index;i>-1; i--)
         cout << this->data_list[i] << " -> ";
         
         cout << "\n";
     }
    
    
};


  int main() {
   
   Stack *stack = new Stack();
   
   cout << "Is Empty " << stack->isEmpty() << "\n";
   
   stack->push(1);
   stack->push(2);
   stack->push(3);

   
    stack->print();
    
     cout << "Size " << stack->size() << "\n";
     
    stack->push(44);
    stack->print();
    
    stack->pop();
    stack->pop();
    stack->pop();
    stack->print();
   
}