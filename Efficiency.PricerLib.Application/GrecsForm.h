#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <iostream>

namespace EfficiencyPricerLibApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	/// <summary>
	/// Summary for GrecsForm
	/// </summary>
	public ref class GrecsForm : public System::Windows::Forms::Form
	{
	public:
		GrecsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_tableauGrecs = new vector<tuple<string, string, double, double, double, double> >;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GrecsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
		vector<tuple<string, string, double, double, double, double> >* _tableauGrecs;
	public:





	private: System::Windows::Forms::Button^  Closebutton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::Panel^  closePanel;
	private: System::Windows::Forms::Panel^  gridPanel;


	protected:

	public:





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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Closebutton = (gcnew System::Windows::Forms::Button());
			this->closePanel = (gcnew System::Windows::Forms::Panel());
			this->gridPanel = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->closePanel->SuspendLayout();
			this->gridPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->BackgroundColor = System::Drawing::Color::GhostWhite;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column5, this->Column4, this->Column6
			});
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ControlLight;
			this->dataGridView1->Location = System::Drawing::Point(0, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(571, 145);
			this->dataGridView1->TabIndex = 1;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Trade ID";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Type du produit";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"Delta";
			this->Column3->Name = L"Column3";
			// 
			// Column5
			// 
			this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column5->HeaderText = L"Vega";
			this->Column5->Name = L"Column5";
			// 
			// Column4
			// 
			this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column4->HeaderText = L"Gamma";
			this->Column4->Name = L"Column4";
			// 
			// Column6
			// 
			this->Column6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column6->HeaderText = L"Theta";
			this->Column6->Name = L"Column6";
			// 
			// Closebutton
			// 
			this->Closebutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Closebutton->Location = System::Drawing::Point(484, 10);
			this->Closebutton->Name = L"Closebutton";
			this->Closebutton->Size = System::Drawing::Size(87, 35);
			this->Closebutton->TabIndex = 2;
			this->Closebutton->Text = L"Fermer";
			this->Closebutton->UseVisualStyleBackColor = true;
			this->Closebutton->Click += gcnew System::EventHandler(this, &GrecsForm::Closebutton_Click);
			// 
			// closePanel
			// 
			this->closePanel->Controls->Add(this->Closebutton);
			this->closePanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->closePanel->Location = System::Drawing::Point(0, 154);
			this->closePanel->Name = L"closePanel";
			this->closePanel->Size = System::Drawing::Size(574, 48);
			this->closePanel->TabIndex = 3;
			// 
			// gridPanel
			// 
			this->gridPanel->Controls->Add(this->dataGridView1);
			this->gridPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gridPanel->Location = System::Drawing::Point(0, 0);
			this->gridPanel->Name = L"gridPanel";
			this->gridPanel->Size = System::Drawing::Size(574, 154);
			this->gridPanel->TabIndex = 4;
			// 
			// GrecsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(574, 202);
			this->Controls->Add(this->gridPanel);
			this->Controls->Add(this->closePanel);
			this->MinimumSize = System::Drawing::Size(590, 241);
			this->Name = L"GrecsForm";
			this->Text = L"Facteurs de risque";
			this->Load += gcnew System::EventHandler(this, &GrecsForm::GrecsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->closePanel->ResumeLayout(false);
			this->gridPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	public:
		property vector<tuple<string, string, double, double, double, double> >* tableauGrecs
		{
			vector<tuple<string, string, double, double, double, double> >* get()
			{
				return _tableauGrecs;
			}
			void set(vector<tuple<string, string, double, double, double, double> > * tabGrecs)
			{
				_tableauGrecs = NULL;

				bool isNotNull = tabGrecs == NULL ? false : true;

				if (isNotNull) {
					_tableauGrecs = tabGrecs;
				}

				dataGridView1->Enabled = isNotNull;
				//CloseButton->Enabled = isNotNull;
			}
		}

	private: System::Void Closebutton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void GrecsForm_Load(System::Object^  sender, System::EventArgs^  e) {
	if (_tableauGrecs != NULL && _tableauGrecs->size() >0) {
		ShowDataGridGrecs();
	}
}

private:
	System::Void ShowDataGridGrecs()
	{
		dataGridView1->Rows->Add(_tableauGrecs->size());
		// Afficher les éléments du tableau des résultats dans le dataGrid.
		for (std::size_t indice = 0; indice < _tableauGrecs->size(); indice++)
		{
			dataGridView1->Rows[indice]->Cells[0]->Value
				= gcnew String(std::get<0>(_tableauGrecs[0][indice]).c_str());
			dataGridView1->Rows[indice]->Cells[1]->Value
				= gcnew String(std::get<1>(_tableauGrecs[0][indice]).c_str());
			dataGridView1->Rows[indice]->Cells[2]->Value
				= std::get<2>(_tableauGrecs[0][indice]).ToString();
			dataGridView1->Rows[indice]->Cells[3]->Value
				= std::get<3>(_tableauGrecs[0][indice]).ToString();
			dataGridView1->Rows[indice]->Cells[4]->Value
				= std::get<4>(_tableauGrecs[0][indice]).ToString();
			dataGridView1->Rows[indice]->Cells[5]->Value
				= std::get<5>(_tableauGrecs[0][indice]).ToString();
		}
	}


};
}
