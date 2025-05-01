#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

struct node {
	int coff, power;
	node* next;
};

node* newNode(int coff, int power) {
	node* p = new node();
	p->coff = coff;
	p->power = power;
	p->next = nullptr;
	return p;
}

node* create_poly() {
	node* header = new node();
	header->next = header;
	return header;
}

void delete_poly(node* header) {
	node* curr = header->next;
	while (curr != header) {
		node* temp = curr;
		curr = curr->next;
		delete temp;
	}
	header->next = header;  // 恢復成空串列(易忘)
}

node* polyA;	node* polyB;	node* polyC;

void insert_term(node* header, int coff, int power) {
	if (coff == 0) return;
	node* curr = header;
	while (curr->next != header && curr->next->power > power)
		curr = curr->next;
	if (curr->next != header && curr->next->power == power) {
		curr->next->coff += coff;
		if (curr->next->coff == 0) {
			node* tmp = curr->next;
			curr->next = tmp->next;
			free(tmp);
		}
		return;
	}
	node* p = newNode(coff, power);
	p->next = curr->next;
	curr->next = p;
}

node* add_poly(node* A, node* B) {
	node* C = create_poly();

	node* p = A->next;
	while (p != A) {
		insert_term(C, p->coff, p->power);
		p = p->next;
	}

	node* q = B->next;
	while (q != B) {
		insert_term(C, q->coff, q->power);
		q = q->next;
	}

	return C;
}

