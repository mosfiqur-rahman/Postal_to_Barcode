#include <iostream>
#include <string>

using namespace std;
int makeCheckDigit (int zipcode);
string convertDigit(int value);
string barcode( int zipcode);


int main()
{
    int zipcode, check_digit;
    int value;
    string bar_code_value;
    cout << "Hi, welcome to postal bar-code converter. I will convert your postal code into bar code." << endl;
    cout << "So, lets start!" << endl;
    while (cout << "Please, enter the zip code: " && cin >> zipcode)
    {
    if(zipcode > 0)
    {   check_digit = makeCheckDigit(zipcode);
        cout << "So, the check digit for your zip code is: " << check_digit <<endl << endl;

        bar_code_value = barcode(zipcode);
        cout << "Finally, your bar code is: " << bar_code_value << endl << endl;
    }
    else
    {
        cout << "Sorry, you have typed a negative number. Please, give a positive integer as an input." << endl;
    }
    }
    return 0;
}

int makeCheckDigit (int zipcode)
{
int sum_of_digits = 0;
int check_digit;
while(zipcode >0)
    {
        sum_of_digits += zipcode % 10;
        zipcode /= 10;
    }
    check_digit = 10 - (sum_of_digits % 10);
}


string convertDigit(int value)
{
if (value == 0)
return "||:::";
else if (value == 1)
return ":::||";
else if (value == 2)
return "::|:|";
else if (value == 3)
return "::||:";
else if (value == 4)
return ":|::|";
else if (value == 5)
return ":|:|:";
else if (value == 6)
return ":||::";
else if (value == 7)
return "|:::|";
else if (value == 8)
return "|::|:";
else if (value == 9)
return "|:|::";
else
return "Invalid";

}


string barcode( int zipcode)
{
int check_digit = makeCheckDigit(zipcode);
int digit_1, digit_2, digit_3, digit_4, digit_5;
digit_1 = zipcode % 10;
zipcode /= 10;
digit_2 = zipcode % 10;
zipcode /= 10;
digit_3 = zipcode % 10;
zipcode /= 10;
digit_4 = zipcode % 10;
zipcode /= 10;
digit_5 = zipcode % 10;
zipcode /= 10;

string prefix = "|" + convertDigit(digit_5) + convertDigit(digit_4) + convertDigit(digit_3) + convertDigit(digit_2) + convertDigit(digit_1);
string suffix = convertDigit(check_digit) + "|";

return (prefix + suffix);
}

