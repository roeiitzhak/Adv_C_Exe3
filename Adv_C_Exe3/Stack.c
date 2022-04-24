#include "Stack.h"

/***************** Stack ADT Implementation *****************/

/*
typedef struct charNode
{
	char data;
	struct charNode* next;
}charNode;

typedef struct Stack
{
	charNode* head;
}Stack;
*/

void initStack(Stack* s)
{
	s->head = NULL;
}

// 'a' -> 'b' -> 'c' -> NULL
void destroyStack(Stack* s)
{
	charNode* pCurCharNode = s->head;
	while (pCurCharNode != NULL)
	{
		charNode* pCurCharNodeToDel = pCurCharNode;
		pCurCharNode = pCurCharNode->next;
		free(pCurCharNodeToDel);
	}
	s->head = NULL;
}

//  'd'->'a' -> 'b' -> 'c' -> NULL
void push(Stack* s, char data)
{
	charNode* pNewCharNode = (charNode*)malloc(sizeof(charNode));
	pNewCharNode->data = data;
	pNewCharNode->next = s->head;
	s->head = pNewCharNode;
}

char pop(Stack* s)
{
	char retChar = s->head->data;
	charNode* pSecondNode = s->head->next;
	free(s->head);
	s->head = pSecondNode;
	return retChar;
}

int isEmptyStack(const Stack* s)
{
	return s->head == NULL ? 1 : 0;
}

/*************** Functions using stacks - Implementation/definition **************************/
// remem#reb# thi#carp s#tice -> remember this practice
void flipBetweenHashes(const char* sentence)
{
	Stack helperStack;
	initStack(&helperStack);
	for (int i = 0; i < strlen(sentence); i++)
	{
		if (sentence[i] != '#')
		{
			printf("%c", sentence[i]);
		}
		else
		{
			i++;
			while (sentence[i] != '#' && sentence[i] != '\0')
			{
				push(&helperStack, sentence[i]);
				i++;
			}
			while (isEmptyStack(&helperStack) == 0)
			{
				printf("%c", pop(&helperStack));
			}
		}
	}
}

// abba, abcba
// 'a'->'b'->'b'->'a'->NULL returns 1
// 'a'->'b'->'a'->'a'->NULL returns 0
// 'a'->'b'->'c'->'b'->'a'->NULL returns 1
int isPalindrome(Stack* s)
{
	if (s == NULL || s->head == NULL)
	{
		return 1;
	}
	Stack helperStack;
	initStack(&helperStack);
	int inputStackSize = 0;
	// this while calculates the input stack's size
	while (isEmptyStack(s) == 0)
	{
		inputStackSize++;
		push(&helperStack, pop(s));
	}
	for (int i = 0; i < inputStackSize / 2; i++)
	{
		push(s, pop(&helperStack));
	}
	// 13%2=1
	if (inputStackSize % 2 == 1)
	{
		pop(&helperStack);
	}
	while (isEmptyStack(&helperStack) == 0)
	{
		if (pop(&helperStack) != pop(s))
		{
			return 0;
		}
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	if (s == NULL || s->head == NULL)
	{
		return;
	}
	Stack helperStack;
	initStack(&helperStack);
	int inputStackSize = 0;
	// this while calculates the input stack's size
	while (isEmptyStack(s) == 0)
	{
		inputStackSize++;
		push(&helperStack, pop(s));
	}
	// change input stack back to what is was before moving it's chars to the helper stack. 
	while (isEmptyStack(&helperStack) == 0)
	{
		push(s, pop(&helperStack));
	}
	if (n > inputStackSize || n <= 0)
	{
		return;
	}

	while (n > 0)
	{
		while (isEmptyStack(s) == 0)
		{
			push(&helperStack, pop(s));
		}
		char curTopChar = pop(&helperStack);
		while (isEmptyStack(&helperStack) == 0)
		{
			push(s, pop(&helperStack));
		}
		push(s, curTopChar);
		n--;
	}
}