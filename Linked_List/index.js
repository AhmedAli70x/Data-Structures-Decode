const { linkedList, linkedlistNode, linkedlistIterator } = require('./linkedlist.js');

var list = new linkedList();
list.insertLast(1);
list.insertLast(2);
list.insertLast(3);
console.log(list.size());
list.printList();

list.insertBefore(3, 55);
list.printList();

list.insertAfter(3, 44);
list.printList();

console.log(list.size());
console.log("final");