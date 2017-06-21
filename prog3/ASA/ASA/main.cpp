#include "ASA_GUI.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:main")
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main()
{
	ASA::ASA_GUI form;
	Application::Run(%form);
}