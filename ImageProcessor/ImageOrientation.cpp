#include "MyForm.h";

System::Void ImageProcessor::MyForm::hMirror_Click(System::Object^  sender, System::EventArgs^  e) { // horizontal mirror method
	this->undoChange->Show(); // resets undo
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	changed->push(bitmap);
	bitmap->RotateFlip(RotateFlipType::RotateNoneFlipX); // flip x built in function
	currentImage->Image = bitmap; // current image set to new bitmap
}

System::Void ImageProcessor::MyForm::vMirror_Click(System::Object^  sender, System::EventArgs^  e) { // vertical mirror method
	this->undoChange->Show(); // resets undo
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	changed->push(bitmap);
	bitmap->RotateFlip(RotateFlipType::RotateNoneFlipY); // flip y built in function
	currentImage->Image = bitmap; // current image set to new bitmap
}

System::Void ImageProcessor::MyForm::rotateC_Click(System::Object^  sender, System::EventArgs^  e) { // rotate clockwise method
	this->undoChange->Show(); // resets undo
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	changed->push(bitmap);
	bitmap->RotateFlip(RotateFlipType::Rotate90FlipNone); // rotate 90
	currentImage->Image = bitmap; // current image set to new bitmap
}

System::Void ImageProcessor::MyForm::rotateCC_Click(System::Object^  sender, System::EventArgs^  e) { // rotate counterclockwise method
	this->undoChange->Show(); // resets undo
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
	changed->push(bitmap);
	bitmap->RotateFlip(RotateFlipType::Rotate270FlipNone); // rotate 270 (-90)
	currentImage->Image = bitmap; // current image set to new bitmap
}
