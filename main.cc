#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct pizza {
	int index;
	bool disponible;
	vector<string> Ingredients;
}


void lectura(vector<pizza>& v){
    int n=v.size();
    for(int i=0; i<n; ++i){
        v[i].index = i;
        v[i].disponible = true;
        int numing;
        cin >> numing;
        for(int j=0; j<numing; ++j){
            string ing;
            cin >> ing;
            v[i].Ingredients.pushback(ing);
        }
        sort(v[i].Ingredients.begin(),v[i].Ingredients.end());
    }
}

// pre: a i b pizzes valides d'un vector de pizzes
// post: retorna cert si a te més ingredients que b, o bé si els ingredients de a
// han d'anar abans lexicograficament els de b
bool criteri_ordre(const pizza& a, const pizza& b){
	int n_ingredients = a.Ingredients.size();
	if (n_ingredients != b.Ingredients.size()) return n_ingredients > b.Ingredients.size();

	for (int i = 0; i < n_ingredients; ++i)
		if (a.Ingredients[i] != b.Ingredients[i]) return a.Ingredients[i] < return b.Ingredients[i];

	return false;
}

// pre: indexs_pizzes es un vector on cada element representa a un equip amb pizzes,
// cada equip és un vector amb els indexs de les pizzes que els hi pertoquen
// post: imprimeix l'output
bool output(const vector<vector<int>>& indexs_pizzes){
	int equips_amb_pizza = indexs_pizzes.size();
	cout << equips_amb_pizza << endl;

	for (int i = 0; i < equips_amb_pizza; ++i){
		int membres_equip = indexs_pizzes[i].size();
		cout << membres_equip;

		for (int j = 0; j < membres_equip; ++j) cout << ' ' << indexs_pizzes[i][j];
	}
	

// Precondicio: v1 i v2 son dos vectors de strings (llistes d'ingredients) ordenats alfabeticament
// Postcondicio: la funcio retorna un vector de strings amb els tots els ingredients a v1 i v2 sense repetir-los i ordenat alfabeticament.
vector<string> fusio(const vector<string>& v1, const vector<string>& v2){
    int s1 = v1.size();
    int s2 = v2.size();
    vector<string> t;
    
    int i = 0;
    int j = 0;
    while (i < s1 and j < s2){
        if (v2[j] < v1[i]){
            t.push_back(v2[j]);
            ++j;
        }
        else if (v2[j] > v1[i]){
            t.push_back(v1[i]);
            ++i;
        }
        else{
            t.push_back(v1[i]);
            ++i, ++j;
        }
    }
    while (i < s1){
        t.push_back(v1[i]);
        ++i;
    }
    while (j < s2){
        t.push_back(v2[j]);
        ++j;
    }
    
    return t;
}

// Pre: entrada es un vector d'strings, ingre, una posicio valida del vector de pizzes v i un vector 
// d'enters indexs.

// Post: retorna un vector d'strings (no repetits) amb els ingredients de 'ingre' units amb els ingredients
// d'un element en la posicio i (i > pos) del vector v tal que el nombre d'ingredients no repetits sigui el 
// mes gran possible.

vector<string> trobar_parella(vector<pizza>& v, int pos, const vector<int> ingre, vector<int>& indexs) {
	vector<string> combinacio_max = fusio(ingre, v[pos + 1].Ingredients);
	int parella = pos + 1;
	int ing_max = combinacio_max.size();
	for (int i = pos + 2; i < size; ++i) {
		if (v[i].disponible) {
			vector<string> s = fusio(ingre, v[i].Ingredients);
			if(s.size() > ing_max) {
				combinacio_max = s;
				ing_max = s.size();
				parella = i;
			}
		}
	}
	indexs.push_back(v[parella].index)
	v[pos].disponible = false;
	v[parella].disponible = false;

	return combinacio_max;
}


int main() {
	int M, T_2, T_3, T_4;
	cin >> M >> T_2 >> T_3 >> T_4;
	vector<pizza> v(M);
	lectura(v);
	sort(v.begin(), v.end(), criteri_ordre);

	int deliveries = 0;
	int pos = 0, size = v.size();
	vector< vector<int> > index_pizza;

	// equips de 2
	while (pos < size and T_2 > 0 and M > 0) {
		if (v[pos].disponible) {
			vector<int> indexs(1);
			indexs[0] = 2;
			index.push_back(v[pos].index);
			vector<string> max2 = trobar_parella(v, pos, v[pos].Ingredients, indexs);
			++deliveries;
			++pos;
			--T_2;
			M = M - 2;
			index_pizza.push_back(indexs);
		}
	}

	//equips de 3
	while (pos < size and T_3 > 0 and M > 0) {
		if (v[pos.disponible]) {
			vector<int> indexs(1);
			indexs[0] = 3;
			index.push_back(v[pos].index);
			vector<string> max2 = trobar_parella(v, pos, v[pos].Ingredients, indexs);
			vector<string> max3 = trobar_parella (v, pos, max2, indexs);
			++deliveries;
			++pos;
			--T_3;
			M = M - 3;
			index_pizza.push_back(indexs);
		}
	}

	//equips de 4
	while (pos < size and T_4 > 0 and M > 0) {
		if (v[pos].disponible) {
			vector<int> indexs(1);
			indexs[0] = 4;
			index.push_back(v[pos].index);
			vector<string> max2 = trobar_parella(v, pos, v[pos].Ingredients, indexs);
			vector<string> max3 = trobar_parella (v, pos, max2, indexs);
			vector<string> max4 = trobar_parella (v, pos, max4, indexs);
			++deliveries;
			++pos;
			--T_4;
			M = M - 4;
			index_pizza.push_back(indexs);
		}
	}
}
