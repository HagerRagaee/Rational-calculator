// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: rational caculator.cpp
// Author1: Hager Ragaee_ ID:20211108_ Group A.
// Author2:Amal Mohamed_ ID:20211016_ Group A.
// Author3:Abdelrhman sayed_ ID:20210205_ Group: A.
//Team Task

#include <iostream>
#include <string>
#include <regex>
using namespace std;
//This function(regex) determines what is allowed to be entered as text
//[-+]...>>>positive or negative in front of first ration >>> example >>(-or+)1/2
//(?)The question mark in this function indicates that it is optional between parentheses
//(*)The multiplication sign in this function indicates that between parentheses is compulsory
//[1-9][0-9]  Even allowing the user to enter whatever numbers he wants
//[0-9]+(/[1-9][0-9]......>>This part inserts the first rational number
//[-+*/]...>>this operators allowed to use it in text
//0-9]+(/[1-9][0-9]......>>This part inserts the second rational number

bool isValidRational_add(string&x)
{
    regex validRational_add("[-+]?[0-9]+(/[1-9][0-9]*)?[+][0-9]+(/[1-9][0-9]*)?");
    return regex_match(x, validRational_add);
}
bool isValidRational_sub(string&x)
{
    regex validRational_sub("[-+]?[0-9]+(/[1-9][0-9]*)?[-][0-9]+(/[1-9][0-9]*)?");
    return regex_match(x, validRational_sub);
}
bool isValidRational_mal(string&x)
{
    regex validRational_mal("[-+]?[0-9]+(/[1-9][0-9]*)?[*][0-9]+(/[1-9][0-9]*)?");
    return regex_match(x, validRational_mal);
}
bool isValidRational_div(string&x)
{
    regex validRational_div("[-+]?[0-9]+(/[1-9][0-9]*)?[/][0-9]+(/[1-9][0-9]*)?");
    return regex_match(x, validRational_div);
}
int main() {
    string x;
    string num1,num2,de1,de2;
    int n1,n2,d1,d2;
    int Num_Result,DEN_result,choice;
     /*x:that text contain ration one +operation+ration two
    de1 : the first denominator(string)
    de2 : the second denominator(string)
    num1: the first numerator(string)
    num2 : the second numerator(string)


    d1 : the first denominator(integer)
    d2 : the second denominator(integer)
    n1: the first numerator(integer)
    n2 : the second numerator(integer)
    Num_Result : This the result of numerator
    DEN_result : This the result of denominator
    */

    cout<<"#Welcome ,user"<<endl;
    cout<<"****This Rational Calculator Program****"<<endl;
    while(true)
    {
        cout<<"======================================================================================================================="<<endl;

        cout<<endl;
        cout << "1) Add" << endl;
        cout << "2) Subtract" << endl;
        cout << "3) Multiply" << endl;
        cout << "4) Divide" << endl;
        cout << "5) Quit" << endl;
         if (!cin)//This condition to not allow infinite loop
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
        cout << "Enter the operation you want: \n";
        cin >> choice;
        if (choice > 5)
            {
           cout << "Invalid input\nPlease ,Enter number in range 0---->5! \n";
        }

       //this functions(stoi.substr) do same thing in multiply
       else if (choice == 1) {
           cout << "Please ,Enter the text:\n";
           cin >> x;
           if (isValidRational_add(x)) {

               num1 = x.substr(0, x.find('/'));
               de1 = x.substr(x.find('/') + 1, x.find('+') - 2);
               num2 = x.substr(x.find('+') + 1, x.find('/'));
               de2 = x.substr(x.find('+') + 3, x.find('/') + 2);

               n1 = stoi(num1);
               n2 = stoi(num2);
               d1 = stoi(de1);
               d2 = stoi(de2);
               Num_Result = (n1 * d2) + (n2 * d1);
               DEN_result = d1 * d2;
               cout << '=' << Num_Result << '/' << DEN_result << endl;

           }
           else
           {
               cout << "Invalid operand!!\n**Please try again**\n"<<endl;;
           }
       }
       //this functions(stoi.substr) do same thing in multiply
        else if (choice == 2)
        {
            cout << "Please ,Enter the text:\n";
            cin >> x;
            if (isValidRational_sub(x))
            {
                num1 = x.substr(0, x.find('/'));
                de1 = x.substr(x.find('/') + 1, x.find('-') - 2);
                num2 = x.substr(x.find('-') + 1, x.find('/'));
                de2 = x.substr(x.find('-') + 3, x.find('/') + 2);

                n1 = stoi(num1);
                n2 = stoi(num2);
                d1 = stoi(de1);
                d2 = stoi(de2);
                Num_Result = (n1 * d2) - (n2 * d1);
                DEN_result = d1 * d2;
                cout << '=' << Num_Result << '/' << DEN_result << endl;
            }
            else
            {
                cout << "Invalid operand!!\n**Please try again**\n"<<endl;
            }
        }
        if (choice == 3)
        {
            cout << "Please ,Enter the text:\n";                             // n1/d1*d2/n2
            cin >> x;
            if (isValidRational_mal(x)&&x.find('*'))
            {

                //example .....>>> input >>123/34*45/5
                //This function(substr) takes a specific part of the entered text
                // This function(find) searches for a specific character in the entered text
                num1 = x.substr(0, x.find('/'));//it will take character from 0 to it reach to (/) ...>>> 123 >>>> this became the first denominator
                de1 = x.substr(x.find('/') + 1, x.find('*') - 2);// it will take character from after(/) to (*) .....>>34>>this became the first numerator
                num2 = x.substr(x.find('*') + 1, x.find('/'));//it will take character from after (*) to find (/)...>>>45>>this became the second denominator
                de2 = x.substr(x.find('*') + 3, x.find('/') + 2);// this become the second numerator
                // this function(stoi) covert string to integer
                n1 = stoi(num1);
                n2 = stoi(num2);
                d1 = stoi(de1);
                d2 = stoi(de2);

                Num_Result = n1 * n2;
                DEN_result = d1 * d2;
                cout << '=' << Num_Result << '/' << DEN_result << endl;
            }
            else
            {
                cout << "Invalid operand!!\n**Please try again**\n"<<endl;
            }
        }
        //this functions(stoi.substr) do same thing in multiply
        else if (choice == 4) {
            cout << "Please ,Enter the text:\n";
            cin >> x;
            if (isValidRational_div(x))
            {
                num1 = x.substr(0, x.find('/'));
                de1 = x.substr(x.find('/') + 1, x.find('/') - 2);
                num2 = x.substr(x.find('/') + 1, x.find('/'));
                de2 = x.substr(x.find('/') + 3, x.find('/') + 2);

                n1 = stoi(num1);
                n2 = stoi(num2);
                d1 = stoi(de1);
                d2 = stoi(de2);
                Num_Result = n1 * d2;
                DEN_result = d1 * n2;
                cout << '=' << Num_Result << '/' << DEN_result << endl;

            }
            else
            {
                cout << "Invalid operand!!\n**Please try again**\n"<<endl;
            }
        }
        else if (choice == 5)
        {
            cout << "##Thank you for using rational number calculator\n";
            break;
        }
        else
            {
                cout<<"Invalid input\n**Please try again**"<<endl;
                continue;
            }
    }
    return 0;
}
