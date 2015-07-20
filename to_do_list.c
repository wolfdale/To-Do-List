#include<stdio.h>
#include<stdlib.h>
void display_pri();
void add_item();
void display();
void del_item();
void exit_end();
struct note{
	char data[20];
	int entry;
	int priority;
	struct note * next;
};

struct note *head=NULL;
int e_count=0;

int main()
{
	int a;
	do{
		printf("Press 1 for Adding Item to list\n");
		printf("Press 2 for Deleting Item from list\n");
		printf("Press 3 to Display list\n");
		printf("press 4 to Exit \n");
		scanf("%d",&a);
		switch(a){
			case 1:{add_item();
                   break;}
			case 2:{del_item();
                   break;}
			case 3:{display();
                   break;}
			case 4:{exit_end();
                   break;}
			default:{printf("Sorry I Can't Understand you !\n");
                    break;}

		}
		printf("\n");

	}while(a!=4);
    return 0;

}

void exit_end()
{
    printf("\nGoodBye!");

}

void add_item()
{
	struct note * ptr,*temp;
	ptr=(struct note*)malloc(sizeof(struct note));
	e_count++;
	ptr->next=NULL;
	ptr->entry=e_count;
	printf("\nEnetr Item:\n");
	scanf("%s",ptr->data);
	printf("Set priority");
	scanf("%d",&ptr->priority);
	if(head==NULL)
	{
		head=ptr;
	}
	else
	{
	    while(temp!=NULL)
        {
            temp=temp->next;
        }
		temp->next=ptr;

	}

}


void display()
{
    if(e_count==0)
    {
        printf("\nList is Empty !\n");
        return ;
    }


	struct note*ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("\n%d  %s\n",ptr->entry,ptr->data);
		ptr=ptr->next;
	}

}


void del_item()
{
	struct note *temp,*prev;
	prev=NULL;
	temp=head;
	int x,eno;
	printf("\nPress 1 to Display list\n");
	printf("\nPress 2 to enter the Entry number\n");
	scanf("%d",&x);
	if(x==1){
		display();
		printf("\nEnter Entry number:\n");
		scanf("%d",&eno);
	}
	else{
		scanf("%d",&eno);
	}

	while(temp!=NULL)
	{
		if(temp->entry==eno)
		{
			if(prev==NULL)
			{
				head=temp->next;
				free(temp);

			}
			else{
				prev->next=temp->next;
				free(temp);
			}
			break;

		}
		else{
			temp=temp->next;
		}
	}
	e_count--;
}
void display_pri()
{
	struct note *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->priority==1)
		{
			printf("%s",ptr->data);

		}
		else
		{
			ptr=ptr->next;
		}
	}

}
