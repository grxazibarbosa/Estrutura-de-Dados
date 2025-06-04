// NAO MEXA NESTE ARQUIVO, ELE JA ESTA PRONTO PARA SER USADO PELO MOODLE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ForwardList.h"
using namespace std;

int main() 
{
	vector<ForwardList> listas; // um vector de listas
	
	while(true) {
		string comando, token;
		getline(cin, comando);
		stringstream ss{ comando };
        ss >> token;

        cout << "$" << ss.str() << endl;

		// exit
		if(token == "exit") {
			listas.clear();
			break;
		}
		// create
		else if(token == "create") {
			listas.push_back(ForwardList());
		}
		// size l
		else if(token == "size") {
			int l;
            ss >> l;
			cout << "size list " << l << ": " << listas[l].size() << std::endl;
		}
        // createWith l
		else if(token == "createWith") {
			int l;
            ss >> l;
			listas.push_back(ForwardList());
            listas.back() = listas[l];
		}
        // clone l
		else if(token == "clone") {
			int l;
            ss >> l;
			listas.push_back(ForwardList());
            listas.back() = listas[l];
		}
        // concat l1 l2
		else if(token == "concat") {
			int l1, l2;
            ss >> l1 >> l2;
			listas[l1].concat(listas[l2]);
		}
        // remove x l
		else if(token == "remove") {
			int x, l;
            ss >> x >> l;
			listas[l].remove(x);
		}
        // swap l1 l2
        else if(token == "swap") {
			int l1, l2; 
            ss >> l1 >> l2;
			listas[l1].swap(listas[l2]);
		}
        // equals l1 l2 
		else if(token == "equals") {
			int l1, l2; 
            ss >> l1 >> l2;
			if(listas[l1] == listas[l2]) cout << "listas iguais" << endl;
			else cout << "listas diferentes" << endl;
		}
        // reverse l
		else if(token == "reverse") {
			int l;
            ss >> l;
			listas[l].reverse();
		}
        // addFront l a1 ... an 
		else if(token == "addFront") {
			int l;
            ss >> l;
            int value;
            while(ss >> value) {
                listas[l].push_front(value);
            }
		}
        // show 
		else if(token == "show") {
            for(unsigned i = 0; i < listas.size(); ++i) {
                cout << "lista " << i << ": " << listas[i] << endl;
            }	
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}