// triFichier.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>

std::string toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    std::ifstream file("test.txt");
    std::vector<std::string> mots;
    std::string mot;

    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier test.txt" << std::endl;
        return 1;
    }

   
    while (file >> mot) {
        mots.push_back(toLowerCase(mot)); 
    }
    file.close();

    std::cout << "Contenu du fichier dans le vecteur :" << std::endl;
    for (const auto& m : mots) {
        std::cout << m << std::endl;
    }
    //TRI
    std::cout << "______________TRI DE CES MOTS__________________" << std::endl;
    std::sort(mots.begin(), mots.end());

    for (const auto& m : mots) {
        std::cout << m << std::endl;
    }

   //Recherche
    std::string mot_a_chercher;
    std::cout << "Entrez une valeur a rechercher : ";
    std::cin >> mot_a_chercher;
    mot_a_chercher = toLowerCase(mot_a_chercher); 

    int compteur = std::count(mots.begin(), mots.end(), mot_a_chercher);
    if (compteur > 0) {
        auto it = std::find(mots.begin(), mots.end(), mot_a_chercher);
        std::cout << "Le mot '" << mot_a_chercher << "' a ete trouve " << compteur
            << " fois à l'index " << std::distance(mots.begin(), it) << "." << std::endl;
    }
    else {
        std::cout << "Le mot '" << mot_a_chercher << "' n'a pas ete trouve." << std::endl;
    }
    //Supression
    std::string mot_a_sup;
    std::cout << "Entrez une valeur a supprimer : ";
    std::cin >> mot_a_sup;
    mot_a_sup = toLowerCase(mot_a_sup); // Convertir le mot à supprimer en minuscule

    auto avant_suppr = mots.size();
    mots.erase(std::remove(mots.begin(), mots.end(), mot_a_sup), mots.end());
    if (mots.size() < avant_suppr) {
        std::cout << "Le mot '" << mot_a_sup << "' a été supprimé." << std::endl;
    }
    else {
        std::cout << "Le mot '" << mot_a_sup << "' n'a pas été trouvé dans le vecteur." << std::endl;
    }

    std::cout << "Liste des mots après suppression : " << std::endl;
    for (const auto& mot : mots) {
        std::cout << mot << std::endl;
    }

    // Créer une map avec occurences
    std::map<std::string, int> map_mots;
    for (const std::string& m : mots) {
        map_mots[m]++;
    }
    std::cout << "*****************************MAPPING****************************************************++\n";
    // Afficher les mots et leurs occurrences dans la map
    std::cout << "Occurrences des mots :\n";
    for (const auto& paire : map_mots) {
        std::cout << paire.first << ": " << paire.second << std::endl;
    }
    //crer map de traduction
    std::map<std::string, std::string> traductions = {
      {"that", "que"},
      {"After", "Après"},
      {"Baring", "Exposant"},
      {"Being", "Être"},
      {"Byelinsky", "Byelinsky"},
      {"Dostoevsky", "Dostoevsky"},
      {"Dourov,", "Dourov,"},
      {"Gogol,", "Gogol,"},
      {"He", "Il"},
      {"I", "Je"},
      {"I.", "Je."},
      {"Majesty", "Majesté"},
      {"Maurice", "Maurice"},
      {"Mihail,", "Mihail,"},
      {"Nicholas", "Nicholas"},
      {"Plestcheiev", "Plestcheiev"},
      {"Semyonovsky", "Semyonovsky"},
      {"Square", "Place"},
      {"Suddenly", "Soudainement"},
      {"The", "Le"},
      {"Thereupon", "Là-dessus"},
      {"They", "Ils"},
      {"Under", "Sous"},
      {"Writing", "Écriture"},
      {"a", "un"},
      {"accused", "accusé"},
      {"against", "contre"},
      {"and", "et"},
      {"as", "comme"},
      {"back", "en arrière"},
      {"be", "être"},
      {"beat", "battre"},
      {"before", "avant"},
      {"bid", "offre"},
      {"bound", "lié"},
      {"brother", "frère"},
      {"brought", "apporté"},
      {"by", "par"},
      {"calls", "appels"},
      {"censorship,", "censure,"},
      {"commuted", "commuté"},
      {"concluded", "conclu"},
      {"condemned", "condamné"},
      {"contrived", "artificiel"},
      {"conversations", "conversations"},
      {"dear", "cher"},
      {"death.", "mort."},
      {"eight", "huit"},
      {"enough,", "assez,"},
      {"execution.", "exécution."},
      {"farewell.", "adieu."},
      {"few", "peu"},
      {"from", "de"},
      {"had", "avait"},
      {"hard", "dur"},
      {"he", "il"},
      {"heads,", "têtes,"},
      {"him)", "lui)"},
      {"his", "son"},
      {"imprisonment", "emprisonnement"},
      {"in", "dans"},
      {"informed", "informé"},
      {"intention", "intention"},
      {"just", "juste"},
      {"kiss", "baiser"},
      {"knowing", "savoir"},
      {"labour.", "travail."},
      {"letter", "lettre"},
      {"life", "vie"},
      {"lives.", "vies."},
      {"made", "fait"},
      {"man,", "homme,"},
      {"me,", "moi,"},
      {"me.", "moi."},
      {"minutes", "minutes"},
      {"months", "mois"},
      {"next", "suivant"},
      {"of", "de"},
      {"on", "sur"},
      {"ones", "un"},
      {"only", "seulement"},
      {"others", "autres"},
      {"our", "notre"},
      {"out", "dehors"},
      {"over", "au-dessus"},
      {"part", "partie"},
      {"persons", "personnes"},
      {"press.", "presse."},
      {"printing", "impression"},
      {"put", "mettre"},
      {"reading", "lecture"},
      {"row,", "rang,"},
      {"says:", "dit:"},
      {"scaffold,", "échafaud,"},
      {"sentence", "sentence"},
      {"set", "ensemble"},
      {"shirts", "chemises"},
      {"shot.", "tiré."},
      {"snapped", "claqué"},
      {"spared", "épargné"},
      {"stakes,", "enjeux,"},
      {"stern", "sérieux"},
      {"suffer", "souffrir"},
      {"taken", "pris"},
      {"taking", "prendre"},
      {"tattoo,", "tatouage,"},
      {"the", "le"},
      {"them", "eux"},
      {"they", "ils"},
      {"third", "troisième"},
      {"this", "ce"},
      {"thought", "pensé"},
      {"threes", "trois"},
      {"to", "à"},
      {"troops", "troupes"},
      {"twenty-one", "vingt et un"},
      {"unbound,", "détaché,"},
      {"up", "haut"},
      {"upon", "sur"},
      {"us", "nous"},
      {"was", "était"},
      {"we", "nous"},
      {"were", "étaient"},
      {"white", "blanc"},
      {"who", "qui"},
      {"with", "avec"},
      {"words", "mots"},
      {"worn", "usé"},
      {"you", "vous"},
      {"your", "votre"},
      {"you", "vous"}
    };

    std::string mot_a_traduire;
    std::cout << "Entrez un mot en anglais à traduire : ";
    std::cin >> mot_a_traduire;
    mot_a_traduire = toLowerCase(mot_a_traduire); 

    auto it_map = traductions.find(mot_a_traduire);
    if (it_map != traductions.end()) {
        std::cout << "La traduction de '" << mot_a_traduire << "' est : " << it_map->second << std::endl;
    }
    else {
        std::cout << "Le mot '" << mot_a_traduire << "' n'est pas dans le dictionnaire." << std::endl;
    }

    return 0;
}






// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
