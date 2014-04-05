





typedef struct{

 void *topOfStack;

}Stack;







Stack *stackNew(void);

void push(void *data,Stack *stack);

void *pop(Stack *stack);
