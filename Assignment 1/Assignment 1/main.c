#include <stdio.h>
#include "header.h"

int main (void)
{
    // asks the user how many users they would like to make 
	printf("How many users would you like to create?");
	int Numberofusers;
    if (scanf_s("%d", &Numberofusers) != 1) {
        printf("Invalid input\n");
        return exit();
    }

    // ititalizing the queue
	struct queue Queue;
	initializeQueue(&Queue);

    // inserting users into the queue and returning an error if an error is encountered
    if (insertUsers(&Queue, Numberofusers) != 0) {
        printf("Error occurred while enqueuing users\n");
        return exit();
    }

    // will print all the users until the queue is empty
    while (!isQueueEmpty(&Queue)) {
        struct user user = removeFromQueue(&Queue);
        printf("Dequeued User: Username=%s, Level=%d, Faction=%s\n", user.userName, user.userLevel, user.userFaction);
    }

    return 0;
}