#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Reflection;
using namespace System::IO;



// Используем явное указание управляемого массива, чтобы не путать с std::array
static Assembly^ OnResolve(Object^ sender, ResolveEventArgs^ args) {
    Assembly^ execAssembly = Assembly::GetExecutingAssembly();

    // Используем cli::array, чтобы не было конфликта с std::array
    cli::array<String^>^ resNames = execAssembly->GetManifestResourceNames();

    // Явно указываем тип переменной в цикле
    for each (String ^ resourcePath in resNames) {
        // Ищем ресурс, содержащий имя библиотеки
        if (resourcePath->IndexOf("ZedGraph", StringComparison::OrdinalIgnoreCase) >= 0) {
            Stream^ s = execAssembly->GetManifestResourceStream(resourcePath);
            if (s != nullptr) {
                cli::array<Byte>^ data = gcnew cli::array<Byte>((int)s->Length);
                s->Read(data, 0, data->Length);

                // Явное приведение к cli::array<Byte>^ для метода Load
                return Assembly::Load((cli::array<Byte>^)data);
            }
        }
    }
    return nullptr;
}

using namespace System::Runtime::CompilerServices; // Нужно для атрибута

[MethodImpl(MethodImplOptions::NoInlining)]
void RunApp() {
    terverlaba2WF::MyForm form;
    Application::Run(% form);
}

[MethodImpl(MethodImplOptions::NoInlining)]
void Launcher() {
    terverlaba2WF::MyForm^ form = gcnew terverlaba2WF::MyForm();
    Application::Run(form);
}

[STAThread]
int main() {
    // 1. ПЕРВАЯ СТРОКА: регистрация обработчика
    AppDomain::CurrentDomain->AssemblyResolve += gcnew ResolveEventHandler(&OnResolve);

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // 2. Вызываем лончер, который "не знает" о ZedGraph до этого момента
    try {
        Launcher();
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message, "Критическая ошибка загрузки");
    }
    
    return 0;
}