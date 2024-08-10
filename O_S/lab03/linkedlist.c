//Free space management 

#include<stdio.h>
#include<stdlib.h>
struct SLL
{
    int info ;
    struct SLL *next;
};
struct SLL *head=NULL;
int main()

{
    int choice,data,d;
do
{
printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a particular node\n");
        printf("4. Insert before a particular node\n");
        printf("5. Delete particular node\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

switch(choice)
{
case 1:
printf("enter the data :");
scanf("%d",&data);
struct SLL*ptr1=(struct SLL*)malloc(sizeof(struct SLL));
ptr1->info=data;
ptr1->next=head;
head=ptr1;
break;


case 2:
printf("Enter the data :");
scanf("%d",&data);
struct SLL*ptr2=(struct SLL*)malloc(sizeof(struct SLL));
ptr2->info=data;
ptr2->next=NULL;
if(head==NULL)
{
head=ptr2;

}
else
{

struct SLL *temp = head;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = ptr2;
}
break;

case 3:
printf("Enter the new data to insert: ");
 scanf("%d", &data);
printf("Enter the node data after which to insert: ");
scanf("%d", &d);
struct SLL *ptr3 = (struct SLL *)malloc(sizeof(struct SLL));
ptr3->info = data;
struct SLL *temp3 = head;
while (temp3 != NULL && temp3->info != d)
{
temp3 = temp3->next;
}
if (temp3 == NULL)
{
printf("Node with key %d not found\n", d);
}
else
{
ptr3->next = temp3->next;
temp3->next = ptr3;
}
break;

case 4:
printf("Enter the new data to insert: ");
scanf("%d", &data);
printf("Enter the node data before which to insert: ");
scanf("%d", &d);
struct SLL *ptr4 = (struct SLL *)malloc(sizeof(struct SLL));
ptr4->info = data;
struct SLL *temp4 = head;
struct SLL *prev4 = NULL;
while (temp4 != NULL && temp4->info != d)
{
 prev4 = temp4;
 temp4 = temp4->next;
 }
if (temp4 == NULL)
{
printf("Node with key %d not found\n", d);
}
 else
{
if (prev4 == NULL)
{
ptr4->next = head;
head = ptr4;
}
else
{
ptr4->next = temp4;
prev4->next = ptr4;
}
}
break;

case 5:
printf("enetr the node data to delete :");
scanf("%d", &d);
if (head == NULL)
{printf("Empty linked list\n");
}
else
{
                struct SLL *temp5 = head;
                struct SLL *prev5 = NULL;
                while (temp5 != NULL && temp5->info != d)
                {
                    prev5 = temp5;
                    temp5 = temp5->next;
                }
                if (temp5 == NULL)
                {
                    printf("Node with key %d not found\n", d);
                }
                else
                {
                    if (prev5 == NULL)
                    {
                        head = head->next;
                    }
                    else
                    {
                        prev5->next = temp5->next;
                    }
                    free(temp5);
                }
            }
            break;

case 6:
if(head ==NULL)

{
    printf("List is empty \n");
    
}
else{

    printf("Elements in the list are :");
    struct SLL*temp6=head;
    while ((temp6!=NULL))
    {
       
    printf("%d ", temp6->info);
    temp6 = temp6->next; 
    }
    printf("\n");

    
}
break;
case 7:
exit(0);

}




} while (choice!=7);
return 0;
}

