#pragma once
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

int boardSize=0;
vector<vector<int>> boardGrid;

//將移動方向建表
int xMove[8] = { 2,1,-1,-2,-2,-1,1,2 };
int yMove[8] = { 1,2,2,1,-1,-2,-2,-1 };

//檢查邊界
bool safe(int x, int y) {
	return (x >= 0 && x < boardSize && y >= 0 && y < boardSize && boardGrid[x][y] == -1);
}

// 計算可行的下一步數量(by Warnsdorff's Rule)，優先選擇可行路徑最少的移動
int countAvailableMoves(int x, int y) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		int nextX = x + xMove[i];
		int nextY = y + yMove[i];
		if (safe(nextX, nextY)) {
			count++;
		}
	}
	return count;
}

bool solveKTUtil(int x, int y, int moveCount) {
	if (moveCount == boardSize * boardSize) return true;

	vector<pair<int, int>> moves;
	for (int i = 0; i < 8; i++) {
		int nextX = x + xMove[i];
		int nextY = y + yMove[i];
		if (safe(nextX, nextY)) {
			// 優先選擇下一步選項最少的移動
			moves.push_back({ countAvailableMoves(nextX, nextY), i });
		}
	}

	// 根據 Warnsdorff's Rule，先選擇可行路徑最少的移動
	sort(moves.begin(), moves.end());

	for (auto &move : moves) {
		int i = move.second;
		int nextX = x + xMove[i];
		int nextY = y + yMove[i];
		boardGrid[nextX][nextY] = moveCount;
		//這一步走到之後還可以繼續往下走
		if (solveKTUtil(nextX, nextY, moveCount + 1)) return true;
		boardGrid[nextX][nextY] = -1; // 回溯
	}
	return false;
}

namespace bonus2 {

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
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
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
			this->splitContainer1->Panel1->Controls->Add(this->textBox3);
			this->splitContainer1->Panel1->Controls->Add(this->textBox2);
			this->splitContainer1->Panel1->Controls->Add(this->label3);
			this->splitContainer1->Panel1->Controls->Add(this->button2);
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer1->Size = System::Drawing::Size(1659, 999);
			this->splitContainer1->SplitterDistance = 459;
			this->splitContainer1->SplitterWidth = 6;
			this->splitContainer1->TabIndex = 0;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(326, 278);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(81, 52);
			this->textBox3->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(198, 278);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(81, 52);
			this->textBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(60, 282);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(487, 37);
			this->label3->TabIndex = 6;
			this->label3->Text = L"( x , y )= (              ,                )";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(54, 543);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(387, 102);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Knight Tour Animation";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(54, 398);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(387, 102);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Knight Tour";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(67, 214);
			this->checkBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(277, 41);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"Random position";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(66, 150);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(244, 37);
			this->label2->TabIndex = 2;
			this->label2->Text = L"starting position";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(134, 60);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(191, 52);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(66, 68);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"n=";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1194, 999);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 47);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage1->Size = System::Drawing::Size(1093, 948);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Tour in listBox";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 37;
			this->listBox1->Location = System::Drawing::Point(4, 5);
			this->listBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(1085, 938);
			this->listBox1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 47);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage2->Size = System::Drawing::Size(1093, 948);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Tour in StringGrid";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(4, 5);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 38;
			this->dataGridView1->Size = System::Drawing::Size(1085, 938);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView2);
			this->tabPage3->Location = System::Drawing::Point(4, 47);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1186, 948);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Tour in Animation";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 82;
			this->dataGridView2->RowTemplate->Height = 38;
			this->dataGridView2->Size = System::Drawing::Size(1186, 948);
			this->dataGridView2->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(19, 37);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1659, 999);
			this->Controls->Add(this->splitContainer1);
			this->Font = (gcnew System::Drawing::Font(L"新細明體", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"bonus2-111701026";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		boardSize = int::Parse(textBox1->Text);
		int attempted_move = 0;

		// **確保重新初始化 boardGrid**
		vector<vector<int>>().swap(boardGrid);
		boardGrid.assign(boardSize, vector<int>(boardSize, -1));

		//決定起點是要自行生成或是輸入指定
		int startX, startY;
		if (checkBox1->Checked) {
			srand(time(NULL));
			startX = rand() % boardSize;
			startY = rand() % boardSize;
			textBox2->Text = startX.ToString();
			textBox3->Text = startY.ToString();
		}
		else {
			if (textBox2->Text == "" || textBox3->Text == "") {
				MessageBox::Show("請輸入起始座標!", "錯誤", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			startX = int::Parse(textBox2->Text);
			startY = int::Parse(textBox3->Text);
		}

		//第一個填入的數字為0
		boardGrid[startX][startY] = 0;

		//solveKTUtil裡面的變數(當前X座標,當前Y座標,填到的數字)
		if (!solveKTUtil(startX, startY, 1)) {
			listBox1->Items->Add("No solutions. ");
			MessageBox::Show("No solutions. The grid's window remains");
		}
		else {
			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();
			dataGridView1->RowCount = boardSize;
			dataGridView1->ColumnCount = boardSize;

			for (int i = 0; i < boardSize; i++) {
				for (int j = 0; j < boardSize; j++) {
					if (boardGrid[i][j] == -1)
						dataGridView1->Rows[i]->Cells[j]->Value = "X";
					else
						dataGridView1->Rows[i]->Cells[j]->Value = boardGrid[i][j];
				}
			}

			listBox1->Items->Add("Total attempted moves: " + attempted_move);
			listBox1->Items->Add("=========================");
		}
	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView2->Rows->Clear();
	dataGridView2->Columns->Clear();
	dataGridView2->RowCount = boardSize;
	dataGridView2->ColumnCount = boardSize;

	int minVal = boardGrid[0][0];
	int maxVal = boardGrid[0][0];
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			int val = boardGrid[i][j];
			if (val < minVal) minVal = val;
			if (val > maxVal) maxVal = val;
		}
	}

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			int val = boardGrid[i][j];
			dataGridView2->Rows[i]->Cells[j]->Value = val;

			// 正規化為 0~255 強度
			double normalized = (double)(val - minVal) / (maxVal - minVal);
			int intensity = 255 - static_cast<int>(normalized * 255); // 數值越大顏色越深

			// 使用漸層藍色背景
			dataGridView2->Rows[i]->Cells[j]->Style->BackColor = Color::FromArgb(intensity, intensity, 255);
		}
	}

	
	
}
};
}
