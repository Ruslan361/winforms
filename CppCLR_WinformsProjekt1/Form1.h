#pragma once
#include "Rectangle.h"
namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class Form1 : public System::Windows::Forms::Form
	{


	public:
		Form1(void)
		{
			InitializeComponent();

		}

	protected:

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBoxNum;
	private: System::Windows::Forms::Label^ label4;




	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBoxNum = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"X=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(175, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Y=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(320, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"H= ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(785, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(56, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 7;
			this->textBox1->Text = L"100";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(202, 28);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"300";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(351, 28);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(785, 65);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(785, 109);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Move";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBoxNum
			// 
			this->textBoxNum->Location = System::Drawing::Point(507, 31);
			this->textBoxNum->Name = L"textBoxNum";
			this->textBoxNum->Size = System::Drawing::Size(100, 20);
			this->textBoxNum->TabIndex = 13;
			this->textBoxNum->Text = L"0";
			this->textBoxNum->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxNum_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(476, 31);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(24, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"N= ";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(885, 519);
			this->Controls->Add(this->textBoxNum);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Train^ wagon;
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		wagon = gcnew Train(100, 300, 1, 1);
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	clear();
	int x = Convert::ToInt32(textBox1->Text);
	int y = Convert::ToInt32(textBox2->Text);
	int number = Convert::ToInt32(textBoxNum->Text);
	int hight = Convert::ToInt32(textBox3->Text);
	wagon = gcnew Train(x, y, number, hight);
	Graphics^ b = Form1::CreateGraphics();
	wagon->show(b);
}
void clear() {
	Graphics^ b = Form1::CreateGraphics();
	System::Drawing::SolidBrush brush(System::Drawing::Color::White);
	b->FillRectangle(% brush, 0, 0, 10000, 10000);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	clear();
}


private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	clear();
	wagon->move(10);
	Graphics^ b = Form1::CreateGraphics();
	wagon->show(b);
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxNum_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
