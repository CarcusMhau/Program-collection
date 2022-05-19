#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream> // need to include this for scoreboard
using namespace std;


class menu{
    public:
        menu(/*int &pieces, int &range1, int&range2*/ ){
            welcome = "[Greetings, and welcome to the puzzle game]"; //Greeting phrase
            piecenums= 25;
            range3= 0;
            range4= 5;
        };


        void checks(){
            cin.clear(); // Reset the input error status to no error
            cin.ignore(255, '\n'); // ignore maximum of 255 characters,
        }

        

        void pritm(){
            string start[10]={"start game","settings","Features","credits","exit"}; //storage for menu options
            cout<<welcome<<endl;
            cout<<"*****Main menu*****"<<endl;
            for(int a=0;a<5;a++){
                cout<<setw(10)<<right<<"["<<a+1<<"]";
                cout<<start[a]<<endl;
                 
            }
            cout<<endl;
            userinp();

        }

        void mumber(){
            cout<<endl<<setw(11)<<right<<"Credits"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<setw(15)<<left<<"Student name:"<<setw(9)<<"Student number: "<<setw(3)<<"Class no. :"<<endl;
	        cout << "Chau Ka Hei     21147834A      204B" << endl;
	        cout << "Leung Hei Ho    21053424A      204D" << endl;
	        cout << "Leung Ka Hung   21000720A      204D" << endl;
	        cout << "Yeung Nga Ting  21166627A      204D" << endl;
	        cout << "Yiu King Wai    21029829A      204A" << endl;
	        cout << "Yu Chung Ming   21031296A      204A" << endl;
        
          
            cout<<endl<<"Enter .q to return to main menu: ";
            string text;
            cin>>text;
            if(text==".q")
                pritm();
            else if(cin.fail()){
                checks();
                mumber();
            }
            
        }

         void feareturn(){
            string text;
            cout<<endl<<"Enter .q to return to feature menu: ";
            cin>>text;
            if(text==".q")
                features();
            
            else{
                feareturn();
            }
        }

        void quit(){ // options for exiting the game, call test.quit() as prototype
            char choice;
            cout<<endl<<"Are you sure that you want to quit? (y/n): ";
            cin>>choice;
            while(choice!='n' || choice!='N'){
                 if(choice=='y' || choice =='Y'){
                    return ;}
                else{
                    cout << "The value entered is out of range or of a different type";
                    break; 
                }
            }
            
            //system("cls");
            pritm();
        }

        void scorebrd(){ //every n press minus 10, 100 base points, if win times points by two
            int first=0,second=0, third=0,compare=0,compare2,records[]={0,0,0};
            string list[40];


            for(int a=0;a<gameloops;a++){        
            compare = score[a];   
                if(compare>first){
                    third = second;
                    second = first;
                    first= compare; 
                    records[0]=a;
                   
                }
                else if(compare>second){
                    third = second;
                    second = compare;
                    records[1] = a;
                   
                }
                else if(compare>third){
                    third=compare;
                    records[2] = a;

                }
            }

            cout <<setw(35)<< "__Score leaderboard__"<<endl<<endl;
            cout<<"Rank"<<setw(9)<<right<<"Score"<<setw(15)<<right<<"Moves used"<<setw(11)<<"User name"<<endl<<endl;
            cout<<"1: "<<setw(6)<<first<<setw(10)<<" "<<turns[records[0]]<<" "<<setw(11)<<name[records[0]]<<endl;
            cout<<"2: "<<setw(6)<<second<<setw(10)<<" "<<turns[records[1]]<<" "<<setw(11)<<name[records[1]]<<endl;
            cout<<"3: "<<setw(6)<<third<<setw(10)<<" "<<turns[records[2]]<<" "<<setw(11)<<name[records[2]]<<endl;
        }

        void piece_no(int &piecenums){ // the changes in piece nums can't affect main 
            int flag= 1,temp=piecenums;
            cout<<"Settings:: pieces in the game"<<endl<<endl;
            cout<<"current number of pieces in game : "<<piecenums<<endl;
            while(flag==1 ){
                cout<<"insert the number of pieces :";
                cin>>temp;
                if(temp>=1 && temp<=25 ){
                    piecenums = temp ;
                    cout<<"the new  number of pieces is "<<piecenums<<endl;
                    flag=0;}
                else if(cin.fail()){
                    cout<<"The input is invalid, a integer should be inserted"<<endl;
                    cin.clear(); // Reset the input error status to no error
                    cin.ignore(255, '\n');
                    }

                else {cout<<"Invalid input range , the number should be between 1 and 25"<<endl;}
                
                }
            settings();
            }

        void rand_number(int &ar, int &br){ 
                int flag=1, temp1, temp2;
                cout<<endl<<endl<<"Settings:: range of piece numbers"<<endl;
                cout<<"current range is "<<ar<<" to "<<br<<endl;
                while(flag==1){
                    cout<<"insert the smallest number first then the largest number in the range: ";
                    cin>>temp1>>temp2;
    
                    if(temp2>=temp1 && temp1>=0 && temp2 <=9){
                        ar = temp1;
                        br = temp2;
                        flag=0;}
                    else if (cin.fail()) { // check whether last input was failed
                        cout<<"The input is invalid, a integer should be inserted"<<endl;
                        checks();}
                    else if(temp2<temp1){
                        cout<<"The smaller number should be inserted first"<<endl;
                    }
                    else {cout<<"The numbers are not within range, "<<endl;} 
                
                }
                cout<<"the new  range is "<<ar<<" to "<<br<<endl<<endl;
                settings();
        }

