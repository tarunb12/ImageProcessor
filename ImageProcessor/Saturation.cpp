#include "MyForm.h"

System::Void ImageProcessor::MyForm::saturationSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->saturationTimer->Enabled = true;
}

System::Void ImageProcessor::MyForm::saturationSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->saturationTimer->Enabled = false;
	this->saturationTimer->Enabled = true;
	this->saturationTimer->Enabled = false;
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	changes->push(bitmap);
}

System::Void ImageProcessor::MyForm::saturationSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	int percentage = (this->saturationSlider->Value * 100) / 255;
	this->saturationValue->Text = System::Convert::ToString(percentage);
}

System::Void ImageProcessor::MyForm::saturationValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {
	if (e->KeyCode == Keys::Enter) {
		int saturationVal;
		if (System::Int32::TryParse(this->saturationValue->Text, saturationVal)) {
			if (saturationVal > 100) {
				this->saturationSlider->Value = 255;
			}
			else if (saturationVal < -100) {
				this->saturationSlider->Value = -255;
			}
			else {
				this->saturationSlider->Value = (saturationVal * 255) / 100;
			}
			saturationSlider_ValueChange();
		}
	}
}

System::Void ImageProcessor::MyForm::saturationTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
	saturationSlider_ValueChange();
}


System::Void ImageProcessor::MyForm::saturationSlider_ValueChange() {
	System::Drawing::Bitmap^ tempBitmap = changes->bitmapPeek();
	// float saturation = (float)(((this->saturationSlider->Value + 255.0f / 255.0f) / 2)); CAN BE THERMAL FILTER

	float saturation = (float)(1 + (this->saturationSlider->Value / 255.0f));
	float rWeight = 0.3086f;
	float gWeight = 0.6094f;
	float bWeight = 0.0820f;

	float x = (1.0f - saturation) * rWeight + saturation;
	float y = (1.0f - saturation) * gWeight + saturation;
	float z = (1.0f - saturation) * bWeight + saturation;
	float r = (1.0f - saturation) * rWeight;
	float g = (1.0f - saturation) * gWeight;
	float b = (1.0f - saturation) * bWeight;

	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(tempBitmap->Width, tempBitmap->Height);
	System::Drawing::Graphics^ newGraphics = System::Drawing::Graphics::FromImage(newBitmap);
	System::Drawing::Imaging::ColorMatrix^ colorMatrix = gcnew System::Drawing::Imaging::ColorMatrix();

	// [ x ] [ r ] [ r ] [ 0 ] [ 0 ]
	colorMatrix->Matrix00 = x;
	colorMatrix->Matrix01 = r;
	colorMatrix->Matrix02 = r;
	colorMatrix->Matrix03 = 0;
	colorMatrix->Matrix04 = 0;

	// [ g ] [ y ] [ g ] [ 0 ] [ 0 ]
	colorMatrix->Matrix10 = g;
	colorMatrix->Matrix11 = y;
	colorMatrix->Matrix12 = g;
	colorMatrix->Matrix13 = 0;
	colorMatrix->Matrix14 = 0;

	// [ b ] [ b ] [ z ] [ 0 ] [ 0 ]
	colorMatrix->Matrix20 = b;
	colorMatrix->Matrix21 = b;
	colorMatrix->Matrix22 = z;
	colorMatrix->Matrix23 = 0;
	colorMatrix->Matrix24 = 0;

	// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
	colorMatrix->Matrix30 = 0;
	colorMatrix->Matrix31 = 0;
	colorMatrix->Matrix32 = 0;
	colorMatrix->Matrix33 = 1;
	colorMatrix->Matrix34 = 0;

	// [ 0 ] [ 0 ] [ 0 ] [ 0 ] [ 1 ]
	colorMatrix->Matrix40 = 0;
	colorMatrix->Matrix41 = 0;
	colorMatrix->Matrix42 = 0;
	colorMatrix->Matrix43 = 0;
	colorMatrix->Matrix44 = 1;

	// [ x ] [ r ] [ r ] [ 0 ] [ 0 ]
	// [ g ] [ y ] [ g ] [ 0 ] [ 0 ]
	// [ b ] [ b ] [ z ] [ 0 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 0 ] [ 1 ]
	// Matrix which will manipulate the saturation of the image

	System::Drawing::Imaging::ImageAttributes^ attributes = gcnew System::Drawing::Imaging::ImageAttributes();
	attributes->SetColorMatrix(colorMatrix);
	newGraphics->DrawImage(tempBitmap, Rectangle(0, 0, tempBitmap->Width, tempBitmap->Height), 0, 0, tempBitmap->Width, tempBitmap->Height, GraphicsUnit::Pixel, attributes);
	currentImage->Image = newBitmap;
}