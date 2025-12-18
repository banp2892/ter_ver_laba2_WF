#pragma once
#include "MyMath.h"
#include "InputForm.h" 

// Директива для компилятора C++/CLI, указывающая на сборку ZedGraph
// Убедитесь, что файл ZedGraph.dll доступен по пути поиска или находится в папке проекта/сборки.
#using <ZedGraph.dll>

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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Results))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Stats))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->part2_table))->BeginInit();
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
            this->textBox_lambda->Text = L"12,0";
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
            this->dataGridView_Results->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView_Results->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_Results->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->i,
                    this->X_i
            });
            this->dataGridView_Results->Location = System::Drawing::Point(23, 113);
            this->dataGridView_Results->Name = L"dataGridView_Results";
            this->dataGridView_Results->RowHeadersVisible = false;
            this->dataGridView_Results->Size = System::Drawing::Size(150, 480);
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
            this->dataGridView_Stats->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
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
            this->zedGraphControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->zedGraphControl1->Location = System::Drawing::Point(179, 283);
            this->zedGraphControl1->Name = L"zedGraphControl1";
            this->zedGraphControl1->ScrollGrace = 0;
            this->zedGraphControl1->ScrollMaxX = 0;
            this->zedGraphControl1->ScrollMaxY = 0;
            this->zedGraphControl1->ScrollMaxY2 = 0;
            this->zedGraphControl1->ScrollMinX = 0;
            this->zedGraphControl1->ScrollMinY = 0;
            this->zedGraphControl1->ScrollMinY2 = 0;
            this->zedGraphControl1->Size = System::Drawing::Size(493, 414);
            this->zedGraphControl1->TabIndex = 10;
            // 
            // mera_rashojdenia
            // 
            this->mera_rashojdenia->AutoSize = true;
            this->mera_rashojdenia->Location = System::Drawing::Point(930, 113);
            this->mera_rashojdenia->Name = L"mera_rashojdenia";
            this->mera_rashojdenia->Size = System::Drawing::Size(110, 13);
            this->mera_rashojdenia->TabIndex = 11;
            this->mera_rashojdenia->Text = L"Мера расхождения: ";
            // 
            // gistogramma
            // 
            this->gistogramma->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->gistogramma->Location = System::Drawing::Point(678, 283);
            this->gistogramma->Name = L"gistogramma";
            this->gistogramma->ScrollGrace = 0;
            this->gistogramma->ScrollMaxX = 0;
            this->gistogramma->ScrollMaxY = 0;
            this->gistogramma->ScrollMaxY2 = 0;
            this->gistogramma->ScrollMinX = 0;
            this->gistogramma->ScrollMinY = 0;
            this->gistogramma->ScrollMinY2 = 0;
            this->gistogramma->Size = System::Drawing::Size(493, 414);
            this->gistogramma->TabIndex = 12;
            // 
            // part2_table
            // 
            this->part2_table->AllowUserToAddRows = false;
            this->part2_table->AllowUserToDeleteRows = false;
            this->part2_table->AllowUserToResizeColumns = false;
            this->part2_table->AllowUserToResizeRows = false;
            this->part2_table->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
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
            this->m_gist->Text = L"-1";
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
            this->k_enterval_label->Size = System::Drawing::Size(195, 13);
            this->k_enterval_label->TabIndex = 16;
            this->k_enterval_label->Text = L"Количество интервалов для 3 пункта";
            // 
            // k_intervalov_path_3
            // 
            this->k_intervalov_path_3->Location = System::Drawing::Point(892, 17);
            this->k_intervalov_path_3->Name = L"k_intervalov_path_3";
            this->k_intervalov_path_3->Size = System::Drawing::Size(100, 20);
            this->k_intervalov_path_3->TabIndex = 17;
            this->k_intervalov_path_3->Text = L"5";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1453, 709);
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
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
        MyMath* math;
        List<double>^ chiSquareNodes;
        std::vector<double>* chi_square_nodes;
        System::Collections::Generic::List<double>^ lastUsedZNodes;
        // ------------------------------------------------------------------
        // РЕАЛИЗАЦИЯ МЕТОДА ОТРЕСОВКИ
        // ------------------------------------------------------------------
        void DrawCDFGraphs(const std::vector<double>& sample, double lambda_param)
        {
            GraphPane^ myPane = zedGraphControl1->GraphPane;
            myPane->CurveList->Clear();
            myPane->Title->Text = "Теоретическая F_eta(x) и выборочная F_eta(x) функции распределения";
            myPane->XAxis->Title->Text = "x";
            myPane->YAxis->Title->Text = "F(x)";

            // 1. Построение Эмпирической функции распределения (F_hat)
            PointPairList^ empCDFList = gcnew PointPairList();
            double N = (double)sample.size();

            empCDFList->Add(0.0, 0.0);

            for (size_t i = 0; i < N; ++i) // в каждой точке x у нас скачек вверх на 1/N
            {
                double x = sample[i];
                double F_val = (double)(i + 1) / N;

                if (i > 0) {
                    empCDFList->Add(x, (double)i / N);
                }
                empCDFList->Add(x, F_val);
            }

            LineItem^ empCurve = myPane->AddCurve("Выборочная F_eta(x)", empCDFList, Color::Blue, SymbolType::None);
            empCurve->Line->StepType = StepType::ForwardStep;


            // 2. Построение Теоретической функции распределения (F)
            PointPairList^ teorCDFList = gcnew PointPairList();

            double maxX = sample.empty() ? 10.0 : sample.back() * 1.1;

            for (int i = 0; i <= 100; ++i)
            {
                double x_teor = (double)i * maxX / 100.0;
                // F(x) = 1 - exp(-lambda * x)
                double F_teor = 1.0 - exp(-lambda_param * x_teor);
                teorCDFList->Add(x_teor, F_teor);
            }

            myPane->AddCurve("Теоретическая F_eta(x)", teorCDFList, Color::Red, SymbolType::None);


            // 3. Обновление графика
            myPane->XAxis->Scale->Min = 0.0;
            myPane->YAxis->Scale->Min = 0.0;
            myPane->YAxis->Scale->Max = 1.0;

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


        // ⭐ НОВЫЙ МЕТОД ДЛЯ ПОСТРОЕНИЯ ГИСТОГРАММЫ И ТЕОРЕТИЧЕСКОЙ ПЛОТНОСТИ
        void DrawHistogram(const std::vector<MyMath::IntervalData>& data_series, int N_total, double lambda_param)
        {
            GraphPane^ myPane = gistogramma->GraphPane;
            myPane->CurveList->Clear();
            myPane->Title->Text = "Гистограмма относительных частот и f(x) распределения";
            myPane->XAxis->Title->Text = "Интервалы";
            myPane->YAxis->Title->Text = "Плотность";

            // 1. Построение Гистограммы (Выборочная плотность h_j)
            PointPairList^ histList = gcnew PointPairList();
            double delta_prime = 0.0;
            if (data_series.size() > 0) {
                delta_prime = data_series[0].interval_end - data_series[0].interval_start;
            }

            for (const auto& data : data_series)
            {
                double empirical_density = 0.0;
                if (N_total > 0 && delta_prime > 0) {
                    empirical_density = (double)data.n_j / (N_total * delta_prime);
                }
                histList->Add(data.z_j, empirical_density);
            }

            // BarItem - это гистограмма
            BarItem^ histCurve = myPane->AddBar("Выборочная плотность h_j", histList, Color::Green);
            histCurve->Bar->Fill->IsVisible = false; // Отключаем заливку
            histCurve->Bar->Border->IsVisible = true; // Включаем видимость границы
            histCurve->Bar->Border->Color = Color::Black; // (Опционально) Устанавливаем черный цвет обводки
            histCurve->Bar->Border->Width = 1.0f; // (Опционально) Толщина обводки
            // ⭐ ИСПРАВЛЕНИЕ: Используем BarWidth, чтобы избежать ошибок ClusterScaleWidthTag и BarBase::Width
            if (delta_prime > 0)
            {
                myPane->BarSettings->Base = BarBase::X;
                myPane->BarSettings->Type = BarType::Overlay;
                myPane->BarSettings->ClusterScaleWidth = delta_prime; // Универсальный способ задания ширины
                myPane->BarSettings->MinClusterGap = 0.0f; // Столбцы без зазора
            }

            // 2. Построение Теоретической плотности (f(x) = lambda * exp(-lambda * x))
            PointPairList^ theorDensityList = gcnew PointPairList();

            // Диапазон для теоретической кривой
            double maxX = data_series.empty() ? 10.0 : data_series.back().interval_end * 1.1;

            for (int i = 0; i <= 100; ++i)
            {
                double x_teor = (double)i * maxX / 100.0;
                // f(x) = lambda * exp(-lambda * x)
                double f_teor = lambda_param * exp(-lambda_param * x_teor);
                theorDensityList->Add(x_teor, f_teor);
            }

            LineItem^ teorCurve = myPane->AddCurve("Теоретическая плотность f(x)", theorDensityList, Color::Red, SymbolType::None);
            teorCurve->Line->Width = 2.0f;
            teorCurve->IsY2Axis = false;
            
            // 3. Обновление графика
            myPane->XAxis->Scale->Min = 0.0;
            myPane->YAxis->Scale->Min = 0.0;

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
        int k_intervals = 0; // Переименовал, чтобы не путать с локальной переменной k
        double lambda_k = 0.0;
        int N = 0;
        int m_default = 10;

        try
        {
            k_intervals = Int32::Parse(k_intervalov_path_3->Text); // Использую правильное имя поля
            lambda_k = Double::Parse(textBox_lambda->Text);
            N = Int32::Parse(textBox_N->Text);
            m_default = Int32::Parse(m_gist->Text);
        }
        catch (System::FormatException^)
        {
            MessageBox::Show("Пожалуйста, введите корректные числа.", "Ошибка ввода", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
            return;
        }

        if (k_intervals <= 1 || lambda_k <= 0.0 || N <= 0)
        {
            MessageBox::Show("Параметры должны быть положительными (k >= 2).", "Ошибка данных", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
            return;
        }

        // =================================================================
        // 2. Создание объекта, моделирование и расчеты
        // =================================================================

        // Удаляем старый объект, если он есть (т.к. math объявлен как член класса MyForm)
        if (math)
        {
            delete math;
            math = nullptr;
        }

        // Создание нового объекта и выполнение part_1
        math = new MyMath(k_intervals, lambda_k, N);
        math->part_1(); // Моделирование, сортировка, расчет Lambda, E_eta, D_eta
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

        int required_nodes = k_intervals - 1;

        List<double>^ defaultValues = nullptr;

        if (this->lastUsedZNodes != nullptr && this->lastUsedZNodes->Count == required_nodes)
        {
            // Если количество интервалов K-1 совпадает, используем старые значения
            defaultValues = this->lastUsedZNodes;
        }

        // Изменение: Передаем defaultValues в конструктор InputForm
        InputForm inputDialog(required_nodes, max_x_value, defaultValues); // <--- ИЗМЕНЕНИЕ ЗДЕСЬ

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

        // --- ТАБЛИЦА 2: Сводка характеристик (dataGridView_Stats) ---
        if (dataGridView_Stats->RowCount != 1)
        {
            dataGridView_Stats->RowCount = 1;
        }

        // Очищаем содержимое ячеек
        for (int j = 0; j < dataGridView_Stats->ColumnCount; ++j)
        {
            dataGridView_Stats->Rows[0]->Cells[j]->Value = nullptr;
        }

        // --- Заполнение СТРОКИ 0 ---
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


        // ⭐ МЕРА РАСХОЖДЕНИЯ D
        mera_rashojdenia->Text = "Мера расхождения (Колмогорова): " + math->D_statistic.ToString("F6");


        // --- Построение графиков и таблиц, зависимых от интервалов гистограммы ---
        FillDensityTable(math->interval_series_results, N, math->Lambda);
        DrawHistogram(math->interval_series_results, N, math->Lambda);

        // ⭐ ВЫЗОВ: Построение графиков CDF (функции распределения)
        DrawCDFGraphs(math->sample, math->Lambda);

        // Корректный режим AutoResizeColumns
        dataGridView_Stats->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells);

        // ВАЖНО: delete math; убран отсюда. Теперь math - член класса, 
        // и он будет использоваться в методе расчета Хи-квадрат.
    }


    


    



   

    



};

    

}