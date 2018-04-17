#include "MyForm.h"

System::Void ImageProcessor::MyForm::hueSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	changes->push(bitmap);
	this->hueTimer->Enabled = true;
}

System::Void ImageProcessor::MyForm::hueSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->hueTimer->Enabled = false;
	this->hueTimer->Enabled = true;
	this->hueTimer->Enabled = false;
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	changes->push(bitmap);
}

System::Void ImageProcessor::MyForm::hueSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::hueValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {

}

System::Void ImageProcessor::MyForm::hueTimer_Tick(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::hueSlider_ValueChange() {

}