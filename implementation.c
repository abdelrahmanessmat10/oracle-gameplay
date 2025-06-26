#include "game.h"
int choice;

struct node* read_tree(FILE* fptr){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    char str[MAX];
    fgets(str, MAX, fptr);
    str[strcspn(str, "\n")] = '\0';
    if(!strcmp(str, "#")) return NULL;
    strcpy(n->question_or_course, str);
    n->yes = read_tree(fptr);
    n->no = read_tree(fptr);
    return n;
}

void play(struct node* root){
    if(root->yes != NULL && root->no != NULL){
        printf("%s (yes/no): ", root->question_or_course);
    }
    char answer[100];
    if(root->yes != NULL && root->no != NULL){
        while(gets(answer)){
            if(!strcmp(answer, "yes") || !strcmp(answer, "YES") || !strcmp(answer, "Yes")){
                play(root->yes);
                break;
            }
            else if(!strcmp(answer, "no") || !strcmp(answer, "NO")  || !strcmp(answer, "No")){
                play(root->no);
                break;
            }
            else{
                printf("Enter a valid answer (yes/no): ");
            }
        }
    }
    else{
            printf("Is it %s? (yes/no): ", root->question_or_course);
            while(gets(answer)){
                if(!strcmp(answer, "yes") || !strcmp(answer, "YES") || !strcmp(answer, "Yes")){
                    printf("\nEasy! I guessed correctly!\n");
                    break;
                }
                else if(!strcmp(answer, "no") || !strcmp(answer, "NO")  || !strcmp(answer, "No")){
                    if(choice == 1){
                        printf("\nDamn it! I don't know, What is the course?\n");
                    }
                    else{
                        printf("\nDamn it! I don't know, Who is the character?\n");
                    }
                    update_tree(root);
                    break;
                }
                else printf("Enter a valid answer (yes/no): ");
            }
    }
}

void update_tree(struct node* root){
    char newCourse[100], question[MAX], oldCourse[100];
    strcpy(oldCourse, root->question_or_course);
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    struct node* oldNode = (struct node*) malloc(sizeof(struct node));
    gets(newCourse);
    printf("Enter a question to distinguish between %s and %s:\n", root->question_or_course, newCourse);
    gets(question);
    strcpy(newNode->question_or_course, newCourse);
    strcpy(root->question_or_course, question);
    strcpy(oldNode->question_or_course, oldCourse);
    root->yes = newNode;
    root->no = oldNode;
}

void save_tree(FILE* fptr, struct node* root){
    if(root == NULL){
        fprintf(fptr, "#\n");
        return;
    }
    fprintf(fptr, "%s\n", root->question_or_course);
    save_tree(fptr, root->yes);
    save_tree(fptr, root->no);
}

void free_tree(struct node* root){
    if(root == NULL) return;
    free_tree(root->yes);
    free_tree(root->no);
    free(root);
}
