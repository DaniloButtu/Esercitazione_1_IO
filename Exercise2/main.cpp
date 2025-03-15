#include <iostream>
#include <fstream>
#include <iomanip> //libreria che mi serve per controllare l'output con scientific e setprecision(n)
using namespace std;

//funzione che mappa in valori da [1,5] in [-1,2] f(x)=(3*x-7)/4
double mapping_function(double x){
    return (3.0*x-7.0)/4.0;
}

int main()
{   
    string ifile_name="data.txt";
    string ofile_name="result.txt";

    ifstream ifile(ifile_name);
    ofstream ofile(ofile_name);

    if (ifile.fail() || ofile.fail()){

        cout<<"Error in files"<<endl;

        return 1;
    }

    ofile<<"# N Mean"<<endl; //Creo l'intestazione del file di output

    //lettura dei dati dal file data.txt
    double val=0.0;
    double mean=0.0;
    unsigned int i=0;

    while(ifile>>val){
        double mapped_val=mapping_function(val);
        i++;

        //Calcolo ad ogni passo la media m_i come m_i=((i-1)*m_(i-1)+val(i))/i;
        mean=(((i-1)*mean)+mapped_val)/i;  
        
        //scrittura del risultato nel file result.txt
        ofile<<scientific<<setprecision(16)<<i<<' '<<mean<<endl;
    }

    //chiudo i file usati nel programma
    ifile.close();
    ofile.close();

    return 0;
}
