const { linkedList, linkedlistNode, linkedlistIterator } = require('./linkedlist.js');


module.exports = class Stack{

 #data_list;
 constructor(){

    this.#data_list = new linkedList();
 }

 push(_data){
    this.#data_list.insertFirst(_data);
 }
 pop(){
    var head_data = this.#data_list.head.data;
    this.#data_list.deleteHead();
    return head_data;
 }
 peek(){
     return this.#data_list.head.data;
 }

 isEmpty(){
    return this.#data_list.length <=0;
 }

 print(){
    this.#data_list.printList();
 }
 size(){
    return this.#data_list.size();
 }
}