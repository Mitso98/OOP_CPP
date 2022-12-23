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
            cout << "##################### Stack Items #####################" << endl;
            for (int i=0; i<m_tos; i++)
            {
                cout<<m_stack[i]<<endl;
            }
            cout << "##################### Stack Items #####################" << endl;
        }
        cout<<"Stack is empty!"<<endl;
    }
    ~Stack()
    {
        cout << "Stack number " << m_number_of_stacks << " has been terminated" << endl;
        delete[] m_stack;
        m_number_of_stacks--;
    }


};
int Stack::m_number_of_stacks = 0;

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
    return 0;
}
