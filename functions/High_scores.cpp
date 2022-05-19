#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void scorebrd(int gameloops, int turns[], int score[], string name[]){ //every n press minus 10, 100 base points, if win times points by two
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

int main(){
    string name[100] = {"jack","mary","le"};
    int turns[100] = {132,23,30}, score[100] = {12,56,11}, gameloops=3;
    scorebrd(gameloops, turns, score, name);


}