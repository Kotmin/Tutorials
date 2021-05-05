#include <iostream>

using namespace std;


float test(int n) //1 krok

{
    float mianownik=0;
    int licznik=0;
    float tab[n];
    float s=0;
    int i=1;

    bool czy_nie_przekroczono=true;
//2 krok

//while

    for(i=n; i>0; i--)
    {
        cout<<i<<". ";
        cin>>tab[i];
        if(i!=n)
            if(tab[i]>tab[i+1])
                break;
    }



//}

    //3 krok
    for(i=n; i>0; i--)
    {
        if(tab[i]!=0)
        {
            licznik++;
            mianownik=mianownik+(float)(1/tab[i]);
            //if m==0 //return -1;
            s=licznik/mianownik;
        }
    }



    cout<<"\nS wynosi "<<s<<"\n";
    //4 krok
    return s;
}



int main()
{

    test(5); //tutaj to 5 nie musi byc podawwane na sztywno
    //int n; cin>>n;test(n);

    return 0;
}
