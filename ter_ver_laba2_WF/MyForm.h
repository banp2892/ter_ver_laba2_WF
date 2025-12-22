#pragma once
#include "MyMath.h"
#include "InputForm.h" 

// Директива для компилятора C++/CLI, указывающая на сборку ZedGraph
// Убедитесь, что файл ZedGraph.dll доступен по пути поиска или находится в папке проекта/сборки.


namespace terverlaba2WF {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace ZedGraph; // Пространство имен для графической библиотеки
    using namespace System::Collections::Generic; // Для работы с управляемыми списками и std::vector

    // Внимание: для использования std::vector<double> вам нужна доступная реализация MyMath.h и MyMath.cpp

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();

           
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

    private:
        // --- Элементы управления, определенные в Дизайнере ---
        System::Windows::Forms::Label^ label_k;
        System::Windows::Forms::TextBox^ textBox_k;
        System::Windows::Forms::Label^ label_lambda;
        System::Windows::Forms::TextBox^ textBox_lambda;
        System::Windows::Forms::Label^ label_N;
        System::Windows::Forms::TextBox^ textBox_N;
        System::Windows::Forms::Button^ button_Start;
        System::Windows::Forms::DataGridView^ dataGridView_Results;
        System::Windows::Forms::DataGridView^ dataGridView_Stats;

        // --- Столбцы DataGridView (часть сгенерированного кода) ---
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ i;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ X_i;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ E_eta;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ x;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ raznost_E_eta_x;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ D_eta;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ S_kvadrat;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ raznost_disp;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Me_eta;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Me_hat;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Me_diff;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ R;

           // --- ОБЪЯВЛЕНИЕ ГРАФИЧЕСКОГО КОНТРОЛА И МЕТОДА ---
    private: ZedGraph::ZedGraphControl^ zedGraphControl1;
    private: System::Windows::Forms::Label^ mera_rashojdenia;
    private: ZedGraph::ZedGraphControl^ gistogramma;
    private: System::Windows::Forms::DataGridView^ part2_table;

    private: System::Windows::Forms::Label^ label_max_density_deviation;
    private: System::Windows::Forms::TextBox^ m_gist;

    private: System::Windows::Forms::Label^ gist_label;
    private: System::Windows::Forms::Label^ k_enterval_label;
    private: System::Windows::Forms::TextBox^ k_intervalov_path_3;
    private: System::Windows::Forms::CheckBox^ checkBox_part1;
    private: System::Windows::Forms::TextBox^ textBox_alpha;
    private: System::Windows::Forms::Label^ label_alpha;
    private: System::Windows::Forms::Label^ part_3_res;

    private: System::Windows::Forms::Label^ gipoteza;
    private: System::Windows::Forms::DataGridView^ datagrid_part_3;

    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
    private: System::Windows::Forms::DataGridView^ grid_part_3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ alpha_column;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ p;
    private: System::Windows::Forms::Label^ path_3_number_of_try;
    private: System::Windows::Forms::TextBox^ text_box_part_3_aaa;




















    private:
        
        // ----------------------------------------------------


        System::ComponentModel::IContainer^ components;

