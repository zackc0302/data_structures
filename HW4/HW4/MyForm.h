#pragma once
namespace HW4 {

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
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;

	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ listBox6;
	private: System::Windows::Forms::ListBox^ listBox5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(7, 127);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(359, 81);
			this->button1->TabIndex = 0;
			this->button1->Text = L"infix->prefix";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(7, 271);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(359, 77);
			this->button2->TabIndex = 1;
			this->button2->Text = L"infix->postfix";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(395, 36);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(747, 43);
			this->textBox1->TabIndex = 2;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 37;
			this->listBox1->Location = System::Drawing::Point(395, 106);
			this->listBox1->Margin = System::Windows::Forms::Padding(4);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(747, 115);
			this->listBox1->TabIndex = 3;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 37;
			this->listBox2->Location = System::Drawing::Point(395, 251);
			this->listBox2->Margin = System::Windows::Forms::Padding(4);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(747, 115);
			this->listBox2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(158, 40);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 37);
			this->label1->TabIndex = 5;
			this->label1->Text = L"infix";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->HotTrack = true;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1553, 650);
			this->tabControl1->TabIndex = 6;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->listBox2);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Location = System::Drawing::Point(8, 51);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1537, 591);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"infix";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->listBox4);
			this->tabPage2->Controls->Add(this->listBox3);
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->textBox2);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(8, 51);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1537, 591);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"prefix";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 37;
			this->listBox4->Location = System::Drawing::Point(373, 264);
			this->listBox4->Margin = System::Windows::Forms::Padding(4);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(747, 115);
			this->listBox4->TabIndex = 11;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 37;
			this->listBox3->Location = System::Drawing::Point(373, 140);
			this->listBox3->Margin = System::Windows::Forms::Padding(4);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(747, 115);
			this->listBox3->TabIndex = 10;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(7, 259);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(359, 81);
			this->button4->TabIndex = 9;
			this->button4->Text = L"prefix->postfix";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(7, 157);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(359, 81);
			this->button3->TabIndex = 8;
			this->button3->Text = L"prefix->infix";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(373, 53);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(747, 43);
			this->textBox2->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(157, 63);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 37);
			this->label2->TabIndex = 6;
			this->label2->Text = L"prefix";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->textBox3);
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Controls->Add(this->button6);
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Controls->Add(this->listBox6);
			this->tabPage3->Controls->Add(this->listBox5);
			this->tabPage3->Location = System::Drawing::Point(8, 51);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1537, 591);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"postfix";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(380, 63);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(747, 43);
			this->textBox3->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(151, 66);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 37);
			this->label3->TabIndex = 12;
			this->label3->Text = L"postfix";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(13, 305);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(359, 81);
			this->button6->TabIndex = 11;
			this->button6->Text = L"postfix->prefix";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(13, 174);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(359, 81);
			this->button5->TabIndex = 10;
			this->button5->Text = L"postfix->infix";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// listBox6
			// 
			this->listBox6->FormattingEnabled = true;
			this->listBox6->ItemHeight = 37;
			this->listBox6->Location = System::Drawing::Point(380, 291);
			this->listBox6->Margin = System::Windows::Forms::Padding(4);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(747, 115);
			this->listBox6->TabIndex = 5;
			// 
			// listBox5
			// 
			this->listBox5->FormattingEnabled = true;
			this->listBox5->ItemHeight = 37;
			this->listBox5->Location = System::Drawing::Point(380, 157);
			this->listBox5->Margin = System::Windows::Forms::Padding(4);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(747, 115);
			this->listBox5->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(15, 37);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1553, 650);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	/*define "Stack" (array) as a stack with a "top" index.*/
	/*Stack1存運算子*/
		static array<String^>^ Stack1 = gcnew array<String^>(100);
		static int top = -1;
	/*Stack2存運算元*/
		static array<String^>^ Stack2 = gcnew array<String^>(100);
		static int top_a = -1;

		void get_fix(String^ x, int flag) {
			String^ a = pop(2);
			a = (flag == 1) ? x + pop(2) + a : pop(2) + a + x;
			push(2, a);
		}

	/*define the "push"*/
		void push(int flag, String^ data) {
			switch (flag) {
			case(1):/*只要Stack1還沒滿，把運算子丟入Stack1*/
				if (top == 99)
					break;
				else
					Stack1[++top]=data;
				break;
			case(2):/*只要Stack2還沒滿，把運算子丟入Stack1*/
				if (top_a == 99)
					break;
				else
					Stack2[++top_a]=data;
				break;
			}
		}

	/*define the "pop"*/
		String^ pop(int flag) {
			switch (flag) {
			case(1):/*Stack1若是滿了，將元素從上層推出*/
				if (top == -1)
					break;
				else
					return Stack1[top--];
				break;
			case(2):/*Stack2若是滿了，將元素從上層推出*/
				if (top_a == -1)
					break;
				else
					return Stack2[top_a--];
				break;
			}
		}

	/*define "p"進入堆疊[前]的優先順序*/
		int p(String^ op) {
			if ((op == "+") || (op == "-")) return 3;
			if ((op == "*") || (op == "/")) return 4;
			if ((op == "^") || (op == "&") || (op == "|")) return 5;
			if (op == "(") return 8;
			if (op == "#") return -1;
		}

	/*define "q"進入堆疊[後]的優先順序*/
		int q(String^ op) {
			if ((op == "+") || (op == "-")) return 3;
			if ((op == "*") || (op == "/")) return 4;
			if ((op == "^") || (op == "&") || (op == "|")) return 5;
			if (op == "(") return 1;
			if (op == "#") return -1;
		}

	/*判斷字元是否合法*/
		bool IsOperand(String^ s) {
			MessageBox::Show("s = " + s);/*show出所有運算元、運算子*/
			if ((s != "+") && (s != "-") && (s != "*") && (s != "/") && (s != "(") && (s != ")") && (s != "&") && (s != "|") && (s != "^"))
				return true;
			return false;
		}

	/*infix轉成其他的*/
		String^ transformation(String^ infix, int flag) {
			int i, j;
			String^ s, ^ x;
			push(1, "#");/*在Stack1中先放入"#"*/
			for (i = 0; i < infix->Length; i++) {
				s =  Convert::ToString(infix[i]);
				if (IsOperand(s))
					push(2, s); /*運算元放入Stack2*/
				else if (s == ")")
					while ((x = pop(1)) != "(") {
							get_fix(x, flag);
					}
				else {
					while (p(s) <= q(Stack1[top])) {
						x = pop(1);
						get_fix(x, flag);
					}
					push(1, s);
				}
			}
			while (Stack1[top] != "#") {
				x = pop(1);
				get_fix(x, flag);
			}
			pop(1);
			return pop(2);
	}
	
	/*prefix->postfix*/
		String^ prefixTopostfix(String^ prefix)
		{
			int i, counter = 0;
			String^ s,^ post;
			/*key:從後往前看*/
			for (i = prefix->Length -1; i >= 0; i--)
			{
				s = Convert::ToString(prefix[i]);
				if (IsOperand(s))
					push(2, s);
				else
				{
					post = pop(2);/*post為Stack2的最上層元素*/
					post += pop(2) + s;/*post更新為Stack2的最上層兩元素+倒數第一的運算子*/
					push(2, post);/*將完成的放入Stack2*/
				}
			}
			return pop(2);/*將Stack2的東西回傳*/
		}

	/*prefix->infix*/
		String^ prefixToinfix(String^ prefix)
		{
			int i;
			String^ s,^ s1,^ s2,^ x,^ y,^ prev = "#";
			/*key:從後往前看*/
			for (i = prefix->Length -1; i >=0; i--)
			{
				s = Convert::ToString(prefix[i]);
				push(1, "#");
				if (IsOperand(s)){
					push(2, s);
				}
				else{
					s1 = pop(1);
					s2 = pop(1);
					x = pop(2);
					y = pop(2);
					if (q(s1) < q(s) && x->Length > 1)
						x = "(" + x + ")";
					if (q(s2) < q(s) && y->Length > 1)
						y = "(" + y + ")";
					push(2, x + s + y);
					push(1, s);
				}
			}
			return pop(2);/*將Stack2的東西回傳*/
		}

	/*postfix->prefix*/
		String^ postfixToprefix(String^ postfix)
		{
			int i;
			String^ s,^ x;
			for (i = 0; i < postfix->Length; i++)
			{
				s = Convert::ToString(postfix[i]);
				if (IsOperand(s))
					push(2, s);
				else
					get_fix(s, 1);
			}
			return pop(2);
		}

	/*postfix->infix*/
		String^ postfixToinfix(String^ postfix)
		{
			int i;
			String^ s,^ s1,^ s2,^ x,^ y,^ prev = "#";
			for (i = 0; i < postfix->Length; i++)
			{
				s = Convert::ToString(postfix[i]);
				if (IsOperand(s))
				{
					push(2, s);
					push(1, "#");
				}
				else
				{
					s1 = pop(1);
					s2 = pop(1);
					x = pop(2);
					y = pop(2);
					if (p(s) > p(s1) && x->Length > 1)
						x = "(" + x + ")";
					if (p(s) > p(s2) && y->Length > 1)
						y = "(" + y + ")";
					push(2, y + s + x);
					push(1, s);
				}
			}
			return pop(2);
		}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ infix = textBox1->Text;
	String^ prefix = transformation(infix,1);
	listBox1->Items->Add(prefix);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ infix = textBox1->Text;
	String^ postfix = transformation(infix, 2);
	listBox2->Items->Add(postfix);	
}	
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ prefix = textBox2->Text;
	String^ infix = prefixToinfix(prefix);
	listBox3->Items->Add(infix);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ prefix = textBox2->Text;
	String^ postfix = prefixTopostfix(prefix);
	listBox4->Items->Add(postfix);
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ postfix = textBox3->Text;
	String^ infix = postfixToinfix(postfix);
	listBox5->Items->Add(infix);
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ postfix = textBox3->Text;
	String^ prefix = postfixToprefix(postfix);
	listBox6->Items->Add(prefix);
}
};
}
