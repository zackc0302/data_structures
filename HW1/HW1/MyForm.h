#pragma once
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
int list[100000];
int sorted[100000];
using namespace std;

namespace HW1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ListBox^ listBox5;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart4;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::ListBox^ listBox6;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::ListBox^ listBox7;
	private: System::Windows::Forms::Label^ label7;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea13 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend13 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series37 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series38 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series39 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea14 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend14 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series40 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series41 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series42 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea15 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend15 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series43 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series44 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series45 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea16 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend16 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series46 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series47 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series48 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->listBox7 = (gcnew System::Windows::Forms::ListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->chart4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(52, 201);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(209, 55);
			this->button1->TabIndex = 0;
			this->button1->Text = L"DATA GENERATION";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(119, 131);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(154, 27);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"100";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Location = System::Drawing::Point(308, 72);
			this->listBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(224, 244);
			this->listBox1->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(50, 264);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(211, 53);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Selection Sort";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 20;
			this->listBox2->Location = System::Drawing::Point(557, 72);
			this->listBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(221, 244);
			this->listBox2->TabIndex = 4;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(50, 325);
			this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(211, 51);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Bubble Sort";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 20;
			this->listBox3->Location = System::Drawing::Point(804, 72);
			this->listBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(214, 244);
			this->listBox3->TabIndex = 6;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(51, 99);
			this->checkBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(102, 24);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Echo Print";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(76, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"n =";
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Location = System::Drawing::Point(159, 64);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(114, 27);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"9999";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(46, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 20);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Range from 0 to";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(700, 402);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(211, 50);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Binary Search";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(791, 458);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(120, 27);
			this->textBox3->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(698, 461);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Target Value";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 20;
			this->listBox4->Location = System::Drawing::Point(940, 402);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(448, 84);
			this->listBox4->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(612, 52);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 20);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Selection Sort";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(863, 52);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 20);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Bubble Sort";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1114, 52);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(81, 20);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Quick Sort";
			// 
			// listBox5
			// 
			this->listBox5->FormattingEnabled = true;
			this->listBox5->ItemHeight = 20;
			this->listBox5->Location = System::Drawing::Point(1041, 72);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(213, 244);
			this->listBox5->TabIndex = 18;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->button5->Location = System::Drawing::Point(50, 383);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(211, 45);
			this->button5->TabIndex = 19;
			this->button5->Text = L"Quick Sort";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(50, 29);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(82, 24);
			this->checkBox2->TabIndex = 20;
			this->checkBox2->Text = L"Choose";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(0, 0);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(200, 100);
			this->tabPage2->TabIndex = 0;
			this->tabPage2->Text = L"tabPage2";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1566, 799);
			this->tabControl1->TabIndex = 23;
			// 
			// tabPage1
			// 
			this->tabPage1->AutoScroll = true;
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->listBox7);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->listBox6);
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->checkBox1);
			this->tabPage1->Controls->Add(this->listBox4);
			this->tabPage1->Controls->Add(this->listBox5);
			this->tabPage1->Controls->Add(this->button5);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->listBox3);
			this->tabPage1->Controls->Add(this->checkBox2);
			this->tabPage1->Controls->Add(this->listBox2);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Location = System::Drawing::Point(4, 29);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1558, 766);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"主頁";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->button7->Location = System::Drawing::Point(50, 440);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(211, 45);
			this->button7->TabIndex = 25;
			this->button7->Text = L"Merge Sort";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// listBox7
			// 
			this->listBox7->FormattingEnabled = true;
			this->listBox7->ItemHeight = 20;
			this->listBox7->Location = System::Drawing::Point(1274, 72);
			this->listBox7->Name = L"listBox7";
			this->listBox7->Size = System::Drawing::Size(213, 244);
			this->listBox7->TabIndex = 24;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1347, 52);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(87, 20);
			this->label7->TabIndex = 23;
			this->label7->Text = L"Merge Sort";
			// 
			// listBox6
			// 
			this->listBox6->FormattingEnabled = true;
			this->listBox6->ItemHeight = 20;
			this->listBox6->Location = System::Drawing::Point(61, 595);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(448, 84);
			this->listBox6->TabIndex = 22;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(61, 522);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(211, 50);
			this->button6->TabIndex = 21;
			this->button6->Text = L"Correct\?";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->chart4);
			this->tabPage3->Controls->Add(this->chart3);
			this->tabPage3->Controls->Add(this->chart2);
			this->tabPage3->Controls->Add(this->chart1);
			this->tabPage3->Location = System::Drawing::Point(4, 29);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1558, 766);
			this->tabPage3->TabIndex = 1;
			this->tabPage3->Text = L"圖表";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// chart4
			// 
			chartArea13->Name = L"ChartArea1";
			this->chart4->ChartAreas->Add(chartArea13);
			legend13->Name = L"Legend1";
			this->chart4->Legends->Add(legend13);
			this->chart4->Location = System::Drawing::Point(40, 253);
			this->chart4->Name = L"chart4";
			series37->ChartArea = L"ChartArea1";
			series37->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series37->Legend = L"Legend1";
			series37->Name = L"Series1";
			series38->ChartArea = L"ChartArea1";
			series38->Legend = L"Legend1";
			series38->Name = L"Series2";
			series39->ChartArea = L"ChartArea1";
			series39->Legend = L"Legend1";
			series39->Name = L"Series3";
			this->chart4->Series->Add(series37);
			this->chart4->Series->Add(series38);
			this->chart4->Series->Add(series39);
			this->chart4->Size = System::Drawing::Size(370, 241);
			this->chart4->TabIndex = 3;
			this->chart4->Text = L"chart4";
			// 
			// chart3
			// 
			chartArea14->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea14);
			legend14->Name = L"Legend1";
			this->chart3->Legends->Add(legend14);
			this->chart3->Location = System::Drawing::Point(398, 6);
			this->chart3->Name = L"chart3";
			series40->ChartArea = L"ChartArea1";
			series40->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series40->Legend = L"Legend1";
			series40->Name = L"Series1";
			series41->ChartArea = L"ChartArea1";
			series41->Legend = L"Legend1";
			series41->Name = L"Series2";
			series42->ChartArea = L"ChartArea1";
			series42->Legend = L"Legend1";
			series42->Name = L"Series3";
			this->chart3->Series->Add(series40);
			this->chart3->Series->Add(series41);
			this->chart3->Series->Add(series42);
			this->chart3->Size = System::Drawing::Size(370, 241);
			this->chart3->TabIndex = 2;
			this->chart3->Text = L"chart3";
			// 
			// chart2
			// 
			chartArea15->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea15);
			legend15->Name = L"Legend1";
			this->chart2->Legends->Add(legend15);
			this->chart2->Location = System::Drawing::Point(398, 253);
			this->chart2->Name = L"chart2";
			series43->ChartArea = L"ChartArea1";
			series43->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series43->Legend = L"Legend1";
			series43->Name = L"Series1";
			series44->ChartArea = L"ChartArea1";
			series44->Legend = L"Legend1";
			series44->Name = L"Series2";
			series45->ChartArea = L"ChartArea1";
			series45->Legend = L"Legend1";
			series45->Name = L"Series3";
			this->chart2->Series->Add(series43);
			this->chart2->Series->Add(series44);
			this->chart2->Series->Add(series45);
			this->chart2->Size = System::Drawing::Size(370, 241);
			this->chart2->TabIndex = 1;
			this->chart2->Text = L"chart2";
			// 
			// chart1
			// 
			chartArea16->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea16);
			legend16->Name = L"Legend1";
			this->chart1->Legends->Add(legend16);
			this->chart1->Location = System::Drawing::Point(40, 6);
			this->chart1->Name = L"chart1";
			series46->ChartArea = L"ChartArea1";
			series46->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series46->Legend = L"Legend1";
			series46->Name = L"Series1";
			series47->ChartArea = L"ChartArea1";
			series47->Legend = L"Legend1";
			series47->Name = L"Series2";
			series48->ChartArea = L"ChartArea1";
			series48->Legend = L"Legend1";
			series48->Name = L"Series3";
			this->chart1->Series->Add(series46);
			this->chart1->Series->Add(series47);
			this->chart1->Series->Add(series48);
			this->chart1->Size = System::Drawing::Size(370, 241);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->ClientSize = System::Drawing::Size(1566, 799);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"111701026_張肇政_HW1";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		void SelectionSort(int list[], int n) {
			int i, j, min, temp;
			for (i = 0; i < n; i++) {
				min = i;
				for (j = i + 1; j < n; j++)
					if (list[j] < list[min]) min = j;
				temp = list[i];
				list[i] = list[min];
				list[min] = temp;
			}
		}

		void BubbleSort(int list[], int n) {
			for (int i = 0; i < n -1; i++) {
				for (int j = 0; j < n -1-i; j++) {
					if (list[j] > list[j + 1]) swap(list[j], list[j + 1]);
				}
			}
		}

		int partition(int arr[], int start, int end) {
			int pivot = arr[end]; // 最後一個元素作為基準點
			int i = start - 1; 

			for (int j = start; j < end; j++) {
				if (arr[j] <= pivot) {
					i++;
					swap(arr[i], arr[j]);
				}
			}
			swap(arr[i + 1], arr[end]);
			return i + 1;
		}

		void quickSort(int sorted[], int start, int end)
		{
			if (start < end) {
				int p = partition(sorted, start, end);
				quickSort(sorted, start, p - 1);
				quickSort(sorted, p + 1, end);
			}
		}

		void mergeSort(int list[], int left, int right) {
			if (left < right) {
				int mid = (left + right) / 2;
				mergeSort(list, left, mid);
				mergeSort(list, mid + 1, right);
				merge(list, left, mid, right);
			}
		}

		void merge(int list[], int left, int mid, int right) {
			int i = left;
			int j = mid + 1; 
			int k = 0;       

			int size = right - left + 1;
			vector<int> temp(size);

			while (i <= mid && j <= right) {
				if (list[i] <= list[j]) {
					temp[k] = list[i];
					i++;
				}
				else {
					temp[k] = list[j];
					j++;
				}
				k++;
			}

			while (i <= mid) {
				temp[k] = list[i];
				i++;
				k++;
			}

			while (j <= right) {
				temp[k] = list[j];
				j++;
				k++;
			}

			for (int s = 0; s < size; s++) list[left + s] = temp[s];
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int i, s;
		double n;
		listBox1->Items->Clear();
		n = double::Parse(textBox1->Text);
		if (n - int(n) == 0) {
			int n = int::Parse(textBox1->Text);
			if (checkBox2->Checked) {
				s = int::Parse(textBox2->Text);
				for (i = 0; i < n; i++) {
					list[i] = rand() % (s + 1);
					listBox1->Items->Add(list[i]);
				}
			}
			else {
				for (i = 0; i < n; i++) {
					list[i] = rand() % (s + 1);
					listBox1->Items->Add(list[i]);
				}
			}
		}
else {
	MessageBox::Show("請再次輸入有效位數!", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//SelectionSort
		int n = int::Parse(textBox1->Text);
		int i,j;
		listBox2->Items->Clear();
		clock_t start, end;
		double duration;
		for (i = 0; i < n; i++) sorted[i] = list[i];
		start = clock();
		SelectionSort(sorted, n);
		end = clock();
		duration = (double) (end - start)/CLOCKS_PER_SEC;
		if (checkBox1->Checked) {
			for (i = 0; i < n; i++) {
				listBox2->Items->Add(sorted[i]);
			}
		}
		listBox2->Items->Add("SelectionSort: " + duration + "(sec.)");
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = int::Parse(textBox1->Text);
		int s = int::Parse(textBox2->Text);
		int i,j;
		listBox3->Items->Clear();
		clock_t start, end;
		double duration2;
		for (i = 0; i < n; i++) sorted[i] = list[i];
		start = clock();
		BubbleSort(sorted, n);
		end = clock();
		duration2 = (double)(end - start) / CLOCKS_PER_SEC;
		if (checkBox1->Checked) {
			for (i = 0; i < n; i++) {
				listBox3->Items->Add(sorted[i]);
			}
		}
		listBox3->Items->Add("BubbleSort: " + duration2 + "(sec.)");
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		//BinarySearch
		int tv, n, mid,s,r;
		tv = int::Parse(textBox3->Text);
		n = int::Parse(textBox1->Text);
		s = int::Parse(textBox2->Text);
		listBox4->Items->Clear();
		int low = 0, high =n - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (sorted[mid] == tv) {
				listBox4->Items->Add(tv + " has been found in list[" + mid + "]");
				break;
			}
			else if (sorted[mid] < tv) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		if (low > high) {
			listBox4->Items->Add(" Can't find the target value");
		}
	}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	//QuickSort
	int n = int::Parse(textBox1->Text);
	int s = int::Parse(textBox2->Text);
	int i, j;
	clock_t start, end;
	double duration;
	listBox5->Items->Clear();
	for (i = 0; i < n; i++) sorted[i] = list[i];
	start = clock();
	quickSort(sorted, 0, n-1);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
		if (checkBox1->Checked) {
			for (i = 0; i < n; i++) {
				listBox5->Items->Add(sorted[i]);
			}
		}
		listBox5->Items->Add("QuickSort: " + duration + "(sec.)");
}
private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	int Y1[10], Y2[10];
	int X[10];
	int i;
	String^ name1 = "Selection"; // String in VSC++
	chart1->Series->Clear();
	chart1->Series->Add(name1);
	// String ^ name2 = "Bubble"; // if another series is required
	// chart1->Series->Add(name2);
	for (i = 0; i < 10; i++)
	{
		Y1[i] = rand() & 1000;
		X[i] = i + 1;
		chart1->Series[name1]->Points->AddXY(X[i], Y1[i]);
		// Y2[i] = rand();
		// chart1->Series[name2]->Points->AddXY(X[i], Y2[i]);
	}
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	int n = int::Parse(textBox1->Text);
	bool flag = is_sorted(sorted, sorted + n);
	listBox6->Items->Clear();
	if (flag) listBox6->Items->Add("Correct");
	else listBox6->Items->Add("Incorrect");
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	//Mergesort
	int n = int::Parse(textBox1->Text);
	int s = int::Parse(textBox2->Text);
	int i, j;
	clock_t start, end;
	double duration;
	listBox7->Items->Clear();
	for (i = 0; i < n; i++) sorted[i] = list[i];
	start = clock();
	mergeSort(sorted, 0, n-1);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	if (checkBox1->Checked) {
		for (i = 0; i < n; i++) {
			listBox7->Items->Add(sorted[i]);
		}
	}
	listBox7->Items->Add("MergeSort: " + duration + "(sec.)");
}
};
}