/* PROGRAM`S IDENTITY: Wed Alsulaimani and a group of programmers
A SMALL DEFINITION ABOUT THE PROGRAM:	
The program receives the currency of the current country and outputs the exchange currency of the country that the user wants.
The program will not stop entering unless the user writes the currencies correctly.
A screen will appear to the user containing the names of countries and their currencies.
There is an attached file from which the conversion data is to be read. At the moment ,the program only transfers to the Arab Gulf countries */ 
#include<cctype>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void File(double,string,string);                
bool usable(string);                                                
double exchange(double); 
string capitalize(char,char,char);                                                      
void screen();
void getInput(string&);
int main(){                                                              
    string currency1,currency2;
    char firstletter,secondletter,thirdletter;
    screen();
    cout<<"Enter your current currency: ";
    getInput(currency1);
    cout<<"\nEnter the currency you want exchange it to: ";
    getInput(currency2);
    double ex = exchange(ex);
	 
	if(currency1==currency2){
		cout<<"FOCUS you wrote the same currency twice, \nEnter the currency you want exchange it to: ";
		getInput(currency2);
		if(currency1==currency2){
			
		cout<<"do you want to convert from and to the same currency? got it, the result is: "<<currency1<<" "<<ex;	
		}
		else{
		getInput(currency2);	
		}
	}           
    File(ex,currency1,currency2);
    return 0;
    }

    bool usable(string letter){
    	if(letter=="SAR"||letter=="KWD"||letter=="QAR"||letter=="AED"||letter=="BHD"||letter=="OMR"){
    		return true;
		}
		else{
			cout<<"Invalid currency please try again: ";
			return false;
		}}

    string capitalize(char firstletter,char secondletter,char thirdletter){
    string letter;
	cin>>firstletter>>secondletter>>thirdletter;
	cout<<endl;
	letter.append(1,toupper(firstletter));
	letter.append(1,toupper(secondletter));
	letter.append(1,toupper(thirdletter));
	return letter;                                                               
    }

    void screen(){
    string s = "SAR--> Kingdom of Saudi Arabia Riyal \nKWD--> Kuwaiti Dinar \nQAR--> Qatar Riyal \nAED--> United Arab Emirates Dirham \nBHD--> Bahraini Dinar \nOMR--> Omani Riyal \n\n";
    cout<<s;
    }

    double exchange(double ex){
    do{
    cout<<"\nHow much money you want to exchange? ";
    cin>>ex;	
	}
	while(ex<=0);
    return ex;
    }
    
    void getInput(string &currency){
	char firstletter,secondletter,thirdletter; 
	do{
    currency=capitalize(firstletter,secondletter,thirdletter);	
	}
    while(!usable(currency));
    usable(currency);
	}
    
    void File(double ex, string cc, string nc){                                                                                                                 // ex = exchange money , cc = current currency , nc = new currency 
    ifstream file; 
	string currency1,currency2;
	double rate1,rate2; 
	file.open("ExchageRate.txt");   
    while(!file.eof()){                                                                                                                                    // eof = End Of File {function}
    string array[15][4];
    for(int i=0;i<15;i++){
    	for(int j=0;j<4;j++){
		file>>rate1>>currency1>>rate2>>currency2;                                                                                                        //The order of the variables is important
        if(cc==array[15][4] && nc==array[15][2]){                                                                                                       // If the current currency entries are equal to the currencies in the file on the left, we multiply and the opposite is true
	    cout<<"\nthe result of exchange is: "<<currency1<<" is "<<rate2*ex<<" "<<currency2; 
	    break;
        }   
        else if(cc==array[15][2] && nc==array[15][4]){
	    cout<<"\nthe result of exchange is: "<<currency2<<" is "<<ex/rate2<<" "<<currency1;
	    break;
        }
		else{
			break;
		}}}
     file.close();
    }}
