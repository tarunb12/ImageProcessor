#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//85, 880

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ImageProcessor::MyForm form;
	form.FormBorderStyle = FormBorderStyle::FixedSingle;
	form.Size = System::Drawing::Size(1000, 600);
	form.MaximizeBox = false;
	form.MinimizeBox = false;
	Application::Run(%form);
}

System::Void ImageProcessor::MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	hideTempObjects();
}

System::Void ImageProcessor::MyForm::uploadImage_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::OpenFileDialog^ Open = gcnew System::Windows::Forms::OpenFileDialog();
	Open->Title = "Open Image File";
	Open->Filter = "Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG";
	Open->FilterIndex = 1;
	currentImage->MaximumSize = System::Drawing::Size(1671, 1108);
	Bitmap^ bitmap;
	if (Open->ShowDialog() == ::DialogResult::OK) {
		bitmap = gcnew Bitmap(System::Drawing::Bitmap::FromFile(Open->FileName));
		currentImage->Image = bitmap;
	}
}

System::Void ImageProcessor::MyForm::saveImage_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::SaveFileDialog^ SaveFile = gcnew System::Windows::Forms::SaveFileDialog();
	SaveFile->Title = "Save Image";
	SaveFile->Filter = "Image Files(*.JPG;*.PNG;*.BMP;)|*.JPG;*.PNG;*.BMP;";
	SaveFile->FilterIndex = 1;
	SaveFile->DefaultExt = "JPG";
	SaveFile->RestoreDirectory = true;	
	if (SaveFile->ShowDialog() == ::DialogResult::OK) {
		System::Drawing::Imaging::ImageFormat^ format;
		System::String^ systExt = System::IO::Path::GetExtension(SaveFile->FileName);
		if (systExt == "JPG") {
			format = System::Drawing::Imaging::ImageFormat::Jpeg;
		}
		else if (systExt == "PNG") {
			format = System::Drawing::Imaging::ImageFormat::Png;
		}
		else if (systExt == "BMP") {
			format = System::Drawing::Imaging::ImageFormat::Bmp;
		}
		else {
			format = System::Drawing::Imaging::ImageFormat::Jpeg;
		}
		currentImage->Image->Save(SaveFile->FileName, format);
	}
}

System::Void ImageProcessor::MyForm::hideTempObjects() {
	this->hMirror->Hide();
	this->vMirror->Hide();
	this->rotateC->Hide();
	this->rotateCC->Hide();
}

System::Void ImageProcessor::MyForm::rotateImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		hideTempObjects();
		this->rotateC->Show();
		this->rotateCC->Show();
	}
}

System::Void ImageProcessor::MyForm::mirrorImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		hideTempObjects();
		this->hMirror->Show();
		this->vMirror->Show();
	}
}

System::Void ImageProcessor::MyForm::cropImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		hideTempObjects();
	}
}

System::Void ImageProcessor::MyForm::resizeImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		hideTempObjects();
	}
}

System::Void ImageProcessor::MyForm::invertImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		hideTempObjects();
		invertCurrentImage();
	}
}

System::Void ImageProcessor::MyForm::grayscaleImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		hideTempObjects();
		grayscaleCurrentImage();
	}
}

System::Void ImageProcessor::MyForm::imageBrightness_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		hideTempObjects();
	}
}

System::Void ImageProcessor::MyForm::imageContrast_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		hideTempObjects();
	}
}