#include "MyForm.h"

System::Void ImageProcessor::MyForm::contrastSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->contrastTimer->Enabled;

}

System::Void ImageProcessor::MyForm::contrastSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->contrastTimer->Enabled = false;
	this->contrastTimer->Enabled = true;
	this->contrastTimer->Enabled = false;
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	changes->push(bitmap);
}

System::Void ImageProcessor::MyForm::contrastSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::contrastValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {
	if (e->KeyCode == Keys::Enter) {
		double contrastVal;
		if (System::Double::TryParse(this->contrastValue->Text, contrastVal)) {

			contrastSlider_ValueChange();
		}
	}
}

System::Void ImageProcessor::MyForm::contrastTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
	contrastSlider_ValueChange();
}

System::Void ImageProcessor::MyForm::contrastSlider_ValueChange() {

}