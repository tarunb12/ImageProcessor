#include "MyForm.h"

System::Void ImageProcessor::MyForm::dimensionChange() {
	int oldWidth = currentImage->Image->Width;
	int oldHeight = currentImage->Image->Height;
	this->currentWidthValue->Text = "Current Width: " + System::Convert::ToString(oldWidth) + " px";
	this->currentHeightValue->Text = "Current Height: " + System::Convert::ToString(oldHeight) + " px";

	this->currentWidthValue->Show();
	this->currentHeightValue->Show();
	this->newWidthLabel->Show();
	this->newHeightLabel->Show();
	this->newWidthInput->Show();
	this->newHeightInput->Show();
	this->applyDimensionChange->Show();
	this->cancelDimensionChange->Show();

	this->newWidthInput->Text = "";
	this->pixel1->Show();
	this->newHeightInput->Text = "";
	this->pixel2->Show();
}

System::Void ImageProcessor::MyForm::applyDimensionChange_Click(System::Object^  sender, System::EventArgs^  e) {
	if (System::Int32::TryParse(this->newWidthInput->Text, newWidth) && System::Int32::TryParse(this->newHeightInput->Text, newHeight)) {
		this->currentWidthValue->Show();
		this->currentHeightValue->Show();
		this->newWidthLabel->Show();
		this->newHeightLabel->Show();
		this->newWidthInput->Show();
		this->newHeightInput->Show();
		this->applyDimensionChange->Show();
		this->cancelDimensionChange->Show();

		System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);

		System::Drawing::Rectangle rect = Rectangle(0, 0, newWidth, newHeight);
		// change
		System::Drawing::Bitmap^ newBitmap = gcnew Bitmap(newWidth, newHeight);
		// change
		newBitmap->SetResolution(bitmap->HorizontalResolution, bitmap->VerticalResolution);
		System::Drawing::Graphics^ newGraphics = System::Drawing::Graphics::FromImage(newBitmap);
		newGraphics->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceCopy;
		newGraphics->CompositingQuality = System::Drawing::Drawing2D::CompositingQuality::HighQuality;
		newGraphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
		newGraphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::HighQuality;
		newGraphics->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::HighQuality;

		System::Drawing::Imaging::ImageAttributes^ attributes = gcnew System::Drawing::Imaging::ImageAttributes();
		attributes->SetWrapMode(System::Drawing::Drawing2D::WrapMode::TileFlipXY);
		newGraphics->DrawImage(bitmap, rect, 0, 0, bitmap->Width, bitmap->Height, System::Drawing::GraphicsUnit::Pixel, attributes);
		newWidth = -1;
		newHeight = -1;

		this->currentWidthValue->Hide();
		this->currentHeightValue->Hide();
		this->newWidthLabel->Hide();
		this->newHeightLabel->Hide();
		this->newWidthInput->Hide();
		this->newHeightInput->Hide();
		this->applyDimensionChange->Hide();
		this->cancelDimensionChange->Hide();
		this->pixel1->Hide();
		this->pixel2->Hide();

		currentImage->Image = newBitmap;
	}
}

System::Void ImageProcessor::MyForm::cancelDimensionChange_Click(System::Object^  sender, System::EventArgs^  e) {
	this->currentWidthValue->Hide();
	this->currentHeightValue->Hide();
	this->newWidthLabel->Hide();
	this->newHeightLabel->Hide();
	this->newWidthInput->Hide();
	this->newHeightInput->Hide();
	this->applyDimensionChange->Hide();
	this->cancelDimensionChange->Hide();
	this->pixel1->Hide();
	this->pixel2->Hide();
}

