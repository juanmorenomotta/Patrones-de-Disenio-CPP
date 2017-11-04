#include <iostream>
using namespace std;

class StackIterator;

class AbstractStack{
    int items[10];
    int sp;
  public:
    friend class StackIterator;
    Stack();
    void push(int);
    int pop();
    bool isEmpty();
    StackIterator *createIterator() const; // 2. Add a createIterator() member
};

class Stack : public AbstractStack
{
    int items[10];
    int sp;
  public:
    friend class StackIterator;
    Stack()
    {
        sp =  - 1;
    }
    void push(int in)
    {
        items[++sp] = in;
    }
    int pop()
    {
        return items[sp--];
    }
    bool isEmpty()
    {
        return (sp ==  - 1);
    }
	StackIterator *createIterator() const; // 2. Add a createIterator() member
};

class AbstractListIterator{
        const Stack *stk;
        int index;

    public:
        StackIterator(const Stack *_stack);
        void first();
        void next();
        bool isDone();
        int currentItem();
};

class StackIterator : public AbstractListIterator
{
    // 1. Design an "iterator" class
    const Stack *stk;
    int index;

  public:
    StackIterator(const Stack *_stack)
    {
        stk = _stack;
    }

    void first()
    {
        index = 0;
    }

    void next()
    {
        index++;
    }
    bool isDone()
    {
        return index == stk->sp + 1;
    }
    int currentItem()
    {
        return stk->items[index];
    }
};

StackIterator *Stack::createIterator() const
{
  return new StackIterator(this);
}

bool operator == (const Stack &l, const Stack &r)
{
  // 3. Clients ask the container object to create an iterator object
  StackIterator *itl = l.createIterator();
  StackIterator *itr = r.createIterator();
  // 4. Clients use the first(), isDone(), next(), and currentItem() protocol
  for (itl->first(), itr->first(); !itl->isDone(); itl->next(), itr->next())
    if (itl->currentItem() != itr->currentItem())
      break;
  bool ans = itl->isDone() && itr->isDone();
  delete itl;
  delete itr;
  return ans;
}

int main()
{
  Stack s1;
  for (int i = 1; i < 5; i++)
    s1.push(i);
  Stack s2(s1), s3(s1), s4(s1), s5(s1);
  s3.pop();
  s5.pop();
  s4.push(2);
  s5.push(9);
  cout << "1 == 2 es " << (s1 == s2) << endl;
  cout << "1 == 3 es " << (s1 == s3) << endl;
  cout << "1 == 4 es " << (s1 == s4) << endl;
  cout << "1 == 5 es " << (s1 == s5) << endl;
}
