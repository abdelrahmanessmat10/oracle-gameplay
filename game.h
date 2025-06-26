#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct node {
    char question_or_course[MAX];
    struct node* yes;
    struct node* no;
};

struct node* read_tree(FILE* fptr);             /* this function loads the tree info from the file
                                                it takes the file as an input and outputs the root node */

void play(struct node* root);                   /* this function prints the question/course/character of the nodes
                                                   while navigating through the tree until reaching a final answer,
                                                   it takes the root of the tree as an input and outputs nothing */

void update_tree(struct node* root);            /* this function is responsible for learning, it updates the tree with
                                                    the new info it learns from the user after guessing wrong, it takes
                                                    the node of the wrong guessed course as an input (and inside the
                                                    function it takes the new course and its question from the user) and outputs nothing */

void save_tree(FILE* fptr, struct node* root);  /* this function saves the updated data into the txt file */

void free_tree(struct node* root);              /* this function frees each node of the tree */

#endif // GAME_H
