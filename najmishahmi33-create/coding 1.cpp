
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

double calculateMonthlyInstallment(double,double,double,int);

int main()
{
    int model, variant, region , loan_period;
    double price, down_payment, interest_rate;
    char _model[50], _variant[50], _region[50], option;
    
    do
    {
        cout << "Proton Car Loan Calculator" << endl << endl;
    
        cout << "Model [1-X50, 2-Exora, 3-Persona]: ";
        cin >> model;
        cout << "Variants [1-1.6L Standard CVT, 2-1.6L Premium CVT]: ";
        cin >> variant;
        if(model==1)
        {
            strcpy(_model,"X50");
            if(variant==1)
            {
                strcpy(_variant,"1.6L Standard CVT");
                price=85000.00;
            }
            else
            {
                strcpy(_variant,"1.6L Premium CVT");
                price=100000.00;
            }
        }
        else if(model==2)
        {
            strcpy(_model,"Exora");
            if(variant==1)
            {
                strcpy(_variant,"1.6L Standard CVT");
                price=59800.00;
            }
            else
            {
                strcpy(_variant,"1.6L Premium CVT");
                price=66800.00;
            }
        }
        else
        {
            strcpy(_model,"Persona");
            if(variant==1)
            {
                strcpy(_variant,"1.6L Standard CVT");
                price=47800.00;
            }
            else
            {
                strcpy(_variant,"1.6L Premium CVT");
                price=54600.00;
            }
        }

        cout << "Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
        cin >> region;
        if(region==1)
        {
            strcpy(_region,"Peninsular Malaysia");
        }
        else
        {
            strcpy(_region,"East Malaysia");
            price+=2000.00;
        }

        cout << "\nCar info" << endl;
        cout << "Model: " << _model << endl;
        cout << "Variant: " << _variant << endl;
        cout << "Region: "  << _region << endl;
        cout << "Paint Type: Metallic" << endl;
        cout << "Price (MYR) : " << fixed << setprecision(2) << price << endl; 
        
        cout << "\nDown Payment (MYR) : " ;
        cin >> down_payment;
        cout << "Interest Rate (%): ";
        cin >> interest_rate;
        cout << "Repayment period (in years): ";
        cin >> loan_period;

        double monthlyInstallment = calculateMonthlyInstallment(price, down_payment, interest_rate, loan_period);
        cout << "\nMONTHLY INSTALLMENT (MYR): " << fixed << setprecision(2) << monthlyInstallment << endl;

        cout << "\nDo you want to enter other data? [Y @ N]: ";
        cin >> option;
    }while((option=='Y')||(option=='y'));
    cout << "\nThank you :)";
    return 0;

}

double calculateMonthlyInstallment(double _price, double _down_payment, double _interest_rate, int _loan_period)
{
    double loanPrice = _price - _down_payment;
    double totalInterest = (loanPrice)*(_interest_rate/100.0)*(_loan_period);
    double monthlyLoan = (loanPrice + totalInterest) / (_loan_period*12.0);
    return monthlyLoan;
}   
