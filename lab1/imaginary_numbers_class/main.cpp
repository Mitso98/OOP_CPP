#include <iostream>

using namespace std;

class Complex{

private:
    int m_real, m_imag;

public:
    int getReal()
    {
        return this->m_real;
    }
    int getImag()
    {
        return this->m_imag;
    }
    void setReal(int real)
    {
        m_real = real;
    }
    void setImag(int imag)
    {
        m_imag = imag;
    }
    void add(Complex comp)
    {
        m_real += comp.getReal();
        m_imag += comp.getImag();
    }
    void subtract(Complex comp)
    {
        m_real -= comp.getReal();
        m_imag -= comp.getImag();
    }
    void print()
    {
        if (m_imag > 0)
            cout << m_real << " + " << m_imag << "i";
        else
            cout << m_real << " - " << m_imag << "i";
    }

};

int main()
{
    Complex comp1, comp2;

    comp1.setImag(10);
    comp1.setReal(5);

    comp2.setImag(6);
    comp2.setReal(12);

    cout << "Before addition:\n";

    comp1.print();

    comp1.add(comp2);

    cout << "\nAfter addition:\n";

    comp1.print();
    return 0;
}
