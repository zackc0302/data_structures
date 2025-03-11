#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace HW2_111701026 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 篕璶
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  篶ㄧΑ祘Α絏
			//
		}

	protected:
		/// <summary>
		/// 睲埃ヴㄏノい戈方
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;


	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;

	public: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::CheckBox^ checkBox8;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::SplitContainer^ splitContainer3;
	public:
	private:
	private:
		/// <summary>
		/// 砞璸ㄣ┮惠跑计
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 砞璸ㄣや穿┮惠よ猭 - 叫づㄏノ祘Α絏絪胯竟э
		/// 硂よ猭ず甧
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(36, 60);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Square Size";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(226, 55);
			this->textBox1->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(153, 38);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::PeachPuff;
			this->button1->Font = (gcnew System::Drawing::Font(L"New Gulim", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(39, 487);
			this->button1->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(485, 196);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Magic Square";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(84, 404);
			this->checkBox2->Margin = System::Windows::Forms::Padding(5);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(92, 36);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(84, 344);
			this->checkBox1->Margin = System::Windows::Forms::Padding(5);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(92, 36);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(226, 344);
			this->checkBox3->Margin = System::Windows::Forms::Padding(5);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(92, 36);
			this->checkBox3->TabIndex = 7;
			this->checkBox3->Text = L"オ";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(226, 404);
			this->checkBox4->Margin = System::Windows::Forms::Padding(5);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(92, 36);
			this->checkBox4->TabIndex = 8;
			this->checkBox4->Text = L"オ";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label2->Location = System::Drawing::Point(76, 278);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 32);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Ωつ匡";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Margin = System::Windows::Forms::Padding(5);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1657, 846);
			this->tabControl1->TabIndex = 10;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->splitContainer1);
			this->tabPage1->Location = System::Drawing::Point(4, 40);
			this->tabPage1->Margin = System::Windows::Forms::Padding(5);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(5);
			this->tabPage1->Size = System::Drawing::Size(1649, 802);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"计";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(5, 5);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(5);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1->Controls->Add(this->label3);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox2);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox5);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox1);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox6);
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox7);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox3);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox8);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label5);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox4);
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->dataGridView1);
			this->splitContainer1->Size = System::Drawing::Size(1639, 792);
			this->splitContainer1->SplitterDistance = 545;
			this->splitContainer1->SplitterWidth = 7;
			this->splitContainer1->TabIndex = 18;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label3->Location = System::Drawing::Point(61, 141);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 39);
			this->label3->TabIndex = 17;
			this->label3->Text = L"癬翴";
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(315, 186);
			this->checkBox5->Margin = System::Windows::Forms::Padding(5);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(64, 36);
			this->checkBox5->TabIndex = 16;
			this->checkBox5->Text = L"";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(315, 125);
			this->checkBox6->Margin = System::Windows::Forms::Padding(5);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(64, 36);
			this->checkBox6->TabIndex = 15;
			this->checkBox6->Text = L"";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(173, 125);
			this->checkBox7->Margin = System::Windows::Forms::Padding(5);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(64, 36);
			this->checkBox7->TabIndex = 14;
			this->checkBox7->Text = L"";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(173, 186);
			this->checkBox8->Margin = System::Windows::Forms::Padding(5);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(64, 36);
			this->checkBox8->TabIndex = 13;
			this->checkBox8->Text = L"オ";
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(393, 441);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 21);
			this->label5->TabIndex = 12;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 38;
			this->dataGridView1->Size = System::Drawing::Size(1087, 792);
			this->dataGridView1->TabIndex = 10;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->splitContainer2);
			this->tabPage2->Location = System::Drawing::Point(4, 40);
			this->tabPage2->Margin = System::Windows::Forms::Padding(5);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(5);
			this->tabPage2->Size = System::Drawing::Size(1649, 802);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"计";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(5, 5);
			this->splitContainer2->Margin = System::Windows::Forms::Padding(5);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->label4);
			this->splitContainer2->Panel1->Controls->Add(this->button2);
			this->splitContainer2->Panel1->Controls->Add(this->textBox2);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->dataGridView2);
			this->splitContainer2->Size = System::Drawing::Size(1639, 792);
			this->splitContainer2->SplitterDistance = 410;
			this->splitContainer2->SplitterWidth = 7;
			this->splitContainer2->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(19, 31);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(169, 32);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Square Size";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::PeachPuff;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(24, 80);
			this->button2->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(340, 76);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Magic Square";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(209, 25);
			this->textBox2->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(153, 38);
			this->textBox2->TabIndex = 11;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(5);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 38;
			this->dataGridView2->Size = System::Drawing::Size(1222, 792);
			this->dataGridView2->TabIndex = 13;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->splitContainer3);
			this->tabPage3->Location = System::Drawing::Point(4, 40);
			this->tabPage3->Margin = System::Windows::Forms::Padding(5);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1649, 802);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"┮Τ案计";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Margin = System::Windows::Forms::Padding(5);
			this->splitContainer3->Name = L"splitContainer3";
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->label6);
			this->splitContainer3->Panel1->Controls->Add(this->button3);
			this->splitContainer3->Panel1->Controls->Add(this->textBox3);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->dataGridView3);
			this->splitContainer3->Size = System::Drawing::Size(1649, 802);
			this->splitContainer3->SplitterDistance = 549;
			this->splitContainer3->SplitterWidth = 7;
			this->splitContainer3->TabIndex = 18;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(27, 45);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(169, 32);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Square Size";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::PeachPuff;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(32, 94);
			this->button3->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(466, 143);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Magic Square";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(217, 39);
			this->textBox3->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(280, 38);
			this->textBox3->TabIndex = 15;
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView3->Location = System::Drawing::Point(0, 0);
			this->dataGridView3->Margin = System::Windows::Forms::Padding(5);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->RowTemplate->Height = 38;
			this->dataGridView3->Size = System::Drawing::Size(1093, 802);
			this->dataGridView3->TabIndex = 17;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1657, 846);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->Name = L"MyForm";
			this->Text = L"111701026_眎籉現";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel1->PerformLayout();
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->ResumeLayout(false);

		}


