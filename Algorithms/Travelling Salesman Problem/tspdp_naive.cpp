#include <bits/stdc++.h> 
using namespace std; 

void travellingSalesmanProblem(int** graph, int s,int size) 
{  
	vector<int> vertex;                 // store all vertex apart from source vertex
    vector<int> temp_path;              //path in one iteration, stored temporarily
    vector<int> fin_path;               //final minimum path
    
	for (int i = 0; i < size; i++) 
        if (i != s) 
			vertex.push_back(i);

	
	int min_path = INT_MAX; 
	do { 

		int current_pathweight = 0;     //cost of current iteration(path)
		temp_path.resize(0);            //current path
        
		// compute current path weight 
		int k = s;
        temp_path.push_back(k);
		for (int i = 0; i < vertex.size(); i++) { 
			current_pathweight += graph[k][vertex[i]]; 
			k = vertex[i];
            temp_path.push_back(k);
		} 
		current_pathweight += graph[k][s];
        temp_path.push_back(s);

		// update minimum 
        if(current_pathweight<min_path)
        {
            min_path=current_pathweight;
            fin_path=temp_path;
        } 
		
	} while (next_permutation(vertex.begin(), vertex.end())); 
    
    //print solution
    cout<<"\nThe minimum distance is: "<<min_path<<"\nThe path is:\n";
    for(int i=0;i<size;i++)
    {
        cout<<fin_path[i]<<" -> ";
    }
    cout<<fin_path[size]<<"\n";
}

int** createGraph(int size) //user input
{
    int** g=new int*[size];
    for(int i=0;i<size;i++)
    {
        g[i]=new int[size];
    }
    
    cout<<"Enter distances:\n\n";
    
    for(int i=0;i<size;i++)
    {
        cout<<"From vertex "<<i<<"\n";
        for(int j=0;j<size;j++)
        {
            if(i==j)
                g[i][j]=0;
            else
            {
                cout<<"To vertex "<<j<<": ";
                cin>>g[i][j];
            }
        }
        cout<<"\n";
    }
    
    return g;
} 

int main() 
{ 
    int city_count=0;
    
    do
    {
        cout<<"Enter total cities:\t";
        cin>>city_count;
        
        if(city_count<=0)
            cout<<"Invalid Input!\n\n";
    }while(city_count<=0);
    
    
    int** graph = createGraph(city_count);
    
	int s = 0;
    
    do
    {
        cout<<"Enter start vertex:\t";
        cin>>s;
        
        if(s>=city_count)
            cout<<"Invalid Input\n";
        
    }while(s>=city_count);
    
	travellingSalesmanProblem(graph, s,city_count);
	return 0; 
} 
