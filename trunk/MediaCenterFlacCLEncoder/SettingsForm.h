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

			result.MappedMemory = TriboolFromCheckState(MappedMemoryChk->CheckState);
			result.EstimateWindow = TriboolFromCheckState(EstimateWindowChk->CheckState);
			result.ComputeSeekTable = TriboolFromCheckState(ComputeSeekTableChk->CheckState);
			result.ConstantFramesEncoding = TriboolFromCheckState(ConstantFramesEncodingChk->CheckState);
			result.GpuWorkGroupSize = (System::Int32)GroupSizeNum->Value;
			result.FramesPerMultiprocessor = (System::Int32)TaskSizeNum->Value;
			result.AdditionalCpuThreads = (System::Int32)CpuThreadsNum->Value;
			result.BlockSize = (System::Int32)BlockSizeNum->Value;
			result.TasksPerChannel = (System::Int32)TasksPerChannelNum->Value;
			result.TasksPerWindow = (System::Int32)TasksPerWindowNum->Value;
			result.StereoDecorrelationAlgorithm;
			result.WindowAlgorithm;

			result.PartitionOrder = std::pair<int, int>((Int32), (Int32));
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

			MappedMemoryChk->CheckState = CheckStateFromTribool(config.MappedMemory);
			EstimateWindowChk->CheckState = CheckStateFromTribool(config.EstimateWindow);
			ComputeSeekTableChk->CheckState = CheckStateFromTribool(config.ComputeSeekTable);
			ConstantFramesEncodingChk->CheckState = CheckStateFromTribool(config.ConstantFramesEncoding);
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

	private:
		boost::tribool TriboolFromCheckState(CheckState value)
		{
			return value == CheckState::Indeterminate ? boost::tribool(boost::indeterminate) :
				value == CheckState::Checked;
		}

		CheckState CheckStateFromTribool(boost::tribool value)
		{
			return boost::indeterminate(value) ? CheckState::Indeterminate :
				(value ? CheckState::Checked : CheckState::Unchecked);
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
private: System::Windows::Forms::Label^  minimumLbl;
private: System::Windows::Forms::Label^  maximumLbl;
private: System::Windows::Forms::Label^  PartitionOrderLbl;
private: System::Windows::Forms::Label^  PredictionOrderLbl;
private: System::Windows::Forms::Label^  FixedOrderLbl;
private: System::Windows::Forms::Label^  PrecisionLbl;
private: System::Windows::Forms::NumericUpDown^  PrecisionMaxNum;







private: System::Windows::Forms::NumericUpDown^  PrecisionMinNum;

private: System::Windows::Forms::NumericUpDown^  FixedOrderMaxNum;

private: System::Windows::Forms::NumericUpDown^  FixedOrderMinNum;

private: System::Windows::Forms::NumericUpDown^  PredictionOrderMaxNum;

private: System::Windows::Forms::NumericUpDown^  PredictionOrderMinNum;

private: System::Windows::Forms::NumericUpDown^  PartitionOrderMaxNum;

private: System::Windows::Forms::NumericUpDown^  PartitionOrderMinNum;

	private: System::Windows::Forms::NumericUpDown^  BlockSizeNum;
	private: System::Windows::Forms::NumericUpDown^  PaddingBytesNum;
	private: System::Windows::Forms::TabControl^  MainTabControl;
	private: System::Windows::Forms::TabPage^  BasicSettings;
	private: System::Windows::Forms::TabPage^  AdvancedSettings;
	private: System::Windows::Forms::Button^  OkBtn;
	private: System::Windows::Forms::Button^  CancelBtn;
private: System::Windows::Forms::Label^  fastestEncodingLbl;
private: System::Windows::Forms::Label^  slowestEncodingLbl;


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
private: System::Windows::Forms::Label^  TaskSizeLbl;
private: System::Windows::Forms::Label^  BlockSizeLbl;


private: System::Windows::Forms::Label^  CpuThreadsLbl;

private: System::Windows::Forms::Label^  TasksPerWindowLbl;
private: System::Windows::Forms::Label^  TasksPerChannelLbl;


private: System::Windows::Forms::Label^  WindowFunctionLbl;





private: System::Windows::Forms::Label^  StereoDecorrelationLbl;


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
			this->minimumLbl = (gcnew System::Windows::Forms::Label());
			this->maximumLbl = (gcnew System::Windows::Forms::Label());
			this->PartitionOrderLbl = (gcnew System::Windows::Forms::Label());
			this->PredictionOrderLbl = (gcnew System::Windows::Forms::Label());
			this->FixedOrderLbl = (gcnew System::Windows::Forms::Label());
			this->PrecisionLbl = (gcnew System::Windows::Forms::Label());
			this->PrecisionMaxNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->PrecisionMinNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->FixedOrderMaxNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->FixedOrderMinNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->PredictionOrderMaxNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->PredictionOrderMinNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->PartitionOrderMaxNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->PartitionOrderMinNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->BlockSizeNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->PaddingBytesNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->MainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->BasicSettings = (gcnew System::Windows::Forms::TabPage());
			this->PaddingBytesLbl = (gcnew System::Windows::Forms::Label());
			this->fastestEncodingLbl = (gcnew System::Windows::Forms::Label());
			this->slowestEncodingLbl = (gcnew System::Windows::Forms::Label());
			this->CompressionLevelLbl = (gcnew System::Windows::Forms::Label());
			this->AdvancedSettings = (gcnew System::Windows::Forms::TabPage());
			this->WindowFunctionLbl = (gcnew System::Windows::Forms::Label());
			this->StereoDecorrelationLbl = (gcnew System::Windows::Forms::Label());
			this->TasksPerWindowLbl = (gcnew System::Windows::Forms::Label());
			this->TasksPerChannelLbl = (gcnew System::Windows::Forms::Label());
			this->BlockSizeLbl = (gcnew System::Windows::Forms::Label());
			this->CpuThreadsLbl = (gcnew System::Windows::Forms::Label());
			this->TaskSizeLbl = (gcnew System::Windows::Forms::Label());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PrecisionMaxNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PrecisionMinNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FixedOrderMaxNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FixedOrderMinNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PredictionOrderMaxNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PredictionOrderMinNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PartitionOrderMaxNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PartitionOrderMinNum))->BeginInit();
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
			this->tableLayoutPanel1->Controls->Add(this->minimumLbl, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->maximumLbl, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->PartitionOrderLbl, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->PredictionOrderLbl, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->FixedOrderLbl, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->PrecisionLbl, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->PrecisionMaxNum, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->PrecisionMinNum, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->FixedOrderMaxNum, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->FixedOrderMinNum, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->PredictionOrderMaxNum, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->PredictionOrderMinNum, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->PartitionOrderMaxNum, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->PartitionOrderMinNum, 1, 1);
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
			// minimumLbl
			// 
			this->minimumLbl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->minimumLbl->Location = System::Drawing::Point(95, 0);
			this->minimumLbl->Name = L"minimumLbl";
			this->minimumLbl->Size = System::Drawing::Size(91, 22);
			this->minimumLbl->TabIndex = 0;
			this->minimumLbl->Text = L"Minimum";
			this->minimumLbl->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// maximumLbl
			// 
			this->maximumLbl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->maximumLbl->Location = System::Drawing::Point(192, 0);
			this->maximumLbl->Name = L"maximumLbl";
			this->maximumLbl->Size = System::Drawing::Size(92, 22);
			this->maximumLbl->TabIndex = 1;
			this->maximumLbl->Text = L"Maximum";
			this->maximumLbl->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// PartitionOrderLbl
			// 
			this->PartitionOrderLbl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PartitionOrderLbl->Location = System::Drawing::Point(3, 22);
			this->PartitionOrderLbl->Name = L"PartitionOrderLbl";
			this->PartitionOrderLbl->Size = System::Drawing::Size(86, 26);
			this->PartitionOrderLbl->TabIndex = 2;
			this->PartitionOrderLbl->Text = L"Partition Order:";
			this->PartitionOrderLbl->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// PredictionOrderLbl
			// 
			this->PredictionOrderLbl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PredictionOrderLbl->Location = System::Drawing::Point(3, 48);
			this->PredictionOrderLbl->Name = L"PredictionOrderLbl";
			this->PredictionOrderLbl->Size = System::Drawing::Size(86, 26);
			this->PredictionOrderLbl->TabIndex = 5;
			this->PredictionOrderLbl->Text = L"Prediction Order:";
			this->PredictionOrderLbl->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// FixedOrderLbl
			// 
			this->FixedOrderLbl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FixedOrderLbl->Location = System::Drawing::Point(3, 74);
			this->FixedOrderLbl->Name = L"FixedOrderLbl";
			this->FixedOrderLbl->Size = System::Drawing::Size(86, 26);
			this->FixedOrderLbl->TabIndex = 8;
			this->FixedOrderLbl->Text = L"Fixed Order:";
			this->FixedOrderLbl->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// PrecisionLbl
			// 
			this->PrecisionLbl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PrecisionLbl->Location = System::Drawing::Point(3, 100);
			this->PrecisionLbl->Name = L"PrecisionLbl";
			this->PrecisionLbl->Size = System::Drawing::Size(86, 26);
			this->PrecisionLbl->TabIndex = 11;
			this->PrecisionLbl->Text = L"Precision:";
			this->PrecisionLbl->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// PrecisionMaxNum
			// 
			this->PrecisionMaxNum->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PrecisionMaxNum->Location = System::Drawing::Point(192, 103);
			this->PrecisionMaxNum->Name = L"PrecisionMaxNum";
			this->PrecisionMaxNum->Size = System::Drawing::Size(92, 20);
			this->PrecisionMaxNum->TabIndex = 13;
			// 
			// PrecisionMinNum
			// 
			this->PrecisionMinNum->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PrecisionMinNum->Location = System::Drawing::Point(95, 103);
			this->PrecisionMinNum->Name = L"PrecisionMinNum";
			this->PrecisionMinNum->Size = System::Drawing::Size(91, 20);
			this->PrecisionMinNum->TabIndex = 12;
			// 
			// FixedOrderMaxNum
			// 
			this->FixedOrderMaxNum->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FixedOrderMaxNum->Location = System::Drawing::Point(192, 77);
			this->FixedOrderMaxNum->Name = L"FixedOrderMaxNum";
			this->FixedOrderMaxNum->Size = System::Drawing::Size(92, 20);
			this->FixedOrderMaxNum->TabIndex = 10;
			// 
			// FixedOrderMinNum
			// 
			this->FixedOrderMinNum->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FixedOrderMinNum->Location = System::Drawing::Point(95, 77);
			this->FixedOrderMinNum->Name = L"FixedOrderMinNum";
			this->FixedOrderMinNum->Size = System::Drawing::Size(91, 20);
			this->FixedOrderMinNum->TabIndex = 9;
			// 
			// PredictionOrderMaxNum
			// 
			this->PredictionOrderMaxNum->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PredictionOrderMaxNum->Location = System::Drawing::Point(192, 51);
			this->PredictionOrderMaxNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {32, 0, 0, 0});
			this->PredictionOrderMaxNum->Name = L"PredictionOrderMaxNum";
			this->PredictionOrderMaxNum->Size = System::Drawing::Size(92, 20);
			this->PredictionOrderMaxNum->TabIndex = 7;
			// 
			// PredictionOrderMinNum
			// 
			this->PredictionOrderMinNum->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PredictionOrderMinNum->Location = System::Drawing::Point(95, 51);
			this->PredictionOrderMinNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {32, 0, 0, 0});
			this->PredictionOrderMinNum->Name = L"PredictionOrderMinNum";
			this->PredictionOrderMinNum->Size = System::Drawing::Size(91, 20);
			this->PredictionOrderMinNum->TabIndex = 6;
			// 
			// PartitionOrderMaxNum
			// 
			this->PartitionOrderMaxNum->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PartitionOrderMaxNum->Location = System::Drawing::Point(192, 25);
			this->PartitionOrderMaxNum->Name = L"PartitionOrderMaxNum";
			this->PartitionOrderMaxNum->Size = System::Drawing::Size(92, 20);
			this->PartitionOrderMaxNum->TabIndex = 4;
			// 
			// PartitionOrderMinNum
			// 
			this->PartitionOrderMinNum->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PartitionOrderMinNum->Location = System::Drawing::Point(95, 25);
			this->PartitionOrderMinNum->Name = L"PartitionOrderMinNum";
			this->PartitionOrderMinNum->Size = System::Drawing::Size(91, 20);
			this->PartitionOrderMinNum->TabIndex = 3;
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
			this->BasicSettings->Controls->Add(this->fastestEncodingLbl);
			this->BasicSettings->Controls->Add(this->slowestEncodingLbl);
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
			// fastestEncodingLbl
			// 
			this->fastestEncodingLbl->AutoSize = true;
			this->fastestEncodingLbl->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->fastestEncodingLbl->Location = System::Drawing::Point(112, 39);
			this->fastestEncodingLbl->Name = L"fastestEncodingLbl";
			this->fastestEncodingLbl->Size = System::Drawing::Size(162, 13);
			this->fastestEncodingLbl->TabIndex = 3;
			this->fastestEncodingLbl->Text = L"Fastest encoding (largest filesize)";
			// 
			// slowestEncodingLbl
			// 
			this->slowestEncodingLbl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->slowestEncodingLbl->AutoSize = true;
			this->slowestEncodingLbl->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->slowestEncodingLbl->Location = System::Drawing::Point(467, 39);
			this->slowestEncodingLbl->Name = L"slowestEncodingLbl";
			this->slowestEncodingLbl->Size = System::Drawing::Size(171, 13);
			this->slowestEncodingLbl->TabIndex = 4;
			this->slowestEncodingLbl->Text = L"Slowest encoding (smallest filesize)";
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
			this->AdvancedSettings->Controls->Add(this->WindowFunctionLbl);
			this->AdvancedSettings->Controls->Add(this->StereoDecorrelationLbl);
			this->AdvancedSettings->Controls->Add(this->TasksPerWindowLbl);
			this->AdvancedSettings->Controls->Add(this->tableLayoutPanel1);
			this->AdvancedSettings->Controls->Add(this->TasksPerChannelLbl);
			this->AdvancedSettings->Controls->Add(this->BlockSizeLbl);
			this->AdvancedSettings->Controls->Add(this->CpuThreadsLbl);
			this->AdvancedSettings->Controls->Add(this->TaskSizeLbl);
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
			// WindowFunctionLbl
			// 
			this->WindowFunctionLbl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->WindowFunctionLbl->AutoSize = true;
			this->WindowFunctionLbl->Location = System::Drawing::Point(347, 36);
			this->WindowFunctionLbl->Name = L"WindowFunctionLbl";
			this->WindowFunctionLbl->Size = System::Drawing::Size(135, 13);
			this->WindowFunctionLbl->TabIndex = 27;
			this->WindowFunctionLbl->Text = L"Window function algorithm:";
			// 
			// StereoDecorrelationLbl
			// 
			this->StereoDecorrelationLbl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->StereoDecorrelationLbl->AutoSize = true;
			this->StereoDecorrelationLbl->Location = System::Drawing::Point(347, 9);
			this->StereoDecorrelationLbl->Name = L"StereoDecorrelationLbl";
			this->StereoDecorrelationLbl->Size = System::Drawing::Size(150, 13);
			this->StereoDecorrelationLbl->TabIndex = 26;
			this->StereoDecorrelationLbl->Text = L"Stereo decorrelation algorithm:";
			// 
			// TasksPerWindowLbl
			// 
			this->TasksPerWindowLbl->AutoSize = true;
			this->TasksPerWindowLbl->Location = System::Drawing::Point(6, 232);
			this->TasksPerWindowLbl->Name = L"TasksPerWindowLbl";
			this->TasksPerWindowLbl->Size = System::Drawing::Size(99, 13);
			this->TasksPerWindowLbl->TabIndex = 25;
			this->TasksPerWindowLbl->Text = L"Tasks per Window:";
			// 
			// TasksPerChannelLbl
			// 
			this->TasksPerChannelLbl->AutoSize = true;
			this->TasksPerChannelLbl->Location = System::Drawing::Point(6, 206);
			this->TasksPerChannelLbl->Name = L"TasksPerChannelLbl";
			this->TasksPerChannelLbl->Size = System::Drawing::Size(100, 13);
			this->TasksPerChannelLbl->TabIndex = 24;
			this->TasksPerChannelLbl->Text = L"Tasks Per Channel:";
			// 
			// BlockSizeLbl
			// 
			this->BlockSizeLbl->AutoSize = true;
			this->BlockSizeLbl->Location = System::Drawing::Point(6, 180);
			this->BlockSizeLbl->Name = L"BlockSizeLbl";
			this->BlockSizeLbl->Size = System::Drawing::Size(58, 13);
			this->BlockSizeLbl->TabIndex = 23;
			this->BlockSizeLbl->Text = L"Block size:";
			// 
			// CpuThreadsLbl
			// 
			this->CpuThreadsLbl->AutoSize = true;
			this->CpuThreadsLbl->Location = System::Drawing::Point(6, 154);
			this->CpuThreadsLbl->Name = L"CpuThreadsLbl";
			this->CpuThreadsLbl->Size = System::Drawing::Size(140, 13);
			this->CpuThreadsLbl->TabIndex = 22;
			this->CpuThreadsLbl->Text = L"Use additional CPU threads:";
			// 
			// TaskSizeLbl
			// 
			this->TaskSizeLbl->AutoSize = true;
			this->TaskSizeLbl->Location = System::Drawing::Point(6, 128);
			this->TaskSizeLbl->Name = L"TaskSizeLbl";
			this->TaskSizeLbl->Size = System::Drawing::Size(198, 13);
			this->TaskSizeLbl->TabIndex = 21;
			this->TaskSizeLbl->Text = L"Set number of frames per multiprocessor:";
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PrecisionMaxNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PrecisionMinNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FixedOrderMaxNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FixedOrderMinNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PredictionOrderMaxNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PredictionOrderMinNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PartitionOrderMaxNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PartitionOrderMinNum))->EndInit();
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
