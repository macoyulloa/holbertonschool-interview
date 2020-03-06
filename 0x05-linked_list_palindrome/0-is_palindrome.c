#include "lists.h"
#include <stdio.h>

void reverse(listint_t **head)
{
	listint_t *prev, *current, *next;
	prev = NULL;
	current = *head;
	next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int compareLists(listint_t **head, listint_t **copy)
{
	listint_t *temp1, *temp2;
	temp1 = *head;
	temp2 = *copy;

	while (temp1 && temp2) {
	        if (temp1->n == temp2->n) {
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	        else
			return 0;
	}
	if (temp1 == NULL && temp2 == NULL)
		return 1;
	return 0;
}

/**
 * is_palindrome - know if is a palindrome
 * @head: word or sentence
 * Return: 0 if not or 1 if it is
 */
int is_palindrome(listint_t **head)
{
	listint_t *copy;
	int num;
	num = 0;
	copy = *head;

	if ((*head) == NULL)
		return (0);
	if ((*head)->next == NULL)
		return (1);

	reverse(head);
	print_listint(*head);
	num = compareLists(*head, copy);
	if (num == 0)
		return (0);
	else
		return (1);
}
