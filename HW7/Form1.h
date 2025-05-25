#pragma once
# include <stdio.h>
# include <vector>
# include <ctime>
# include <iostream>
# include <time.h>
#include <queue>
#include <climits>
#include <stack>
using namespace std;

vector<vector<int>> table;
int** g;
int* dist;
int* parent;

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Runtime::InteropServices;
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
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	protected:
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage6;
	private: System::Windows::Forms::TabPage^ tabPage7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::ListBox^ listBox1;

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::DataGridView^ dataGridView5;
	private: System::Windows::Forms::DataGridView^ dataGridView6;
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
	this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
	this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
	this->button5 = (gcnew System::Windows::Forms::Button());
	this->button4 = (gcnew System::Windows::Forms::Button());
	this->button3 = (gcnew System::Windows::Forms::Button());
	this->label7 = (gcnew System::Windows::Forms::Label());
	this->button2 = (gcnew System::Windows::Forms::Button());
	this->textBox5 = (gcnew System::Windows::Forms::TextBox());
	this->textBox4 = (gcnew System::Windows::Forms::TextBox());
	this->textBox3 = (gcnew System::Windows::Forms::TextBox());
	this->textBox2 = (gcnew System::Windows::Forms::TextBox());
	this->textBox1 = (gcnew System::Windows::Forms::TextBox());
	this->label6 = (gcnew System::Windows::Forms::Label());
	this->label5 = (gcnew System::Windows::Forms::Label());
	this->label4 = (gcnew System::Windows::Forms::Label());
	this->label3 = (gcnew System::Windows::Forms::Label());
	this->label2 = (gcnew System::Windows::Forms::Label());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
	this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
	this->listBox1 = (gcnew System::Windows::Forms::ListBox());
	this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
	this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
	this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
	this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
	this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
	this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
	this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
	this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
	this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
	this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
	this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
	this->splitContainer1->Panel1->SuspendLayout();
	this->splitContainer1->Panel2->SuspendLayout();
	this->splitContainer1->SuspendLayout();
	this->tabControl1->SuspendLayout();
	this->tabPage1->SuspendLayout();
	this->tabPage2->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
	this->tabPage3->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
	this->tabPage4->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
	this->tabPage6->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
	this->tabPage7->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->BeginInit();
	this->SuspendLayout();
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
	this->splitContainer1->Panel1->AllowDrop = true;
	this->splitContainer1->Panel1->AutoScroll = true;
	this->splitContainer1->Panel1->Controls->Add(this->checkBox1);
	this->splitContainer1->Panel1->Controls->Add(this->button5);
	this->splitContainer1->Panel1->Controls->Add(this->button4);
	this->splitContainer1->Panel1->Controls->Add(this->button3);
	this->splitContainer1->Panel1->Controls->Add(this->label7);
	this->splitContainer1->Panel1->Controls->Add(this->button2);
	this->splitContainer1->Panel1->Controls->Add(this->textBox5);
	this->splitContainer1->Panel1->Controls->Add(this->textBox4);
	this->splitContainer1->Panel1->Controls->Add(this->textBox3);
	this->splitContainer1->Panel1->Controls->Add(this->textBox2);
	this->splitContainer1->Panel1->Controls->Add(this->textBox1);
	this->splitContainer1->Panel1->Controls->Add(this->label6);
	this->splitContainer1->Panel1->Controls->Add(this->label5);
	this->splitContainer1->Panel1->Controls->Add(this->label4);
	this->splitContainer1->Panel1->Controls->Add(this->label3);
	this->splitContainer1->Panel1->Controls->Add(this->label2);
	this->splitContainer1->Panel1->Controls->Add(this->label1);
	this->splitContainer1->Panel1->Controls->Add(this->button1);
	// 
	// splitContainer1.Panel2
	// 
	this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
	this->splitContainer1->Size = System::Drawing::Size(1686, 820);
	this->splitContainer1->SplitterDistance = 456;
	this->splitContainer1->SplitterWidth = 5;
	this->splitContainer1->TabIndex = 0;
	// 
	// checkBox1
	// 
	this->checkBox1->AutoSize = true;
	this->checkBox1->Location = System::Drawing::Point(36, 419);
	this->checkBox1->Name = L"checkBox1";
	this->checkBox1->Size = System::Drawing::Size(290, 43);
	this->checkBox1->TabIndex = 17;
	this->checkBox1->Text = L"Undirected Graph";
	this->checkBox1->UseVisualStyleBackColor = true;
	// 
	// button5
	// 
	this->button5->Location = System::Drawing::Point(31, 648);
	this->button5->Name = L"button5";
	this->button5->Size = System::Drawing::Size(312, 63);
	this->button5->TabIndex = 16;
	this->button5->Text = L"Transitive Closure";
	this->button5->UseVisualStyleBackColor = true;
	this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
	// 
	// button4
	// 
	this->button4->Location = System::Drawing::Point(31, 580);
	this->button4->Name = L"button4";
	this->button4->Size = System::Drawing::Size(312, 63);
	this->button4->TabIndex = 15;
	this->button4->Text = L"All Pairs";
	this->button4->UseVisualStyleBackColor = true;
	this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
	// 
	// button3
	// 
	this->button3->Location = System::Drawing::Point(31, 512);
	this->button3->Name = L"button3";
	this->button3->Size = System::Drawing::Size(312, 63);
	this->button3->TabIndex = 14;
	this->button3->Text = L"Single Source All Desinations";
	this->button3->UseVisualStyleBackColor = true;
	this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
	// 
	// label7
	// 
	this->label7->AutoSize = true;
	this->label7->BackColor = System::Drawing::SystemColors::ButtonShadow;
	this->label7->ForeColor = System::Drawing::SystemColors::ControlText;
	this->label7->Location = System::Drawing::Point(31, 468);
	this->label7->Name = L"label7";
	this->label7->Size = System::Drawing::Size(311, 39);
	this->label7->TabIndex = 13;
	this->label7->Text = L"Shortest Path Solver";
	// 
	// button2
	// 
	this->button2->Location = System::Drawing::Point(31, 355);
	this->button2->Name = L"button2";
	this->button2->Size = System::Drawing::Size(292, 50);
	this->button2->TabIndex = 12;
	this->button2->Text = L"Generate Graph";
	this->button2->UseVisualStyleBackColor = true;
	this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
	// 
	// textBox5
	// 
	this->textBox5->Location = System::Drawing::Point(263, 303);
	this->textBox5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->textBox5->Name = L"textBox5";
	this->textBox5->Size = System::Drawing::Size(64, 47);
	this->textBox5->TabIndex = 11;
	this->textBox5->Text = L"0";
	// 
	// textBox4
	// 
	this->textBox4->Location = System::Drawing::Point(263, 260);
	this->textBox4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->textBox4->Name = L"textBox4";
	this->textBox4->Size = System::Drawing::Size(64, 47);
	this->textBox4->TabIndex = 10;
	this->textBox4->Text = L"9999";
	// 
	// textBox3
	// 
	this->textBox3->Location = System::Drawing::Point(263, 217);
	this->textBox3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->textBox3->Name = L"textBox3";
	this->textBox3->Size = System::Drawing::Size(64, 47);
	this->textBox3->TabIndex = 9;
	this->textBox3->Text = L"80";
	// 
	// textBox2
	// 
	this->textBox2->Location = System::Drawing::Point(263, 174);
	this->textBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->textBox2->Name = L"textBox2";
	this->textBox2->Size = System::Drawing::Size(64, 47);
	this->textBox2->TabIndex = 8;
	this->textBox2->Text = L"100";
	// 
	// textBox1
	// 
	this->textBox1->Location = System::Drawing::Point(263, 131);
	this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->textBox1->Name = L"textBox1";
	this->textBox1->Size = System::Drawing::Size(64, 47);
	this->textBox1->TabIndex = 7;
	this->textBox1->Text = L"12";
	// 
	// label6
	// 
	this->label6->AutoSize = true;
	this->label6->Location = System::Drawing::Point(54, 303);
	this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label6->Name = L"label6";
	this->label6->Size = System::Drawing::Size(162, 39);
	this->label6->TabIndex = 6;
	this->label6->Text = L"Souce no. =";
	// 
	// label5
	// 
	this->label5->AutoSize = true;
	this->label5->Location = System::Drawing::Point(54, 265);
	this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label5->Name = L"label5";
	this->label5->Size = System::Drawing::Size(106, 39);
	this->label5->TabIndex = 5;
	this->label5->Text = L"w(e) =";
	// 
	// label4
	// 
	this->label4->AutoSize = true;
	this->label4->Location = System::Drawing::Point(54, 222);
	this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label4->Name = L"label4";
	this->label4->Size = System::Drawing::Size(134, 39);
	this->label4->TabIndex = 4;
	this->label4->Text = L"if w(e) >";
	// 
	// label3
	// 
	this->label3->AutoSize = true;
	this->label3->Location = System::Drawing::Point(54, 174);
	this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label3->Name = L"label3";
	this->label3->Size = System::Drawing::Size(193, 39);
	this->label3->TabIndex = 3;
	this->label3->Text = L"range (w(e))";
	// 
	// label2
	// 
	this->label2->AutoSize = true;
	this->label2->Location = System::Drawing::Point(54, 131);
	this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label2->Name = L"label2";
	this->label2->Size = System::Drawing::Size(48, 39);
	this->label2->TabIndex = 2;
	this->label2->Text = L"n=";
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->BackColor = System::Drawing::SystemColors::AppWorkspace;
	this->label1->Location = System::Drawing::Point(28, 79);
	this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(274, 39);
	this->label1->TabIndex = 1;
	this->label1->Text = L"Randomly generate";
	// 
	// button1
	// 
	this->button1->Location = System::Drawing::Point(25, 21);
	this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(300, 53);
	this->button1->TabIndex = 0;
	this->button1->Text = L"Read Graph";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
	// 
	// tabControl1
	// 
	this->tabControl1->Controls->Add(this->tabPage1);
	this->tabControl1->Controls->Add(this->tabPage2);
	this->tabControl1->Controls->Add(this->tabPage3);
	this->tabControl1->Controls->Add(this->tabPage4);
	this->tabControl1->Controls->Add(this->tabPage6);
	this->tabControl1->Controls->Add(this->tabPage7);
	this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->tabControl1->Font = (gcnew System::Drawing::Font(L"Ink Free", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->tabControl1->Location = System::Drawing::Point(0, 0);
	this->tabControl1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->tabControl1->Name = L"tabControl1";
	this->tabControl1->SelectedIndex = 0;
	this->tabControl1->Size = System::Drawing::Size(1225, 820);
	this->tabControl1->TabIndex = 0;
	// 
	// tabPage1
	// 
	this->tabPage1->Controls->Add(this->listBox1);
	this->tabPage1->Location = System::Drawing::Point(8, 53);
	this->tabPage1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->tabPage1->Name = L"tabPage1";
	this->tabPage1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->tabPage1->Size = System::Drawing::Size(1152, 759);
	this->tabPage1->TabIndex = 0;
	this->tabPage1->Text = L"G\'s adjacent matrix";
	this->tabPage1->UseVisualStyleBackColor = true;
	// 
	// listBox1
	// 
	this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->listBox1->FormattingEnabled = true;
	this->listBox1->ItemHeight = 39;
	this->listBox1->Location = System::Drawing::Point(4, 5);
	this->listBox1->Name = L"listBox1";
	this->listBox1->Size = System::Drawing::Size(1144, 749);
	this->listBox1->TabIndex = 0;
	// 
	// tabPage2
	// 
	this->tabPage2->Controls->Add(this->dataGridView2);
	this->tabPage2->Location = System::Drawing::Point(8, 53);
	this->tabPage2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->tabPage2->Name = L"tabPage2";
	this->tabPage2->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->tabPage2->Size = System::Drawing::Size(1209, 759);
	this->tabPage2->TabIndex = 1;
	this->tabPage2->Text = L"Graph in adjacent matrix";
	this->tabPage2->UseVisualStyleBackColor = true;
	// 
	// dataGridView2
	// 
	this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
	this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
	this->dataGridView2->Location = System::Drawing::Point(4, 5);
	this->dataGridView2->Name = L"dataGridView2";
	this->dataGridView2->RowHeadersWidth = 82;
	this->dataGridView2->RowTemplate->Height = 38;
	this->dataGridView2->Size = System::Drawing::Size(1201, 749);
	this->dataGridView2->TabIndex = 0;
	// 
	// tabPage3
	// 
	this->tabPage3->Controls->Add(this->dataGridView1);
	this->tabPage3->Location = System::Drawing::Point(8, 60);
	this->tabPage3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->tabPage3->Name = L"tabPage3";
	this->tabPage3->Size = System::Drawing::Size(1151, 752);
	this->tabPage3->TabIndex = 2;
	this->tabPage3->Text = L"SSAD tables";
	this->tabPage3->UseVisualStyleBackColor = true;
	// 
	// dataGridView1
	// 
	this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
	this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->dataGridView1->Location = System::Drawing::Point(0, 0);
	this->dataGridView1->Name = L"dataGridView1";
	this->dataGridView1->RowHeadersWidth = 82;
	this->dataGridView1->RowTemplate->Height = 38;
	this->dataGridView1->Size = System::Drawing::Size(1151, 752);
	this->dataGridView1->TabIndex = 0;
	// 
	// tabPage4
	// 
	this->tabPage4->Controls->Add(this->dataGridView4);
	this->tabPage4->Location = System::Drawing::Point(8, 60);
	this->tabPage4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->tabPage4->Name = L"tabPage4";
	this->tabPage4->Size = System::Drawing::Size(1151, 752);
	this->tabPage4->TabIndex = 3;
	this->tabPage4->Text = L"All Pairs";
	this->tabPage4->UseVisualStyleBackColor = true;
	// 
	// dataGridView4
	// 
	this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
	this->dataGridView4->Dock = System::Windows::Forms::DockStyle::Fill;
	this->dataGridView4->Location = System::Drawing::Point(0, 0);
	this->dataGridView4->Name = L"dataGridView4";
	this->dataGridView4->RowHeadersWidth = 82;
	this->dataGridView4->RowTemplate->Height = 38;
	this->dataGridView4->Size = System::Drawing::Size(1151, 752);
	this->dataGridView4->TabIndex = 0;
	// 
	// tabPage6
	// 
	this->tabPage6->Controls->Add(this->dataGridView5);
	this->tabPage6->Location = System::Drawing::Point(8, 60);
	this->tabPage6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->tabPage6->Name = L"tabPage6";
	this->tabPage6->Size = System::Drawing::Size(1151, 752);
	this->tabPage6->TabIndex = 5;
	this->tabPage6->Text = L"All pairs table";
	this->tabPage6->UseVisualStyleBackColor = true;
	// 
	// dataGridView5
	// 
	this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
	this->dataGridView5->Dock = System::Windows::Forms::DockStyle::Fill;
	this->dataGridView5->Location = System::Drawing::Point(0, 0);
	this->dataGridView5->Name = L"dataGridView5";
	this->dataGridView5->RowHeadersWidth = 82;
	this->dataGridView5->RowTemplate->Height = 38;
	this->dataGridView5->Size = System::Drawing::Size(1151, 752);
	this->dataGridView5->TabIndex = 0;
	// 
	// tabPage7
	// 
	this->tabPage7->Controls->Add(this->dataGridView6);
	this->tabPage7->Location = System::Drawing::Point(8, 60);
	this->tabPage7->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->tabPage7->Name = L"tabPage7";
	this->tabPage7->Size = System::Drawing::Size(1151, 752);
	this->tabPage7->TabIndex = 6;
	this->tabPage7->Text = L"Transitive closure";
	this->tabPage7->UseVisualStyleBackColor = true;
	// 
	// dataGridView6
	// 
	this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
	this->dataGridView6->Dock = System::Windows::Forms::DockStyle::Fill;
	this->dataGridView6->Location = System::Drawing::Point(0, 0);
	this->dataGridView6->Name = L"dataGridView6";
	this->dataGridView6->RowHeadersWidth = 82;
	this->dataGridView6->RowTemplate->Height = 38;
	this->dataGridView6->Size = System::Drawing::Size(1151, 752);
	this->dataGridView6->TabIndex = 1;
	// 
	// openFileDialog1
	// 
	this->openFileDialog1->FileName = L"openFileDialog1";
	// 
	// Form1
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(17, 39);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(1686, 820);
	this->Controls->Add(this->splitContainer1);
	this->Font = (gcnew System::Drawing::Font(L"Ink Free", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
	this->Name = L"Form1";
	this->Text = L"Shortest Path_111701026_張肇政";
	this->splitContainer1->Panel1->ResumeLayout(false);
	this->splitContainer1->Panel1->PerformLayout();
	this->splitContainer1->Panel2->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
	this->splitContainer1->ResumeLayout(false);
	this->tabControl1->ResumeLayout(false);
	this->tabPage1->ResumeLayout(false);
	this->tabPage2->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
	this->tabPage3->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
	this->tabPage4->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
	this->tabPage6->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
	this->tabPage7->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->EndInit();
	this->ResumeLayout(false);

}
#pragma endregion

void dijkstra(int n, int source, int* dist, int* parent, int limit, int& colCount) {
	vector<bool> visited(n, false);
	vector<bool> everUpdated(n, false);

	for (int i = 0; i < n; i++) {
		dist[i] = limit;
		parent[i] = -1;
	}
	dist[source] = 0;

	dataGridView1->Columns->Clear();
	dataGridView1->Rows->Clear();

	dataGridView1->RowCount = n;
	for (int i = 0; i < n; i++) {
		dataGridView1->Rows[i]->HeaderCell->Value = i.ToString();
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, source });

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = true;

		listBox1->Items->Add("min = " + u);

		vector<bool> justUpdated(n, false);
		bool updated = false;

		for (int v = 0; v < n; v++) {
			if (g[u][v] != limit && g[u][v] > 0) {
				int newDist = dist[u] + g[u][v];
				if (newDist < dist[v]) {
					dist[v] = newDist;
					parent[v] = u;
					pq.push({ newDist, v });
					justUpdated[v] = true;
					everUpdated[v] = true;
					updated = true;
				}
			}
		}

		int col = dataGridView1->Columns->Add(colCount.ToString(), colCount.ToString());
		colCount++;
		for (int j = 0; j < n; j++) {
			DataGridViewCell^ cell = dataGridView1->Rows[j]->Cells[col];

			if (dist[j] >= limit) {
				cell->Value = "∞";
				cell->Style->BackColor = Color::White;
			}
			else {
				cell->Value = dist[j].ToString();

				if (justUpdated[j])
					cell->Style->BackColor = Color::LightYellow;
				else if (everUpdated[j])
					cell->Style->BackColor = Color::LightBlue;
				else
					cell->Style->BackColor = Color::White;
			}
		}
	}
	int fromCol = dataGridView1->Columns->Add("from", "from");

	for (int i = 0; i < n; i++) {
		if (parent[i] != -1) {
			dataGridView1->Rows[i]->Cells[fromCol]->Value = parent[i].ToString();
			dataGridView1->Rows[i]->Cells[fromCol]->Style->BackColor = Color::LightGreen;
		}
		else {
			dataGridView1->Rows[i]->Cells[fromCol]->Value = "-";
			dataGridView1->Rows[i]->Cells[fromCol]->Style->BackColor = Color::White;
		}
	}
}

void ssad(int size, int source, int limit) {
	int n = size;
	int* dist = new int[n];
	int* parent = new int[n];
	int rowCount = 0;

	listBox1->Items->Clear();
	dataGridView1->Columns->Clear();

	int colCount = 0;
	dijkstra(n, source, dist, parent, limit, colCount);

	// 顯示最短路徑
	for (int i = 0; i < n; i++) {
		if (i == source || dist[i] >= limit) continue;

		stack<int> pathStack;
		int current = i;
		while (current != -1) {
			pathStack.push(current);
			current = parent[current];
		}

		String^ pathStr = source.ToString();
		int last = source;
		while (!pathStack.empty()) {
			int next = pathStack.top();
			pathStack.pop();
			pathStr += "--[" + g[last][next] + "]-->" + next;
			last = next;
		}

		String^ msg = "The shortest distance from " + source + " to " + i +
			" is " + dist[i] + " with path " + pathStr;
		listBox1->Items->Add(msg);
	}

	delete[] dist;
	delete[] parent;
}

/*Read Graph*/
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName);
			String^ firstLine = reader->ReadLine(); 
			cli::array<String^>^ width_and_height = firstLine->Split(' ');

			int n = int::Parse(width_and_height[0]);
			int m = int::Parse(width_and_height[1]);

			textBox1->Text = width_and_height[0];
			textBox2->Text = width_and_height[1];

			g = new int* [n];
			for (int i = 0; i < n; i++) {
				g[i] = new int[m];
			}

			for (int i = 0; i < n; i++) {
				cli::array<String^>^ g_content = reader->ReadLine()->Split(
					gcnew cli::array<wchar_t>{' ', '\t'}, // 處理空格與Tab
					StringSplitOptions::RemoveEmptyEntries // 移除多餘的空字串
				);

				for (int j = 0; j < m; j++) {
					g[i][j] = int::Parse(g_content[j]); 
				}
			}
			reader->Close();

			dataGridView2->RowCount = n+1;  /*這個要+1*/
			dataGridView2->ColumnCount = m; 
			dataGridView2->ColumnHeadersVisible = false;
			dataGridView2->RowHeadersVisible = false;
			dataGridView2->AllowUserToAddRows = false;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					dataGridView2->Rows[i]->Cells[j]->Value = g[i][j].ToString();
				}
			}
		}
	}

