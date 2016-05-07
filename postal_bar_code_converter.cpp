/***************************************************************************************************
PROGRAM : postal_bar_code_converter.cpp
PURPOSE : This program will convert any five digit zipcode into its complete barcode. For this reason,
          it will take the integer value of the zipcode as an input, and will show the barcode as an output.
          Here, the program will ask its user  to input a zipcode, the program will convert it into barcode.
          The program will continue to ask its user as long as the user
          inputs positive integers. If the user inputs anything other than integers[i.e. any character like- 'a', etc],
          then the program will terminate, and will end its process. But if the user inputs any decimal number,
          the program will only count the integer part of the input.
Coder :   Mosfiqur Rahman (mr986@drexel.edu)
Last Modified : 9th Febrruary, 2016.
***************************************************************************************************/

#include <iostream>  // for  having input and output
#include <string>    // for the using of sting

using namespace std; //for standard library functions, like- cout, etc.
int makeCheckDigit (int zipcode); // prototyping function makeCheckDigit, which will find the check digit from the zipcode.
string convertDigit(int value); // prototyping function convertDigit, which will convert every single digit of the zipcode to barcode individually.
string barcode( int zipcode); //prototyping function barcode, which will produce the whole barcode for the zipcode using
                             // both the makeCheckDigit, and convertDigit function.

// The following function is the main function.
int main()
{
    int zipcode, check_digit; // declearing integer variables for storing the values of zipcode, and check_digit.
    string bar_code_value; // declearing a string variable to store the final barcode value of zipcode.


    cout << "Hi, welcome to postal barcode converter." << endl << "I will convert your postal code into barcode." << endl; // Optional, irtoductory texts.
    cout << endl << "So, lets start!" << endl<< endl; // Optional, irtoductory texts.

    while (cout << "Please, enter the five-digit zip code: " && cin >> zipcode) // a while loop for
                                                                    //asking a user to input a zipcode, for converting the input to barcode everytime, and
                                                                   //for asking another input again.
    {
        if(zipcode > 0)// Checking whether the value of zipcode is positive or negative.
        {             // If it's positive then continues, or moves to other conditional statement.

            check_digit = makeCheckDigit(zipcode);
            // Calling the makeCheckDigit funtion, and passing the value of zipcode in it.
            // Storing the value calculated by the makeChoiceDigit function in the integer variable check_digit.

            cout << endl << "So, the check digit for your zip code is: " << check_digit <<endl << endl;
            // Showing the value of the check digit as an output, which is stored in the variable check_digit.

            bar_code_value = barcode(zipcode);
            // Calling the barcode function, and passing the value of zipcode in it.
            // Storing the value calculated by the barcode function in the string variable bar_code_value.

            cout << "Finally, your barcode is: " << bar_code_value << endl << endl;
            // Showing the final value of the barcode as an output, which is stored in the variable bar_code_value.
        }

        else // If the previous 'if' statement fails, then the program runs through this statement.
        {    // i.e. Notifies the user if the input not non-negative.
            cout << endl << "Sorry, you have typed a negative number." << endl << "You need to give a positive integer as an input." << endl << endl;
            // Showing an error message that the user has typed a negative number.
            // And tells the user that he/she needs to give a positive number as an input.
        }
    }

    return 0;
}
/*
The following function will find the check-digit for a zipcode.
[Check-digit:- A check-digit is the value of the summation of all digits of a number,
 and it's chosen to make the sum a multiple of 10.]
@param 'zipcode', an integer variable, is the only parameter which will be taken by this function.
        After passing the value of the parameter, the function will go through a couple of steps-
       step 1:- It will run the value through a while loop to find the sum of the digits, and will continue
                calculating as long as its done with the following sub-steps.
                sub-step 1:- To find the sum, it will first find the modulus 10 of the passed value.
                sub-step 2:- Then it will store the value as an integer value in the variable 'sum_of_digits'.
                sub-step 3:- After that, it will divide the value of the variable 'zipcode' by 10, and will renew
                the integer value of the variable zipcode.
                sub-step 4:- The program will run sub-step 1 to 3 as long as it is done with the last digit of the value of 'zipcode'.
       step 2:- Now to find the desired check digit, the function will subtract the value of the modulus 10 of the value of the
                variable 'sum_of_digits', and will store the value in an integer variable check_digit.
@return the check digit value of the zipcode, which was stored in the variable check_digit after passing the value of zipcode.
*/
int makeCheckDigit (int zipcode) // Defining the makeCheckDigit function, which will find the check digit.
{
int sum_of_digits = 0;
// Declearing a variable to store the summation of the digits in the zipcode.[i.e. the passed value to the makeCheckDigit function]
// Initilizing the value of the variable to 0.

int check_digit;
// Declearing a variable to store the value of the check digit.

while(zipcode) // Running a while loop to find the summation of the digits of the zipcode.
    {
        sum_of_digits += zipcode % 10;
        // Finding every single digit individually by taking the modulus of the zipcode with the combination of the next step.
        zipcode /= 10;
        // After being done with the previous modulus 10 of zipcode, it will divide the value of zipcode by 10
        // Then it renews the value of zipcode in the variable zipcode.
    }
    check_digit = 10 - (sum_of_digits % 10);
    // To find the value of check digit,
    //it first finds the modulus 10 of the value of the summation of all digits in zipcode[i.e. the value of the variable sum_of_digits.
    // Then subtracts the value from 10 to find the desired value of check digit, and stores the value in the variable check_digit.

    return check_digit; // returns the value of check digit[i.e. the value of the variable check_digit.]
}

