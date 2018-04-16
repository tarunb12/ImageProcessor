#include "MyForm.h"

/*
	rgb: has four values
	ex. rgb(0, 128, 255, 1)
	first three values represent red, green, blue pixel, min value 0, max value 255
	last value represents alpha, represent transparency of the pixel, min value 0 (transparent), max value 1 (opaque)
*/

System::Void ImageProcessor::MyForm::invertCurrentImage() { // unsafe?
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current picturebox image
	System::Drawing::Rectangle rect = Rectangle(0, 0, bitmap->Width, bitmap->Height); // new rectangle object w/ same image dimensions
	System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadOnly, bitmap->PixelFormat); // locks bitmap
	IntPtr ptr = bitmapData->Scan0; // idk scans bitmap data
	int bytes = Math::Abs(bitmapData->Stride) * bitmap->Height; // rgb values converted into byte value
	array<Byte>^ rgbValues = gcnew array<Byte>(bytes); // byte array to hold rgb values
	System::Runtime::InteropServices::Marshal::Copy(ptr, rgbValues, 0, bytes); // copies values to rgb array
	for (int i = 0; i < rgbValues->Length; i += 4) { // goes through each pixel in the image
		rgbValues[i] = 255 - rgbValues[i]; // finds inverse of red pixel
		rgbValues[i + 1] = 255 - rgbValues[i + 1]; // finds inverse of green pixel
		rgbValues[i + 2] = 255 - rgbValues[i + 2]; // finds inverse of blue pixel
	}
	System::Runtime::InteropServices::Marshal::Copy(rgbValues, 0, ptr, bytes); // copies rgb values to bitmap data
	bitmap->UnlockBits(bitmapData); // transfers bitmap data back to bitmap & unlocks bitmap
	currentImage->Image = bitmap; // current picturebox image set to bitmap
}

System::Void ImageProcessor::MyForm::grayscaleCurrentImage() { // unsafe? grayscale by averaging r + g + b values
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image); // new bitmap of current picturebox image
	System::Drawing::Rectangle rect = Rectangle(0, 0, bitmap->Width, bitmap->Height); // new rectangle object w/ same image dimensions
	System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadOnly, bitmap->PixelFormat); // locks bitmap
	IntPtr ptr = bitmapData->Scan0; // idk scans bitmap data
	int bytes = Math::Abs(bitmapData->Stride) * bitmap->Height; // rgb values converted into byte value
	array<Byte>^ rgbValues = gcnew array<Byte>(bytes); // array of bytes rep
	System::Runtime::InteropServices::Marshal::Copy(ptr, rgbValues, 0, bytes); // copies values to rgb array
	for (int i = 0; i < rgbValues->Length; i += 4) {
		Byte r = rgbValues[i]; // value of red / 255
		Byte g = rgbValues[i + 1]; // value of green / 255
		Byte b = rgbValues[i + 2]; // value of blue / 255
		Byte average = (r + g + b) / 3; // average of three rgb values
		rgbValues[i] = average; // red pixel set to average
		rgbValues[i + 1] = average; // green pixel set to average
		rgbValues[i + 2] = average; // blue pixel set to average
	}
	System::Runtime::InteropServices::Marshal::Copy(rgbValues, 0, ptr, bytes); // copies rgb values to bitmap data
	bitmap->UnlockBits(bitmapData); // transfers bitmap data back to bitmap & unlocks bitmap
	currentImage->Image = bitmap; // current picturebox image set to new bitmap
}