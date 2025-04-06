#pragma once
# include <stdio.h>
#include <ctime>
#include <cmath>
int width;
int height;
int end_x;
int end_y;
#define possible_direction 8
struct offset {
	int dx, dy;
};
enum directions {
	N, NE, E, SE, S, SW, W, NW
};
struct position {
	int x, y;
	directions dir;
};
struct offset move[possible_direction];
struct offset f1[4];
struct offset f2[4];

int** maze;
int** mark;
int m, p, top;
struct position* stack;

void push(struct position data) {
	if (top == (m * p - 1)) {
		// Handle StackFull condition
	}
	else {
		stack[++top] = data;
	}
}

struct position pop() {
	if (top == -1) {
		// Handle StackEmpty condition
	}
	else {
		return stack[top--];
	}
}

int nextMove(int x, int y) {

	f1[0] = { -1, 0 }; // N
	f1[1] = { 0, 1 };  // E
	f1[2] = { 1, 0 };  // S
	f1[3] = { 0, -1 }; // W

	f2[0] = { -2, 0 }; // N
	f2[1] = { 0, 2 };  // E
	f2[2] = { 2, 0 };  // S
	f2[3] = { 0, -2 }; // W

	for (int i = 0; i < 4; i++) {
		int nx = x + f2[i].dx;
		int ny = y + f2[i].dy;
		if (nx >= 0 && nx < height && ny >= 0 && ny < width && maze[nx][ny] == 1) {
			return 1;
		}
	}
	return 0;
}

//void path(int m, int p, int step_x, int step_y) {
//	if (mark != nullptr) {
//		for (int i = 0; i < height; i++) delete[] mark[i];
//		delete[] mark;
//		mark = nullptr;
//	}
//	
//	top = -1;
//
//	stack = new struct position[width * height];
//
//	struct position step;
//	int i, j, u, v;
//	directions d;
//	
//	step.x = step_x;
//	step.y = step_y;
//	step.dir = E;
//	push(step);
//
//	move[N].dx = -1; move[N].dy = 0;
//	move[NE].dx = -1; move[NE].dy = 1;
//	move[E].dx = 0; move[E].dy = 1;
//	move[SE].dx = 1;  move[SE].dy = 1;
//	move[S].dx = 1; move[S].dy = 0;
//	move[SW].dx = 1; move[SW].dy = -1;
//	move[W].dx = 0; move[W].dy = -1;
//	move[NW].dx = -1; move[NW].dy = -1;
//
//	mark = new int* [height];
//	for (int i = 0; i < height; i++) {
//		mark[i] = new int[width];
//	}
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			mark[i][j] = maze[i][j];
//		}
//	}
//
//	while (top != -1) {
//		step = pop();
//		i = step.x;
//		j = step.y;
//		d = step.dir;
//
//		for (d = static_cast<directions>(0); d <= 7; d = static_cast<directions>(static_cast<int>(d) + 1)) {
//			u = i + move[d].dx;
//			v = j + move[d].dy;
//
//			/*判斷u, v是否可走且不曾走過*/
//			if (u >= 0 && u < height && v >= 0 && v < width && !maze[u][v] && !mark[u][v]) {
//				mark[u][v] = 3;/*走過的路徑顯示3*/
//				step.x = i;
//				step.y = j;
//				step.dir = static_cast<directions>(static_cast<int>(d) + 1);
//				push(step);/*若腳下的位置有辦法通往下一步，將腳下的位置推放進堆疊*/
//				if ((u == m) && (v == p)) {
//					// Print the path from exit to entrance
//					delete[] stack;/*找到終點則刪除堆疊*/
//					return;/*結束path()*/
//				}
//				step.x = u;
//				step.y = v;
//				step.dir = N;
//				push(step);
//				break;
//				//i = u;
//				//j = v;
//				//d = N;/*方向回到初始的方向，以利迴圈執行*/
//			}
//
//		}
//	}
//	// Print "No way out in this maze"
//	delete[] stack;
//}

