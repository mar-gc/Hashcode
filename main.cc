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
