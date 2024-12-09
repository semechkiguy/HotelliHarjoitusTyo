//Jako Tirp Harjoitustyö. ansaitsen mielestäni 2 tästä työstä
#include <iostream>
#include <random>
#include <vector>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>



using namespace std;
int laskeHinta(int aika, int huoneHinta) { //aliohjelma kokonaishinnan laskemiselle
	return aika * huoneHinta;
}
int main() {
	setlocale(LC_ALL, "fi-FI"); // ääkkösiä varten
	srand(static_cast<unsigned>(time(0)));
	const int huoneMaara = rand()%41+30; // montako huonetta hotellissa on
	vector<bool>varattu(huoneMaara, false); //onko huone varattu vai ei
	const int  huoneHinta = rand()%21+80;
	int varausNro = 10000+ (rand() % (99999-10000+1)); //satunnainen varausnumero
	
	cout << "Hotellihuoneen varaus: Tervetuloa! " << endl;
	string nimi;
	cout << "Millä nimellä varaus tehdään? " << endl;
	 getline(cin, nimi);
	cout << "Vapaata huonetta: " << huoneMaara << ", jotka maksavat " << huoneHinta << " euroa per yö" << endl;
	int varaukset = 0;
	while (varaukset < huoneMaara) { // ei voi olla enemmän varauksia kuin huoneita
		int huoneNro, aika;
		cout << "Valitse huone numerosta 1-" << huoneMaara <<". Jos haluat satunnaisen huonenumeron, valitse 0. "<< endl;
		while (!(cin >> huoneNro)) { // ilman tätä jos laittaa kirjaimen inputtiin niin koodi joutuu looppiin
			cout << "Virhe. huonenumeron kuuluu olla luku, yritä uudelleen";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
		}
		if (huoneNro == 0) { //arpoo numeron ei varatuista huoneista
			do {
				huoneNro = rand() % huoneMaara + 1;
			} while (varattu[huoneNro - 1]);
			cout << "Sait huoneen " << huoneNro << "!" << endl;
		}


		if (huoneNro<1 || huoneNro>huoneMaara) { //tarkistaa jos huonenumero on käyttökelpoinen
			cout << "Annettua huonenumeroa ei ole olemassa, yritä uudelleen. " << endl;
			continue;
		}
		if (varattu[huoneNro - 1]) {//tarkistaa jos huone on jo varattu
			cout << "Huone " << huoneNro << " on jo varattu, yritä uudelleen. " << endl;
			continue;
		}
		cout << "Moneksi yöksi?" << endl;
		cin >> aika;
		if (aika <= 0) {
			cout << "Öitten määrä ei voi olla alle 0 tai kirjain, yritä uudelleen." << endl;
			continue;
		}
		if (aika >= 31) {
			cout << "Öitten määrä ei voi olla yli 30, yritä uudelleen." << endl;
			continue;
		}
		varattu[huoneNro - 1] = true;
		
		int kokHinta = laskeHinta(aika, huoneHinta); //aikaisempi aliohjelma
		
		
		cout << "Huone numero " << huoneNro << " varattu " << aika << " yöksi" << endl;
		cout << "Kokonaishinta on " << kokHinta << " euroa." << endl;
		cout << "Varaus tehty nimellä " << nimi << ". Varausnumero " << varausNro<<" "<<endl;
		varaukset++;// nostaa varauksien määrää
	}
	cout << "kaikki huoneet varattu!" << endl;

	return 0;
}
