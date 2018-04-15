#include <iostream>
#include <string>
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
			this->uploadImage = (gcnew System::Windows::Forms::Button());
			this->currentImage = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentImage))->BeginInit();
			this->SuspendLayout();
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
			// currentImage
			// 
			this->currentImage->Location = System::Drawing::Point(806, 79);
			this->currentImage->Name = L"currentImage";
			this->currentImage->Size = System::Drawing::Size(1671, 1108);
			this->currentImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->currentImage->TabIndex = 1;
			this->currentImage->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2564, 1559);
			this->Controls->Add(this->currentImage);
			this->Controls->Add(this->uploadImage);
			this->MaximumSize = System::Drawing::Size(2590, 1630);
			this->MinimumSize = System::Drawing::Size(2558, 1518);
			this->Name = L"MyForm";
			this->Text = L"Image Processor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentImage))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void uploadImage_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void updatePictureBox(Bitmap^ newBitMap);
	};
}
