#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct queue
{
    struct node *head;
    struct node *tail;
};

typedef struct node node;
typedef struct queue queue;

void enqueue(queue *q, int e)
{
    if (q->tail == NULL) {
        q->head = (node *)malloc(sizeof (node));
        q->head->val = e;
        q->head->next = NULL;
        q->tail = q->head;
    }
    else {
        q->tail->next = (node *)malloc(sizeof (node));
        q->tail->next->val = e;
        q->tail->next->next = NULL;
        q->tail = q->tail->next;
    }
}

int dequeue(queue *q)
{
    if (q->head == NULL)
        return 0;

    int val = q->head->val;
    
    if (q->head == q->tail) {
        free(q->head);
        q->head = NULL;
        q->tail = NULL;
    }
    else {
        node *first = q->head;
        q->head = q->head->next;
        free(first);
    }

    return val;
}

int main()
{
    int case_num = 0;

    while (1) {
        int t;
        scanf("%d", &t);
        if (t == 0)
            break;

        printf("Scenario #%d\n", ++case_num);

        static int elem[999999]; // stack too small
        
        int i;
        for (i = 0; i < t; ++i) {
            int l;
            scanf("%d", &l);

            while (l--) {
                int e;
                scanf("%d", &e);

                elem[e] = i;
            }
        }
        getchar();
        
        queue team_q[1000] = {{NULL}};
        int team_order[1000];
        int *last = &team_order[0];
        int *first = &team_order[0];
        
        int command = getchar();
        while (command != 'S') {
            if (command == 'E') {
                while (getchar() != ' ');
                
                int e;
                scanf("%d", &e);
                
                int team_num = elem[e];
                
                if (team_q[team_num].head == NULL) {
                    *last = elem[e];
                    ++last;
                }
                enqueue(&team_q[team_num], e);
                
                while (getchar() != '\n');
            }
            else if (command == 'D') {
                while (getchar() != '\n');
                
                printf("%d\n", dequeue(&team_q[*first]));
                
                if (team_q[*first].head == NULL)
                    ++first;
            }
            
            command = getchar();
        }
        while (getchar() != '\n');
        
        while (first != last) {
            dequeue(&team_q[*first]);
            if (team_q[*first].head == NULL)
                ++first;
        }
        
        printf("\n");
        
    }
    
    return 0;
}
