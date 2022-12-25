#include <iostream>

using namespace std;

class Complex
{

private:
    float m_real, m_imag;
    static int counter;
public:
    Complex()
    {
        m_real = 0;
        m_imag = 0;
        counter++;
        cout<<"Object " << counter <<  " has been created successfully."<<endl;
    }
    Complex(float n)
    {
        m_real = n;
        m_imag = n;
        counter++;
        cout<<"Object " << counter <<  " has been created successfully."<<endl;
    }
    Complex(float real, float imag)
    {
        m_real = real;
        m_imag = imag;
        counter++;
        cout<<"Object " << counter <<  " has been created successfully."<<endl;
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
        cout << "#############################################" << endl;
        if (m_imag > 0)
            cout << m_real << " + " << m_imag << "i" << endl;
        else
            cout << m_real << " - " << m_imag << "i" << endl;
        cout << "#############################################" << endl;
    }
    void operator = (Complex x)
    {
        this->m_real = x.m_real;
        this->m_imag = x.m_imag;

    }
    Complex operator + (Complex x)
    {
        int real = this->m_real + x.m_real;
        int imag = this->m_imag + x.m_imag;

        Complex tmp(real, imag);

        return tmp;
    }
    Complex operator + (float f)
    {
        Complex tmp;
        tmp.m_real = m_real + f;
        tmp.m_imag = m_imag;
        return tmp;

    }
    friend Complex operator + (float f, Complex x);
    Complex operator - (Complex x)
    {
        int real = this->m_real - x.m_real;
        int imag = this->m_imag - x.m_imag;

        Complex tmp(real, imag);

        return tmp;
    }
    void operator += (Complex x)
    {
        this->m_real += x.m_real;
        this->m_imag += x.m_imag;
    }
    void operator -= (Complex x)
    {
        this->m_real -= x.m_real;
        this->m_imag -= x.m_imag;
    }
    int operator == (Complex x)
    {
        if (this->m_real == x.m_real && this->m_imag == x.m_imag)
            return 1;
        return 0;
    }
    Complex operator ++ ()
    {
        m_real++; //this->m_real
        return *this;
    }
    Complex operator ++ (int)
    {
        Complex tmp = *this;
        m_real++; //this->m_real
        return tmp;
    }
    operator float()
    {
        // no return for casting operator as it automatically returns the type it casting to
        return m_real;
    }
    ~Complex()
    {
        cout<<"Object " << counter <<  " has been terminated successfully."<<endl;
        counter--;
    }
};
int Complex::counter = 0;
    Complex operator + (float f, Complex x)
    {
        Complex tmp;
        tmp.m_real = x.m_real + f;
        tmp.m_imag = x.m_imag;
        return tmp;
    }
int main()
{
    Complex comp1(5, 10);

    cout << "Before addition:\n";

    comp1.print();

    comp1.add(comp2);

    cout << "\nAfter addition:\n";

    comp1.print();


    comp1 = comp2;
    comp1 = comp1 + comp2;
    comp1 += comp2;
    comp1 -= comp2;
    comp1 -= comp2;


    if(comp1 == comp2)
        cout << "True" <<endl;
    else
        cout << "False" <<endl;

    comp1++;
    ++comp1;

    comp1 = 6 + comp1;
    comp1.print();


    cout<<"#### casting ####"<<endl;
    cout << (float) comp2 << endl;
    cout<<"#### casting ####"<<endl;
    return 0;
}
