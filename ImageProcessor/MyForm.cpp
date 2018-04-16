#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//85, 880

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ImageProcessor::MyForm form; // new windows form object
	form.FormBorderStyle = FormBorderStyle::FixedSingle; // makes window non resizable
	form.Size = System::Drawing::Size(1000, 600); // sets size of the window form
	form.MaximizeBox = false; // makes window non maximizable
	form.MinimizeBox = false; // makes window non minimizable
	Application::Run(%form);
}

System::Void ImageProcessor::MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e) { // loads when form initially launches
	hideTempObjects(); // hides temp objects on initial form launch
}

System::Void ImageProcessor::MyForm::uploadImage_Click(System::Object^  sender, System::EventArgs^  e) { // upload image clicked
	System::Windows::Forms::OpenFileDialog^ Open = gcnew System::Windows::Forms::OpenFileDialog(); // new open file dialog object
	Open->Title = "Open Image File"; // open file window name
	Open->Filter = "Image Files(*.jpg;*.png;*.gif;*.tiff;*.bmp;)|*.jpg;*.png;*.gif;*.tiff;*.bmp"; // all valid file types
	Open->FilterIndex = 1; // sets filter
	currentImage->MaximumSize = System::Drawing::Size(1671, 1108); // max size of the  picture box
	Bitmap^ bitmap; // bitmap object to put in picturebox
	if (Open->ShowDialog() == ::DialogResult::OK) { // checks if "Open" clicked on valid image
		bitmap = gcnew Bitmap(System::Drawing::Bitmap::FromFile(Open->FileName)); // new bitmap from filename (filename is full path, ex. C:\User\Pictures\Image)
		currentImage->Image = bitmap; // sets current image in picture box to the above bitmap
	}
}

System::Void ImageProcessor::MyForm::saveImage_Click(System::Object^  sender, System::EventArgs^  e) { // save image clicked
	System::Windows::Forms::SaveFileDialog^ SaveFile = gcnew System::Windows::Forms::SaveFileDialog(); // save file dialog object
	SaveFile->Title = "Save Image File"; // save file window name
	SaveFile->Filter = "JPEG Image | *.jpg | PNG Image | *.png | GIF Image | *.gif | TIFF Image | *.tiff | Bitmap Image | *.bmp"; // all savable image types
	SaveFile->ShowDialog(); // reveals save file dialog
	if (SaveFile->FileName != "") { // checks if filename not empty
		System::IO::FileStream^ filestream = safe_cast<System::IO::FileStream^>(SaveFile->OpenFile()); // filestream to save images
		switch (SaveFile->FilterIndex) { // looks at filter index to determine selected file type
			case 1:
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Jpeg); // save image as jpeg
				break;

			case 2:
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Png); // save image as png
				break;

			case 3:
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Gif); // save image as gif
				break;

			case 4:
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Tiff); // save image as tiff
				break;

			case 5:
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Bmp); // save image as bitmap
				break;

			default:
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Jpeg); // default to jpeg
				break;
		}
	}
}

System::Void ImageProcessor::MyForm::hideTempObjects() { // hides all object not displayed on initial launch
	this->hMirror->Hide();
	this->vMirror->Hide();
	this->rotateC->Hide();
	this->rotateCC->Hide();
}

System::Void ImageProcessor::MyForm::undoChange_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		hideTempObjects();
		currentImage->Image = previousBitmap;
		this->undoChange->Hide();
	}
}

System::Void ImageProcessor::MyForm::rotateImage_Click(System::Object^  sender, System::EventArgs^  e) { // reveal rotate clockwise/counterclockwise buttons
	if (currentImage->Image) {
		hideTempObjects();
		this->rotateC->Show();
		this->rotateCC->Show();
	}
}

System::Void ImageProcessor::MyForm::mirrorImage_Click(System::Object^  sender, System::EventArgs^  e) { // reveal horizontal/vertical mirror image buttons
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

System::Void ImageProcessor::MyForm::invertImage_Click(System::Object^  sender, System::EventArgs^  e) { // calls invert image method (Coloring.cpp)
	if (currentImage->Image) {
		hideTempObjects();
		invertCurrentImage();
	}
}

System::Void ImageProcessor::MyForm::grayscaleImage_Click(System::Object^  sender, System::EventArgs^  e) { // calls grayscale image method (Coloring.cpp)
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