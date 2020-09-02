#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int rand();
    void pause();
    int warFunction(int,int,bool&);
    int userCard, comCard, woncards,hold;
    bool turn = true;
    string extra;

    srand(time(0));                                    // seed the random number generator
    woncards = 26;

    while (woncards < 52 && woncards > 0)			   // check to see if you have all the cards or lost all your cards
    {
        if(!turn){                                     // switch comCard with user card every other turn.
            comCard = userCard;                        // computer gets random card
            userCard = rand()%14;
            turn = true;
        }else{                                          // user choosing card
            comCard = rand()%14;
            cout <<"User choose a card: ";
            cin >> userCard;
            getline(cin, extra);                        // remove anything in the buffer
            turn = false;
        }

        if (userCard > 14 || userCard < 1)              // check for incorrect input.
        {
            cout << "Cheater! YOU LOSE!" << endl;
            return 0;
        }

        cout << "Your Card is: ";
        switch(userCard){
            case 1:cout<< "ACE" <<endl;
                   userCard = 14;
                    break;
            case 13:cout<< "KING" <<endl;
                    break;
            case 12:cout<< "QUEEN" <<endl;
                    break;
            case 11:cout<< "JACK" <<endl;
                    break;
            default:cout<< userCard <<endl;
        }

        cout<<"Computer Card: ";
        switch(comCard){
            case 1:cout<< "ACE" <<endl;
                   comCard = 14;
                    break;
            case 13:cout<< "KING" <<endl;
                    break;
            case 12:cout<< "QUEEN" <<endl;
                    break;
            case 11:cout<< "JACK" <<endl;
                    break;
            default:cout<< comCard <<endl;
        }

        if (userCard > comCard)
        {
            cout <<"You Win!"<<endl;
            woncards++;
        }
        else if(userCard < comCard)
        {
            cout << "You Lose" << endl;
            woncards--;
        }
        else if(userCard == comCard)
        {
            cout << "WAR!" << endl;
            woncards = warFunction(woncards,userCard,turn);
        }

         cout <<"Current Score: " <<woncards<<endl;
         pause();


    }
        cout<< "game Over"<<endl;


    return 0;
}
//---------------------------------------------------------
/*
Name: warFunction
Description: recursive call for cases of war
Called by: main
Calls: pause
*/
int warFunction(int woncards, int userCard,bool &turn)
{
   int rand();
   int pause();
   int comCard, hold;
   string extra;

   cout << "\n3 cards are on the table!\n" <<endl;
   //cout <<"User choose a card: ";
   //cin >> userCard;

   if(!turn){                                     //switch comCard with user card every other turn.
            comCard = userCard;
            userCard = rand()%14;
            turn = true;
        }else{                                    //user choosing card
            comCard = rand()%14;
            cout <<"User choose a card: ";
            cin >> userCard;
            getline(cin, extra);                  //remove anything in the buffer
            turn = false;
        }

   if (userCard > 14 || userCard < 1)             //check for incorrect input.
        cout << "Cheater" << endl;

    cout << "Your Card is: ";                     //renaming cards
    switch(userCard){
        case 1:cout<< "ACE" <<endl;
               userCard = 14;
               break;
        case 13:cout<< "KING" <<endl;
               break;
        case 12:cout<< "QUEEN" <<endl;
               break;
        case 11:cout<< "JACK" <<endl;
               break;
        default:cout<< userCard <<endl;
    }

    cout<<"Computer Card: ";                       //re naming cards
        switch(comCard){
            case 1:cout<< "ACE" <<endl;
                   comCard = 14;
                    break;
            case 13:cout<< "KING" <<endl;
                    break;
            case 12:cout<< "QUEEN" <<endl;
                    break;
            case 11:cout<< "JACK" <<endl;
                    break;
            default:cout<< comCard <<endl;
        }

    if (userCard > comCard)
    {
       cout <<"You Win!"<<endl;
       woncards += 5;                                   //the amount of cards you win by war.
    }
    else if(userCard < comCard)
    {
       cout << "You Lose" << endl;
       woncards += 5;
    }
    else if(userCard == comCard)
    {
       cout << "WAR!" << endl;
       woncards = warFunction(woncards,userCard,turn);
       //pause();
    }

    return woncards;

}
//---------------------------------------------------------
/*
Name: pause
Description: pause game for user.
Called by: main
Calls: n/a
*/
void pause()
{
    string response;

    cout << "\nReady for the next hand?! Click <Enter> to draw!\n" <<endl;
    getline(cin, response);

    return;
}
