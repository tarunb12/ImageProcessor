#pragma once
ref class BitmapStack
{
public:
	ref struct BITMAP {
		System::Drawing::Bitmap^ bitmap;
		BITMAP^ prev;
	};
	BITMAP^ stackPtr;

	BitmapStack();
	System::Void push(System::Drawing::Bitmap^ bitmapIn);
	BITMAP^ peek();
	System::Drawing::Bitmap^ pop();
};

