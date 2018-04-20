#include "MyForm.h"

System::Void ImageProcessor::MyForm::monochromeTint_Click(System::Object^  sender, System::EventArgs^  e) {
	saveCurrentImage();

	this->monochromeTint->Hide();
	this->customTint->Hide();
	this->chooseMonoTintColor->Show();
}

System::Void ImageProcessor::MyForm::chooseMonoTintColor_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::ColorDialog^ tintColors = gcnew ColorDialog();
	tintColors->AllowFullOpen = true;
	tintColors->ShowHelp = true;

	if (tintColors->ShowDialog() == ::System::Windows::Forms::DialogResult::OK) {
		tintColorSelect = tintColors->Color;
		changes->push(gcnew Bitmap(currentImage->Image));

		System::Drawing::Bitmap^ changedBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current picturebox image
		System::Drawing::Rectangle rect = Rectangle(0, 0, changedBitmap->Width, changedBitmap->Height); // new rectangle object w/ same image dimensions
		System::Drawing::Imaging::BitmapData^ bitmapData = changedBitmap->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadOnly, changedBitmap->PixelFormat); // locks bitmap
		IntPtr ptr = bitmapData->Scan0; // idk scans bitmap data
		int bytes = Math::Abs(bitmapData->Stride) * changedBitmap->Height; // rgb values converted into byte value
		array<Byte>^ rgbValues = gcnew array<Byte>(bytes); // byte array to hold rgb values
		System::Runtime::InteropServices::Marshal::Copy(ptr, rgbValues, 0, bytes); // copies values to rgb array
		for (int i = 0; i < rgbValues->Length; i += 4) {
			Byte r = rgbValues[i]; // value of red / 255
			Byte g = rgbValues[i + 1]; // value of green / 255
			Byte b = rgbValues[i + 2]; // value of blue / 255
			Byte average = (r + g + b) / 3; // average of three rgb values
			rgbValues[i] = average + tintColorSelect.B < 255 ? average + tintColorSelect.B : 255;
			rgbValues[i + 1] = average + tintColorSelect.G < 255 ? average + tintColorSelect.G : 255;
			rgbValues[i + 2] = average + tintColorSelect.R < 255 ? average + tintColorSelect.R : 255;
		}
		System::Runtime::InteropServices::Marshal::Copy(rgbValues, 0, ptr, bytes); // copies rgb values to bitmap data
		changedBitmap->UnlockBits(bitmapData); // transfers bitmap data back to bitmap & unlocks bitmap
		currentImage->Image = changedBitmap; // current picturebox image set to bitmap
	}

}

System::Void ImageProcessor::MyForm::customTint_Click(System::Object^  sender, System::EventArgs^  e) {
	saveCurrentImage();
	this->monochromeTint->Hide();
	this->customTint->Hide();
	this->tintColor->Show();
}

System::Void ImageProcessor::MyForm::tintColor_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::ColorDialog^ tintColors = gcnew ColorDialog();
	tintColors->AllowFullOpen = true;
	tintColors->ShowHelp = true;

	if (tintColors->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		tintColorSelect = tintColors->Color;
		this->tintIntensitySlider->Value = 0;
		this->tintIntensityValue->Text = "0";
		tintIntensityValue->ForeColor = ((tintColorSelect.R + tintColorSelect.G + tintColorSelect.B) / 3 < 127.5) ? Color::White : Color::Black;
		this->tintIntensityValue->BackColor = tintColorSelect;
		this->tintIntensitySlider->Show();
		this->tintIntensityValue->Show();
		this->percentLabelTint->Show();
		changes->push(gcnew Bitmap(currentImage->Image));
	}
}

System::Void ImageProcessor::MyForm::tintIntensitySlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->tintIntensityTimer->Enabled = true;
}

System::Void ImageProcessor::MyForm::tintIntensitySlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->tintIntensityTimer->Enabled = false;
	this->tintIntensityTimer->Enabled = true;
	this->tintIntensityTimer->Enabled = false;
}

