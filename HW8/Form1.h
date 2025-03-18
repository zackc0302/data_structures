#include <vector>
#include <ctime>
#include <algorithm>
#include <stack>
using namespace std;

void selection_Sort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] < v[minIndex]) {
				minIndex = j;
			}
		}
		swap(v[i], v[minIndex]);
	}
}

void Bubble_Sort(vector<int>& v) {
	int i, j;
	for (i = v.size() - 1; i > 0; i--)
		for (j = 1; j <= i; j++)
			if (v[j - 1] > v[j])
				swap(v[j - 1], v[j]);
}

void insertion_Sort(vector<int>& v) {
	for (int i = 1; i < v.size(); ++i) {
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > key) {
			v[j + 1] = v[j];
			j --;
		}
		v[j + 1] = key;
	}
}

void quick_Sort_recur(vector<int>& v, int left, int right) {
	if (left >= right) return;

	int pivot = v[left]; // 取最左邊為 pivot
	int i = left + 1, j = right;

	while (i <= j) {
		while (i <= right && v[i] <= pivot) i++;
		while (j > left && v[j] >= pivot) j--;

		if (i < j) swap(v[i], v[j]);
	}
	swap(v[left], v[j]);

	quick_Sort_recur(v, left, j - 1);
	quick_Sort_recur(v, j + 1, right);
}

void quick_Sort_recur(vector<int>& v) {
	quick_Sort_recur(v, 0, v.size() - 1);
}

// 非遞迴版 Quick Sort
void quick_Sort_nonrecur(vector<int>& v) {
	if (v.empty()) return;

	stack<pair<int, int>> st; // 模擬遞迴的堆疊
	st.push(make_pair(0, v.size() - 1));

	while (!st.empty()) {
		pair<int, int> range = st.top();
		st.pop();

		int left = range.first;
		int right = range.second;

		if (left >= right) continue;

		int pivot = v[left]; // 取最左邊為 pivot
		int i = left + 1, j = right;

		while (i <= j) {
			while (i <= right && v[i] <= pivot) i++;
			while (j > left && v[j] >= pivot) j--;

			if (i < j) swap(v[i], v[j]);
		}
		swap(v[left], v[j]);

		st.push(make_pair(left, j - 1));
		st.push(make_pair(j + 1, right));
	}
}


void merge(vector<int>& v, vector<int>& temp, int left, int mid, int right) {
	int i = left;      // 左半部的起始索引
	int j = mid + 1;   // 右半部的起始索引
	int k = left;      // 暫存陣列的起始索引

	// 將兩部分依序比較並合併到暫存陣列
	while (i <= mid && j <= right) {
		if (v[i] <= v[j]) {
			temp[k++] = v[i++];
		}
		else {
			temp[k++] = v[j++];
		}
	}

	// 將剩餘的左半部分複製到暫存陣列
	while (i <= mid) {
		temp[k++] = v[i++];
	}

	// 將剩餘的右半部分複製到暫存陣列
	while (j <= right) {
		temp[k++] = v[j++];
	}

	// 將暫存陣列複製回原始陣列
	for (int idx = left; idx <= right; ++idx) {
		v[idx] = temp[idx];
	}
}

void merge_Sort_recur(vector<int>& v, vector<int>& temp, int left, int right) {
	if (left >= right) return;  // 遞迴基底條件

	int mid = left + (right - left) / 2;

	// 遞迴分割左半部分
	merge_Sort_recur(v, temp, left, mid);

	// 遞迴分割右半部分
	merge_Sort_recur(v, temp, mid + 1, right);

	// 合併左右兩部分
	merge(v, temp, left, mid, right);
}

void merge_Sort_nonrecur(vector<int>& v) {
	int n = v.size();
	vector<int> temp(n);  // 暫存陣列

	// 子陣列大小從 1 開始逐步加倍
	for (int size = 1; size < n; size *= 2) {
		for (int left = 0; left < n - size; left += 2 * size) {
			int mid = left + size - 1;
			int right = min(left + 2 * size - 1, n - 1);  // 確保不越界
			merge(v, temp, left, mid, right);  // 合併區間
		}
	}
}

