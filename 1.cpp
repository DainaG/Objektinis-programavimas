
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using namespace std;

/* Dariau tik iki 2 nes iš tikrųjų negalejau daryti 3 */
                /* Atsiprašau */

class Langas{
    public:
        void Set(float, float);
        float Get();
    private:
        float height;
        float widht;
        float area = height*widht;
};

class Duris{
    public:
        void SetDuris(float, float);
        float GetDuris();
    private:
        float heightD;
        float widhtD;
        float areaD = heightD*widhtD;
};

class Kambarys{
    public:
        void SetKambarys(float, float, float);
        float GetKambarys();
        float AddLangas();
        float AddDuris();
        float GetArea();
    private:
        float heightK;
        float widhtK;
        float lenghtK;
        std::vector<Langas> CantL;
        std::vector<Duris> CantD;
};

float Kambarys::GetKambarys(){
    float h, w, l;
    cout << "Please write the height, widht and lenght of the room" << endl;
    cin >> h >> w >> l;
    return h, w, l;
}
void Kambarys::SetKambarys(float height, float widht, float lenght){
    heightK = height;
    widhtK = widht;
    lenghtK = lenght;
}
float Kambarys::AddLangas(){
    CantL.push_back(Langas());
}
float Kambarys::AddDuris(){
    CantD.push_back(Duris());
}
float Kambarys::GetArea(){
    float hk, wk, areak, areal;
    int max;
    max = sizeof(CantL);
    hk = heightK;
    wk = widhtK;
    areak = hk*wk;
    cout << areak;
    //for (int i = 0; i < max; i++)
    //    areal = CantL + areal;
}

float Duris::GetDuris(){
    float h, w;
    cout << "Please write the height and widht of the door" << endl;
    cin >> h >> w;
    return h, w;
}
void Duris::SetDuris(float height, float widht){
    heightD = height;
    widhtD = widht;
}

float Langas::Get(){
    float h, w;
    cout << "Please write the height and widht of the window" << endl;
    cin >> h >> w;
    return h, w;
}
void Langas::Set(float h, float w){
    height = h;
    widht = w;
}

int main(){
    float h, w, l;
    Duris dur;
    Langas lang;
    Kambarys kam;
    kam.GetKambarys();
    kam.SetKambarys(h, w, l);
    lang.Get();
    lang.Set(h, w);
    kam.AddLangas();
    dur.GetDuris();
    dur.SetDuris(h, w);
    kam.AddDuris();
    kam.GetArea();
    return 0;
}