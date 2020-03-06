#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - know if is a palindrome
 * @head: word or sentence
 * Return: 0 if not or 1 if it is
 */
int is_palindrome(listint_t **head)
{
	listint_t *copy1, *copy2;
	int i, j, leng, part1, part2;

	leng = 0;
	copy1 = *head;
	copy2 = *head;

	while (copy1 != NULL)
	{
		leng += 1;
		copy1 = copy1->next;
	}
	copy1 = *head;

	if (leng % 2 == 0)
	{
		part1 = (int)leng / 2;
		part2 = part1 + 1;
	}
	else
	{
		part1 = (int)leng / 2 + 1;
		part2 = part1;
	}

	for (j = 0; j <= part2; i++)
		copy2 = copy2->next;
	printf("este es %d es la posicion %d\n", copy2->n, part2);

	for (j = part2; j <= leng; j++)
	{
		for (i = 0; i <= part1; i++)
			copy1 = copy1->next;
		if (copy1->n != copy2->n)
			return (0);
		part1 = part1 - 1;
		copy2 = *head;
		printf("comparando %d en pos %d y %d en pos %d",copy1->n, part1, copy2->n, part2);
	}
	return (1);
}
