# Week 0 
### C Projects
#### DAY-1 : Command Line Calculator 
###### Prerequisites
- argc/argv
- input validation 
###### Intuition
- `main` function already can take arguments as strings, so we can use this to pass number and operation type e.g., `./calc add 5 4`. Which shall output `9.00`. 
- You will need function for each opeartion (add, sub, mul, divide). 
- You will need a way to parse the user's input such that, when `add` is passed the add function is called. This can be done cleverly using `strcmp`. 
- Now, we need to get the numbers they want to operate on, since input will be as a string, we need to typecast them as **double** or **float**. We can do this using `atof` function from the `stdlib` library.

#### DAY-2 : Dynamic Array Implementation 
###### Prerequisites
- malloc
- free
- pointers
- struct 
###### Intuition 
- you can get a contiguous memory block using `malloc` and then use `realoc` to increment the size of array.
- the important part is to check if the array can or cannot insert an element or not. If the array capacity is 5 int elements for instance and it currently has the size 5, then we have to realoc more memory to insert a new element. 
- we can create a `typedef struct` which can hold metadata about the dynamic array i.e., **Initial Capacity**, **Size** and pointer to the first address of the contiguous memory block.

#### DAY-3 : Student Record System
###### Prerequisites
- file I/O
- struct 
- fopen 
- fwrite
###### Intuition
- Create a struct to store the inputs, write them using `fwrite` as binary using `wb` mode.
- Do the same for reading using `fread` in `rb` mode.  

#### DAY-4 : Singly Linked List Implementation 
##### Prerequisistes
- linked list 
- pointers 
- struct 
- dynamic array
- memory mangament  

##### Intuition 
- ***linked list*** is a dynamic array where the first element also stores a pointer to the next element, creating a node like structure. 
- We can `typedef` a `struct` creating a custom data type with value and a pointer
- and each of these **struct element** will the element of a dynamic array.


#### DAY-5: Text File Analyzer
##### Prerequisites 
- File I/O
- fread
- fseek
- ftell 
- string handling 

##### Intuition 
- dedicated function of counting lines, words and characters(non-spaces)
- we need to have a buffer that stores the texts/string from the txt file, then we can operate on the buffer using our functions.
- use `fseek` to get the **size** of the file, starting from 0 to **SEEK_END**.
- use `ftell` to store the size in a **long** variable. 
- now use `fread` to store in our `buffer` (make sure to `rewind` the file before reading)

#### DAY-6 Matrix Library 
##### Prerequisites
- pointers
- memory management 