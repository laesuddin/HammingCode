#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int a, b, c[100], d, r = 0, d1,err[10]={0};
    ifstream input;
    input.open("input.txt");
    cout << "Enter the Data Bits such as 4,11,26: ";
    input >> a;
    cout<<a<<endl;
    while (a + r + 1 > pow (2, r))
    {
      r++;
    }
    cout << "Total Bits(data+redundant) :" << a + r << endl;

    cout <<endl<< "Enter the data bits :";
    for (int i = 1; i <= a; ++i)
        input >> c[i];

    for (int i = 1; i <= a; ++i)
        cout << c[i] << " ";
    cout << endl;
    int data[a + r],res[a+r];
    d = 0;
    d1 = 1;
    for (int i = 1; i <= a + r; ++i)
    {
      if ((i) == pow (2, d))
        {
        data[i] = 0;
        ++d;
        }
      else
        {
        data[i] = c[d1];
        ++d1;
        }
    }
    cout<<endl<< "Data bits are encoded with parity bits-0: ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
    d1 = 0;
    int min, max = 0, parity, s, j;
    /*Parity Bit Calculation */
    for (int i = 1; i <= a + r; i = pow (2, d1))
    {
      ++d1;
      parity = 0;
      j = i;
      s = i;
      min = 1;
      max = i;
      for (j; j <= a + r;)
    {
        for (s = j; max >= min && s <= a + r; ++min, ++s)
        {
        if (data[s] == 1)
            parity++;
        }
        j = s + i;
        min = 1;
    }
      if (parity % 2 == 0) // Even Parity
    {
    data[i] = 0;
    }
      else
    {
    data[i] = 1;
    }
    }
    cout << endl << "Hamming codeword bits for even parity are : ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
    cout << endl << endl;


    cout<<"Enter received message: "<<endl;
    for (int i = 1; i <= a+r; ++i)
        input >> res[i];

    for (int i = 1; i <= a+r; ++i)
        cout << res[i] << " ";
    cout << endl;

    d1 = 0;max=0;int ec=0;
    //int min, max = 0, parity, s, j;
    /*Parity Bit Calculation */
    for (int i = 1; i <= a + r; i = pow (2, d1))
    {
      ++d1;
      parity = 0;
      j = i;
      s = i;
      min = 1;
      max = i;
      for (j; j <= a + r;)
    {
        for (s = j; max >= min && s <= a + r; ++min, ++s)
        {
        if (res[s] == 1)
            parity++;
        }
        j = s + i;
        min = 1;
    }
      if (parity % 2 == 0) // Even Parity
    {
    err[ec]=0;
    ec++;
    }
      else
    {
    err[ec]=1;
    ec++;
    }
    }
    int flag = 1;
    for(int i =r-1;i>=0;i--)
    {
        if(err[i]==1)
        {
            flag =0;
                break;
        }
    }
    if(flag==0)
    {
        int pos=0;
    cout<<endl<<"Error detected at: ";
    for(int i =r-1;i>=0;i--)
    {
        cout<<err[i]<<" ";
        if(err[i]==1)
            pos+=pow(2,i);
    }
        cout<<"\nPosition of error :"<<pos;
        res[pos]=!res[pos];
        cout<<"\nAfter correction: ";
        for(int i =1;i<=a+r;i++)
          cout<<res[i]<<" ";
        cout<<endl;
    }
    else
       cout<<"No Error detected. ";
    return 0;
}
