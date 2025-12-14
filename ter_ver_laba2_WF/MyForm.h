#pragma once
#include "MyMath.h"

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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Results))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Stats))->BeginInit();
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
            this->textBox_k->Text = L"3";
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
            this->textBox_lambda->Text = L"10,0";
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
            this->textBox_N->Text = L"100";
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
            this->dataGridView_Results->Size = System::Drawing::Size(137, 480);
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
            this->dataGridView_Stats->Size = System::Drawing::Size(731, 49);
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
            this->zedGraphControl1->Location = System::Drawing::Point(188, 179);
            this->zedGraphControl1->Name = L"zedGraphControl1";
            this->zedGraphControl1->ScrollGrace = 0;
            this->zedGraphControl1->ScrollMaxX = 0;
            this->zedGraphControl1->ScrollMaxY = 0;
            this->zedGraphControl1->ScrollMaxY2 = 0;
            this->zedGraphControl1->ScrollMinX = 0;
            this->zedGraphControl1->ScrollMinY = 0;
            this->zedGraphControl1->ScrollMinY2 = 0;
            this->zedGraphControl1->Size = System::Drawing::Size(479, 414);
            this->zedGraphControl1->TabIndex = 10;
            
            // 
            // mera_rashojdenia
            // 
            this->mera_rashojdenia->AutoSize = true;
            this->mera_rashojdenia->Location = System::Drawing::Point(687, 179);
            this->mera_rashojdenia->Name = L"mera_rashojdenia";
            this->mera_rashojdenia->Size = System::Drawing::Size(110, 13);
            this->mera_rashojdenia->TabIndex = 11;
            this->mera_rashojdenia->Text = L"Мера расхождения: ";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1063, 709);
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
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

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


        // ------------------------------------------------------------------
        // ОБРАБОТЧИК КНОПКИ
        // ------------------------------------------------------------------
    private: System::Void button_Start_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // =================================================================
        // 1. Считывание и конвертация входных параметров (k, λk, N)
        // =================================================================
        int k = 0;
        double lambda_k = 0.0;
        int N = 0;

        try
        {
            k = Int32::Parse(textBox_k->Text);
            lambda_k = Double::Parse(textBox_lambda->Text);
            N = Int32::Parse(textBox_N->Text);
        }
        catch (System::FormatException^)
        {
            MessageBox::Show("Пожалуйста, введите корректные числа в поля ввода (k, λk, N).", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (k <= 0 || lambda_k <= 0.0 || N <= 0)
        {
            MessageBox::Show("Параметры k, λk, N должны быть положительными.", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Создание объекта и выполнение моделирования/расчетов
        MyMath* math = new MyMath(k, lambda_k, N);
        math->part_1(); // Моделирование, сортировка, расчет Lambda, E_eta, D_eta
        math->part_2(); // Расчет x_bar, S_sq, R_bar, Me_hat, D_statistic (выборочные характеристики)

        // Вычисление абсолютных отклонений
        double abs_E_diff = abs(math->E_eta - math->x_bar);
        double abs_D_diff = abs(math->D_eta - math->S_sq);
        double abs_Me_diff = abs(math->Me_hat - math->Me_eta);

        // =================================================================
        // 3. ТАБЛИЦА 1: Упорядоченная выборка (dataGridView_Results)
        // =================================================================
        dataGridView_Results->Rows->Clear();

        for (size_t i = 0; i < math->sample.size(); ++i)
        {
            int rowIndex = dataGridView_Results->Rows->Add();
            dataGridView_Results->Rows[rowIndex]->Cells[L"i"]->Value = (int)(i + 1);
            dataGridView_Results->Rows[rowIndex]->Cells[L"X_i"]->Value = math->sample[i].ToString("F6");
        }

        dataGridView_Results->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::DisplayedCells);

        // =================================================================
        // 4. ТАБЛИЦА 2: Сводка характеристик (dataGridView_Stats)
        // =================================================================
        if (dataGridView_Stats->RowCount != 1)
        {
            dataGridView_Stats->RowCount = 1;
        }

        // Очищаем содержимое ячеек
        for (int i = 0; i < dataGridView_Stats->RowCount; ++i)
        {
            for (int j = 0; j < dataGridView_Stats->ColumnCount; ++j)
            {
                dataGridView_Stats->Rows[i]->Cells[j]->Value = nullptr;
            }
        }

        // --- Заполнение СТРОКИ 0 ---
        dataGridView_Stats->Rows[0]->Cells[L"E_eta"]->Value = math->E_eta.ToString("F6"); // Теоретическое E
        dataGridView_Stats->Rows[0]->Cells[L"D_eta"]->Value = math->D_eta.ToString("F6"); // Теоретическое D

        dataGridView_Stats->Rows[0]->Cells[L"x"]->Value = math->x_bar.ToString("F6"); // Выборочное x
        dataGridView_Stats->Rows[0]->Cells[L"raznost_E_eta_x"]->Value = abs_E_diff.ToString("F6");

        dataGridView_Stats->Rows[0]->Cells[L"S_kvadrat"]->Value = math->S_sq.ToString("F6"); // Выборочное S^2
        dataGridView_Stats->Rows[0]->Cells[L"raznost_disp"]->Value = abs_D_diff.ToString("F6");

        dataGridView_Stats->Rows[0]->Cells[L"R"]->Value = math->R_bar.ToString("F6"); // Выборочное R

        dataGridView_Stats->Rows[0]->Cells[L"Me_eta"]->Value = math->Me_eta.ToString("F6"); // Теоретическая Me
        dataGridView_Stats->Rows[0]->Cells[L"Me_hat"]->Value = math->Me_hat.ToString("F6"); // Выборочная Me
        dataGridView_Stats->Rows[0]->Cells[L"Me_diff"]->Value = abs_Me_diff.ToString("F6");


        // ⭐ МЕРА РАСХОЖДЕНИЯ D
        mera_rashojdenia->Text = "Мера расхождения: "+math->D_statistic.ToString("F6");
        
        

        // ⭐ ВЫЗОВ: Построение графиков CDF
        DrawCDFGraphs(math->sample, math->Lambda);

        // Корректный режим AutoResizeColumns
        dataGridView_Stats->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells);

        delete math;
    }

    };
}