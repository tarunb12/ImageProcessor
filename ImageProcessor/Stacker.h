#pragma once
ref class Stacker
{
public:
	ref struct BITMAP {
		System::Drawing::Bitmap^ bitmap;
		BITMAP^ prev;
	};
	BITMAP^ stackPtr;

	Stacker();
	System::Void push(System::Drawing::Bitmap^ bitmapIn);
	BITMAP^ peek();
	System::Drawing::Bitmap^ pop();
};

