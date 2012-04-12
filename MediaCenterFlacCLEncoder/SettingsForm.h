#pragma once
#include "JREncoderInterface.h"

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
			ToolTip->SetToolTip(OffloadGpuToCpuChk, L"Useful for increasing the encoding speed of slow GPUs.");
			ToolTip->SetToolTip(RiceEncodingChk, L"Improves compression, but computationally expensive: useful for fast GPUs.");
		}

		MediaCenterFlacCLEncoderInterface::Config GetConfig()
		{
			MediaCenterFlacCLEncoderInterface::Config result;
			
			result.CompressionLevel = CompressionLevelSlider->Value;
			result.PaddingBytes = (System::Int32)PaddingBytesNum->Value;
			result.VerifyEncoding = VerifyEncodingChk->Checked;
			result.ComputeMd5Hash = ComputeMd5HashChk->Checked;
			result.OffloadTasksToCpu = OffloadGpuToCpuChk->Checked;
			result.DoRiceEncoding = RiceEncodingChk->Checked;

			result.MappedMemory = MappedMemoryChk->Checked;
			result.EstimateWindow = EstimateWindowChk->Checked;
			result.ComputeSeekTable = ComputeSeekTableChk->Checked;
			result.ConstantFramesEncoding = ConstantFramesEncodingChk->Checked;
			result.GpuWorkGroupSize = (System::Int32)GroupSizeNum->Value;
			result.FramesPerMultiprocessor = (System::Int32)TaskSizeNum->Value;
			result.AdditionalCpuThreads = (System::Int32)CpuThreadsNum->Value;
			result.BlockSize = (System::Int32)BlockSizeNum->Value;
			result.TasksPerChannel = (System::Int32)TasksPerChannelNum->Value;
			result.TasksPerWindow = (System::Int32)TasksPerWindowNum->Value;
			result.StereoDecorrelationAlgorithm;
			result.WindowAlgorithm;

			result.PartitionOrder;
			result.PredictionOrder;
			result.FixedOrder;
			result.Precision;

			result.OpenCLDefines;
			result.OpenCLPlatform;
			result.UseCpuEmulation;

			return result;
		}

		void SetConfig(const MediaCenterFlacCLEncoderInterface::Config& config)
		{
			CompressionLevelSlider->Value = config.CompressionLevel;
			PaddingBytesNum->Value = config.PaddingBytes;
			VerifyEncodingChk->Checked = config.VerifyEncoding;
			ComputeMd5HashChk->Checked = config.ComputeMd5Hash;
			OffloadGpuToCpuChk->Checked = config.OffloadTasksToCpu;
			RiceEncodingChk->Checked = config.DoRiceEncoding;

			MappedMemoryChk->Checked = config.MappedMemory;
			EstimateWindowChk->Checked = config.EstimateWindow;
			ComputeSeekTableChk->Checked = config.ComputeSeekTable;
			ConstantFramesEncodingChk->Checked = config.ConstantFramesEncoding;
			GroupSizeNum->Value = config.GpuWorkGroupSize;
			TaskSizeNum->Value= config.FramesPerMultiprocessor;
			CpuThreadsNum->Value = config.AdditionalCpuThreads;
			BlockSizeNum->Value = config.BlockSize;
			TasksPerChannelNum->Value = config.TasksPerChannel;
			TasksPerWindowNum->Value = config.TasksPerWindow;
			config.StereoDecorrelationAlgorithm;
			config.WindowAlgorithm;

			config.PartitionOrder;
			config.PredictionOrder;
			config.FixedOrder;
			config.Precision;

			config.OpenCLDefines;
			config.OpenCLPlatform;
			config.UseCpuEmulation;
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
	private: System::Windows::Forms::CheckBox^  VerifyEncodingChk;
	private: System::Windows::Forms::CheckBox^  ComputeMd5HashChk;
	private: System::Windows::Forms::CheckBox^  OffloadGpuToCpuChk;
	private: System::Windows::Forms::CheckBox^  RiceEncodingChk;
	private: System::Windows::Forms::CheckBox^  MappedMemoryChk;
	protected: 

	protected: 




	private: System::Windows::Forms::NumericUpDown^  GroupSizeNum;
	private: System::Windows::Forms::NumericUpDown^  TaskSizeNum;



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
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  CompressionLevelLbl;
	private: System::Windows::Forms::Label^  PaddingBytesLbl;
	private: System::Windows::Forms::ToolTip^  ToolTip;
	private: System::Windows::Forms::TabPage^  OpenCLSettings;
	private: System::Windows::Forms::Label^  OpenCLDefinesLbl;
	private: System::Windows::Forms::Label^  OpenCLPlatformLbl;
	private: System::Windows::Forms::CheckBox^  CpuEmulationChk;
	private: System::Windows::Forms::TextBox^  OpenCLDefinesTxt;
	private: System::Windows::Forms::TextBox^  OpenCLPlatformTxt;
private: System::Windows::Forms::CheckBox^  ConstantFramesEncodingChk;

private: System::Windows::Forms::CheckBox^  ComputeSeekTableChk;



	private: System::Windows::Forms::CheckBox^  EstimateWindowChk;
	private: System::Windows::Forms::NumericUpDown^  TasksPerChannelNum;
	private: System::Windows::Forms::NumericUpDown^  TasksPerWindowNum;
	private: System::Windows::Forms::Label^  GroupSizeLbl;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->VerifyEncodingChk = (gcnew System::Windows::Forms::CheckBox());
			this->ComputeMd5HashChk = (gcnew System::Windows::Forms::CheckBox());
			this->OffloadGpuToCpuChk = (gcnew System::Windows::Forms::CheckBox());
			this->RiceEncodingChk = (gcnew System::Windows::Forms::CheckBox());
			this->MappedMemoryChk = (gcnew System::Windows::Forms::CheckBox());
			this->GroupSizeNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->TaskSizeNum = (gcnew System::Windows::Forms::NumericUpDown());
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
			this->PaddingBytesLbl = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->CompressionLevelLbl = (gcnew System::Windows::Forms::Label());
			this->AdvancedSettings = (gcnew System::Windows::Forms::TabPage());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->GroupSizeLbl = (gcnew System::Windows::Forms::Label());
			this->ConstantFramesEncodingChk = (gcnew System::Windows::Forms::CheckBox());
			this->ComputeSeekTableChk = (gcnew System::Windows::Forms::CheckBox());
			this->EstimateWindowChk = (gcnew System::Windows::Forms::CheckBox());
			this->TasksPerChannelNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->TasksPerWindowNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->OpenCLSettings = (gcnew System::Windows::Forms::TabPage());
			this->OpenCLDefinesLbl = (gcnew System::Windows::Forms::Label());
			this->OpenCLPlatformLbl = (gcnew System::Windows::Forms::Label());
			this->CpuEmulationChk = (gcnew System::Windows::Forms::CheckBox());
			this->OpenCLDefinesTxt = (gcnew System::Windows::Forms::TextBox());
			this->OpenCLPlatformTxt = (gcnew System::Windows::Forms::TextBox());
			this->OkBtn = (gcnew System::Windows::Forms::Button());
			this->CancelBtn = (gcnew System::Windows::Forms::Button());
			this->ToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TasksPerChannelNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TasksPerWindowNum))->BeginInit();
			this->OpenCLSettings->SuspendLayout();
			this->SuspendLayout();
			// 
			// VerifyEncodingChk
			// 
			this->VerifyEncodingChk->AutoSize = true;
			this->VerifyEncodingChk->Location = System::Drawing::Point(113, 97);
			this->VerifyEncodingChk->Name = L"VerifyEncodingChk";
			this->VerifyEncodingChk->Size = System::Drawing::Size(100, 17);
			this->VerifyEncodingChk->TabIndex = 7;
			this->VerifyEncodingChk->Text = L"Verify Encoding";
			this->VerifyEncodingChk->UseVisualStyleBackColor = true;
			// 
			// ComputeMd5HashChk
			// 
			this->ComputeMd5HashChk->AutoSize = true;
			this->ComputeMd5HashChk->Checked = true;
			this->ComputeMd5HashChk->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ComputeMd5HashChk->Location = System::Drawing::Point(113, 120);
			this->ComputeMd5HashChk->Name = L"ComputeMd5HashChk";
			this->ComputeMd5HashChk->Size = System::Drawing::Size(122, 17);
			this->ComputeMd5HashChk->TabIndex = 8;
			this->ComputeMd5HashChk->Text = L"Compute MD5 Hash";
			this->ComputeMd5HashChk->UseVisualStyleBackColor = true;
			// 
			// OffloadGpuToCpuChk
			// 
			this->OffloadGpuToCpuChk->AutoSize = true;
			this->OffloadGpuToCpuChk->Location = System::Drawing::Point(113, 143);
			this->OffloadGpuToCpuChk->Name = L"OffloadGpuToCpuChk";
			this->OffloadGpuToCpuChk->Size = System::Drawing::Size(197, 17);
			this->OffloadGpuToCpuChk->TabIndex = 9;
			this->OffloadGpuToCpuChk->Text = L"Offload some GPU tasks to the CPU";
			this->OffloadGpuToCpuChk->UseVisualStyleBackColor = true;
			// 
			// RiceEncodingChk
			// 
			this->RiceEncodingChk->AutoSize = true;
			this->RiceEncodingChk->Location = System::Drawing::Point(113, 166);
			this->RiceEncodingChk->Name = L"RiceEncodingChk";
			this->RiceEncodingChk->Size = System::Drawing::Size(181, 17);
			this->RiceEncodingChk->TabIndex = 10;
			this->RiceEncodingChk->Text = L"Do Rice Encoding (experimental)";
			this->RiceEncodingChk->UseVisualStyleBackColor = true;
			// 
			// MappedMemoryChk
			// 
			this->MappedMemoryChk->AutoSize = true;
			this->MappedMemoryChk->Checked = true;
			this->MappedMemoryChk->CheckState = System::Windows::Forms::CheckState::Indeterminate;
			this->MappedMemoryChk->Location = System::Drawing::Point(6, 8);
			this->MappedMemoryChk->Name = L"MappedMemoryChk";
			this->MappedMemoryChk->Size = System::Drawing::Size(127, 17);
			this->MappedMemoryChk->TabIndex = 1;
			this->MappedMemoryChk->Text = L"Use Mapped Memory";
			this->MappedMemoryChk->ThreeState = true;
			this->MappedMemoryChk->UseVisualStyleBackColor = true;
			// 
			// GroupSizeNum
			// 
			this->GroupSizeNum->Location = System::Drawing::Point(220, 100);
			this->GroupSizeNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {256, 0, 0, 0});
			this->GroupSizeNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			this->GroupSizeNum->Name = L"GroupSizeNum";
			this->GroupSizeNum->Size = System::Drawing::Size(120, 20);
			this->GroupSizeNum->TabIndex = 5;
			this->GroupSizeNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			// 
			// TaskSizeNum
			// 
			this->TaskSizeNum->Location = System::Drawing::Point(220, 126);
			this->TaskSizeNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			this->TaskSizeNum->Name = L"TaskSizeNum";
			this->TaskSizeNum->Size = System::Drawing::Size(120, 20);
			this->TaskSizeNum->TabIndex = 6;
			this->TaskSizeNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			// 
			// CpuThreadsNum
			// 
			this->CpuThreadsNum->Location = System::Drawing::Point(220, 152);
			this->CpuThreadsNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			this->CpuThreadsNum->Name = L"CpuThreadsNum";
			this->CpuThreadsNum->Size = System::Drawing::Size(120, 20);
			this->CpuThreadsNum->TabIndex = 10;
			this->CpuThreadsNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			// 
			// CompressionLevelSlider
			// 
			this->CompressionLevelSlider->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->CompressionLevelSlider->BackColor = System::Drawing::SystemColors::Window;
			this->CompressionLevelSlider->Location = System::Drawing::Point(115, 7);
			this->CompressionLevelSlider->Maximum = 11;
			this->CompressionLevelSlider->Minimum = 1;
			this->CompressionLevelSlider->Name = L"CompressionLevelSlider";
			this->CompressionLevelSlider->Size = System::Drawing::Size(523, 45);
			this->CompressionLevelSlider->TabIndex = 2;
			this->CompressionLevelSlider->Value = 7;
			// 
			// StereoDecorrelationCmb
			// 
			this->StereoDecorrelationCmb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->StereoDecorrelationCmb->FormattingEnabled = true;
			this->StereoDecorrelationCmb->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Search", L"Independent"});
			this->StereoDecorrelationCmb->Location = System::Drawing::Point(516, 6);
			this->StereoDecorrelationCmb->Name = L"StereoDecorrelationCmb";
			this->StereoDecorrelationCmb->Size = System::Drawing::Size(121, 21);
			this->StereoDecorrelationCmb->TabIndex = 12;
			// 
			// WindowFunctionCmb
			// 
			this->WindowFunctionCmb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->WindowFunctionCmb->FormattingEnabled = true;
			this->WindowFunctionCmb->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Welch", L"Tukey", L"Hann", L"Flattop", 
				L"Bartlett", L"Tukey-Flattop"});
			this->WindowFunctionCmb->Location = System::Drawing::Point(516, 33);
			this->WindowFunctionCmb->Name = L"WindowFunctionCmb";
			this->WindowFunctionCmb->Size = System::Drawing::Size(121, 21);
			this->WindowFunctionCmb->TabIndex = 13;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(350, 75);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 22)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(287, 129);
			this->tableLayoutPanel1->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Location = System::Drawing::Point(95, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Minimum";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Location = System::Drawing::Point(192, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Maximum";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Location = System::Drawing::Point(3, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 26);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Partition Order:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Location = System::Drawing::Point(3, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 26);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Prediction Order:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label5->Location = System::Drawing::Point(3, 74);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 26);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Fixed Order:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label6->Location = System::Drawing::Point(3, 100);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 26);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Precision:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// numericUpDown8
			// 
			this->numericUpDown8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown8->Location = System::Drawing::Point(192, 103);
			this->numericUpDown8->Name = L"numericUpDown8";
			this->numericUpDown8->Size = System::Drawing::Size(92, 20);
			this->numericUpDown8->TabIndex = 13;
			// 
			// numericUpDown7
			// 
			this->numericUpDown7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown7->Location = System::Drawing::Point(95, 103);
			this->numericUpDown7->Name = L"numericUpDown7";
			this->numericUpDown7->Size = System::Drawing::Size(91, 20);
			this->numericUpDown7->TabIndex = 12;
			// 
			// numericUpDown6
			// 
			this->numericUpDown6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown6->Location = System::Drawing::Point(192, 77);
			this->numericUpDown6->Name = L"numericUpDown6";
			this->numericUpDown6->Size = System::Drawing::Size(92, 20);
			this->numericUpDown6->TabIndex = 10;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown5->Location = System::Drawing::Point(95, 77);
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(91, 20);
			this->numericUpDown5->TabIndex = 9;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown4->Location = System::Drawing::Point(192, 51);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {32, 0, 0, 0});
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(92, 20);
			this->numericUpDown4->TabIndex = 7;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown3->Location = System::Drawing::Point(95, 51);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {32, 0, 0, 0});
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(91, 20);
			this->numericUpDown3->TabIndex = 6;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown2->Location = System::Drawing::Point(192, 25);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(92, 20);
			this->numericUpDown2->TabIndex = 4;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown1->Location = System::Drawing::Point(95, 25);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(91, 20);
			this->numericUpDown1->TabIndex = 3;
			// 
			// BlockSizeNum
			// 
			this->BlockSizeNum->Location = System::Drawing::Point(220, 178);
			this->BlockSizeNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			this->BlockSizeNum->Name = L"BlockSizeNum";
			this->BlockSizeNum->Size = System::Drawing::Size(120, 20);
			this->BlockSizeNum->TabIndex = 14;
			this->BlockSizeNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			// 
			// PaddingBytesNum
			// 
			this->PaddingBytesNum->Location = System::Drawing::Point(113, 71);
			this->PaddingBytesNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65536, 0, 0, 0});
			this->PaddingBytesNum->Name = L"PaddingBytesNum";
			this->PaddingBytesNum->Size = System::Drawing::Size(120, 20);
			this->PaddingBytesNum->TabIndex = 6;
			// 
			// MainTabControl
			// 
			this->MainTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MainTabControl->Controls->Add(this->BasicSettings);
			this->MainTabControl->Controls->Add(this->AdvancedSettings);
			this->MainTabControl->Controls->Add(this->OpenCLSettings);
			this->MainTabControl->Location = System::Drawing::Point(12, 12);
			this->MainTabControl->Name = L"MainTabControl";
			this->MainTabControl->SelectedIndex = 0;
			this->MainTabControl->Size = System::Drawing::Size(652, 349);
			this->MainTabControl->TabIndex = 1;
			// 
			// BasicSettings
			// 
			this->BasicSettings->Controls->Add(this->PaddingBytesLbl);
			this->BasicSettings->Controls->Add(this->label9);
			this->BasicSettings->Controls->Add(this->label8);
			this->BasicSettings->Controls->Add(this->CompressionLevelLbl);
			this->BasicSettings->Controls->Add(this->VerifyEncodingChk);
			this->BasicSettings->Controls->Add(this->PaddingBytesNum);
			this->BasicSettings->Controls->Add(this->ComputeMd5HashChk);
			this->BasicSettings->Controls->Add(this->OffloadGpuToCpuChk);
			this->BasicSettings->Controls->Add(this->RiceEncodingChk);
			this->BasicSettings->Controls->Add(this->CompressionLevelSlider);
			this->BasicSettings->Location = System::Drawing::Point(4, 22);
			this->BasicSettings->Name = L"BasicSettings";
			this->BasicSettings->Padding = System::Windows::Forms::Padding(3);
			this->BasicSettings->Size = System::Drawing::Size(644, 323);
			this->BasicSettings->TabIndex = 0;
			this->BasicSettings->Text = L"Basic Settings";
			this->BasicSettings->UseVisualStyleBackColor = true;
			// 
			// PaddingBytesLbl
			// 
			this->PaddingBytesLbl->AutoSize = true;
			this->PaddingBytesLbl->Location = System::Drawing::Point(6, 73);
			this->PaddingBytesLbl->Name = L"PaddingBytesLbl";
			this->PaddingBytesLbl->Size = System::Drawing::Size(77, 13);
			this->PaddingBytesLbl->TabIndex = 5;
			this->PaddingBytesLbl->Text = L"Padding bytes:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->label9->Location = System::Drawing::Point(112, 39);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(162, 13);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Fastest encoding (largest filesize)";
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->label8->Location = System::Drawing::Point(467, 39);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(171, 13);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Slowest encoding (smallest filesize)";
			// 
			// CompressionLevelLbl
			// 
			this->CompressionLevelLbl->AutoSize = true;
			this->CompressionLevelLbl->Location = System::Drawing::Point(6, 10);
			this->CompressionLevelLbl->Name = L"CompressionLevelLbl";
			this->CompressionLevelLbl->Size = System::Drawing::Size(95, 13);
			this->CompressionLevelLbl->TabIndex = 1;
			this->CompressionLevelLbl->Text = L"Compression level:";
			// 
			// AdvancedSettings
			// 
			this->AdvancedSettings->Controls->Add(this->label15);
			this->AdvancedSettings->Controls->Add(this->label14);
			this->AdvancedSettings->Controls->Add(this->label13);
			this->AdvancedSettings->Controls->Add(this->tableLayoutPanel1);
			this->AdvancedSettings->Controls->Add(this->label12);
			this->AdvancedSettings->Controls->Add(this->label11);
			this->AdvancedSettings->Controls->Add(this->label10);
			this->AdvancedSettings->Controls->Add(this->label7);
			this->AdvancedSettings->Controls->Add(this->GroupSizeLbl);
			this->AdvancedSettings->Controls->Add(this->ConstantFramesEncodingChk);
			this->AdvancedSettings->Controls->Add(this->ComputeSeekTableChk);
			this->AdvancedSettings->Controls->Add(this->EstimateWindowChk);
			this->AdvancedSettings->Controls->Add(this->TasksPerChannelNum);
			this->AdvancedSettings->Controls->Add(this->TasksPerWindowNum);
			this->AdvancedSettings->Controls->Add(this->MappedMemoryChk);
			this->AdvancedSettings->Controls->Add(this->GroupSizeNum);
			this->AdvancedSettings->Controls->Add(this->TaskSizeNum);
			this->AdvancedSettings->Controls->Add(this->WindowFunctionCmb);
			this->AdvancedSettings->Controls->Add(this->StereoDecorrelationCmb);
			this->AdvancedSettings->Controls->Add(this->BlockSizeNum);
			this->AdvancedSettings->Controls->Add(this->CpuThreadsNum);
			this->AdvancedSettings->Location = System::Drawing::Point(4, 22);
			this->AdvancedSettings->Name = L"AdvancedSettings";
			this->AdvancedSettings->Padding = System::Windows::Forms::Padding(3);
			this->AdvancedSettings->Size = System::Drawing::Size(644, 323);
			this->AdvancedSettings->TabIndex = 1;
			this->AdvancedSettings->Text = L"Advanced Settings";
			this->AdvancedSettings->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(347, 36);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(135, 13);
			this->label15->TabIndex = 27;
			this->label15->Text = L"Window function algorithm:";
			// 
			// label14
			// 
			this->label14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(347, 9);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(150, 13);
			this->label14->TabIndex = 26;
			this->label14->Text = L"Stereo decorrelation algorithm:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 232);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(99, 13);
			this->label13->TabIndex = 25;
			this->label13->Text = L"Tasks per Window:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 206);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(100, 13);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Tasks Per Channel:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 180);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(58, 13);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Block size:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 154);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(140, 13);
			this->label10->TabIndex = 22;
			this->label10->Text = L"Use additional CPU threads:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 128);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(198, 13);
			this->label7->TabIndex = 21;
			this->label7->Text = L"Set number of frames per multiprocessor:";
			// 
			// GroupSizeLbl
			// 
			this->GroupSizeLbl->AutoSize = true;
			this->GroupSizeLbl->Location = System::Drawing::Point(6, 102);
			this->GroupSizeLbl->Name = L"GroupSizeLbl";
			this->GroupSizeLbl->Size = System::Drawing::Size(192, 13);
			this->GroupSizeLbl->TabIndex = 20;
			this->GroupSizeLbl->Text = L"Set GPU work group size (64,128,256):";
			// 
			// ConstantFramesEncodingChk
			// 
			this->ConstantFramesEncodingChk->AutoSize = true;
			this->ConstantFramesEncodingChk->Checked = true;
			this->ConstantFramesEncodingChk->CheckState = System::Windows::Forms::CheckState::Indeterminate;
			this->ConstantFramesEncodingChk->Location = System::Drawing::Point(6, 77);
			this->ConstantFramesEncodingChk->Name = L"ConstantFramesEncodingChk";
			this->ConstantFramesEncodingChk->Size = System::Drawing::Size(196, 17);
			this->ConstantFramesEncodingChk->TabIndex = 19;
			this->ConstantFramesEncodingChk->Text = L"Detect and encode constant frames";
			this->ConstantFramesEncodingChk->ThreeState = true;
			this->ConstantFramesEncodingChk->UseVisualStyleBackColor = true;
			// 
			// ComputeSeekTableChk
			// 
			this->ComputeSeekTableChk->AutoSize = true;
			this->ComputeSeekTableChk->Checked = true;
			this->ComputeSeekTableChk->CheckState = System::Windows::Forms::CheckState::Indeterminate;
			this->ComputeSeekTableChk->Location = System::Drawing::Point(6, 54);
			this->ComputeSeekTableChk->Name = L"ComputeSeekTableChk";
			this->ComputeSeekTableChk->Size = System::Drawing::Size(126, 17);
			this->ComputeSeekTableChk->TabIndex = 18;
			this->ComputeSeekTableChk->Text = L"Compute Seek Table";
			this->ComputeSeekTableChk->ThreeState = true;
			this->ComputeSeekTableChk->UseVisualStyleBackColor = true;
			// 
			// EstimateWindowChk
			// 
			this->EstimateWindowChk->AutoSize = true;
			this->EstimateWindowChk->Checked = true;
			this->EstimateWindowChk->CheckState = System::Windows::Forms::CheckState::Indeterminate;
			this->EstimateWindowChk->Location = System::Drawing::Point(6, 31);
			this->EstimateWindowChk->Name = L"EstimateWindowChk";
			this->EstimateWindowChk->Size = System::Drawing::Size(108, 17);
			this->EstimateWindowChk->TabIndex = 17;
			this->EstimateWindowChk->Text = L"Estimate Window";
			this->EstimateWindowChk->ThreeState = true;
			this->EstimateWindowChk->UseVisualStyleBackColor = true;
			// 
			// TasksPerChannelNum
			// 
			this->TasksPerChannelNum->Location = System::Drawing::Point(220, 204);
			this->TasksPerChannelNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {32, 0, 0, 0});
			this->TasksPerChannelNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			this->TasksPerChannelNum->Name = L"TasksPerChannelNum";
			this->TasksPerChannelNum->Size = System::Drawing::Size(120, 20);
			this->TasksPerChannelNum->TabIndex = 16;
			this->TasksPerChannelNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			// 
			// TasksPerWindowNum
			// 
			this->TasksPerWindowNum->Location = System::Drawing::Point(220, 230);
			this->TasksPerWindowNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			this->TasksPerWindowNum->Name = L"TasksPerWindowNum";
			this->TasksPerWindowNum->Size = System::Drawing::Size(120, 20);
			this->TasksPerWindowNum->TabIndex = 15;
			this->TasksPerWindowNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			// 
			// OpenCLSettings
			// 
			this->OpenCLSettings->Controls->Add(this->OpenCLDefinesLbl);
			this->OpenCLSettings->Controls->Add(this->OpenCLPlatformLbl);
			this->OpenCLSettings->Controls->Add(this->CpuEmulationChk);
			this->OpenCLSettings->Controls->Add(this->OpenCLDefinesTxt);
			this->OpenCLSettings->Controls->Add(this->OpenCLPlatformTxt);
			this->OpenCLSettings->Location = System::Drawing::Point(4, 22);
			this->OpenCLSettings->Name = L"OpenCLSettings";
			this->OpenCLSettings->Padding = System::Windows::Forms::Padding(3);
			this->OpenCLSettings->Size = System::Drawing::Size(644, 323);
			this->OpenCLSettings->TabIndex = 2;
			this->OpenCLSettings->Text = L"OpenCL Settings";
			this->OpenCLSettings->UseVisualStyleBackColor = true;
			// 
			// OpenCLDefinesLbl
			// 
			this->OpenCLDefinesLbl->AutoSize = true;
			this->OpenCLDefinesLbl->Location = System::Drawing::Point(6, 9);
			this->OpenCLDefinesLbl->Name = L"OpenCLDefinesLbl";
			this->OpenCLDefinesLbl->Size = System::Drawing::Size(126, 13);
			this->OpenCLDefinesLbl->TabIndex = 1;
			this->OpenCLDefinesLbl->Text = L"OpenCL Compile defines:";
			// 
			// OpenCLPlatformLbl
			// 
			this->OpenCLPlatformLbl->AutoSize = true;
			this->OpenCLPlatformLbl->Location = System::Drawing::Point(6, 35);
			this->OpenCLPlatformLbl->Name = L"OpenCLPlatformLbl";
			this->OpenCLPlatformLbl->Size = System::Drawing::Size(112, 13);
			this->OpenCLPlatformLbl->TabIndex = 3;
			this->OpenCLPlatformLbl->Text = L"Use OpenCL Platform:";
			// 
			// CpuEmulationChk
			// 
			this->CpuEmulationChk->AutoSize = true;
			this->CpuEmulationChk->Location = System::Drawing::Point(138, 58);
			this->CpuEmulationChk->Name = L"CpuEmulationChk";
			this->CpuEmulationChk->Size = System::Drawing::Size(119, 17);
			this->CpuEmulationChk->TabIndex = 5;
			this->CpuEmulationChk->Text = L"Use CPU Emulation";
			this->CpuEmulationChk->UseVisualStyleBackColor = true;
			// 
			// OpenCLDefinesTxt
			// 
			this->OpenCLDefinesTxt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->OpenCLDefinesTxt->Location = System::Drawing::Point(138, 6);
			this->OpenCLDefinesTxt->Name = L"OpenCLDefinesTxt";
			this->OpenCLDefinesTxt->Size = System::Drawing::Size(500, 20);
			this->OpenCLDefinesTxt->TabIndex = 2;
			// 
			// OpenCLPlatformTxt
			// 
			this->OpenCLPlatformTxt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->OpenCLPlatformTxt->Location = System::Drawing::Point(138, 32);
			this->OpenCLPlatformTxt->Name = L"OpenCLPlatformTxt";
			this->OpenCLPlatformTxt->Size = System::Drawing::Size(500, 20);
			this->OpenCLPlatformTxt->TabIndex = 4;
			// 
			// OkBtn
			// 
			this->OkBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->OkBtn->Location = System::Drawing::Point(504, 367);
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
			this->CancelBtn->Location = System::Drawing::Point(585, 367);
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
			this->ClientSize = System::Drawing::Size(676, 402);
			this->Controls->Add(this->OkBtn);
			this->Controls->Add(this->CancelBtn);
			this->Controls->Add(this->MainTabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"FlacCL Encoder Settings";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GroupSizeNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TaskSizeNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CpuThreadsNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CompressionLevelSlider))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TasksPerChannelNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TasksPerWindowNum))->EndInit();
			this->OpenCLSettings->ResumeLayout(false);
			this->OpenCLSettings->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 DialogResult = System::Windows::Forms::DialogResult::OK;
			 Close();
		 }
};
}
