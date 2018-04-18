#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

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

	this->brightnessSlider->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::brightnessSlider_MouseUp);
	this->brightnessSlider->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::brightnessSlider_MouseDown);
	this->brightnessValue->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MyForm::brightnessValue_KeyDown);

	this->contrastSlider->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::contrastSlider_MouseUp);
	this->contrastSlider->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::contrastSlider_MouseDown);
	this->contrastValue->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MyForm::contrastValue_KeyDown);

	this->saturationSlider->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::saturationSlider_MouseUp);
	this->saturationSlider->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::saturationSlider_MouseDown);
	this->saturationValue->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MyForm::saturationValue_KeyDown);

	this->hueSlider->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hueSlider_MouseUp);
	this->hueSlider->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hueSlider_MouseDown);
	this->hueValue->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MyForm::hueValue_KeyDown);
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
		this->uploadImageLabel->Hide(); // hides initial "Upload New Image" Label
		hideTempObjects();
		while (changes->peek() != nullptr) {
			changes->pop();
		}
	}
}

System::Void ImageProcessor::MyForm::uploadImageLabel_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::OpenFileDialog^ Open = gcnew System::Windows::Forms::OpenFileDialog(); // new open file dialog object
	Open->Title = "Open Image File"; // open file window name
	Open->Filter = "Image Files(*.jpg;*.png;*.gif;*.tiff;*.bmp;)|*.jpg;*.png;*.gif;*.tiff;*.bmp"; // all valid file types
	Open->FilterIndex = 1; // sets filter
	currentImage->MaximumSize = System::Drawing::Size(1671, 1108); // max size of the  picture box
	Bitmap^ bitmap; // bitmap object to put in picturebox
	if (Open->ShowDialog() == ::DialogResult::OK) { // checks if "Open" clicked on valid image
		bitmap = gcnew Bitmap(System::Drawing::Bitmap::FromFile(Open->FileName)); // new bitmap from filename (filename is full path, ex. C:\User\Pictures\Image)
		currentImage->Image = bitmap; // sets current image in picture box to the above bitmap
		this->uploadImageLabel->Hide(); // hides initial "Upload New Image Label"
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
			case 1: // jpeg
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Jpeg); // save image as jpeg
				break;

			case 2: // png
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Png); // save image as png
				break;

			case 3: // gif
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Gif); // save image as gif
				break;

			case 4: // tiff
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Tiff); // save image as tiff
				break;

			case 5: // bitmap
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Bmp); // save image as bitmap
				break;

			default: // jpeg
				currentImage->Image->Save(filestream, System::Drawing::Imaging::ImageFormat::Jpeg); // idk when this would happen
				break;
		}
	}
}

System::Void ImageProcessor::MyForm::currentImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!currentImage->Image) {
		System::Windows::Forms::OpenFileDialog^ Open = gcnew System::Windows::Forms::OpenFileDialog(); // new open file dialog object
		Open->Title = "Open Image File"; // open file window name
		Open->Filter = "Image Files(*.jpg;*.png;*.gif;*.tiff;*.bmp;)|*.jpg;*.png;*.gif;*.tiff;*.bmp"; // all valid file types
		Open->FilterIndex = 1; // sets filter
		currentImage->MaximumSize = System::Drawing::Size(1671, 1108); // max size of the  picture box
		Bitmap^ bitmap; // bitmap object to put in picturebox
		if (Open->ShowDialog() == ::DialogResult::OK) { // checks if "Open" clicked on valid image
			bitmap = gcnew Bitmap(System::Drawing::Bitmap::FromFile(Open->FileName)); // new bitmap from filename (filename is full path, ex. C:\User\Pictures\Image)
			currentImage->Image = bitmap; // sets current image in picture box to the above bitmap
			this->uploadImageLabel->Hide(); // hides initial "Upload New Image Label"
		}
	}
}

System::Void ImageProcessor::MyForm::hideTempObjects() { // hides all objects not displayed on initial launch
	this->hMirror->Hide();
	this->vMirror->Hide();
	this->rotateC->Hide();
	this->rotateCC->Hide();
	this->dimensionChange->Hide();
	this->stretchShrink->Hide();
	this->applyDimensionChange->Hide();
	this->cancelDimensionChange->Hide();

	this->percentLabel->Hide();
	this->degreeLabel->Hide();
	this->lowBrightness->Hide();
	this->highBrightness->Hide();
	this->lowLabel->Hide();
	this->highLabel->Hide();
	this->lowHueDegrees->Hide();
	this->highHueDegrees->Hide();
	this->currentWidthValue->Hide();
	this->currentHeightValue->Hide();
	this->newWidthLabel->Hide();
	this->newHeightLabel->Hide();

	this->brightnessSlider->Hide();
	this->brightnessValue->Hide();

	this->contrastSlider->Hide();
	this->contrastValue->Hide();

	this->saturationSlider->Hide();
	this->saturationValue->Hide();

	this->hueSlider->Hide();
	this->hueValue->Hide();

// <<<<<<< HEAD
	this->newWidthInput->Hide();
	this->newHeightInput->Hide();
// =======
	this->fillBoxStartX->Hide();
	this->fillBoxStartY->Hide();
	this->fillBoxEndX->Hide();
	this->fillBoxEndY->Hide();
	this->fillBoxLoad->Hide();
	this->boxX1->Hide();
	this->boxX2->Hide();
	this->boxY1->Hide();
	this->boxY2->Hide();
	this->colorSelector->Hide();
// >>>>>>> 6f4c8e83783d4a17af28267f2a561a6042f443df
}