/*Generate Graph*/
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = int::Parse(textBox1->Text);
		int r = int::Parse(textBox2->Text);
		int limit = int::Parse(textBox3->Text);
		int value = int::Parse(textBox4->Text);
		int source = int::Parse(textBox5->Text);
		g = new int* [n];
		for (int i = 0; i < n; i++) {
			g[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = 0;
			}
		}
		srand(time(0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = rand()%r+1;
				if (g[i][j] > limit) g[i][j] = value;
				if (i == j) g[i][j] = value;
				if(!checkBox1->Checked) g[j][i] = g[i][j];
			}
		}
		dataGridView2->RowCount = n;
		dataGridView2->ColumnCount = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dataGridView2->Rows[i]->Cells[j]->Value = g[i][j];
			}
		}
	}

/*Single Source All Desinations (SSAD)*/
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int n = int::Parse(textBox1->Text);
	int limit = int::Parse(textBox3->Text);
	int source = int::Parse(textBox5->Text);
	ssad(n, source, limit);
}

/*all pairs*/
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	int n = int::Parse(textBox1->Text);
	int limit = int::Parse(textBox3->Text);

	// Floyd-Warshall 
	vector<vector<int>> dist(n, vector<int>(n, limit));
	vector<vector<int>> pred(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) dist[i][j] = 0;
			else if (g[i][j] != limit && g[i][j] > 0) {
				dist[i][j] = g[i][j];
				pred[i][j] = i;
			}
		}
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist[i][k] < limit && dist[k][j] < limit &&
					dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					pred[i][j] = pred[k][j];
				}

	// 顯示 All pairs 最短距離（dataGridView4）
	dataGridView4->RowCount = n;
	dataGridView4->ColumnCount = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dataGridView4->Rows[i]->Cells[j]->Value =
			(dist[i][j] >= limit ? "∞" : dist[i][j].ToString());

	// 顯示 Predecessor（dataGridView5）
	dataGridView5->RowCount = n;
	dataGridView5->ColumnCount = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dataGridView5->Rows[i]->Cells[j]->Value =
			(dist[i][j] >= limit || i == j ? i.ToString() : pred[i][j].ToString());

	// 顯示最短路徑文字敘述（listBox1）
	listBox1->Items->Add("==========ALL PAIRS==========");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || dist[i][j] >= limit) continue;

			stack<int> path;
			int current = j;
			while (current != i) {
				path.push(current);
				current = pred[i][current];
			}
			path.push(i);

			String^ msg = "The shortest distance from " + i + " to " + j +
				" is " + dist[i][j] + " with path ";
			int last = path.top(); path.pop();
			msg += last;
			while (!path.empty()) {
				int next = path.top(); path.pop();
				msg += "--[" + g[last][next] + "]-->" + next;
				last = next;
			}
			listBox1->Items->Add(msg);
		}
		listBox1->Items->Add("==============================");
	}
}

/*transitive closure*/
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	int n = int::Parse(textBox1->Text);
	int limit = int::Parse(textBox3->Text);

	// 用 Floyd 做傳遞
	vector<vector<bool>> reach(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j || g[i][j] != limit && g[i][j] > 0)
				reach[i][j] = true;

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

	// 顯示傳遞（dataGridView6）
	dataGridView6->RowCount = n;
	dataGridView6->ColumnCount = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dataGridView6->Rows[i]->Cells[j]->Value = reach[i][j] ? "1" : "0";
}
};
}
