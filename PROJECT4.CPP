#include <stdio.h>
#include <stdlib.h>


    struct node{
	int data;
	struct node *next;
	struct node *previous;

    };

    struct node *head,*temp,*newnode,*dnode;

void Creation(int size){
    head=NULL;
    if(size>=1){
	head=(struct node*)malloc(sizeof(struct node));
	if(head!=0){
	    printf("Enter the data 1 \n");
	    scanf("%d",&head->data);
	    head->next=NULL;
	    head->previous=NULL;
	    temp=head;
	for(int i=2; i<=size; i++){
	newnode=(struct node*)malloc(sizeof(struct node));

		printf("Enter thr data %d \n",i);
		scanf("%d",&newnode->data);
		newnode->previous=temp;
		newnode->next=NULL;

		temp->next=newnode;
		temp=newnode;

	}
	}
    }else{
	printf("NOT Possible");
    }

}
void Display(){
    struct node *print;
    print=head;
    while(print!=0){
	printf("The data is %d \n",print->data);
	print=print->next;
    }

}

void insertionAtBeg(){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int s;
    printf("Enter the element \n");
    scanf("%d",&s);
    ptr->data=s;
    ptr->next=head;
    ptr->previous=NULL;

    head->previous=ptr;
   head=ptr;

}

void insertionAtend(){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int s;
    printf("Enter the element \n");
    scanf("%d",&s);
    temp=NULL;
    temp=head;
    while(temp->next!=NULL){
	    temp=temp->next;

    }
    ptr->data=s;
    ptr->next=NULL;
    ptr->previous=temp;
    temp->next=ptr;

    temp=ptr;
}
void inserttionAtIndex(int size){
    int index;
    printf("Enter the index \n");
    scanf("%d",&index);

    if(index>=size){
	printf("Not Possible");
    }else
    {
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int s;
    temp=NULL;
    temp=head;
    for(int i=1; i<index; i++){
	temp=temp->next;
	if(temp==NULL){
	    printf("Not Possible ");
	}
    }
    printf("Enter the element \n");
    scanf("%d",&s);
    ptr->data=s;
    ptr->next=temp->next;
    ptr->previous=temp;
    temp->next=ptr;
    temp->next->previous=ptr;;


    }

}

void DeletionAtBeg(){


 if(head==NULL){
	printf("Not Possible");

 }else{
    dnode=head;
    head=head->next;
    head->previous=NULL;
    free(dnode);
 }
    printf("Deleted successfully :-> \n");

}
void DeletionAtEnd(){

	struct node *nodeDelete;
	    if(temp==NULL){
	      printf("Not Possible \n");
	    }else{
	    nodeDelete=temp;
	    temp=temp->previous;
	    if(temp!=NULL){
		temp->next=NULL;
	    }
	    free(nodeDelete);
	    }

}
void DeletionAtIndex(int size){
    int position;
    printf("\n Enter the position");
    scanf("%d", &position);
    if(position==NULL){
	    printf("Not possible");
    }
    else if(position==size){
     printf("Not possible");
    }

    struct node *current;
    int i;

    current = head;
    for(i=0; i<position; i++)
    {
	current = current->next;
    }

	current->previous->next = current->next;
	current->previous->previous = current->previous;

	free(current); // Delete the n node

	printf(" Node deleted at position % \n", position);

	Display();
}
void  Reversal(){
    struct node *current ,*nextnn;

    current=head;
    while(current!=NULL){
	nextnn=current->next;
	current->next=current->previous;
	current->previous=nextnn;
	current=nextnn;
    }
   current=head;
   head=temp;
   temp=current;
}



void main()
{
    int n;
    printf("Enter the size of the list \n");
    scanf("%d",&n);
    Creation(n);
    Display();
    int choice;
    printf("\n");
    printf("Press 1 for Insertion at beg. \n");
    printf("Press 2 for Insertion at end \n");
    printf("Press 3 for Insertion at Index \n");
    printf("Press 4 for Deletion at beg \n");
    printf("Press 5 for Deletion at end \n");
    printf("Press 6 for Deletion at Index \n");
    printf("Press 7 for Reversal \n");
    scanf("%d",&choice);

    switch(choice){
    case 1:
	insertionAtBeg();
	Display();
	break;
    case 2:
	insertionAtend();
	Display();
	break;
    case 3:
	inserttionAtIndex(n);
	Display();
	break;
    case 4:
	DeletionAtBeg();
	Display();
	break;
    case 5:
	DeletionAtEnd();
	Display();
	break;
    case 6:
	DeletionAtIndex(n);
	Display();
	break;
    case 7:
	Reversal();
	Display();
	break;
    default:
	printf("Invalid choice \n");
    }



}
