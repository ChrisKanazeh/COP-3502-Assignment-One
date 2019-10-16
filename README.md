# COP-3502-Assignment-One
COP 3502 Assignment One

Create a linked list node to include char name[50]; int id; struct node *next;

main()

Call the function to read in the data file as a linked list - Provide the user a menu of the following options: 1. Insert 2. Display 3. Delete by ID 4. Delete by Name 5. Exit - Use a conditional statement to evaluate the user’s selection -- if option 1, call function to insert a new student -- if option 2, call function to display the linked list -- if option 3, call function to delete by id number -- if option 4, call function to delete by student name -- if option 5, exit the program

Function to read the data file as nodes in a linked list: Read in the contents of data file "AssignmentOneInput.txt" into the node data structure

Function to insert a new student: Prompt the user for the student’s name Prompt the user for the student’s id number Populate an instance of the linked list node with the data Add the new node to the existing linked list

Function to display the linked list: Traverse the linked list and display the data of each node

Function to delete by id number: Prompt the user for the student’s id number Traverse the linked list to find the entered id number If it exists delete it and inform the user it has been deleted If it does not exit inform the user the entered id number was not found

Function to delete by name (first, middle, or last name are sufficient): Prompt the user for the student’s id name Traverse the linked list to find the entered name If it exists delete it and inform the user it has been deleted If it does not exist inform the user the entered name was not found

Exit the program: Write the appropriate code to exit the program
