#pragma once

// structure definitions
 struct user {
	char userName[11]; // plus 1 for null-terminator
	int userLevel;
	char userFaction[6]; // plus 1 for null-terminator
};

 struct queueNode {
	struct queueNode* pNext; //pNext points to the next node
	struct user data;
};

 struct queue {
	struct queueNode* head;
	struct queueNode* tail;
};

 // function declarations 
 void initializeQueue(struct queue* q);
 int isQueueEmpty(struct queue* q);
 void addToQueue(struct queue* q, struct user u);
 struct user removeFromQueue(struct queue* q);
 void randomUsername(char* username);
 void randomFaction(char* faction);
 struct user createRandomUser();
 int insertUsers(struct queue* q, int numOfUsers);