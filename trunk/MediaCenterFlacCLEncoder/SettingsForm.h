#pragma once

namespace MediaCenterFlacCLEncoder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox1;
	protected: 
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::NumericUpDown^  GroupSizeNum;
	private: System::Windows::Forms::NumericUpDown^  TaskSizeNum;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::TextBox^  OpenCLDefinesTxt;
	private: System::Windows::Forms::TextBox^  OpenCLPlatformTxt;
	private: System::Windows::Forms::NumericUpDown^  CpuThreadsNum;
	private: System::Windows::Forms::TrackBar^  CompressionLevelSlider;
	private: System::Windows::Forms::ComboBox^  StereoDecorrelationCmb;
	private: System::Windows::Forms::ComboBox^  WindowFunctionCmb;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown8;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown7;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  BlockSizeNum;
	private: System::Windows::Forms::NumericUpDown^  PaddingBytesNum;
	private: System::Windows::Forms::TabControl^  MainTabControl;
	private: System::Windows::Forms::TabPage^  BasicSettings;
	private: System::Windows::Forms::TabPage^  AdvancedSettings;
	private: System::Windows::Forms::Button^  OkBtn;
	private: System::Windows::Forms::Button^  CancelBtn;

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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->GroupSizeNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->TaskSizeNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->OpenCLDefinesTxt = (gcnew System::Windows::Forms::TextBox());
			this->OpenCLPlatformTxt = (gcnew System::Windows::Forms::TextBox());
			this->CpuThreadsNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->CompressionLevelSlider = (gcnew System::Windows::Forms::TrackBar());
			this->StereoDecorrelationCmb = (gcnew System::Windows::Forms::ComboBox());
			this->WindowFunctionCmb = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown8 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown7 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->BlockSizeNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->PaddingBytesNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->MainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->BasicSettings = (gcnew System::Windows::Forms::TabPage());
			this->AdvancedSettings = (gcnew System::Windows::Forms::TabPage());
			this->OkBtn = (gcnew System::Windows::Forms::Button());
			this->CancelBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GroupSizeNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TaskSizeNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CpuThreadsNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CompressionLevelSlider))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlockSizeNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PaddingBytesNum))->BeginInit();
			this->MainTabControl->SuspendLayout();
			this->BasicSettings->SuspendLayout();
			this->AdvancedSettings->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(6, 15);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(100, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Verify Encoding";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(6, 38);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(122, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"Compute MD5 Hash";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(6, 61);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(304, 17);
			this->checkBox3->TabIndex = 2;
			this->checkBox3->Text = L"Offload some GPU tasks to the CPU (useful for slow GPUs)";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(6, 84);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(474, 17);
			this->checkBox4->TabIndex = 3;
			this->checkBox4->Text = L"Do Rice Encoding (compression improvement, computationally expensive: useful for " 
				L"fast GPUs)";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(6, 6);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(127, 17);
			this->checkBox5->TabIndex = 4;
			this->checkBox5->Text = L"Use Mapped Memory";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// GroupSizeNum
			// 
			this->GroupSizeNum->Location = System::Drawing::Point(6, 29);
			this->GroupSizeNum->Name = L"GroupSizeNum";
			this->GroupSizeNum->Size = System::Drawing::Size(120, 20);
			this->GroupSizeNum->TabIndex = 5;
			// 
			// TaskSizeNum
			// 
			this->TaskSizeNum->Location = System::Drawing::Point(6, 55);
			this->TaskSizeNum->Name = L"TaskSizeNum";
			this->TaskSizeNum->Size = System::Drawing::Size(120, 20);
			this->TaskSizeNum->TabIndex = 6;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(6, 81);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(119, 17);
			this->checkBox6->TabIndex = 7;
			this->checkBox6->Text = L"Use CPU Emulation";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// OpenCLDefinesTxt
			// 
			this->OpenCLDefinesTxt->Location = System::Drawing::Point(6, 104);
			this->OpenCLDefinesTxt->Name = L"OpenCLDefinesTxt";
			this->OpenCLDefinesTxt->Size = System::Drawing::Size(100, 20);
			this->OpenCLDefinesTxt->TabIndex = 8;
			// 
			// OpenCLPlatformTxt
			// 
			this->OpenCLPlatformTxt->Location = System::Drawing::Point(6, 130);
			this->OpenCLPlatformTxt->Name = L"OpenCLPlatformTxt";
			this->OpenCLPlatformTxt->Size = System::Drawing::Size(100, 20);
			this->OpenCLPlatformTxt->TabIndex = 9;
			// 
			// CpuThreadsNum
			// 
			this->CpuThreadsNum->Location = System::Drawing::Point(6, 156);
			this->CpuThreadsNum->Name = L"CpuThreadsNum";
			this->CpuThreadsNum->Size = System::Drawing::Size(120, 20);
			this->CpuThreadsNum->TabIndex = 10;
			// 
			// CompressionLevelSlider
			// 
			this->CompressionLevelSlider->BackColor = System::Drawing::SystemColors::Window;
			this->CompressionLevelSlider->Location = System::Drawing::Point(6, 107);
			this->CompressionLevelSlider->Maximum = 11;
			this->CompressionLevelSlider->Minimum = 1;
			this->CompressionLevelSlider->Name = L"CompressionLevelSlider";
			this->CompressionLevelSlider->Size = System::Drawing::Size(104, 45);
			this->CompressionLevelSlider->TabIndex = 11;
			this->CompressionLevelSlider->Value = 1;
			// 
			// StereoDecorrelationCmb
			// 
			this->StereoDecorrelationCmb->FormattingEnabled = true;
			this->StereoDecorrelationCmb->Location = System::Drawing::Point(6, 182);
			this->StereoDecorrelationCmb->Name = L"StereoDecorrelationCmb";
			this->StereoDecorrelationCmb->Size = System::Drawing::Size(121, 21);
			this->StereoDecorrelationCmb->TabIndex = 12;
			// 
			// WindowFunctionCmb
			// 
			this->WindowFunctionCmb->FormattingEnabled = true;
			this->WindowFunctionCmb->Location = System::Drawing::Point(5, 209);
			this->WindowFunctionCmb->Name = L"WindowFunctionCmb";
			this->WindowFunctionCmb->Size = System::Drawing::Size(121, 21);
			this->WindowFunctionCmb->TabIndex = 13;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->label1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label6, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown8, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown7, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown6, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown5, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown4, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown3, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown2, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown1, 1, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(172, 55);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 22)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(378, 129);
			this->tableLayoutPanel1->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Location = System::Drawing::Point(95, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Minimum";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Location = System::Drawing::Point(238, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Maximum";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Partition Order:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Prediction Order:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 74);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(64, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Fixed Order:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 100);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"label6";
			// 
			// numericUpDown8
			// 
			this->numericUpDown8->Location = System::Drawing::Point(238, 103);
			this->numericUpDown8->Name = L"numericUpDown8";
			this->numericUpDown8->Size = System::Drawing::Size(120, 20);
			this->numericUpDown8->TabIndex = 13;
			// 
			// numericUpDown7
			// 
			this->numericUpDown7->Location = System::Drawing::Point(95, 103);
			this->numericUpDown7->Name = L"numericUpDown7";
			this->numericUpDown7->Size = System::Drawing::Size(120, 20);
			this->numericUpDown7->TabIndex = 12;
			// 
			// numericUpDown6
			// 
			this->numericUpDown6->Location = System::Drawing::Point(238, 77);
			this->numericUpDown6->Name = L"numericUpDown6";
			this->numericUpDown6->Size = System::Drawing::Size(120, 20);
			this->numericUpDown6->TabIndex = 11;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(95, 77);
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(120, 20);
			this->numericUpDown5->TabIndex = 10;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(238, 51);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {32, 0, 0, 0});
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(120, 20);
			this->numericUpDown4->TabIndex = 9;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(95, 51);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {32, 0, 0, 0});
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 20);
			this->numericUpDown3->TabIndex = 8;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(238, 25);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 7;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(95, 25);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 6;
			// 
			// BlockSizeNum
			// 
			this->BlockSizeNum->Location = System::Drawing::Point(5, 236);
			this->BlockSizeNum->Name = L"BlockSizeNum";
			this->BlockSizeNum->Size = System::Drawing::Size(120, 20);
			this->BlockSizeNum->TabIndex = 14;
			// 
			// PaddingBytesNum
			// 
			this->PaddingBytesNum->Location = System::Drawing::Point(8, 158);
			this->PaddingBytesNum->Name = L"PaddingBytesNum";
			this->PaddingBytesNum->Size = System::Drawing::Size(120, 20);
			this->PaddingBytesNum->TabIndex = 15;
			// 
			// MainTabControl
			// 
			this->MainTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MainTabControl->Controls->Add(this->BasicSettings);
			this->MainTabControl->Controls->Add(this->AdvancedSettings);
			this->MainTabControl->Location = System::Drawing::Point(12, 12);
			this->MainTabControl->Name = L"MainTabControl";
			this->MainTabControl->SelectedIndex = 0;
			this->MainTabControl->Size = System::Drawing::Size(612, 349);
			this->MainTabControl->TabIndex = 1;
			// 
			// BasicSettings
			// 
			this->BasicSettings->Controls->Add(this->checkBox1);
			this->BasicSettings->Controls->Add(this->PaddingBytesNum);
			this->BasicSettings->Controls->Add(this->checkBox2);
			this->BasicSettings->Controls->Add(this->checkBox3);
			this->BasicSettings->Controls->Add(this->checkBox4);
			this->BasicSettings->Controls->Add(this->CompressionLevelSlider);
			this->BasicSettings->Location = System::Drawing::Point(4, 22);
			this->BasicSettings->Name = L"BasicSettings";
			this->BasicSettings->Padding = System::Windows::Forms::Padding(3);
			this->BasicSettings->Size = System::Drawing::Size(604, 323);
			this->BasicSettings->TabIndex = 0;
			this->BasicSettings->Text = L"Basic Settings";
			this->BasicSettings->UseVisualStyleBackColor = true;
			// 
			// AdvancedSettings
			// 
			this->AdvancedSettings->Controls->Add(this->checkBox5);
			this->AdvancedSettings->Controls->Add(this->GroupSizeNum);
			this->AdvancedSettings->Controls->Add(this->tableLayoutPanel1);
			this->AdvancedSettings->Controls->Add(this->TaskSizeNum);
			this->AdvancedSettings->Controls->Add(this->WindowFunctionCmb);
			this->AdvancedSettings->Controls->Add(this->checkBox6);
			this->AdvancedSettings->Controls->Add(this->StereoDecorrelationCmb);
			this->AdvancedSettings->Controls->Add(this->BlockSizeNum);
			this->AdvancedSettings->Controls->Add(this->OpenCLDefinesTxt);
			this->AdvancedSettings->Controls->Add(this->OpenCLPlatformTxt);
			this->AdvancedSettings->Controls->Add(this->CpuThreadsNum);
			this->AdvancedSettings->Location = System::Drawing::Point(4, 22);
			this->AdvancedSettings->Name = L"AdvancedSettings";
			this->AdvancedSettings->Padding = System::Windows::Forms::Padding(3);
			this->AdvancedSettings->Size = System::Drawing::Size(604, 323);
			this->AdvancedSettings->TabIndex = 1;
			this->AdvancedSettings->Text = L"Advanced Settings";
			this->AdvancedSettings->UseVisualStyleBackColor = true;
			// 
			// OkBtn
			// 
			this->OkBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->OkBtn->Location = System::Drawing::Point(464, 367);
			this->OkBtn->Name = L"OkBtn";
			this->OkBtn->Size = System::Drawing::Size(75, 23);
			this->OkBtn->TabIndex = 2;
			this->OkBtn->Text = L"OK";
			this->OkBtn->UseVisualStyleBackColor = true;
			this->OkBtn->Click += gcnew System::EventHandler(this, &SettingsForm::OkBtn_Click);
			// 
			// CancelBtn
			// 
			this->CancelBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CancelBtn->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelBtn->Location = System::Drawing::Point(545, 367);
			this->CancelBtn->Name = L"CancelBtn";
			this->CancelBtn->Size = System::Drawing::Size(75, 23);
			this->CancelBtn->TabIndex = 3;
			this->CancelBtn->Text = L"Cancel";
			this->CancelBtn->UseVisualStyleBackColor = true;
			// 
			// SettingsForm
			// 
			this->AcceptButton = this->OkBtn;
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->CancelButton = this->CancelBtn;
			this->ClientSize = System::Drawing::Size(636, 402);
			this->Controls->Add(this->OkBtn);
			this->Controls->Add(this->CancelBtn);
			this->Controls->Add(this->MainTabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SettingsForm";
			this->Text = L"FlacCL Encoder Settings";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GroupSizeNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TaskSizeNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CpuThreadsNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CompressionLevelSlider))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlockSizeNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PaddingBytesNum))->EndInit();
			this->MainTabControl->ResumeLayout(false);
			this->BasicSettings->ResumeLayout(false);
			this->BasicSettings->PerformLayout();
			this->AdvancedSettings->ResumeLayout(false);
			this->AdvancedSettings->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OkBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
