#pragma once
#include "MyMath.h"

#using <ZedGraph.dll>

namespace terverlaba2WF {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    
    using namespace ZedGraph;
    using namespace System::Collections::Generic;
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
            this->dataGridView_Results->Size = System::Drawing::Size(117, 423);
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
            this->dataGridView_Stats->Location = System::Drawing::Point(149, 113);
            this->dataGridView_Stats->Name = L"dataGridView_Stats";
            this->dataGridView_Stats->RowHeadersVisible = false;
            this->dataGridView_Stats->Size = System::Drawing::Size(778, 49);
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
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(954, 652);
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

        // =================================================================
        // 2. Расчет теоретических характеристик
        // =================================================================
        double E_eta_teor = lambda_k / k;
        double D_eta_teor = pow(lambda_k / k, 2);

        // Создание объекта и выполнение моделирования/расчетов
        MyMath* math = new MyMath(k, lambda_k, N);
        math->part_1(); // Моделирование, сортировка
        math->part_2(); // Расчет x_bar, S_sq, R_bar, Me_hat (выборочные характеристики)

        


        // =================================================================
        // 3. ТАБЛИЦА 1: Упорядоченная выборка (dataGridView_Results)
        // =================================================================
        dataGridView_Results->Rows->Clear();

        // Заполнение данными (используем имена столбцов: "i" и "X_i")
        for (size_t i = 0; i < math->sample.size(); ++i)
        {
            int rowIndex = dataGridView_Results->Rows->Add();
            dataGridView_Results->Rows[rowIndex]->Cells[L"i"]->Value = (int)(i + 1);
            dataGridView_Results->Rows[rowIndex]->Cells[L"X_i"]->Value = math->sample[i].ToString("F6");
        }

        // Корректный режим AutoResizeColumns
        dataGridView_Results->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::DisplayedCells);


        // =================================================================
        // 4. ТАБЛИЦА 2: Сводка характеристик (dataGridView_Stats)
        // =================================================================

        // Убеждаемся, что в таблице 2 строки (для Теор. и Выбор. данных)
        if (dataGridView_Stats->RowCount != 1)
        {
            dataGridView_Stats->RowCount = 1;
        }

        // Очищаем только содержимое ячеек
        for (int i = 0; i < dataGridView_Stats->RowCount; ++i)
        {
            for (int j = 0; j < dataGridView_Stats->ColumnCount; ++j)
            {
                dataGridView_Stats->Rows[i]->Cells[j]->Value = nullptr;
            }
        }

        // --- Заполнение ПЕРВОЙ строки (Теоретические значения) ---
        // Строка 0


        double abs_E_diff = abs(math->E_eta - math->x_bar); // Используем math->E_eta
        double abs_D_diff = abs(math->D_eta - math->S_sq);   // Используем math->D_eta
        double abs_Me_diff = abs(math->Me_hat - math->Me_eta);

        dataGridView_Stats->Rows[0]->Cells[L"E_eta"]->Value = E_eta_teor.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"D_eta"]->Value = D_eta_teor.ToString("F6");
        
        
        dataGridView_Stats->Rows[0]->Cells[L"x"]->Value = math->x_bar.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"raznost_E_eta_x"]->Value = abs_E_diff.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"S_kvadrat"]->Value = math->S_sq.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"raznost_disp"]->Value = abs_D_diff.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"R"]->Value = math->R_bar.ToString("F6");

        
        dataGridView_Stats->Rows[0]->Cells[L"Me_eta"]->Value = math->Me_eta.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"Me_hat"]->Value = math->Me_hat.ToString("F6");
        dataGridView_Stats->Rows[0]->Cells[L"Me_diff"]->Value = abs_Me_diff.ToString("F6");

        // Корректный режим AutoResizeColumns
        

       

        delete math;
    }

    

    };
}