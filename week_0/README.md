# Week 0 
### C Projects
#### DAY-1 : Command Line Calculator 
**Prerequisites**
    - argc/argv
    - input validation 
**Intuition**
    - `main` function already can take arguments as strings, so we can use this to pass number and operation type e.g., `./calc add 5 4`. Which shall output `9.00`. 
    - You will need function for each opeartion (add, sub, mul, divide). 
    - You will need a way to parse the user's input such that, when `add` is passed the add function is called. This can be done cleverly using `strcmp`. 
    - Now, we need to get the numbers they want to operate on, since input will be as a string, we need to typecast them as **double** or **float**. We can do this using `atof` function from the `stdlib` library.
#### DAy-2 : 