#pragma once
#include<vector>
#include<map>
using namespace std;

vector<vector<vector<int>>> currentSolutions;
int currentSolutionIndex;
int totalSolutions;

bool validate(const vector<vector<int>>& board, int n) {
	vector<int> rowCount(n, 0), colCount(n, 0);
	map<int, int> mainDiag, antiDiag;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (board[row][col] == 1) {
				rowCount[row]++;
				colCount[col]++;
				mainDiag[row - col]++;
				antiDiag[row + col]++;

				if (rowCount[row] > 1 || colCount[col] > 1 || mainDiag[row - col] > 1 || antiDiag[row + col] > 1) return false;
			}
		}
	}
	return true;
}

void solveAll(vector<vector<int>>& board, int col, int n, vector<vector<vector<int>>>& solutions) {
	if (col >= n) {
		solutions.push_back(board);
		return;
	}

	for (int row = 0; row < n; row++) {
		if (board[row][col] == 0) { 
			board[row][col] = 1;
			if (validate(board, n)) {
				solveAll(board, col + 1, n, solutions); 
			}
			board[row][col] = 0; 
		}
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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::CheckBox^ checkBox1;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->checkBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer1->Size = System::Drawing::Size(1605, 829);
			this->splitContainer1->SplitterDistance = 381;
			this->splitContainer1->SplitterWidth = 5;
			this->splitContainer1->TabIndex = 0;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(92, 202);
			this->checkBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(254, 33);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"clear history results\?";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(302, 47);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"1<n<30";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 97);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(386, 84);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Solve the N-Queen";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 38);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(141, 38);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 42);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"n=";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1101, 829);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView1);
			this->tabPage3->Location = System::Drawing::Point(4, 38);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1093, 787);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Queens in grid";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 38;
			this->dataGridView1->Size = System::Drawing::Size(1093, 787);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->listBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 38);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Size = System::Drawing::Size(1093, 787);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Queens in chess";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// listBox2
			// 
			this->listBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 29;
			this->listBox2->Location = System::Drawing::Point(4, 4);
			this->listBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(1085, 779);
			this->listBox2->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->AutoScroll = true;
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 38);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Size = System::Drawing::Size(1093, 787);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Queen\'s position";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 29;
			this->listBox1->Location = System::Drawing::Point(4, 4);
			this->listBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(1085, 779);
			this->listBox1->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(17, 30);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1605, 829);
			this->Controls->Add(this->splitContainer1);
			this->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"n-queen_111701026";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		void ShowCurrentSolution() {
			if (currentSolutionIndex >= totalSolutions) {
				MessageBox::Show("已顯示所有解");
				return;
			}

			auto& solution = currentSolutions[currentSolutionIndex];
			int n = solution.size();

			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();
			dataGridView1->RowCount = n;
			dataGridView1->ColumnCount = n;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (solution[i][j] == 1) dataGridView1->Rows[i]->Cells[j]->Value = "Q";
				}
			}

			String^ message = "Solution #" + (currentSolutionIndex + 1) + " of " + totalSolutions;
			Windows::Forms::DialogResult result = MessageBox::Show(message, "N-Queens Solution",
				MessageBoxButtons::OKCancel, MessageBoxIcon::Information);

			if (result == Windows::Forms::DialogResult::OK) {
				currentSolutionIndex++;
				if (currentSolutionIndex < totalSolutions) ShowCurrentSolution();
				else MessageBox::Show("All solutions have been displayed.");
			}
		}
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			int n = int::Parse(textBox1->Text);
			vector<vector<int>> board(n, vector<int>(n, 0));
			vector<vector<vector<int>>> solutions;
			solveAll(board, 0, n, solutions);

			if (checkBox1->Checked) {
				listBox1->Items->Clear();
				listBox2->Items->Clear();
			};

			if (solutions.empty()) {
				listBox1->Items->Add("無解");
				listBox2->Items->Add("無解");
				return;
			}

			listBox1->Items->Add("Total solutions: " + solutions.size());
			listBox2->Items->Add("Total solutions: " + solutions.size());

			// chess
			int solutionNumber = 1;
			for (const auto& sol : solutions) {
				String^ solutionLabel = "Solution #" + solutionNumber.ToString();
				listBox1->Items->Add(solutionLabel);
				for (int i = 0; i < n; i++) {
					String^ Str = "";
					for (int j = 0; j < n; j++) {
						Str += sol[i][j] ? "Q " : ". ";
					}
					listBox1->Items->Add(Str);
				}
				listBox1->Items->Add("");
				solutionNumber++;
			}

			// position
			solutionNumber = 1;
			for (const auto& sol : solutions) {
				String^ Str = "";
				for (int col = 0; col < n; col++) {
					for (int row = 0; row < n; row++) {
						if (sol[row][col] == 1) {
							Str += (row + 1).ToString() + " ";
							break;
						}
					}
				}
				listBox2->Items->Add(Str + " [" + solutionNumber + "]");
				solutionNumber++;
			}

			currentSolutions = solutions;
			currentSolutionIndex = 0;
			totalSolutions = solutions.size();

			ShowCurrentSolution();
		}
};
}
