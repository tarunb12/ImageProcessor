#include "BitmapStack.h"

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
	private: System::Windows::Forms::TrackBar^  brightnessSlider;
	private: System::Windows::Forms::TrackBar^  contrastSlider;
	private: System::Windows::Forms::TextBox^  brightnessValue;
	private: System::Windows::Forms::Timer^  brightnessTimer;
	private: System::Windows::Forms::Button^  imageHue;
	private: System::Windows::Forms::Button^  imageSaturation;
	private: System::Windows::Forms::TextBox^  contrastValue;
	private: System::Windows::Forms::Timer^  contrastTimer;
	private: System::Windows::Forms::TrackBar^  saturationSlider;
	private: System::Windows::Forms::TextBox^  saturationValue;
	private: System::Windows::Forms::Timer^  saturationTimer;
	private: System::Windows::Forms::TrackBar^  hueSlider;
	private: System::Windows::Forms::Label^  percentLabel;
	private: System::Windows::Forms::TextBox^  hueValue;
	private: System::Windows::Forms::Label^  highBrightness;
	private: System::Windows::Forms::Label^  highLabel;
	private: System::Windows::Forms::Label^  lowBrightness;
	private: System::Windows::Forms::Label^  lowLabel;
	private: System::Windows::Forms::Label^  lowHueDegrees;
	private: System::Windows::Forms::Label^  highHueDegrees;
	private: System::Windows::Forms::Timer^  hueTimer;
	private: System::Windows::Forms::Label^  degreeLabel;
	private: System::ComponentModel::IContainer^  components;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
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
			this->brightnessSlider = (gcnew System::Windows::Forms::TrackBar());
			this->contrastSlider = (gcnew System::Windows::Forms::TrackBar());
			this->brightnessValue = (gcnew System::Windows::Forms::TextBox());
			this->brightnessTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->imageHue = (gcnew System::Windows::Forms::Button());
			this->imageSaturation = (gcnew System::Windows::Forms::Button());
			this->contrastValue = (gcnew System::Windows::Forms::TextBox());
			this->contrastTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->saturationSlider = (gcnew System::Windows::Forms::TrackBar());
			this->saturationValue = (gcnew System::Windows::Forms::TextBox());
			this->saturationTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->hueSlider = (gcnew System::Windows::Forms::TrackBar());
			this->percentLabel = (gcnew System::Windows::Forms::Label());
			this->hueValue = (gcnew System::Windows::Forms::TextBox());
			this->highBrightness = (gcnew System::Windows::Forms::Label());
			this->highLabel = (gcnew System::Windows::Forms::Label());
			this->lowBrightness = (gcnew System::Windows::Forms::Label());
			this->lowLabel = (gcnew System::Windows::Forms::Label());
			this->lowHueDegrees = (gcnew System::Windows::Forms::Label());
			this->highHueDegrees = (gcnew System::Windows::Forms::Label());
			this->hueTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->degreeLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightnessSlider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contrastSlider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->saturationSlider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hueSlider))->BeginInit();
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
			this->rotateC->Location = System::Drawing::Point(99, 949);
			this->rotateC->Name = L"rotateC";
			this->rotateC->Size = System::Drawing::Size(220, 71);
			this->rotateC->TabIndex = 4;
			this->rotateC->Text = L"Rotate Clockwise";
			this->rotateC->UseVisualStyleBackColor = true;
			this->rotateC->Click += gcnew System::EventHandler(this, &MyForm::rotateC_Click);
			// 
			// rotateCC
			// 
			this->rotateCC->Location = System::Drawing::Point(383, 949);
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
			this->hMirror->Location = System::Drawing::Point(99, 949);
			this->hMirror->Name = L"hMirror";
			this->hMirror->Size = System::Drawing::Size(220, 71);
			this->hMirror->TabIndex = 7;
			this->hMirror->Text = L"Horizontal Mirror";
			this->hMirror->UseVisualStyleBackColor = true;
			this->hMirror->Click += gcnew System::EventHandler(this, &MyForm::hMirror_Click);
			// 
			// vMirror
			// 
			this->vMirror->Location = System::Drawing::Point(383, 949);
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
			// brightnessSlider
			// 
			this->brightnessSlider->Location = System::Drawing::Point(99, 942);
			this->brightnessSlider->Maximum = 255;
			this->brightnessSlider->Minimum = -255;
			this->brightnessSlider->Name = L"brightnessSlider";
			this->brightnessSlider->Size = System::Drawing::Size(504, 90);
			this->brightnessSlider->TabIndex = 16;
			this->brightnessSlider->ValueChanged += gcnew System::EventHandler(this, &MyForm::brightnessSlider_ValueChanged);
			// 
			// contrastSlider
			// 
			this->contrastSlider->Location = System::Drawing::Point(99, 942);
			this->contrastSlider->Maximum = 255;
			this->contrastSlider->Minimum = -255;
			this->contrastSlider->Name = L"contrastSlider";
			this->contrastSlider->Size = System::Drawing::Size(504, 90);
			this->contrastSlider->TabIndex = 17;
			this->contrastSlider->ValueChanged += gcnew System::EventHandler(this, &MyForm::contrastSlider_ValueChanged);
			// 
			// brightnessValue
			// 
			this->brightnessValue->BackColor = System::Drawing::SystemColors::Control;
			this->brightnessValue->Location = System::Drawing::Point(314, 1001);
			this->brightnessValue->Name = L"brightnessValue";
			this->brightnessValue->Size = System::Drawing::Size(50, 31);
			this->brightnessValue->TabIndex = 21;
			this->brightnessValue->Text = L"0";
			this->brightnessValue->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// brightnessTimer
			// 
			this->brightnessTimer->Interval = 300;
			this->brightnessTimer->Tick += gcnew System::EventHandler(this, &MyForm::brightnessTimer_Tick);
			// 
			// imageHue
			// 
			this->imageHue->Location = System::Drawing::Point(85, 640);
			this->imageHue->Name = L"imageHue";
			this->imageHue->Size = System::Drawing::Size(233, 71);
			this->imageHue->TabIndex = 23;
			this->imageHue->Text = L"Hue";
			this->imageHue->UseVisualStyleBackColor = true;
			this->imageHue->Click += gcnew System::EventHandler(this, &MyForm::imageHue_Click);
			// 
			// imageSaturation
			// 
			this->imageSaturation->Location = System::Drawing::Point(382, 640);
			this->imageSaturation->Name = L"imageSaturation";
			this->imageSaturation->Size = System::Drawing::Size(233, 71);
			this->imageSaturation->TabIndex = 24;
			this->imageSaturation->Text = L"Saturation";
			this->imageSaturation->UseVisualStyleBackColor = true;
			this->imageSaturation->Click += gcnew System::EventHandler(this, &MyForm::imageSaturation_Click);
			// 
			// contrastValue
			// 
			this->contrastValue->BackColor = System::Drawing::SystemColors::Control;
			this->contrastValue->Location = System::Drawing::Point(314, 1001);
			this->contrastValue->Name = L"contrastValue";
			this->contrastValue->Size = System::Drawing::Size(50, 31);
			this->contrastValue->TabIndex = 25;
			this->contrastValue->Text = L"0";
			this->contrastValue->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// contrastTimer
			// 
			this->contrastTimer->Interval = 300;
			this->contrastTimer->Tick += gcnew System::EventHandler(this, &MyForm::contrastTimer_Tick);
			// 
			// saturationSlider
			// 
			this->saturationSlider->Location = System::Drawing::Point(99, 942);
			this->saturationSlider->Maximum = 255;
			this->saturationSlider->Minimum = -255;
			this->saturationSlider->Name = L"saturationSlider";
			this->saturationSlider->Size = System::Drawing::Size(504, 90);
			this->saturationSlider->TabIndex = 28;
			this->saturationSlider->ValueChanged += gcnew System::EventHandler(this, &MyForm::saturationSlider_ValueChanged);
			// 
			// saturationValue
			// 
			this->saturationValue->BackColor = System::Drawing::SystemColors::Control;
			this->saturationValue->Location = System::Drawing::Point(314, 1001);
			this->saturationValue->Name = L"saturationValue";
			this->saturationValue->Size = System::Drawing::Size(50, 31);
			this->saturationValue->TabIndex = 29;
			this->saturationValue->Text = L"0";
			this->saturationValue->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// saturationTimer
			// 
			this->saturationTimer->Interval = 300;
			this->saturationTimer->Tick += gcnew System::EventHandler(this, &MyForm::saturationTimer_Tick);
			// 
			// hueSlider
			// 
			this->hueSlider->Location = System::Drawing::Point(99, 942);
			this->hueSlider->Maximum = 360;
			this->hueSlider->Name = L"hueSlider";
			this->hueSlider->Size = System::Drawing::Size(504, 90);
			this->hueSlider->TabIndex = 36;
			// 
			// percentLabel
			// 
			this->percentLabel->AutoSize = true;
			this->percentLabel->Location = System::Drawing::Point(370, 1004);
			this->percentLabel->Name = L"percentLabel";
			this->percentLabel->Size = System::Drawing::Size(31, 25);
			this->percentLabel->TabIndex = 37;
			this->percentLabel->Text = L"%";
			this->percentLabel->Visible = false;
			// 
			// hueValue
			// 
			this->hueValue->BackColor = System::Drawing::SystemColors::Control;
			this->hueValue->Location = System::Drawing::Point(314, 1001);
			this->hueValue->Name = L"hueValue";
			this->hueValue->Size = System::Drawing::Size(50, 31);
			this->hueValue->TabIndex = 38;
			this->hueValue->Text = L"0";
			this->hueValue->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// highBrightness
			// 
			this->highBrightness->AutoSize = true;
			this->highBrightness->Location = System::Drawing::Point(593, 972);
			this->highBrightness->Name = L"highBrightness";
			this->highBrightness->Size = System::Drawing::Size(68, 25);
			this->highBrightness->TabIndex = 39;
			this->highBrightness->Text = L"Bright";
			// 
			// highLabel
			// 
			this->highLabel->AutoSize = true;
			this->highLabel->Location = System::Drawing::Point(593, 972);
			this->highLabel->Name = L"highLabel";
			this->highLabel->Size = System::Drawing::Size(56, 25);
			this->highLabel->TabIndex = 40;
			this->highLabel->Text = L"High";
			// 
			// lowBrightness
			// 
			this->lowBrightness->AutoSize = true;
			this->lowBrightness->Location = System::Drawing::Point(51, 972);
			this->lowBrightness->Name = L"lowBrightness";
			this->lowBrightness->Size = System::Drawing::Size(57, 25);
			this->lowBrightness->TabIndex = 41;
			this->lowBrightness->Text = L"Dark";
			// 
			// lowLabel
			// 
			this->lowLabel->AutoSize = true;
			this->lowLabel->Location = System::Drawing::Point(51, 972);
			this->lowLabel->Name = L"lowLabel";
			this->lowLabel->Size = System::Drawing::Size(51, 25);
			this->lowLabel->TabIndex = 42;
			this->lowLabel->Text = L"Low";
			// 
			// lowHueDegrees
			// 
			this->lowHueDegrees->AutoSize = true;
			this->lowHueDegrees->Location = System::Drawing::Point(70, 972);
			this->lowHueDegrees->Name = L"lowHueDegrees";
			this->lowHueDegrees->Size = System::Drawing::Size(32, 25);
			this->lowHueDegrees->TabIndex = 43;
			this->lowHueDegrees->Text = L"0°";
			// 
			// highHueDegrees
			// 
			this->highHueDegrees->AutoSize = true;
			this->highHueDegrees->Location = System::Drawing::Point(593, 972);
			this->highHueDegrees->Name = L"highHueDegrees";
			this->highHueDegrees->Size = System::Drawing::Size(56, 25);
			this->highHueDegrees->TabIndex = 44;
			this->highHueDegrees->Text = L"360°";
			// 
			// hueTimer
			// 
			this->hueTimer->Interval = 300;
			this->hueTimer->Tick += gcnew System::EventHandler(this, &MyForm::hueTimer_Tick);
			// 
			// degreeLabel
			// 
			this->degreeLabel->AutoSize = true;
			this->degreeLabel->Location = System::Drawing::Point(370, 995);
			this->degreeLabel->Name = L"degreeLabel";
			this->degreeLabel->Size = System::Drawing::Size(20, 25);
			this->degreeLabel->TabIndex = 45;
			this->degreeLabel->Text = L"°";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1949, 1091);
			this->Controls->Add(this->degreeLabel);
			this->Controls->Add(this->highHueDegrees);
			this->Controls->Add(this->lowHueDegrees);
			this->Controls->Add(this->lowLabel);
			this->Controls->Add(this->lowBrightness);
			this->Controls->Add(this->highLabel);
			this->Controls->Add(this->highBrightness);
			this->Controls->Add(this->hueValue);
			this->Controls->Add(this->percentLabel);
			this->Controls->Add(this->hueSlider);
			this->Controls->Add(this->saturationValue);
			this->Controls->Add(this->saturationSlider);
			this->Controls->Add(this->contrastValue);
			this->Controls->Add(this->imageSaturation);
			this->Controls->Add(this->imageHue);
			this->Controls->Add(this->brightnessValue);
			this->Controls->Add(this->contrastSlider);
			this->Controls->Add(this->brightnessSlider);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightnessSlider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contrastSlider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->saturationSlider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hueSlider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: // prototypes of all event handlers / image processing functions
		System::Void uploadImage_Click(System::Object^  sender, System::EventArgs^  e); // shows open file dialog on click
		System::Void uploadImageLabel_Click(System::Object^  sender, System::EventArgs^  e); // shows open file dialog on click
		System::Void saveImage_Click(System::Object^  sender, System::EventArgs^  e); // shows save file dialog on click

		System::Void hideTempObjects(); // hides objects

		BitmapStack^ changes = gcnew BitmapStack(); // Stack object, holds previous versions of the current image
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
		System::Void invertCurrentImage(); // inversion function (direct rgb manipulation)

		System::Void grayscaleImage_Click(System::Object^  sender, System::EventArgs^  e); // grayscales current image
		System::Void grayscaleCurrentImage(); // grayscale function (direct rgb manipulation)

		System::Void imageBrightness_Click(System::Object^  sender, System::EventArgs^  e); // slider with adjusting image brightness appears
		System::Void brightnessSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void brightnessSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void brightnessSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void brightnessValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e);
		System::Void brightnessTimer_Tick(System::Object^  sender, System::EventArgs^  e);
		System::Void brightnessSlider_ValueChange(); // brightness function (color matrix manipulation)

		System::Void imageContrast_Click(System::Object^  sender, System::EventArgs^  e); // not implemented yet
		System::Void contrastSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void contrastSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void contrastSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void contrastValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e);
		System::Void contrastTimer_Tick(System::Object^  sender, System::EventArgs^  e);
		System::Void contrastSlider_ValueChange(); // contrast function (color matrix manipulation)
		
		System::Void imageHue_Click(System::Object^  sender, System::EventArgs^  e); // Not yet implemented
		System::Void hueSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void hueSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void hueSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void hueValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e);
		System::Void hueTimer_Tick(System::Object^  sender, System::EventArgs^  e);
		System::Void hueSlider_ValueChange();

		System::Void imageSaturation_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void saturationSlider_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void saturationSlider_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void saturationSlider_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void saturationValue_KeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e);
		System::Void saturationTimer_Tick(System::Object^  sender, System::EventArgs^  e);
		System::Void saturationSlider_ValueChange(); // saturation function (color matrix manipulation)

		System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e); // hide objects on form launch
};
}