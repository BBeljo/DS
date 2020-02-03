#include <iostream>
#include <iomanip>
using namespace std;

const int MAXv=10; //najveci dozvoljeni broj vrhova
const int MAXe=100; //najveci dozvoljeni broj bridova

struct edge //uredjeni par
{
    int x;
    int y;
};

struct graph
{
    int numV; //brojac vrhova
    int vtx[MAXv];// polje vrhova
    int numE; //brojac bridova
    edge e[MAXe];// elt tipa struktura edge
    int mat[MAXv][MAXv];
};

void initialize(graph *&G); //inicijalizacija grafa

void inputEdge(graph *&G, int x, int y);//unos bridova
void writeVertices(graph *G);
void writeEdges(graph *G);
void MATRIXinc(int r_c, int val, int mat[10][10]);
void writeMatrix(int mat[][10], int r_c);
void addToMatrix(graph *&G, int x, int y);

int main()
{
    int vrhX,vrhY;
    char odg;
    graph *G = new graph;// kreiramo novi graf, alociramo jednu instancu grafa
    cout<<"\nInicijalizacija grafa...unos oznaka za vrhove...\n";
    initialize(G);
    cout<<"\nUnos bridova u grafu...unose se vrhovi koje zelite povezati...\n";
    do
    {
        cout<<"Unesite oznake vrhova koje zelite povezati\n";
        cout<<"vrh X: "; //izvorisni cvor
        cin>>vrhX;
        cout<<"vrh Y: ";//odredisni cvor
        cin>>vrhY;
        inputEdge(G,vrhX,vrhY);
        cout<<"Zelite li dodati jos jedan brid (d/n)?";
        cin>>odg;
    }
    while(odg!='n');
    writeVertices(G);
    writeEdges(G);
    writeMatrix(G->mat, G->numV);

    return 0;
}

void initialize(graph *&G)
{
    cout<<"Unesite broj vrhova: ";
    cin>>G->numV;//pristup komponentama preko pokazivaca
    cout<<"Unesite oznake vrhova grafa (brojevima): \n";
    for (int i=0;i<G->numV;i++)
        cin>>G->vtx[i];
    G->numE=0;
    MATRIXinc(G->numV, 0, G->mat);
    return;
}

void inputEdge(graph *&G, int x, int y)
{
G->e[G->numE].x=x; //polje e sadrzi te bridove, 1.brid na nultoj poziciji u polju
G->e[G->numE].y=y;
addToMatrix(G,x,y);
G->numE++;
}

void writeVertices(graph *G)
{
    cout<<"Vrhovi: ";
    for (int i=0; i<G->numV; i++)
        cout<<setw(5)<<G->vtx[i];
    cout<<endl;
}

void writeEdges(graph *G)
{
cout<<"Bridovi (parovi vrhova): \n";
    for (int i=0; i<G->numE; i++)
        cout<<setw(5)<<"("<<G->e[i].x<<", "<<(*G).e[i].y<<")\n";
    cout<<endl;
}

void MATRIXinc(int r_c, int val, int mat[][10])
{
    for(int i=0;i<r_c;i++)
        for(int j=0;j<r_c;j++)
            mat[i][j]=val;
}


void writeMatrix(int mat[][10], int r_c){
    for(int i=0;i<r_c;i++)
        {
            for(int j=0;j<r_c;j++)
                cout<<mat[i][j];
            cout<<endl;
        }
}


void addToMatrix(graph *&G, int x, int y){
    int i=0, j=0;
    while(G->vtx[i]!=x)
            i++;
    while(G->vtx[j]!=y)
            j++;
    G->mat[i][j]=1;
}

