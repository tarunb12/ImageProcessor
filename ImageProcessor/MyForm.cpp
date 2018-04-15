#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ImageProcessor::MyForm form;
	Application::Run(%form);
}

System::Void ImageProcessor::MyForm::uploadImage_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::OpenFileDialog^ Open = gcnew System::Windows::Forms::OpenFileDialog();
	Open->Title = "Open Image File";
	Open->Filter = "Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.PNG";
	Open->FilterIndex = 1;
	currentImage->MaximumSize = System::Drawing::Size(1671, 1108);

	if (Open->ShowDialog() == ::DialogResult::OK) {
		Bitmap^ bitmap = gcnew Bitmap(System::Drawing::Bitmap::FromFile(Open->FileName));
		currentImage->Image = bitmap;
	}
	
	
	
	/*
	Open->ShowDialog();
	currentImage->ImageLocation = Open->FileName;
	currentImage->MaximumSize = System::Drawing::Size(1671, 1108);
	*/
}

System::Void ImageProcessor::MyForm::updatePictureBox(System::Drawing::Bitmap^ newBitmap) {
	currentImage->Image = newBitmap;
}