#include <iostream>
#include <iomanip>
using namespace std;

struct graph
{
	int V;
	int E;
	int adj[10][10];
};

graph *initialize();
void MATRIXinc(int r_c, int val, int mat[10][10]);

void inputEdge(graph *G, int X, int Y);
void writeVertices(graph *G);
void writeEdges(graph *G);
void writeMatrix(int mat[][10], int r_c); 


int main(){
	graph *G;
	int x,y;
	char odg;
	cout<<"Inicijalizacija grafa...\n";
	G = initialize();
	cout<<"Povezivanje bridova u grafu...\n";
	do
	{
		cout<<"Koje vrhove želite povezati: (Oznake do "<<G->V<<")";
		cout<<"\nx: ";
		cin>>x;
		cout<<"y: ";
		cin>>y;
		inputEdge(G,x,y);
		cout<<"Zelite li upisati jos vrhova (d/n): ";
		cin>>odg;
	}
	while(odg!='n');
	writeVertices(G);
	writeEdges(G);
	writeMatrix(G->adj,G->V);

	return 0;
}

graph *initialize()
{
	graph *G = new graph;
	cout<<"Koliko vrhova ce imati graf (izmedju 1 i 10): ";
	cin>>G->V;
	G->E=0;
	MATRIXinc(G->V, 0, G->adj);
    cout<<"Generirani su vrhovi od 1 do "<<G->V<<": ";
	return G;
}

void MATRIXinc(int r_c, int val, int mat[][10])
{
	for(int i=0;i<r_c;i++)
		for(int j=0;j<r_c;j++)
			mat[i][j]=val;
}

void inputEdge(graph *G,int X,int Y)
{
	if(G->adj[X][Y]==0)
		G->E++;
	G->adj[X][Y]=1;
	G->adj[Y][X]=1;
}

void writeVertices(graph *G)
{
	for(int i=1;i<=G->V;i++)
		cout<<setw(5)<<i;
	cout<<endl;
}

void writeEdges(graph *G)
{
	for(int i=0;i<=G->V;i++)
		for(int j=0;j<=i;j++) //brojac ide do i da ne pročita 2 puta 
			if(G->adj[i][j]==1)
			{
					cout<<setw(5)<<"("<<i<<", "<<j<<")";
					cout<<endl;
			}
}


void writeMatrix(int mat[][10], int r_c){
    for(int i=1;i<=r_c;i++)
        {
            for(int j=1;j<=r_c;j++)
                cout<<mat[i][j];
            cout<<endl;
        }
}

