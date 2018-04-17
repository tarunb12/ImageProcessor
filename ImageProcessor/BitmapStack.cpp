#include "BitmapStack.h"

using namespace System;
using namespace System::Drawing;

BitmapStack::BitmapStack() {
	stackPtr = nullptr;
}

System::Void BitmapStack::push(System::Drawing::Bitmap^ bitmapIn) {
	BITMAP^ bm = gcnew BITMAP;
	bm->bitmap = bitmapIn;
	if (stackPtr == nullptr) {
		stackPtr = bm;
		stackPtr->prev = nullptr;
	}
	else {
		bm->prev = stackPtr;
		stackPtr = bm;
	}
}

BitmapStack::BITMAP^ BitmapStack::peek() {
	return stackPtr;
}

System::Drawing::Bitmap^ BitmapStack::bitmapPeek() {
	return stackPtr->bitmap;
}

System::Drawing::Bitmap^ BitmapStack::pop() {
	System::Drawing::Bitmap^ bitmapOut;
	if (stackPtr != nullptr) {
		BITMAP^ bm = stackPtr;
		stackPtr = stackPtr->prev;
		bm->prev = nullptr;
		bitmapOut = bm->bitmap;
		delete bm;
	}
	return bitmapOut;
}