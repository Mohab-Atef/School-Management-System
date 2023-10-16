#include "header.h"

/* Display the main menu of the school management system */
void MAIN_MENU (){

    /*Print a horizontal line of asterisks to create a visual separator*/
        printf("**************************************\n");
    /* Print a header line for the main menu with the system name */
        printf("|   School Management System Menu    |\n");
    /* Print another horizontal line of asterisks then dashes as a separator */
        printf("**************************************\n");
        printf("*------------------------------------*\n");
    /* Print options for various actions the user can take */
        printf("|  1. Add New Student                |\n");
        printf("|  2. Delete Student                 |\n");
        printf("|  3. List Students                  |\n");
        printf("|  4. Edit Student Details           |\n");
        printf("|  5. Rank Students by CS Score      |\n");
        printf("|  6. Update Student Scores          |\n");
        printf("|  0. Exit                           |\n");
    /* Print another horizontal line of asterisks with dashes as a separator */
        printf("*------------------------------------*\n");
    /* Prompt the user to enter their choice */
        printf("Enter your choice: ");
}

/* Helper function to insert a new student into the tree */
ACCOUNT* insertStudent(ACCOUNT* root, ACCOUNT* newStudent) {
    /* Check if the current root node is NULL (empty tree)*/
    if (root == NULL) {
        /* If the tree is empty, simply return the new student as the new root */
        return newStudent;
    }
    else{

    /* Check if the new student's ID is less than the current root's ID*/
        if (newStudent->id < root->id) {
            /* If the new student's ID is smaller, recursively insert it into the left subtree */
            root->left = insertStudent(root->left, newStudent); /*recursion to the left child*/
        } else if (newStudent->id > root->id) {
            /* If the new student's ID is larger, recursively insert it into the right subtree */
            root->right = insertStudent(root->right, newStudent); /*recursion to the right child*/
        }
        else{
                /*If The new student's id is taken print that messege */
                printf("This Id Is Taken , please Try Another One \n");
        }
    /* Return the current root node (with potential modifications) */
    return root;}
}

/*This function allows the user to input details for a new student
    and returns a pointer to the created student structure */
ACCOUNT* NEW_STUDENT() {
    /* Allocate memory for a new student structure and assign it to 'newStudent' */
    ACCOUNT* newStudent = (ACCOUNT*)malloc(sizeof(ACCOUNT));
    /* Check if memory allocation was successful */
    if (newStudent == NULL) {
    /* Handle memory allocation failure by returning NULL,
        This indicates that the function failed to create a new student*/
        return NULL;
    }
    else {
        /* Prompt the user to enter student details */
        printf("Enter student details:\n");
        printf("ID: ");
        scanf("%d", &newStudent->id);
        /* Clear any remaining characters from the input buffer (stdin)*/
        fflush(stdin);

        /*Prompt for and read the student name*/
        printf("Name: ");
        fgets(newStudent->name, sizeof(newStudent->name), stdin);
        /* Remove the trailing newline character from the name */
        newStudent->name[strcspn(newStudent->name, "\n")] = '\0';
        /* Clear any remaining characters from the input buffer (stdin)*/
        fflush(stdin);

        /* Prompt for and read the student date of birth */
        printf("Date of Birth: ");
        fgets(newStudent->dob, sizeof(newStudent->dob), stdin);
        /* Remove the trailing newline character from the dob */
        newStudent->dob[strcspn(newStudent->dob, "\n")] = '\0';
        /* Clear any remaining characters from the input buffer (stdin)*/
        fflush(stdin);

        /* Prompt for and read the student address*/
        printf("Address: ");
        fgets(newStudent->address, sizeof(newStudent->address), stdin);
        /* Remove the trailing newline character from the address */
        newStudent->address[strcspn(newStudent->address, "\n")] = '\0';
        /* Clear any remaining characters from the input buffer (stdin)*/
        fflush(stdin);

        /* Prompt for and read the student phone number */
        printf("Phone: ");
        fgets(newStudent->phone, sizeof(newStudent->phone), stdin);
        /* Remove the trailing newline character from the phone number */
        newStudent->phone[strcspn(newStudent->phone, "\n")] = '\0';
        /* Clear any remaining characters from the input buffer (stdin)*/
        fflush(stdin);

        /* Prompt for and read the student science score */
        printf("Computer Science Score: ");
        scanf("%lf", &newStudent->csScore);
        /* Clear any remaining characters from the input buffer (stdin)*/
        fflush(stdin);

        /* Initialize left and right pointers of the new student to NULL */
        newStudent->left = NULL;
        newStudent->right = NULL;

        /* Return a pointer to the newly created student structure*/
        return newStudent;}
}

