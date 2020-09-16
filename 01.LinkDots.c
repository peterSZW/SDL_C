#include <stdio.h>
#include <SDL.h>


struct Tdot{
    struct Tdot *pre;
    int x;
    int y;
    struct Tdot *next;
};  


struct Tdot *head, *tail; 

int Append(struct Tdot *data) {
	if (head==0) {
		head=data;
		tail=data;
	} else {
		tail->next=data;
		data->pre=tail;
		tail=data;
	}
}

int main(int argc, char *argv[])
{   
	struct Tdot *d=(struct Tdot *)malloc(sizeof(struct Tdot));
	int i=0;
	for(  i=0;i<10;i++) {
		d=(struct Tdot *)malloc(sizeof(struct Tdot));
		d->pre=0;
		d->x=i;
		d->y=i;
		d->next=0;
		Append(d);
	}
	
    struct Tdot *cur ;
    
    for(cur=head;cur->next != 0 ;cur = cur->next) {
        printf("(%p,%p,%d,%d,%p)\n",cur,cur->pre,cur->x,cur->y,cur->next );
    }

    return 0;
}