#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = int::Parse(textBox1->Text);
		if (n % 2 != 1) {
			MessageBox::Show("祘Α度続ノ计Magic SquareネΘ");
			return;
		}
		vector<vector<int>> square(n, vector<int>(n, 0));
		int num = 1, i, j;

		/*匡拒癬翴竚*/
		if (checkBox7->Checked) {i = 0; j = n / 2;}
		else if (checkBox6->Checked) {i = n - 1; j = n / 2;}
		else if (checkBox8->Checked) {i = n/2; j = 0;}
		else if (checkBox5->Checked) {i = n/2; j = n-1;}

		/*穝よ*/
		if (checkBox1->Checked) {
			while (num <= n * n) {
				square[i][j] = num++;
				int newi = (i - 1 + n) % n;//
				int newj = (j + 1) % n;//
				if (square[newi][newj]) {
					i = (i + 1) % n;
				}
				else {
					i = newi;
					j = newj;
				}
			}
		}
		else if (checkBox2->Checked) {
			while (num <= n * n) {
				square[i][j] = num++;
				int newi = (i + 1 + n) % n;//
				int newj = (j + 1) % n;//
				if (square[newi][newj]) {
					i = (i - 1+n) % n;
				}
				else {
					i = newi;
					j = newj;
				}
			}
		}
		else if (checkBox3->Checked) {
			while (num <= n * n) {
				square[i][j] = num++;
				int newi = (i - 1 + n) % n;//
				int newj = (j - 1 + n) % n;//オ
				if (square[newi][newj]) {
					i = (i + 1 + n) % n;
				}
				else {
					i = newi;
					j = newj;
				}
			}
		}
		else if (checkBox4->Checked) {
			while (num <= n * n) {
				square[i][j] = num++;
				int newi = (i + 1 + n) % n;//
				int newj = (j - 1 + n) % n;//オ
				if (square[newi][newj]) {
					i = (i - 1 + n) % n;
				}
				else {
					i = newi;
					j = newj;
				}
			}
		}
		dataGridView1->Columns->Clear();
		dataGridView1->Rows->Clear();
		dataGridView1->ColumnCount = n+1;
		dataGridView1->RowCount = n+1;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				dataGridView1->Rows[i]->Cells[j]->Value = square[i][j];
			}
		}
		
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = int::Parse(textBox2->Text);
		if (n % 4 != 0) {
			MessageBox::Show("祘Α度続ノ4计Magic SquareネΘ");
			return;
		}
		vector<vector<int>> square(n, vector<int>(n));
		int num = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				square[i][j] = num++;
			}
		}
		/*オオじ场腁ㄤ緇ぃ跑*/
		/*そΑ: n^2+1-x */
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (((i % 4 == j % 4) || ((i + j) % 4 == 3))) {
					square[i][j] = n * n + 1 - square[i][j];
				}
			}
		}

		dataGridView2->Columns->Clear();	dataGridView2->Rows->Clear();
		dataGridView2->ColumnCount = n;		dataGridView2->RowCount = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dataGridView2->Rows[i]->Cells[j]->Value = square[i][j];
			}
		}
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int n = int::Parse(textBox3->Text);
	if (n % 2 != 0 || n % 4 == 0) {
		MessageBox::Show("祘Α度続ノ案计獶4计ほよネΘ");
		return;
	}

	vector<vector<int>> square(n, vector<int>(n, 0)); 
	int half = n / 2;
	int subSquareSize = half;
	vector<vector<int>> baseSquare(half, vector<int>(half, 0));

	int num = 1;
	int i = 0, j = subSquareSize / 2;
	while (num <= subSquareSize * subSquareSize) {
		baseSquare[i][j] = num++;
		int newi = (i - 1 + subSquareSize) % subSquareSize;
		int newj = (j + 1) % subSquareSize;
		if (baseSquare[newi][newj]) {
			i = (i + 1) % subSquareSize;
		}
		else {
			i = newi;
			j = newj;
		}
	}

	for (int r = 0; r < half; r++) {
		for (int c = 0; c < half; c++) {
			square[r][c] = baseSquare[r][c];							 // オ
			square[r + half][c + half] = baseSquare[r][c] + half * half; // 
			square[r][c + half] = baseSquare[r][c] + 2 * half * half;    // 
			square[r + half][c] = baseSquare[r][c] + 3 * half * half;    // オ
		}
	}

	int k = (n - 2) / 4;
	for (int r = 0; r < half; r++) {
		for (int c = 0; c < k; c++) swap(square[r][c], square[r + half][c]);
		for (int c = n - k + 1; c < n; c++) swap(square[r][c], square[r + half][c]);
	}

	for (int c = k; c < k + 1; c++) swap(square[k][c], square[k + half][c]);

	dataGridView3->Columns->Clear();	dataGridView3->Rows->Clear();
	dataGridView3->ColumnCount = n;		dataGridView3->RowCount = n;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			dataGridView3->Rows[r]->Cells[c]->Value = square[r][c]; 
		}
	}
}
};
}