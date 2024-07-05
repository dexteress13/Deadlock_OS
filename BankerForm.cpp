#include "BankerForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OSProject::BankerForm form;
	Application::Run(% form);
}