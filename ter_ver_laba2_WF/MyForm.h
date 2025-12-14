#pragma once
#include "MyMath.h"

namespace terverlaba2WF {

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
        System::Windows::Forms::Label^ label_k;
        System::Windows::Forms::TextBox^ textBox_k;
        System::Windows::Forms::Label^ label_lambda;
        System::Windows::Forms::TextBox^ textBox_lambda;
        System::Windows::Forms::Label^ label_N;
        System::Windows::Forms::TextBox^ textBox_N;
        System::Windows::Forms::Button^ button_Start;
        // Первая таблица: Упорядоченная выборка
        System::Windows::Forms::DataGridView^ dataGridView_Results;
        // Вторая таблица: Сводка характеристик (ДОБАВЛЕНО)
        System::Windows::Forms::DataGridView^ dataGridView_Stats;
        System::Windows::Forms::Label^ label_Criteria;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ i;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ X_i;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ E_eta;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ x;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ raznost_E_eta_x;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ D_eta;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ S_kvadrat;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ raznost_disp;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Mediana;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ R;


        System::ComponentModel::IContainer^ components;

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
            this->label_k = (gcnew System::Windows::Forms::Label());
            this->textBox_k = (gcnew System::Windows::Forms::TextBox());
            this->label_lambda = (gcnew System::Windows::Forms::Label());
            this->textBox_lambda = (gcnew System::Windows::Forms::TextBox());
            this->label_N = (gcnew System::Windows::Forms::Label());
            this->textBox_N = (gcnew System::Windows::Forms::TextBox());
            this->button_Start = (gcnew System::Windows::Forms::Button());
            this->dataGridView_Results = (gcnew System::Windows::Forms::DataGridView());
            this->label_Criteria = (gcnew System::Windows::Forms::Label());
            this->dataGridView_Stats = (gcnew System::Windows::Forms::DataGridView());
            this->E_eta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->x = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->raznost_E_eta_x = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->D_eta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->S_kvadrat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->raznost_disp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Mediana = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->R = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->X_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
            this->textBox_lambda->Text = L"10.0";
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
            this->dataGridView_Results->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView_Results->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_Results->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->i,
                    this->X_i
            });
            this->dataGridView_Results->Location = System::Drawing::Point(12, 123);
            this->dataGridView_Results->Name = L"dataGridView_Results";
            this->dataGridView_Results->RowHeadersVisible = false;
            this->dataGridView_Results->Size = System::Drawing::Size(207, 189);
            this->dataGridView_Results->TabIndex = 9;
            // 
            // label_Criteria
            // 
            this->label_Criteria->AutoSize = true;
            this->label_Criteria->Location = System::Drawing::Point(658, 275);
            this->label_Criteria->Name = L"label_Criteria";
            this->label_Criteria->Size = System::Drawing::Size(254, 13);
            this->label_Criteria->TabIndex = 8;
            this->label_Criteria->Text = L"Критерии: D = [Ожидание], Max Diff = [Ожидание]";
            // 
            // dataGridView_Stats
            // 
            this->dataGridView_Stats->AllowUserToDeleteRows = false;
            this->dataGridView_Stats->AllowUserToResizeColumns = false;
            this->dataGridView_Stats->AllowUserToResizeRows = false;
            this->dataGridView_Stats->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView_Stats->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_Stats->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
                this->E_eta,
                    this->x, this->raznost_E_eta_x, this->D_eta, this->S_kvadrat, this->raznost_disp, this->Mediana, this->R
            });
            this->dataGridView_Stats->Location = System::Drawing::Point(12, 397);
            this->dataGridView_Stats->Name = L"dataGridView_Stats";
            this->dataGridView_Stats->RowHeadersVisible = false;
            this->dataGridView_Stats->Size = System::Drawing::Size(805, 47);
            this->dataGridView_Stats->TabIndex = 7;
            // 
            // E_eta
            // 
            this->E_eta->HeaderText = L"E_eta";
            this->E_eta->Name = L"E_eta";
            this->E_eta->ReadOnly = true;
            // 
            // x
            // 
            this->x->HeaderText = L"x";
            this->x->Name = L"x";
            this->x->ReadOnly = true;
            // 
            // raznost_E_eta_x
            // 
            this->raznost_E_eta_x->HeaderText = L"| E_eta - x |";
            this->raznost_E_eta_x->Name = L"raznost_E_eta_x";
            this->raznost_E_eta_x->ReadOnly = true;
            // 
            // D_eta
            // 
            this->D_eta->HeaderText = L"D_eta";
            this->D_eta->Name = L"D_eta";
            this->D_eta->ReadOnly = true;
            // 
            // S_kvadrat
            // 
            this->S_kvadrat->HeaderText = L"S_2";
            this->S_kvadrat->Name = L"S_kvadrat";
            this->S_kvadrat->ReadOnly = true;
            // 
            // raznost_disp
            // 
            this->raznost_disp->HeaderText = L"| D_eta - S_2 |";
            this->raznost_disp->Name = L"raznost_disp";
            this->raznost_disp->ReadOnly = true;
            // 
            // Mediana
            // 
            this->Mediana->HeaderText = L"Me";
            this->Mediana->Name = L"Mediana";
            this->Mediana->ReadOnly = true;
            // 
            // R
            // 
            this->R->HeaderText = L"R";
            this->R->Name = L"R";
            this->R->ReadOnly = true;
            // 
            // i
            // 
            this->i->HeaderText = L"i";
            this->i->Name = L"i";
            this->i->ReadOnly = true;
            // 
            // X_i
            // 
            this->X_i->HeaderText = L"X_i";
            this->X_i->Name = L"X_i";
            this->X_i->ReadOnly = true;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(954, 652);
            this->Controls->Add(this->dataGridView_Stats);
            this->Controls->Add(this->label_Criteria);
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
        // ОБРАБОТЧИК КНОПКИ
        // ------------------------------------------------------------------
    private: System::Void button_Start_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // 1. Считывание и конвертация входных параметров
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

        // 2. Создание объекта и выполнение Части 1 и 2
        MyMath* math = new MyMath(k, lambda_k, N);

        math->part_1();
        math->part_2();

        // 3. ТАБЛИЦА 1: Упорядоченная выборка (dataGridView_Results)
        dataGridView_Results->Rows->Clear();
        dataGridView_Results->Columns->Clear();

        dataGridView_Results->Columns->Add("Index", "j");
        dataGridView_Results->Columns->Add("SampleValue", "x(j)");

        dataGridView_Results->Columns[0]->Width = 50;
        dataGridView_Results->Columns[1]->Width = 150;

        for (size_t i = 0; i < math->sample.size(); ++i)
        {
            int rowIndex = dataGridView_Results->Rows->Add();
            dataGridView_Results->Rows[rowIndex]->Cells[0]->Value = (int)(i + 1);
            dataGridView_Results->Rows[rowIndex]->Cells[1]->Value = math->sample[i].ToString("F6");
        }

        // 4. ТАБЛИЦА 2: Сводка характеристик (dataGridView_Stats)

        // Вычисление абсолютных отклонений
        double abs_E_diff = abs(math->E_eta - math->x_bar);
        double abs_D_diff = abs(math->D_eta - math->S_sq);

        dataGridView_Stats->Rows->Clear();
        dataGridView_Stats->Columns->Clear();

        // Определение столбцов, как вы просили: Eη x̄ |Eη − x̄| Dη S² |Dη − S²| M̃η M̂e R̄
        dataGridView_Stats->Columns->Add("E_eta", "Eη");
        dataGridView_Stats->Columns->Add("X_bar", "x̄");
        dataGridView_Stats->Columns->Add("E_diff", "|Eη − x̄|");
        dataGridView_Stats->Columns->Add("D_eta", "Dη");
        dataGridView_Stats->Columns->Add("S_sq", "S²");
        dataGridView_Stats->Columns->Add("D_diff", "|Dη − S²|");
        dataGridView_Stats->Columns->Add("Me_eta", "M̃η");
        dataGridView_Stats->Columns->Add("Me_hat", "M̂e");
        dataGridView_Stats->Columns->Add("R_bar", "R̄");

        // Настройка внешнего вида
        dataGridView_Stats->RowHeadersVisible = true;
        dataGridView_Stats->AllowUserToAddRows = false;
        dataGridView_Stats->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::DisableResizing;

        // Добавляем две строки
        dataGridView_Stats->RowCount = 2;
        dataGridView_Stats->Rows[0]->HeaderCell->Value = "Теор.";
        dataGridView_Stats->Rows[1]->HeaderCell->Value = "Выбор.";

        // Заполнение ТЕОРЕТИЧЕСКИХ значений (Первая строка - 'Теор.')
        dataGridView_Stats->Rows[0]->Cells[0]->Value = math->E_eta.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[3]->Value = math->D_eta.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[6]->Value = math->Me_eta.ToString("F6");

        // Заполнение ВЫБОРОЧНЫХ значений и ОТКЛОНЕНИЙ (Вторая строка - 'Выбор.')
        dataGridView_Stats->Rows[1]->Cells[1]->Value = math->x_bar.ToString("F6");
        dataGridView_Stats->Rows[1]->Cells[2]->Value = abs_E_diff.ToString("F6");
        dataGridView_Stats->Rows[1]->Cells[4]->Value = math->S_sq.ToString("F6");
        dataGridView_Stats->Rows[1]->Cells[5]->Value = abs_D_diff.ToString("F6");
        dataGridView_Stats->Rows[1]->Cells[7]->Value = math->Me_hat.ToString("F6");
        dataGridView_Stats->Rows[1]->Cells[8]->Value = math->R_bar.ToString("F6");

        // Автоматическая подгонка ширины столбцов
        dataGridView_Stats->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);

        // 5. Вывод критериев в label_Criteria
        System::String^ criteria_output =
            "*** Критерии согласия (Раздел 2) ***\n" +
            "Критерий Колмогорова-Смирнова (D) = " + math->D_statistic.ToString("F6") + "\n" +
            "Макс. отклонение плотности (Max Diff) = " + math->max_density_deviation.ToString("F6");

        label_Criteria->Text = criteria_output;

        delete math;
    }
    };
}