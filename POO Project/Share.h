#pragma once

using namespace MySql::Data::MySqlClient;

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
		void connect(Object ^, BindingSource^, Object^);
		//Form^ getreturnForm();
		void setreturnForm(Form^ form);

	private:
		MySqlConnection^ con;
		String^  id;
		String^  mdp;
	public:Form^ returnForm;

	};


}