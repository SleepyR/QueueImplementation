#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
};

template <class T>
class Queue
{
  private:
  Node<T>* head;
  Node<T>* tail;
  public:
  Queue()
  {
    head=NULL;
    tail=NULL;
  }
  ~Queue()
  {
    delete head;
    delete tail;
  }
  bool is_empty()
  {
    return head==NULL;
  }
  void enqueue(T data)
  {
    Node<T>* temp=new Node<T>;
    Node<T>* pre=new Node<T>;
    temp->data=data;
    temp->next=NULL;
    if(is_empty())
    {
      head=temp;
      tail=head;
    }
    else
    {
      pre=tail;
      tail->next=temp;
      tail=temp;
    }
  }
  void dequeue()
  {
    head=head->next;
  }
  T get_front()
  {
    return head->data;
  }
};


int main() {
  Queue<int>* q=new Queue<int>();
  q->enqueue(5);
  q->enqueue(15);
  q->enqueue(115);
  q->enqueue(1115);
  cout<<q->is_empty()<<endl;
  cout<<q->get_front()<<endl;
  q->dequeue();
  cout<<q->get_front()<<endl;
  q->dequeue();
  cout<<q->get_front()<<endl;
  q->dequeue();
  cout<<q->get_front()<<endl;
  q->dequeue();
  cout<<q->is_empty()<<endl;


}
