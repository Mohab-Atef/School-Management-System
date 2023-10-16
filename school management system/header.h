#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to represent a Student */
typedef struct Student {
    int id;                 /* Student ID */
    char name[50];          /* Student name */
    char dob[20];           /* Date of birth */
    char address[100];      /* Student address */
    char phone[15];         /* Student phone number */
    double csScore;         /* Computer Science Score */
    struct Student* left;   /* Pointer to the left child */
    struct Student* right;  /* Pointer to the right child */
}ACCOUNT;


/* Helper Function prototypes*/

/* Function to insert a new student into the tree */
ACCOUNT* insertStudent(ACCOUNT* root, ACCOUNT* newStudent);
/*Function to search for a student by ID*/
ACCOUNT* SEARCH_STUDENT(ACCOUNT* root, int id);
/*Function to delete a student by ID (recursive)*/
ACCOUNT* deleteStudent(ACCOUNT* root, int id);
/*Function to populate students array and count (in-order traversal)*/
void RANK_STUDENT_SORT(ACCOUNT* root, ACCOUNT* students[], int* count);
/*Function to compare Names (ascending order)*/
int compareNames(const void* a, const void* b);
/* Function to populate students array and count (in-order traversal) */
void STUDENT_LIST_SORT(ACCOUNT* root, ACCOUNT* students[], int* count);
/*Function to compare CS scores (descending order)*/
int compareCS(const void* a, const void* b);

/*main function prototypes*/

/* Function displays the welcome screen and targeted activates */
void MAIN_MENU ();
/* Function to create a new student */
ACCOUNT* NEW_STUDENT();
/* Function to delete a student by ID (wrapper function) */
void DELETE_STUDENT(ACCOUNT** root, int id);
/* Function to list all students (sorted by names) */
void STUDENT_LIST(ACCOUNT* root);
/* Function to edit student details by ID */
void STUDENT_EDIT(ACCOUNT* root, int id);
/* Function to rank students based on CS score */
void RANK_STUDENT(ACCOUNT* root);
/*Function to update student scores (in-order traversal)*/
void STUDENT_SCORE_UPDATE(ACCOUNT* root);
/* Function to free memory occupied by the binary search tree */
void FREE_TREE(ACCOUNT* root);

#endif

