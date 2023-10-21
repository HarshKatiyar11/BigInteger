#include<stdio.h>
#include<string.h>
#include"BI.h">
struct node
{
  int data;
  struct node* next;
};
int main()
{
  struct node* head1=NULL;
  struct node* head2=NULL;
  struct node* headadd=NULL;
  struct node* headsub=NULL;
  struct node* headmul=NULL;
  struct node* headdiv=NULL;
  char s1[100],s2[100];
  printf("Enter 1st number"); 
  gets(s1);
  printf("Enter 2nd number");
  gets(s2);
  head1=convert(head1,s1);
  head2=convert(head2,s2);
  headadd=add(head1,head2);
  headsub=subtract(head1,head2);
  headmul=multiply(head1,head2);
  headdiv=divide(head1,head2);
  display(headadd);
  display(headsub);
  display(headmul);
  display(headdiv);
  printf("\n");
}