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

	/*Form^ Login::getreturnForm() {
		Object^ sender;
		return returnForm;
	};*/

	void Login::setreturnForm(Form^ form) {
		returnForm = form;
		
	}

}