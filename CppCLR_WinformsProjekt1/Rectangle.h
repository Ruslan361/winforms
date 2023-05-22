#pragma once
#include "Form1.h"
#include <vector>

namespace CppCLRWinformsProjekt {
ref class Rectangle
{
public:
	int x;
	int y;
	int width;
	int height;

	Rectangle(int x_, int y_, int width_, int height_)
	{
		x = x_;
		y = y_;
		width = width_;
		height = height_;
	}

	virtual void show(System::Drawing::Graphics^ g) = 0;

	void Move(int dx)
	{
		x += dx;
	}
};


	//класс Тело вагона
ref class WagonBody : public Rectangle {

public:
	WagonBody(int x_, int y_, int width_, int height_) : Rectangle(x_, y_, width_, height_) {}
	void show(System::Drawing::Graphics^ b) override {
		System::Drawing::SolidBrush brush(System::Drawing::Color::Black);
		b->FillRectangle(% brush, x, y, width, height);
	}
};



// класс Окно
ref class Window : public Rectangle {
public:
	Window(int x_, int y_, int width_, int height_) : Rectangle(x_, y_, width_, height_) {}
	void show(System::Drawing::Graphics^ w) override {
		System::Drawing::SolidBrush brush(System::Drawing::Color::LightBlue);
		w->FillRectangle(% brush, x, y, width, height);
	}
};



// класс Дверь
ref class Door : public Rectangle {
public:
	Door(int x_, int y_, int width_, int height_) : Rectangle(x_, y_, width_, height_) {}
	void show(System::Drawing::Graphics^ d) override {
		System::Drawing::SolidBrush brush(System::Drawing::Color::Brown);
		d->FillRectangle(% brush, x, y, width, height);
	}
};


// класс Труба
ref class Smokestack : public Rectangle {
public:
	Smokestack(int x_, int y_, int width_, int height_) : Rectangle(x_, y_, width_, height_) {}
	void show(System::Drawing::Graphics^ s) override {
		System::Drawing::SolidBrush brush(System::Drawing::Color::Red);
		s->FillRectangle(% brush, x, y, width, height);
	}
};



// класс Колесо
ref class Wheel : public Rectangle {
public:
	Wheel(int x_, int y_, int diameter) : Rectangle(x_, y_, diameter, diameter) {}
	void show(System::Drawing::Graphics^ wh) override {
		System::Drawing::SolidBrush brush(System::Drawing::Color::Black);
		wh->FillEllipse(% brush, x, y, width, height);
	}
};



// класс сцепки
ref class Coupling {
public:
	int x1, y1, x2, y2; // координаты сцепки 

	Coupling(int x1, int y1, int x2, int y2) { // конструктор сцепки 
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	void show(System::Drawing::Graphics^ c) override {
		System::Drawing::Pen myPen(System::Drawing::Color::Black);
		c->DrawLine(% myPen, x1, y1, x2, y2);
	}
};



ref class EngineLine { // класс движка линии 
public:
	int x1, y1, x2, y2; // координаты линии 

	EngineLine(int x1, int y1, int x2, int y2) { // конструктор линии 
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	void show(System::Drawing::Graphics^ e) override {
		System::Drawing::Pen myPen(System::Drawing::Color::Green);
		myPen.Width = 3;
		e->DrawLine(% myPen, x1, y1, x2, y2);
	}

	void move(int dx, int dy) { // метод для передвижения линии на заданное расстояние на оси x и y 
		x1 += dx;
		y1 += dy;
		x2 += dx;
		y2 += dy;
	}
};

ref class Wagon {
public:
	WagonBody body;
	Door door;
	Window window1;
	Window window2;
	Window window3;
	Wheel wheel1, wheel2;
	Coupling coupling;

	Wagon(int x, int y, int h) :body(x, y, 250*h, 130*h), door(x + 20*h, y + 50*h, 40*h, 80*h),
		window1(x + 80*h, y + 35*h, 40*h, 40*h), window2(x + 130*h, y + 35*h, 40*h, 40*h) ,
		window3(x + 180*h, y + 35*h, 40*h, 40*h),wheel1(x+20*h,y+127*h,50*h), wheel2(x + 180*h, y + 127*h, 50*h),
		coupling(x,y+130*h,x-20*h,y+130*h){}/* smokestack(x + 90, y + 10, 10, 30), wheel1(x + 10, y + 40, 20, 20), wheel2(x + 70, y + 40, 20, 20) {}*/

	void show(System::Drawing::Graphics^ wag) {
		body.show(wag);
		door.show(wag);
		window1.show(wag);
		window2.show(wag);
		window3.show(wag);
		wheel1.show(wag);
		wheel2.show(wag);
		coupling.show(wag);
	}

	void move(int dx) {
		body.x += dx;
		door.x += dx;
		window1.x += dx;
		window2.x += dx;
		window3.x += dx;
		wheel1.x += dx;
		wheel2.x += dx;
		coupling.x1 += dx;
		coupling.x2 += dx;
	}
};
ref class Train {
public:
	EngineLine engine;
	Wagon wagon;
	Smokestack smokestack;
	int num_wagons;
	int h;

	Train(int x, int y, int _num_wagons, int h) :engine((x + 65*h), y + 150*h, x + 225*h, y + 150*h), wagon( x, y,h), smokestack(x + 180*h, y - 40*h, 20*h,40*h ), num_wagons(_num_wagons){
		this->h = h;
	}

	void show(System::Drawing::Graphics^ g) {
		wagon.show(g);
		smokestack.show(g);
		for (size_t i = 1; i <= num_wagons; i++)
		{
			Wagon wag(wagon.body.x - i * 270*h, wagon.body.y, h);
			wag.show(g);
		}
		System::Drawing::Pen myPen(System::Drawing::Color::Green);
		myPen.Width = 3;
		double speed = 0.015;
		int x = wagon.body.x;
		int y = wagon.body.y;
		g->DrawLine(% myPen, x + 180 * h + 25 *h , y + 127 * h + 25*h, x + 180 * h +25*h +int( 25 * cos(x * speed)), y + 180 * h - 25*h + int(25*h * sin(x*speed)));
		g->DrawLine(% myPen, x + 20 * h + 25 * h, y + 127 * h + 25 * h, x + 20 * h + 25*h + int(25 * cos(x * speed)), y + 180 * h - 25*h + int(25*h * sin(x * speed)));
		engine.x1 = x + 180 * h + 25 * h + int(25 * cos(x * speed));
		engine.x2 = x + 20 * h + 25 * h + int(25 * cos(x * speed));
		engine.y1 = y + 180 * h - 25 * h + int(25 * h * sin(x * speed));
		engine.y2 = y + 180 * h - 25 * h + int(25 * h * sin(x * speed));
		engine.show(g);
	}

	void move(int dx) {
		engine.move(dx,0);
		wagon.move(dx);
		smokestack.Move(dx);
	}
};
}
