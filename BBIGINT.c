#include "BI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
  int data;
  struct node *next;
};
struct node *insertatbeginning(struct node *head, int a)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL)
  {
    printf(" Memory allocationn failed");
    exit(1);
  }
  newnode->data = a;
  newnode->next = head;
  head = newnode;
  return head;
}
struct node *insertatend(struct node *ptr, int a)
{
  struct node *temp;
  temp = ptr;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL)
  {
    printf(" Memory allocationn failed");
    exit(1);
  }
  newnode->data = a;
  newnode->next = NULL;
  if (ptr == NULL)
  {
    return newnode;
  }
  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = newnode;
  return temp;
}
struct node *convert(struct node *head, char s[100])
{
  int l = strlen(s);
  int a;
  for (int i = 0; i < l; i++)
  {
    a = s[i] - 48;
    head = insertatbeginning(head, a);
  }
  return head;
}
struct node *reverse(struct node *head)
{
  struct node *curr = head;
  struct node *prev = NULL;
  struct node *next = NULL;

  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}
void insert(struct node **head, int data)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    struct node *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newNode;
  }
}
void display(struct node *ptr)
{
  while (ptr != NULL)
  {
    printf("%d", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
  return;
}
struct node *add(struct node *head1, struct node *head2)
{
  int c = 0;
  struct node *head3;
  int a = 0;
  head3 = NULL;
  while (head1 != NULL)
  {
    a = head1->data + head2->data + c;
    if (a > 9)
    {
      a = a % 10;
      c = 1;
    }
    else
    {
      c = 0;
    }
    head3 = insertatend(head3, a);
    if (head1->next == NULL && c == 1)
    {
      head3 = insertatend(head3, c);
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  head3 = reverse(head3);
  return head3;
}

struct node *subtract(struct node *head1, struct node *head2)
{
  struct node *result = NULL;
  struct node *temp = NULL;
  int borrow = 0;

  while (head1 != NULL || head2 != NULL)
  {
    int data1 = (head1 != NULL) ? head1->data : 0;
    int data2 = (head2 != NULL) ? head2->data : 0;

    int diff = data1 - data2 - borrow;

    if (diff < 0)
    {
      borrow = 1;
      diff += 10;
    }
    else
    {
      borrow = 0;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = diff;
    new_node->next = NULL;

    if (result == NULL)
    {
      result = temp = new_node;
    }
    else
    {
      temp->next = new_node;
      temp = new_node;
    }

    if (head1 != NULL)
    {
      head1 = head1->next;
    }
    if (head2 != NULL)
    {
      head2 = head2->next;
    }
  }
  result = reverse(result);
  return result;
}
struct node *multiply(struct node *num1, struct node *num2)
{
  struct node *result = NULL;
  struct node *temp1, *temp2;
  int carry = 0;

  for (temp1 = num1; temp1 != NULL; temp1 = temp1->next)
  {
    int x = temp1->data;
    int prod_carry = 0;
    struct node *current = result;

    for (temp2 = num2; temp2 != NULL; temp2 = temp2->next)
    {
      int y = temp2->data;
      int product = x * y + prod_carry;

      if (current == NULL)
      {
        insert(&result, product % 10);
      }
      else
      {
        product += current->data;
        current->data = product % 10;
      }
      prod_carry = product / 10;

      if (current == NULL)
      {
        current = result;
      }
      else
      {
        current = current->next;
      }
    }

    if (prod_carry > 0)
    {
      insert(&result, prod_carry);
    }
  }

  return result;
}
struct node *divide(struct node *dividend, struct node *divisor)
{
  dividend = reverse(dividend);
  dividend = reverse(divisor);
  struct node *result = NULL;
  struct node *temp = NULL;
  int quotient = 0;

  while (dividend != NULL)
  {
    int dividend_value = dividend->data;
    int divisor_value = (divisor != NULL) ? divisor->data : 0;

    if (divisor_value == 0)
    {
    }

    if (dividend_value < divisor_value)
    {
      struct node *zero = (struct node *)malloc(sizeof(struct node));
      zero->data = 0;
      zero->next = NULL;

      if (result == NULL)
      {
        result = temp = zero;
      }
      else
      {
        temp->next = zero;
        temp = zero;
      }

      dividend = dividend->next;
    }
    else
    {
      int current_quotient = dividend_value / divisor_value;
      quotient = quotient * 10 + current_quotient;

      struct node *q = (struct node *)malloc(sizeof(struct node));
      q->data = current_quotient;
      q->next = NULL;

      if (result == NULL)
      {
        result = temp = q;
      }
      else
      {
        temp->next = q;
        temp = q;
      }

      int remainder = dividend_value % divisor_value;
      struct node *r = (struct node *)malloc(sizeof(struct node));
      r->data = remainder;
      r->next = NULL;

      if (dividend->next == NULL && remainder == 0)
      {
        free(r);
      }
      else
      {
        dividend->data = remainder;
        r->next = dividend->next;
        dividend->next = r;
      }
    }
  }

  return result;
}