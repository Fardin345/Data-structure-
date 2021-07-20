
#include <iostream>

using namespace std;
//terms of polynomial
class Term
{
 public:
    int coeff;
    int Exp;
};
//Polynomial class 
class Polynomial 
{
private:
    int n;
    Term* t;
public:
    Polynomial(int n) 
    {
        this->n = n;
        t = new Term[n];
    }

    
    ~Polynomial() 
    {
        delete[]t;
    }

    Polynomial operator+(Polynomial &p);
    friend istream& operator>>(istream& is, Polynomial& p);
    friend ostream& operator<<(ostream& is, Polynomial& p);
};

istream& operator>>(istream &is, Polynomial& p) 
{
    cout << "Enter non-zero terms: ";
    for (int i = 0; i < p.n; i++)
    {
        cin >> p.t[i].coeff >> p.t[i].Exp;
    }

    return is;
}


ostream& operator<<(ostream &os, Polynomial& p) 
{
    for (int i = 0; i < p.n; i++)
    {
        cout << "Coefficient: " << p.t[i].coeff << "  " << "Power: " << p.t[i].Exp;
        cout << endl;
    }

    return os;
}

Polynomial Polynomial::operator+(Polynomial &p)
{
    Polynomial *p3 = new Polynomial(n+p.n);
    int i = 0, j = 0, k = 0;
    while (i < n && j < p.n) 
    {
        if (t[i].Exp > p.t[j].Exp)
            p3->t[k++] = t[i++];
        else if (t[i].Exp < p.t[j].Exp)
            p3->t[k++] = p.t[j++];
        else 
        {
            p3->t[k].Exp = t[i].Exp;
            p3->t[k++].coeff = t[i++].coeff + p.t[j++].coeff;
        }
        
    } 
    for (; i < n; i++) p3->t[k++] = t[i++];
    for (; j < p.n; j++) p3->t[k++] = p.t[j++];
    p3->n = k;
    return *p3;
}

int main()
{
    Polynomial p1(3);
    Polynomial p2(5);
    cin >> p1;
    cin >> p2;

    Polynomial p3 = p1 + p2;  
    

    cout << p1 <<endl;
    cout << p2 << endl;

    cout << p3 << endl;
    return 0;
}





