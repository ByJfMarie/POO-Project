#pragma once

namespace ShareFonctionality {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Login
	{
	public:
		void connexion(String^, String^);
		void afficher();

	private:
		String^  id;
		String^  mdp;

	};


}