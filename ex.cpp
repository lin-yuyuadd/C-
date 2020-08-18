#include <iostream>
using namespace std;

typedef struct list{
	int num;
	list *pre;
	list *next;
}list;

void list_merge(list* a0,list* a1);
void list_init(list* ,int num, list* pre, list* next );

int main(void)
{
	
	list *a = new list;
	list *b = new list;
	list *c = new list;
	list_init(a,1,NULL,b);
	list_init(b,2,a,c);
	list_init(c,4,b,NULL);

	cout<<a->num<<a->next->num<<a->next->next->num<<endl;//测试链表
	list *d = new list;
	list *e = new list;
	list *f = new list;
	list_init(d,1,NULL,e);
	list_init(e,3,d,f);
	list_init(f,4,e,NULL);

	cout<<d->num<<d->next->num<<d->next->next->num<<endl;

	list_merge(a,d);//合并a d链表

	while(a)//输出a链表
	{
		cout<<a->num<<endl;
		a = a->next;
	}
	
	getchar();
	return 0;
}

void list_merge(list* a0,list* a1)
{	
	list*cur_a1 = a1;

	while(a0){
		cur_a1 = a1->next;
		a1->next = a0->next;
		if(a0->next != NULL)
			a0->next->pre = a1;
		a0->next = a1;
		a1->pre = a0;

		a0 = a1->next;
		a1 = cur_a1;
	}
}

void list_init(list* a ,int num, list* pre, list* next )
{
	a->num = num;
	a->pre = pre;
	a->next = next;
}