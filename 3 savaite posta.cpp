#include <iostream>
#include <vector>
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
		int GetObjectCount(){return objectCount;}
		void Set(float x, float y){ 
			height = x; 
			width = y;
		}
		float GetValueHeight() { return height; }
		float GetValueWidth() { return width; }
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
		int GetObjectCount(){return objectCount;}
		void Set(float x, float y){ 
			height = x; 
			width = y;
		}
		float GetValueHeight() { return height; }
		float GetValueWidth() { return width; }
};

class Kambarys{
	private:
		float height;
		float width;
		float lenght;
		vector<Langas *> window;
		vector<Durys *> door;

	public:
		Kambarys(float x, float y, float z){
			height = x;
			width = y;
			lenght = z;
		}
		~Kambarys(){
		}
		void setlenght(float x) { lenght = x; }
		void setwidth(float x) { width = x; }
		void setheight(float x) { height = x; }
		float getlenght() { return lenght; }
		float getwidth() { return width; }
		float getheight() { return height; }

		void addWindow(Langas* wind){
			window.push_back(wind);
		}
		void addDoor(Durys* doors){
			door.push_back(doors);
		}
		float areaOfWall(){

			float area = 0;
			area += (lenght * height) * 2;
			area += (width * height) * 2;

			for (int i = 0; i < int(window.size()); ++i)
				area -= window[i]->getValueWidth() * window[i]->getValueHeight();
			for (int i = 0; i < int(door.size()); ++i)
				area -= door[i]->getValueWidth() * door[i]->getValueHeight();
			return area;
		}
		float lenghtOfSkirting(){
			float skirting = 0;
			skirting += width * 2 + lenght * 2;
			for (int i = 0; i < int(door.size()); ++i){
				skirting -= door[i]->getValueWidth();
        }
		return skirting;
	}
};

int Langas::objectCount = 0;
int Durys::objectCount = 0;

int main(){
    Langas *lang1 = new Langas(1.0f, 1.0f);
    cout << "Quantity of windows: " << lang1->GetObjectCount() << endl;
    Langas *lang2 = new Langas(1.0f, 1.0f);
    cout << "Quantity of windows: " << lang1->GetObjectCount() << endl;
    Durys *dur1 = new Durys(2.0f, 1.0f);
    cout << "Quantity of doors: " << dur1->GetObjectCount() << endl;
    Durys *dur2 = new Durys(2.0f, 1.0f);
    cout << "Quantity of doors: " << dur2->GetObjectCount() << endl;
    Kambarys *kam = new Kambarys(3.0f, 5.0f,5.0f);
    //Langas langas1(1.0f, 1.0f);
    //Durys durys1(2.0f, 1.0f);
    //Durys durys2(2.0f, 1.0f);
    //Kambarys kamb(3.0f, 5.0f, 5.0f);

    kam->addWindow(lang1);
    kam->addWindow(lang2);
    kam->addDoor(dur1);
    kam->addDoor(dur2);
    cout << "Size of room " << kam->areaOfWall() << endl;
    cout << "Size of floor " << kam->lenghtOfSkirting() << endl;
    delete lang1;
    cout << "Quantity of windows: " << lang1->GetObjectCount() << endl;
    delete lang2;
    cout << "Quantity of windows: " << lang1->GetObjectCount() << endl;
    delete dur1;
    cout << "Quantity of doors: " << dur1->GetObjectCount() << endl;
    delete dur2;
    cout << "Quantity of doors: " << dur1->GetObjectCount() << endl;
    delete kam;
    return 0;
}