/* Function to search for a student by ID */
ACCOUNT* SEARCH_STUDENT(ACCOUNT* root, int id) {
/* Check if the current root node is NULL */
    if (root == NULL) {
/* If the tree is empty or the student is not found , return NULL */
        return NULL; /* Student not found */
    }
    else{
    /* Check if the ID being searched matches the ID of the current root node */
        if (root->id < id) {
                /* If the ID is greater than the current root's ID, search in the right subtree */
            return SEARCH_STUDENT(root->right, id);
        } else if (root->id > id) {
            /* If the ID is smaller than the current root's ID, search in the left subtree */
            return SEARCH_STUDENT(root->left, id);
        } else {
            /* If the ID matches the current root's ID, return a pointer to the found student */
            return root;  /* Student found */
                }
        }
}

/* Function to delete a student by ID (recursive) */
ACCOUNT* deleteStudent(ACCOUNT* root, int id) {
    /* Check if the current root node is NULL */
    if (root == NULL) {
    /* If the student is not found, return NULL .
    In this case, we didn't find the student in the tree*/
        return root;
    }
    else{
        /* Check if the ID being searched is less than the current root's ID */
        if (id < root->id) {
                /* If the ID is smaller, recursively delete in the left subtree */
            root->left = deleteStudent(root->left, id);
        /* Check if the ID being searched is greater than the current root's ID */
        } else if (id > root->id) {
            /* If the ID is greater, recursively delete in the right subtree */
            root->right = deleteStudent(root->right, id);
        } else {
            /* If the ID matches the current root's ID */
            if (root->left == NULL) {
                /* If the left child is NULL, assign the right child to the current root
                    We have to replace the current node with its right child (if it exists)
                    This is because there is no left subtree to promote */
                ACCOUNT* temp = root->right;
                /* Free the memory occupied by the current root node */
                free(root);
                /* Return the right child (or NULL if it doesn't exist) as the new root of the subtree */
                return temp;
            } else if (root->right == NULL) {
                /* If the right child is NULL, assign the left child to the current root
                    We have to replace the current node with its left child (if it exists)
                    This is because there is no right subtree to promote */
                ACCOUNT* temp = root->left;
                /* Free the memory occupied by the current root node */
                free(root);
                /* Return the left child (or NULL if it doesn't exist) as the new root of the subtree */
                return temp;
            }
            else {
            /* If both left and right children are present
                Initialize a temporary pointer with the right child*/
                ACCOUNT* temp = root->right;
                while (temp->left != NULL) {
                        /* Find the leftmost (smallest) child in the right subtree */
                    temp = temp->left;
                }
                /* Replace the current root's data with the data of the leftmost child of the right subtree */
                root->id = temp->id;
                strcpy(root->name, temp->name);
                strcpy(root->dob, temp->dob);
                strcpy(root->address, temp->address);
                strcpy(root->phone, temp->phone);
                root->csScore = temp->csScore;
                /* Recursively delete the leftmost child of the right subtree */
                root->right = deleteStudent(root->right, temp->id);
                }}
    /* Return the current root (with potential modifications) */
        return root;}
}

/* Function to delete a student by ID (wrapper function) */
void DELETE_STUDENT(ACCOUNT** root, int id) {
    /* Search for the student with the specified ID in the tree */
    ACCOUNT* studentToDelete = SEARCH_STUDENT(*root, id);

    if (studentToDelete == NULL) {
    /* If the student with the given ID is not found, print a message and return */
        printf("Student with ID %d not found please make sure that you type it correctly.\n", id);
        return;
    }
    else{

        /* Call the deleteStudent function to perform the actual deletion */
        *root = deleteStudent(*root, id);
        /* Print a message indicating that the student has been successfully deleted */
        printf("Student with ID %d has been deleted.\n", id);}
}

/* Function to compare student names for qsort */
int compareNames(const void* a, const void* b) {
/* Cast the input pointers to pointers to struct Student */
    ACCOUNT* studentA = *((ACCOUNT**)a);
    ACCOUNT* studentB = *((ACCOUNT**)b);
    /* Used strcmp to compare the names of studentA and studentB
    lexoraphically , then return (negative number , positive number or zero)
    according the result of comparison*/
    return strcmp(studentA->name, studentB->name);
}

