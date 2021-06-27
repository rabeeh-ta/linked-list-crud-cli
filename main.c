#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head; // this is the head of the linked list.

// function prototypes
void main_menu();     // print the main UI
void insert_a_node(); // all the INSERTING  FEATURES
void free_memory();   // free() the malloced() memory
void print_list();    // display the linkedlist
int size_of_list();   // return the number of nodes in the linked list

int main()
{
    bool quit = false;

    do
    {
        int choice = 0;

        main_menu(); // print the menu options
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_a_node();
            break;
        case 2:
            printf("\n!!Deleting Part is under construction!!\n");
            break;
        case 3:
            print_list();
            break;
        case 4:
            free_memory();
            quit = true; // exit out of the while loop and also the entire program.
            break;
        default:
            printf("Invalit Input, Select the number associated with the operation.\n");
            main_menu();
            break;
        }

    } while (!quit);
}

// inserting a node to the linked list. Insert to beginning, Ending or to any specific index.
void insert_a_node()
{
    int choice = 0;
    do
    {

        printf("\n-----Inserting Menu-----\n");
        printf("1 -> Insert to Beginning\n");
        printf("2 -> Insert to Ending\n");
        printf("3 -> Insert by Index Value\n");
        printf("4 -> Return to Main Menu\n");
        printf("\n");
        printf("Enter the Number from the menu ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            return;
        }

    } while (choice > 5 || choice == 0); // 0 and anything above 4 is invalid

    // get the value to store in linked list
    int data; // user input to store in linked list
    printf("\nEnter the data to store in linked list (datatype int) ");
    scanf("%d", &data);

    // make the node to add
    node *n;
    n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    // Insert data to the linked list
    if (head == NULL) // if the list has only one item
    {
        head = n;
    }
    else // list has atleast one item
    {

        if (choice == 1) // insert to the begging of the list
        {
            node *temp;
            temp = head;
            head = n;
            head->next = temp;
        }
        else if (choice == 2) // insert to the Ending of the list
        {
            // get the ending node
            node *lastNode = head;
            while (lastNode->next != NULL)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = n;
        }
        else if (choice == 3) // insert to the index given
        {
            int index;
            printf("\nAt what index from 1 to %i would you like to add this node ", size_of_list());
            scanf("%i", &index);

            // the inserting to the index position part
            node *currentNode = head;
            node *previousNode = head;
            for (int i = 1; currentNode != NULL; i++)
            {
                if (i == index) // insert n node at this place
                {
                    for (int j = 2; j < index; j++) // the previous node of index.
                    {

                        previousNode = previousNode->next;
                    }

                    n->next = currentNode;
                    previousNode->next = n;
                    break; // job done get out of the loop
                }
                currentNode = currentNode->next;
            }
        }
    }
}

// this is the starting menu interface
void main_menu()
{
    printf("\n---------Main Menu---------\n");
    printf("1 -> Insert\n");
    printf("2 -> Delete\n");
    printf("3 -> View Linked List\n");
    printf("4 -> Quit\n");
    printf("\n");
    printf("Enter the Number from the menu ");
}

void print_list()
{
    printf("\n\n---- linked-list <size %i> ----\n", size_of_list());
    for (node *i = head; i != NULL; i = i->next)
    {
        printf("%i \n", i->data);
    }
}

int size_of_list()
{
    int count = 0;
    node *counterNode = head;
    while (counterNode != NULL)
    {
        counterNode = counterNode->next;
        count++;
    }
    return count;
}

void free_memory()
{
    node *cursor = head;
    node *temp = head;

    while (cursor != NULL)
    {
        cursor = cursor->next;
        free(temp);
        temp = cursor;
    }
}
