#include "MyForm.h"

System::Void ImageProcessor::MyForm::blackWhiteFilter_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Drawing::Bitmap^ tempBitmap = gcnew Bitmap(currentImage->Image);
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(tempBitmap->Width, tempBitmap->Height);
	System::Drawing::Graphics^ newGraphics = System::Drawing::Graphics::FromImage(newBitmap);
	System::Drawing::Imaging::ColorMatrix^ colorMatrix = gcnew System::Drawing::Imaging::ColorMatrix();

	float a = 0.299f;
	float b = 0.587f;
	float c = 0.114f;

	// [ a ] [ a ] [ a ] [ 0 ] [ 0 ]
	colorMatrix->Matrix00 = a;
	colorMatrix->Matrix01 = a;
	colorMatrix->Matrix02 = a;
	colorMatrix->Matrix03 = 0;
	colorMatrix->Matrix04 = 0;

	// [ b ] [ b ] [ b ] [ 0 ] [ 0 ]
	colorMatrix->Matrix10 = b;
	colorMatrix->Matrix11 = b;
	colorMatrix->Matrix12 = b;
	colorMatrix->Matrix13 = 0;
	colorMatrix->Matrix14 = 0;

	// [ c ] [ c ] [ c ] [ 0 ] [ 0 ]
	colorMatrix->Matrix20 = c;
	colorMatrix->Matrix21 = c;
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

	// [ a ] [ a ] [ a ] [ 0 ] [ 0 ]
	// [ b ] [ b ] [ b ] [ 0 ] [ 0 ]
	// [ 0 ] [ c ] [ c ] [ 0 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 0 ] [ 1 ]
	// Matrix which will make the image black and white

	System::Drawing::Imaging::ImageAttributes^ attributes = gcnew System::Drawing::Imaging::ImageAttributes();
	attributes->SetThreshold(0.5);
	attributes->SetColorMatrix(colorMatrix);
	newGraphics->DrawImage(tempBitmap, Rectangle(0, 0, tempBitmap->Width, tempBitmap->Height), 0, 0, tempBitmap->Width, tempBitmap->Height, GraphicsUnit::Pixel, attributes);
	changes->push(newBitmap);
	currentImage->Image = newBitmap;
}

System::Void ImageProcessor::MyForm::sepiaFilter_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Drawing::Bitmap^ tempBitmap = gcnew Bitmap(currentImage->Image);
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(tempBitmap->Width, tempBitmap->Height);
	System::Drawing::Graphics^ newGraphics = System::Drawing::Graphics::FromImage(newBitmap);
	System::Drawing::Imaging::ColorMatrix^ colorMatrix = gcnew System::Drawing::Imaging::ColorMatrix();

	float a = 0.393f;
	float b = 0.349f;
	float c = 0.272f;
	float d = 0.769f;
	float f = 0.686f;
	float g = 0.534f;
	float h = 0.189f;
	float i = 0.168f;
	float j = 0.131f;

	// [ a ] [ b ] [ c ] [ 0 ] [ 0 ]
	colorMatrix->Matrix00 = a;
	colorMatrix->Matrix01 = b;
	colorMatrix->Matrix02 = c;
	colorMatrix->Matrix03 = 0;
	colorMatrix->Matrix04 = 0;

	// [ d ] [ f ] [ g ] [ 0 ] [ 0 ]
	colorMatrix->Matrix10 = d;
	colorMatrix->Matrix11 = f;
	colorMatrix->Matrix12 = g;
	colorMatrix->Matrix13 = 0;
	colorMatrix->Matrix14 = 0;

	// [ h ] [ i ] [ j ] [ 0 ] [ 0 ]
	colorMatrix->Matrix20 = h;
	colorMatrix->Matrix21 = i;
	colorMatrix->Matrix22 = j;
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

	// [ a ] [ b ] [ c ] [ 0 ] [ 0 ]
	// [ d ] [ f ] [ g ] [ 0 ] [ 0 ]
	// [ h ] [ h ] [ j ] [ 0 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 0 ] [ 1 ]
	// Matrix which will make the have a sepia filter

	System::Drawing::Imaging::ImageAttributes^ attributes = gcnew System::Drawing::Imaging::ImageAttributes();
	attributes->SetColorMatrix(colorMatrix);
	newGraphics->DrawImage(tempBitmap, Rectangle(0, 0, tempBitmap->Width, tempBitmap->Height), 0, 0, tempBitmap->Width, tempBitmap->Height, GraphicsUnit::Pixel, attributes);
	changes->push(newBitmap);
	currentImage->Image = newBitmap;
}

System::Void ImageProcessor::MyForm::rgbToBgr_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Drawing::Bitmap^ tempBitmap = gcnew Bitmap(currentImage->Image);
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(tempBitmap->Width, tempBitmap->Height);
	System::Drawing::Graphics^ newGraphics = System::Drawing::Graphics::FromImage(newBitmap);
	System::Drawing::Imaging::ColorMatrix^ colorMatrix = gcnew System::Drawing::Imaging::ColorMatrix();


	// [ 0 ] [ 0 ] [ 1 ] [ 0 ] [ 0 ]
	colorMatrix->Matrix00 = 0;
	colorMatrix->Matrix01 = 0;
	colorMatrix->Matrix02 = 1;
	colorMatrix->Matrix03 = 0;
	colorMatrix->Matrix04 = 0;

	// [ 0 ] [ 1 ] [ 0 ] [ 0 ] [ 0 ]
	colorMatrix->Matrix10 = 0;
	colorMatrix->Matrix11 = 1;
	colorMatrix->Matrix12 = 0;
	colorMatrix->Matrix13 = 0;
	colorMatrix->Matrix14 = 0;

	// [ 1 ] [ 0 ] [ 0 ] [ 0 ] [ 0 ]
	colorMatrix->Matrix20 = 1;
	colorMatrix->Matrix21 = 0;
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

	// [ 0 ] [ 0 ] [ 1 ] [ 0 ] [ 0 ]
	// [ 0 ] [ 1 ] [ 0 ] [ 0 ] [ 0 ]
	// [ 1 ] [ 0 ] [ 0 ] [ 0 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 1 ] [ 0 ]
	// [ 0 ] [ 0 ] [ 0 ] [ 0 ] [ 1 ]
	// Matrix which will make the have a sepia filter

	System::Drawing::Imaging::ImageAttributes^ attributes = gcnew System::Drawing::Imaging::ImageAttributes();
	attributes->SetColorMatrix(colorMatrix);
	newGraphics->DrawImage(tempBitmap, Rectangle(0, 0, tempBitmap->Width, tempBitmap->Height), 0, 0, tempBitmap->Width, tempBitmap->Height, GraphicsUnit::Pixel, attributes);
	changes->push(newBitmap);
	currentImage->Image = newBitmap;
}