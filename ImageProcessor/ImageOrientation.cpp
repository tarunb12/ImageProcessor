#include "MyForm.h";

using namespace System;
using namespace System::Windows::Forms;

System::Void ImageProcessor::MyForm::hMirror_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(currentImage->Image);
	newBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);
	currentImage->Image = newBitmap;
}

System::Void ImageProcessor::MyForm::vMirror_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(currentImage->Image);
	newBitmap->RotateFlip(RotateFlipType::RotateNoneFlipY);
	currentImage->Image = newBitmap;
}