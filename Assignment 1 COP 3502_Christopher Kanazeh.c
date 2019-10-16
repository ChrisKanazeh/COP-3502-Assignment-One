/* Christopher Kanazeh
Assignment 1
CS1 2/8/2015 */

//libraries for the program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Linked List Node created with global variable head.
struct node
{
    char name [50];
    int id;
    struct node *next;
} *head;

//Prototypes
int deleteId(int num);
int deleteName(char *deleteName);
void display(struct node *displayNode);
void insert(char * insertName, char * insertId);
void readDataFile();

//Main Function
int main()
{
    //declare all variables
    char nameDelete[50];
    char nameInsert[50];
    char id[10];
    int idDelete;
    int i;
    int num;
    struct node *DisplayList;

    //set head equal to NULL
    head = NULL;
    //Read the Data File to put the data in the linked list
    readDataFile();
    //prints out the menu of options for the user
    while(1)
    {
        printf("OPTIONS FOR PROGRAM\n\n");
        printf("1. Insert a new student\n");
        printf("2. Display the list\n");
        printf("3. Delete student by Id\n");
        printf("4. Delete student by Name\n");
        printf("5. Exit program\n");
        printf("Enter your choice : ");


        //if the option entered is not a number, it exits the program and prompts the user to enter a number
        if(scanf("%d", &i) <= 0)
        {
            printf("Enter only a number between 1-5. \n");
            exit(0);

        }
        //if the option entered is a usable number, then we go to the cases.
        else
        {
            //switch function to read in the options for the cases.
            switch(i)
            {
                //option 1 to insert names and the id as a node into the linked list.
                case 1:
                    //prompts the user to insert the name of the person and scans it in.
                    printf("Enter the name to insert: ");
                    scanf(" %[^\n]s", nameInsert);
                    //prompts the user to enter the name of the id for the person, and scans it in.
                    printf("What is the id number for %s? ", nameInsert);
                    scanf(" %[^\n]s", id);
                    //then it inserts the name into the linked list as a node at the end and returns.
                    insert(nameInsert, id);
                    break;
                //option 2 to display the list
                case 2:
                    //if the head is equal to NULL, that means the list is empty and we tell the user.
                    if(head == NULL)
                    {
                        printf("List is Empty\n");
                    }
                    else
                    {
                        //if the list is not empty, then we display the list from the file.
                        printf("Element(s) in the list are : \n");
                        display(DisplayList);
                    }

                    break;
                //option 3 deletes nodes by id
                case 3:
                    //if the head is equal to NULL, then the list is empty and then we tell the user it is empty
                    if(head == NULL)
                        printf("List is Empty\n");
                    else
                    {
                        //prompts the user to enter the ID to be deleted and scans in the data.
                        printf("Enter the ID to delete : ");
                        scanf("%d", &num);
                        //if the id to be deleted exists, then we delete the node that the id is assigned to.
                        //if the id does not exist, then we tell the user and then we return.
                        if(deleteId(num))
                            printf("%d deleted successfully\n", num);
                        else
                            printf("%d not found in the list\n", num);
                    }
                    break;
                //option 4 deletes by name
                case 4:
                    //if the head is equal to NULL, then the list is empty, so we print that out
                    if(head == NULL)
                        printf("List is Empty\n");
                    else
                    {
                        //prompts user to enter the desired name to be deleted and scans it in.
                        printf("Enter the name to delete : ");
                        scanf(" %[^\n]s", nameDelete);
                        //if the name entered is in the linked list, then we delete it and its id and return
                        //if its not in the list then we print out that it is not in the list and return
                        if(deleteName(nameDelete))
                            printf("%s deleted successfully\n", nameDelete);
                        else
                            printf("%s not found in the list\n", nameDelete);
                    }
                    break;
                //exits the program with selection 5.
                case 5:
                    printf("You have chosen to exit the program, Goodbye!\n\n");
                    return 0;
                //the default option when the value given is not an option it prints out that it is invalid.
                default:
                    printf("Invalid Option\n");

            }
        }
    }

    return 0;

}

