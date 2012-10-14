#include "StdAfx.h"
#include "SettingsForm.h"

namespace MediaCenterNeroAacEncoder {

	void SettingsForm::SettingsForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		encodingProfileCmb->SelectedIndex = 0;
		targetAverageBitrateLabel->Enabled = false;
		targetAverageBitrateTxt->Enabled = false;
		targetStreamingBitrateLabel->Enabled = false;
		targetStreamingBitrateTxt->Enabled = false;
	}

	MediaCenterNeroAacEncoderInterface::Config SettingsForm::GetConfig()
	{
		MediaCenterNeroAacEncoderInterface::Config result;
		
		if (targetAverageBitrateButton->Checked)
		{
			result.Mode = MediaCenterNeroAacEncoderInterface::Config::EncoderMode::TargetBitRate;
			result.TargetBitRate = Decimal::ToUInt32(targetAverageBitrateTxt->Value);
		}
		else if (targetStreamingBitrateButton->Checked)
		{
			result.Mode = MediaCenterNeroAacEncoderInterface::Config::EncoderMode::TargetStreamingBitRate;
			result.TargetStreamingBitRate = Decimal::ToUInt32(targetStreamingBitrateTxt->Value);
		}
		else
		{
			result.Mode = MediaCenterNeroAacEncoderInterface::Config::EncoderMode::TargetQuality;
			result.TargetQuality = targetQualitySlider->Value / (float)targetQualitySlider->Maximum;
		}

		result.Profile = static_cast<MediaCenterNeroAacEncoderInterface::Config::EncoderProfile>(
			encodingProfileCmb->SelectedIndex);
		return result;
	}

	void SettingsForm::SetConfig(const MediaCenterNeroAacEncoderInterface::Config& config)
	{
		switch (config.Mode)
		{
		case MediaCenterNeroAacEncoderInterface::Config::EncoderMode::TargetBitRate:
			targetAverageBitrateButton->Checked = true;
			targetAverageBitrateTxt->Value = config.TargetBitRate;
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderMode::TargetStreamingBitRate:
			targetStreamingBitrateButton->Checked = true;
			targetStreamingBitrateTxt->Value = config.TargetStreamingBitRate;
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderMode::TargetQuality:
		default:
			targetQualityBtn->Checked = true;
			targetQualitySlider->Value = static_cast<int>(
				config.TargetQuality * targetQualitySlider->Maximum);
			break;
		}

		encodingProfileCmb->SelectedIndex = static_cast<int>(config.Profile);
	}

	void SettingsForm::targetType_CheckChanged(System::Object^ sender, System::EventArgs^ e)
	{
		targetQualitySlider->Enabled = targetQualityBtn->Checked;
		targetAverageBitrateLabel->Enabled = targetAverageBitrateButton->Checked;
		targetAverageBitrateTxt->Enabled = targetAverageBitrateButton->Checked;
		targetStreamingBitrateLabel->Enabled = targetStreamingBitrateButton->Checked;
		targetStreamingBitrateTxt->Enabled = targetStreamingBitrateButton->Checked;
	}

	void SettingsForm::OKButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		DialogResult = System::Windows::Forms::DialogResult::OK;
		Close();
	}

	void SettingsForm::CancelButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		DialogResult = System::Windows::Forms::DialogResult::Cancel;
		Close();
	}
}