void path(int m, int p, int step_x, int step_y) {
	/*if (mark != nullptr && height > 0) {
		for (int i = 0; i < height; i++) {
			if (mark[i] != nullptr)
				delete[] mark[i];
		}
		delete[] mark;
		mark = nullptr;
	}*/


	top = -1;

	stack = new struct position[width * height];

	struct position step;
	int i, j, u, v;
	directions d;

	// 初始方向為 N（之後會從 N 開始嘗試）
	step.x = step_x;
	step.y = step_y;
	step.dir = N;
	push(step);

	// 設定方向表
	move[N].dx = -1; move[N].dy = 0;
	move[NE].dx = -1; move[NE].dy = 1;
	move[E].dx = 0; move[E].dy = 1;
	move[SE].dx = 1;  move[SE].dy = 1;
	move[S].dx = 1; move[S].dy = 0;
	move[SW].dx = 1; move[SW].dy = -1;
	move[W].dx = 0; move[W].dy = -1;
	move[NW].dx = -1; move[NW].dy = -1;

	mark = new int* [height];
	for (int i = 0; i < height; i++) {
		mark[i] = new int[width];
		for (int j = 0; j < width; j++) {
			mark[i][j] = maze[i][j];
		}
	}

	// 起點標記為已走過
	mark[step_x][step_y] = 3;

	while (top != -1) {
		step = pop();
		i = step.x;
		j = step.y;
		d = step.dir;

		// 從上次方向開始繼續走
		for (; d <= NW; d = static_cast<directions>(static_cast<int>(d) + 1)) {
			u = i + move[d].dx;
			v = j + move[d].dy;

			if (u >= 0 && u < height && v >= 0 && v < width && !maze[u][v] && !mark[u][v]) {
				// 將目前節點推回（保留下一方向）
				step.x = i;
				step.y = j;
				step.dir = static_cast<directions>(static_cast<int>(d) + 1);
				push(step);

				// 推入新節點
				struct position next;
				next.x = u;
				next.y = v;
				next.dir = N;
				push(next);

				mark[u][v] = 3;

				// 若是終點則回傳
				if ((u == m) && (v == p)) {
					delete[] stack;
					return;
				}
				break;
			}
		}

		// 如果八個方向都嘗試過，代表走到底、無法再前進 → 回溯
		if (d > NW) {
			mark[i][j] = 4; // 回溯錯路
		}
	}

	delete[] stack;
}

