#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// linked-list node.
typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL; // this is the head of the linked list.

// function prototypes
void main_menu();
void insert_a_node();
void free_memory();
void print_linked_list();

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
            printf("do the Deleting part\n");
            break;
        case 3:
            print_linked_list();
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

// this is the starting menu interface
void main_menu()
{
    printf("-----Main Menu-----\n");
    printf("\n");
    printf("1 -> Insert\n");
    printf("2 -> Delete\n");
    printf("3 -> View Linked List\n");
    printf("4 -> Quit\n");
    printf("\n");
    printf("Enter the Number from the menu ");
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

    // make a node and get the value for the in to the node
    node *n;
    n = malloc(sizeof(node));

    // get the value to store in linked list
    int data; // user input to store in linked list
    printf("Enter the data to store in linked list (datatype int) ");
    scanf("%d", &data);

    // put the data to the node
    n->data = data;
    n->next = NULL;

    // now insert this to the linked list
    if (choice == 1) // insert to the begging of the list
    {
        node *temp = head; // store the starting part
        head = n;          // head is the new node
        n->next = temp;    // then the list starts after the new node
    }
    else if (choice == 2) // insert to the begging of the list
    {
        node *i = head;
        for (i != NULL; i = i->next;)
        {
            continue;
        }
        // now i is the last node
        i->next = n;
    }
    free(n);
}
