#include <cmath>

#include "MyForm.h"

System::Void ImageProcessor::MyForm::hueSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->hueTimer->Enabled = true;
}

System::Void ImageProcessor::MyForm::hueSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->hueTimer->Enabled = false;
	this->hueTimer->Enabled = true;
	this->hueTimer->Enabled = false;
}

System::Void ImageProcessor::MyForm::hueSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	int degrees = this->hueSlider->Value;
	this->hueValue->Text = System::Convert::ToString(degrees);
}

System::Void ImageProcessor::MyForm::hueValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {
	if (e->KeyCode == Keys::Enter) {
		int hueVal;
		if (System::Int32::TryParse(this->hueValue->Text, hueVal)) {
			int newVal = hueVal;
			if (hueVal > 360) {
				while (newVal > 360) {
					newVal -= 360;
				}
				hueVal = newVal;
			}
			else if (hueVal < 0) {
				while (newVal < 0) {
					newVal += 360;
				}
				hueVal = newVal;
			}
			this->hueValue->Text = System::Convert::ToString(hueVal);
			this->hueSlider->Value = hueVal;
			hueSlider_ValueChange();
		}
	}
}

System::Void ImageProcessor::MyForm::hueTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
	hueSlider_ValueChange();
}

System::Void ImageProcessor::MyForm::hueSlider_ValueChange() {
	System::Drawing::Bitmap^ tempBitmap = changes->bitmapPeek();

	const float wedge = 120.0f / 360;
	float degrees = (float)this->hueSlider->Value;
	float value = degrees / 360;
	float hueDegree = (float)std::fmod((-1.0f * value), 1);
	if (hueDegree < 1) {
		hueDegree++;
	}

	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(tempBitmap->Width, tempBitmap->Height);
	System::Drawing::Graphics^ newGraphics = System::Drawing::Graphics::FromImage(newBitmap);
	System::Drawing::Imaging::ColorMatrix^ colorMatrix = gcnew System::Drawing::Imaging::ColorMatrix();

	if (hueDegree <= wedge) {
		float theta = (float)((hueDegree / wedge) * (Math::PI / 2));
		float c = (float)Math::Cos(theta);
		float s = (float)Math::Sin(theta);

		// [ c ] [ 0 ] [ s ] [ 0 ] [ 0 ]
		colorMatrix->Matrix00 = c;
		colorMatrix->Matrix01 = 0;
		colorMatrix->Matrix02 = s;
		colorMatrix->Matrix03 = 0;
		colorMatrix->Matrix04 = 0;

		// [ s ] [ c ] [ 0 ] [ 0 ] [ 0 ]
		colorMatrix->Matrix10 = s;
		colorMatrix->Matrix11 = c;
		colorMatrix->Matrix12 = 0;
		colorMatrix->Matrix13 = 0;
		colorMatrix->Matrix14 = 0;

		// [ 0 ] [ s ] [ c ] [ 0 ] [ 0 ]
		colorMatrix->Matrix20 = 0;
		colorMatrix->Matrix21 = s;
		colorMatrix->Matrix22 = c;
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

		// [ c ] [ 0 ] [ s ] [ 0 ] [ 0 ]
		// [ s ] [ c ] [ 0 ] [ 0 ] [ 0 ]
		// [ 0 ] [ s ] [ c ] [ 0 ] [ 0 ]
		// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
		// [ 0 ] [ 0 ] [ 0 ] [ 0 ] [ 1 ]
		// Matrix which will manipulate the hue of the image
	}
	else if (hueDegree <= wedge * 2) {
		float theta = (float)(((hueDegree - wedge) / wedge) * (Math::PI / 2));
		float c = (float)Math::Cos(theta);
		float s = (float)Math::Sin(theta);

		// [ 0 ] [ s ] [ c ] [ 0 ] [ 0 ]
		colorMatrix->Matrix00 = 0;
		colorMatrix->Matrix01 = s;
		colorMatrix->Matrix02 = c;
		colorMatrix->Matrix03 = 0;
		colorMatrix->Matrix04 = 0;

		// [ c ] [ 0 ] [ s ] [ 0 ] [ 0 ]
		colorMatrix->Matrix10 = s;
		colorMatrix->Matrix11 = c;
		colorMatrix->Matrix12 = 0;
		colorMatrix->Matrix13 = 0;
		colorMatrix->Matrix14 = 0;

		// [ s ] [ c ] [ 0 ] [ 0 ] [ 0 ]
		colorMatrix->Matrix20 = s;
		colorMatrix->Matrix21 = c;
		colorMatrix->Matrix22 = 0;
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

		// [ 0 ] [ s ] [ c ] [ 0 ] [ 0 ]
		// [ c ] [ 0 ] [ s ] [ 0 ] [ 0 ]
		// [ s ] [ c ] [ 0 ] [ 0 ] [ 0 ]
		// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
		// [ 0 ] [ 0 ] [ 0 ] [ 0 ] [ 1 ]
		// Matrix which will manipulate the hue of the image
	}
	else {
		float theta = (float)(((hueDegree - (2 * wedge)) / wedge) * (Math::PI / 2));
		float c = (float)Math::Cos(theta);
		float s = (float)Math::Sin(theta);

		// [ s ] [ c ] [ 0 ] [ 0 ] [ 0 ]
		colorMatrix->Matrix00 = s;
		colorMatrix->Matrix01 = c;
		colorMatrix->Matrix02 = 0;
		colorMatrix->Matrix03 = 0;
		colorMatrix->Matrix04 = 0;

		// [ 0 ] [ s ] [ c ] [ 0 ] [ 0 ]
		colorMatrix->Matrix10 = 0;
		colorMatrix->Matrix11 = s;
		colorMatrix->Matrix12 = c;
		colorMatrix->Matrix13 = 0;
		colorMatrix->Matrix14 = 0;

		// [ c ] [ 0 ] [ s ] [ 0 ] [ 0 ]
		colorMatrix->Matrix20 = c;
		colorMatrix->Matrix21 = 0;
		colorMatrix->Matrix22 = s;
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

		// [ c ] [ 0 ] [ s ] [ 0 ] [ 0 ]
		// [ s ] [ c ] [ 0 ] [ 0 ] [ 0 ]
		// [ 0 ] [ s ] [ c ] [ 0 ] [ 0 ]
		// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
		// [ 0 ] [ 0 ] [ 0 ] [ 0 ] [ 1 ]
		// Matrix which will manipulate the hue of the image
	}

	System::Drawing::Imaging::ImageAttributes^ attributes = gcnew System::Drawing::Imaging::ImageAttributes();
	attributes->SetColorMatrix(colorMatrix);
	newGraphics->DrawImage(tempBitmap, Rectangle(0, 0, tempBitmap->Width, tempBitmap->Height), 0, 0, tempBitmap->Width, tempBitmap->Height, GraphicsUnit::Pixel, attributes);
	currentImage->Image = newBitmap;
}