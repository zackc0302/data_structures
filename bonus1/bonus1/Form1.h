#pragma once
#include<time.h>
#include<iostream>
#include<cmath>

/*binary exponentiation(recursive)*/
long long binpowr(long long a, long long b) {
	if (b == 0) return 1;
	long long res = binpowr(a, b / 2);
	if (b % 2) return res * res * a;
	else return res * res;
}

/*binary exponentiation(iterative)*/
long long binpowi(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

/*Horner's Method(陣列, 項數(陣列大小), X的值)*/
int horner(int poly[], int n, int x)
{
	int result = poly[0]; // Initialize result 

	// Evaluate value of polynomial using Horner's method 
	for (int i = 1; i < n; i++)
		result = result * x + poly[i];

	return result;
}

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;

	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1588, 595);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->splitContainer1);
			this->tabPage1->Location = System::Drawing::Point(4, 32);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1580, 559);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Power / Exponentiation";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->AllowDrop = true;
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->button4);
			this->splitContainer1->Panel1->Controls->Add(this->label6);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox4);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox3);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox2);
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox1);
			this->splitContainer1->Panel1->Controls->Add(this->textBox2);
			this->splitContainer1->Panel1->Controls->Add(this->textBox3);
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->listBox1);
			this->splitContainer1->Size = System::Drawing::Size(1574, 553);
			this->splitContainer1->SplitterDistance = 367;
			this->splitContainer1->SplitterWidth = 3;
			this->splitContainer1->TabIndex = 1;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(31, 424);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(315, 51);
			this->button4->TabIndex = 18;
			this->button4->Text = L"remove data";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(25, 144);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(146, 32);
			this->label6->TabIndex = 10;
			this->label6->Text = L"次數(times)";
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(54, 321);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(306, 27);
			this->checkBox4->TabIndex = 9;
			this->checkBox4->Text = L"squaring_>>-位元運算(底數限用2)";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(120, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(93, 30);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"2";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(54, 276);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(163, 27);
			this->checkBox3->TabIndex = 8;
			this->checkBox3->Text = L"squaring-快速冪";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(64, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"x=";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(54, 230);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(103, 27);
			this->checkBox2->TabIndex = 7;
			this->checkBox2->Text = L"pow(x,n)";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(64, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"n=";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(54, 186);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(98, 27);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"for-loop";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(120, 84);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(93, 30);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"50";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(177, 148);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(152, 30);
			this->textBox3->TabIndex = 5;
			this->textBox3->Text = L"100000000";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(31, 354);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(315, 54);
			this->button1->TabIndex = 4;
			this->button1->Text = L"x^n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 23;
			this->listBox1->Location = System::Drawing::Point(0, 0);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(1200, 549);
			this->listBox1->TabIndex = 10;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->splitContainer2);
			this->tabPage2->Location = System::Drawing::Point(4, 32);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1580, 559);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Polynomials";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(3, 3);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->AutoScroll = true;
			this->splitContainer2->Panel1->Controls->Add(this->button3);
			this->splitContainer2->Panel1->Controls->Add(this->label5);
			this->splitContainer2->Panel1->Controls->Add(this->button2);
			this->splitContainer2->Panel1->Controls->Add(this->label3);
			this->splitContainer2->Panel1->Controls->Add(this->textBox6);
			this->splitContainer2->Panel1->Controls->Add(this->textBox4);
			this->splitContainer2->Panel1->Controls->Add(this->label4);
			this->splitContainer2->Panel1->Controls->Add(this->textBox5);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->listBox2);
			this->splitContainer2->Size = System::Drawing::Size(1574, 553);
			this->splitContainer2->SplitterDistance = 250;
			this->splitContainer2->SplitterWidth = 3;
			this->splitContainer2->TabIndex = 17;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(20, 174);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(198, 33);
			this->button3->TabIndex = 17;
			this->button3->Text = L"remove data";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 23);
			this->label5->TabIndex = 14;
			this->label5->Text = L"size: ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(20, 135);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(198, 33);
			this->button2->TabIndex = 16;
			this->button2->Text = L"random poly.";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(28, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"x=";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(108, 27);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(93, 30);
			this->textBox6->TabIndex = 15;
			this->textBox6->Text = L"10";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(108, 99);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(93, 30);
			this->textBox4->TabIndex = 4;
			this->textBox4->Text = L"7";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(28, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 23);
			this->label4->TabIndex = 12;
			this->label4->Text = L"range: ";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(108, 63);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(93, 30);
			this->textBox5->TabIndex = 13;
			this->textBox5->Text = L"50";
			// 
			// listBox2
			// 
			this->listBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 31;
			this->listBox2->Location = System::Drawing::Point(0, 0);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(1321, 553);
			this->listBox2->TabIndex = 11;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1588, 595);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Name = L"Form1";
			this->Text = L"bonus1_111701026";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		clock_t start1, end1, start2, end2, start3, end3, start4, end4;

		if (checkBox1->Checked) {
			double singleDuration = 0.0;
			double totalDuration = 0.0;
			long long int x = int::Parse(textBox1->Text);
			long long int n = int::Parse(textBox2->Text);
			long long int s = int::Parse(textBox3->Text);
			long long int result;
			start1 = clock();
			for (long long int i = 0; i < s; i++) {
				result = 1;
				for (long long int j = 0; j < n; j++) {
					result *= x;
				}
			}
			end1 = clock();

			totalDuration = (double)(end1 - start1) / CLOCKS_PER_SEC;
			singleDuration = totalDuration / s;
			listBox1->Items->Add("for-loop: " + result + "==>[" + totalDuration + "(sec.)]==>" + s + "times.");
		}
		//pow(double x, double n)函式庫
		if (checkBox2->Checked) {
			double singleDuration = 0.0;
			double totalDuration = 0.0;
			double x = double::Parse(textBox1->Text);
			double n = double::Parse(textBox2->Text);
			int s = int::Parse(textBox3->Text);
			double result2 = 1;
			start2 = clock();
			for (long long int i = 0; i < s; i++) {
				result2 = pow(x, n);
			}
			end2 = clock();
			totalDuration = (double)(end2 - start2) / CLOCKS_PER_SEC;
			singleDuration = totalDuration / s;
			listBox1->Items->Add("pow(k, n)=" + result2 + "==>[" + totalDuration + "(sec.)]==>" + s + "times.");
		}
		//快速冪
		if (checkBox3->Checked) {
			double singleDuration = 0.0;
			double totalDuration = 0.0;
			long long x = long::Parse(textBox1->Text);
			long long n = long::Parse(textBox2->Text);
			int s = int::Parse(textBox3->Text);
			long long result3=1;
			start3 = clock();
			while (n > 0) {
				if (n % 2 == 1) { 
					result3 *= x;
				}
				x = (x * x);
				n = n >> 1;
			}
			end3 = clock();
			totalDuration = (double)(end3 - start3) / CLOCKS_PER_SEC;
			singleDuration = totalDuration / s;
			listBox1->Items->Add("squaring " +result3 + "==>[" + totalDuration + "(sec.)]==>" + s + "times.");
		}
		if (checkBox4->Checked) {
			double singleDuration = 0.0;
			double totalDuration = 0.0;
			int x = int::Parse(textBox1->Text);
			int n = int::Parse(textBox2->Text);
			int s = int::Parse(textBox3->Text);
			long long result4;
			start4 = clock();
			for (int j = 0; j < s; j++) {
				result4 = 1LL << n;
			}
			end4 = clock();
			totalDuration = (double)(end4 - start4) / CLOCKS_PER_SEC;
			singleDuration = totalDuration / s;
			listBox1->Items->Add("squaring_>> " + result4 + "==>[" + totalDuration + "(sec.)]==>" + s + "times.");
		}
		listBox1->Items->Add("=================================================");
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int size = int::Parse(textBox6->Text);
	int range = int::Parse(textBox5->Text);
	int x = int::Parse(textBox4->Text);
	int i;
	/*動態宣告一維陣列*/
	int* array;
	array = new int[size];
	srand(time(NULL));
	for (i = 0; i < size; i++)	array[i] = rand()%range*2-range;
	listBox2->Items->Add("random coef.: ");
	String^ f = "f(x)=";
	f += array[size - 1];
	int cnt = 1;
	for (int i = size - 2; i >= 0; i--) {
		if (array[i] > 0)
			f += "+" + array[i] + "(x^" + cnt++ + ")";
		else if (array[i] == 0) { cnt++; continue; }
		else if (array[i] < 0)
			f += array[i] + "(x^" + cnt++ + ")";
	}
	listBox2->Items->Add(f);

	for (i = 0; i < size; i++) listBox2->Items->Add(array[i]+"=>"+(size-i-1)+"次方");
	int ans = horner(array, size, x);
	listBox2->Items->Add(ans);
	
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	listBox2->Items->Clear();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	listBox1->Items->Clear();
}
};
	}