        void settings(){
            int counter;
            string options[10]={"Number of puzzle pieces", "Range of random number", "Return to main menu"};// setting options
            cout<<"*** Settings menu ***"<<endl;
            for(int a=0;a<3;a++){
                cout<<setw(10)<<right<<"["<<a+1<<"]";
                cout<<options[a]<<endl;

            }
            cout<<"*************"<<endl;
            cout<<"Options (1 - 3): ";
            cin>>counter;
            if (counter==1){ // handles setting options
                   piece_no(piecenums); }
                
            else if(counter==2){
                    rand_number(range3, range4);}
            else if(counter=3){
                    pritm();
                    }
            else if(cin.fail()){
                    checks();
                    cout<<"The insertion is invalid, only a integer is accepted";

            }
            else{
                cout<<"number is invalid or out of range";
                settings();
                }
        }


       
        void features() {
	        const int options = 4;
		    int userinp;
		    string start[options] = { "Rulebook","Scoreboard","Game tips","Exit"};
            
	        cout <<endl<<setw(35)<< "__Game features__"<<endl<<endl;
            for (int a = 0; a <options; a++) {
                cout << setw(18) << right << "[" << a + 1 << "]";
                cout << start[a] << endl;
            }
            cout << "Select an option: "; cin >> userinp;

            if(userinp==2){
                scorebrd();
                feareturn();
            }
            else if(userinp==1){        
                cout << endl << endl << setw(35) <<right <<"-----Rules:-----"<< endl;
                cout << "First, choose any not-yet-placed puzzle piece and type in the coordinates." << endl;
                cout << "Then, the piece would be placed in the desired location in the game board." << endl;
                cout << "There is one criteria for the piece placement: Each puzzle piece can only be placed next to an existing piece in the game board\n, and that their touching sides should have the same number." << endl;
                cout << "Finally, the game is won when the player inserts all pieces into the the game board / the not yet place zone is empty\n" << endl;
                cout << "Player controls:\n" << endl;
                cout << "\t1.Rotate the selected piece: \nPlayers can rotate the selected puzzle piece in clockwise, anticlockwise direction or default position through inserting C, A or N respectively.\n";
                cout << "Regarding the rotion options from above, the number of rotations can set by the user" << endl;
                cout << "\t2.Placing the selected piece: \nInput a location (e.g. 1A) in the game board for placing the selected puzzle piece. \nElse, the player can choose to skip this step.\n" << endl;
                cout << "\t3.Rollback changes: \nIf the user wants to rollback their inputs, they can enter '#' in the undo row" << endl;
                feareturn();

            }
            else if(userinp==3) {
                //Tips();
                write(12,60);
                features();
            }
            else if (userinp == 4) {
			    pritm();
		    }
            else if(cin.fail()){
                cout << "A character is not valid for the menu "<<endl;
                checks();
                features();
            }
            else {
                checks();
                cout << "input is invalid or if wrong type "<<endl;
                features();
            }
            


        }

       

    int userinp(){ // takes user inputs and assigns a function
            cout<<"Option (1 - 5): ";
            cin>>counter;
            cout<<endl;
            switch (counter){
                case 1:
                    break;
                case 2:
                    settings();break;
                case 3:
                    features();
                    break;
                case 5:
                    quit();break;
                case 4:
                    mumber(); break;
                default: //validates users inputs
                    checks();
                    cout<<"The number is out of range or an invalid type"<<endl<<endl;
                    pritm();// calls back to menu
                    break;
            }
        }

        void write(int t,int steps){
            //string name; 

            /*best_time.open("test.txt",ofstream::out | ofstream::app);// the path can be changed for diffreent txt files*/


            cout<<"PLease input your nickname: ";
            cin>>name[gameloops];
            
            turns[gameloops] = steps;
            score[gameloops] = t;
            gameloops++;
            
            
    
        }

        string get(){
            /*for(int a=0;a<4;a++){
            cout<<"PLease input your nickname: ";
            cin>>name[a];
            }*/
            return name[0];
            
            
        }
    string welcome;
    string name[100] = {"jack","mary","le"};
    int turns[100] = {132,23,30}, score[100] = {12,56,11};
    int  counter, piecenums, range3,range4, gameloops=4;

};

 void features(int score){
            ofstream best_time;  // Opens the file included woth the program
            best_time.open("board.txt");// the path can be changed for diffreent txt files
            //while (! best_time.eof()){
               //     getline (best_time, line);
                    best_time<<score;
            //}
            best_time.close();
}
    
void write(int time,int steps){
    menu input;
    ofstream best_time;
    string name; 

    /*best_time.open("test.txt",ofstream::out | ofstream::app);// the path can be changed for diffreent txt files
    turns[100] = { */

    cout<<"PLease input your nickname: ";
    cin>>name;
    input.name[0]=name;
    input.turns[0] = steps;
    input.score[0] = time;
    //cout<<input.name[0]<<input.time[0]<<input.turns[0];
    
    
}


int main(){
    int q=12, gamepieces=25, range1=0, range2=5;
    menu test;/*gamepieces, range1, range2*/ //you can change the name 
    test.pritm(); //just call this and the menu test

   // write(test.turns[0],test.time[0]);
    cout<<test.get();
    
    //cout<<test.piecenums<<test.range3<<test.range4;
    //cout<<gamepieces<<endl;
    //test.write_time("12:00");
    return 0 ;
}