/*
The following function will convert individual digits of zipcode to its indivudial barcodes.
If someone gives more than one digit as an input, it will generate an alert message of "invalid" output.
@param 'value', an integer variable is the only parameter, which will be taken by this fiunction.
       After passing the value of the parameter, it will pass the value through
       some logical statements[if-else statements], and check what the digit is.
       Again, there are different return values[i.e. barcode values] for every digit from 0 to 9.
       However, if anything else than a digit from 0 to 9 is passed, it will also generate an alert message of "invalid" output.
@return the barcode value of an individual digit after passing the value of the variable 'value'.
*/
string convertDigit(int value) // Defining the convertDigit function, which will convert individual digits to its barcodes.
{
    if (value == 0)
    // Setting up a condition, for the passed value of the integer 0.
        return "||:::";
        // returns the value as initialized in the string when the passed integer is 0.

    else if (value == 1)
    // Setting up a condition, for the passed value of the integer 1.
        return ":::||";
        // returns the value as initialized in the string when the passed integer is 1.

    else if (value == 2)
    // Setting up a condition, for the passed value of the integer 2.
        return "::|:|";
        // returns the value as initialized in the string when the passed integer is 2.

    else if (value == 3)
    // Setting up a condition, for the passed value of the integer 3.
        return "::||:";
        // returns the value as initialized in the string when the passed integer is 3.

    else if (value == 4)
    // Setting up a condition, for the passed value of the integer 4.
        return ":|::|";
        // returns the value as initialized in the string when the passed integer is 4.

    else if (value == 5)
    // Setting up a condition, for the passed value of the integer 5.
        return ":|:|:";
        // returns the value as initialized in the string when the passed integer is 5.

    else if (value == 6)
    // Setting up a condition, for the passed value of the integer 6.
        return ":||::";
        // returns the value as initialized in the string when the passed integer is 6.

    else if (value == 7)
    // Setting up a condition, for the passed value of the integer 7.
        return "|:::|";
        // returns the value as initialized in the string when the passed integer is 7.

    else if (value == 8)
    // Setting up a condition, for the passed value of the integer 8.
        return "|::|:";
        // returns the value as initialized in the string when the passed integer is 8.

    else if (value == 9)
    // Setting up a condition, for the passed value of the integer 9.
        return "|:|::";
        // returns the value as initialized in the string when the passed integer is 9.

    else
    // Setting up the condition, for rest of the integer inputs, except [from 0 to 9].
        return "Invalid";
        // returns the value as initialized in the string when the passed integer is except [from 0 to 9]

}
/*
The following function will convert the whole zipcode into its complete barcode.
@param 'zipcode', an integer variable, is the only parameter, which will be taken by the function.
       After passing the value of the parameter, it will call the 'makeCheckDigit' function, and pass
       the value again to this function. By using the 'makeCheckDigit' function, it will get the
       check digit of the passed value, and will store the value in an integer variable check_digit.
       Now it store the barcode value of every single digit of the zipcode by placing one after another
       in a string variable 'prefix' starting with "|" at the front using the convertDigit function.
       Here, to separate the digits from the whole zipcode,
       step-1:- the function will find the modulus 10 of the zipcode, and store the value in a integer variable digit_1.
       step-2:- Then it'll divide the value of zipcode by 10 and renew the value in the variable zipcode.
       step-3:- the function will follow step 1 and 2 till it's done with the last digit, store the values in
       variables digit_2, digit_3, digit_4, digit_5 respectively as there are five digits in a zipcode.
       Now, the barcode function will pass the values of the variables from digit_5 to digit_1 in the
       convertDigit function, and will store the complete value in string 'prefix'.
       This is the first part of the complete barcode of the passed zipcode.
       To get the rest of the part of the barcode, the barcode function will call the convertDigit function again,
       and will find the barcode for the checkdigit. After that, it will store the value in another string 'postfix',
       placing a "|" after that.
@return the value of (prefix+postfix).

*/
string barcode(int zipcode) // Defining the barcode function, which will convert the whole zipcode into complete barcode.
{

    int check_digit = makeCheckDigit(zipcode);
    // Calling the makeCheckDigit funtion, and passing the value of zipcode in it.
   // Storing the value calculated by the makeChoiceDigit function in the integer variable check_digit.

    int digit_1, digit_2, digit_3, digit_4, digit_5;
   // Declearing five different variables to store the five particular digits of the zipcode respectively.

        digit_1 = zipcode % 10;
        // Declearing a variable to store the last digit of the zipcode indivudially,
        // by taking modulus 10 of the value of the variable zipcode.
        zipcode /= 10;
        // After being done with the previous modulus 10 of zipcode, it will divide the value of zipcode by 10
        // Then it renews the value of zipcode in the variable zipcode.
        digit_2 = zipcode % 10;
        // Declearing a variable to store the forth digit of the zipcode indivudially,
        // by taking modulus 10 of the value of the variable zipcode.
        zipcode /= 10;
        // After being done with the previous modulus 10 of zipcode, it will divide the value of zipcode by 10
        // Then it renews the value of zipcode in the variable zipcode.
        digit_3 = zipcode % 10;
        // Declearing a variable to store the third digit of the zipcode indivudially,
        // by taking modulus 10 of the value of the variable zipcode.
        zipcode /= 10;
        // After being done with the previous modulus 10 of zipcode, it will divide the value of zipcode by 10
        // Then it renews the value of zipcode in the variable zipcode.
        digit_4 = zipcode % 10;
        // Declearing a variable to store the second digit of the zipcode indivudially,
        // by taking modulus 10 of the value of the variable zipcode.
        zipcode /= 10;
        // After being done with the previous modulus 10 of zipcode, it will divide the value of zipcode by 10
        // Then it renews the value of zipcode in the variable zipcode.
        digit_5 = zipcode % 10;
        // Declearing a variable to store the first digit of the zipcode indivudially,
        // by taking modulus 10 of the value of the variable zipcode.
        zipcode /= 10;
        // After being done with the previous modulus 10 of zipcode, it will divide the value of zipcode by 10
        // Then it renews the value of zipcode in the variable zipcode.

string prefix = "|" + convertDigit(digit_5) + convertDigit(digit_4) + convertDigit(digit_3) + convertDigit(digit_2) + convertDigit(digit_1);
// Calling the convertDigit function several times to convert every single digit of the value of zipcoe[i.e. zipcode variable]
// Then it will combine all the results from every call of the convertDigit function, starting with "|"
// Now it will store the converted value in a string variable prefix.
// It's the first part of the whole barcode.

string postfix = convertDigit(check_digit) + "|";
// Calling the convertDigit function to convert the value of the check digit[i.e. check_digit variable]
// Then it will store the converted value in a string variable postfix.
// It's the second/last part of the whole barcode.

return (prefix + postfix);
// returns the value of the string prefix and postfix all together.
}
