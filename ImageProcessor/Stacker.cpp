#include "Stacker.h"

using namespace System;
using namespace System::Drawing;

Stacker::Stacker() {
	stackPtr = nullptr;
}

System::Void Stacker::push(System::Drawing::Bitmap^ bitmapIn) {
	BITMAP^ bm = gcnew BITMAP;
	bm->bitmap = bitmapIn;
	if (stackPtr == nullptr) {
		stackPtr = bm;
	}
	else {
		bm->prev = stackPtr;
		stackPtr = bm;
	}
}

Stacker::BITMAP^ Stacker::peek() {
	return stackPtr;
}

System::Drawing::Bitmap^ Stacker::pop() {
	System::Drawing::Bitmap^ bitmapOut;
	if (stackPtr != nullptr) {
		BITMAP^ bm = stackPtr;
		stackPtr = stackPtr->prev;
		bm->prev = nullptr;
		bitmapOut = bm->bitmap;
	}
	return bitmapOut;
}