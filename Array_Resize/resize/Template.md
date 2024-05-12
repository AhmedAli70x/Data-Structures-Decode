## NAME 
Resize

## Assumptions 
- Array data store in memory heap
- Array address is stored in memory stack

## Inputs 
- the array data type
- the array itself
- new size

## Processes 
- Validations 
  - the new size is a valid number
  - the array is not null
  - the new size in not equal the current size

- Resize
  - create new empty array from the same type with the new size
  - move all items from source array to new array
  - assign the address of the new array for the source array address

## Outputs:
 - nothing

