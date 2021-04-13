#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
using namespace std;

//Compiler version g++ 6.3.0
class Fraction{
    public:
        Fraction(int, int);
        void Simplify();
        int GCD(int, int);
        void ToString();
        void Add(Fraction, Fraction);
        void Bigger();
        void Compare(Fraction, Fraction);
    private:
        int num;
        int denom;
        string fract;
};

Fraction::Fraction(int a, int b){
    if (b == 0){
        throw out_of_range ("Denominator can't be 0!");
    }
    else{
        num = a;
        denom = b;
    }
}
void Fraction::Simplify(){
    int gcd = GCD(num, denom);
    num = num / gcd;
    denom = denom / gcd;
}
int Fraction::GCD(int a, int b){
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
void Fraction::ToString(){
    string snom, sdenom;
    snom = to_string(num);
    sdenom = to_string(denom);
    fract = snom + "/" + sdenom;
    cout << fract << endl;
}
void Fraction::Add(Fraction a, Fraction b){
    int num1, denom1, num2, denom2, num3;
    num1 = a.num;
    denom1 = a.denom;
    num2 = b.num;
    denom2 = b.denom;
    int lcm = (denom1 * denom2)/GCD(denom1, denom2);
    int sum = (num1 * lcm/denom1) + (num2 * lcm/denom2);
    num3 = sum / GCD(sum, lcm);
    lcm = lcm / GCD(sum, lcm);
    //cout << num3 << "/" << lcm << endl;
    Fraction fracsum (num3, lcm);
    fracsum.Simplify();
    fracsum.ToString();
}

void Fraction::Bigger(){
    int nu;
    nu = denom;
    num = num + nu;
}

void Fraction::Compare(Fraction a, Fraction b){
    int num1, denom1, num2, denom2, num3;
    num1 = a.num;
    denom1 = a.denom;
    num2 = b.num;
    denom2 = b.denom;
    int lcm = (denom1 * denom2)/GCD(denom1, denom2);
    int final1 = num1 * lcm/denom1;
    int final2 = num2 * lcm/denom2;
    if (final1 == final2)
        cout << "Equal" << endl;
    if (final1 < final2)
        cout << num2 << "/" << denom2 << " is bigger" << endl;
    if (final1 > final2)
        cout << num1 << "/" << denom1 << " is bigger" << endl;
}

int main(){
    Fraction frac (4, 9);
    frac.Simplify();
    frac.ToString();
    frac.Bigger();
    frac.Simplify();
    frac.ToString();
    Fraction frac2 (5, 9);
    frac2.Simplify();
    frac2.ToString();
    frac2.Bigger();
    frac2.ToString();
    frac.Compare(frac, frac2);
    Fraction frac3 (5, 3);
    frac3.Simplify();
    frac3.ToString();
    frac.Add(frac, frac3);
}