#include "Share.h"

namespace ShareFonctionality {



	void Login::connexion(String^ identifiant, String^ motdepasse) {

		id = identifiant;
		mdp = motdepasse;

	}

	void Login::afficher() {
		MessageBox::Show(id, mdp);
	}
}