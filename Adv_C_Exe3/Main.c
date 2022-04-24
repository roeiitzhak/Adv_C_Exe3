//#include <stdio.h>
#include "Stack.h"
#include "Queue.h"


void printStack(Stack* s)
{
	while (isEmptyStack(s) == 0)
	{
		printf("%c->", pop(s));
	}
	printf("NULL\n");
}

void printQueue(Queue* q)
{
	while (isEmptyQueue(q) == 0)
	{
		printf("%d->", dequeue(q));
	}
	printf("NULL\n");
}


void main()
{/*
	flipBetweenHashes("remem#reb# thi#carp s#tice \n");
	flipBetweenHashes("remem#reb# thi#carp s#tice#abc");*/

	//Stack charsStack;
	//initStack(&charsStack);
	//push(&charsStack, 'a');
	//push(&charsStack, 'b');
	//push(&charsStack, 'b');
	//push(&charsStack, 'b');
	//push(&charsStack, 'a');
	//if (isPalindrome(&charsStack) == 1)
	//{
	//	printf("chars stack is a palindrome");
	//}
	//else
	//{
	//	printf("chars stack is NOT a palindrome");
	//}

	// ->fedcba changes stack to: ->cbafed
	/*Stack charsStack;
	initStack(&charsStack);
	push(&charsStack, 'a');
	push(&charsStack, 'b');
	push(&charsStack, 'c');
	push(&charsStack, 'd');
	push(&charsStack, 'e');
	push(&charsStack, 'f');
	rotateStack(&charsStack, 3);
	printf("stack after rotate:\n");
	printStack(&charsStack);*/

	//// rotateQueue
	/*Queue numsQ;
	initQueue(&numsQ);
	enqueue(&numsQ, 1);
	enqueue(&numsQ, 2);
	enqueue(&numsQ, 3);
	enqueue(&numsQ, 4);
	rotateQueue(&numsQ);
	printQueue(&numsQ);*/

	//// cutAndReplace
	/*Queue numQ1;
	initQueue(&numQ1);
	enqueue(&numQ1, 6);
	enqueue(&numQ1, 1);
	enqueue(&numQ1, 5);
	enqueue(&numQ1, 2);
	enqueue(&numQ1, 3);
	enqueue(&numQ1, 1);
	enqueue(&numQ1, 9);
	cutAndReplace(&numQ1);
	printQueue(&numQ1);*/

	/*Queue numQ2;
	initQueue(&numQ2);
	enqueue(&numQ2, 6);
	enqueue(&numQ2, 5);
	enqueue(&numQ2, 2);
	enqueue(&numQ2, 3);
	enqueue(&numQ2, 1);
	enqueue(&numQ2, 9);
	cutAndReplace(&numQ2);
	printQueue(&numQ2);*/

	// sortKidsFirst
	// ->6413152 changes queue to: ->123456
	/*Queue numsQ;
	initQueue(&numsQ);
	enqueue(&numsQ, 6);
	enqueue(&numsQ, 4);
	enqueue(&numsQ, 1);
	enqueue(&numsQ, 3);
	enqueue(&numsQ, 1);
	enqueue(&numsQ, 5);
	enqueue(&numsQ, 2);
	sortKidsFirst(&numsQ);
	printQueue(&numsQ);*/
}