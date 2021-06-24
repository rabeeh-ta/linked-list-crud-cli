#include <stdio.h>
#include <stdbool.h>

void main_menu();

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
            printf("do the inserting part\n");
            break;
        case 2:
            printf("do the Deleting part\n");
            break;
        case 3:
            printf("do the Listing the whole linked list part\n");
            break;
        case 4:
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
    printf("3 -> View\n");
    printf("4 -> Quit\n");
    printf("\n");
    printf("Enter the Number from the menu ");
}