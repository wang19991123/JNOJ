#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct fuck
{
	char a[99];
	struct fuck*next;
}WTF;
#define LEN sizeof(WTF)
WTF*newend(WTF**head,WTF*end);
int printlist(WTF*head);
WTF*delet(WTF*head,char*d);

int main()
{
	int i;
	char c[99] = {"#"},b[99],d[99];
	WTF*end = NULL,*head = NULL;
	i = 0;
	while(scanf("%s",b),strcmp(b,c)!=0)
	{
		end = newend(&head,end);
		strcpy(end->a,b);
		i++;
	}
	printlist(head);
	printf("%d\n",i);
	scanf("%s",d);
	head = delet(head,d);
	printlist(head);
	printf("%d\n",i-1);
	return 0;
}

WTF*newend(WTF**head,WTF*end)
{
	WTF*p;
	if(end==NULL)
	{
		end = (WTF*)malloc(LEN);
		end->next = NULL;
		*head = end;
		return end;
	}
	p = (WTF*)malloc(LEN);
	end->next = p;
	p->next = NULL;
	return p;
}

int printlist(WTF*head)
{
	WTF*q;
	q = head;
	while(q->next!=NULL)
	{
		printf("%s\n",q->a);
		q = q->next;
	}
	printf("%s\n",q->a);
	return 0;
}

WTF*delet(WTF*head,char*d)
{
	WTF*q,*qlast;
	q = head;
	if(strcmp(q->a,d)==0)
	{
		free(head);
		head = q->next;
		return head;
	}
	qlast = head;
	while(q->next!=NULL)
	{
		if(strcmp(q->a,d)==0)
		{
			qlast->next = q->next;
			free(q);
			return head;
		}
		qlast = q;
		q = q->next;
	}
	if(strcmp(q->a,d)==0)
	{
		free(q);
		qlast->next = NULL;
		return head;
	}
	return 0;
}
