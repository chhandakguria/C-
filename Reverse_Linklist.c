
#include<stdio.h>
typedef struct link
{
    int data;
	struct *link

} ST;
---------> header.h
---------
main.c
-------

extern SL *head;

void rev(SL *head)
{
  Sl* temp1, temp2, temp3;
  
  if(head == null || head->link== null)
    return;

  temp1 = head;
  temp2 = temp1->link;
  temp3 = temp2->link;
  
  temp1->link = null;
  temp2->link = temp1;
  
  while(temp3)
  {
    temp1 = temp2;
	temp2 = temp3;
	temp3 = temp3->link;
	temp2->link = temp1;
  }
  
  head = temp2;
  
}
  


}
