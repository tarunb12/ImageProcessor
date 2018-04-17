#include "MyForm.h"

System::Void ImageProcessor::MyForm::contrastSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->contrastTimer->Enabled = true;
}

System::Void ImageProcessor::MyForm::contrastSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->contrastTimer->Enabled = false;
	this->contrastTimer->Enabled = true;
	this->contrastTimer->Enabled = false;
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	changes->push(bitmap);
}

System::Void ImageProcessor::MyForm::contrastSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	int percentage = this->contrastSlider->Value;
	this->contrastValue->Text = System::Convert::ToString(percentage);
}

System::Void ImageProcessor::MyForm::contrastValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {
	if (e->KeyCode == Keys::Enter) {
		double contrastVal;
		if (System::Double::TryParse(this->contrastValue->Text, contrastVal)) {
			this->contrastSlider->Value = (int)contrastVal;
			contrastSlider_ValueChange();
		}
	}
}

System::Void ImageProcessor::MyForm::contrastTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
	contrastSlider_ValueChange();
}

System::Void ImageProcessor::MyForm::contrastSlider_ValueChange() {
	System::Drawing::Bitmap^ tempBitmap = changes->bitmapPeek();
	float c = (float)(1.0f + (this->contrastSlider->Value / 100.0f));
	float t = 0.5f * (1.0f - c);
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(tempBitmap->Width, tempBitmap->Height);

	System::Drawing::Graphics^ newGraphics = System::Drawing::Graphics::FromImage(newBitmap);
	System::Drawing::Imaging::ColorMatrix^ colorMatrix = gcnew System::Drawing::Imaging::ColorMatrix();

	// [ c ] [ 0 ] [ 0 ] [ 0 ] [ 0 ]
	colorMatrix->Matrix00 = c;
	colorMatrix->Matrix01 = 0;
	colorMatrix->Matrix02 = 0;
	colorMatrix->Matrix03 = 0;
	colorMatrix->Matrix04 = 0;

	// [ 0 ] [ c ] [ 0 ] [ 0 ] [ 0 ]
	colorMatrix->Matrix10 = 0;
	colorMatrix->Matrix11 = c;
	colorMatrix->Matrix12 = 0;
	colorMatrix->Matrix13 = 0;
	colorMatrix->Matrix14 = 0;

	// [ 0 ] [ 0 ] [ c ] [ 0 ] [ 0 ]
	colorMatrix->Matrix20 = 0;
	colorMatrix->Matrix21 = 0;
	colorMatrix->Matrix22 = c;
	colorMatrix->Matrix23 = 0;
	colorMatrix->Matrix24 = 0;

	// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
	colorMatrix->Matrix30 = 0;
	colorMatrix->Matrix31 = 0;
	colorMatrix->Matrix32 = 0;
	colorMatrix->Matrix33 = 1;
	colorMatrix->Matrix34 = 0;

	// [ t ] [ t ] [ t ] [ 0 ] [ 1 ]
	colorMatrix->Matrix40 = t;
	colorMatrix->Matrix41 = t;
	colorMatrix->Matrix42 = t;
	colorMatrix->Matrix43 = 1;
	colorMatrix->Matrix44 = 1;

	// [ c ] [ 0 ] [ 0 ] [ 0 ] [ 0 ]
	// [ 0 ] [ c ] [ 0 ] [ 0 ] [ 0 ]
	// [ 0 ] [ 0 ] [ c ] [ 0 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
	// [ t ] [ t ] [ t ] [ 1 ] [ 1 ]
	// Matrix which will manipulate the contrast of the image

	System::Drawing::Imaging::ImageAttributes^ attributes = gcnew System::Drawing::Imaging::ImageAttributes();
	attributes->SetColorMatrix(colorMatrix);
	newGraphics->DrawImage(tempBitmap, Rectangle(0, 0, tempBitmap->Width, tempBitmap->Height), 0, 0, tempBitmap->Width, tempBitmap->Height, GraphicsUnit::Pixel, attributes);
	currentImage->Image = newBitmap;
}