void generate_poly(node* poly, int max_expo, int max_range, int non0_range) {

	set<int> used_expo; 

	while (used_expo.size() < non0_range) {
		int expo = rand() % (max_expo + 1);
		if (used_expo.count(expo)) continue;

		int coeff = (rand() % (2 * max_range + 1)) - max_range;  // [-max_range, +max_range]
		if (coeff == 0) continue; 

		used_expo.insert(expo);
		insert_term(poly, coeff, expo);
	}
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
			srand(time(0));
			polyA = create_poly();
			polyB = create_poly();
			polyC = create_poly();
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
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button5;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1240, 922);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 33);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1232, 885);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Polynomial";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 23;
			this->listBox1->Location = System::Drawing::Point(3, 3);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(1226, 879);
			this->listBox1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->listBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1232, 893);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Addition";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// listBox2
			// 
			this->listBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 23;
			this->listBox2->Location = System::Drawing::Point(3, 3);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(1226, 887);
			this->listBox2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(334, 75);
			this->button1->TabIndex = 1;
			this->button1->Text = L"new term in Poly A";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(33, 184);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(334, 77);
			this->button2->TabIndex = 2;
			this->button2->Text = L"new term in Poly B";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(164, 98);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(157, 35);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(164, 143);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(157, 35);
			this->textBox2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(89, 110);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 23);
			this->label1->TabIndex = 5;
			this->label1->Text = L"coff.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(89, 146);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 23);
			this->label2->TabIndex = 6;
			this->label2->Text = L"exp.";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 278);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 23);
			this->label3->TabIndex = 7;
			this->label3->Text = L"max exp.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(29, 324);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 23);
			this->label4->TabIndex = 8;
			this->label4->Text = L"max range";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(33, 364);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(116, 23);
			this->label5->TabIndex = 9;
			this->label5->Text = L"non-0 range";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(164, 275);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(157, 35);
			this->textBox3->TabIndex = 10;
			this->textBox3->Text = L"4";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(164, 318);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(157, 35);
			this->textBox4->TabIndex = 11;
			this->textBox4->Text = L"5";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(164, 358);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(157, 35);
			this->textBox5->TabIndex = 12;
			this->textBox5->Text = L"2";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(33, 399);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(334, 66);
			this->button3->TabIndex = 13;
			this->button3->Text = L"random Polys A & B";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::Info;
			this->button4->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->button4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button4->Location = System::Drawing::Point(33, 481);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(334, 62);
			this->button4->TabIndex = 14;
			this->button4->Text = L"C=A+B";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->button5);
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			this->splitContainer1->Panel1->Controls->Add(this->button4);
			this->splitContainer1->Panel1->Controls->Add(this->button2);
			this->splitContainer1->Panel1->Controls->Add(this->button3);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->textBox5);
			this->splitContainer1->Panel1->Controls->Add(this->textBox2);
			this->splitContainer1->Panel1->Controls->Add(this->textBox4);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1->Controls->Add(this->textBox3);
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			this->splitContainer1->Panel1->Controls->Add(this->label5);
			this->splitContainer1->Panel1->Controls->Add(this->label3);
			this->splitContainer1->Panel1->Controls->Add(this->label4);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer1->Size = System::Drawing::Size(1648, 922);
			this->splitContainer1->SplitterDistance = 402;
			this->splitContainer1->SplitterWidth = 6;
			this->splitContainer1->TabIndex = 15;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Red;
			this->button5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button5->Location = System::Drawing::Point(33, 558);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(334, 62);
			this->button5->TabIndex = 15;
			this->button5->Text = L"Clear the poly";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1648, 922);
			this->Controls->Add(this->splitContainer1);
			this->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Name = L"Form1";
			this->Text = L"bonus4_111701026";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int coeff = int::Parse(textBox1->Text);
	int exp = int::Parse(textBox2->Text);
	insert_term(polyA, coeff, exp);
	node* q = polyA->next;
	String^ poly_str_A = "";
	while (q!= polyA) {
		String^ term = "";

		if (q->coff == 1 && q->power != 0)
			term += "x^" + q->power;
		else if (q->coff == -1 && q->power != 0)
			term += "-x^" + q->power;
		else
			term += q->coff + ((q->power != 0) ? "x^" + q->power : "");

		if (poly_str_A != "" && q->coff > 0)
			poly_str_A += "+";

		poly_str_A += term;
		q = q->next;
	}

	listBox1->Items->Add(poly_str_A == "" ? "0" : "A: "+ poly_str_A);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int coeff = int::Parse(textBox1->Text);
	int exp = int::Parse(textBox2->Text);
	insert_term(polyB, coeff, exp);
	node* q = polyB->next;
	String^ poly_str_B = "";
	while (q != polyB) {
		String^ term = "";

		if (q->coff == 1 && q->power != 0)
			term += "x^" + q->power;
		else if (q->coff == -1 && q->power != 0)
			term += "-x^" + q->power;
		else
			term += q->coff + ((q->power != 0) ? "x^" + q->power : "");

		if (poly_str_B != "" && q->coff > 0)
			poly_str_B += "+";

		poly_str_B += term;
		q = q->next;
	}

	listBox1->Items->Add(poly_str_B == "" ? "0" : "B: " + poly_str_B);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	listBox1->Items->Add("================= Random Poly-A and Poly-B =================");

	int max_expo = int::Parse(textBox3->Text);
	int max_range = int::Parse(textBox4->Text);
	int non0_range = int::Parse(textBox5->Text);

	generate_poly(polyA, max_expo, max_range, non0_range);
	generate_poly(polyB, max_expo, max_range, non0_range);

	listBox1->Items->Add("Poly A:");
	node* q = polyA->next;
	String^ poly_str_A = "";
	while (q != polyA) {
		String^ term = "";

		if (q->coff == 1 && q->power != 0)
			term += "x^" + q->power;
		else if (q->coff == -1 && q->power != 0)
			term += "-x^" + q->power;
		else
			term += q->coff + ((q->power != 0) ? "x^" + q->power : "");

		if (poly_str_A != "" && q->coff > 0)
			poly_str_A += "+";

		poly_str_A += term;
		q = q->next;
	}

	listBox1->Items->Add(poly_str_A == "" ? "0" : "A: " + poly_str_A);


	listBox1->Items->Add("Poly B:");
	q = polyB->next;
	String^ poly_str_B = "";
	while (q != polyB) {
		String^ term = "";

		if (q->coff == 1 && q->power != 0)
			term += "x^" + q->power;
		else if (q->coff == -1 && q->power != 0)
			term += "-x^" + q->power;
		else
			term += q->coff + ((q->power != 0) ? "x^" + q->power : "");

		if (poly_str_B != "" && q->coff > 0)
			poly_str_B += "+";

		poly_str_B += term;
		q = q->next;
	}

	listBox1->Items->Add(poly_str_B == "" ? "0" : "B: " + poly_str_B);

	listBox1->Items->Add("======================================================");
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	delete polyC; 
	polyC = add_poly(polyA, polyB); 

	String^ result = "";
	node* q = polyC->next;

	while (q != polyC) {
		String^ term = "";

		if (q->coff == 1 && q->power != 0)
			term += "x^" + q->power;
		else if (q->coff == -1 && q->power != 0)
			term += "-x^" + q->power;
		else
			term += q->coff + ((q->power != 0) ? "x^" + q->power : "");

		if (result != "" && q->coff > 0)
			result += "+";

		result += term;
		q = q->next;
	}

	listBox2->Items->Add(result == "" ? "0" : "C = "+result);
	listBox2->Items->Add("======================================================");
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	delete_poly(polyA);
	delete_poly(polyB);

	polyA = create_poly();
	polyB = create_poly();

	//listBox1->Items->Clear();
	//listBox2->Items->Clear();

	MessageBox::Show("Poly A 與 Poly B 清除");
}

};
}
