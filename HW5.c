#include <stdio.h>
#include <stdlib.h>


//Усов Александр
/*
1. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
3. *Реализовать очередь на основе двусвязного списка.
*/

#define T char
 #define SZ 100

 typedef int boolean;
#define true 1
#define false 0

typedef struct _Node {
    char value;
    struct _Node *next;
    struct _Node *prev; 
} Node1;
typedef struct _Queue {
    int size;
    Node1 *head;
    Node1 *tail;
} Queue;

typedef struct Node {
  T data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int size;
} Stack;

boolean push(Stack *st, T value) {
  Node *temp = (Node*) malloc(sizeof(Node));
  if (temp == NULL)
	return false;

  temp->data = value;
  temp->next = st->head;

  st->head = temp;
  st->size++;
  return true;
}

T pop(Stack *st) {
  if (st->size == 0) {
	return -1;
  }

  Node *temp = st->head;
  T result = st->head->data;

  st->head = st->head->next;
  st->size--;
  free(temp);
  return result;
}
Queue* createQueue() {
    Queue *tmp = (Queue*) malloc(sizeof(Queue));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp;
}
void* popQueue(Queue *list) {
    Node1 *prev;
    char tmp;
    if (list->head == NULL) {
        exit(1);
    }
 
    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    
 
    list->size--;
    return tmp;
}
void pushQueue(Queue *list, char value) {
    Node1 *tmp = (Node1*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(2);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}
int ch[3] = {0, 0, 0};
// 0 -(), 1 - [], 2 - {} 
char sym[6] ={')', '(', ']', '[', '}', '{'};
void check(char result){
	if(result == sym[0]) ch[0] +=1;
	else if(result == sym[1]) ch[0]-=1;
	else if(result == sym[2]) ch[1]+=1;
	else if(result == sym[3]) ch[1]-=1;
	else if(result == sym[4]) ch[2]+=1;
	else if(result == sym[5]) ch[2]-=1;
}
int main(int argc, const char** argv) {
  system("chcp 1251");
  Stack s;
  int i;
  s.size = 0;
  s.head = NULL;
  char a[10];
  for( i=0; i<3;i++){
	  a[i] = 0;
  }
  printf("Введите строку из символов (){}[]\n");
  scanf("%s", &a);
  for( i=0; i<10;i++){
	  push(&s, a[i]);
  }
  for(i = 1; i <10 ; i++){
	  check(pop(&s));
  }
  int count = 0;
  for(i = 0; i<10; i++){
	  if(ch[i] == 0) count++;
  }
  if(count == 3) printf("OK");
  else printf("Error");
  
  while (s.size > 0) {
	printf("%c ", pop(&s));
  }
  
  printf("\n");
  
  Queue que;
  que.size = 0;
  que.head = NULL;
  que.tail = NULL;
  
  pushQueue(&que, 'a');
  pushQueue(&que, 'b');
  pushQueue(&que, 'c');
  pushQueue(&que, 'd');
  pushQueue(&que, 'e');
  pushQueue(&que, 'f');
  pushQueue(&que, 'g');
  pushQueue(&que, 'h');
  
  while (que.size > 0) {
	printf("%c ", popQueue(&que));
  }
  printf("\n");
  getchar();
  return 0;
}