#pragma once
#include "JREncoderInterface.h"

namespace MediaCenterNeroAacEncoder {

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
			//
			//TODO: Add the constructor code here
			//
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

	public:
		MediaCenterNeroAacEncoderInterface::Config GetConfig();

		void SetConfig(const MediaCenterNeroAacEncoderInterface::Config& config);

	private: System::Windows::Forms::RadioButton^  targetQualityBtn;
	private: System::Windows::Forms::RadioButton^  targetAverageBitrateButton;
	private: System::Windows::Forms::RadioButton^  targetStreamingBitrateButton;
	protected: 

	protected: 


	private: System::Windows::Forms::TrackBar^  targetQualitySlider;
	private: System::Windows::Forms::NumericUpDown^  targetAverageBitrateTxt;

	private: System::Windows::Forms::NumericUpDown^  targetStreamingBitrateTxt;


	private: System::Windows::Forms::Label^  targetAverageBitrateLabel;
	private: System::Windows::Forms::Label^  targetStreamingBitrateLabel;
	private: System::Windows::Forms::Label^  encodingProfileLabel;
	private: System::Windows::Forms::ComboBox^  encodingProfileCmb;
	private: System::Windows::Forms::Button^  OKButton;
	private: System::Windows::Forms::Button^  CancelButton;




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
			this->targetQualityBtn = (gcnew System::Windows::Forms::RadioButton());
			this->targetAverageBitrateButton = (gcnew System::Windows::Forms::RadioButton());
			this->targetStreamingBitrateButton = (gcnew System::Windows::Forms::RadioButton());
			this->targetQualitySlider = (gcnew System::Windows::Forms::TrackBar());
			this->targetAverageBitrateTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->targetStreamingBitrateTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->targetAverageBitrateLabel = (gcnew System::Windows::Forms::Label());
			this->targetStreamingBitrateLabel = (gcnew System::Windows::Forms::Label());
			this->encodingProfileLabel = (gcnew System::Windows::Forms::Label());
			this->encodingProfileCmb = (gcnew System::Windows::Forms::ComboBox());
			this->OKButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->targetQualitySlider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->targetAverageBitrateTxt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->targetStreamingBitrateTxt))->BeginInit();
			this->SuspendLayout();
			// 
			// targetQualityBtn
			// 
			this->targetQualityBtn->AutoSize = true;
			this->targetQualityBtn->Checked = true;
			this->targetQualityBtn->Location = System::Drawing::Point(12, 12);
			this->targetQualityBtn->Name = L"targetQualityBtn";
			this->targetQualityBtn->Size = System::Drawing::Size(94, 17);
			this->targetQualityBtn->TabIndex = 0;
			this->targetQualityBtn->TabStop = true;
			this->targetQualityBtn->Text = L"Target Quality:";
			this->targetQualityBtn->UseVisualStyleBackColor = true;
			this->targetQualityBtn->CheckedChanged += gcnew System::EventHandler(this, &SettingsForm::targetType_CheckChanged);
			// 
			// targetAverageBitrateButton
			// 
			this->targetAverageBitrateButton->AutoSize = true;
			this->targetAverageBitrateButton->Location = System::Drawing::Point(12, 86);
			this->targetAverageBitrateButton->Name = L"targetAverageBitrateButton";
			this->targetAverageBitrateButton->Size = System::Drawing::Size(135, 17);
			this->targetAverageBitrateButton->TabIndex = 2;
			this->targetAverageBitrateButton->Text = L"Target Average Bitrate:";
			this->targetAverageBitrateButton->UseVisualStyleBackColor = true;
			this->targetAverageBitrateButton->CheckedChanged += gcnew System::EventHandler(this, &SettingsForm::targetType_CheckChanged);
			// 
			// targetStreamingBitrateButton
			// 
			this->targetStreamingBitrateButton->AutoSize = true;
			this->targetStreamingBitrateButton->Location = System::Drawing::Point(12, 135);
			this->targetStreamingBitrateButton->Name = L"targetStreamingBitrateButton";
			this->targetStreamingBitrateButton->Size = System::Drawing::Size(142, 17);
			this->targetStreamingBitrateButton->TabIndex = 5;
			this->targetStreamingBitrateButton->Text = L"Target Streaming Bitrate:";
			this->targetStreamingBitrateButton->UseVisualStyleBackColor = true;
			this->targetStreamingBitrateButton->CheckedChanged += gcnew System::EventHandler(this, &SettingsForm::targetType_CheckChanged);
			// 
			// targetQualitySlider
			// 
			this->targetQualitySlider->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->targetQualitySlider->LargeChange = 10;
			this->targetQualitySlider->Location = System::Drawing::Point(30, 35);
			this->targetQualitySlider->Maximum = 100;
			this->targetQualitySlider->Name = L"targetQualitySlider";
			this->targetQualitySlider->Size = System::Drawing::Size(242, 45);
			this->targetQualitySlider->SmallChange = 5;
			this->targetQualitySlider->TabIndex = 1;
			this->targetQualitySlider->TickFrequency = 5;
			this->targetQualitySlider->Value = 50;
			// 
			// targetAverageBitrateTxt
			// 
			this->targetAverageBitrateTxt->Location = System::Drawing::Point(30, 109);
			this->targetAverageBitrateTxt->Name = L"targetAverageBitrateTxt";
			this->targetAverageBitrateTxt->Size = System::Drawing::Size(120, 20);
			this->targetAverageBitrateTxt->TabIndex = 3;
			// 
			// targetStreamingBitrateTxt
			// 
			this->targetStreamingBitrateTxt->Location = System::Drawing::Point(30, 158);
			this->targetStreamingBitrateTxt->Name = L"targetStreamingBitrateTxt";
			this->targetStreamingBitrateTxt->Size = System::Drawing::Size(120, 20);
			this->targetStreamingBitrateTxt->TabIndex = 6;
			// 
			// targetAverageBitrateLabel
			// 
			this->targetAverageBitrateLabel->AutoSize = true;
			this->targetAverageBitrateLabel->Location = System::Drawing::Point(156, 111);
			this->targetAverageBitrateLabel->Name = L"targetAverageBitrateLabel";
			this->targetAverageBitrateLabel->Size = System::Drawing::Size(30, 13);
			this->targetAverageBitrateLabel->TabIndex = 4;
			this->targetAverageBitrateLabel->Text = L"kbps";
			// 
			// targetStreamingBitrateLabel
			// 
			this->targetStreamingBitrateLabel->AutoSize = true;
			this->targetStreamingBitrateLabel->Location = System::Drawing::Point(156, 160);
			this->targetStreamingBitrateLabel->Name = L"targetStreamingBitrateLabel";
			this->targetStreamingBitrateLabel->Size = System::Drawing::Size(30, 13);
			this->targetStreamingBitrateLabel->TabIndex = 7;
			this->targetStreamingBitrateLabel->Text = L"kbps";
			// 
			// encodingProfileLabel
			// 
			this->encodingProfileLabel->AutoSize = true;
			this->encodingProfileLabel->Location = System::Drawing::Point(9, 187);
			this->encodingProfileLabel->Name = L"encodingProfileLabel";
			this->encodingProfileLabel->Size = System::Drawing::Size(87, 13);
			this->encodingProfileLabel->TabIndex = 8;
			this->encodingProfileLabel->Text = L"Encoding Profile:";
			// 
			// encodingProfileCmb
			// 
			this->encodingProfileCmb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->encodingProfileCmb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->encodingProfileCmb->FormattingEnabled = true;
			this->encodingProfileCmb->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"(automatic)", L"LC-AAC", L"HE-AAC", 
				L"HE-AAC v2"});
			this->encodingProfileCmb->Location = System::Drawing::Point(102, 184);
			this->encodingProfileCmb->Name = L"encodingProfileCmb";
			this->encodingProfileCmb->Size = System::Drawing::Size(170, 21);
			this->encodingProfileCmb->TabIndex = 9;
			// 
			// OKButton
			// 
			this->OKButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->OKButton->Location = System::Drawing::Point(116, 221);
			this->OKButton->Name = L"OKButton";
			this->OKButton->Size = System::Drawing::Size(75, 23);
			this->OKButton->TabIndex = 10;
			this->OKButton->Text = L"OK";
			this->OKButton->UseVisualStyleBackColor = true;
			this->OKButton->Click += gcnew System::EventHandler(this, &SettingsForm::OKButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CancelButton->Location = System::Drawing::Point(197, 221);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 11;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &SettingsForm::CancelButton_Click);
			// 
			// SettingsForm
			// 
			this->AcceptButton = this->OKButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(284, 256);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->OKButton);
			this->Controls->Add(this->encodingProfileCmb);
			this->Controls->Add(this->encodingProfileLabel);
			this->Controls->Add(this->targetStreamingBitrateLabel);
			this->Controls->Add(this->targetAverageBitrateLabel);
			this->Controls->Add(this->targetStreamingBitrateTxt);
			this->Controls->Add(this->targetAverageBitrateTxt);
			this->Controls->Add(this->targetQualitySlider);
			this->Controls->Add(this->targetStreamingBitrateButton);
			this->Controls->Add(this->targetAverageBitrateButton);
			this->Controls->Add(this->targetQualityBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(300, 294);
			this->Name = L"SettingsForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Nero AAC Encoder Settings";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->targetQualitySlider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->targetAverageBitrateTxt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->targetStreamingBitrateTxt))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SettingsForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void targetType_CheckChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void OKButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e);
};
}
