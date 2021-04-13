/* 1 */
/*
#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main(){
    int size;
    bool tr = true;
    vector<int> arr;
	while (tr == true){
        cout << "Please insert element ";
        cin >> size;
        if (size != 0){
            arr.push_back(size);
        }
        else{
            tr = false;
        }
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
*/
/* 1.2 */
/*
#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;

int main(){
    string size;
    bool tr = true;
    vector<string> arr;
	while (tr == true){
        cout << "Please insert element ";
        cin >> size;
        if (size != "-"){
            arr.push_back(size);
        }
        else{
            tr = false;
        }
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}*/

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
    vector<int> arr;
	while (tr == true){
        cout << "Please insert element ";
        cin >> size;
        if (size != 0){
            arr.push_back(size);
        }
        else{
            tr = false;
        }
    }
	int size = sizeof(arr)/sizeof(arr[0]);
	BubbleSort(arr, size);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
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