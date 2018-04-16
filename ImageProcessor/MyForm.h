#pragma once

namespace ImageProcessor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  uploadImage;
	private: System::Windows::Forms::PictureBox^  currentImage;
	private: System::Windows::Forms::Button^  rotateImage;
	private: System::Windows::Forms::Button^  rotateC;
	private: System::Windows::Forms::Button^  rotateCC;
	private: System::Windows::Forms::Button^  mirrorImage;
	private: System::Windows::Forms::Button^  hMirror;
	private: System::Windows::Forms::Button^  vMirror;
	private: System::Windows::Forms::Button^  cropImage;
	private: System::Windows::Forms::Button^  resizeImage;
	private: System::Windows::Forms::Button^  saveImage;
	private: System::Windows::Forms::Button^  invertImage;
	private: System::Windows::Forms::Button^  grayscaleImage;
	private: System::Windows::Forms::Button^  imageBrightness;
	private: System::Windows::Forms::Button^  imageContrast;
	private: System::Windows::Forms::Button^  undoChange;
	private: System::Windows::Forms::Label^  uploadImageLabel;




	protected:



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->currentImage = (gcnew System::Windows::Forms::PictureBox());
			this->uploadImage = (gcnew System::Windows::Forms::Button());
			this->saveImage = (gcnew System::Windows::Forms::Button());
			this->rotateImage = (gcnew System::Windows::Forms::Button());
			this->rotateC = (gcnew System::Windows::Forms::Button());
			this->rotateCC = (gcnew System::Windows::Forms::Button());
			this->mirrorImage = (gcnew System::Windows::Forms::Button());
			this->hMirror = (gcnew System::Windows::Forms::Button());
			this->vMirror = (gcnew System::Windows::Forms::Button());
			this->cropImage = (gcnew System::Windows::Forms::Button());
			this->resizeImage = (gcnew System::Windows::Forms::Button());
			this->invertImage = (gcnew System::Windows::Forms::Button());
			this->grayscaleImage = (gcnew System::Windows::Forms::Button());
			this->imageBrightness = (gcnew System::Windows::Forms::Button());
			this->imageContrast = (gcnew System::Windows::Forms::Button());
			this->undoChange = (gcnew System::Windows::Forms::Button());
			this->uploadImageLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentImage))->BeginInit();
			this->SuspendLayout();
			// 
			// currentImage
			// 
			this->currentImage->Location = System::Drawing::Point(704, 80);
			this->currentImage->Name = L"currentImage";
			this->currentImage->Size = System::Drawing::Size(1167, 806);
			this->currentImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->currentImage->TabIndex = 0;
			this->currentImage->TabStop = false;
			// 
			// uploadImage
			// 
			this->uploadImage->Location = System::Drawing::Point(1180, 949);
			this->uploadImage->Name = L"uploadImage";
			this->uploadImage->Size = System::Drawing::Size(215, 83);
			this->uploadImage->TabIndex = 1;
			this->uploadImage->Text = L"Upload Image";
			this->uploadImage->UseVisualStyleBackColor = true;
			this->uploadImage->Click += gcnew System::EventHandler(this, &MyForm::uploadImage_Click);
			// 
			// uploadImageLabel
			// 
			this->uploadImageLabel->AutoSize = true;
			this->uploadImageLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->uploadImageLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->uploadImageLabel->Location = System::Drawing::Point(871, 414);
			this->uploadImageLabel->Name = L"uploadImageLabel";
			this->uploadImageLabel->Size = System::Drawing::Size(856, 108);
			this->uploadImageLabel->TabIndex = 15;
			this->uploadImageLabel->Text = L"Upload New Image";
			this->uploadImageLabel->Click += gcnew System::EventHandler(this, &MyForm::uploadImageLabel_Click);
			// 
			// saveImage
			// 
			this->saveImage->Location = System::Drawing::Point(704, 949);
			this->saveImage->Name = L"saveImage";
			this->saveImage->Size = System::Drawing::Size(215, 83);
			this->saveImage->TabIndex = 2;
			this->saveImage->Text = L"Save Image";
			this->saveImage->UseVisualStyleBackColor = true;
			this->saveImage->Click += gcnew System::EventHandler(this, &MyForm::saveImage_Click);
			// 
			// rotateImage
			// 
			this->rotateImage->Location = System::Drawing::Point(85, 80);
			this->rotateImage->Name = L"rotateImage";
			this->rotateImage->Size = System::Drawing::Size(233, 71);
			this->rotateImage->TabIndex = 3;
			this->rotateImage->Text = L"Rotate";
			this->rotateImage->UseVisualStyleBackColor = true;
			this->rotateImage->Click += gcnew System::EventHandler(this, &MyForm::rotateImage_Click);
			// 
			// rotateC
			// 
			this->rotateC->Location = System::Drawing::Point(98, 705);
			this->rotateC->Name = L"rotateC";
			this->rotateC->Size = System::Drawing::Size(220, 71);
			this->rotateC->TabIndex = 4;
			this->rotateC->Text = L"Rotate Clockwise";
			this->rotateC->UseVisualStyleBackColor = true;
			this->rotateC->Click += gcnew System::EventHandler(this, &MyForm::rotateC_Click);
			// 
			// rotateCC
			// 
			this->rotateCC->Location = System::Drawing::Point(382, 705);
			this->rotateCC->Name = L"rotateCC";
			this->rotateCC->Size = System::Drawing::Size(220, 71);
			this->rotateCC->TabIndex = 5;
			this->rotateCC->Text = L"Rotate Counterclockwise";
			this->rotateCC->UseVisualStyleBackColor = true;
			this->rotateCC->Click += gcnew System::EventHandler(this, &MyForm::rotateCC_Click);
			// 
			// mirrorImage
			// 
			this->mirrorImage->Location = System::Drawing::Point(382, 80);
			this->mirrorImage->Name = L"mirrorImage";
			this->mirrorImage->Size = System::Drawing::Size(233, 71);
			this->mirrorImage->TabIndex = 6;
			this->mirrorImage->Text = L"Mirror";
			this->mirrorImage->UseVisualStyleBackColor = true;
			this->mirrorImage->Click += gcnew System::EventHandler(this, &MyForm::mirrorImage_Click);
			// 
			// hMirror
			// 
			this->hMirror->Location = System::Drawing::Point(98, 705);
			this->hMirror->Name = L"hMirror";
			this->hMirror->Size = System::Drawing::Size(220, 71);
			this->hMirror->TabIndex = 7;
			this->hMirror->Text = L"Horizontal Mirror";
			this->hMirror->UseVisualStyleBackColor = true;
			this->hMirror->Click += gcnew System::EventHandler(this, &MyForm::hMirror_Click);
			// 
			// vMirror
			// 
			this->vMirror->Location = System::Drawing::Point(382, 705);
			this->vMirror->Name = L"vMirror";
			this->vMirror->Size = System::Drawing::Size(220, 71);
			this->vMirror->TabIndex = 8;
			this->vMirror->Text = L"Vertical Mirror";
			this->vMirror->UseVisualStyleBackColor = true;
			this->vMirror->Click += gcnew System::EventHandler(this, &MyForm::vMirror_Click);
			// 
			// cropImage
			// 
			this->cropImage->Location = System::Drawing::Point(85, 220);
			this->cropImage->Name = L"cropImage";
			this->cropImage->Size = System::Drawing::Size(233, 71);
			this->cropImage->TabIndex = 9;
			this->cropImage->Text = L"Crop";
			this->cropImage->UseVisualStyleBackColor = true;
			this->cropImage->Click += gcnew System::EventHandler(this, &MyForm::cropImage_Click);
			// 
			// resizeImage
			// 
			this->resizeImage->Location = System::Drawing::Point(382, 220);
			this->resizeImage->Name = L"resizeImage";
			this->resizeImage->Size = System::Drawing::Size(233, 71);
			this->resizeImage->TabIndex = 10;
			this->resizeImage->Text = L"Resize";
			this->resizeImage->UseVisualStyleBackColor = true;
			this->resizeImage->Click += gcnew System::EventHandler(this, &MyForm::resizeImage_Click);
			// 
			// invertImage
			// 
			this->invertImage->Location = System::Drawing::Point(85, 360);
			this->invertImage->Name = L"invertImage";
			this->invertImage->Size = System::Drawing::Size(233, 71);
			this->invertImage->TabIndex = 11;
			this->invertImage->Text = L"Invert";
			this->invertImage->UseVisualStyleBackColor = true;
			this->invertImage->Click += gcnew System::EventHandler(this, &MyForm::invertImage_Click);
			// 
			// grayscaleImage
			// 
			this->grayscaleImage->Location = System::Drawing::Point(382, 360);
			this->grayscaleImage->Name = L"grayscaleImage";
			this->grayscaleImage->Size = System::Drawing::Size(233, 71);
			this->grayscaleImage->TabIndex = 8;
			this->grayscaleImage->Text = L"Grayscale";
			this->grayscaleImage->UseVisualStyleBackColor = true;
			this->grayscaleImage->Click += gcnew System::EventHandler(this, &MyForm::grayscaleImage_Click);
			// 
			// imageBrightness
			// 
			this->imageBrightness->Location = System::Drawing::Point(85, 500);
			this->imageBrightness->Name = L"imageBrightness";
			this->imageBrightness->Size = System::Drawing::Size(233, 71);
			this->imageBrightness->TabIndex = 12;
			this->imageBrightness->Text = L"Brightness";
			this->imageBrightness->UseVisualStyleBackColor = true;
			this->imageBrightness->Click += gcnew System::EventHandler(this, &MyForm::imageBrightness_Click);
			// 
			// imageContrast
			// 
			this->imageContrast->Location = System::Drawing::Point(382, 500);
			this->imageContrast->Name = L"imageContrast";
			this->imageContrast->Size = System::Drawing::Size(233, 71);
			this->imageContrast->TabIndex = 13;
			this->imageContrast->Text = L"Contrast";
			this->imageContrast->UseVisualStyleBackColor = true;
			this->imageContrast->Click += gcnew System::EventHandler(this, &MyForm::imageContrast_Click);
			// 
			// undoChange
			// 
			this->undoChange->Location = System::Drawing::Point(1656, 949);
			this->undoChange->Name = L"undoChange";
			this->undoChange->Size = System::Drawing::Size(215, 83);
			this->undoChange->TabIndex = 14;
			this->undoChange->Text = L"Undo";
			this->undoChange->UseVisualStyleBackColor = true;
			this->undoChange->Click += gcnew System::EventHandler(this, &MyForm::undoChange_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1949, 1091);
			this->Controls->Add(this->uploadImageLabel);
			this->Controls->Add(this->imageContrast);
			this->Controls->Add(this->imageBrightness);
			this->Controls->Add(this->grayscaleImage);
			this->Controls->Add(this->invertImage);
			this->Controls->Add(this->saveImage);
			this->Controls->Add(this->resizeImage);
			this->Controls->Add(this->cropImage);
			this->Controls->Add(this->mirrorImage);
			this->Controls->Add(this->hMirror);
			this->Controls->Add(this->vMirror);
			this->Controls->Add(this->rotateImage);
			this->Controls->Add(this->rotateC);
			this->Controls->Add(this->rotateCC);
			this->Controls->Add(this->currentImage);
			this->Controls->Add(this->uploadImage);
			this->Controls->Add(this->undoChange);
			this->Name = L"MyForm";
			this->Text = L"Image Processor";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentImage))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: // prototypes of all event handlers / image processing functions
		System::Void uploadImage_Click(System::Object^  sender, System::EventArgs^  e); // shows open file dialog on click
		System::Void uploadImageLabel_Click(System::Object^  sender, System::EventArgs^  e); // shows open file dialog on click
		System::Void saveImage_Click(System::Object^  sender, System::EventArgs^  e); // shows save file dialog on click

		System::Void hideTempObjects(); // hides objects

		System::Drawing::Bitmap^ previousBitmap; // previous bitmap for undo
		System::Void undoChange_Click(System::Object^  sender, System::EventArgs^  e); // reverts a single change

		System::Void rotateImage_Click(System::Object^  sender, System::EventArgs^  e); // shows rotatec/rotatecc buttons
		System::Void rotateC_Click(System::Object^  sender, System::EventArgs^  e); // rotates image clockwise
		System::Void rotateCC_Click(System::Object^  sender, System::EventArgs^  e); // rotates image counterclockwise

		System::Void mirrorImage_Click(System::Object^  sender, System::EventArgs^  e); // shows hmirror/vmirror buttons
		System::Void hMirror_Click(System::Object^  sender, System::EventArgs^  e); // mirrors image horizontally
		System::Void vMirror_Click(System::Object^  sender, System::EventArgs^  e); // mirrors image vertically

		System::Void cropImage_Click(System::Object^  sender, System::EventArgs^  e); // not implemented yet

		System::Void resizeImage_Click(System::Object^  sender, System::EventArgs^  e); // not implemented yet

		System::Void invertImage_Click(System::Object^  sender, System::EventArgs^  e); // inverts current image
		System::Void invertCurrentImage(); // inversion function

		System::Void grayscaleImage_Click(System::Object^  sender, System::EventArgs^  e); // grayscales current image
		System::Void grayscaleCurrentImage(); // grayscale function

		System::Void imageBrightness_Click(System::Object^  sender, System::EventArgs^  e); // not implemented yet

		System::Void imageContrast_Click(System::Object^  sender, System::EventArgs^  e); // not implemented yet

		System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e); // hide objects on form launch
		
};
}
