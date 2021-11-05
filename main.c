#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head; // has the address of the first node of the linked list

// function prototypes
void main_menu();           // print the main UI
void insert_a_node();       // all the INSERTING  FEATURES
void delete_a_node();       // all the INSERTING  FEATURES
void free_memory();         // free() the malloced() memory
void print_list();          // display the linkedlist
int size_of_list();         // return the number of nodes in the linked list
void reverse_linked_list(); // reverse the given linked list;

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
            delete_a_node();
            break;
        case 3:
            print_list();
            break;
        case 4:
            reverse_linked_list();
            break;
        case 5:
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

//? this function will do everything with deleting option
// delete one, delete end, delete by index value

void delete_a_node()
{
    int choice = 0;
    do
    {

        printf("\n-----Inserting Menu-----\n");
        printf("1 -> Delete One in Beginning\n");
        printf("2 -> Delete One in Ending\n");
        printf("3 -> Delete by Index Value\n");
        printf("4 -> Return to Main Menu\n");
        printf("\n");
        printf("Enter the Number from the menu ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            return;
        }

    } while (choice > 5 || choice == 0); // 0 and anything above 4 is invalid

    //! first check if there is something in the linked list
    if (size_of_list() == 0)
    {
        printf("\n\nLinked list is Empty\n\n");
        return;
    }
    else // there is more than one node you can delete endnode startnode or indexnode.
    {
        if (choice == 1) // delete one in deggening
        {
            //! what if there is only one node in list
            if (size_of_list() == 1) // End and Beggining is one node
            {
                head = NULL;
                free(head);
                return;
            }

            node *firstNode = head;
            head = firstNode->next; // head is set to what is next of first node
            free(firstNode);
        }
        else if (choice == 2)
        {

            //! what if there is only one node in list
            if (size_of_list() == 1) // End and Beggining is one node
            {
                head = NULL;
                free(head);
                return;
            }

            node *lastNodesPrevious = head;
            while (lastNodesPrevious->next->next != NULL)
            {

                lastNodesPrevious = lastNodesPrevious->next;
            }

            node *lastNode = lastNodesPrevious->next;
            lastNodesPrevious->next = NULL; // delete reference of last node from the list
            free(lastNode);                 // delete last node
        }
        else if (choice == 3)
        {
            int index;
            printf("\nAt what index from 1 to %i would you like to add this node ", size_of_list());
            scanf("%i", &index);

            //? if check if first one
            if (index == 1)
            {
                node *firstNode = head;
                head = firstNode->next; // head is set to what is next of first node
                free(firstNode);
            }
            else if (index >= 2 && size_of_list() >= index) // any other node
            {
                node *nodeBDN = head; // nodeBeforeDeleteNode
                node *deleteNode;
                int i = 1;
                while (i != index - 1)
                {
                    nodeBDN = nodeBDN->next;
                    i++;
                }
                deleteNode = nodeBDN->next;
                nodeBDN->next = deleteNode->next;
                free(deleteNode);
            }
        }
    }
}

//? inserting a node to the linked list. Insert to beginning, Ending or to any specific index.

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
    if (head == NULL) // if the list is empty
    {
        head = n;
    }
    else // list has atleast one item
    {

        // all the features start here

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

            if (index == 1) // add to the first index
            {
                node *temp;
                temp = head;
                head = n;
                head->next = temp;
            }
            else // any other index
            {
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
}

//!-------------- helper functions----------------//

// this is the starting menu interface
void main_menu()
{
    printf("\n---------Main Menu---------\n");
    printf("1 -> Insert\n");
    printf("2 -> Delete\n");
    printf("3 -> View Linked List\n");
    printf("4 -> Reverse the Linked List\n");
    printf("5 -> Quit\n");
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

void reverse_linked_list()
{
    node *prev, *next, *cursor;
    cursor = head;
    next = head;
    prev = NULL;

    while (cursor->next != NULL)
    {
        // printf("%i ", cursor->data);
        // cursor = cursor->next;
        next = cursor->next;
        cursor->next = prev;
        prev = cursor;
        cursor = next;
        printf("looped count\n");
    }
    head = cursor;
}
