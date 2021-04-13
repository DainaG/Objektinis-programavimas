#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Langas{
	private:
		float height;
		float width;

	public:
		static int objectCount;
		Langas(float x, float y){
			height = x;
			width = y;
			objectCount++;
		}
		~Langas(){
			objectCount--;
		}
		int getObjectCount(){return objectCount;}
		void Set(float x, float y){ 
			height = x; 
			width = y;
		}
		float getValueHeight() { return height; }
		float getValueWidth() { return width; }
};

class Durys{
	private:
		float height;
		float width;

	public:
		static int objectCount;
		Durys(float x, float y){
			height = x;
			width = y;
			objectCount++;
		}
		~Durys(){
			objectCount--;
		}
		int getObjectCount(){return objectCount;}
		void Set(float x, float y){ 
			height = x; 
			width = y;
		}
		float getValueHeight() { return height; }
		float getValueWidth() { return width; }
};

class Kambarys{
	private:
		float height;
		float width;
		float lenght;
		vector<Langas *> wind;
		vector<Durys *> doors;

	public:
		Kambarys(float x, float y, float z){
            height = x;
            width = y;
            lenght = z;
		}
		~Kambarys(){
		}
		void Set(float x, float y, float z) { 
            height = x;
            width = y;
            lenght = z;
        }
		float getlenght() { return lenght; }
		float getwidth() { return width; }
		float getheight() { return height; }
        vector<Langas *> getlangas(){
            return wind;
        }
        float getlangasheight(int i){
            return wind[i]->getValueHeight();
        }
        float getlangaswidht(int i){
            return wind[i]->getValueWidth();
        }
        vector<Durys *> getdurys(){
            return doors;
        }
        float getdurysheight(int i){
            return doors[i]->getValueHeight();
        }
        float getduryswidht(int i){
            return doors[i]->getValueWidth();
        }

		void addWindow(Langas* window){
			wind.push_back(window);
		}
		void addDoor(Durys* door){
			doors.push_back(door);
		}
        /*Kambarys (const Kambarys &k){
            lang = new Langas(kamb.getLangas());
        }
        void getLangas() const { return lang -> lang; }*/
        float getkambarea(){
            float area = 0;
			area += (lenght * height) * 2;
			area += (width * height) * 2;

			for (int i = 0; i < int(wind.size()); ++i)
				area -= wind[i]->getValueWidth() * wind[i]->getValueHeight();
			for (int i = 0; i < int(doors.size()); ++i)
				area -= doors[i]->getValueWidth() * doors[i]->getValueHeight();
			return area;
        }
        float getkambskirting(){
            float skirting = 0;
			skirting += width * 2 + lenght * 2;
			for (int i = 0; i < int(doors.size()); ++i){
				skirting -= doors[i]->getValueWidth();
        }
		return skirting;
        }
};

int Langas::objectCount = 0;
int Durys::objectCount = 0;

float AreaOfWall(Kambarys kam);
float LenghtOfSkirting(Kambarys kam);

float AreaOfWall(Kambarys kam){
    float area = 0;
    float h, w, l;
    h = kam.getheight();
    w = kam.getwidth();
    l = kam.getlenght();
	area += (l * h) * 2;
	area += (w * h) * 2;
	for (int i = 0; i < int(kam.getlangas().size()); i++)
		area -= kam.getlangaswidht(i) * kam.getlangasheight(i);
	for (int i = 0; i < int(kam.getdurys().size()); i++)
		area -= kam.getduryswidht(i) * kam.getduryswidht(i);
    assert(area != kam.getkambarea());
	return area;
}
float LenghtOfSkirting(Kambarys kam){
    float skirting = 0;
	skirting += kam.getheight() * 2 + kam.getlenght() * 2;
	for (int i = 0; i < int(kam.getdurys().size()); i++)
		skirting -= kam.getduryswidht(i);
    assert(skirting != kam.getkambskirting());
	return skirting;
}

int main(){
    Langas *lang1 = new Langas(1.0f, 1.0f);
    cout << "Quantity of windows: " << lang1->getObjectCount() << endl;
    Langas *lang2 = new Langas(1.0f, 1.0f);
    cout << "Quantity of windows: " << lang1->getObjectCount() << endl;
    Durys *dur1 = new Durys(2.0f, 1.0f);
    cout << "Quantity of doors: " << dur1->getObjectCount() << endl;
    Durys *dur2 = new Durys(2.0f, 1.0f);
    cout << "Quantity of doors: " << dur2->getObjectCount() << endl;
    Kambarys *kam = new Kambarys(10.0f, 5.0f, 10.0f);

    kam->addWindow(lang1);
    kam->addWindow(lang2);
    kam->addDoor(dur1);
    kam->addDoor(dur2);
    cout << "Size of room " << AreaOfWall(*kam) << endl;
    cout << "Size of floor " << LenghtOfSkirting(*kam) << endl;
    delete lang1;
    cout << "Quantity of windows: " << lang1->getObjectCount() << endl;
    delete lang2;
    cout << "Quantity of windows: " << lang1->getObjectCount() << endl;
    delete dur1;
    cout << "Quantity of doors: " << dur1->getObjectCount() << endl;
    delete dur2;
    cout << "Quantity of doors: " << dur1->getObjectCount() << endl;
    delete kam;
    return 0;
}
