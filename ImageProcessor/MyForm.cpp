#include <iostream>

#include "MyForm.h"
#include "ImageOrientation.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ImageProcessor::MyForm form;
	form.StartPosition = FormStartPosition::CenterScreen;
	form.WindowState = FormWindowState::Maximized;
	Application::Run(%form);
}

System::Void ImageProcessor::MyForm::updatePictureBox(System::Drawing::Bitmap^ newBitmap) {
	currentImage->Image = newBitmap;
}

System::Void ImageProcessor::MyForm::uploadImage_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::OpenFileDialog^ Open = gcnew System::Windows::Forms::OpenFileDialog();
	Open->Title = "Open Image File";
	Open->Filter = "Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.PNG";
	Open->FilterIndex = 1;
	currentImage->SizeMode = PictureBoxSizeMode::Zoom;
	currentImage->MaximumSize = System::Drawing::Size(1671, 1108);
	Bitmap^ bitmap;

	if (Open->ShowDialog() == ::DialogResult::OK) {
		bitmap = gcnew Bitmap(System::Drawing::Bitmap::FromFile(Open->FileName));
		currentImage->Image = bitmap;
	}
}

System::Void ImageProcessor::MyForm::saveImage_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::rotateImage_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::mirrorImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		this->hMirror->Show();
		this->vMirror->Show();
	}
}

System::Void ImageProcessor::MyForm::hMirror_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::vMirror_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::cropImage_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::resizeImage_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::invertImage_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::grayscaleImage_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::imageBrightness_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void ImageProcessor::MyForm::imageContrast_Click(System::Object^  sender, System::EventArgs^  e) {

}