        // --- Required designer variable. ---

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->label_k = (gcnew System::Windows::Forms::Label());
            this->textBox_k = (gcnew System::Windows::Forms::TextBox());
            this->label_lambda = (gcnew System::Windows::Forms::Label());
            this->textBox_lambda = (gcnew System::Windows::Forms::TextBox());
            this->label_N = (gcnew System::Windows::Forms::Label());
            this->textBox_N = (gcnew System::Windows::Forms::TextBox());
            this->button_Start = (gcnew System::Windows::Forms::Button());
            this->dataGridView_Results = (gcnew System::Windows::Forms::DataGridView());
            this->i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->X_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridView_Stats = (gcnew System::Windows::Forms::DataGridView());
            this->E_eta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->x = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->raznost_E_eta_x = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->D_eta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->S_kvadrat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->raznost_disp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Me_eta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Me_hat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Me_diff = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->R = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
            this->mera_rashojdenia = (gcnew System::Windows::Forms::Label());
            this->gistogramma = (gcnew ZedGraph::ZedGraphControl());
            this->part2_table = (gcnew System::Windows::Forms::DataGridView());
            this->m_gist = (gcnew System::Windows::Forms::TextBox());
            this->gist_label = (gcnew System::Windows::Forms::Label());
            this->k_enterval_label = (gcnew System::Windows::Forms::Label());
            this->k_intervalov_path_3 = (gcnew System::Windows::Forms::TextBox());
            this->checkBox_part1 = (gcnew System::Windows::Forms::CheckBox());
            this->textBox_alpha = (gcnew System::Windows::Forms::TextBox());
            this->label_alpha = (gcnew System::Windows::Forms::Label());
            this->part_3_res = (gcnew System::Windows::Forms::Label());
            this->gipoteza = (gcnew System::Windows::Forms::Label());
            this->datagrid_part_3 = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->grid_part_3 = (gcnew System::Windows::Forms::DataGridView());
            this->alpha_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->p = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->path_3_number_of_try = (gcnew System::Windows::Forms::Label());
            this->text_box_part_3_aaa = (gcnew System::Windows::Forms::TextBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Results))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Stats))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->part2_table))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datagrid_part_3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_part_3))->BeginInit();
            this->SuspendLayout();
            // 
            // label_k
            // 
            this->label_k->AutoSize = true;
            this->label_k->Location = System::Drawing::Point(20, 20);
            this->label_k->Name = L"label_k";
            this->label_k->Size = System::Drawing::Size(92, 13);
            this->label_k->TabIndex = 0;
            this->label_k->Text = L"Число людей (k):";
            // 
            // textBox_k
            // 
            this->textBox_k->Location = System::Drawing::Point(149, 17);
            this->textBox_k->Name = L"textBox_k";
            this->textBox_k->Size = System::Drawing::Size(100, 20);
            this->textBox_k->TabIndex = 1;
            this->textBox_k->Text = L"7";
            // 
            // label_lambda
            // 
            this->label_lambda->AutoSize = true;
            this->label_lambda->Location = System::Drawing::Point(20, 50);
            this->label_lambda->Name = L"label_lambda";
            this->label_lambda->Size = System::Drawing::Size(130, 13);
            this->label_lambda->TabIndex = 2;
            this->label_lambda->Text = L"Среднее опоздание (λk):";
            // 
            // textBox_lambda
            // 
            this->textBox_lambda->Location = System::Drawing::Point(149, 47);
            this->textBox_lambda->Name = L"textBox_lambda";
            this->textBox_lambda->Size = System::Drawing::Size(100, 20);
            this->textBox_lambda->TabIndex = 3;
            this->textBox_lambda->Text = L"0,5";
            // 
            // label_N
            // 
            this->label_N->AutoSize = true;
            this->label_N->Location = System::Drawing::Point(20, 80);
            this->label_N->Name = L"label_N";
            this->label_N->Size = System::Drawing::Size(109, 13);
            this->label_N->TabIndex = 4;
            this->label_N->Text = L"Объем выборки (N):";
            // 
            // textBox_N
            // 
            this->textBox_N->Location = System::Drawing::Point(149, 77);
            this->textBox_N->Name = L"textBox_N";
            this->textBox_N->Size = System::Drawing::Size(100, 20);
            this->textBox_N->TabIndex = 5;
            this->textBox_N->Text = L"125";
            // 
            // button_Start
            // 
            this->button_Start->Location = System::Drawing::Point(255, 17);
            this->button_Start->Name = L"button_Start";
            this->button_Start->Size = System::Drawing::Size(120, 80);
            this->button_Start->TabIndex = 6;
            this->button_Start->Text = L"СТАРТ ВЫЧИСЛЕНИЙ";
            this->button_Start->UseVisualStyleBackColor = true;
            this->button_Start->Click += gcnew System::EventHandler(this, &MyForm::button_Start_Click);
            // 
            // dataGridView_Results
            // 
            this->dataGridView_Results->AllowUserToAddRows = false;
            this->dataGridView_Results->AllowUserToDeleteRows = false;
            this->dataGridView_Results->AllowUserToResizeColumns = false;
            this->dataGridView_Results->AllowUserToResizeRows = false;
            this->dataGridView_Results->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_Results->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->i,
                    this->X_i
            });
            this->dataGridView_Results->Location = System::Drawing::Point(23, 113);
            this->dataGridView_Results->Name = L"dataGridView_Results";
            this->dataGridView_Results->RowHeadersVisible = false;
            this->dataGridView_Results->Size = System::Drawing::Size(150, 490);
            this->dataGridView_Results->TabIndex = 9;
            // 
            // i
            // 
            this->i->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->i->HeaderText = L"i";
            this->i->Name = L"i";
            this->i->ReadOnly = true;
            this->i->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->i->Width = 34;
            // 
            // X_i
            // 
            this->X_i->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->X_i->HeaderText = L"X_i";
            this->X_i->Name = L"X_i";
            this->X_i->ReadOnly = true;
            // 
            // dataGridView_Stats
            // 
            this->dataGridView_Stats->AllowUserToAddRows = false;
            this->dataGridView_Stats->AllowUserToDeleteRows = false;
            this->dataGridView_Stats->AllowUserToResizeColumns = false;
            this->dataGridView_Stats->AllowUserToResizeRows = false;
            this->dataGridView_Stats->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_Stats->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
                this->E_eta,
                    this->x, this->raznost_E_eta_x, this->D_eta, this->S_kvadrat, this->raznost_disp, this->Me_eta, this->Me_hat, this->Me_diff,
                    this->R
            });
            this->dataGridView_Stats->Location = System::Drawing::Point(179, 113);
            this->dataGridView_Stats->Name = L"dataGridView_Stats";
            this->dataGridView_Stats->RowHeadersVisible = false;
            this->dataGridView_Stats->Size = System::Drawing::Size(735, 49);
            this->dataGridView_Stats->TabIndex = 7;
            // 
            // E_eta
            // 
            this->E_eta->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->E_eta->HeaderText = L"E_eta";
            this->E_eta->Name = L"E_eta";
            this->E_eta->ReadOnly = true;
            this->E_eta->Width = 60;
            // 
            // x
            // 
            this->x->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->x->HeaderText = L"x";
            this->x->Name = L"x";
            this->x->ReadOnly = true;
            this->x->Width = 37;
            // 
            // raznost_E_eta_x
            // 
            this->raznost_E_eta_x->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->raznost_E_eta_x->HeaderText = L"| E_eta - x |";
            this->raznost_E_eta_x->Name = L"raznost_E_eta_x";
            this->raznost_E_eta_x->ReadOnly = true;
            this->raznost_E_eta_x->Width = 84;
            // 
            // D_eta
            // 
            this->D_eta->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->D_eta->HeaderText = L"D_eta";
            this->D_eta->Name = L"D_eta";
            this->D_eta->ReadOnly = true;
            this->D_eta->Width = 61;
            // 
            // S_kvadrat
            // 
            this->S_kvadrat->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->S_kvadrat->HeaderText = L"S_2";
            this->S_kvadrat->Name = L"S_kvadrat";
            this->S_kvadrat->ReadOnly = true;
            this->S_kvadrat->Width = 51;
            // 
            // raznost_disp
            // 
            this->raznost_disp->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->raznost_disp->HeaderText = L"| D_eta - S_2 |";
            this->raznost_disp->Name = L"raznost_disp";
            this->raznost_disp->ReadOnly = true;
            this->raznost_disp->Width = 99;
            // 
            // Me_eta
            // 
            this->Me_eta->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->Me_eta->HeaderText = L"Me_t";
            this->Me_eta->Name = L"Me_eta";
            this->Me_eta->ReadOnly = true;
            this->Me_eta->Width = 56;
            // 
            // Me_hat
            // 
            this->Me_hat->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->Me_hat->HeaderText = L"Me_s";
            this->Me_hat->Name = L"Me_hat";
            this->Me_hat->ReadOnly = true;
            this->Me_hat->Width = 58;
            // 
            // Me_diff
            // 
            this->Me_diff->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
            this->Me_diff->HeaderText = L"| Me_t - Me_s |";
            this->Me_diff->Name = L"Me_diff";
            this->Me_diff->ReadOnly = true;
            this->Me_diff->Width = 101;
            // 
            // R
            // 
            this->R->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->R->HeaderText = L"R";
            this->R->Name = L"R";
            this->R->ReadOnly = true;
            // 
            // zedGraphControl1
            // 
            this->zedGraphControl1->Location = System::Drawing::Point(179, 283);
            this->zedGraphControl1->Name = L"zedGraphControl1";
            this->zedGraphControl1->ScrollGrace = 0;
            this->zedGraphControl1->ScrollMaxX = 0;
            this->zedGraphControl1->ScrollMaxY = 0;
            this->zedGraphControl1->ScrollMaxY2 = 0;
            this->zedGraphControl1->ScrollMinX = 0;
            this->zedGraphControl1->ScrollMinY = 0;
            this->zedGraphControl1->ScrollMinY2 = 0;
            this->zedGraphControl1->Size = System::Drawing::Size(544, 448);
            this->zedGraphControl1->TabIndex = 10;
            // 
            // mera_rashojdenia
            // 
            this->mera_rashojdenia->AutoSize = true;
            this->mera_rashojdenia->Location = System::Drawing::Point(1288, 112);
            this->mera_rashojdenia->Name = L"mera_rashojdenia";
            this->mera_rashojdenia->Size = System::Drawing::Size(51, 13);
            this->mera_rashojdenia->TabIndex = 11;
            this->mera_rashojdenia->Text = L"Мера D: ";
            // 
            // gistogramma
            // 
            this->gistogramma->Location = System::Drawing::Point(729, 283);
            this->gistogramma->Name = L"gistogramma";
            this->gistogramma->ScrollGrace = 0;
            this->gistogramma->ScrollMaxX = 0;
            this->gistogramma->ScrollMaxY = 0;
            this->gistogramma->ScrollMaxY2 = 0;
            this->gistogramma->ScrollMinX = 0;
            this->gistogramma->ScrollMinY = 0;
            this->gistogramma->ScrollMinY2 = 0;
            this->gistogramma->Size = System::Drawing::Size(544, 448);
            this->gistogramma->TabIndex = 12;
            // 
            // part2_table
            // 
            this->part2_table->AllowUserToAddRows = false;
            this->part2_table->AllowUserToDeleteRows = false;
            this->part2_table->AllowUserToResizeColumns = false;
            this->part2_table->AllowUserToResizeRows = false;
            this->part2_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->part2_table->Location = System::Drawing::Point(179, 168);
            this->part2_table->Name = L"part2_table";
            this->part2_table->RowHeadersVisible = false;
            this->part2_table->Size = System::Drawing::Size(735, 109);
            this->part2_table->TabIndex = 13;
            // 
            // m_gist
            // 
            this->m_gist->Location = System::Drawing::Point(585, 20);
            this->m_gist->Name = L"m_gist";
            this->m_gist->Size = System::Drawing::Size(100, 20);
            this->m_gist->TabIndex = 14;
            this->m_gist->Text = L"8";
            // 
            // gist_label
            // 
            this->gist_label->AutoSize = true;
            this->gist_label->Location = System::Drawing::Point(384, 20);
            this->gist_label->Name = L"gist_label";
            this->gist_label->Size = System::Drawing::Size(195, 13);
            this->gist_label->TabIndex = 15;
            this->gist_label->Text = L"Количество разбиений гистограммы";
            // 
            // k_enterval_label
            // 
            this->k_enterval_label->AutoSize = true;
            this->k_enterval_label->Location = System::Drawing::Point(691, 20);
            this->k_enterval_label->Name = L"k_enterval_label";
            this->k_enterval_label->Size = System::Drawing::Size(374, 13);
            this->k_enterval_label->TabIndex = 16;
            this->k_enterval_label->Text = L"Количество интервалов разбиения для вычисления функции хи-квадрат";
            // 
            // k_intervalov_path_3
            // 
            this->k_intervalov_path_3->Location = System::Drawing::Point(1071, 17);
            this->k_intervalov_path_3->Name = L"k_intervalov_path_3";
            this->k_intervalov_path_3->Size = System::Drawing::Size(100, 20);
            this->k_intervalov_path_3->TabIndex = 17;
            this->k_intervalov_path_3->Text = L"5";
            // 
            // checkBox_part1
            // 
            this->checkBox_part1->AutoSize = true;
            this->checkBox_part1->Location = System::Drawing::Point(387, 80);
            this->checkBox_part1->Name = L"checkBox_part1";
            this->checkBox_part1->Size = System::Drawing::Size(130, 17);
            this->checkBox_part1->TabIndex = 18;
            this->checkBox_part1->Text = L"Закрепить значения";
            this->checkBox_part1->UseVisualStyleBackColor = true;
            this->checkBox_part1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_FixParameters_CheckedChanged);
            // 
            // textBox_alpha
            // 
            this->textBox_alpha->Location = System::Drawing::Point(949, 51);
            this->textBox_alpha->Name = L"textBox_alpha";
            this->textBox_alpha->Size = System::Drawing::Size(100, 20);
            this->textBox_alpha->TabIndex = 19;
            this->textBox_alpha->Text = L"0,05";
            // 
            // label_alpha
            // 
            this->label_alpha->AutoSize = true;
            this->label_alpha->Location = System::Drawing::Point(691, 54);
            this->label_alpha->Name = L"label_alpha";
            this->label_alpha->Size = System::Drawing::Size(252, 13);
            this->label_alpha->TabIndex = 20;
            this->label_alpha->Text = L"Уровень значимости (значение альфа от 0 до 1)";
            // 
            // part_3_res
            // 
            this->part_3_res->AutoSize = true;
            this->part_3_res->Location = System::Drawing::Point(1288, 138);
            this->part_3_res->Name = L"part_3_res";
            this->part_3_res->Size = System::Drawing::Size(65, 13);
            this->part_3_res->TabIndex = 21;
            this->part_3_res->Text = L"Результат: ";
            // 
            // gipoteza
            // 
            this->gipoteza->AutoSize = true;
            this->gipoteza->Location = System::Drawing::Point(1288, 167);
            this->gipoteza->Name = L"gipoteza";
            this->gipoteza->Size = System::Drawing::Size(105, 13);
            this->gipoteza->TabIndex = 23;
            this->gipoteza->Text = L"Приняли гипотезу: ";
            // 
            // datagrid_part_3
            // 
            this->datagrid_part_3->AllowUserToAddRows = false;
            this->datagrid_part_3->AllowUserToDeleteRows = false;
            this->datagrid_part_3->AllowUserToResizeColumns = false;
            this->datagrid_part_3->AllowUserToResizeRows = false;
            this->datagrid_part_3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->datagrid_part_3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewTextBoxColumn1,
                    this->dataGridViewTextBoxColumn2
            });
            this->datagrid_part_3->Location = System::Drawing::Point(1291, 283);
            this->datagrid_part_3->Name = L"datagrid_part_3";
            this->datagrid_part_3->RowHeadersVisible = false;
            this->datagrid_part_3->Size = System::Drawing::Size(150, 448);
            this->datagrid_part_3->TabIndex = 24;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
            this->dataGridViewTextBoxColumn1->HeaderText = L"i";
            this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
            this->dataGridViewTextBoxColumn1->ReadOnly = true;
            this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewTextBoxColumn1->Width = 34;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this->dataGridViewTextBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->dataGridViewTextBoxColumn2->HeaderText = L"P_i";
            this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
            this->dataGridViewTextBoxColumn2->ReadOnly = true;
            // 
            // grid_part_3
            // 
            this->grid_part_3->AllowUserToAddRows = false;
            this->grid_part_3->AllowUserToDeleteRows = false;
            this->grid_part_3->AllowUserToResizeColumns = false;
            this->grid_part_3->AllowUserToResizeRows = false;
            this->grid_part_3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->grid_part_3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->alpha_column,
                    this->p
            });
            this->grid_part_3->Location = System::Drawing::Point(927, 113);
            this->grid_part_3->Name = L"grid_part_3";
            this->grid_part_3->RowHeadersVisible = false;
            this->grid_part_3->Size = System::Drawing::Size(346, 164);
            this->grid_part_3->TabIndex = 25;
            // 
            // alpha_column
            // 
            this->alpha_column->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->alpha_column->HeaderText = L"№ Попытки / p-value";
            this->alpha_column->Name = L"alpha_column";
            // 
            // p
            // 
            this->p->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->p->HeaderText = L"Результат (H0)";
            this->p->Name = L"p";
            // 
            // path_3_number_of_try
            // 
            this->path_3_number_of_try->AutoSize = true;
            this->path_3_number_of_try->Location = System::Drawing::Point(1163, 54);
            this->path_3_number_of_try->Name = L"path_3_number_of_try";
            this->path_3_number_of_try->Size = System::Drawing::Size(105, 13);
            this->path_3_number_of_try->TabIndex = 26;
            this->path_3_number_of_try->Text = L"Количество циклов";
            // 
            // text_box_part_3_aaa
            // 
            this->text_box_part_3_aaa->Location = System::Drawing::Point(1057, 50);
            this->text_box_part_3_aaa->Name = L"text_box_part_3_aaa";
            this->text_box_part_3_aaa->Size = System::Drawing::Size(100, 20);
            this->text_box_part_3_aaa->TabIndex = 27;
            this->text_box_part_3_aaa->Text = L"100";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1561, 743);
            this->Controls->Add(this->text_box_part_3_aaa);
            this->Controls->Add(this->path_3_number_of_try);
            this->Controls->Add(this->grid_part_3);
            this->Controls->Add(this->datagrid_part_3);
            this->Controls->Add(this->gipoteza);
            this->Controls->Add(this->part_3_res);
            this->Controls->Add(this->label_alpha);
            this->Controls->Add(this->textBox_alpha);
            this->Controls->Add(this->checkBox_part1);
            this->Controls->Add(this->k_intervalov_path_3);
            this->Controls->Add(this->k_enterval_label);
            this->Controls->Add(this->gist_label);
            this->Controls->Add(this->m_gist);
            this->Controls->Add(this->part2_table);
            this->Controls->Add(this->gistogramma);
            this->Controls->Add(this->mera_rashojdenia);
            this->Controls->Add(this->zedGraphControl1);
            this->Controls->Add(this->dataGridView_Stats);
            this->Controls->Add(this->dataGridView_Results);
            this->Controls->Add(this->button_Start);
            this->Controls->Add(this->textBox_N);
            this->Controls->Add(this->label_N);
            this->Controls->Add(this->textBox_lambda);
            this->Controls->Add(this->label_lambda);
            this->Controls->Add(this->textBox_k);
            this->Controls->Add(this->label_k);
            this->Name = L"MyForm";
            this->Text = L"Лабораторная работа 27: Экспоненциальное распределение";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Results))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Stats))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->part2_table))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datagrid_part_3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_part_3))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
        MyMath* math;
        List<double>^ chiSquareNodes;
        std::vector<double>* chi_square_nodes;
        System::Collections::Generic::List<double>^ lastUsedZNodes;

        double lastLambda = -1.0;
        int lastN = -1;
        int lastK_part_1 = -1;

        // ------------------------------------------------------------------
        // РЕАЛИЗАЦИЯ МЕТОДА ОТРЕСОВКИ
        // ------------------------------------------------------------------
        void DrawCDFGraphs(const std::vector<double>& sample, double lambda_param)
        {
            GraphPane^ myPane = zedGraphControl1->GraphPane;
            myPane->CurveList->Clear();

            // 1. Расчет масштаба
            // Для CDF логика та же: после 4-х мат. ожиданий функция уже практически равна 1.0
            double theoretical_mean = 1.0 / lambda_param;
            double smartMaxX = theoretical_mean * 4.0;

            // Если выборка пуста, maxX берем из теории, если нет — из конца отсортированного массива
            // (ВАЖНО: sample должен быть отсортирован по возрастанию!)
            double actual_data_max = sample.empty() ? smartMaxX : sample.back();
            double final_maxX = (actual_data_max > smartMaxX) ? actual_data_max : smartMaxX;

            // 2. Построение Эмпирической функции (ступеньки)
            PointPairList^ empCDFList = gcnew PointPairList();
            double N = (double)sample.size();

            empCDFList->Add(0.0, 0.0);
            for (size_t i = 0; i < sample.size(); ++i)
            {
                double x = sample[i];
                double F_val = (double)(i + 1) / N;

                // Рисуем только то, что попадает в видимую область
                if (x > final_maxX * 1.5) break;

                if (i > 0) {
                    empCDFList->Add(x, (double)i / N);
                }
                empCDFList->Add(x, F_val);
            }

            LineItem^ empCurve = myPane->AddCurve("Выборочная F_eta(x)", empCDFList, Color::Blue, SymbolType::None);
            empCurve->Line->StepType = StepType::ForwardStep;

            // 3. Построение Теоретической функции (F(x) = 1 - e^(-Lx))
            PointPairList^ teorCDFList = gcnew PointPairList();
            int points_count = 500; // Больше точек для плавного изгиба

            for (int i = 0; i <= points_count; ++i)
            {
                double x_teor = (double)i * final_maxX / (double)points_count;
                double F_teor = 1.0 - exp(-lambda_param * x_teor);
                teorCDFList->Add(x_teor, F_teor);
            }

            LineItem^ teorCurve = myPane->AddCurve("Теоретическая F_eta(x)", teorCDFList, Color::Red, SymbolType::None);
            teorCurve->Line->Width = 2.0f;


            myPane->Title->Text = "Функции распределения (Lambda = " + lambda_param.ToString("F2") + ")";
            myPane->XAxis->Title->Text = "x";
            myPane->YAxis->Title->Text = "F(x)";


            myPane->XAxis->Scale->Min = 0.0;
            myPane->XAxis->Scale->Max = smartMaxX;
            myPane->XAxis->Scale->MagAuto = true; 
            myPane->XAxis->Scale->Format = "g";

            myPane->YAxis->Scale->Min = 0.0;
            myPane->YAxis->Scale->Max = 1.5; 

            zedGraphControl1->AxisChange();
            zedGraphControl1->Invalidate();
        }

        void FillDensityTable(const std::vector<MyMath::IntervalData>& data_series, int N_total, double lambda_param)
        {
            // Теперь part2_table доступен через "this->"
            if (this->part2_table == nullptr) return;

            // 1. Очистка и установка числа колонок
            this->part2_table->Rows->Clear();
            this->part2_table->Columns->Clear();
            this->part2_table->ColumnCount = data_series.size() + 1; // +1 для заголовка строки

            // 2. Установка заголовков столбцов (Интервалы 1, 2, 3...)
            this->part2_table->Columns[0]->HeaderText = "Показатель";
            this->part2_table->Columns[0]->ReadOnly = true;

            for (size_t j = 0; j < data_series.size(); ++j)
            {
                this->part2_table->Columns[j + 1]->HeaderText = String::Format("Интервал {0}", (int)(j + 1));
                this->part2_table->Columns[j + 1]->ReadOnly = true;
            }

            // 3. Добавление трех строк для данных (z_j, f(z_j), h_j)
            this->part2_table->Rows->Add(3);

            // Установка заголовков строк
            this->part2_table->Rows[0]->Cells[0]->Value = "z_j (Середина)";
            this->part2_table->Rows[1]->Cells[0]->Value = "f(z_j) (Теор. плотность)";
            this->part2_table->Rows[2]->Cells[0]->Value = "h_j (Выб. плотность)";

            // 4. Заполнение данных
            double delta_prime = 0.0;
            if (data_series.size() > 0) {
                delta_prime = data_series[0].interval_end - data_series[0].interval_start;
            }

            // ⭐ ТЕОРЕТИЧЕСКАЯ ПЛОТНОСТЬ f(x) = lambda * exp(-lambda * x)
            // В MyMath::IntervalData уже есть поле f_teor, используем его
            // Если же нет, то нужно добавить в MyMath.h/cpp и рассчитать.

            for (size_t j = 0; j < data_series.size(); ++j)
            {
                const auto& data = data_series[j];

                // Выборочная плотность h_j = n_j / (N * delta_prime)
                double empirical_density = 0.0;
                if (N_total > 0 && delta_prime > 0) {
                    empirical_density = (double)data.n_j / (N_total * delta_prime);
                }

                // Теоретическая плотность (расчет по середине интервала)
                double theoretical_density = lambda_param * exp(-lambda_param * data.z_j);


                int col = (int)j + 1;

                // Строка 1: z_j
                this->part2_table->Rows[0]->Cells[col]->Value = data.z_j.ToString("F4");

                // Строка 2: f(z_j) (Теоретическая плотность)
                this->part2_table->Rows[1]->Cells[col]->Value = theoretical_density.ToString("F6");

                // Строка 3: h_j (Выборочная плотность)
                this->part2_table->Rows[2]->Cells[col]->Value = empirical_density.ToString("F6");
            }

            this->part2_table->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::DisplayedCells);
        }


        void DrawHistogram(const std::vector<MyMath::IntervalData>& data_series, int N_total, double lambda_param)
        {
            GraphPane^ myPane = gistogramma->GraphPane;
            myPane->CurveList->Clear();

            // 1. Динамический расчет границ
            // При лямбда = 1000, среднее = 0.001. 
            // Весь изгиб экспоненты виден на промежутке 3-4 мат. ожиданий.
            double theoretical_mean = 1.0 / lambda_param;
            double smartMaxX = theoretical_mean * 4.0;

            int series_size = static_cast<int>(data_series.size());

            // Берем максимум между данными и теоретическим пределом, чтобы график не был "сплюснутым"
            double actual_data_max = (series_size == 0) ? smartMaxX : data_series[series_size - 1].interval_end;
            double final_maxX = (actual_data_max > smartMaxX) ? actual_data_max : smartMaxX;

            // 2. Построение Гистограммы (столбиков)
            PointPairList^ histList = gcnew PointPairList();
            double delta_prime = 0.0;
            if (series_size > 0) {
                delta_prime = data_series[0].interval_end - data_series[0].interval_start;
            }

            for (const auto& data : data_series)
            {
                double empirical_density = 0.0;
                if (N_total > 0 && delta_prime > 0) {
                    // Нормировка высоты под площадь = 1
                    empirical_density = (double)data.n_j / (N_total * delta_prime);
                }
                histList->Add(data.z_j, empirical_density);
            }

            BarItem^ histBar = myPane->AddBar("Выборочная плотность", histList, Color::LightGreen);
            histBar->Bar->Fill->IsVisible = true;
            histBar->Bar->Fill->Color = Color::FromArgb(150, Color::LightGreen);
            histBar->Bar->Border->Color = Color::Black;

            if (delta_prime > 0)
            {
                myPane->BarSettings->Base = BarBase::X;
                myPane->BarSettings->Type = BarType::Overlay;
                myPane->BarSettings->ClusterScaleWidth = delta_prime;
                myPane->BarSettings->MinClusterGap = 0.0f;
            }

            // 3. Построение Теоретической кривой (красная линия)
            PointPairList^ theorDensityList = gcnew PointPairList();
            int points_count = 500; // Увеличиваем детализацию для крутых изгибов
            for (int i = 0; i <= points_count; ++i)
            {
                double x_teor = (double)i * final_maxX / (double)points_count;
                double f_teor = lambda_param * exp(-lambda_param * x_teor);
                theorDensityList->Add(x_teor, f_teor);
            }

            LineItem^ teorCurve = myPane->AddCurve("Теория: f(x)", theorDensityList, Color::Red, SymbolType::None);
            teorCurve->Line->Width = 2.5f;

            // 4. НАСТРОЙКА ОСЕЙ (Масштабирование)
            myPane->Title->Text = "Распределение минимума (Lambda = " + lambda_param.ToString("F2") + ")";
            myPane->XAxis->Title->Text = "Время x";
            myPane->YAxis->Title->Text = "Плотность";

            // Фиксируем X так, чтобы видеть изгиб, а не бесконечный пустой хвост
            myPane->XAxis->Scale->Min = 0.0;
            myPane->XAxis->Scale->Max = smartMaxX;

            // Включаем "научный" формат: если числа < 0.1, появится множитель 10^-3
            myPane->XAxis->Scale->MagAuto = true;
            myPane->XAxis->Scale->Format = "g";

            // Фиксируем Y по пику лямбды
            myPane->YAxis->Scale->Min = 0.0;
            myPane->YAxis->Scale->Max = lambda_param * 1.1;
            myPane->YAxis->Scale->MagAuto = true;

            // 5. Обновление
            gistogramma->AxisChange();
            gistogramma->Invalidate();
        }
        // ------------------------------------------------------------------
        // ОБРАБОТЧИК КНОПКИ
        // ------------------------------------------------------------------
    private: System::Void button_Start_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // =================================================================
        // 1. Считывание и конвертация входных параметров (k, λk, N)
        // =================================================================
        int k = 0; // Переименовал, чтобы не путать с локальной переменной k
        int k_part_3 = 0;
        double lambda_k = 0.0;
        int N = 0;
        int m_default = 10;
        double alpha = 0.0;

        try
        {
            k = Int32::Parse(textBox_k->Text); // Использую правильное имя поля
            k_part_3 = Int32::Parse(k_intervalov_path_3->Text); // Использую правильное имя поля
            lambda_k = Double::Parse(textBox_lambda->Text);
            N = Int32::Parse(textBox_N->Text);
            m_default = Int32::Parse(m_gist->Text);
            alpha = Double::Parse(textBox_alpha->Text);

        }
        catch (System::FormatException^)
        {
            MessageBox::Show("Пожалуйста, введите корректные числа.", "Ошибка ввода", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
            return;
        }

        if (k_part_3 <= 1 || lambda_k <= 0.0 || N <= 0)
        {
            MessageBox::Show("Параметры должны быть положительными (k >= 2).", "Ошибка данных", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
            return;
        }

        // =================================================================
        // 2. Создание объекта, моделирование и расчеты
        // =================================================================

        


        bool needFullRebuild = (math == nullptr) || (lambda_k != lastLambda) || (N != lastN) || (k!= lastK_part_1) || (!checkBox_part1->Checked);
        // Создание нового объекта и выполнение part_1
        
        if (needFullRebuild)
        {
            if (math) delete math;

            math = new MyMath(k, lambda_k, N);
            math->part_1(); // Генерируем НОВУЮ выборку

            // Запоминаем параметры
            lastLambda = lambda_k;
            lastN = N;
            lastK_part_1 = k;
        }
        else
        {
            // Если параметры те же, мы просто обновляем k_intervals внутри существующего объекта,
            // но НЕ вызываем моделирование заново.
            math->k = k;
            // Важно: если в MyMath Lambda вычисляется как оценка, 
            // убедитесь, что вы не затираете её случайно.
        }
        math->part_2(m_default); // Расчет x_bar, S_sq, R_bar, Me_hat, D_statistic (выборочные характеристики)

        // Вычисление абсолютных отклонений
        double abs_E_diff = abs(math->E_eta - math->x_bar);
        double abs_D_diff = abs(math->D_eta - math->S_sq);
        double abs_Me_diff = abs(math->Me_hat - math->Me_eta);

        // =================================================================
        // 3. ВЫЗОВ: Ввод границ Z для Хи-квадрат (новая логика)
        // =================================================================

        double max_x_value = 0.0;

        // Если выборка существует (должна существовать после part_1), берем max_x
        if (!math->sample.empty())
        {
            max_x_value = math->sample.back();
        }

        int required_nodes = k_part_3 - 1;

        List<double>^ defaultValues = nullptr;

        if (this->lastUsedZNodes != nullptr && this->lastUsedZNodes->Count == required_nodes)
        {
            // Если количество интервалов K-1 совпадает, используем старые значения
            defaultValues = this->lastUsedZNodes;
        }

        // Изменение: Передаем defaultValues в конструктор InputForm
        InputForm inputDialog(required_nodes, max_x_value, defaultValues, math->sample);

        if (inputDialog.ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            // 1. Очищаем старую память
            if (this->chi_square_nodes != nullptr)
            {
                delete this->chi_square_nodes;
                this->chi_square_nodes = nullptr; // Сбрасываем указатель после удаления
            }

            // 2. Выделяем новую память для вектора
            this->chi_square_nodes = new std::vector<double>();


            // 3. Получаем управляемый список
            List<double>^ inputList = inputDialog.InputValues;
            this->lastUsedZNodes = inputList;
            // 4. Заполняем через указатель
            this->chi_square_nodes->reserve(inputList->Count);

            for each (double value in inputList)
            {
                this->chi_square_nodes->push_back(value);
            }
        }

        if (math != nullptr && this->chi_square_nodes != nullptr) {
            // Копируем узлы из формы в объект math
            math->chi_square_bounds = *(this->chi_square_nodes);
        }

        math->part_3(alpha);
        part_3_res->Text = "Результат (значение p_value): " + math->p_value.ToString();
        // =================================================================
        // 4. Обновление интерфейса (Таблицы и Графики)
        // =================================================================

        // --- ТАБЛИЦА 1: Упорядоченная выборка (dataGridView_Results) ---
        dataGridView_Results->Rows->Clear();

        for (size_t i = 0; i < math->sample.size(); ++i)
        {
            int rowIndex = dataGridView_Results->Rows->Add();
            dataGridView_Results->Rows[rowIndex]->Cells[L"i"]->Value = (int)(i + 1);
            dataGridView_Results->Rows[rowIndex]->Cells[L"X_i"]->Value = math->sample[i].ToString("F6");
        }

        dataGridView_Results->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells);
        RunHypothesisTestCycles(grid_part_3);
       
        if (dataGridView_Stats->RowCount != 1)
        {
            dataGridView_Stats->RowCount = 1;
        }


        for (int j = 0; j < dataGridView_Stats->ColumnCount; ++j)
        {
            dataGridView_Stats->Rows[0]->Cells[j]->Value = nullptr;
        }

        dataGridView_Stats->Rows[0]->Cells[L"E_eta"]->Value = math->E_eta.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"D_eta"]->Value = math->D_eta.ToString("F6");

        dataGridView_Stats->Rows[0]->Cells[L"x"]->Value = math->x_bar.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"raznost_E_eta_x"]->Value = abs_E_diff.ToString("F6");

        dataGridView_Stats->Rows[0]->Cells[L"S_kvadrat"]->Value = math->S_sq.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"raznost_disp"]->Value = abs_D_diff.ToString("F6");

        dataGridView_Stats->Rows[0]->Cells[L"R"]->Value = math->R_bar.ToString("F6");

        dataGridView_Stats->Rows[0]->Cells[L"Me_eta"]->Value = math->Me_eta.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"Me_hat"]->Value = math->Me_hat.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"Me_diff"]->Value = abs_Me_diff.ToString("F6");

        mera_rashojdenia->Text = "Мера D: " + math->D_statistic.ToString("F6") + " в точке " + math->x_mera_d + " j = " + math->j_mera_d;


        FillDensityTable(math->interval_series_results, N, math->Lambda);
        DrawHistogram(math->interval_series_results, N, math->Lambda);

        DrawCDFGraphs(math->sample, math->Lambda);

        dataGridView_Stats->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells);
        
        if (math->hypothesis_accepted) {
            gipoteza->Text = "Приняли гипотезу: приняли!";
        }
        else {
            gipoteza->Text = "Приняли гипотезу: отклонили!";
        }

        if (math != nullptr && !math->vector_q_j.empty())
        {
            // Очищаем старые строки, если они были
            datagrid_part_3->Rows->Clear();

            for (int i = 0; i < math->vector_q_j.size(); ++i)
            {
                // Добавляем новую строку
                int rowIndex = datagrid_part_3->Rows->Add();

                // В первый столбец (индекс 0) пишем номер j (i+1)
                datagrid_part_3->Rows[rowIndex]->Cells[0]->Value = (i + 1);

                // Во второй столбец (индекс 1) пишем значение q_j
                datagrid_part_3->Rows[rowIndex]->Cells[1]->Value = math->vector_q_j[i].ToString("F4");
            }

            // Автоподбор ширины колонок для красоты
            datagrid_part_3->AutoResizeColumns();
        }

        
        

    }


    void RunHypothesisTestCycles(DataGridView^ grid) {
        // 1. Считываем количество циклов из твоего поля
        int num_cycles;
        try {
            num_cycles = Int32::Parse(text_box_part_3_aaa->Text);
        }
        catch (...) {
            MessageBox::Show("Введите целое число циклов (например, 100)");
            return;
        }


        if (num_cycles <= 0) {
            num_cycles = 0;
        }
        // Уровень значимости берем из основного поля (например, textBox_alpha)
        double current_alpha = Double::Parse(textBox_alpha->Text);

        grid->Rows->Clear();

        // Инициализируем генератор ОДИН раз (из part_1 удали!)
        srand((unsigned int)time(0));

        // Настраиваем заголовки
        grid->Columns[0]->HeaderText = "Попытка (p-value)";
        grid->Columns[1]->HeaderText = "Вердикт (a=" + current_alpha.ToString("F2") + ")";

        // 2. Создаем верхнюю строку для ИТОГОВ
        int summaryRowIdx = grid->Rows->Add();
        grid->Rows[summaryRowIdx]->Cells[0]->Value = "ИТОГО ПРИНЯТО:";
        grid->Rows[summaryRowIdx]->Cells[1]->Value = "0 из " + num_cycles;

        // Стили для итога
        System::Drawing::Font^ boldFont = gcnew System::Drawing::Font(grid->Font, System::Drawing::FontStyle::Bold);
        grid->Rows[summaryRowIdx]->DefaultCellStyle->Font = boldFont;
        grid->Rows[summaryRowIdx]->DefaultCellStyle->ForeColor = System::Drawing::Color::Blue;

        int accepted_count = 0;

        // 3. Основной цикл по количеству из text_box_part_3_aaa
        for (int i = 0; i < num_cycles; ++i) {
            math->part_1();
            math->part_2(10);
            math->part_3(current_alpha);

            int rowIdx = grid->Rows->Add();
            grid->Rows[rowIdx]->Cells[0]->Value = "№" + (i + 1) + " (p=" + math->p_value.ToString("F4") + ")";

            if (math->hypothesis_accepted) {
                grid->Rows[rowIdx]->Cells[1]->Value = "Принята";
                grid->Rows[rowIdx]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGreen;
                accepted_count++;
            }
            else {
                grid->Rows[rowIdx]->Cells[1]->Value = "Отвергнута";
                grid->Rows[rowIdx]->DefaultCellStyle->BackColor = System::Drawing::Color::MistyRose;
            }

            // Обновляем итоги в первой строке на каждой итерации
            double current_percent = ((double)accepted_count / (i + 1) * 100.0);
            grid->Rows[summaryRowIdx]->Cells[1]->Value = accepted_count + " из " + (i + 1) +
                " (" + current_percent.ToString("F1") + "%)";

            // Чтобы форма не зависала при больших числах (например, 500 циклов)
            if (i % 10 == 0) Application::DoEvents();
        }
    }


    
    private: System::Void checkBox_FixParameters_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
        // Получаем состояние галочки
        bool isChecked = checkBox_part1->Checked;

        // Устанавливаем ReadOnly
        textBox_k->ReadOnly = isChecked;
        textBox_lambda->ReadOnly = isChecked;
        textBox_N->ReadOnly = isChecked;

        // Визуальный отклик (меняем цвет фона)
        if (isChecked) {
            textBox_k->BackColor = System::Drawing::SystemColors::Control; // Серый
            textBox_lambda->BackColor = System::Drawing::SystemColors::Control;
            textBox_N->BackColor = System::Drawing::SystemColors::Control;
        }
        else {
            textBox_k->BackColor = System::Drawing::SystemColors::Window;  // Белый
            textBox_lambda->BackColor = System::Drawing::SystemColors::Window;
            textBox_N->BackColor = System::Drawing::SystemColors::Window;
        }
    }


   

    




};

    

}