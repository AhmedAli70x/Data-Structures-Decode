

module.exports = class Stack{

 #data_list;
 #top_index;
 constructor(){
    this.#data_list = [];
    this.#top_index = -1 ;

 }

 push(_data){
    this.#data_list.push(_data);
    this.#top_index++;
 }
 pop(){
    if (this.#top_index == -1 )return;
    var head_data = this.#data_list.splice(this.#top_index, 1)[0];
    this.#top_index--;
    return head_data;
 }
 peek(){
     return this.#data_list[this.#top_index];
 }

 isEmpty(){
    return this.#data_list.length <=0;
 }

 print(){
    var print_data = "";
    for(var i = this.#top_index; i >=0; i--){
        print_data += this.#data_list[i] + " -> ";
    }
    console.log(print_data);
 }
 size(){
    return this.#data_list.length;
 }
}