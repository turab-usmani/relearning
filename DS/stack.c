#include "stdio.h"

struct Stack {

    int* data;
    int top_index;
    size_t size;

};


int is_empty(struct Stack * s) {

    if (s->top_index == 0) {
        return 1;
    }
    else return 0;

}


int top(struct Stack * s) {

    if (!is_empty(s)) {
        return s->data[s->top_index];
    }

    return -2;
}



int pop(struct Stack * s) {

    if (!is_empty(s)) {

        int i = top(s);
        s->data[s->top_index] = 0;
        s->top_index--;

        return i;

    }

}

void push(struct Stack * s, int item) {

    if (s->top_index + 1 > s-> size) {

        printf("Error, stack is full \n");
        return;
    } else {

        s->data[s->top_index] = item;

        if (s->top_index + 1 < s->size) {
            
            s->top_index++;
        }
        
        

    }


}




int main() {
    
    struct Stack s;
    s.top_index = 0;
    s.size = 4;


    s.data = malloc(s.size * sizeof(int));
    
    push(&s, 5);
    push(&s, 10);
    push(&s, 9);
    push(&s, 120);
    //push(&s, 15);
    //push(&s, 25);

    printf("popped last element %d \n", pop(&s));
    printf("popped last element %d \n", pop(&s));
    printf("popped last element %d \n", pop(&s));


    for (int x = 0; x < 4; x++) {

        printf("%d \n", s.data[x]);

    }

    
    return 0;
}