//delete the node by Id function
int deleteId(int num)
{
    // sets temp and prev struct pointers
    struct node *temp, *prev;
    //sets temp equal to head
    temp = head;
    //while temp is not equal to NULL
    while(temp != NULL)
    {
        //if the id temp is pointing to is the number entered
        if(temp->id == num)
        {
            //if the temp pointer is at the beginning
            if(temp == head)
            {
                //then that means the id we need to delete is at the beginning
                //so we set the head of the list to the next node essentially removing it
                head = temp->next;
                //then we free the space and return
                free(temp);
                return 1;
            }
            else
            {
                //we set the previous pointer to the temporary pointer and free space
                prev->next = temp->next;
                free(temp);
                return 1;
            }
        }
        else
        {
            //if its not the correct id, then we keep traversing the list
            prev = temp;
            temp = temp->next;
        }
    }
    return 0;
}

//deleteName function that deletes nodes by name
int deleteName(char *name)
{
    //sets the temp pointer and the pointer to the previous node
    struct node *temp, *prev;
    //sets temp pointer equal to head
    temp = head;
    //while temp is not equal to NULL
    while(temp != NULL)
    {
        //compare the name the temp pointer is pointing to with the name that name is pointing to.
        if(strcmp(temp->name, name) ==0)
        {
            //if the name is a match, then it prints we found the name
            printf("found %s!\n", name);
            if(temp == head)
            {
                 head = temp->next;
                 free(temp);
                 return 1;
            }
            //when we find the name, we set the next part of prev node, to the next portion of the temp node
            //then we free temp and return with success
            else
            {
                //sets prev next equal to temp next
                prev->next = temp->next;
                //frees temp
                free(temp);
                return 1;
            }
        }
        else
        {
            //the prev pointer goes back to temp, and the temp keeps traversing the list
            prev = temp;
            temp = temp->next;
        }
    }
    return 0;

}

//Display Function to display the list from the file
void display(struct node *displayNode)
{
    //set the displayNode equal to head at the beginning
    displayNode = head;
    //if the displayNode is equal to NULL, then we return.
    if(displayNode == NULL)
    {
        return;
    }
    //if displayNode is not equal to NULL
    while(displayNode != NULL)
    {
        //traverses the linked list and prints out each name and id next to each other
        printf("Student %s has id %d\n", displayNode->name, displayNode->id);
        //the part that actually traverses the list, the above part prints each node
        displayNode = displayNode->next;
    }
    //prints a space after each name to make it more readable
    printf("\n");
}

//function for inserting the name and id of the person
void insert(char *insertName, char *insertId)
{
    //we set 2 temporary pointers to insert in the list
    struct node *temp, * temp2;

    temp = (struct node*)malloc(sizeof(struct node));

    //atoi gets rid of the whitespace characters until the first non-whitespace character is found
    int intId = atoi(insertId);
    //string copy the name temp pointer is pointing too, to insertName
    strcpy(temp->name, insertName);
    temp->id = intId;
    //since we created a new node, the pointer field for the node is at the end of the list so it points to NULL
    temp->next = NULL;
    //if the head pointer is pointing at nothing, then the head pointer is set to the temp pointer
    if(head == NULL)
    {
        head = temp;
    }
    //if the head is not pointing to NULL, then set the 2nd temp pointer too head
    else
    {
        temp2 = head;
        //if the noce after the second temporary pointer is not NULL, we set the second temp pointer to the next node.
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        //sets the next node from temporary pointer 2 to the new temp which is the new node we inserted.
        temp2->next = temp;
    }

}

//Function to read in the data from the file
void readDataFile()
{
    //declare variables
    //set the constant length
    const LENGTH = 50;
    //set the constant character comma
    const char comma[2] = ",";
    char * name;
    char * id;
    char data[LENGTH];
    //sets fileName to the file we need to open which is AssignmentOneInput.txt
    char fileName[] = "AssignmentOneInput.txt";
    //set file pointer
    FILE *ifp;

    //opens the file in read mode so we cant change the file
    ifp = fopen(fileName, "r");

    //while the the is there we execute this function
    while( (fgets(data, LENGTH, ifp) ) != NULL)
    {
        //string token splits the string into "tokens"
        //basically making it easier to remove the comma
        name = strtok(data, comma);

        id = strtok(NULL, comma);
        //inserts the name and id separately to work around the comma
        insert(name, id);
    }
    //we close the file
    fclose(ifp);
}
