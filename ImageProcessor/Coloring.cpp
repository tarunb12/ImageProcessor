#include "MyForm.h"

System::Void ImageProcessor::MyForm::invertCurrentImage() {
	System::Drawing::Bitmap^ bitmap = gcnew Bitmap(currentImage->Image);
	System::Drawing::Rectangle rect = Rectangle(0, 0, bitmap->Width, bitmap->Height);
	System::Drawing::Imaging::BitmapData^ bitmapData = bitmap->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bitmap->PixelFormat);
	IntPtr ptr = bitmapData->Scan0;
	int bytes = Math::Abs(bitmapData->Stride) * bitmap->Height;
	array<Byte>^ rgbValues = gcnew array<Byte>(bytes);
	System::Runtime::InteropServices::Marshal::Copy(ptr, rgbValues, 0, bytes);
	for (int i = 0; i < rgbValues->Length; i += 4) {
		rgbValues[i] = (Byte)(255 - rgbValues[i]);
		rgbValues[i + 1] = (Byte)(255 - rgbValues[i]);
		rgbValues[i + 2] = (Byte)(255 - rgbValues[i]);
	}
	
	System::Runtime::InteropServices::Marshal::Copy(rgbValues, 0, ptr, bytes);
	bitmap->UnlockBits(bitmapData);
	currentImage->Image = bitmap;
}