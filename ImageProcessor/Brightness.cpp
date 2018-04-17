#include "MyForm.h"

// BE CAREFUL WITH PRETTY HIGH RES PICS

System::Void ImageProcessor::MyForm::brightnessSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->brightnessTimer->Enabled = true;
}

System::Void ImageProcessor::MyForm::brightnessSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->brightnessTimer->Enabled = false;
	this->brightnessTimer->Enabled = true;
	this->brightnessTimer->Enabled = false;
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	changes->push(bitmap);
}

System::Void ImageProcessor::MyForm::brightnessSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	int percentage = (this->brightnessSlider->Value * 100) / 255;
	this->brightnessValue->Text = System::Convert::ToString(percentage);
}

System::Void ImageProcessor::MyForm::brightnessValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {
	if (e->KeyCode == Keys::Enter) {
		double brightnessVal;
		if (System::Double::TryParse(this->brightnessValue->Text, brightnessVal)) {
			this->brightnessSlider->Value = (int)((brightnessVal * 255) / 100);
			brightnessSlider_ValueChange();
		}
	}
}

System::Void ImageProcessor::MyForm::brightnessTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
	brightnessSlider_ValueChange();
}

System::Void ImageProcessor::MyForm::brightnessSlider_ValueChange() {
	System::Drawing::Bitmap^ tempBitmap = changes->bitmapPeek();
	float finalValue = (float)this->brightnessSlider->Value / 255.0f;
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(tempBitmap->Width, tempBitmap->Height);

	System::Drawing::Graphics^ newGraphics = System::Drawing::Graphics::FromImage(newBitmap);
	System::Drawing::Imaging::ColorMatrix^ colorMatrix = gcnew System::Drawing::Imaging::ColorMatrix();

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

	// [ finalValue ] [ finalValue ] [ finalValue ] [ 1 ] [ 1 ]
	colorMatrix->Matrix40 = finalValue;
	colorMatrix->Matrix41 = finalValue;
	colorMatrix->Matrix42 = finalValue;
	colorMatrix->Matrix43 = 1;
	colorMatrix->Matrix44 = 1;

	//     [ 1 ]		  [ 0 ]			[ 0 ]		[ 0 ] [ 0 ]
	//     [ 0 ]		  [ 1 ]			[ 0 ]		[ 0 ] [ 0 ]
	//     [ 0 ]		  [ 0 ]			[ 1 ]		[ 0 ] [ 0 ]
	//	   [ 0 ]		  [ 0 ]			[ 0 ]		[ 1 ] [ 0 ]
	// [ finalValue ] [ finalValue ] [ finalValue ] [ 1 ] [ 1 ]
	// Matrix which will manipulate the brightness of the image

	System::Drawing::Imaging::ImageAttributes^ attributes = gcnew System::Drawing::Imaging::ImageAttributes();
	attributes->SetColorMatrix(colorMatrix);
	newGraphics->DrawImage(tempBitmap, Rectangle(0, 0, tempBitmap->Width, tempBitmap->Height), 0, 0, tempBitmap->Width, tempBitmap->Height, GraphicsUnit::Pixel, attributes);
	currentImage->Image = newBitmap;
}