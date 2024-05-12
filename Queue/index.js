const  Stack = require('./queue.js');

 

var stack = new Stack();

console.log("IsEmpty", stack.isEmpty());

stack.push(11);
stack.push(21);
stack.push(33);
stack.push(154);

stack.print();
console.log("IsEmpty", stack.isEmpty());
 
console.log("Size", stack.size());
console.log("pop", stack.pop());
console.log("peek", stack.peek());

stack.print();

while(!stack.isEmpty()){
    console.log("pop", stack.pop());
    stack.print();
    console.log("Size", stack.size());
    console.log("\n");

}