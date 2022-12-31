#include <iostream>

using namespace std;
template <class T>
class Stack
{
    int top;
    int sizeofstack;
    T *ptr;
    static int counter;
public:
    Stack();
    Stack(int n);
    ~Stack();
    static int getCounter();
    Stack (Stack &);
    void push(T);
    T pop();
    Stack& operator= (Stack&);
    friend void viewContent(Stack);
};
template <class T>
int Stack<T>::counter=0;
template <class T>
Stack<T>::Stack()
{
    top=0;
    sizeofstack=10;
    ptr= new T[sizeofstack];
    counter++;
};
template <class T>
Stack<T>::Stack(int n)
{
    sizeofstack = n;
    ptr = new int[sizeofstack];
    top = 0;
    counter=0;

};
template <class T>
Stack<T>::~Stack()
{
    delete[] ptr;
    cout<<"This is the destructor"<<endl;
    counter--;
    cout<<"destructor counter = "<<counter<<endl;

};
template <class T>
void Stack<T>::push(T x)
{
    if (top == sizeofstack)
    {
        cout<<"Stack is full"<<endl;
    }
    else
    {
        ptr[top]=x;
        (top)++;
        counter++;
    }
};
template <class T>
T Stack<T>::pop()
{
    int retVal;

    if (top==0)
    {
        cout<<"Stack is empty"<<endl;
        retVal = -1;

    }
    else
    {
        (top)--;
        retVal = ptr[top];

    }
    return retVal;
};
template <class T>
int Stack<T>::getCounter()
{
    return counter;
}
/*void viewContent(Stack x)
{
    int t=x.top;
    while (t != 0)
    {
        cout<<x.ptr[--t]<<endl;
    }
}*/

int main()
{
    Stack<int> s1(5);
    s1.push(4);
    s1.push(3);
    s1.push(5);
    cout<<"the count is : "<<s1.getCounter()<<endl;
    cout<<"first integer is : "<<s1.pop()<<endl;
    cout<<"second integer is : "<<s1.pop()<<endl;


    return 0;
}
