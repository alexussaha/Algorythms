#include <stdio.h>
#include <stdlib.h>

// Усов Александр
typedef struct GraphNode
{
	int data;
	int used;
	int size;
	struct GraphNode *children;
} GraphNode;
#define STACK_MAX_SIZE 20
typedef GraphNode *T;
typedef struct Stack_tag
{
    T data[STACK_MAX_SIZE];
	size_t size;
} Stack_t;

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

void push(Stack_t *stack,  T value)
{
	if (stack->size >= STACK_MAX_SIZE)
	{
		exit(STACK_OVERFLOW);
	}
	stack->data[stack->size] = value;
	stack->size++;
}
T pop(Stack_t *stack)
{
	if (stack->size == 0)
	{
		exit(STACK_UNDERFLOW);
	}
	stack->size--;
	return stack->data[stack->size];
}
// int widthTravers(GraphNode *start, GraphNode *stop)
// {
// 	pushQueue(queue, start);
// 	start->used = 1;
// 	while (queue->size != 0)
// 	{
// 		GraphNode current = popQueue(queue);
// 		if (current->data == stop->data)
// 			return 1;
// 
// 		int i;
// 		for (i = 0; i < children->size; i++)
// 		{
// 			if (children[i].used != 1)
// 			{
// 				pushQueue(queue, children.get(i));
// 				get(children, i).used = 1;
// 			}
// 		}
// 	}
// 	return 0;
// }
//Обход графа в глубину
int dfs(GraphNode *start, GraphNode *stop)
{
	Stack_t *stack;
	push(stack, start);
	start->used = 1;
	
	while (stack->size != 0)
	{
		GraphNode *current = pop(stack);
		if (current->data == stop->data)
			return 1;

		int i;
		for (i = 0; i < current->size; i++)
		{
			if (current->children[i].used != 1)
			{
				push(stack, current.children[i]);
				current->children[i].used = 1;
			}
		}
	}
	return 0;
}
// рекурсивный обход графа в ширину
int widthTraversRec(GraphNode * start, GraphNode * stop){
			int s =0;
			if(start->used) return 0;
			start->used = 1;
			if(start->size == 0) return 0;
			else if(start == stop) return 1;
			int i;
		GraphNode *start1 = start->children[i]
      for( i = 0; i < start ->size; i++ ) s+= widthTraversRec(*start1, stop);
      return s;
}
	
	



int main(int argc, const char** argv)
		{
			GraphNode *gr;
			gr->data = 1;
			gr->size = 3;
			struct GraphNode children[3] = {2,0,0,NULL, 3, 0,0,NULL, 4,0,0,NULL};
			gr ->children = children;
			printf("%d",widthTraversRec(gr, gr.children[2]));	
			return 0;
		}