namespace HW3 {

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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
	/// <summary>
	/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
	/// 這個方法的內容。
	/// </summary>
	void InitializeComponent(void)
		{
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
		this->textBox1 = (gcnew System::Windows::Forms::TextBox());
		this->textBox2 = (gcnew System::Windows::Forms::TextBox());
		this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
		this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
		this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
		this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
		this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
		this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
		this->textBox5 = (gcnew System::Windows::Forms::TextBox());
		this->textBox6 = (gcnew System::Windows::Forms::TextBox());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->textBox4 = (gcnew System::Windows::Forms::TextBox());
		this->textBox3 = (gcnew System::Windows::Forms::TextBox());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->button4 = (gcnew System::Windows::Forms::Button());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
		this->tabControl1->SuspendLayout();
		this->tabPage1->SuspendLayout();
		this->tabPage2->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
		this->splitContainer2->Panel1->SuspendLayout();
		this->splitContainer2->Panel2->SuspendLayout();
		this->splitContainer2->SuspendLayout();
		this->SuspendLayout();
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(52, 84);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(109, 27);
		this->label1->TabIndex = 0;
		this->label1->Text = L"Height(m)";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(52, 124);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(98, 27);
		this->label2->TabIndex = 1;
		this->label2->Text = L"Width(p)";
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(57, 388);
		this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(191, 47);
		this->button1->TabIndex = 2;
		this->button1->Text = L"Path";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(57, 443);
		this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(191, 47);
		this->button2->TabIndex = 3;
		this->button2->Text = L"Load Maze";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
		// 
		// button3
		// 
		this->button3->Location = System::Drawing::Point(57, 498);
		this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(191, 47);
		this->button3->TabIndex = 4;
		this->button3->Text = L"Save Maze";
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
		// 
		// openFileDialog1
		// 
		this->openFileDialog1->FileName = L"openFileDialog1";
		this->openFileDialog1->ShowHelp = true;
		this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
		// 
		// textBox1
		// 
		this->textBox1->Location = System::Drawing::Point(167, 84);
		this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->textBox1->Name = L"textBox1";
		this->textBox1->Size = System::Drawing::Size(140, 34);
		this->textBox1->TabIndex = 5;
		// 
		// textBox2
		// 
		this->textBox2->Location = System::Drawing::Point(167, 126);
		this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->textBox2->Name = L"textBox2";
		this->textBox2->Size = System::Drawing::Size(140, 34);
		this->textBox2->TabIndex = 6;
		// 
		// dataGridView1
		// 
		this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
		this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
		this->dataGridView1->Location = System::Drawing::Point(3, 4);
		this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->dataGridView1->Name = L"dataGridView1";
		this->dataGridView1->RowHeadersWidth = 82;
		this->dataGridView1->RowTemplate->Height = 38;
		this->dataGridView1->Size = System::Drawing::Size(1178, 797);
		this->dataGridView1->TabIndex = 7;
		this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
		// 
		// dataGridView2
		// 
		this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
		this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
		this->dataGridView2->GridColor = System::Drawing::Color::Gray;
		this->dataGridView2->Location = System::Drawing::Point(3, 4);
		this->dataGridView2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->dataGridView2->Name = L"dataGridView2";
		this->dataGridView2->RowHeadersWidth = 82;
		this->dataGridView2->RowTemplate->Height = 38;
		this->dataGridView2->Size = System::Drawing::Size(1043, 793);
		this->dataGridView2->TabIndex = 8;
		// 
		// tabControl1
		// 
		this->tabControl1->Controls->Add(this->tabPage1);
		this->tabControl1->Controls->Add(this->tabPage2);
		this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
		this->tabControl1->Location = System::Drawing::Point(0, 0);
		this->tabControl1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->tabControl1->Name = L"tabControl1";
		this->tabControl1->SelectedIndex = 0;
		this->tabControl1->Size = System::Drawing::Size(1192, 845);
		this->tabControl1->TabIndex = 9;
		// 
		// tabPage1
		// 
		this->tabPage1->Controls->Add(this->dataGridView1);
		this->tabPage1->Location = System::Drawing::Point(4, 36);
		this->tabPage1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->tabPage1->Name = L"tabPage1";
		this->tabPage1->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->tabPage1->Size = System::Drawing::Size(1184, 805);
		this->tabPage1->TabIndex = 0;
		this->tabPage1->Text = L"檔案迷宮";
		this->tabPage1->UseVisualStyleBackColor = true;
		// 
		// tabPage2
		// 
		this->tabPage2->Controls->Add(this->dataGridView2);
		this->tabPage2->Location = System::Drawing::Point(4, 40);
		this->tabPage2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->tabPage2->Name = L"tabPage2";
		this->tabPage2->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->tabPage2->Size = System::Drawing::Size(1049, 801);
		this->tabPage2->TabIndex = 1;
		this->tabPage2->Text = L"迷宮結果";
		this->tabPage2->UseVisualStyleBackColor = true;
		// 
		// splitContainer2
		// 
		this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
		this->splitContainer2->Location = System::Drawing::Point(0, 0);
		this->splitContainer2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->splitContainer2->Name = L"splitContainer2";
		// 
		// splitContainer2.Panel1
		// 
		this->splitContainer2->Panel1->Controls->Add(this->checkBox1);
		this->splitContainer2->Panel1->Controls->Add(this->textBox5);
		this->splitContainer2->Panel1->Controls->Add(this->textBox6);
		this->splitContainer2->Panel1->Controls->Add(this->label4);
		this->splitContainer2->Panel1->Controls->Add(this->textBox4);
		this->splitContainer2->Panel1->Controls->Add(this->textBox3);
		this->splitContainer2->Panel1->Controls->Add(this->label3);
		this->splitContainer2->Panel1->Controls->Add(this->button4);
		this->splitContainer2->Panel1->Controls->Add(this->label1);
		this->splitContainer2->Panel1->Controls->Add(this->textBox2);
		this->splitContainer2->Panel1->Controls->Add(this->label2);
		this->splitContainer2->Panel1->Controls->Add(this->textBox1);
		this->splitContainer2->Panel1->Controls->Add(this->button1);
		this->splitContainer2->Panel1->Controls->Add(this->button3);
		this->splitContainer2->Panel1->Controls->Add(this->button2);
		// 
		// splitContainer2.Panel2
		// 
		this->splitContainer2->Panel2->Controls->Add(this->tabControl1);
		this->splitContainer2->Size = System::Drawing::Size(1567, 845);
		this->splitContainer2->SplitterDistance = 371;
		this->splitContainer2->TabIndex = 10;
		// 
		// checkBox1
		// 
		this->checkBox1->AutoSize = true;
		this->checkBox1->Location = System::Drawing::Point(43, 278);
		this->checkBox1->Name = L"checkBox1";
		this->checkBox1->Size = System::Drawing::Size(221, 31);
		this->checkBox1->TabIndex = 14;
		this->checkBox1->Text = L"自行選擇起點/終點\?";
		this->checkBox1->UseVisualStyleBackColor = true;
		// 
		// textBox5
		// 
		this->textBox5->Location = System::Drawing::Point(128, 227);
		this->textBox5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->textBox5->Name = L"textBox5";
		this->textBox5->Size = System::Drawing::Size(57, 34);
		this->textBox5->TabIndex = 13;
		// 
		// textBox6
		// 
		this->textBox6->Location = System::Drawing::Point(195, 227);
		this->textBox6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->textBox6->Name = L"textBox6";
		this->textBox6->Size = System::Drawing::Size(57, 34);
		this->textBox6->TabIndex = 12;
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Location = System::Drawing::Point(67, 230);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(54, 27);
		this->label4->TabIndex = 11;
		this->label4->Text = L"終點";
		// 
		// textBox4
		// 
		this->textBox4->Location = System::Drawing::Point(195, 185);
		this->textBox4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->textBox4->Name = L"textBox4";
		this->textBox4->Size = System::Drawing::Size(57, 34);
		this->textBox4->TabIndex = 10;
		// 
		// textBox3
		// 
		this->textBox3->Location = System::Drawing::Point(128, 185);
		this->textBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->textBox3->Name = L"textBox3";
		this->textBox3->Size = System::Drawing::Size(57, 34);
		this->textBox3->TabIndex = 9;
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(67, 188);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(54, 27);
		this->label3->TabIndex = 8;
		this->label3->Text = L"起點";
		// 
		// button4
		// 
		this->button4->Location = System::Drawing::Point(57, 333);
		this->button4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->button4->Name = L"button4";
		this->button4->Size = System::Drawing::Size(191, 47);
		this->button4->TabIndex = 7;
		this->button4->Text = L"Generate maze";
		this->button4->UseVisualStyleBackColor = true;
		this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
		// 
		// MyForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(12, 27);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(1567, 845);
		this->Controls->Add(this->splitContainer2);
		this->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		this->Name = L"MyForm";
		this->Text = L"mouse_maze_111701026";
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
		this->tabControl1->ResumeLayout(false);
		this->tabPage1->ResumeLayout(false);
		this->tabPage2->ResumeLayout(false);
		this->splitContainer2->Panel1->ResumeLayout(false);
		this->splitContainer2->Panel1->PerformLayout();
		this->splitContainer2->Panel2->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
		this->splitContainer2->ResumeLayout(false);
		this->ResumeLayout(false);

	}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void bindingNavigator1_RefreshItems(System::Object^ sender, System::EventArgs^ e) {
	}

