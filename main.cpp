//p.434 문제 3번
/*#include <iostream>
using namespace std;

class Box 
{
private:
	double length;
	double width;
	double height;
public:
	Box(int l = 0, int w = 0, int h = 0) : length(l), width(w), height(h) {  }
	bool operator<(Box& b) 
	{
		if (this->getVolume() < b.getVolume()) return true;
		else return false;
	}
	double getVolume(void) 
	{
		return length * width * height;
	}
	void getItem(void) 
	{
		cout << "상자의 길이 : " << length << endl;
		cout << "상자의 너비 : " << width << endl;
		cout << "상자의 높이 : " << height << endl;
		cout << "상자의 부피 : " << getVolume() << endl << endl;
	}
};

int main(int argc, const char* argv[]) 
{
	Box a(10, 10, 10), b(20, 20, 20);
	cout << "상자 #1" << endl;
	a.getItem();
	cout << "상자 #2" << endl;
	b.getItem();
	if (a < b) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}*/



//p.435 문제 5번
/*#include <iostream>
using namespace std;

class Time 
{
private:
	int hours;
	int minutes;
public:
	Time() : hours(0), minutes(0) {}
	Time(int h, int m) : hours{ h }, minutes{ m }{}
	void displayTime()
	{
		cout << hours << ": " << minutes << endl;
	}
	const Time& operator++() 
	{ 
		if (this->minutes < 59) this->minutes++;
		else if (this->minutes == 59) 
		{
			this->hours++;
			this->minutes = 0;
		}
		return (*this);
	}
};

int main(int argc, const char* argv[]) 
{
	Time t(10, 59);
	t.displayTime();
	++t;
	t.displayTime();
	++t;
	t.displayTime();

	return 0;
}*/



//p.470 student 클래스 작성
/*#include <iostream>
#include <string>
using namespace std;

class Person
{
	string name;
	int birthYear;
public:
	Person(string name, int year)
	{
		this->name = name;
		this->birthYear = year;
	}
	void print()
	{
		cout << "성명 : " << name << endl;
		cout << "출생연도 : " << birthYear << endl;
	}
};
class Student :public Person
{
	string university;
public:
	Student(string name, int year, string university) :Person(name, year)
	{
		this->university = university;
	}
	void print()
	{
		Person::print();
		cout << "대학교 : " << university << endl;
	}
};

int main()
{
	Student s("홍길동", 1997, "한국대학교");
	s.print();
	return 0;
}*/



//p.476 문제 3번
/*#include <iostream>
#include <string>
using namespace std;

class Employee 
{ 
	string name;
	int salary;
public:
	Employee(string n, int s) { name = n; salary = s; }
	void setName(string n) { name = n; } 
	void setSalary(int s) { salary = s; }
	string getName() { return name; } 
	int getSalary() { return salary; }
	int computeSalary() { return salary; }
};

class Manager : public Employee 
{ 
	int bonus;
public:
	Manager(string name, int salary, int bonus) :Employee(name, salary) { this->bonus = bonus; }
	void setBonus(int b) { bonus = b; } 
	int getBonus() { return bonus; }
	int computeSalary() { return getSalary() + bonus; }
};

int main() 
{
	Manager e("김철수", 200, 100); 
	cout << "이름 : " << e.getName() << endl;
	cout << "월급 : " << e.getSalary() << endl;
	cout << "보너스 : " << e.getBonus() << endl;
	cout << "전체 급여 : " << e.computeSalary() << endl;
	return 0;
}*/



//p.506~511 던전 게임 작성
/*#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Sprite
{
protected:
	int x, y;
	char shape;
public:
	Sprite(int x, int y, char shape) : x(x), y(y), shape{ shape } { }
	virtual ~Sprite() {}

	virtual void move(char d) = 0;
	char getShape() { return shape; }

	int getX() { return x; }
	int getY() { return y; }

	bool checkCollision(Sprite *other)
	{
		if (x == other->getX() && y == other->getY())
			return true;
		else
			return true;
	}
};

class Hero : public Sprite
{
public:
	Hero(int x, int y) :Sprite(x, y, 'H') {}
	void draw() { cout << 'H'; }
	void move(char d)
	{
		if (d == 'a') { x -= 1; }
		else if (d == 'w') { y -= 1; }
		else if (d == 's') { y += 1; }
		else if (d == 'd') { x += 1; }
	}
};

class Treasure : public Sprite
{
public:
	Treasure(int x, int y) :Sprite(x, y, 'T') {}
	void move(char d) {}
};

class Enemy : public Sprite
{
public:
	Enemy(int x, int y) :Sprite(x, y, 'E') {}
	void move(char d) {}
};

class Board
{
	char *board;
	int width, height;
public:
	Board(int w, int h) :width(w), height(h)
	{
		board = new char[width * height];
		clearBoard();
	}
	~Board()
	{
		delete board;
	}
	void setValue(int r, int c, char shape)
	{
		board[r * width + c] = shape;
	}
	void printBoard()
	{
		for (int i = 0; i < height; i++)
		{
			cout << "\t";
			for (int j = 0; j < height; j++)
				cout << board[i * width + j];
			cout << endl;
		}
	}
	void clearBoard()
	{
		for (int i = 0; i < height; i++)
			for (int j = 0; j < height; j++)
				board[i * width + j] = '.';
	}
};

void drawLine(char x)
{
	cout << endl;
	for (int i = 0; i < 100; i++)
		cout << x;
	cout << endl;
}

int main()
{
	vector<Sprite *> list;
	int width, height;

	cout << "보드의 크기를 입력하시오[최대 10x10] : " << endl;
	cout << "가로 : ";
	cin >> width;
	cout << "세로 : ";
	cin >> height;

	Board board(height, width);
	list.push_back(new Hero(0, 0));
	list.push_back(new Treasure(height - 1, width - 1));
	list.push_back(new Enemy(3, 3));

	drawLine('*');
	cout << "이 게임의 목표는 함정(T)이나 적(E)을 만나지 않고 보물에 도달하는 것이다. ";
	cout << "주인공은 a, s, w, d 키를 이용하여 움직일 수 있다. " << endl;
	drawLine('*');
	cout << endl;
	
	while (true)
	{
		board.clearBoard();
		for (auto& e : list)
			board.setValue(e->getY(), e->getX(), e->getShape());
		board.printBoard();

		char direction;
		cout << "어디로 움직일까요(a, s, w, d) : ";
		cin >> direction;

		for (auto& e : list)
			e->move(direction);
		drawLine('-');
	}

	for (auto& e : list)
		delete e;
	list.clear();
	return 0;
}*/



//p.514 문제 2번
 


//p.590 문제 3번



//p.591 문제 4번



//p.592 문제 7번


