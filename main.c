#include "game.h"

struct node* root;
int choice;        // variable to select the mode of the game (Courses/Characters)

int main(){
    FILE* fptr;
    printf("Welcome to the game\nChoose an option:\n1. Play \n2. Quit\n");
    int option;   // variable for selecting whether to play the game or to quit
    while(scanf("%d", &option)){
        getchar();
        if(option == 1){
            printf("Select the mode:\n1. Courses\n2. Characters\n");
            while(scanf("%d", &choice)){
                getchar();
                if(choice == 1){
                fptr = fopen("tree_data.txt", "r");
                    root = read_tree(fptr);
                    play(root->yes);
                    break;
                }
                else if(choice == 2){
                   fptr = fopen("tree_data.txt", "r");
                    root = read_tree(fptr);
                    play(root->no);
                    break;
                }
                else{
                    printf("Enter a valid option(1 or 2): ");
                }
            }
            break;
        }
        else if(option == 2){
            printf("Thanks for playing!");
            fclose(fptr);
            free_tree(root);
          break;

        }
        else{
            printf("Enter a valid option (1 or 2): ");
        }
    }
    while(1){
        printf("\nChoose an option:\n1. Play Again \n2. Quit\n");
        scanf("%d", &option);
        getchar();
        if(option == 1){
            printf("Select the mode:\n1. Courses\n2. Characters\n");
            while(scanf("%d", &choice)){
                getchar();
                if(choice == 1){
                    play(root->yes);
                    break;
                }
                else if(choice == 2){
                    play(root->no);
                    break;
                }
                else{
                    printf("Enter a valid option(1 or 2): ");
                }
            }
        }
        else if(option == 2){
            printf("Thanks for playing!");
            fclose(fptr);
            fptr = fopen("tree_data.txt", "w");
            save_tree(fptr, root);
            fclose(fptr);
            free_tree(root);
            break;
        }
        else{
            printf("Enter a valid option (1 or 2)");
            continue;
        }
    }
    return 0;
}
