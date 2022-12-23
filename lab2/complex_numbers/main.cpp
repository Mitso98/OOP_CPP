#include <iostream>

using namespace std;

class Complex{

private:
    float m_real, m_imag;

public:
    Complex()
    {
        m_real = 0;
        m_imag = 0;
    }
    Complex(float n)
    {
        m_real = n;
        m_imag = n;
    }
    Complex(float real, float imag)
    {
      m_real = real;
      m_imag = imag;
    }
    float getReal()
    {
        return this->m_real;
    }
    float getImag()
    {
        return this->m_imag;
    }
    void setReal(float real)
    {
        m_real = real;
    }
    void setImag(float imag)
    {
        m_imag = imag;
    }
    void setComplex(float real, float imag)
    {
        // sett both attributes at once
        m_real = real;
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
    ~Complex()
    {
        cout<<"This object has been terminated successfully."<<endl;
    }

};

int main()
{
    Complex comp1(5, 10), comp2(3);

    cout << "Before addition:\n";

    comp1.print();

    comp1.add(comp2);

    cout << "\nAfter addition:\n";

    comp1.print();
    return 0;
}
