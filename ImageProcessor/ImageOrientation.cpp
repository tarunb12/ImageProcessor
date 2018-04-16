#include "MyForm.h";

using namespace System;
using namespace System::Windows::Forms;

System::Void ImageProcessor::MyForm::hMirror_Click(System::Object^  sender, System::EventArgs^  e) { // horizontal mirror method
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	newBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX); // flip x built in function
	currentImage->Image = newBitmap; // current image set to new bitmap
}

System::Void ImageProcessor::MyForm::vMirror_Click(System::Object^  sender, System::EventArgs^  e) { // vertical mirror method
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	newBitmap->RotateFlip(RotateFlipType::RotateNoneFlipY); // flip y built in function
	currentImage->Image = newBitmap; // current image set to new bitmap
}

System::Void ImageProcessor::MyForm::rotateC_Click(System::Object^  sender, System::EventArgs^  e) { // rotate clockwise method
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	newBitmap->RotateFlip(RotateFlipType::Rotate90FlipNone); // rotate 90�
	currentImage->Image = newBitmap; // current image set to new bitmap
}

System::Void ImageProcessor::MyForm::rotateCC_Click(System::Object^  sender, System::EventArgs^  e) { // rotate counterclockwise method
	System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	newBitmap->RotateFlip(RotateFlipType::Rotate270FlipNone); // rotate 270� (-90�)
	currentImage->Image = newBitmap; // current image set to new bitmap
}