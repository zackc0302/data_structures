#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<algorithm>
#include<ctime>
#include<queue>
#include<stack>
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

//這裡的FindMin是找左子樹的max
Node* FindMin(Node* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}

struct Node* Delete(struct Node* root, int data) {
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	//發現欲刪除的點，開始進行下列判斷
	else {
		//無child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//只有右邊有child
		else if (root->left == NULL) {
			struct Node* temp = root;
			root = root->right;
			delete temp;
		}
		//只有左邊有child
		else if (root->right == NULL) {
			struct Node* temp = root;
			root = root->left;
			delete temp;
		}
		// 兩邊都有child<最難，有兩種方式，找左子樹的max或右子樹的min>
		else {
			struct Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

Node* Insert_non(Node* root, int data) {
	Node* newNode = new Node{ data, nullptr, nullptr };
	if (root == nullptr) return newNode;

	Node* current = root;
	while (true) {
		if (data <= current->data) {
			if (current->left == nullptr) {
				current->left = newNode;
				break;
			}
			else current = current->left;
		}
		else {
			if (current->right == nullptr) {
				current->right = newNode;
				break;
			}
			else current = current->right;
		}
	}
	return root;
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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button4;



	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::CheckBox^ checkBox8;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TreeView^ treeView1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;




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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(137, 46);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(244, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"insert into BST";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(59, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(71, 30);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(59, 109);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(71, 30);
			this->textBox2->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(137, 104);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(244, 52);
			this->button2->TabIndex = 2;
			this->button2->Text = L"delete from BST";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 23;
			this->listBox1->Location = System::Drawing::Point(3, 3);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(945, 792);
			this->listBox1->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(59, 171);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(71, 30);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(137, 162);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(244, 52);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Search from BST";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(59, 297);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(71, 30);
			this->textBox4->TabIndex = 8;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(137, 297);
			this->button4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(244, 52);
			this->button4->TabIndex = 7;
			this->button4->Text = L"random integers";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(31, 415);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(165, 27);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"inorder traversal";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(31, 462);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(177, 27);
			this->checkBox2->TabIndex = 13;
			this->checkBox2->Text = L"preorder traversal";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(31, 509);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(185, 27);
			this->checkBox3->TabIndex = 14;
			this->checkBox3->Text = L"postorder traversal";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(31, 556);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(187, 27);
			this->checkBox4->TabIndex = 15;
			this->checkBox4->Text = L"levelorder traversal";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->button6);
			this->splitContainer1->Panel1->Controls->Add(this->label4);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox6);
			this->splitContainer1->Panel1->Controls->Add(this->label3);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox5);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox7);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox8);
			this->splitContainer1->Panel1->Controls->Add(this->button5);
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1->Controls->Add(this->textBox6);
			this->splitContainer1->Panel1->Controls->Add(this->textBox5);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox4);
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox3);
			this->splitContainer1->Panel1->Controls->Add(this->button2);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox2);
			this->splitContainer1->Panel1->Controls->Add(this->textBox2);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox1);
			this->splitContainer1->Panel1->Controls->Add(this->button3);
			this->splitContainer1->Panel1->Controls->Add(this->textBox4);
			this->splitContainer1->Panel1->Controls->Add(this->textBox3);
			this->splitContainer1->Panel1->Controls->Add(this->button4);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer1->Size = System::Drawing::Size(1410, 834);
			this->splitContainer1->SplitterDistance = 447;
			this->splitContainer1->TabIndex = 16;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button6->DialogResult = System::Windows::Forms::DialogResult::Ignore;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->ForeColor = System::Drawing::SystemColors::MenuText;
			this->button6->Location = System::Drawing::Point(66, 677);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(304, 50);
			this->button6->TabIndex = 27;
			this->button6->Text = L"tree view";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(295, 375);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 23);
			this->label4->TabIndex = 26;
			this->label4->Text = L"非遞迴";
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(247, 462);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(177, 27);
			this->checkBox6->TabIndex = 23;
			this->checkBox6->Text = L"preorder traversal";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(133, 375);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 23);
			this->label3->TabIndex = 25;
			this->label3->Text = L"遞迴";
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(247, 415);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(165, 27);
			this->checkBox5->TabIndex = 24;
			this->checkBox5->Text = L"inorder traversal";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(247, 509);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(185, 27);
			this->checkBox7->TabIndex = 22;
			this->checkBox7->Text = L"postorder traversal";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(247, 556);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(187, 27);
			this->checkBox8->TabIndex = 21;
			this->checkBox8->Text = L"levelorder traversal";
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button5->DialogResult = System::Windows::Forms::DialogResult::Ignore;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->ForeColor = System::Drawing::SystemColors::MenuText;
			this->button5->Location = System::Drawing::Point(66, 602);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(304, 50);
			this->button5->TabIndex = 20;
			this->button5->Text = L"clear all";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(248, 249);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 23);
			this->label2->TabIndex = 19;
			this->label2->Text = L"to";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(74, 249);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 23);
			this->label1->TabIndex = 18;
			this->label1->Text = L"From";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(299, 246);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(71, 30);
			this->textBox6->TabIndex = 17;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(164, 246);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(71, 30);
			this->textBox5->TabIndex = 16;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(959, 834);
			this->tabControl1->TabIndex = 27;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 32);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(951, 798);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"text";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->treeView1);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(951, 805);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tree view";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// treeView1
			// 
			this->treeView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeView1->Location = System::Drawing::Point(3, 3);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(945, 799);
			this->treeView1->TabIndex = 5;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->pictureBox1);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(951, 805);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"picturebox";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(951, 805);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1410, 834);
			this->Controls->Add(this->splitContainer1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"binarySearchTree_111701026";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		const int NODE_RADIUS = 15;
		const int HORIZONTAL_SPACING = 120;
		const int VERTICAL_SPACING = 60;

		void DrawNode(Graphics^ g, Node* node, int x, int y, int depth, int xOffset) {
			if (node == nullptr) return;

			// 畫左子樹線與遞迴
			if (node->left != nullptr) {
				int leftX = x - xOffset;
				int leftY = y + VERTICAL_SPACING;
				g->DrawLine(Pens::Black, x, y, leftX, leftY);
				DrawNode(g, node->left, leftX, leftY, depth + 1, xOffset / 2);
			}

			// 畫右子樹線與遞迴
			if (node->right != nullptr) {
				int rightX = x + xOffset;
				int rightY = y + VERTICAL_SPACING;
				g->DrawLine(Pens::Black, x, y, rightX, rightY);
				DrawNode(g, node->right, rightX, rightY, depth + 1, xOffset / 2);
			}

			// 畫圓形節點與資料
			Rectangle rect(x - NODE_RADIUS, y - NODE_RADIUS, NODE_RADIUS * 2, NODE_RADIUS * 2);
			g->FillEllipse(Brushes::LightBlue, rect);
			g->DrawEllipse(Pens::Black, rect);

			String^ text = node->data.ToString();
			System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 10);
			SizeF textSize = g->MeasureString(text, font);
			PointF textPoint(x - textSize.Width / 2, y - textSize.Height / 2);
			g->DrawString(text, font, Brushes::Black, textPoint);
		}

		void DrawTree(Node* root) {
			if (pictureBox1->Image != nullptr)
				delete pictureBox1->Image;

			Bitmap^ bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			Graphics^ g = Graphics::FromImage(bmp);
			g->Clear(Color::White);

			int centerX = pictureBox1->Width / 1.8;
			int startY = NODE_RADIUS + 10;
			int initialOffset = 200;  // 根節點的左右展開間距
			DrawNode(g, root, centerX, startY, 0, initialOffset);

			pictureBox1->Image = bmp;
		}

		//印出過程
		void print(vector<int> vec) {
			String^ str = "";
			for (int i = 0; i < vec.size(); i++) {
				if (i == vec.size() - 1) {
					str += vec[i];
				}
				else {
					str += vec[i] + "->";
				}
			}
			listBox1->Items->Add(str);
			listBox1->Items->Add("==================");
		}

		//判斷是否搜尋成功
		bool Search(Node* root, int element, vector<int>& record)
		{
			if (root == NULL) {
				record.clear();
				return false;
			}
			else {
				record.push_back(root->data);
			}
			if (root->data == element) return true;
			if (element <= root->data)
				return Search(root->left, element, record);
			else
				return Search(root->right, element, record);
		}

		//遞迴中序排列(左->根->右)
		void Inorder(Node* root, vector<int>& record) {
			if (root == nullptr) return;
			Inorder(root->left, record);
			record.push_back(root->data);
			Inorder(root->right, record);
		}

		//遞迴前序排列(根->左->右)
		void preorder(Node* root, vector<int>& record) {
			if (root == nullptr) return;
			record.push_back(root->data);
			preorder(root->left, record);
			preorder(root->right, record);
		}

		//非遞迴前序排列(根->左->右)
		void Preorder_non(Node* root, vector<int>& record) {
			if (root == nullptr) return;
			stack<Node*> s;
			s.push(root);
			while (!s.empty()) {
				Node* curr = s.top();
				s.pop();
				record.push_back(curr->data);

				if (curr->right) s.push(curr->right); // 注意：先右後左，因為 stack 是後進先出
				if (curr->left) s.push(curr->left);
			}
		}

		//遞迴後序排列(左->右->根)
		void postorder(Node* root, vector<int>& record) {
			if (root == nullptr) return;
			postorder(root->left, record);
			postorder(root->right, record);
			record.push_back(root->data);
		}

		//非遞迴後序排列(左->右->根)
		void Postorder_non(Node* root, vector<int>& record) {
			if (root == nullptr) return;
			stack<Node*> s1, s2;
			s1.push(root);
			while (!s1.empty()) {
				Node* curr = s1.top(); s1.pop();
				s2.push(curr);
				if (curr->left) s1.push(curr->left);
				if (curr->right) s1.push(curr->right);
			}
			while (!s2.empty()) {
				record.push_back(s2.top()->data);
				s2.pop();
			}
		}


		//非遞迴中序排列(左->根->右)
		void Inorder_non(Node* root, vector<int>& record) {
			stack<Node*> nodeStack;
			Node* curr = root;
			while (curr != nullptr || !nodeStack.empty()) {
				while (curr != nullptr) {
					nodeStack.push(curr);
					curr = curr->left;
				}

				// 彈出堆疊頂部節點並處理
				curr = nodeStack.top();
				nodeStack.pop();

				record.push_back(curr->data);

				// 轉向右子樹
				curr = curr->right;
			}
		}

		void levelorder(Node* root, vector<int>& record) {
			if (root == NULL) return;
			queue<Node*> Q;
			Q.push(root);
			//while there is at least one discovered node
			while (!Q.empty()) {
				Node* current = Q.front();
				record.push_back(current->data);
				Q.pop(); // removing the element at front
				if (current->left != NULL) Q.push(current->left);
				if (current->right != NULL) Q.push(current->right);
			}
		}

		void clearall(vector<int>& record) {
			record.clear();
		}

		void DisplayBSTInTreeView(Node* root, TreeNode^ treeNode) {
			if (root == nullptr) return;

			TreeNode^ current = gcnew TreeNode(root->data.ToString());
			if (treeNode == nullptr)
				treeView1->Nodes->Add(current);
			else
				treeNode->Nodes->Add(current);

			DisplayBSTInTreeView(root->left, current);
			DisplayBSTInTreeView(root->right, current);
		}

		//初始化root
		Node* root = NULL;


		
		
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int n = int::Parse(textBox1->Text);
	vector<int> record;

	// 選擇遞迴或非遞迴插入
	if (checkBox5->Checked || checkBox6->Checked || checkBox7->Checked || checkBox8->Checked)
		root = Insert_non(root, n);
	else
		root = Insert(root, n);

	listBox1->Items->Add("Root is " + root->data);

	if (checkBox1->Checked)			Inorder(root, record);
	else if (checkBox2->Checked)	preorder(root, record);
	else if (checkBox3->Checked)	postorder(root, record);
	else if (checkBox4->Checked)	levelorder(root, record);
	else if (checkBox5->Checked)	Inorder_non(root, record);
	else if (checkBox6->Checked)	Preorder_non(root, record);
	else if (checkBox7->Checked)	Postorder_non(root, record);
	else if (checkBox8->Checked)	levelorder(root, record); // same as 4
	print(record);
	DrawTree(root);
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int element = int::Parse(textBox2->Text);
	vector<int> record;

	root = Delete(root, element);

	if (root != nullptr)
		listBox1->Items->Add("Root is " + root->data);
	else
		listBox1->Items->Add("Tree is now empty.");

	// 根據勾選的 traversal checkbox 顯示結果
	if (checkBox1->Checked)			Inorder(root, record);
	else if (checkBox2->Checked)	preorder(root, record);
	else if (checkBox3->Checked)	postorder(root, record);
	else if (checkBox4->Checked)	levelorder(root, record);
	else if (checkBox5->Checked)	Inorder_non(root, record);
	else if (checkBox6->Checked)	Preorder_non(root, record);
	else if (checkBox7->Checked)	Postorder_non(root, record);
	else if (checkBox8->Checked)	levelorder(root, record);

	print(record);
	DrawTree(root);
}