	/*path*/
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		struct position step;
		if (checkBox1->Checked) {
			step.x = int::Parse(textBox3->Text);
			step.y = int::Parse(textBox4->Text);
			end_x = int::Parse(textBox5->Text);
			end_y = int::Parse(textBox6->Text);
		}
		else {
			step.x = 1;
			step.y = 0;
			end_x = width - 2;
			end_y = height - 2;
		}

		path(end_x, end_y, step.x, step.y);
		
		dataGridView2->Rows->Clear();
		dataGridView2->Columns->Clear();
		dataGridView2->RowCount = height+1; // 要多加 1，不然他會IndexOutOfRange，可能是dataGridView本身的設定問題
		dataGridView2->ColumnCount = width;
		dataGridView2->ColumnHeadersVisible = false; // 隱藏columns
		dataGridView2->RowHeadersVisible = false; // 隱藏index
		dataGridView2->AllowUserToAddRows = false; // 去掉最後一行空白行

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				dataGridView2->Rows[i]->Cells[j]->Value = mark[i][j];

		/*標記起點以及終點*/
		/*先預設起點是[1][0]，終點是[width-2][height-1]*/
		/*mark[1][0] = 3;
		mark[width - 2][height - 1] = 3;*/

		/*上色*/
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (mark[i][j] == 1)
					dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::Navy;
				else if (mark[i][j] == 2)
					dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::Green;
				else if (mark[i][j] == 0)
					dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
				else if (mark[i][j] == 3) {
					dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::Yellow;
					dataGridView2->Rows[i]->Cells[j]->Value = "🐭";
				}
				else if (mark[i][j] == 4)
					dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::LightBlue;
			}
		}
		/*上色*/
	}

	/*load maze*/
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// 清空舊的 maze 與 mark
		/*if (maze != nullptr) {
			for (int i = 0; i < height; i++) delete[] maze[i];
			delete[] maze;
			maze = nullptr;
		}
		if (mark != nullptr) {
			for (int i = 0; i < height; i++) delete[] mark[i];
			delete[] mark;
			mark = nullptr;
		}*/

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) //順利開檔才要繼續做下去
		{
			StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName);
			String^ firstLine = reader->ReadLine(); // 一次讀檔案中的一行
			cli::array<String^>^ width_and_height = firstLine->Split(gcnew array<wchar_t>{' ', '\t'}, StringSplitOptions::RemoveEmptyEntries);
			width = int::Parse(width_and_height[0]);
			height = int::Parse(width_and_height[1]);
			textBox1->Text = width_and_height[0];
			textBox2->Text = width_and_height[1];
			maze = new int* [height];
			for (int i = 0; i < height; i++){
				maze[i] = new int[width];
			}
			for (int i = 0; i < height; i++) {
				cli::array<String^>^ maze_content = reader->ReadLine()->Split(gcnew array<wchar_t>{' ', '\t'}, StringSplitOptions::RemoveEmptyEntries);
				for (int j = 0; j < width; j++) {
					maze[i][j] = int::Parse(maze_content[j]);
				}
			}
			dataGridView1->RowCount = height+1; // 要多加 1，不然他會IndexOutOfRange，可能是dataGridView本身的設定問題
			dataGridView1->ColumnCount = width;
			dataGridView1->ColumnHeadersVisible = false; // 隱藏columns
			dataGridView1->RowHeadersVisible = false; // 隱藏index
			dataGridView1->AllowUserToAddRows = false; // 去掉最後一行空白行
			//dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill; // 調整欄位寬度，但不知為何這邊沒辦法用這行程式，所以手動去更改屬性的地方
			for (int i = 0; i < height; i++){
				for (int j = 0; j < width; j++){
					dataGridView1->Rows[i]->Cells[j]->Value = maze[i][j];
				}
			}
		}
	}

	/*save maze*/
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		// 讓系統知道存放路徑
		try
		{
			StreamWriter^ writer = gcnew StreamWriter(Directory::GetCurrentDirectory() + "- output.txt");
			// 第一行先填入width和height
			String^ firstLine = width + " " + height;
			writer->WriteLine(firstLine);
			// 填入迷宮內容
			for (int i = 0; i < dataGridView1->RowCount; i++)
			{
				String^ outputString = "";
				for (int j = 0; j < dataGridView1->ColumnCount; j++)
				{
					outputString += dataGridView1->Rows[i]->Cells[j]->Value + " ";
				}
				writer->WriteLine(outputString);
			}
			// 寫完記得關檔
			writer->Close();
			MessageBox::Show("Save successfully !");
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Save failed !");
		}
	}

	/*Generate maze*/
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (maze != nullptr) {
			for (int i = 0; i < height; i++) delete[] maze[i];
			delete[] maze;
			maze = nullptr;
		}
		if (mark != nullptr) {
			for (int i = 0; i < height; i++) delete[] mark[i];
			delete[] mark;
			mark = nullptr;
		}
		// 讀取使用者輸入的高度與寬度
		height = int::Parse(textBox1->Text);
		width = int::Parse(textBox2->Text);
		m = height;
		p = width;

		// 初始化 stack 與 top
		top = -1;
		stack = new struct position[height * width];

		// 初始化 f1 與 f2（方向）
		f1[0] = { -1, 0 }; // N
		f1[1] = { 0, 1 };  // E
		f1[2] = { 1, 0 };  // S
		f1[3] = { 0, -1 }; // W

		f2[0] = { -2, 0 }; // N
		f2[1] = { 0, 2 };  // E
		f2[2] = { 2, 0 };  // S
		f2[3] = { 0, -2 }; // W

		// 建立 maze 陣列
		maze = new int* [height];
		for (int i = 0; i < height; i++) {
			maze[i] = new int[width];
		}

		// 初始化 maze，邊界設為 2，其餘為 1（牆壁）
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
					maze[i][j] = 2;
				else
					maze[i][j] = 1;
			}
		}


		struct position step;
		if (checkBox1->Checked) {
			step.x = int::Parse(textBox3->Text);
			step.y = int::Parse(textBox4->Text);
			end_x = int::Parse(textBox5->Text);
			end_y = int::Parse(textBox6->Text);

		}
		else {
			step.x = 1;
			step.y = 0;
		}// 起點 [1][0] 設為通道
		
		
		/*maze[step.x][step.y] = 0;*/
		push(step);

		Random^ rnd = gcnew Random();

		// 開始挖迷宮
		while (top != -1) {
			step = pop();
			while (nextMove(step.x, step.y)) {
				int d = rnd->Next(4); // 0~3
				int nx = step.x + f2[d].dx;
				int ny = step.y + f2[d].dy;
				if (nx >= 0 && nx < height && ny >= 0 && ny < width && maze[nx][ny] == 1) {
					maze[step.x + f1[d].dx][step.y + f1[d].dy] = 0;
					maze[nx][ny] = 0;
					struct position next = { nx, ny };
					push(next);
					step = next;
				}
			}
		}
		/*把終點標記*/
		if(checkBox1->Checked)maze[end_x][end_y] = 0;
		else maze[height - 2][width - 2] = 0;

		// 顯示 maze 到 DataGridView
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		dataGridView1->RowCount = height;
		dataGridView1->ColumnCount = width;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				dataGridView1->Rows[i]->Cells[j]->Value = maze[i][j].ToString();
			}
		}
	}

};
}