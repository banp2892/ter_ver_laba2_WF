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

        std::vector<double>* currentSample;

        // Конструктор: принимает требуемое количество узлов (K-1) и максимальное значение X
        InputForm(int requiredNodes, double maxVal, List<double>^ defaultNodes, const std::vector<double>& sample)
        {
            this->MaxSampleValue = maxVal;
            this->actualRequiredNodes = requiredNodes;
            this->currentSample = new std::vector<double>(sample);
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
            this->components = (gcnew System::ComponentModel::Container());
            this->buttonsPanel = (gcnew System::Windows::Forms::Panel());
            this->btnOK = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->btnGenerate = (gcnew System::Windows::Forms::Button());
            this->inputTable = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->btnCancel->Click += gcnew System::EventHandler(this, &InputForm::btnCancel_Click);
            // 1. Создаем контейнер для скролла
            System::Windows::Forms::Panel^ scrollContainer = gcnew System::Windows::Forms::Panel();
            scrollContainer->AutoScroll = true;
            scrollContainer->Dock = System::Windows::Forms::DockStyle::Fill;
            scrollContainer->Padding = System::Windows::Forms::Padding(10);

            // Настройка формы
            this->Text = L"Ввод границ Z (K=" + (requiredNodes + 1).ToString() + L")";
            this->Size = System::Drawing::Size(420, 450);
            this->MaximumSize = System::Drawing::Size(450, 800);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->MaximizeBox = false;

            // 2. Настройка таблицы (УБИРАЕМ Location и Anchor!)
            this->inputTable->ColumnCount = 2;
            this->inputTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 120.0F)));
            this->inputTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100.0F)));
            this->inputTable->Dock = System::Windows::Forms::DockStyle::Top; // Позволяет скроллу считать высоту
            this->inputTable->AutoSize = true;
            this->inputTable->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->inputTable->Location = System::Drawing::Point(0, 0); // Обнуляем позицию
            this->inputTable->Padding = System::Windows::Forms::Padding(0, 0, 20, 0);
            // Цикл добавления полей (чуть увеличим высоту для удобства)
            for (int i = 0; i < requiredNodes; ++i)
            {
                this->inputTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30.0F)));

                System::Windows::Forms::Label^ label = (gcnew System::Windows::Forms::Label());
                label->Text = L"Граница z" + (i + 1).ToString() + L":";
                label->TextAlign = ContentAlignment::MiddleLeft;
                label->Dock = DockStyle::Fill;
                this->inputTable->Controls->Add(label, 0, i);

                System::Windows::Forms::TextBox^ textBox = (gcnew System::Windows::Forms::TextBox());
                textBox->Name = L"textBoxZ" + (i + 1).ToString();
                textBox->Tag = i;
                textBox->Dock = DockStyle::Fill;
                textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InputForm::TextBox_OnlyDouble_KeyPress);
                this->inputTable->Controls->Add(textBox, 1, i);
            }

            // 3. Настройка правой панели (ФИКСИРОВАННАЯ)
            this->buttonsPanel->Dock = System::Windows::Forms::DockStyle::Right;
            this->buttonsPanel->Width = 120;
            this->buttonsPanel->Padding = System::Windows::Forms::Padding(5);

            System::Windows::Forms::FlowLayoutPanel^ flow = gcnew System::Windows::Forms::FlowLayoutPanel();
            flow->Dock = System::Windows::Forms::DockStyle::Fill;
            flow->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;

            int btnW = 100;
            this->btnGenerate->Text = L"Заполнить";
            this->btnGenerate->Size = System::Drawing::Size(btnW, 30);
            this->btnOK->Text = L"ОК";
            this->btnOK->Size = System::Drawing::Size(btnW, 30);
            this->btnCancel->Text = L"Отмена";
            this->btnCancel->Size = System::Drawing::Size(btnW, 30);

            flow->Controls->Add(this->btnGenerate);
            flow->Controls->Add(this->btnOK);
            flow->Controls->Add(this->btnCancel);
            this->buttonsPanel->Controls->Add(flow);

            // 4. СБОРКА КОНТРОЛОВ (Критически важный порядок!)
            this->Controls->Add(scrollContainer);
            this->Controls->Add(this->buttonsPanel);
            scrollContainer->Controls->Add(this->inputTable);

            // Таблицу кладем только внутрь скролла
            scrollContainer->Controls->Add(this->inputTable);

            // События
            this->btnGenerate->Click += gcnew System::EventHandler(this, &InputForm::btnGenerate_Click);
            this->btnOK->Click += gcnew System::EventHandler(this, &InputForm::btnOK_Click);

            // ⭐ Перенос старых значений (уже внутри таблицы)
            if (this->DefaultZNodes != nullptr && this->DefaultZNodes->Count == requiredNodes)
            {
                for each (Control ^ c in this->inputTable->Controls) {
                    TextBox^ tb = dynamic_cast<TextBox^>(c);
                    if (tb && tb->Tag) {
                        int idx = safe_cast<int>(tb->Tag);
                        tb->Text = this->DefaultZNodes[idx].ToString("F6");
                    }
                }
            }
        }
        // --- Конец генерируемого кода дизайнера ---
        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Close(); // Принудительно закрываем окно
        }
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

        // ОБНОВЛЕННЫЙ МЕТОД ГЕНЕРАЦИИ:
        System::Void btnGenerate_Click(System::Object^ sender, System::EventArgs^ e)
        {
            int requiredNodes = this->actualRequiredNodes;
            int k_intervals = requiredNodes + 1; // Общее число интервалов

            if (this->currentSample == nullptr || this->currentSample->empty()) {
                MessageBox::Show("Выборка пуста. Невозможно рассчитать границы.", "Ошибка");
                return;
            }

            int N = (int)this->currentSample->size();
            std::vector<double> smart_zi_values;
            smart_zi_values.reserve(requiredNodes);

            // Логика: берем элементы выборки через равные шаги N/K
            for (int i = 1; i <= requiredNodes; ++i)
            {
                // Вычисляем индекс элемента, который станет границей
                // Используем double для точности, затем округляем
                int index = (int)(i * N / k_intervals);

                if (index >= N) index = N - 1;

                double val = (*this->currentSample)[index];
                smart_zi_values.push_back(val);
            }

            // Записываем в TextBox'ы (этот кусок у вас уже есть, используем его)
            for each (Control ^ control in this->inputTable->Controls)
            {
                System::Windows::Forms::TextBox^ tb = dynamic_cast<System::Windows::Forms::TextBox^>(control);
                if (tb != nullptr && tb->Tag != nullptr)
                {
                    int index = safe_cast<int>(tb->Tag);
                    if (index >= 0 && index < (int)smart_zi_values.size())
                    {
                        tb->Text = smart_zi_values[index].ToString("F6", System::Globalization::CultureInfo::CurrentCulture);
                    }
                }
            }

            
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

            //for (int i = 0; i < tempValues->Count; ++i)
            //{
            //    // Проверка на неотрицательность
            //    if (tempValues[i] < 0)
            //    {
            //        MessageBox::Show("Ошибка: Граница z" + (i + 1).ToString() + " (" + tempValues[i].ToString() + ") не может быть отрицательной.",
            //            "Ошибка значения", MessageBoxButtons::OK, MessageBoxIcon::Error);
            //        this->DialogResult = System::Windows::Forms::DialogResult::None;
            //        return;
            //    }

            //    // Проверка на строгое возрастание
            //    if (i < tempValues->Count - 1 && tempValues[i] >= tempValues[i + 1])
            //    {
            //        // Выводим конкретные номера границ и их значения
            //        String^ errorMsg = String::Format("Ошибка порядка:\n\n" +
            //            "Граница z{0} ({1}) должна быть МЕНЬШЕ, чем граница z{2} ({3}).\n\n" +
            //            "Пожалуйста, исправьте значения.",
            //            (i + 1), tempValues[i], (i + 2), tempValues[i + 1]);

            //        MessageBox::Show(errorMsg, "Ошибка порядка", MessageBoxButtons::OK, MessageBoxIcon::Error);

            //        this->DialogResult = System::Windows::Forms::DialogResult::None;
            //        return;
            //    }
            //}

            // Если все OK, сохраняем результат
            this->InputValues = tempValues;
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
        }


        
    };
}