#include "MyForm.h";

System::Void ImageProcessor::MyForm::hMirror_Click(System::Object^  sender, System::EventArgs^  e) { // horizontal mirror method
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // image before being changed
	changes->push(bitmap); // push pre-change bitmap
	System::Drawing::Bitmap^ changedBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	changedBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX); // flip x built in function
	currentImage->Image = changedBitmap; // current image set to new bitmap
}

System::Void ImageProcessor::MyForm::vMirror_Click(System::Object^  sender, System::EventArgs^  e) { // vertical mirror method
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // image before being changed
	changes->push(bitmap); // push pre-change bitmap
	System::Drawing::Bitmap^ changedBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	changedBitmap->RotateFlip(RotateFlipType::RotateNoneFlipY); // flip y built in function
	currentImage->Image = changedBitmap; // current image set to new bitmap
}

System::Void ImageProcessor::MyForm::rotateC_Click(System::Object^  sender, System::EventArgs^  e) { // rotate clockwise method
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // image before being changed
	changes->push(bitmap); // push pre-change bitmap
	System::Drawing::Bitmap^ changedBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	changedBitmap->RotateFlip(RotateFlipType::Rotate90FlipNone); // rotate 90°
	currentImage->Image = changedBitmap; // current image set to new bitmap
}

System::Void ImageProcessor::MyForm::rotateCC_Click(System::Object^  sender, System::EventArgs^  e) { // rotate counterclockwise method
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // image before being changed
	changes->push(bitmap); // push pre-change bitmap
	System::Drawing::Bitmap^ changedBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	changedBitmap->RotateFlip(RotateFlipType::Rotate270FlipNone); // rotate 270° (-90°)
	currentImage->Image = changedBitmap; // current image set to new bitmap
}