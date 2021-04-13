/* 1 */
/*
#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;


int main(){
    int num;
    string word;
    bool tr = true;
    vector<int> narr;
    vector<string> sarr;
	while (tr == true){
        cout << "Please insert element ";
        cin >> num;
        if (num != 0)
            narr.push_back(num);
        else
            tr = false;
    }
    tr = true;
   while (tr == true){
        cout << "Please insert word ";
        cin >> word;
        if (word != "-")
            sarr.push_back(word);
        else
            tr = false;
    }
    for (auto it = narr.begin(); it != narr.end(); it++)
        cout << *it << " ";
    cout << endl;
    for (auto it = sarr.begin(); it != sarr.end(); it++)
        cout << *it << " ";
}
*/
/* 2 */
/*
#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;

void BubbleSort(int array[], int n);
void Swap (int* x, int* y);

int main(){
    int size;
    bool tr = true;
    vector<int> narr;
    while (tr == true){
        cout << "Please insert element ";
        cin >> size;
        if (size != 0)
            narr.push_back(size);
        else
            tr = false;
    }
    int size = sizeof(narr)/sizeof(narr[0]);
    BubbleSort(arr, size);
    for (int i = 0; i < size; i++)
        cout << narr[i] << " ";
}

void Swap (int* x, int* y){
    int t = *x;
    *x = *y;
    *y = t;
}

void BubbleSort(int array[], int n){
    bool S;
    for (int i = 0; i < n-1; i++){
        S = false;
        for (int j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]){
                Swap(&array[j], &array[j+1]);
                S = true;
            }
        }
        if (S == false)
            break;
    }
}
*/
