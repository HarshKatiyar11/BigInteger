#ifndef BI_H
#define BI_H

  struct node *insertatbeginning(struct node * head, int a);
  struct node *insertatend(struct node * ptr, int a);
  struct node *convert(struct node * head, char s[100]);
  struct node *reverse(struct node * head);
  void insert(struct node * *head, int data);
  void display(struct node * ptr);
  struct node *add(struct node * head1, struct node * head2);
  struct node *subtract(struct node * head1, struct node * head2);
  struct node *multiply(struct node * num1, struct node * num2);
  struct node *divide(struct node * dividend, struct node * divisor);

#endif