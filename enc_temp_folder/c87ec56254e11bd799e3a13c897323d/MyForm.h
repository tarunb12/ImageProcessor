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
	private: System::Windows::Forms::Button^  mirrorImage;
	private: System::Windows::Forms::Button^ hMirror;
	private: System::Windows::Forms::Button^ vMirror;
	private: System::Windows::Forms::Button^  cropImage;
	private: System::Windows::Forms::Button^  resizeImage;
	private: System::Windows::Forms::Button^  saveImage;
	private: System::Windows::Forms::Button^  invertImage;
	private: System::Windows::Forms::Button^  grayscaleImage;
	private: System::Windows::Forms::Button^  imageBrightness;
	private: System::Windows::Forms::Button^  imageContrast;


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
			this->mirrorImage = (gcnew System::Windows::Forms::Button());
			this->hMirror = (gcnew System::Windows::Forms::Button());
			this->vMirror = (gcnew System::Windows::Forms::Button());
			this->cropImage = (gcnew System::Windows::Forms::Button());
			this->resizeImage = (gcnew System::Windows::Forms::Button());
			this->invertImage = (gcnew System::Windows::Forms::Button());
			this->grayscaleImage = (gcnew System::Windows::Forms::Button());
			this->imageBrightness = (gcnew System::Windows::Forms::Button());
			this->imageContrast = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentImage))->BeginInit();
			this->SuspendLayout();
			// 
			// currentImage
			// 
			this->currentImage->Location = System::Drawing::Point(803, 80);
			this->currentImage->Name = L"currentImage";
			this->currentImage->Size = System::Drawing::Size(1671, 1108);
			this->currentImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->currentImage->TabIndex = 1;
			this->currentImage->TabStop = false;
			// 
			// uploadImage
			// 
			this->uploadImage->Location = System::Drawing::Point(1166, 1281);
			this->uploadImage->Name = L"uploadImage";
			this->uploadImage->Size = System::Drawing::Size(215, 83);
			this->uploadImage->TabIndex = 0;
			this->uploadImage->Text = L"Upload Image";
			this->uploadImage->UseVisualStyleBackColor = true;
			this->uploadImage->Click += gcnew System::EventHandler(this, &MyForm::uploadImage_Click);
			// 
			// saveImage
			// 
			this->saveImage->Location = System::Drawing::Point(293, 1281);
			this->saveImage->Name = L"saveImage";
			this->saveImage->Size = System::Drawing::Size(215, 83);
			this->saveImage->TabIndex = 6;
			this->saveImage->Text = L"Save Image";
			this->saveImage->UseVisualStyleBackColor = true;
			this->saveImage->Click += gcnew System::EventHandler(this, &MyForm::saveImage_Click);
			// 
			// rotateImage
			// 
			this->rotateImage->Location = System::Drawing::Point(85, 80);
			this->rotateImage->Name = L"rotateImage";
			this->rotateImage->Size = System::Drawing::Size(233, 71);
			this->rotateImage->TabIndex = 2;
			this->rotateImage->Text = L"Rotate";
			this->rotateImage->UseVisualStyleBackColor = true;
			this->rotateImage->Click += gcnew System::EventHandler(this, &MyForm::rotateImage_Click);
			// 
			// mirrorImage
			// 
			this->mirrorImage->Location = System::Drawing::Point(465, 80);
			this->mirrorImage->Name = L"mirrorImage";
			this->mirrorImage->Size = System::Drawing::Size(233, 71);
			this->mirrorImage->TabIndex = 3;
			this->mirrorImage->Text = L"Mirror";
			this->mirrorImage->UseVisualStyleBackColor = true;
			this->mirrorImage->Click += gcnew System::EventHandler(this, &MyForm::mirrorImage_Click);
			//
			// hMirror
			//
			this->hMirror->Location = System::Drawing::Point(85, 880);
			this->hMirror->Name = L"horizontalMirror";
			this->hMirror->Size = System::Drawing::Size(259, 71);
			this->hMirror->TabIndex = 0;
			this->hMirror->Text = L"Horizontal Mirror";
			this->hMirror->UseVisualStyleBackColor = true;
			this->hMirror->Click += gcnew System::EventHandler(this, &MyForm::hMirror_Click);
			this->hMirror->Hide();
			//
			// vMirror
			//
			this->vMirror->Location = System::Drawing::Point(439, 880);
			this->vMirror->Name = L"verticalMirror";
			this->vMirror->Size = System::Drawing::Size(259, 71);
			this->vMirror->TabIndex = 0;
			this->vMirror->Text = L"Vertical Mirror";
			this->vMirror->UseVisualStyleBackColor = true;
			this->vMirror->Click += gcnew System::EventHandler(this, &MyForm::vMirror_Click);
			this->vMirror->Hide();
			// 
			// cropImage
			// 
			this->cropImage->Location = System::Drawing::Point(85, 220);
			this->cropImage->Name = L"cropImage";
			this->cropImage->Size = System::Drawing::Size(233, 71);
			this->cropImage->TabIndex = 4;
			this->cropImage->Text = L"Crop";
			this->cropImage->UseVisualStyleBackColor = true;
			this->cropImage->Click += gcnew System::EventHandler(this, &MyForm::cropImage_Click);
			// 
			// resizeImage
			// 
			this->resizeImage->Location = System::Drawing::Point(465, 220);
			this->resizeImage->Name = L"resizeImage";
			this->resizeImage->Size = System::Drawing::Size(233, 71);
			this->resizeImage->TabIndex = 5;
			this->resizeImage->Text = L"Resize";
			this->resizeImage->UseVisualStyleBackColor = true;
			this->resizeImage->Click += gcnew System::EventHandler(this, &MyForm::resizeImage_Click);
			// 
			// invertImage
			// 
			this->invertImage->Location = System::Drawing::Point(85, 360);
			this->invertImage->Name = L"invertImage";
			this->invertImage->Size = System::Drawing::Size(233, 71);
			this->invertImage->TabIndex = 7;
			this->invertImage->Text = L"Invert";
			this->invertImage->UseVisualStyleBackColor = true;
			this->invertImage->Click += gcnew System::EventHandler(this, &MyForm::invertImage_Click);
			// 
			// grayscaleImage
			// 
			this->grayscaleImage->Location = System::Drawing::Point(465, 360);
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
			this->imageBrightness->TabIndex = 9;
			this->imageBrightness->Text = L"Brightness";
			this->imageBrightness->UseVisualStyleBackColor = true;
			this->imageBrightness->Click += gcnew System::EventHandler(this, &MyForm::imageBrightness_Click);
			// 
			// imageContrast
			// 
			this->imageContrast->Location = System::Drawing::Point(465, 500);
			this->imageContrast->Name = L"imageContrast";
			this->imageContrast->Size = System::Drawing::Size(233, 71);
			this->imageContrast->TabIndex = 10;
			this->imageContrast->Text = L"Contrast";
			this->imageContrast->UseVisualStyleBackColor = true;
			this->imageContrast->Click += gcnew System::EventHandler(this, &MyForm::imageContrast_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2564, 1559);
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
			this->Controls->Add(this->currentImage);
			this->Controls->Add(this->uploadImage);
			this->Name = L"MyForm";
			this->Text = L"Image Processor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentImage))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void updatePictureBox(Bitmap^ newBitMap);
		System::Void uploadImage_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void saveImage_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void rotateImage_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void mirrorImage_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void hMirror_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void vMirror_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void cropImage_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void resizeImage_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void invertImage_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void grayscaleImage_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void imageBrightness_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void imageContrast_Click(System::Object^  sender, System::EventArgs^  e);
};
}