void radix_Sort(vector<int>& v) {
	if (v.empty()) return; // 若向量為空則直接返回

	// 找出最大值以決定需要的位數
	int maxVal = *max_element(v.begin(), v.end());
	int exp = 1; // 從個位數開始排序

	// 基數排序主迴圈
	while (maxVal / exp > 0) {
		// 使用計數排序 (Count Sort) 基於當前位數
		vector<int> output(v.size());
		vector<int> count(10, 0); // 基數為 10 (0~9)

		// 計算每個數字出現次數
		for (int num : v) {
			int digit = (num / exp) % 10; // 提取當前位數
			count[digit]++;
		}

		// 累加計數，調整索引位置
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		// 根據當前位數將數字放入輸出陣列，並保持穩定排序
		for (int i = v.size() - 1; i >= 0; i--) {
			int digit = (v[i] / exp) % 10;
			output[--count[digit]] = v[i];
		}

		// 將排序後的結果存回原向量
		v = output;

		// 處理下一位數
		exp *= 10;
	}
}

void heapify(vector<int>& v, int n, int i) {
	int largest = i;          // 初始化最大值為根節點
	int left = 2 * i + 1;     // 左子節點索引
	int right = 2 * i + 2;    // 右子節點索引

	// 如果左子節點大於根節點
	if (left < n && v[left] > v[largest]) {
		largest = left;
	}

	// 如果右子節點大於目前最大值
	if (right < n && v[right] > v[largest]) {
		largest = right;
	}

	// 如果最大值不是根節點
	if (largest != i) {
		swap(v[i], v[largest]);  // 交換根節點與最大值
		heapify(v, n, largest); // 遞迴調整受影響的子樹
	}
}

