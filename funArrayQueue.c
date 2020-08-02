#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *q;
};

int enqueue(struct Queue *quptr, int x)
{

    //if one ahead of rear is front ptr (if rear at last element check if front at element 0)
    if ((quptr->rear + 1) % quptr->size == quptr->front){
        printf("Queue is Full.\n");
        return -1;
    }
    else
    {
        //move rear up by 1 (if rear at last element, move to zero)
        quptr->rear = (quptr->rear + 1) % quptr->size;
        quptr->q[quptr->rear] = x; //add x to rear element
    }
    return 0;
}

int dequeue(struct Queue *quptr)
{
    int x = -1;

    //this should only be true to start
    if (quptr->front == quptr->rear)
        printf("Queue is Empty.\n");
    else
    {
        //move front up by 1 (if front at last element, move to zero)
        quptr->front = (quptr->front + 1) % quptr->size;
        //always move up then remove, however here front doesn't get removed b/c fixed array
        x = quptr->q[quptr->front];
    }
    return x;
}

void create(struct Queue *quptr, int size)
{
    quptr->size = size + 1; //queue should start at index 1 and index 0 should be blank, so size 5 should be 5+1 indicies
    quptr->front = quptr->rear = 0;
    quptr->q = (int *)malloc(quptr->size * sizeof(int));
}

void display(struct Queue quptr)
{

    //      while(quptr.front != quptr.rear + 1){
    //          printf("%d ", quptr.front+1);
    //          quptr.front = quptr.front+1;
    //      }
    int i = quptr.front + 1;
    do
    {
        printf("%d ", quptr.q[i]);
        i = (i + 1) % quptr.size;
    } while (i != (quptr.rear + 1) % quptr.size);

    printf("\n");
}

int promptint()
{
    int fixin, input, ret = 0;
    //check valid size
    while (ret != 1 || input > INT_MAX || input < INT_MIN)
    {
        printf("Enter a valid integer: ");
        while ((fixin = getchar()) != EOF && fixin != '\n'); // fix stdin
        fflush(stdin);
        ret = scanf("%d", &input);
    }
    return input;
}
int repromptsize()
{
    int fixin, input, ret = 0;
    //check valid size
    while (ret != 1 || input < 1 || input > INT_MAX)
    {
        printf("Enter a valid size: ");
        while ((fixin = getchar()) != EOF && fixin != '\n'); // fix stdin
        fflush(stdin);
        ret = scanf("%d", &input);
    }
    return input;
}
int repromptchoice()
{
    int fixin, input, ret = 0;
    //check valid size
    while (ret != 1 || input > 1 || input < 3)
    {
        printf("Enter a valid choice: ");
        while ((fixin = getchar()) != EOF && fixin != '\n'); // fix stdin
        fflush(stdin);
        ret = scanf("%d", &input);
    }
    return input;
}

int main()
{

    //create queue arr size 5
    struct Queue qu;


    printf("Welcome to the Array Queue Program.\n");
    printf("Create a Queue using an Array.\n");

    int ret, size;
    //prompt user to choose an equation
    //validate
    printf("\nEnter the size of your queue: ");
    ret = scanf("%d", &size);
    if (ret != 1 || size < 1 || size > INT_MAX)
        size = repromptsize();
    create(&qu, size);

    int input, flag = 1;
    do{
        printf("\nWhat do you want to do with the Queue?\n");
        printf("1. Queue an integer.\n");
        printf("2. Dequeue an integer.\n");
        printf("3. Display Queue.\n");

        //validate
        printf("\nEnter your choice: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 3 || input < 1)
            input = repromptchoice();
        
        //set the infix string
        int k,r;
        switch (input)
        {
            case 1:
                k = promptint();
                r = enqueue(&qu,k);
                if(r != -1) 
                    printf("Queued %d element.\n",k);
                printf("Press Any Key to Continue");
                getchar();getchar();fflush(stdin);
                break;
            case 2:
                r = dequeue(&qu);
                if(r != -1)
                    printf("Dequed %d element.\n",r);
                printf("Press Any Key to Continue");
                getchar();getchar();fflush(stdin);
                break;
            case 3:
                display(qu);
                printf("Press Any Key to Continue");
                getchar();getchar();fflush(stdin);
                break;
        }


    }while(flag);

}
