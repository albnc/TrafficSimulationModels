#pragma once

namespace corsimTS0 {

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
		
	public:
		void TS0process(int value) 
		{
			pgbProcess->Value = value;
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
	private: System::Windows::Forms::OpenFileDialog^  dlgOpenFile;
	private: System::Windows::Forms::Button^  btnFileTS0;

	private: System::Windows::Forms::Button^  btnRun;
	protected: 



	private: System::Windows::Forms::ProgressBar^  pgbProcess;
	private: System::Windows::Forms::TextBox^  txbTS0file;



	private: System::Windows::Forms::GroupBox^  gpbTS0;
	private: System::Windows::Forms::GroupBox^  gpbTSI;
	private: System::Windows::Forms::TextBox^  txbTSIfile;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  lblFinal;


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
			this->dlgOpenFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnFileTS0 = (gcnew System::Windows::Forms::Button());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->pgbProcess = (gcnew System::Windows::Forms::ProgressBar());
			this->txbTS0file = (gcnew System::Windows::Forms::TextBox());
			this->gpbTS0 = (gcnew System::Windows::Forms::GroupBox());
			this->gpbTSI = (gcnew System::Windows::Forms::GroupBox());
			this->txbTSIfile = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblFinal = (gcnew System::Windows::Forms::Label());
			this->gpbTS0->SuspendLayout();
			this->gpbTSI->SuspendLayout();
			this->SuspendLayout();
			// 
			// dlgOpenFile
			// 
			this->dlgOpenFile->Filter = L"ts0 files | *.ts0";
			this->dlgOpenFile->InitialDirectory = L"C:\\";
			this->dlgOpenFile->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::dlgOpenFile_FileOk);
			// 
			// btnFileTS0
			// 
			this->btnFileTS0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnFileTS0->Location = System::Drawing::Point(9, 32);
			this->btnFileTS0->Name = L"btnFileTS0";
			this->btnFileTS0->Size = System::Drawing::Size(60, 23);
			this->btnFileTS0->TabIndex = 0;
			this->btnFileTS0->Text = L"TS0 file";
			this->btnFileTS0->UseVisualStyleBackColor = true;
			this->btnFileTS0->Click += gcnew System::EventHandler(this, &MyForm::btnFile_Click);
			// 
			// btnRun
			// 
			this->btnRun->Enabled = false;
			this->btnRun->Location = System::Drawing::Point(434, 223);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(65, 25);
			this->btnRun->TabIndex = 1;
			this->btnRun->Text = L"Process";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &MyForm::btnRun_Click);
			// 
			// pgbProcess
			// 
			this->pgbProcess->Location = System::Drawing::Point(93, 223);
			this->pgbProcess->Name = L"pgbProcess";
			this->pgbProcess->Size = System::Drawing::Size(323, 25);
			this->pgbProcess->TabIndex = 3;
			// 
			// txbTS0file
			// 
			this->txbTS0file->Enabled = false;
			this->txbTS0file->Location = System::Drawing::Point(75, 35);
			this->txbTS0file->Name = L"txbTS0file";
			this->txbTS0file->Size = System::Drawing::Size(403, 20);
			this->txbTS0file->TabIndex = 4;
			// 
			// gpbTS0
			// 
			this->gpbTS0->Controls->Add(this->txbTS0file);
			this->gpbTS0->Controls->Add(this->btnFileTS0);
			this->gpbTS0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gpbTS0->Location = System::Drawing::Point(15, 22);
			this->gpbTS0->Name = L"gpbTS0";
			this->gpbTS0->Size = System::Drawing::Size(485, 80);
			this->gpbTS0->TabIndex = 5;
			this->gpbTS0->TabStop = false;
			this->gpbTS0->Text = L"Vehicle Message";
			// 
			// gpbTSI
			// 
			this->gpbTSI->Controls->Add(this->txbTSIfile);
			this->gpbTSI->Controls->Add(this->button1);
			this->gpbTSI->Enabled = false;
			this->gpbTSI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gpbTSI->Location = System::Drawing::Point(15, 125);
			this->gpbTSI->Name = L"gpbTSI";
			this->gpbTSI->Size = System::Drawing::Size(485, 80);
			this->gpbTSI->TabIndex = 6;
			this->gpbTSI->TabStop = false;
			this->gpbTSI->Text = L"Link Mesure of Effectiveness (MOEs)";
			// 
			// txbTSIfile
			// 
			this->txbTSIfile->Enabled = false;
			this->txbTSIfile->Location = System::Drawing::Point(78, 35);
			this->txbTSIfile->Name = L"txbTSIfile";
			this->txbTSIfile->Size = System::Drawing::Size(400, 20);
			this->txbTSIfile->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(9, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"TSI file";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// lblFinal
			// 
			this->lblFinal->AutoSize = true;
			this->lblFinal->ForeColor = System::Drawing::Color::Red;
			this->lblFinal->Location = System::Drawing::Point(335, 259);
			this->lblFinal->Name = L"lblFinal";
			this->lblFinal->Size = System::Drawing::Size(78, 13);
			this->lblFinal->TabIndex = 7;
			this->lblFinal->Text = L"File completed!";
			this->lblFinal->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 281);
			this->Controls->Add(this->lblFinal);
			this->Controls->Add(this->gpbTSI);
			this->Controls->Add(this->gpbTS0);
			this->Controls->Add(this->pgbProcess);
			this->Controls->Add(this->btnRun);
			this->Name = L"MyForm";
			this->Text = L"Corsim Processor Output Files";
			this->gpbTS0->ResumeLayout(false);
			this->gpbTS0->PerformLayout();
			this->gpbTSI->ResumeLayout(false);
			this->gpbTSI->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnFile_Click(System::Object^  sender, System::EventArgs^  e) {
				 dlgOpenFile->ShowDialog();
			 }
	private: System::Void dlgOpenFile_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
				txbTS0file->Text = dlgOpenFile->FileName;
				if ( txbTS0file->Text != "" ) { // && (txbTSIfile->Text != "") {
					btnRun->Enabled = true;
				}
		 }
	private: System::Void btnRun_Click(System::Object^  sender, System::EventArgs^  e) {
			pgbProcess->Value = 0;
			//System::String^ managedString = txbTS0file->Text;
			msclr::interop::marshal_context context;
			std::string fnamets0 = context.marshal_as<std::string>(txbTS0file->Text);
			
			pgbProcess->Value = 15;
			int a = processTS0file( fnamets0 );

			if(!a){
				pgbProcess->Value = 100;
			}
			lblFinal->Visible = true;
		 }
};
}
