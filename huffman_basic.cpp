#include<iostream>
#include<bitset>
using namespace std;


returnCodes()
{
    if()

 static string code="";
 returnCodes(root->left,code+"1");
 returnCodes(root->right,code+"0");






}
int main(){








}
  /*  //Constuct 01: 8 bits initialized to zero
bitset<8> bitset1;
cout << "Construction without any parameter. Content of bitset1 :"
    << bitset1 << endl;

//Construct 02: Construct it from a integer number
bitset<8> bitset2(177);
cout << "Constructor with int as parameter. Content of bitset2: "
    << bitset2 << endl;

//Construct 03: Construct it from string
bitset<8> bitset3(string("1"));
cout << "Constructor with string parameter.Content of bitset3: "
    << bitset3 << endl;
  bitset3 &= ~(1UL << 5);
   cout << "Constructor with string parameter.Content of bitset3: "
    << bitset3 << endl;
    cout<<bitset2.size();


    }
    /*
int bitstring = 0x02;
bitstring |=1;
cout<< bitstring;

// This turns a 32-bit integer into a binary string.
/*
char lookup[256][9] = {
    "00000000",
    "00000001",
    "00000010",
    "00000011",
    // ... etc (you don't want to do this by hand)
    "11111111"
};

char * lolo = lookup[val & 0xff];
char * lohi = lookup[(val>>8) & 0xff];
char * hilo = lookup[(val>>16) & 0xff];
char * hihi = lookup[(val>>24) & 0xff];

// This part is maybe a bit lazy =)
char bitstr[33];
sprintf( "%s%s%s%s", hihi, hilo, lohi, lolo );
*/
/*
char bitstr[33] = {0};
for( int b = 0; b < 32; b++ ) {
    if( bitstring & (1 << (31-b)) )
        bitstr[b] = '1';
    else
        bitstr[b] = '0';
}
cout<<bitstr;
}*/
