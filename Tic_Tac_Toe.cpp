#include <iostream>
#include <ctime>

void draw_board(char *space);
void player1_choice(char *space,char player1);
void player2_choice(char *space,char player2 );
bool check_winner(char *space,char player1,char player2);
bool check_draw(char *space,char player1,char player2);

int main(){
char space[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
char player1 = 'X';
char player2 = 'O';
bool running = true;



draw_board(space);

while (running){
    
player1_choice(space,player1);
draw_board(space);
if(check_winner(space, player1, player2)){
    running=false;
    break;
}
if(check_draw(space, player1, player2)){
    running=false;
    break;
}


player2_choice(space,player2);
draw_board(space);
if(check_winner(space, player1, player2)){
    running=false;
    break;
}
if(check_draw(space, player1, player2)){
    running=false;
    break;
}
}

return 0;
}

void draw_board(char *space){
std::cout<<"    |    |   "<<"\n";
std::cout<<"   "<<space[0]<<"|"<<"  "<<space[1]<<" |"<<"   "<<space[2]<<"\n";
std::cout<<"____|____|___"<<"\n";
std::cout<<"    |    |   "<<"\n";
std::cout<<"   "<<space[3]<<"|"<<"  "<<space[4]<<" |"<<"   "<<space[5]<<"\n";
std::cout<<"____|____|___"<<"\n";
std::cout<<"    |    |   "<<"\n";
std::cout<<"   "<<space[6]<<"|"<<"  "<<space[7]<<" |"<<"   "<<space[8]<<"\n";

std::cout<<"   "<<"\n";
std::cout<<"   "<<"\n";


}
void player1_choice(char *space,char player1){
int x;
std::cout<<"player 1 choose (1-9) for your turn ";
std::cin>>x;
if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout<<"player 1 choose (1-9) for your turn ";
}

while(x<=0 || x>9||space[x-1]!=' ' ){
std::cin>>x;
}
space[x-1]=player1;

}
void player2_choice(char *space,char player2){
    int x;
std::cout<<"player 2 choose (1-9) for your turn ";
std::cin>>x;
if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout<<"player 2 choose (1-9) for your turn ";
}
while(x<=0 || x>9||space[x-1]!=' ' ){
std::cin>>x;
}
space[x-1]=player2;
}
bool check_winner(char *space,char player1,char player2){
 if (space[1]!=' '&&space[0]==space[1]&&space[1]==space[2]){
   space[1]==player1?std::cout<<"PLAYER 1 WIN!!"<<"\n":std::cout<<"PLAYER 2 WIN!!"<<"\n";
 }
else if (space[3]!=' '&&space[3]==space[4]&&space[4]==space[5]){
   space[3]==player1?std::cout<<"PLAYER 1 WIN!!!!"<<"\n":std::cout<<"PLAYER 2 WIN!!"<<"\n";
 }
else if (space[6]!=' '&&space[6]==space[7]&&space[7]==space[8]){
   space[6]==player1?std::cout<<"PLAYER 1 WIN!!"<<"\n":std::cout<<"PLAYER 2 WIN!!"<<"\n";
 }
else if (space[0]!=' '&&space[0]==space[4]&&space[4]==space[8]){
   space[0]==player1?std::cout<<"PLAYER 1 WIN!!"<<"\n":std::cout<<"PLAYER 2 WIN!!"<<"\n";
 }
else if (space[2]!=' '&&space[2]==space[4]&&space[4]==space[6]){
   space[2]==player1?std::cout<<"PLAYER 1 WIN!!"<<"\n":std::cout<<"PLAYER 2 WIN!!"<<"\n";
 }
else if (space[0]!=' '&&space[0]==space[3]&&space[3]==space[6]){
   space[0]==player1?std::cout<<"PLAYER 1 WIN!!!!"<<"\n":std::cout<<"PLAYER 2 WIN!!"<<"\n";}
else if (space[1]!=' '&&space[1]==space[4]&&space[4]==space[7]){
    space[1]==player1?std::cout<<"PLAYER 1 WIN!!"<<"\n":std::cout<<"PLAYER 2 WIN!!"<<"\n";
   
 }
else if (space[2]!=' '&&space[5]==space[2]&&space[8]==space[5]){
   space[2]==player1?std::cout<<"PLAYER 1 WIN!!"<<"\n":std::cout<<"PLAYER 2 WIN!!"<<"\n";
 }
else{
    return false;
}

    
    return true;
}
bool check_draw(char *space,char player1,char player2){

  for(int i=0;i<9;i++){

    if(space[i]== ' '){
        return false;
    }
  }
  std::cout<<"IT IS A TIE";


    return true;
}



