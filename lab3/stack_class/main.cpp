#include <iostream>

using namespace std;

class Stack{
private:
    int* m_stack;
    int m_tos;
    int m_stack_size;
    static int m_number_of_stacks;

public:
    Stack(int stack_size)
    {
        m_stack = new int[stack_size];
        m_tos = 0;
        m_stack_size = stack_size;
        m_number_of_stacks++;
        cout << "Stack number " << m_number_of_stacks << " has been created." << endl;
        cout << "Size of this stack is " << m_stack_size << endl;
    }
    Stack(Stack &z)
    {
        m_tos = z.m_tos;
        m_stack_size = z.m_stack_size;
        m_stack = new int[m_stack_size];
        for(int i=0;  i < m_tos; i++ )
            m_stack[i] = z.m_stack [i];

        m_number_of_stacks++;
    }
    void push(int value)
    {
        if(m_tos != m_stack_size)
        {
            m_stack[m_tos] = value;
            m_tos++;
            cout << "Value of " << value << " has been inserted!" << endl;
            return;
        }

        cout << "Stack is full!" << endl;
    }
    void pop()
    {
        if( m_tos > 0)
        {
            m_tos--;
            cout << "Value " << m_stack[m_tos] << " has been popped!" << endl;
            return;
        }

        cout << "Stack is already empty!" << endl;
    }
    void print()
    {
        if (0 < m_tos)
        {
            int indx = m_tos;
            cout << "##################### Stack Items #####################" << endl;
            while (0 != indx)
                cout << m_stack[--indx] << endl;
            cout << "##################### Stack Items #####################" << endl;
        }
        cout<<"Stack is empty!"<<endl;
    }
    ~Stack()
    {
        cout << "Stack number " << m_number_of_stacks << " has been terminated" << endl;
        m_number_of_stacks--;
        delete[] m_stack;
    }
    friend void viewContent_value(Stack x);
    friend void viewContent_ref(Stack &x);
};
int Stack::m_number_of_stacks = 0;

void viewContent_value(Stack x)
{
    int c = x.m_tos;

    cout << "############ view_content_by_value ############" << endl;
    while (0 != c)
        cout << x.m_stack[--c] << endl;
    cout << "############ view_content_by_value ############" << endl;
}
void viewContent_ref(Stack &x)
{
    int c = x.m_tos;

    cout << "############ view_content_by_value ############" << endl;
    while (0 != c)
        cout << x.m_stack[--c] << endl;
    cout << "############ view_content_by_value ############" << endl;
}

int main()
{
    Stack s1(5);

    s1.print();
    s1.pop();

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);

    s1.pop();

    s1.print();


    // each time we create a bitwise object without constructor
    // after viewContent finish this class get terminated with the destructor
    // which decrease m_number_of_stacks AKA => 'objects counter'
    viewContent_value(s1); // Destructor: will run saying number 1 was terminated
    viewContent_value(s1);// Destructor: will run saying number 0 was terminated
    viewContent_value(s1);// Destructor: will run saying number -1 was terminated
    // Destructor: will run saying number -2 was terminated,
    // in other words 'main object will be destructed'


    /*
    // only one object will be constructed and then destructed
    // Hence Destructor & Constructor: will run only one time
    // Because we are just dealing with the same object each time
    viewContent_ref(s1);
    viewContent_ref(s1);
    viewContent_ref(s1);
    */

    return 0;
}
