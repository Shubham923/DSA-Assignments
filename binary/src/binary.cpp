#include <iostream>

using namespace std;

class node
{
    int data;
    node *nxt;
    node *prev;
public:
    node()
    {
        data=0;
        nxt=NULL;
        prev=NULL;
    }
    node(int info,node *n=0,node *p=0)
    {
        data=info;
        nxt=NULL;
        prev=NULL;
    }
    friend class link;
};

class link
{
    node *s,*l,*n;
    public:
    link()
    {
        s=NULL;
        l=NULL;
        n=NULL;
    }
    void create(int);
    void display();
    void binary(int);
    friend class node;
};

void link::create(int d)
{
    n=new node;
    n->data=d;
    if(s==NULL)
    {
        n->nxt=NULL;
        n->prev=NULL;
        l=n;
        s=n;
    }
    else
    {
        s->nxt=n;
        n->prev=s;
        s->prev=NULL;
        n->nxt=NULL;
        l=l->nxt;
    }
}

void link::display()
{
    node *c=NULL;
    c=s;
    while(c->nxt!=NULL)
    {
        cout<<c->data<<"\t";
        c=c->nxt;
    }
    if(c->nxt==NULL)
        cout<<c->data;
}

void link::binary(int n)
{

   while(n!=1)
  {
    n=n%2;
    create(n);
    n=n/2;
    binary(n);
  }

	if(n/2==1)
  {
		cout<<1;
  }

}

int main()
{
    link l;

    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;
    l.binary(n);
    l.display();
}

















