#pragma once

#include <vector>       // Для std::vector
#include <algorithm>    // Для std::sort
#include <cmath>        // Для std::abs

namespace terverlaba2WF {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections::Generic; // Для List<double>
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class InputForm : public System::Windows::Forms::Form
    {
    public:
        // Управляемый список для хранения введенных узлов
        List<double>^ InputValues;

        // Свойство для хранения максимального значения выборки, переданного из MyForm
        double MaxSampleValue;

        // Конструктор: принимает требуемое количество узлов (K-1) и максимальное значение X
        InputForm(int requiredNodes, double maxVal, List<double>^ defaultNodes)
        {
            this->MaxSampleValue = maxVal;
            this->actualRequiredNodes = requiredNodes;

            // ⭐ Сохраняем значения по умолчанию
            this->DefaultZNodes = defaultNodes;

            this->InitializeComponent(requiredNodes);
            this->InputValues = gcnew List<double>();
        }

    protected:
        // Деструктор (для освобождения неуправляемого контейнера components)
        ~InputForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // ⭐ 1. ПРИВАТНОЕ ПОЛЕ для надежного хранения количества узлов
        int actualRequiredNodes;
        List<double>^ DefaultZNodes;

        System::ComponentModel::Container^ components;
        System::Windows::Forms::Panel^ buttonsPanel;
        System::Windows::Forms::Button^ btnOK;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::Button^ btnGenerate;
        System::Windows::Forms::TableLayoutPanel^ inputTable;

        // --- Генерируемый код дизайнера ---
        void InitializeComponent(int requiredNodes)
        {
            this->buttonsPanel = (gcnew System::Windows::Forms::Panel());
            this->btnOK = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->btnGenerate = (gcnew System::Windows::Forms::Button());
            this->inputTable = (gcnew System::Windows::Forms::TableLayoutPanel());

            // Настройка формы
            this->Text = L"Ввод границ Z для части 3 (K=" + (requiredNodes + 1).ToString() + L", Max X ≈ " + this->MaxSampleValue.ToString("F3") + L")";
            this->ClientSize = System::Drawing::Size(370, 70 + requiredNodes * 30);
            this->MinimumSize = System::Drawing::Size(390, 150);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->MaximizeBox = false;

            // Настройка TableLayoutPanel для ввода
            this->inputTable->AutoSize = true;
            this->inputTable->ColumnCount = 2;

            // Ширина колонки для Label и TextBox
            this->inputTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 120.0F)));
            this->inputTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100.0F)));

            this->inputTable->Location = System::Drawing::Point(15, 15);
            this->inputTable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Bottom)));

            // Динамическое добавление Label и TextBox
            for (int i = 0; i < requiredNodes; ++i)
            {
                this->inputTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25.0F)));

                System::Windows::Forms::Label^ label = (gcnew System::Windows::Forms::Label());
                label->Text = L"Граница z" + (i + 1).ToString() + L":";
                label->TextAlign = ContentAlignment::MiddleLeft;
                this->inputTable->Controls->Add(label, 0, i);

                System::Windows::Forms::TextBox^ textBox = (gcnew System::Windows::Forms::TextBox());
                textBox->Name = L"textBoxZ" + (i + 1).ToString();
                textBox->Tag = i; // ⭐ СОХРАНЯЕМ ИНДЕКС СТРОКИ
                textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InputForm::TextBox_OnlyDouble_KeyPress);
                this->inputTable->Controls->Add(textBox, 1, i);
            }

            // --- Панель с вертикальными кнопками ---
            this->buttonsPanel->Dock = System::Windows::Forms::DockStyle::Right;
            this->buttonsPanel->Width = 120;
            this->buttonsPanel->Padding = System::Windows::Forms::Padding(10, 10, 10, 10);

            // Используем FlowLayoutPanel для вертикального размещения кнопок
            System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel = gcnew System::Windows::Forms::FlowLayoutPanel();
            flowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            flowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
            flowLayoutPanel->Controls->Add(this->btnGenerate);
            flowLayoutPanel->Controls->Add(this->btnOK);
            flowLayoutPanel->Controls->Add(this->btnCancel);
            this->buttonsPanel->Controls->Clear();
            this->buttonsPanel->Controls->Add(flowLayoutPanel);


            // Настройка кнопок
            int buttonWidth = 90;

            this->btnGenerate->Text = L"Сгенерировать";
            this->btnGenerate->Size = System::Drawing::Size(buttonWidth, 30);
            this->btnGenerate->Margin = System::Windows::Forms::Padding(0, 5, 0, 15);
            this->btnGenerate->Click += gcnew System::EventHandler(this, &InputForm::btnGenerate_Click);

            this->btnOK->Text = L"ОК";
            this->btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->btnOK->Size = System::Drawing::Size(buttonWidth, 30);
            this->btnOK->Margin = System::Windows::Forms::Padding(0, 5, 0, 5);
            this->btnOK->Click += gcnew System::EventHandler(this, &InputForm::btnOK_Click);

            this->btnCancel->Text = L"Отмена";
            this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->btnCancel->Size = System::Drawing::Size(buttonWidth, 30);
            this->btnCancel->Margin = System::Windows::Forms::Padding(0, 5, 0, 5);

            // Добавление контролов на форму
            this->Controls->Add(this->buttonsPanel);
            this->Controls->Add(this->inputTable);

            // ⭐ НОВАЯ ЛОГИКА: Заполнение полей старыми значениями, если они есть
            if (this->DefaultZNodes != nullptr && this->DefaultZNodes->Count == requiredNodes)
            {
                // Используем итерацию по Controls и проверку Tag для надежности
                for each (Control ^ control in this->inputTable->Controls)
                {
                    System::Windows::Forms::TextBox^ tb = dynamic_cast<System::Windows::Forms::TextBox^>(control);

                    if (tb != nullptr && tb->Tag != nullptr)
                    {
                        int index = safe_cast<int>(tb->Tag);

                        if (index >= 0 && index < this->DefaultZNodes->Count)
                        {
                            // Записываем старое значение из списка
                            tb->Text = this->DefaultZNodes[index].ToString("F6", System::Globalization::CultureInfo::CurrentCulture);
                        }
                    }
                }
            }
            // ⭐ КОНЕЦ НОВОЙ ЛОГИКИ
        }
        // --- Конец генерируемого кода дизайнера ---

    private:
        // Метод валидации для TextBox 
        System::Void TextBox_OnlyDouble_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
        {
            String^ decimalSeparator = System::Globalization::CultureInfo::CurrentCulture->NumberFormat->NumberDecimalSeparator;
            if (Char::IsDigit(e->KeyChar) || e->KeyChar == (char)Keys::Back)
            {
                e->Handled = false;
            }
            else if (e->KeyChar.ToString() == decimalSeparator)
            {
                System::Windows::Forms::TextBox^ tb = dynamic_cast<System::Windows::Forms::TextBox^>(sender);
                if (tb != nullptr && tb->Text->Contains(decimalSeparator))
                {
                    e->Handled = true;
                }
                else
                {
                    e->Handled = false;
                }
            }
            else
            {
                e->Handled = true;
            }
        }

        // Обработчик кнопки "Сгенерировать" (Используем Tag для гарантированной записи)
        System::Void btnGenerate_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // ⭐ Используем actualRequiredNodes вместо this->inputTable->RowCount
            int requiredNodes = this->actualRequiredNodes;

            // Проверка, что есть что генерировать
            if (requiredNodes <= 0)
            {
                MessageBox::Show("Для генерации требуется K >= 2.", "Ошибка", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
                return;
            }

            double max_value = (this->MaxSampleValue > 0.0) ? this->MaxSampleValue : 10.0;

            System::Random^ rand = gcnew System::Random();
            std::vector<double> random_zi_values;
            random_zi_values.reserve(requiredNodes);

            // 1. Генерация
            for (int i = 0; i < requiredNodes; ++i)
            {
                double random_value = rand->NextDouble() * max_value;
                random_zi_values.push_back(random_value);
            }

            // 2. Сортировка сгенерированных узлов
            std::sort(random_zi_values.begin(), random_zi_values.end());

            // 3. Гарантированная запись в TextBox'ы через Tag
            for each (Control ^ control in this->inputTable->Controls)
            {
                System::Windows::Forms::TextBox^ tb = dynamic_cast<System::Windows::Forms::TextBox^>(control);

                if (tb != nullptr && tb->Tag != nullptr)
                {
                    int index = safe_cast<int>(tb->Tag);

                    if (index >= 0 && index < random_zi_values.size())
                    {
                        // Запись i-го сгенерированного значения в TextBox с Tag=i
                        tb->Text = random_zi_values[index].ToString("F6", System::Globalization::CultureInfo::CurrentCulture);
                    }
                }
            }

            MessageBox::Show(String::Format("Сгенерировано {0} случайных упорядоченных границ Z в диапазоне [0, {1:F3}].", requiredNodes, max_value), "Готово", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
        }

        // Обработчик нажатия OK: собираем, парсим и проверяем данные 
        System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e)
        {
            List<double>^ tempValues = gcnew List<double>();

            // 1. Сбор и парсинг всех значений
            // Используем итерацию по Controls, т.к. нас интересуют только TextBox'ы
            for each (Control ^ control in this->inputTable->Controls)
            {
                System::Windows::Forms::TextBox^ tb = dynamic_cast<System::Windows::Forms::TextBox^>(control);
                if (tb != nullptr)
                {
                    try
                    {
                        double z_val = Double::Parse(tb->Text, System::Globalization::CultureInfo::CurrentCulture);
                        // ⭐ Используем Tag для сортировки перед добавлением
                        // Это гарантирует, что tempValues будет упорядочен так, как на форме
                        int index = safe_cast<int>(tb->Tag);
                        // Вставляем значение по индексу, чтобы сохранить порядок
                        tempValues->Insert(index, z_val);
                    }
                    catch (System::Exception^)
                    {
                        MessageBox::Show("Ошибка: Введите числовое значение для каждой границы.", "Ошибка ввода", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
                        this->DialogResult = System::Windows::Forms::DialogResult::None;
                        return;
                    }
                }
            }

            // 2. Проверка на неотрицательность и строгое возрастание
            // Поскольку мы использовали Insert(index, value), tempValues уже должен быть упорядочен.

            if (tempValues->Count == 0)
            {
                MessageBox::Show("Ошибка: Не задана ни одна граница.", "Ошибка ввода", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
                this->DialogResult = System::Windows::Forms::DialogResult::None;
                return;
            }

            for (int i = 0; i < tempValues->Count; ++i)
            {
                // Проверка на неотрицательность
                if (tempValues[i] < 0)
                {
                    MessageBox::Show("Ошибка: Границы экспоненциального распределения должны быть неотрицательными.", "Ошибка значения", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
                    this->DialogResult = System::Windows::Forms::DialogResult::None;
                    return;
                }
                // Проверка на строгое возрастание (только если есть следующий элемент)
                if (i < tempValues->Count - 1 && tempValues[i] >= tempValues[i + 1])
                {
                    MessageBox::Show("Ошибка: Значения границ Z должны быть строго упорядочены (z1 < z2 < ...).", "Ошибка порядка", MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
                    this->DialogResult = System::Windows::Forms::DialogResult::None;
                    return;
                }
            }

            // Если все OK, сохраняем результат
            this->InputValues = tempValues;
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
        }
    };
}