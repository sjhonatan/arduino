#pragma once

namespace ASA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ASA_GUI
	/// </summary>
	public ref class ASA_GUI : public System::Windows::Forms::Form
	{
	public:
		ASA_GUI(void)
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
		~ASA_GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tbFrequencia;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chVT;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chIT;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chIV;
	private: System::Windows::Forms::Button^  btnOk;





	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbPorta;

	private: System::Windows::Forms::Label^  label2;
	private: System::IO::Ports::SerialPort^  portaSerial;
	private: System::Windows::Forms::Timer^  leituraPorta;
	private: System::Windows::Forms::Button^  btnComecar;

	private: System::ComponentModel::IContainer^  components;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tbFrequencia = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chVT = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chIT = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chIV = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbPorta = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->portaSerial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->leituraPorta = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnComecar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chVT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chIT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chIV))->BeginInit();
			this->SuspendLayout();
			// 
			// tbFrequencia
			// 
			this->tbFrequencia->Location = System::Drawing::Point(26, 89);
			this->tbFrequencia->Name = L"tbFrequencia";
			this->tbFrequencia->Size = System::Drawing::Size(100, 20);
			this->tbFrequencia->TabIndex = 0;
			this->tbFrequencia->Text = L"1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Frequência (Hz)";
			// 
			// chVT
			// 
			chartArea1->Name = L"ChartArea1";
			this->chVT->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chVT->Legends->Add(legend1);
			this->chVT->Location = System::Drawing::Point(513, 265);
			this->chVT->Name = L"chVT";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"V x t";
			this->chVT->Series->Add(series1);
			this->chVT->Size = System::Drawing::Size(334, 202);
			this->chVT->TabIndex = 2;
			this->chVT->Text = L"chart1";
			// 
			// chIT
			// 
			chartArea2->Name = L"ChartArea1";
			this->chIT->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chIT->Legends->Add(legend2);
			this->chIT->Location = System::Drawing::Point(513, 60);
			this->chIT->Name = L"chIT";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"I x t";
			this->chIT->Series->Add(series2);
			this->chIT->Size = System::Drawing::Size(334, 199);
			this->chIT->TabIndex = 3;
			this->chIT->Text = L"chart2";
			// 
			// chIV
			// 
			chartArea3->Name = L"ChartArea1";
			this->chIV->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chIV->Legends->Add(legend3);
			this->chIV->Location = System::Drawing::Point(26, 115);
			this->chIV->Name = L"chIV";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->Name = L"I x V ( XY )";
			this->chIV->Series->Add(series3);
			this->chIV->Size = System::Drawing::Size(481, 352);
			this->chIV->TabIndex = 4;
			this->chIV->Text = L"chart3";
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(132, 89);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(42, 20);
			this->btnOk->TabIndex = 8;
			this->btnOk->Text = L"Ok";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &ASA_GUI::btnOk_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(217, 87);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(237, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Análise de Assinatura Analógica";
			// 
			// tbPorta
			// 
			this->tbPorta->Location = System::Drawing::Point(26, 42);
			this->tbPorta->Name = L"tbPorta";
			this->tbPorta->Size = System::Drawing::Size(100, 20);
			this->tbPorta->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"COM ( Arduino )";
			// 
			// leituraPorta
			// 
			this->leituraPorta->Interval = 1000;
			this->leituraPorta->Tick += gcnew System::EventHandler(this, &ASA_GUI::leituraPorta_Tick);
			// 
			// btnComecar
			// 
			this->btnComecar->Location = System::Drawing::Point(133, 42);
			this->btnComecar->Name = L"btnComecar";
			this->btnComecar->Size = System::Drawing::Size(75, 20);
			this->btnComecar->TabIndex = 12;
			this->btnComecar->Text = L"Começar";
			this->btnComecar->UseVisualStyleBackColor = true;
			this->btnComecar->Click += gcnew System::EventHandler(this, &ASA_GUI::btnComecar_Click);
			// 
			// ASA_GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(859, 479);
			this->Controls->Add(this->btnComecar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbPorta);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->chIV);
			this->Controls->Add(this->chIT);
			this->Controls->Add(this->chVT);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbFrequencia);
			this->Name = L"ASA_GUI";
			this->Text = L"ASA_GUI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chVT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chIT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chIV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
double contador = 0;
private: System::Void btnOk_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^ comando = gcnew String("");
	portaSerial->PortName = tbPorta->Text;
	portaSerial->Open();
	portaSerial->WriteLine(tbFrequencia->Text);
	System::Threading::Thread::Sleep(500);
	portaSerial->Close();
}
private: System::Void leituraPorta_Tick(System::Object^  sender, System::EventArgs^  e) {
	String ^ comando = portaSerial->ReadLine();
	array<String^>^ substring = comando->Split(' ');
	double corrente;
	double tensao;
	if (substring[0] == "I"){
		corrente = Convert::ToDouble(substring[1]);
	}
	if (substring[0] == "V"){
		tensao = Convert::ToDouble(substring[1]);
	}
	chVT->Series["V x t"]->Points->AddXY(contador, Math::Sin(tensao));
	Refresh();
	chIT->Series["I x t"]->Points->AddXY(contador, Math::Sin(corrente));
	Refresh();
	chIV->Series["I x V"]->Points->AddXY(contador, Math::Sin(tensao));
	Refresh();
	contador += .1;
}
private: System::Void btnComecar_Click(System::Object^  sender, System::EventArgs^  e) {
	leituraPorta->Enabled = true;
}
};
}
