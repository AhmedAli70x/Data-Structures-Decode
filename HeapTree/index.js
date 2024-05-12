const Heap = require('./heap.js');

var  heap = new Heap();
heap.insert(99);
heap.insert(1);
heap.insert(12);
heap.insert(21);
heap.insert(45);
heap.insert(81);
heap.insert(4);
heap.insert(31);

heap.print();
heap.draw();

console.log(heap.pop());
heap.draw();
console.log(heap.pop());
heap.draw();
console.log(heap.pop());
heap.draw();
console.log(heap.pop());
heap.draw();
console.log(heap.pop());
heap.draw();
console.log(heap.pop());
heap.draw();
console.log(heap.pop());
heap.draw();
console.log(heap.pop());
heap.draw();
console.log(heap.pop());
heap.draw();