System::Void ImageProcessor::MyForm::undoChange_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		if (changes->peek()) {
			currentImage->Image = changes->pop();
		}
	}
}

System::Void ImageProcessor::MyForm::rotateImage_Click(System::Object^  sender, System::EventArgs^  e) { // reveal rotate clockwise/counterclockwise buttons
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
		this->rotateC->Show();
		this->rotateCC->Show();
	}
}

System::Void ImageProcessor::MyForm::mirrorImage_Click(System::Object^  sender, System::EventArgs^  e) { // reveal horizontal/vertical mirror image buttons
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
		this->hMirror->Show();
		this->vMirror->Show();
	}
}

System::Void ImageProcessor::MyForm::cropImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
	}
}

System::Void ImageProcessor::MyForm::resizeImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
		this->dimensionChange->Show();
		this->stretchShrink->Show();
	}
}

System::Void ImageProcessor::MyForm::invertImage_Click(System::Object^  sender, System::EventArgs^  e) { // calls invert image method (Coloring.cpp)
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
		invertCurrentImage();
	}
}

System::Void ImageProcessor::MyForm::grayscaleImage_Click(System::Object^  sender, System::EventArgs^  e) { // calls grayscale image method (Coloring.cpp)
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
		grayscaleCurrentImage();
	}
}

System::Void ImageProcessor::MyForm::imageBrightness_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
		this->brightnessSlider->Value = 0;
		this->brightnessSlider->Show();
		this->brightnessValue->Show();
		this->percentLabel->Show();
		this->lowBrightness->Show();
		this->highBrightness->Show();
	}
}

System::Void ImageProcessor::MyForm::imageContrast_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
		this->contrastSlider->Value = 0;
		this->contrastSlider->Show();
		this->contrastValue->Show();
		this->percentLabel->Show();
		this->lowLabel->Show();
		this->highLabel->Show();
	}
}

System::Void ImageProcessor::MyForm::imageHue_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
		this->hueSlider->Value = 0;
		this->hueSlider->Show();
		this->hueValue->Show();
		this->degreeLabel->Show();
		this->lowHueDegrees->Show();
		this->highHueDegrees->Show();
	}
}

System::Void ImageProcessor::MyForm::imageSaturation_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentImage->Image) {
		saveCurrentImage();
		hideTempObjects();
		this->saturationSlider->Value = 0;
		this->saturationSlider->Show();
		this->saturationValue->Show();
		this->percentLabel->Show();
		this->lowLabel->Show();
		this->highLabel->Show();
	}
}

System::Void ImageProcessor::MyForm::saveCurrentImage() {
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	changes->push(bitmap);
}

System::Void ImageProcessor::MyForm::fillBox_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentImage->Image) {
		hideTempObjects();
		this->fillBoxStartX->Show();
		this->fillBoxStartY->Show();
		this->fillBoxEndX->Show();
		this->fillBoxEndY->Show();
		this->fillBoxLoad->Show();
		this->boxX1->Show();
		this->boxX2->Show();
		this->boxY1->Show();
		this->boxY2->Show();
		this->colorSelector->Show();

		
	}
}

System::Void ImageProcessor::MyForm::colorSelector_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentImage->Image) {
		ColorDialog^ MyDialog = gcnew ColorDialog;
		// Keeps the user from selecting a custom color.
		MyDialog->AllowFullOpen = false;
		// Allows the user to get help. (The default is false.)
		MyDialog->ShowHelp = true;
		// Sets the initial color select to the current text color.
		MyDialog->Color = fillColor;

		// Update the text box color if the user clicks OK 
		if (MyDialog->ShowDialog() == ::System::Windows::Forms::DialogResult::OK)
		{
			fillColor = MyDialog->Color;
		}
	}
}

System::Void ImageProcessor::MyForm::fillBoxLoad_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentImage->Image) {

		System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // image before being changed
		changes->push(bitmap); // push pre-change bitmap
		System::Drawing::Bitmap^ changedBitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current image
		for (int y = static_cast<int>(fillBoxStartY->Value); y < static_cast<int>(fillBoxEndY->Value); y++) {
			for (int x = static_cast<int>(fillBoxStartX->Value); x < static_cast<int>(fillBoxEndX->Value); x++) {
				changedBitmap->SetPixel(static_cast<int>(x), static_cast<int>(y), fillColor); // change color of pixel 
			}
		}
		currentImage->Image = changedBitmap; // current image set to new bitmap
	}
}