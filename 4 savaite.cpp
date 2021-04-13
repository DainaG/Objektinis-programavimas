#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

//Compiler version g++ 6.3.0
class Numbers{
    public:
        static int Max;
        static int Min;
        void Assign(int, int);
        void Change(int, int);
        void Display();
    private:
        int Num[10];
};

int Numbers::Max = 55;
int Numbers::Min = 0;

void Numbers::Change(int n, int i){
    if (n <= Max && n >= Min)
        Num[i] = n;
    else{
        cout << "Error! Number out of range, try again" << endl;
        return;
    }
}
void Numbers::Display(){
    for (int i = 0; i < 10; i++){
        if (Num[i] <= Max && Num[i] >= Min)
            cout << Num[i] << " ";
    }
}

int main(){
    Numbers num;
    int n;
    for (int i = 0; i < 10; i++){
        cout << "Please insert " << i+1 << " number" << endl;
        cin >> n;
        if (!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error, not numerical" << endl;
            break;
        }
        else{
            num.Change(n, i);
        }
    }
    num.Display();
}