/* Helper function to populate students array and count (in-order traversal) */
void STUDENT_LIST_SORT(ACCOUNT* root, ACCOUNT* students[], int* count) {
    if (root == NULL) {
    /* If the current node is NULL, return without further processing */
        return;
    }
    else{
        /* Recursively traverse the left subtree (in-order traversal) */
        STUDENT_LIST_SORT(root->left, students, count);
        /* Store a pointer to the current student in the students array */
        students[*count] = root;
        /* Increment the count to keep track of the number of students */
        (*count)++;
        /* Recursively traverse the right subtree (in-order traversal) */
        STUDENT_LIST_SORT(root->right, students, count);}
}

/* Function to list all students (in-order traversal and sorted by names)*/
void STUDENT_LIST(ACCOUNT* root) {
    /* If the tree is empty (no students), return without further processing */
    if (root == NULL) {
        return;
    }
    else{
    /* Array to store pointers to students*/
        ACCOUNT* students[100];
        int count = 0;

        /* Populate the students array */
        STUDENT_LIST_SORT(root, students, &count);

        /* Sort the students array by names using the compareNames function  */
        qsort(students, count, sizeof(ACCOUNT*), compareNames);
        /* Print the table header */
        printf("+----+-------------------+--------------+-------------------------+------------------+\n");
        printf("| ID | Name              | Date of Birth| Address                 | Phone            |\n");
        printf("+----+-------------------+--------------+-------------------------+------------------+\n");
        /* Iterate through the sorted array and print student details */
        for (int i = 0; i < count; i++) {
            printf("| %2d | %-17s | %-12s | %-23s | %-16s |\n", students[i]->id, students[i]->name, students[i]->dob, students[i]->address, students[i]->phone);
            }
            /* Print the table footer */

        printf("+----+-------------------+--------------+-------------------------+------------------+\n");}
}

