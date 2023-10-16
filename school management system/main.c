#include "header.h"

int main() {
    /* Initialize the root of the BST as NULL */
    struct Student* root = NULL;
    int choice, id;

    do {
    /* Display the main menu */
        MAIN_MENU ();
    /* Read the user's choice */
        scanf("%d", &choice);
    /* Clear any remaining characters from the input buffer (stdin)*/
        fflush(stdin);

        switch (choice) {
            case 1:     /* Add a new student to the BST */
                root = insertStudent(root, NEW_STUDENT());
                break;
            case 2:     /* Delete a student by ID */
                printf("Enter ID of student to delete: ");
                scanf("%d", &id);
            /* Clear any remaining characters from the input buffer (stdin)*/
                fflush(stdin);
                DELETE_STUDENT(&root, id);
                break;
            case 3:     /* List all students sorted by name */
                STUDENT_LIST(root);
                break;
            case 4:     /* Edit student details by ID */
                printf("Enter ID of student to edit: ");
                scanf("%d", &id);
            /* Clear any remaining characters from the input buffer (stdin)*/
                fflush(stdin);
                STUDENT_EDIT(root, id);
                break;
            case 5:     /* Rank students by CS score */
                RANK_STUDENT(root);
                break;
            case 6:     /* Update student scores */
                STUDENT_SCORE_UPDATE(root);
                break;
            case 0:     /* Exit the program */
                printf("\n Exiting...\n\n");
                printf("Thanks For Using Our School Management System :) \n");
                break;
            default:    /* Handle invalid input */
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    /* Free memory before exiting */
    FREE_TREE(root);

    return 0;
}