void heap_Sort(vector<int>& v) {
	int n = v.size();

	// 建立最大堆
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	// 一個一個取出元素，並調整堆
	for (int i = n - 1; i >= 0; i--) {
		swap(v[0], v[i]);      // 將堆頂(最大值)移到序列末尾
		heapify(v, i, 0);      // 調整剩餘的堆
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
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage6;
	private: System::Windows::Forms::TabPage^ tabPage7;
	private: System::Windows::Forms::TabPage^ tabPage8;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::ListBox^ listBox5;
	private: System::Windows::Forms::ListBox^ listBox6;
	private: System::Windows::Forms::ListBox^ listBox7;
	private: System::Windows::Forms::ListBox^ listBox8;
	private: System::Windows::Forms::TabPage^ tabPage9;
	private: System::Windows::Forms::ListBox^ listBox9;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart4;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart5;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart6;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart7;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart8;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart9;



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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea10 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea11 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea12 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea13 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend13 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series13 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea14 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend14 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series14 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea15 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend15 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series15 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea16 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend16 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series16 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea17 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend17 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series17 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea18 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend18 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series18 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage9 = (gcnew System::Windows::Forms::TabPage());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox9 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->chart4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->chart5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->chart6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->chart7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->chart8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox7 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->chart9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox8 = (gcnew System::Windows::Forms::ListBox());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->tabPage9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart5))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart6))->BeginInit();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart7))->BeginInit();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart8))->BeginInit();
			this->tabPage8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart9))->BeginInit();
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
			this->tabControl1->Controls->Add(this->tabPage9);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Controls->Add(this->tabPage8);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1118, 763);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->AllowDrop = true;
			this->tabPage1->AutoScroll = true;
			this->tabPage1->Controls->Add(this->chart1);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(8, 39);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1102, 716);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Selection_Sort";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// chart1
			// 
			chartArea10->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea10);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend10->Name = L"Legend1";
			this->chart1->Legends->Add(legend10);
			this->chart1->Location = System::Drawing::Point(3, 700);
			this->chart1->Name = L"chart1";
			series10->ChartArea = L"ChartArea1";
			series10->Legend = L"Legend1";
			series10->Name = L"Series1";
			this->chart1->Series->Add(series10);
			this->chart1->Size = System::Drawing::Size(1062, 516);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// listBox1
			// 
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 24;
			this->listBox1->Location = System::Drawing::Point(3, 3);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(1062, 700);
			this->listBox1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->chart2);
			this->tabPage2->Controls->Add(this->listBox2);
			this->tabPage2->Location = System::Drawing::Point(8, 39);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1102, 722);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Insertion sort";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// chart2
			// 
			chartArea11->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea11);
			this->chart2->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend11->Name = L"Legend1";
			this->chart2->Legends->Add(legend11);
			this->chart2->Location = System::Drawing::Point(3, 290);
			this->chart2->Name = L"chart2";
			series11->ChartArea = L"ChartArea1";
			series11->Legend = L"Legend1";
			series11->Name = L"Series1";
			this->chart2->Series->Add(series11);
			this->chart2->Size = System::Drawing::Size(1096, 429);
			this->chart2->TabIndex = 3;
			this->chart2->Text = L"chart2";
			// 
			// listBox2
			// 
			this->listBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 24;
			this->listBox2->Location = System::Drawing::Point(3, 3);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(1096, 700);
			this->listBox2->TabIndex = 1;
			// 
			// tabPage9
			// 
			this->tabPage9->Controls->Add(this->chart3);
			this->tabPage9->Controls->Add(this->listBox9);
			this->tabPage9->Location = System::Drawing::Point(8, 39);
			this->tabPage9->Name = L"tabPage9";
			this->tabPage9->Size = System::Drawing::Size(1102, 716);
			this->tabPage9->TabIndex = 8;
			this->tabPage9->Text = L"Bubble Sort";
			this->tabPage9->UseVisualStyleBackColor = true;
			// 
			// chart3
			// 
			chartArea12->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea12);
			this->chart3->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend12->Name = L"Legend1";
			this->chart3->Legends->Add(legend12);
			this->chart3->Location = System::Drawing::Point(0, 287);
			this->chart3->Name = L"chart3";
			series12->ChartArea = L"ChartArea1";
			series12->Legend = L"Legend1";
			series12->Name = L"Series1";
			this->chart3->Series->Add(series12);
			this->chart3->Size = System::Drawing::Size(1102, 429);
			this->chart3->TabIndex = 4;
			this->chart3->Text = L"chart3";
			// 
			// listBox9
			// 
			this->listBox9->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBox9->FormattingEnabled = true;
			this->listBox9->ItemHeight = 24;
			this->listBox9->Location = System::Drawing::Point(0, 0);
			this->listBox9->Name = L"listBox9";
			this->listBox9->Size = System::Drawing::Size(1102, 700);
			this->listBox9->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->chart4);
			this->tabPage3->Controls->Add(this->listBox3);
			this->tabPage3->Location = System::Drawing::Point(8, 39);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1102, 716);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Quick sort (recursive versions)";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// chart4
			// 
			chartArea13->Name = L"ChartArea1";
			this->chart4->ChartAreas->Add(chartArea13);
			this->chart4->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend13->Name = L"Legend1";
			this->chart4->Legends->Add(legend13);
			this->chart4->Location = System::Drawing::Point(0, 287);
			this->chart4->Name = L"chart4";
			series13->ChartArea = L"ChartArea1";
			series13->Legend = L"Legend1";
			series13->Name = L"Series1";
			this->chart4->Series->Add(series13);
			this->chart4->Size = System::Drawing::Size(1102, 429);
			this->chart4->TabIndex = 4;
			this->chart4->Text = L"chart4";
			// 
			// listBox3
			// 
			this->listBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 24;
			this->listBox3->Location = System::Drawing::Point(0, 0);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(1102, 700);
			this->listBox3->TabIndex = 1;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->chart5);
			this->tabPage4->Controls->Add(this->listBox4);
			this->tabPage4->Location = System::Drawing::Point(8, 39);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(1102, 716);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Quick sort (non-recursive versions)";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// chart5
			// 
			chartArea14->Name = L"ChartArea1";
			this->chart5->ChartAreas->Add(chartArea14);
			this->chart5->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend14->Name = L"Legend1";
			this->chart5->Legends->Add(legend14);
			this->chart5->Location = System::Drawing::Point(0, 287);
			this->chart5->Name = L"chart5";
			series14->ChartArea = L"ChartArea1";
			series14->Legend = L"Legend1";
			series14->Name = L"Series1";
			this->chart5->Series->Add(series14);
			this->chart5->Size = System::Drawing::Size(1102, 429);
			this->chart5->TabIndex = 4;
			this->chart5->Text = L"chart5";
			// 
			// listBox4
			// 
			this->listBox4->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 24;
			this->listBox4->Location = System::Drawing::Point(0, 0);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(1102, 700);
			this->listBox4->TabIndex = 1;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->chart6);
			this->tabPage5->Controls->Add(this->listBox5);
			this->tabPage5->Location = System::Drawing::Point(8, 39);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(1102, 722);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Merge sort (recursive versions)";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// chart6
			// 
			chartArea15->Name = L"ChartArea1";
			this->chart6->ChartAreas->Add(chartArea15);
			this->chart6->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend15->Name = L"Legend1";
			this->chart6->Legends->Add(legend15);
			this->chart6->Location = System::Drawing::Point(0, 293);
			this->chart6->Name = L"chart6";
			series15->ChartArea = L"ChartArea1";
			series15->Legend = L"Legend1";
			series15->Name = L"Series1";
			this->chart6->Series->Add(series15);
			this->chart6->Size = System::Drawing::Size(1102, 429);
			this->chart6->TabIndex = 4;
			this->chart6->Text = L"chart6";
			// 
			// listBox5
			// 
			this->listBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox5->FormattingEnabled = true;
			this->listBox5->ItemHeight = 24;
			this->listBox5->Location = System::Drawing::Point(0, 0);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(1102, 722);
			this->listBox5->TabIndex = 1;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->chart7);
			this->tabPage6->Controls->Add(this->listBox6);
			this->tabPage6->Location = System::Drawing::Point(8, 39);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(1102, 722);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Merge sort (non-recursive versions)";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// chart7
			// 
			chartArea16->Name = L"ChartArea1";
			this->chart7->ChartAreas->Add(chartArea16);
			this->chart7->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend16->Name = L"Legend1";
			this->chart7->Legends->Add(legend16);
			this->chart7->Location = System::Drawing::Point(0, 293);
			this->chart7->Name = L"chart7";
			series16->ChartArea = L"ChartArea1";
			series16->Legend = L"Legend1";
			series16->Name = L"Series1";
			this->chart7->Series->Add(series16);
			this->chart7->Size = System::Drawing::Size(1102, 429);
			this->chart7->TabIndex = 4;
			this->chart7->Text = L"chart7";
			// 
			// listBox6
			// 
			this->listBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox6->FormattingEnabled = true;
			this->listBox6->ItemHeight = 24;
			this->listBox6->Location = System::Drawing::Point(0, 0);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(1102, 722);
			this->listBox6->TabIndex = 1;
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->chart8);
			this->tabPage7->Controls->Add(this->listBox7);
			this->tabPage7->Location = System::Drawing::Point(8, 39);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Size = System::Drawing::Size(1102, 722);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"Heap sort";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// chart8
			// 
			chartArea17->Name = L"ChartArea1";
			this->chart8->ChartAreas->Add(chartArea17);
			this->chart8->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend17->Name = L"Legend1";
			this->chart8->Legends->Add(legend17);
			this->chart8->Location = System::Drawing::Point(0, 293);
			this->chart8->Name = L"chart8";
			series17->ChartArea = L"ChartArea1";
			series17->Legend = L"Legend1";
			series17->Name = L"Series1";
			this->chart8->Series->Add(series17);
			this->chart8->Size = System::Drawing::Size(1102, 429);
			this->chart8->TabIndex = 4;
			this->chart8->Text = L"chart8";
			// 
			// listBox7
			// 
			this->listBox7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox7->FormattingEnabled = true;
			this->listBox7->ItemHeight = 24;
			this->listBox7->Location = System::Drawing::Point(0, 0);
			this->listBox7->Name = L"listBox7";
			this->listBox7->Size = System::Drawing::Size(1102, 722);
			this->listBox7->TabIndex = 1;
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->chart9);
			this->tabPage8->Controls->Add(this->listBox8);
			this->tabPage8->Location = System::Drawing::Point(8, 39);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Size = System::Drawing::Size(1102, 722);
			this->tabPage8->TabIndex = 7;
			this->tabPage8->Text = L"Radix sort";
			this->tabPage8->UseVisualStyleBackColor = true;
			// 
			// chart9
			// 
			chartArea18->Name = L"ChartArea1";
			this->chart9->ChartAreas->Add(chartArea18);
			this->chart9->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend18->Name = L"Legend1";
			this->chart9->Legends->Add(legend18);
			this->chart9->Location = System::Drawing::Point(0, 293);
			this->chart9->Name = L"chart9";
			series18->ChartArea = L"ChartArea1";
			series18->Legend = L"Legend1";
			series18->Name = L"Series1";
			this->chart9->Series->Add(series18);
			this->chart9->Size = System::Drawing::Size(1102, 429);
			this->chart9->TabIndex = 4;
			this->chart9->Text = L"chart9";
			// 
			// listBox8
			// 
			this->listBox8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox8->FormattingEnabled = true;
			this->listBox8->ItemHeight = 24;
			this->listBox8->Location = System::Drawing::Point(0, 0);
			this->listBox8->Name = L"listBox8";
			this->listBox8->Size = System::Drawing::Size(1102, 722);
			this->listBox8->TabIndex = 1;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->AutoScroll = true;
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			this->splitContainer1->Panel1->Controls->Add(this->textBox4);
			this->splitContainer1->Panel1->Controls->Add(this->label4);
			this->splitContainer1->Panel1->Controls->Add(this->textBox3);
			this->splitContainer1->Panel1->Controls->Add(this->label3);
			this->splitContainer1->Panel1->Controls->Add(this->textBox2);
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer1->Size = System::Drawing::Size(1500, 763);
			this->splitContainer1->SplitterDistance = 378;
			this->splitContainer1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(26, 203);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(237, 75);
			this->button1->TabIndex = 8;
			this->button1->Text = L"calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(199, 141);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(65, 36);
			this->textBox4->TabIndex = 7;
			this->textBox4->Text = L"1000";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(166, 148);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(27, 24);
			this->label4->TabIndex = 6;
			this->label4->Text = L"to";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(84, 141);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(65, 36);
			this->textBox3->TabIndex = 5;
			this->textBox3->Text = L"100";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 24);
			this->label3->TabIndex = 4;
			this->label3->Text = L"from";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(98, 86);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(65, 36);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"7";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"times:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(98, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(65, 36);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"100";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"n:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1500, 763);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"Form1";
			this->Text = L"HW8 Performance Evaluation for Sorting Algorithms";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->tabPage9->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->EndInit();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart5))->EndInit();
			this->tabPage5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart6))->EndInit();
			this->tabPage6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart7))->EndInit();
			this->tabPage7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart8))->EndInit();
			this->tabPage8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart9))->EndInit();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		long times = long::Parse(textBox2->Text); 
		long n = long::Parse(textBox1->Text);
		long n_t = n;
		long up = long::Parse(textBox4->Text);
		long down = long::Parse(textBox3->Text);
		long long loops = n + 2;
		long ln1 = n;long ln2 = n;long ln3 = n;long ln4 = n;
		long ln5 = n; long ln6 = n; long ln7 = n; long ln8 = n; long ln9 = n;
		srand(time(0));  // 設置隨機數種子
		/*Selection Sort*/
		for (int t = 0; t < times; t++) {
			vector<double> durations;  // 存儲多次測試時間
			for (int l = 0; l < loops; l++) {
				vector<int> v;
				v.clear();

				// 生成 n 個隨機數
				for (int i = 0; i < ln1; i++) {
					v.push_back(rand() % (up - down + 1) + down);
				}

				// 計算執行時間
				clock_t start = clock();
				selection_Sort(v);
				clock_t end = clock();

				double duration = (double)(end - start) / CLOCKS_PER_SEC;
				durations.push_back(duration);
				
			}

			// 排序結果並去除最佳與最差各兩次
			sort(durations.begin(), durations.end());
			if (durations.size() > 4) {
				durations.erase(durations.begin());      // 去掉最小
				durations.erase(durations.begin());      // 再去掉最小
				durations.pop_back();                    // 去掉最大
				durations.pop_back();                    // 再去掉最大
			}

			// 計算平均時間
			double sum = 0;
			for (double d : durations) {
				sum += d;
			}
			double avg_time = sum / durations.size();
			
			listBox1->Items->Add("n=" + ln1 + " 平均執行時間: " + System::Convert::ToString(avg_time) + " 秒");
			chart1->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart1->Series[0]->Points->AddXY(ln1, avg_time);  // 橫軸為 n，縱軸為時間
			chart1->ChartAreas[0]->AxisX->Title = "數據大小 (n)";
			chart1->ChartAreas[0]->AxisY->Title = "平均時間 (秒)";
			chart1->Series[0]->Name = "平均時間";
			ln1 += n_t;
		}
		/*Insertion Sort*/
		for (int t = 0; t < times; t++) {
			vector<double> durations;  // 存儲多次測試時間
			for (int l = 0; l < loops; l++) {
				vector<int> v;
				v.clear();

				// 生成 n 個隨機數
				for (int i = 0; i < ln2; i++) {
					v.push_back(rand() % (up - down + 1) + down);
				}

				// 計算執行時間
				clock_t start = clock();
				insertion_Sort(v);
				clock_t end = clock();

				double duration = (double)(end - start) / CLOCKS_PER_SEC;
				durations.push_back(duration);

			}

			// 排序結果並去除最佳與最差各兩次
			sort(durations.begin(), durations.end());
			if (durations.size() > 4) {
				durations.erase(durations.begin());      // 去掉最小
				durations.erase(durations.begin());      // 再去掉最小
				durations.pop_back();                    // 去掉最大
				durations.pop_back();                    // 再去掉最大
			}

			// 計算平均時間
			double sum = 0;
			for (double d : durations) {
				sum += d;
			}
			double avg_time = sum / durations.size();

			listBox2->Items->Add("n=" + ln2 + " 平均執行時間: " + System::Convert::ToString(avg_time) + " 秒");
			chart2->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart2->Series[0]->Points->AddXY(ln2, avg_time);  // 橫軸為 n，縱軸為時間
			chart2->ChartAreas[0]->AxisX->Title = "數據大小 (n)";
			chart2->ChartAreas[0]->AxisY->Title = "平均時間 (秒)";
			chart2->Series[0]->Name = "平均時間";
			ln2 += n_t;
		}
		/*Bubble Sort*/
		for (int t = 0; t < times; t++) {
			vector<double> durations;  // 存儲多次測試時間
			for (int l = 0; l < loops; l++) {
				vector<int> v;
				v.clear();

				// 生成 n 個隨機數
				for (int i = 0; i < ln9; i++) {
					v.push_back(rand() % (up - down + 1) + down);
				}

				// 計算執行時間
				clock_t start = clock();
				Bubble_Sort(v);
				clock_t end = clock();

				double duration = (double)(end - start) / CLOCKS_PER_SEC;
				durations.push_back(duration);

			}

			// 排序結果並去除最佳與最差各兩次
			sort(durations.begin(), durations.end());
			if (durations.size() > 4) {
				durations.erase(durations.begin());      // 去掉最小
				durations.erase(durations.begin());      // 再去掉最小
				durations.pop_back();                    // 去掉最大
				durations.pop_back();                    // 再去掉最大
			}

			// 計算平均時間
			double sum = 0;
			for (double d : durations) {
				sum += d;
			}
			double avg_time = sum / durations.size();

			listBox9->Items->Add("n=" + ln9 + " 平均執行時間: " + System::Convert::ToString(avg_time) + " 秒");
			chart3->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart3->Series[0]->Points->AddXY(ln9, avg_time);  // 橫軸為 n，縱軸為時間
			chart3->ChartAreas[0]->AxisX->Title = "數據大小 (n)";
			chart3->ChartAreas[0]->AxisY->Title = "平均時間 (秒)";
			chart3->Series[0]->Name = "平均時間";
			ln9 += n_t;
		}
		/*Quick Sort recur*/
		for (int t = 0; t < times; t++) {
			vector<double> durations;  // 存儲多次測試時間
			for (int l = 0; l < loops; l++) {
				vector<int> v;
				v.clear();

				// 生成 n 個隨機數
				for (int i = 0; i < ln3; i++) {
					v.push_back(rand() % (up - down + 1) + down);
				}
				int left = 0;
				int right = v.size() - 1;
				// 計算執行時間
				clock_t start = clock();
				quick_Sort_recur(v, left, right);
				clock_t end = clock();

				double duration = (double)(end - start) / CLOCKS_PER_SEC;
				durations.push_back(duration);

			}

			// 排序結果並去除最佳與最差各兩次
			sort(durations.begin(), durations.end());
			if (durations.size() > 4) {
				durations.erase(durations.begin());      // 去掉最小
				durations.erase(durations.begin());      // 再去掉最小
				durations.pop_back();                    // 去掉最大
				durations.pop_back();                    // 再去掉最大
			}

			// 計算平均時間
			double sum = 0;
			for (double d : durations) {
				sum += d;
			}
			double avg_time = sum / durations.size();

			listBox3->Items->Add("n=" + ln3 + " 平均執行時間: " + System::Convert::ToString(avg_time) + " 秒");
			chart4->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart4->Series[0]->Points->AddXY(ln3, avg_time);  // 橫軸為 n，縱軸為時間
			chart4->ChartAreas[0]->AxisX->Title = "數據大小 (n)";
			chart4->ChartAreas[0]->AxisY->Title = "平均時間 (秒)";
			chart4->Series[0]->Name = "平均時間";
			ln3 += n_t;
		}
		/*Quick Sort nonrecur*/
		for (int t = 0; t < times; t++) {
			vector<double> durations;  // 存儲多次測試時間
			for (int l = 0; l < loops; l++) {
				vector<int> v;
				v.clear();

				// 生成 n 個隨機數
				for (int i = 0; i < ln4; i++) {
					v.push_back(rand() % (up - down + 1) + down);
				}
				int left = 0;
				int right = v.size() - 1;
				// 計算執行時間
				clock_t start = clock();
				quick_Sort_nonrecur(v);
				clock_t end = clock();

				double duration = (double)(end - start) / CLOCKS_PER_SEC;
				durations.push_back(duration);

			}

			// 排序結果並去除最佳與最差各兩次
			sort(durations.begin(), durations.end());
			if (durations.size() > 4) {
				durations.erase(durations.begin());      // 去掉最小
				durations.erase(durations.begin());      // 再去掉最小
				durations.pop_back();                    // 去掉最大
				durations.pop_back();                    // 再去掉最大
			}

			// 計算平均時間
			double sum = 0;
			for (double d : durations) {
				sum += d;
			}
			double avg_time = sum / durations.size();

			listBox4->Items->Add("n=" + ln4 + " 平均執行時間: " + System::Convert::ToString(avg_time) + " 秒");
			chart5->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart5->Series[0]->Points->AddXY(ln4, avg_time);  // 橫軸為 n，縱軸為時間
			chart5->ChartAreas[0]->AxisX->Title = "數據大小 (n)";
			chart5->ChartAreas[0]->AxisY->Title = "平均時間 (秒)";
			chart5->Series[0]->Name = "平均時間";
			ln4 += n_t;
		}
		/*merge_Sort_recur*/
		for (int t = 0; t < times; t++) {
			vector<double> durations;  // 存儲多次測試時間
			for (int l = 0; l < loops; l++) {
				vector<int> v;
				v.clear();

				// 生成 n 個隨機數
				for (int i = 0; i < ln5; i++) {
					v.push_back(rand() % (up - down + 1) + down);
				}

				// 計算執行時間
				clock_t start = clock();
				merge_Sort_nonrecur(v);
				clock_t end = clock();

				double duration = (double)(end - start) / CLOCKS_PER_SEC;
				durations.push_back(duration);

			}

			// 排序結果並去除最佳與最差各兩次
			sort(durations.begin(), durations.end());
			if (durations.size() > 4) {
				durations.erase(durations.begin());      // 去掉最小
				durations.erase(durations.begin());      // 再去掉最小
				durations.pop_back();                    // 去掉最大
				durations.pop_back();                    // 再去掉最大
			}

			// 計算平均時間
			double sum = 0;
			for (double d : durations) {
				sum += d;
			}
			double avg_time = sum / durations.size();

			listBox5->Items->Add("n=" + ln5 + " 平均執行時間: " + System::Convert::ToString(avg_time) + " 秒");
			chart6->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart6->Series[0]->Points->AddXY(ln5, avg_time);  // 橫軸為 n，縱軸為時間
			chart6->ChartAreas[0]->AxisX->Title = "數據大小 (n)";
			chart6->ChartAreas[0]->AxisY->Title = "平均時間 (秒)";
			chart6->Series[0]->Name = "平均時間";
			ln5 += n_t;
		}
		/*merge_Sort_nonrecur*/
		for (int t = 0; t < times; t++) {
			vector<double> durations;  // 存儲多次測試時間
			for (int l = 0; l < loops; l++) {
				vector<int> v;
				v.clear();

				// 生成 n 個隨機數
				for (int i = 0; i < ln6; i++) {
					v.push_back(rand() % (up - down + 1) + down);
				}

				// 計算執行時間
				clock_t start = clock();
				merge_Sort_nonrecur(v);
				clock_t end = clock();

				double duration = (double)(end - start) / CLOCKS_PER_SEC;
				durations.push_back(duration);

			}

			// 排序結果並去除最佳與最差各兩次
			sort(durations.begin(), durations.end());
			if (durations.size() > 4) {
				durations.erase(durations.begin());      // 去掉最小
				durations.erase(durations.begin());      // 再去掉最小
				durations.pop_back();                    // 去掉最大
				durations.pop_back();                    // 再去掉最大
			}

			// 計算平均時間
			double sum = 0;
			for (double d : durations) {
				sum += d;
			}
			double avg_time = sum / durations.size();

			listBox6->Items->Add("n=" + ln6 + " 平均執行時間: " + System::Convert::ToString(avg_time) + " 秒");
			chart7->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart7->Series[0]->Points->AddXY(ln6, avg_time);  // 橫軸為 n，縱軸為時間
			chart7->ChartAreas[0]->AxisX->Title = "數據大小 (n)";
			chart7->ChartAreas[0]->AxisY->Title = "平均時間 (秒)";
			chart7->Series[0]->Name = "平均時間";
			ln6 += n_t;
		}
		/*radix sort*/
		for (int t = 0; t < times; t++) {
			vector<double> durations;  // 存儲多次測試時間
			for (int l = 0; l < loops; l++) {
				vector<int> v;
				v.clear();

				// 生成 n 個隨機數
				for (int i = 0; i < ln8; i++) {
					v.push_back(rand() % (up - down + 1) + down);
				}

				// 計算執行時間
				clock_t start = clock();
				radix_Sort(v);
				clock_t end = clock();

				double duration = (double)(end - start) / CLOCKS_PER_SEC;
				durations.push_back(duration);

			}

			// 排序結果並去除最佳與最差各兩次
			sort(durations.begin(), durations.end());
			if (durations.size() > 4) {
				durations.erase(durations.begin());      // 去掉最小
				durations.erase(durations.begin());      // 再去掉最小
				durations.pop_back();                    // 去掉最大
				durations.pop_back();                    // 再去掉最大
			}

			// 計算平均時間
			double sum = 0;
			for (double d : durations) {
				sum += d;
			}
			double avg_time = sum / durations.size();

			listBox8->Items->Add("n=" + ln8 + " 平均執行時間: " + System::Convert::ToString(avg_time) + " 秒");
			chart8->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart8->Series[0]->Points->AddXY(ln8, avg_time);  // 橫軸為 n，縱軸為時間
			chart8->ChartAreas[0]->AxisX->Title = "數據大小 (n)";
			chart8->ChartAreas[0]->AxisY->Title = "平均時間 (秒)";
			chart8->Series[0]->Name = "平均時間";
			ln8 += n_t;
		}
		/*heap sort*/
		for (int t = 0; t < times; t++) {
			vector<double> durations;  // 存儲多次測試時間
			for (int l = 0; l < loops; l++) {
				vector<int> v;
				v.clear();

				// 生成 n 個隨機數
				for (int i = 0; i < ln7; i++) {
					v.push_back(rand() % (up - down + 1) + down);
				}

				// 計算執行時間
				clock_t start = clock();
				heap_Sort(v);
				clock_t end = clock();

				double duration = (double)(end - start) / CLOCKS_PER_SEC;
				durations.push_back(duration);

			}

			// 排序結果並去除最佳與最差各兩次
			sort(durations.begin(), durations.end());
			if (durations.size() > 4) {
				durations.erase(durations.begin());      // 去掉最小
				durations.erase(durations.begin());      // 再去掉最小
				durations.pop_back();                    // 去掉最大
				durations.pop_back();                    // 再去掉最大
			}

			// 計算平均時間
			double sum = 0;
			for (double d : durations) {
				sum += d;
			}
			double avg_time = sum / durations.size();

			listBox7->Items->Add("n=" + ln7 + " 平均執行時間: " + System::Convert::ToString(avg_time) + " 秒");
			chart9->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart9->Series[0]->Points->AddXY(ln7, avg_time);  // 橫軸為 n，縱軸為時間
			chart9->ChartAreas[0]->AxisX->Title = "數據大小 (n)";
			chart9->ChartAreas[0]->AxisY->Title = "平均時間 (秒)";
			chart9->Series[0]->Name = "平均時間";
			ln7 += n_t;
		}
	}
};
}
