#include "Share.h"
#include "MyForm.h"

using namespace MySql::Data::MySqlClient;
using namespace POOProject;


namespace ShareFonctionality {


	void Login::connexion(String^ identifiant, String^ motdepasse) {

		id = identifiant;
		mdp = motdepasse;

	}

	void Login::connect(Object^ data, BindingSource^ bd, Object^ dbd) {
		String^ constr = "Server=51.75.246.94;Uid=" + id + ";Pwd=" + mdp + ";Database=Projet POO";
		con = gcnew MySqlConnection(constr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("select * from TVA", con);
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		dbd = dt;
		data = bd;

	}

	void Login::p_getvalue(String^ nom, String^ prenom, String^ adresse, String^ date, String^ id) {
		p_nom = nom;
		p_prenom = prenom;
		p_adresse = adresse;
		p_date = date;
		sup_id = id;
	}

	void Login::c_getvalue(String^ nom, String^ prenom, String^ datea, String^ date1, String^ adressF, String^ adressL) {
		c_nom = nom;
		c_prenom = prenom;
		c_date_aniv = datea;
		c_date_achat = date1;
		c_adresse_l = adressF;
		c_adresse_f = adressL;
	}

	/*Form^ Login::getreturnForm() {
		Object^ sender;
		return returnForm;
	};*/

	void Login::setreturnForm(Form^ form) {
		returnForm = form;
		
	}

	void Login::createClient() {
		try
		{
			String^ constr = "Server=51.75.246.94;Uid=" + id + ";Pwd=" + mdp + ";Database=Projet POO";
			con = gcnew MySqlConnection(constr);

			if (c_adresse_f == c_adresse_l)

			{
				MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO ADRESSE VALUES('','" + c_adresse_f + "')", con);
				MySqlDataReader^ dr;
				con->Open();
				dr = cmd->ExecuteReader();
				con->Close();

				MySqlCommand^ cmd1 = gcnew MySqlCommand("INSERT INTO DATE VALUES('', '" + c_date_aniv + "')", con);
				con->Open();
				dr = cmd1->ExecuteReader();
				con->Close();

				MySqlCommand^ cmd2 = gcnew MySqlCommand("INSERT INTO DATE VALUES('', '" + c_date_achat + "')", con);
				con->Open();
				dr = cmd2->ExecuteReader();
				con->Close();

				MySqlCommand^ cmd3 = gcnew MySqlCommand("INSERT INTO CLIENT VALUES('', (SELECT ID_ADRESSE FROM ADRESSE WHERE adresse = '" + c_adresse_f + "'), (SELECT ID_ADRESSE FROM ADRESSE WHERE adresse  = '" + c_adresse_l + "'), (SELECT ID_DATE FROM DATE WHERE DATE = '" + c_date_aniv + "'), (SELECT ID_DATE FROM DATE WHERE DATE = '" + c_date_achat + "'), '" + c_nom + "', '" + c_prenom + "')", con);
				con->Open();
				dr = cmd3->ExecuteReader();
				con->Close();

				MessageBox::Show("Client Ajouté");
			}
			else
			{
				MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO ADRESSE VALUES('','" + c_adresse_f + "')", con);
				MySqlDataReader^ dr;
				con->Open();
				dr = cmd->ExecuteReader();
				con->Close();

				MySqlCommand^ cmd1 = gcnew MySqlCommand("INSERT INTO ADRESSE VALUES('','" + c_adresse_l + "')", con);
				con->Open();
				dr = cmd1->ExecuteReader();
				con->Close();

				MySqlCommand^ cmd2 = gcnew MySqlCommand("INSERT INTO DATE VALUES('', '" + c_date_aniv + "')", con);
				con->Open();
				dr = cmd2->ExecuteReader();
				con->Close();

				MySqlCommand^ cmd3 = gcnew MySqlCommand("INSERT INTO DATE VALUES('', '" + c_date_achat + "')", con);
				con->Open();
				dr = cmd3->ExecuteReader();
				con->Close();

				MySqlCommand^ cmd4 = gcnew MySqlCommand("INSERT INTO CLIENT VALUES('', (SELECT ID_ADRESSE FROM ADRESSE WHERE adresse = '" + c_adresse_f + "'), (SELECT ID_ADRESSE FROM ADRESSE WHERE adresse  = '" + c_adresse_l + "'), (SELECT ID_DATE FROM DATE WHERE DATE = '" + c_date_aniv + "'), (SELECT ID_DATE FROM DATE WHERE DATE = '" + c_date_achat + "'), '" + c_nom + "', '" + c_prenom + "')", con);
				con->Open();
				dr = cmd4->ExecuteReader();

				MessageBox::Show("Client Ajouté");

			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

	}

	void Login::deleteClient(String^ idc) {
		try
		{
			String^ constr = "Server=51.75.246.94;Uid=" + id + ";Pwd=" + mdp + ";Database=Projet POO";
			con = gcnew MySqlConnection(constr);

			MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM CLIENT WHERE ID_CLIENT='"+idc+"'", con);
			MySqlDataReader^ dr;
			con->Open();
			dr = cmd->ExecuteReader();
			con->Close();


			MessageBox::Show("Client Supprimé");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	void Login::createPersonel() {
		
		try
		{
			String^ constr = "Server=51.75.246.94;Uid=" + id + ";Pwd=" + mdp + ";Database=Projet POO";
			con = gcnew MySqlConnection(constr);

			MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO ADRESSE(ID_ADRESSE ,ADRESSE) SELECT '','"+p_adresse+"' WHERE NOT EXISTS (SELECT * FROM ADRESSE WHERE ADRESSE='"+p_adresse+"')", con);
			MySqlDataReader^ dr;
			con->Open();
			dr = cmd->ExecuteReader();
			con->Close();

			MySqlCommand^ cmd1 = gcnew MySqlCommand("INSERT INTO DATE(ID_DATE,DATE) SELECT '','"+p_date+"' WHERE NOT EXISTS (SELECT * FROM DATE WHERE DATE='" + p_date + "')", con);
			con->Open();
			dr = cmd1->ExecuteReader();
			con->Close();

			MySqlCommand^ cmd2 = gcnew MySqlCommand("INSERT INTO PERSONNEL VALUES('', (SELECT ID_ADRESSE FROM ADRESSE WHERE adresse = '"+p_adresse+"'), '"+sup_id+"',(SELECT ID_DATE FROM DATE WHERE DATE = '"+p_date+"'), '"+p_nom+"', '"+p_prenom+"')", con);
			con->Open();
			dr = cmd2->ExecuteReader();
			con->Close();

			MessageBox::Show("Personel Ajouté");

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	void Login::deletePersonel(String^ idp) {
		try
		{
			String^ constr = "Server=51.75.246.94;Uid=" + id + ";Pwd=" + mdp + ";Database=Projet POO";
			con = gcnew MySqlConnection(constr);

			MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM PERSONNEL WHERE ID_PERSONNEL='" + idp + "'", con);
			MySqlDataReader^ dr;
			con->Open();
			dr = cmd->ExecuteReader();
			con->Close();


			MessageBox::Show("Personnel Supprimé");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
}