System::Void ImageProcessor::MyForm::tintIntensitySlider_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	int percentage = (this->tintIntensitySlider->Value * 100) / 255;
	this->tintIntensityValue->Text = System::Convert::ToString(percentage);
}

System::Void ImageProcessor::MyForm::tintIntensityValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {
	if (e->KeyCode == Keys::Enter) {
		int tintIntensityVal;
		if (System::Int32::TryParse(this->tintIntensityValue->Text, tintIntensityVal)) {
			if (tintIntensityVal > 100) {
				this->tintIntensitySlider->Value = 255;
			}
			else if (tintIntensityVal < 0) {
				this->tintIntensitySlider->Value = 0;
			}
			else {
				this->tintIntensitySlider->Value = (tintIntensityVal * 255) / 100;
			}
			tintIntensitySlider_ValueChange();
		}
	}
}

System::Void ImageProcessor::MyForm::tintIntensityTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
	tintIntensitySlider_ValueChange();
}

System::Void ImageProcessor::MyForm::tintIntensitySlider_ValueChange() {
	System::Drawing::Bitmap^ tempBitmap = changes->bitmapPeek();
	float intensity = this->tintIntensitySlider->Value / 255.0f;
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(tempBitmap->Width, tempBitmap->Height);
	System::Drawing::Graphics^ newGraphics = System::Drawing::Graphics::FromImage(newBitmap);
	System::Drawing::Imaging::ColorMatrix^ colorMatrix = gcnew System::Drawing::Imaging::ColorMatrix();

	float r = (tintColorSelect.R / 255.0f) * intensity;
	float g = (tintColorSelect.G / 255.0f) * intensity;
	float b = (tintColorSelect.B / 255.0f) * intensity;

	// [ 1 ] [ 0 ] [ 0 ] [ 0 ] [ 0 ]
	colorMatrix->Matrix00 = 1;
	colorMatrix->Matrix01 = 0;
	colorMatrix->Matrix02 = 0;
	colorMatrix->Matrix03 = 0;
	colorMatrix->Matrix04 = 0;

	// [ 0 ] [ 1 ] [ 0 ] [ 0 ] [ 0 ]
	colorMatrix->Matrix10 = 0;
	colorMatrix->Matrix11 = 1;
	colorMatrix->Matrix12 = 0;
	colorMatrix->Matrix13 = 0;
	colorMatrix->Matrix14 = 0;

	// [ 0 ] [ 0 ] [ 1 ] [ 0 ] [ 0 ]
	colorMatrix->Matrix20 = 0;
	colorMatrix->Matrix21 = 0;
	colorMatrix->Matrix22 = 1;
	colorMatrix->Matrix23 = 0;
	colorMatrix->Matrix24 = 0;

	// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
	colorMatrix->Matrix30 = 0;
	colorMatrix->Matrix31 = 0;
	colorMatrix->Matrix32 = 0;
	colorMatrix->Matrix33 = 1;
	colorMatrix->Matrix34 = 0;

	// [ r ] [ g ] [ b ] [ 0 ] [ 1 ]
	colorMatrix->Matrix40 = r;
	colorMatrix->Matrix41 = g;
	colorMatrix->Matrix42 = b;
	colorMatrix->Matrix43 = 0;
	colorMatrix->Matrix44 = 1;

	// [ 1 ] [ 0 ] [ 0 ] [ 0 ] [ 0 ]
	// [ 0 ] [ 1 ] [ 0 ] [ 0 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 1 ] [ 0 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
	// [ b ] [ b ] [ b ] [ 0 ] [ 1 ]
	// Matrix which will manipulate the tint of the image

	System::Drawing::Imaging::ImageAttributes^ attributes = gcnew System::Drawing::Imaging::ImageAttributes();
	attributes->SetColorMatrix(colorMatrix);
	newGraphics->DrawImage(tempBitmap, Rectangle(0, 0, tempBitmap->Width, tempBitmap->Height), 0, 0, tempBitmap->Width, tempBitmap->Height, GraphicsUnit::Pixel, attributes);
	currentImage->Image = newBitmap;
}