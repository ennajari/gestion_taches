#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

typedef struct {
    char description[100];
    int is_completed;
} Task;

void print_menu() {
    printf("\nGestionnaire de tâches\n");
    printf("1. Ajouter une tâche\n");
    printf("2. Afficher les tâches\n");
    printf("3. Marquer une tâche comme accomplie\n");
    printf("4. Supprimer une tâche\n");
    printf("5. Quitter\n");
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    int choice;
    do {
        print_menu();
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_tasks < MAX_TASKS) {
                    printf("Entrez la description de la tâche : ");
                    scanf(" %[^\n]", tasks[num_tasks].description);
                    tasks[num_tasks].is_completed = 0;
                    num_tasks++;
                } else {
                    printf("La liste de tâches est pleine.\n");
                }
                break;

            case 2:
                printf("Liste des tâches :\n");
                for (int i = 0; i < num_tasks; i++) {
                    printf("%d. [%c] %s\n", i + 1, tasks[i].is_completed ? 'x' : ' ', tasks[i].description);
                }
                break;

            case 3:
                printf("Entrez le numéro de la tâche à marquer comme accomplie : ");
                int task_num;
                scanf("%d", &task_num);
                if (task_num > 0 && task_num <= num_tasks) {
                    tasks[task_num - 1].is_completed = 1;
                    printf("Tâche marquée comme accomplie.\n");
                } else {
                    printf("Numéro de tâche invalide.\n");
                }
                break;

            case 4:
                printf("Entrez le numéro de la tâche à supprimer : ");
                scanf("%d", &task_num);
                if (task_num > 0 && task_num <= num_tasks) {
                    for (int i = task_num - 1; i < num_tasks - 1; i++) {
                        tasks[i] = tasks[i + 1];
                    }
                    num_tasks--;
                    printf("Tâche supprimée.\n");
                } else {
                    printf("Numéro de tâche invalide.\n");
                }
                break;

            case 5:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez sélectionner une option valide.\n");
        }

    } while (choice != 5);

    return 0;
}
