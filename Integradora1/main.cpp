#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dato.h"

using namespace std;

template <typename T>
int partition(vector<T>& arr, int low, int high)
{
	int piv = high;
	int i = low;
	
	for (int j = low; j < high; j++)
	{
		
		if (arr[j].getMonthint() < arr[piv].getMonthint())
		{
			swap(arr[i],arr[j]);
			i ++;
		}else if (arr[j].getMonthint() == arr[piv].getMonthint())
		{
			if (arr[j].getDay() < arr[piv].getDay())
			{
				swap(arr[i],arr[j]);
				i ++;
			}else if (arr[j].getDay() == arr[piv].getDay())
			{
				if (arr[j].getTempo() < arr[piv].getTempo())
				{
					swap(arr[i],arr[j]);
					i ++;
				}
			}
		}
		
	}

	swap(arr[i],arr[high]);
	return i;
	
}
template <typename T>
void QuickSort(std::vector<T>& arr, int low , int high)
{
	
	if(low < high)
	{
		int piv = partition(arr, low, high);
		QuickSort(arr,low,piv-1);
		QuickSort(arr,piv+1,high);
	}
	
}

vector <Dato> insertData()
{
	string text;
	vector<Dato> vec;
	fstream File("bitacora.txt");
	while (getline(File,text))
	{
		Dato d(text);
		
		vec.push_back(d);
	}
	return vec;
} 


void AcomodarBitacora(vector<Dato> v,string m_search,string d_search, string t_search)
{

	ofstream myfile;
	myfile.open("bitacora_ordenada.txt");
	string m1, m2, d1, d2;
	string t1, t2;
	int m11,m22;

	/*-----------Month cleaner-------------- */
	for (int i = 0; i < m_search.size(); i++)
	{
		if (i<3)
		{
			m1 += m_search[i];
		}
		else if (i>3)
		{
			m2 += m_search[i];
		}
			
	}

	/*-----------Day cleaner-------------- */
	for (int i = 0; i < d_search.size(); i++)
	{
		if (i<2)
		{
			d1 += d_search[i];
		}
		else if (i>2)
		{
			d2 += d_search[i];
		}
			
	}

	/*-----------Time cleaner-------------- */
	for (int i = 0; i < d_search.size(); i++)
	{
		if (i<8)
		{
			t1 += + t_search[i];
		}
		else if (i>8)
		{
			t2 += + t_search[i];
		}
			
	}
	string Jun = "Jun", Jul = "Jul", Aug = "Aug", Sep = "Sep", Oct = "Oct";

	if (m1 == Jun)
	{
		m11 = 1;
		
	}else if (m1 == Jul)
	{
		m11 = 2;
			
	}else if (m1 == Aug)
	{	
		m11 = 3;

	}else if (m1 == Sep)
	{
		m11 = 4;

	}else if (m1 == Oct)
	{
		m11 = 5;
	}

	/*--------------------------------------------------*/

	if (m2 == Jun)
	{
		m22 = 1;
		
	}else if (m2 == Jul)
	{
		m22 = 2;
			
	}else if (m2 == Aug)
	{	
		m22 = 3;

	}else if (m2 == Sep)
	{
		m22 = 4;

	}else if (m2 == Oct)
	{
		m22 = 5;
	}

	/*----------------------------------------------------------------------------------------*/
	
	for (int i = 0; i < v.size(); i++)
	{
		string d, t;
		int m;
		m = v[i].getMonthint();
		d = v[i].getDay();
		t = v[i].getTempo();
		
		if (m >= m11)
		{
			if (m == m11)
			{
				if (d >= d1)
				{
					if (d == d1)
					{
						if (t >= t1)
						{
							cout << v[i].getDato() << endl;
							myfile <<  v[i].getDato();
							myfile << "\n";
							
							
						}
						
					}
					else
					{
						cout <<v[i].getDato() << endl;
						myfile <<  v[i].getDato();
						myfile << "\n";
					}
				}
			}
			else if (m <= m22)
			{
				if (m == m22)
				{
					cout << t2 << endl;
					if (d <= d2)
					{
						if (d == d2)
						{
							if (t <= t2)
							{
								cout <<"S";
								cout << v[i].getDato() << endl;
								myfile <<  v[i].getDato();
								myfile << "\n";
							}
							cout << t << " " << t1 << endl;
						}
						
						
						cout << v[i].getDato() << endl;
						myfile <<  v[i].getDato();
						myfile << "\n";
						
						
					}
					
				}
				else
				{
					cout << v[i].getDato() << endl;
					myfile <<  v[i].getDato();
					myfile << "\n";
				}
				

			}
		}
		
		
	}	
	
}

void archivo(vector< vector<string> > &bitacoraAcomodada){
        ofstream file;
        file.open("bitacoraOrdenada.txt");
        
        for (int i = 0; i < bitacoraAcomodada.size(); i ++){
          file << bitacoraAcomodada[i][0] << " " << bitacoraAcomodada[i][1] << " " << bitacoraAcomodada[i][2] << ":" << bitacoraAcomodada[i][3] << ":" << bitacoraAcomodada[i][4] << " " << bitacoraAcomodada[i][5] << " " << bitacoraAcomodada[i][6] <<endl;
          
        }
        file.close();
}






int main()
{
	string m_search, d_search,t_search;
	cout << "Cargando datos de bitacora.txt..." << endl;
	vector <Dato> vec = insertData();
	cout << "Datos cargados correctamente." << endl;
	QuickSort<Dato>(vec,0,vec.size()-1);
	//printVect(vec);
	cout << endl;
	cout << "Ingrese rango de meses a buscar (ejemplo: Aug-Sep): ";
	cin >>m_search;
	cout << "Ingrese rango de dias a buscar (ejemplo: 01-31): ";
	cin >>d_search;
	cout << "Ingrese rango de tiempo a buscar en formato hh:mm:ss (ejemplo: 01:01:01-02:02:50): ";
	cin >>t_search;
	AcomodarBitacora(vec, m_search, d_search, t_search);
	cout << "Guardando datos en archivo .txt...";

	//pvect<Dato>(vec);

	return 0;
}