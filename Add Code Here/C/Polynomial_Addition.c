#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int expo;
    struct node *link;
};

struct node * insert(struct node *head,int co,int ex)
{
    struct node *newnode;
    newnode= (struct node *)malloc(sizeof(struct node));
    newnode->coef=co;
    newnode->expo=ex;
    newnode->link=NULL;
    
    if(head == NULL)
    {
        head=newnode;
    }
    
    else
    {
        struct node * temp;
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
    }
    
    return head;
}



struct node *read(struct node *head)
{
    int i,n,co,ex;
    printf("Enter the number of terms in the polynomial:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the details of term %d\n",i+1);
        printf("Enter the coefficient:\n");
        scanf("%d",&co);
        printf("Enter the exponent:\n");
        scanf("%d",&ex);
        head = insert(head,co,ex);
    }
    return head;
}

struct node * add(struct node * head1,struct node * head2,struct node *head3)
{
    struct node *temp1,*temp2;
    temp1=head1;
    temp2=head2;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->expo > temp2->expo)
        {
            head3=insert(head3,temp1->coef,temp1->expo);
            temp1=temp1->link;
        }
        
        else if(temp2->expo > temp1->expo)
        {
            head3=insert(head3,temp2->coef,temp2->expo);
            temp2=temp2->link;
        }
        
        else
        {
            head3=insert(head3,temp1->coef+temp2->coef,temp2->expo);
            temp1=temp1->link;
            temp2=temp2->link;
        }
    }
    
    while(temp1!=NULL)
    {
        head3=insert(head3,temp1->coef,temp1->expo);
        temp1=temp1->link;
    }
    
    while(temp2!=NULL)
    {
        head3=insert(head3,temp2->coef,temp2->expo);
        temp2=temp2->link;
    }
    
    return head3;
}

void display(struct node *head)
{
    if(head==NULL)
    {
        printf("Polynomial doesnot exist\n");
    }
    
    else
    {
        struct node *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->coef < 0)
            {
                printf("%d ",temp->coef);
            }
            
            else
            {
                printf("+ %d",temp->coef);
            }
            printf("x^%d ",temp->expo);
            temp=temp->link;
        }
        printf("\n");
    }
}

int main()
{
    struct node *head1=NULL,*head2=NULL,* head3=NULL;
    printf("Enter the details of first polynomial\n");
    printf("Enter the polynomials of highest degree first\n");
    head1=read(head1);
    printf("Enter the details of second polynomial\n");
    printf("Enter the polynomials of highest degree first\n");
    head2=read(head2);
    printf("The first polynomial is:\n");
    display(head1);
    printf("The second polynomial is:\n");
    display(head2);
    head3= add(head1,head2,head3);/*frgot head3=*/
    printf("Resultant polynomial is:\n");
    display(head3);
    return 0;
}
