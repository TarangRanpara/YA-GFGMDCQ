// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

class TicTocToe{
    private:
        int a[3][3];
        int p1;
        int p2;
    public:
        TicTocToe(){
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    a[i][j] = 0;
              
            p1 = 1;     p2 = 2;      
        }
        
        bool comp(int a, int b, int c, int turn){
            return ((a==b) && (b==c) && (a == turn));
        }
        
        bool tie(){
            int sum = 0;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++)
                    sum += a[i][j];
            }
            
            return (sum == 13)?true:false;
        }
        
        int check_filled(int pos){
            int row = pos/3, col = pos%3;
            while(a[row][col] != 0){
                cout<<"enter pos:"<<endl; cin>>pos;
                row = pos/3; col = pos%3;
            }
            
            return pos;
        }
        
        void move(int pos, int turn){
            int row = pos/3, col=pos%3;
            a[row][col] = turn;
        }
        
        bool check_win(int turn){
            bool row;
            bool col;
            bool diag;
            
            row = ((comp(a[0][0],a[0][1],a[0][2],turn)) || (comp(a[1][0],a[1][1],a[1][2],turn)) || (comp(a[2][0],a[2][1],a[2][2],turn)));
            
            col = ((comp(a[0][0],a[1][0],a[2][0],turn) ) || (comp(a[0][1], a[1][1],a[2][1],turn)) || (comp(a[0][2],a[1][2],a[2][2],turn)));
            
            diag = (comp(a[0][0],a[1][1],a[2][2],turn) || comp(a[0][2],a[1][1],a[2][0],turn));
            
            cout << row << " " << col << " " << diag << endl;
            
            return (row || col || diag);
        }
        
        void play(){
            int turn = p1;
            int pos;
            while(true){
                if(tie()){
                    cout<<"Tie!!"<<endl;
                    break;
                }
                cout << "Turn : " << turn << endl;
                cout<<"enter pos:"<<endl; cin>>pos;
                pos = check_filled(pos);
                move(pos, turn);
                if(check_win(turn)){
                    cout<<turn<<"wins!!";
                    break;
                }
                
                turn = (turn==p1)?p2:p1;
            }
        }
};

int main() {
    // Write C++ code here
    TicTocToe game;
    game.play();

    return 0;
}