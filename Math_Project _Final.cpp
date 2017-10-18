#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
using namespace std;


char arr[100];
int numarr[30];
int asci=65;
string input;
int matrix[10][10];
int encrypted[10][10];
int decrypted[10][10];
int cryptokey[3][3]={{1,2,3},{1,1,2},{0,1,2}};
char decryptedletter[100];
char letterarray[100];
int inverse[3][3];
int mat[3][3];
char ch2;
int determinant;

void det();
void encryption();
void decryption();
void cryptokey_input();
void cryptographykey();
void clear_cls ();
void cryptokey_show();

int main()
{   system("cls");
    char choice;
    for(int i=0,j=65;i<26;i++)
        {
            letterarray[i]=(char)j++;
        }

    for(int i=0;i<26;i++)
    {
        arr[i]=asci;
        arr[i+32]=asci+32;
        asci++;
    }
    det();
    cryptographykey();
    while(1)
    {
        cout<<"Press 1 for Encryption\nPress 2 for Decryption\nPress 3 for See Default Cryptokey\n";
        cout<<"Press 4 for Entering new Cryptokey\nPress escape for exit\n";
            choice=getche();
            system("cls");


        switch(choice)
            {
                case '1':
                    encryption();
                    break;
                case '2':

                    decryption();
                    break;
                case '3':
                        cryptokey_show();
                        cout<<"\nDeterminant is : "<<determinant<<endl;
                    break;
                case '4':
                     cryptokey_input();
                     break;

                case 27:
                    exit(1);
                    break;
                default:
                    cout<<"Input Error!Wrong Key";
            }
            cout<<endl<<"\n\n\nPress anykey To get back to main menu\nPress escape for exit\n";
           choice=getche();
           system("cls");
           if(choice==27)
           {
               break;
           }

             system("cls");
    }
}

void encryption()
{

    cout<<"Enter a string: " ;
    getline(cin,input);
//
int l;
l=input.size();
system("cls");
if(l%3==0)
  {
    for(int i=0;i<l;i++)
    {
        for (int j=0;j<26;j++)
        {
            if(input[i]==arr[j])
                numarr[i]=j+1;
            else if(input[i]==arr[j+32])
                numarr[i]=j+1;
        }
    }
//
    for(int i=0,c=0;i<l/3;i++)
    {
        for (int j=0;j<3;j++)
        {
            matrix[i][j]=numarr[c];
            c++;
        }
    }
cout<<endl;

cout<<"Matrix is: \t";

            for(int i=0;i<l/3;i++)
        {
            for (int j=0;j<3;j++)
            {
               cout<<" "<<matrix[i][j];
            }
            cout<<"\n\t\t";
        }
cout<<endl<<"Encrypted code is : ";
    int sum=0;
    for(int i=0;i<l/3;i++)

    {

        for(int j=0;j<3;j++)
        {   sum=0;
            for(int k=0;k<3;k++)
            {
                sum+=cryptokey[j][k]*matrix[i][k];
            }
            encrypted[i][j]=sum;

        }
    }
     for(int i=0;i<l/3;i++)
        {
            for (int j=0;j<3;j++)
            {
               cout<<" "<<encrypted[i][j];
            }

        }
        cout<<endl;
  }

else
    cout<<"String Length Error! String Length must be divisible by 3" ;
}

void decryption()
{
    int l=0;
    cout<<"Enter the Number of elements : ";
    cin>>l;

if(l%3==0)
    {
        cout<<endl<<"Enter the encrypted codes : ";
     for(int i=0;i<l/3;i++)
        {
            for (int j=0;j<3;j++)
            {
               cin>>encrypted[i][j];
            }
        }

            int sum=0;
        for(int i=0;i<l/3;i++)

        {

            for(int j=0;j<3;j++)
            {   sum=0;
                for(int k=0;k<3;k++)
                {
                    sum+=inverse[j][k]*encrypted[i][k];

                }
                decrypted[i][j]=sum;
            }
        }


    cout<<endl;
       for(int i=0;i<l/3;i++)
            {
                for (int j=0;j<3;j++)
                {
                   cout<<" "<<decrypted[i][j];
                }
                cout<<endl;
            }

         int c=0;
    for(int i=0;i<l/3;i++)
        {
            for(int j=0;j<3;j++)
            {
                    for(int k=1;k<=26;k++)
                        {
                            if(decrypted[i][j]==k)
                            decryptedletter[c]=letterarray[k-1];
                        }
                   c++;
            }
        }
                cout<<"\nDecrypted Message Is: ";
              for(int i=0;i<l;i++)
                {
                    cout<<decryptedletter[i];
                }


    }
    else
        cout<<"Error!Number of Elements must be divisible by 3";
}

