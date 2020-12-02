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
		void p_getvalue(String^, String^, String^, String^, String^);
		void c_getvalue(String^, String^, String^, String^, String^, String^);
		void createClient();

	private:
		MySqlConnection^ con;
		String^  id;
		String^  mdp;

	public:
		//Personel value
		String^ p_nom;
		String^ p_prenom;
		String^ p_adresse;
		String^ p_date;
		String^ sup_id;

		// Client Value
		String^ c_nom;
		String^ c_prenom;
		String^ c_date_aniv;
		String^ c_date_achat;
		String^ c_adresse_l;
		String^ c_adresse_f;

	public:Form^ returnForm;

	};


}