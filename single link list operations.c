#include<stdio.h>
#include<stdlib.h>
typedef struct node //define struct node globally to be available to every function
{
    int data;
    struct node *next;
}noode;
noode *hd=NULL;

void traverse() //function to traverse linked list
{
    noode *p=hd;
    printf("\nThe linked list so far is:\n");
    while(p!=NULL)
    {
        printf(" %d\n",p->data);
        p=p->next;
    }
}

void insertn(int b,int j,int *ncp) //function to insert a number b in linked list
{
    int c=0;
    noode *link,*dal=hd;
    if(j==1)
    {
        link=(noode *)malloc(4);
        link->data=b;
        link->next=hd;
        hd=link;
    }
    else
    {
        while(c!=j-2)
        {
            dal=dal->next;
            c++;
        }
        if(j==(*ncp)+1)
        {
            link=(noode *)malloc(4);
            link->data=b;
            link->next=NULL;
            dal->next=link;
        }
        else
        {
            link=(noode *)malloc(4);
            link->data=b;
            link->next=dal->next;
            dal->next=link;
        }
    }
    (*ncp)++;
}

void deleten(int b,int *ncp) //function to delete b-th node
{
    noode *fre=hd;
    int c=0;
    if(b==1)
    {
        hd=hd->next;
        free(fre);
    }
    else
    {
        while(c!=b-2)
        {
            fre=fre->next;
            c++;
        }

        if(b==*ncp)
        {
            free(fre->next);
            fre->next=NULL;
        }
        else
        {
            noode *p=fre->next;
            fre->next=(fre->next)->next;
            free(p);
        }
    }
    (*ncp)--;
}

void decider(int a,int *ncp) // on the basis of number entered call appropriate function
{
    int b,j;
    switch(a)
    {
        case 1: if(*ncp==0)
                {printf("\nThe linked list is empty, insert a number: ");
                scanf("%d",&b);
                insertn(b,1,ncp);}
                else
                {
                    printf("\nThere are %d nodes in the linked list, at which position u want to enter new data: ",*ncp);
                    scanf("%d",&j);
                    printf("\nEnter a number: ");
                    scanf("%d",&b);
                    insertn(b,j,ncp);
                }
                break;
        case 2: if(*ncp==0)
                printf("\nTHE LINKED LIST IS ALREADY EMPTY\n");
                else
                {printf("\nThere are %d nodes in your linked list, which node you want to delete: ",*ncp);
                scanf("%d",&b);
                deleten(b,ncp);}
                break;
        case 3: if(*ncp==0)
                printf("\nTHE LINKED LIST IS EMPTY\n");
                else
                traverse();
                break;
        case 0: exit(0);

        default : printf("\nYOU MUST ENTER A NUMBER FROM 0 TO 3\n");
    }
}
void main()
{
    int nc=0,a;
    int *ncp=&nc;
    while(1)
    {
        printf("\nPress :\n1 To insert a node.\n2 To delete a node.\n3 To traverse your linked list.\n0 To exit\n\nYour response: ");
        fflush(stdin);
        scanf("%d",&a);
        decider(a,ncp);
    }
}
