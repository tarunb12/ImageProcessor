#pragma once
ref class BitmapStack // Bitmap stack class
{
private:
	ref struct BITMAP { // structure of a node in the stack
		System::Drawing::Bitmap^ bitmap; // holds the previous bitmap
		BITMAP^ prev; // points to bitmap which is next in the stack
	};
	BITMAP^ stackPtr; // points to top of the stack
public:
	BitmapStack(); // default constructor
	System::Void push(System::Drawing::Bitmap^ bitmapIn); // pushes previous bitmap to the top of the stack
	BITMAP^ peek(); // checks if stackptr points to anything
	System::Drawing::Bitmap^ bitmapPeek();
	System::Drawing::Bitmap^ pop(); // returns and deletes the bitmap at the top of the stack
};