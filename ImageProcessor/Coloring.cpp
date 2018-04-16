#include "MyForm.h"

System::Void ImageProcessor::MyForm::invertCurrentImage() {
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	System::Drawing::Rectangle rect = Rectangle(0, 0, bitmap->Width, bitmap->Height);
	System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadOnly, bitmap->PixelFormat);
	IntPtr ptr = bitmapData->Scan0;
	int bytes = Math::Abs(bitmapData->Stride) * bitmap->Height;
	array<Byte>^ rgbValues = gcnew array<Byte>(bytes);
	System::Runtime::InteropServices::Marshal::Copy(ptr, rgbValues, 0, bytes);
	for (int i = 0; i < rgbValues->Length; i += 4) {
		rgbValues[i] = (Byte)(255 - rgbValues[i]);
		rgbValues[i + 1] = (Byte)(255 - rgbValues[i + 1]);
		rgbValues[i + 2] = (Byte)(255 - rgbValues[i + 2]);
	}
	System::Runtime::InteropServices::Marshal::Copy(rgbValues, 0, ptr, bytes);
	bitmap->UnlockBits(bitmapData);
	currentImage->Image = bitmap;
}

System::Void ImageProcessor::MyForm::grayscaleCurrentImage() {
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	System::Drawing::Rectangle rect = Rectangle(0, 0, bitmap->Width, bitmap->Height);
	System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadOnly, bitmap->PixelFormat);
	IntPtr ptr = bitmapData->Scan0;
	int bytes = Math::Abs(bitmapData->Stride) * bitmap->Height;
	array<Byte>^ rgbValues = gcnew array<Byte>(bytes);
	System::Runtime::InteropServices::Marshal::Copy(ptr, rgbValues, 0, bytes);
	for (int i = 0; i < rgbValues->Length; i += 4) {
		Byte r = rgbValues[i];
		Byte g = rgbValues[i + 1];
		Byte b = rgbValues[i + 2];
		Byte average = (r + g + b) / 3;
		rgbValues[i] = average;
		rgbValues[i + 1] = average;
		rgbValues[i + 2] = average;
	}
	System::Runtime::InteropServices::Marshal::Copy(rgbValues, 0, ptr, bytes);
	bitmap->UnlockBits(bitmapData);
	currentImage->Image = bitmap;
}