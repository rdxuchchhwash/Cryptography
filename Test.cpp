#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<string.h>
using namespace std;


char arr[100];
int numarr[100];
int asci=33;
char input[100];
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
int z=0,l=0;
int diff;

void det();
void encryption();
void decryption();
void cryptokey_input();
void cryptographykey();
void clear_cls ();
void cryptokey_show();
void user_input();
void user_input_decryption();
void encrypt_clear_cls();
void decrypt_clear_cls();

int main()
{   system("cls");
    char choice;
    for(int i=0,j=33;i<93;i++)
        {
            letterarray[i]=(char)j++;
        }

    for(int i=0;i<93;i++)   //chang
    {
        arr[i]=asci;
        //arr[i+32]=asci+32;
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
                    z=0;
                    encrypt_clear_cls();
                    break;
                case '2':
                    decrypt_clear_cls();
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

    cout<<"Enter the String: ";
    user_input();


system("cls");
if(z%3==0)
  {
    for(int i=0;i<z;i++)
    {
        for (int j=0;j<93;j++)
        {
            if(input[i]==arr[j])
                numarr[i]=j+1;
        }
    }
//
    for(int i=0,c=0;i<z/3;i++)
    {
        for (int j=0;j<3;j++)
        {
            matrix[i][j]=numarr[c];
            c++;
        }
    }
cout<<endl;

cout<<"Matrix is: \t";

            for(int i=0;i<z/3;i++)
        {
            for (int j=0;j<3;j++)
            {
               cout<<" "<<matrix[i][j];
            }
            cout<<"\n\t\t";
        }
cout<<endl<<"Encrypted code is : ";
    int sum=0;
    for(int i=0;i<z/3;i++)

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
     for(int i=0;i<z/3;i++)
        {
            for (int j=0;j<3;j++)
            {
               cout<<" "<<encrypted[i][j];
            }

        }
        cout<<endl;
  }

}

void decryption()
{
//
        user_input_decryption();
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
                    for(int k=1;k<=93;k++) //changing
                        {
                            if(decrypted[i][j]==k)
                            decryptedletter[c]=letterarray[k-1];
                        }
                   c++;
            }
        }
        if(diff==2)
            l=l-2;
        else if(diff==1)
            l=l-1;
                cout<<"\nDecrypted Message Is: ";
              for(int i=0;i<l+1;i++)
                {
                    cout<<decryptedletter[i];
                }


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

void user_input()
{   int i=0,j=0,k=0;
    while(1)
    {
        input[i]=getche();
         if(input[i]==13)
        {
            break;
        }
        else if(input[i]==27)
            main();
        else if(input[i]==8)
        {

            if(z>0)
            {
               z=z-1;
               i=i-1;
            }

            system("cls");
            cout<<"Enter the String: ";

            for(int h=z-1;h>=0;h--)
                  cout<<"*";

            cout<<endl<<endl<<endl<<"Counter is : "<<z;

        }

        else
        {
            system("cls");
            j=i+1;
            k=0;

            cout<<"Enter the String: ";
           while(k<j)
            {
                cout<<"*";
                k++;
            }
            ++i;
            z++;
            cout<<endl<<endl<<endl<<"Counter is : "<<z;
        }
    }

    while(z%3!=0)
    {
        input[z]=32;
        z++;
    }


}


void user_input_decryption()
{
        int sum=0,s=0;
        char  enter;
        int count=1;
        int en;

    cout<<"Enter the Number of elements : ";

    while(1)
    {
        enter=getche();
        en=(int)enter;
        en=en-48;
        if(enter==27)
        {
            main();
        }
        else if(enter==8)
        {
            s=sum/10;
            sum=s;
            system("cls");
            cout<<"Enter the Number of elements : ";
            if(sum!=0)
                cout<<sum;
        }
        else if(enter==13)
        {
            break;
        }
        else if(enter<48||enter>57)
        {
            system("cls");
            cout<<"Enter the Number of elements : ";
            if(sum!=0)
                cout<<sum;

        }

        else if(count==1&&(enter>=48&&enter<=57))
        {
            sum=en;
        }
        else if(count>1&&(enter>=48&&enter<=57))
        {
            s=sum*10+en;
            sum=s;
        }
        count++;


    }
    l=sum;
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
    }
    else
        {
             while(l%3!=0)
            {
                l++;
            }

            int di=l-sum;
            diff=di;
            cout<<endl<<di;
            int v=l/3;

            if(di==2)
            {
                di=0;
            }

        cout<<endl<<l;
        cout<<endl;
        if(l%3==0)
            {
                cout<<endl<<"Enter the encrypted codes : ";
             for(int i=0;i<l/3;i++)
                {
                    for (int j=0;j<3;j++)
                    {
                            if(i==v-1&&j>di)
                            {
                               break;
                            }

                            else
                                cin>>encrypted[i][j];
                    }

                }
            }
        }

}

void encrypt_clear_cls()
{
    for(int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
            {   matrix[i][j]=0;
                encrypted[i][j]=0;
            }

    }

    for(int i=0;i<100;i++)
    {
        input[i]=0;
        numarr[i]=0;
    }
}


void decrypt_clear_cls()
{
    for(int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
            {  decrypted[i][j]=0;
                encrypted[i][j]=0;
            }

    }
memset (decryptedletter, 0, sizeof( decryptedletter));

}
