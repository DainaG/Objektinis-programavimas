#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;

void BubbleSort(vector<int>&, vector<string>&);

//template <int FROM, int TO>
// Nedirba, nelabai suprantu kodël ir nebeturiu laiko. Atsipraðau.
/*class T{
    public:
        class iterator: public std::iterator<
            std::input_iterator_tag,
            int,
            int,
            const int*,
            int
                >{
            int num = FROM;
        public:
            explicit iterator(int _num = 0) : num(_num){}
            iterator& operator++() {num = TO >= FROM ? num + 1: num - 1; return *this;}
            iterator operator++(int) {iterator retval = *this; ++(*this); return retval;}
            bool operator==(iterator other) const {return num == other.num;}
            bool operator!=(iterator other) const {return !(*this == other);}
            reference operator*() const {return num;}
    };
    iterator begin() {return iterator(FROM);}
    iterator end() {return iterator(TO >= FROM? TO+1 : TO-1);}
};*/

int main(){
    int num;
    string word;
    bool tr = true;
    vector<int> narr;
    vector<string> sarr;
    vector<int>::iterator it;
    vector<string>::iterator st;
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
    BubbleSort(narr, sarr);
    /* 1 */
    for (it = narr.begin(); it <= narr.end(); it++)
        cout << *it << " ";
    cout << endl;
    for (st = sarr.begin(); it != sarr.end(); it++)
        cout << *it << " ";
}

/* 2 */
void BubbleSort(vector<int> &narr, vector<string> &sarr){
    bool S;
    int n = narr.size();
    //cout << n << endl;
    for (int i = 0; i < n-1; i++){
        S = false;
        for (int j = 0; j < n-i-1; j++){
            if (narr[j] > narr[j+1]){
                int t = narr[j];
                narr[j] = narr[j+1];
                narr[j+1] = t;
                S = true;
                //cout << narr[j] << " " << narr[j+1] << endl;
            }
        }
        if (S == false)
            break;
    }
    n = sarr.size();
    //cout << n << endl;
    for (int i = 0; i < n-1; i++){
        S = false;
        for (int j = 0; j < n-i-1; j++){
            if (sarr[j] > sarr[j+1]){
                string t = sarr[j];
                sarr[j] = sarr[j+1];
                sarr[j+1] = t;
                S = true;
                //cout << sarr[i] << " " << sarr[j] << endl;
            }
        }
        if (S == false)
            break;
    }
}