/* Function to edit student details by ID */
void STUDENT_EDIT(ACCOUNT* root, int id) {
    /* Search for the student with the given ID in the binary search tree */
    ACCOUNT* student = SEARCH_STUDENT(root, id);
    if (student == NULL) {
/* If the student with the given ID is not found, print a message and return*/
        printf("Student with ID %d not found.\n", id);
        return;
    }
    else{
        /* Display an editing menu for the user */
        printf("*-----------------------------------*\n");
        printf("| Editing student with ID %d        |\n", id);
        printf("*-----------------------------------*\n");
        printf("| 1. Name                           |\n");
        printf("| 2. Date of Birth                  |\n");
        printf("| 3. Address                        |\n");
        printf("| 4. Phone                          |\n");
        printf("| 5. Computer Science Score         |\n");
        printf("| 0. Cancel                         |\n");
        printf("*-----------------------------------*\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        /* Clear any remaining characters from the input buffer (stdin)*/
        fflush(stdin);
        switch (choice) {
            /* Edit student's name */
            case 1:
                printf("Enter new name: ");
                fgets(student->name, sizeof(student->name), stdin);
                /* Remove the trailing newline character from the name */
                student->name[strcspn(student->name, "\n")] = '\0';
                /* Clear any remaining characters from the input buffer (stdin)*/
                fflush(stdin);
                break;
            /*Edit student's date of birth*/
            case 2:
                printf("Enter new date of birth: ");
                fgets(student->dob, sizeof(student->dob), stdin);
                /* Remove the trailing newline character from the date of birth */
                student->dob[strcspn(student->dob, "\n")] = '\0';
                /* Clear any remaining characters from the input buffer (stdin)*/
                fflush(stdin);
                break;
            /*Edit student's address*/
            case 3:
                printf("Enter new address: ");
                fgets(student->address, sizeof(student->address), stdin);
                /* Remove the trailing newline character from the address */
                student->address[strcspn(student->address, "\n")] = '\0';
                /* Clear any remaining characters from the input buffer (stdin)*/
                fflush(stdin);
                break;
            /*Edit student's phone number*/
            case 4:
                printf("Enter new phone: ");
                //scanf("%s", student->phone);
                fgets(student->phone, sizeof(student->phone), stdin);
                /* Remove the trailing newline character from the phone number */
                student->phone[strcspn(student->phone, "\n")] = '\0';
                /* Clear any remaining characters from the input buffer (stdin)*/
                fflush(stdin);
                break;
            /*Edit student's Computer Science Score*/
            case 5:
                printf("Enter new Computer Science Score: ");
                scanf("%lf", &student->csScore);
                /* Clear any remaining characters from the input buffer (stdin)*/
                fflush(stdin);
                break;
            /*Cancel editing*/
            case 0:
                printf("Editing canceled.\n");
                break;
            default:
                /* Invalid choice */
                printf("Invalid choice.\n");}
    }
}

/* helper Comparison function to compare students based on CS scores (descending order)*/
int compareCS(const void* a, const void* b) {
    /* Convert the void pointers back to pointers to struct Student */
    ACCOUNT* studentA = *((ACCOUNT**)a);
    ACCOUNT* studentB = *((ACCOUNT**)b);

    if (studentA->csScore > studentB->csScore) {
    /* Return -1 to indicate that studentA comes before studentB (descending order)*/
        return -1;
    } else if (studentA->csScore < studentB->csScore) {
    /* Return 1 to indicate that studentB comes before studentA (descending order) */
        return 1;
    }
    else{
    /* Return 0 if the CS scores are equal (no change in order) */
        return 0;}
}

/* Helper function to populate students array and count (in-order traversal)*/
void RANK_STUDENT_SORT(ACCOUNT* root, ACCOUNT* students[], int* count) {
    if (root == NULL) {
    /* If the current node is NULL, return without further processing */
        return;
    }
    else{
    /* Recursively traverse the left subtree (in-order traversal) */
        RANK_STUDENT_SORT(root->left, students, count);
    /* Store a pointer to the current student in the students array */
        students[*count] = root;
    /* Increment the count to keep track of the number of students */
        (*count)++;
    /* Recursively traverse the right subtree (in-order traversal) */
        RANK_STUDENT_SORT(root->right, students, count);}
}

/* Function to rank students based on CS score (in-order traversal with ranking) */
void RANK_STUDENT(ACCOUNT* root) {
    if (root == NULL) {
    /*If the root of the tree is NULL (empty tree), return without further processing*/
        return;
    }
    else{
    /* Array to store pointers to students */
        ACCOUNT* students[100];
    /* Initialize the count of students to 0 */
        int count = 0;

        /* Populate the students array */
        RANK_STUDENT_SORT(root, students, &count);

        /* Sort the students array by CS scores (descending order) */
        qsort(students, count, sizeof(ACCOUNT*), compareCS);
        /* Display the ranked students */
        printf("+-----+-------------------+-----------+\n");
        printf("| Rank| Name              | CS Score  |\n");
        printf("+-----+-------------------+-----------+\n");

        for (int i = 0; i < count; i++) {
        /* Print each student's rank, name, and CS score */
            printf("| %3d | %-17s | %-9.2lf |\n", i + 1, students[i]->name, students[i]->csScore);
        }
        /* Display the end of the table */
        printf("+-----+-------------------+-----------+\n");}
}

/* Helper function to update student scores (in-order traversal) */
void STUDENT_SCORE_UPDATE(ACCOUNT* root) {
    if (root == NULL) {
    /* If the current node is NULL, return without further processing */
        return;
    }
    else{
        /* Recursively update scores in the left subtree */
        STUDENT_SCORE_UPDATE(root->left);
        /* declare a newScore variable to store the updated CS score */
        double newScore;
        printf("Enter updated CS score for student %s (ID %d): ", root->name, root->id);
        scanf("%lf", &newScore);
        /* Clear any remaining characters from the input buffer (stdin)*/
        fflush(stdin);
        /*Update the CS score of the current student*/
        root->csScore = newScore;
        /*Recursively update scores in the right subtree*/
        STUDENT_SCORE_UPDATE(root->right);
        printf("Scores updated.\n");}}
/* Function to free the memory occupied by the binary search tree */

void FREE_TREE(ACCOUNT* root) {
    if (root == NULL) {
    /* If the current node is NULL, return without further processing */
        return;
    }
    else{
    /*Recursively free memory for the left subtree*/
        FREE_TREE(root->left);
    /*Recursively free memory for the right subtree*/
        FREE_TREE(root->right);
    /*Free memory for the current node*/
        free(root);}
}
