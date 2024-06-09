#include <stdio.h>
#include "header.h"
#include <stdlib.h>

// initialize a blank queue
void initializeQueue(struct queue* q) {
	q->head = NULL;
	q->tail = NULL;
}

// checks if queue is empty
int isQueueEmpty(struct queue* q) {
	return q->head == NULL;
}

// add new node to the end of the queue
void addToQueue(struct queue* q, struct user u) {
	struct queueNode* newNode = (struct queueNode*)malloc(sizeof(struct queueNode));  // Allocate memory for a new node
	
	// set user data and points to NULL since it is the end of the queue
	newNode->data = u;
	newNode->pNext = NULL;

	// if queue is empty both head and tail point to newNode
	if (isQueueEmpty(q)) {
		q->head = newNode;
		q->tail = newNode;
	}

	// if queue is not empty it will link the tail to the new node and update the tail to be the new node
	else
	{
		q->tail->pNext = newNode;
		q->tail = newNode;
	}
}

// remove node from the queue
struct user removeFromQueue(struct queue* q) {
	// check is the queue is empty
	if (isQueueEmpty(q))
	{
		printf("The queue is empty \n");
		exit;
	}

	// stores the current head in a temp variable
	// gets userdata from the head node and then moves the head pointer to the next node in queue
	struct queueNode* temp = q->head;
	struct user userData = temp->data;
	q->head = q->head->pNext;

	// if queue is empty, set the tail to NULL
	if (q->head == NULL) {
		q->tail = NULL;
	}

	// free the temp variable and return userData
	free(temp);
	return userData;
}

// randomly generates a username
void randomUsername(char* username)
{
	for (int i = 0; i < 10; i++) {
		int randomVal = rand() % 36; // since there are 36 values including the alphabets and 1-10
		if (randomVal < 26) { // if its less that 26 its a letter
			username[i] = 'A' + randomVal; 
		}
		else { // otherwise its a number
			username[i] = '0' + (randomVal - 26);
		}
	}
	username[10] = '\0'; // null terminator
}

// randomly generates a number between 0-2 and assigns a faction
void randomFaction(char* faction) {
	int randomFaction = rand() % 3;
	if (randomFaction == 0) {
		strcpy(faction, "red");
	}
	else if (randomFaction == 1) {
		strcpy(faction, "blue");
	}
	else {
		strcpy(faction, "green"); 
	}
}

// gives the user a random username, level and faction
struct user createRandomUser() {
	struct user newUser;
	randomUsername(newUser.userName);
	newUser.userLevel = rand() % 60 + 1; // generates the user level from 1-60 and +1 makes it start from 1 instead of 0
	randomFaction(newUser.userFaction);
	return newUser;
}

// creates the number of user profiles needed and then adds it to the queue
int insertUsers(struct queue* q, int numOfUsers) {
	for (int i = 0; i < numOfUsers; i++) {
		struct user addUsersToQueue = createRandomUser();
		addToQueue(q, addUsersToQueue);
	}
	return 0;
}