void det()
{   int detA;
    detA=0;
    detA+=  (cryptokey[0][0])*(cryptokey[1][1]*cryptokey[2][2]-cryptokey[1][2]*cryptokey[2][1]);

    detA+= (-cryptokey[0][1])*(cryptokey[1][0]*cryptokey[2][2]-cryptokey[1][2]*cryptokey[2][0]);

    detA+=  (cryptokey[0][2])*(cryptokey[1][0]*cryptokey[2][1]-cryptokey[1][1]*cryptokey[2][0]);

    determinant=detA;

}

void cryptographykey()
{   det();
    if(determinant!=0)
    {
        mat[0][0]=cryptokey[1][1]*cryptokey[2][2]-cryptokey[1][2]*cryptokey[2][1];
        mat[0][1]=-(cryptokey[1][0]*cryptokey[2][2]-cryptokey[1][2]*cryptokey[2][0]);
        mat[0][2]=cryptokey[1][0]*cryptokey[2][1]-cryptokey[1][1]*cryptokey[2][0];
        mat[1][0]=-(cryptokey[0][1]*cryptokey[2][2]-cryptokey[0][2]*cryptokey[2][1]);
        mat[1][1]=cryptokey[0][0]*cryptokey[2][2]-cryptokey[0][2]*cryptokey[2][0];
        mat[1][2]=-(cryptokey[0][0]*cryptokey[2][1]-cryptokey[0][1]*cryptokey[2][0]);
        mat[2][0]=cryptokey[0][1]*cryptokey[1][2]-cryptokey[0][2]*cryptokey[1][1];
        mat[2][1]=-(cryptokey[0][0]*cryptokey[1][2]-cryptokey[0][2]*cryptokey[1][0]);
        mat[2][2]=cryptokey[0][0]*cryptokey[1][1]-cryptokey[0][1]*cryptokey[1][0];


        inverse[0][0]=mat[0][0]/determinant;
        inverse[0][1]=mat[1][0]/determinant;
        inverse[0][2]=mat[2][0]/determinant;
        inverse[1][0]=mat[0][1]/determinant;
        inverse[1][1]=mat[1][1]/determinant;
        inverse[1][2]=mat[2][1]/determinant;
        inverse[2][0]=mat[0][2]/determinant;
        inverse[2][1]=mat[1][2]/determinant;
        inverse[2][2]=mat[2][2]/determinant;
    }
    else
        cout<<"\nError! Determinant can't be 0\n";

cout<<endl;

}


void cryptokey_show()
{

    int i,j;
    system("cls");
    cout<<"Default Key Matrix is:  ";
      for(int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
               cout<<"  "<<cryptokey[i][j];
            }
            cout<<"\n\t\t\t";
        }
    cout<<"\nAnd Inverse of the Matrix is :  " ;
      for(int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
               cout<<"   "<<inverse[i][j];
            }
            cout<<"\n\t\t\t\t";
        }

}
void cryptokey_input()
{
            system("cls");
            clear_cls();
            cout<<"\nEnter the Numbers : ";

                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        cin>>cryptokey[i][j];
                    }
                }

                system("Cls");
                cout<<"Cryptokey Matrix is :"<<endl;
                for(int i=0;i<3;i++)
                    {
                        for (int j=0;j<3;j++)
                        {
                           cout<<" "<<cryptokey[i][j];
                        }
                        cout<<endl;
                    }
                    cout<<endl;
                cout<<"New Cryptokey has been inserted successfully."<<endl;

                        cryptographykey();
                        cout<<"\nDeterminant is : "<<determinant<<endl;
                        if(determinant!=0)
                        {
                            cout<<"\n\nInverse matrix is : ";
                                for(int i=0;i<3;i++)
                            {
                                for (int j=0;j<3;j++)
                                {
                                   cout<<"  "<<inverse[i][j];
                                }
                                 cout<<"\n\t\t    ";

                            }
                            cout<<endl;
                        }
        }

void clear_cls()
{
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            {   cryptokey[i][j]=0;
                inverse[i][j]=0;
                mat[i][j]=0;
            }

    }
}