private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int target = int::Parse(textBox3->Text);
	vector<int> record;
	if (Search(root, target, record)) {
		listBox1->Items->Add(target + " has been found.");
		print(record);
	}
	else listBox1->Items->Add(target + " hasn't been found.");
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	srand(time(NULL));
	int num_integer = int::Parse(textBox4->Text);
	int minn = int::Parse(textBox5->Text);
	int maxx = int::Parse(textBox6->Text);

	vector<int> to_be_insert, record;
	for (int i = 0; i < num_integer; i++) {
		to_be_insert.push_back(rand() % (maxx - minn + 1) + minn);
	}

	// 顯示產生的亂數序列
	String^ str = "";
	for (int i = 0; i < to_be_insert.size(); i++) {
		str += to_be_insert[i];
		if (i != to_be_insert.size() - 1) str += "->";
	}
	listBox1->Items->Add("Random integers to be inserted: " + str);

	// 決定使用哪一種插入方式（遞迴或非遞迴）
	bool use_non_recursive_insert = checkBox5->Checked || checkBox6->Checked || checkBox7->Checked || checkBox8->Checked;

	for (int i = 0; i < num_integer; i++) {
		if (use_non_recursive_insert)
			root = Insert_non(root, to_be_insert[i]);
		else
			root = Insert(root, to_be_insert[i]);
	}

	listBox1->Items->Add("Root is " + root->data);

	// 決定 traversal 顯示方式
	if (checkBox1->Checked)			Inorder(root, record);
	else if (checkBox2->Checked)	preorder(root, record);
	else if (checkBox3->Checked)	postorder(root, record);
	else if (checkBox4->Checked)	levelorder(root, record);
	else if (checkBox5->Checked)	Inorder_non(root, record);
	else if (checkBox6->Checked)	Preorder_non(root, record);
	else if (checkBox7->Checked)	Postorder_non(root, record);
	else if (checkBox8->Checked)	levelorder(root, record);

	print(record);
	DrawTree(root);
}


private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<int> record;
	clearall(record);                 // 清空向量
	listBox1->Items->Clear();        // 清空 ListBox 顯示內容
	pictureBox1->Image = nullptr;    // 清空畫面上的樹圖
	treeView1->Nodes->Clear();       // 清空 TreeView 顯示的結構
	root = nullptr;                  // 清空 BST 資料本體（可選）
}



private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	treeView1->Nodes->Clear();
	DisplayBSTInTreeView(root, nullptr);
	treeView1->ExpandAll(); // 讓所有節點展開

}
};
}
