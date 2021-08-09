#include <bits/stdc++.h>
using namespace std;
//Tubes
const int MAX = 12;
const int tube_max=4;
const int n=4;
int i;
int j;
int flag,sz;
stack<char> tube_1;
stack<char> tube_2;
stack<char> tube_3;
stack<char> tube_4;
stack<char> tube_5;

char balls[MAX] = {'R','R','B','Y','B','R','R' ,'Y','B','Y','Y','B'};

//----------------------------------------------
char set_Colors()
{
    int i;
    for(i=0;i<n;i++){
        tube_1.push(balls[i%MAX]);
    }
    for(i=n;i<2*n;i++)
    {
        tube_2.push(balls[i%MAX]);
    }
    for(i=2*n;i<3*n;i++)
    {
        tube_3.push(balls[i%MAX]);
    }
}

//----------------------------------------------

void PrintStack(stack<char> s)
{
    // If stack is empty
    if (s.empty())
        return;

// Extract top of the stack
    char x = s.top();

    // Pop the top element
    s.pop();

    // Print the current top
    // of the stack i.e., x
    cout << x << ' ';

    // Proceed to print
// remaining stack
    PrintStack(s);

    // Push the element back
    s.push(x);
}

//----------------------------------------------

void print_tubes()
{
      cout<< "Tube 1: ";
      PrintStack(tube_1);
      cout << endl << "Tube 2: ";
      PrintStack(tube_2);
      cout << endl << "Tube 3: ";
      PrintStack(tube_3);
      cout << endl << "Tube 4: ";
      PrintStack(tube_4);
      cout << endl << "Tube 5: ";
      PrintStack(tube_5);
      cout << endl;
}

//----------------------------------------------

bool Check_Move_Availability(int i, int j)
{
    if((i<0 || i>5 || j<0 || j>5) || i==j)
        return false;
    if(i==1 && j==2)
    {
        if(tube_2.empty() || (!tube_1.empty()&&tube_1.top() == tube_2.top() && tube_2.size() < tube_max))
            return true;
    }
    else if(i==1 && j==3)
    {
        if(tube_3.empty() || (!tube_1.empty()&&tube_1.top() == tube_3.top() && tube_3.size() < tube_max))
            return true;
    }

    else if(i==1 && j==4)
    {
        if(tube_4.empty() || (!tube_1.empty()&&tube_1.top() == tube_4.top() && tube_4.size() < tube_max) )
            return true;
    }

    else if(i==1 && j==5)
    {
        if(tube_5.empty() || (!tube_1.empty()&&tube_1.top() == tube_5.top() && tube_5.size() < tube_max))
            return true;
    }

    //-----------------------------------------------

    else if(i==2 && j==1)
    {
        if(tube_1.empty() || (!tube_2.empty()&&tube_2.top() == tube_1.top() && tube_1.size() < tube_max))
            return true;
    }
    else if(i==2 && j==3)
    {
        if(tube_3.empty() || (!tube_2.empty()&&tube_2.top() == tube_3.top() && tube_3.size() < tube_max) )
            return true;
    }

    else if(i==2 && j==4)
    {
        if(tube_4.empty() || (!tube_2.empty()&&tube_2.top() == tube_4.top() && tube_4.size() < tube_max))
            return true;
    }

    else if(i==2 && j==5)
    {
        if(tube_5.empty() || (!tube_2.empty()&&tube_2.top() == tube_5.top() && tube_5.size() < tube_max))
            return true;
    }

     //-----------------------------------------------

    else if(i==3 && j==1)
    {
        if(tube_1.empty() || ( !tube_3.empty()&&tube_3.top() == tube_1.top() && tube_1.size() < tube_max))
            return true;
    }
    else if(i==3 && j==2)
    {
        if(tube_2.empty() || (!tube_3.empty()&& tube_3.top() == tube_2.top()&& tube_2.size() < tube_max))
            return true;
    }

    else if(i==3 && j==4)
    {
        if(tube_4.empty() || (!tube_3.empty()&&tube_3.top() == tube_4.top() && tube_4.size() < tube_max))
           {
            return true;
           }
    }

    else if(i==3 && j==5)
    {
        if(tube_5.empty() || (!tube_3.empty()&&tube_3.top() == tube_5.top() && tube_5.size() < tube_max))
            return true;
    }

     //-----------------------------------------------

    else if(i==4 && j==1)
    {
        if(tube_1.empty() || (!tube_4.empty()&&tube_4.top() == tube_1.top()  && tube_1.size() < tube_max) )
            return true;
    }
    else if(i==4 && j==2)
    {
        if(tube_2.empty() || (!tube_4.empty()&&tube_4.top() == tube_2.top()  && tube_2.size() < tube_max))
            return true;
    }

    else if(i==4 && j==3)
    {
        if(tube_3.empty() || (!tube_4.empty()&&tube_4.top() == tube_3.top()  && tube_3.size() < tube_max) )
            return true;
    }

    else if(i==4 && j==5)
    {
        if(tube_5.empty() || (!tube_4.empty()&&tube_4.top() == tube_5.top()  && tube_5.size()< tube_max))
            return true;
    }

    //-----------------------------------------------

    else if(i==5 && j==1)
    {
        if(tube_1.empty() || (!tube_5.empty()&&tube_5.top() == tube_1.top()  && tube_1.size() < tube_max))
            return true;
    }
    else if(i==5 && j==2)
    {
        if(tube_2.empty() || (!tube_5.empty()&&tube_5.top() == tube_2.top()  && tube_2.size() < tube_max) )
            return true;
    }

    else if(i==5 && j==3)
    {
        if(tube_3.empty() || (!tube_5.empty()&&tube_5.top() == tube_3.top()  && tube_3.size() < tube_max))
            return true;
    }

    else if(i==5 && j==4)
    {
        if(tube_4.empty() || (!tube_5.empty()&&tube_5.top() == tube_4.top()  && tube_4.size() < tube_max))
            return true;
    }

    return false;
}

//----------------------------------------------

void Move_Ball(int i, int j)
{

    if(i==1 && j==2)
    {
        tube_2.push(tube_1.top());
        tube_1.pop();
    }

    else if(i==1 && j==3)
    {
        tube_3.push(tube_1.top());
        tube_1.pop();
    }

    else if(i==1 && j==4)
    {
        tube_4.push(tube_1.top());
        tube_1.pop();
    }

    else if(i==1 && j==5)
    {
        tube_5.push(tube_1.top());
        tube_1.pop();
    }

    //-----------------------------------------------

    else if(i==2 && j==1)
    {
        tube_1.push(tube_2.top());
        tube_2.pop();
    }
    else if(i==2 && j==3)
    {
        tube_3.push(tube_2.top());
        tube_2.pop();
    }

    else if(i==2 && j==4)
    {
        tube_4.push(tube_2.top());
        tube_2.pop();
    }

    else if(i==2 && j==5)
    {
        tube_5.push(tube_2.top());
        tube_2.pop();
    }

     //-----------------------------------------------

    else if(i==3 && j==1)
    {
       tube_1.push(tube_3.top());
       tube_3.pop();
    }
    else if(i==3 && j==2)
    {
        tube_2.push(tube_3.top());
        tube_3.pop();    }

    else if(i==3 && j==4)
    {
        tube_4.push(tube_3.top());
        tube_3.pop();
    }

    else if(i==3 && j==5)
    {
        tube_5.push(tube_3.top());
        tube_3.pop();
    }

     //-----------------------------------------------

    else if(i==4 && j==1)
    {
        tube_1.push(tube_4.top());
        tube_4.pop();
    }
    else if(i==4 && j==2)
    {
        tube_2.push(tube_4.top());
        tube_4.pop();
    }

    else if(i==4 && j==3)
    {
        tube_3.push(tube_4.top());
        tube_4.pop();
    }

    else if(i==4 && j==5)
    {
        tube_5.push(tube_4.top());
        tube_4.pop();
    }

    //-----------------------------------------------

    else if(i==5 && j==1)
    {
        tube_1.push(tube_5.top());
        tube_5.pop();
    }
    else if(i==5 && j==2)
    {
        tube_2.push(tube_5.top());
        tube_5.pop();
    }

    else if(i==5 && j==3)
    {
        tube_3.push(tube_5.top());
        tube_5.pop();
    }

    else if(i==5 && j==4)
    {
        tube_4.push(tube_5.top());
        tube_5.pop();
    }

}

//----------------------------------------------
void check_if_elements_same(stack<char> s,char c)
{
    if(s.empty())
        return ;
    char temp = s.top();
    s.pop();
    if(temp != c)
       flag=1;
    else sz+=1;
    check_if_elements_same(s,c);
    s.push(temp);
}
bool Check_Win()
{
    flag =0; sz=0;
 if(!tube_1.empty())
    check_if_elements_same(tube_1,tube_1.top());
    if(sz>0&&sz<n)return false;
 sz=0;
 if(!tube_2.empty())
    check_if_elements_same(tube_2,tube_2.top());
    if(sz>0&&sz<n)return false;
 sz=0;
  if(!tube_3.empty())
    check_if_elements_same(tube_3,tube_3.top());
    if(sz>0&&sz<n)return false;
  sz=0;
  if(!tube_4.empty())
    check_if_elements_same(tube_4,tube_4.top());
    if(sz>0&&sz<n)return false;
 sz=0;
  if(!tube_5.empty())check_if_elements_same(tube_5,tube_5.top());
  if(sz>0&&sz<n)return false;
  if(flag==0)
        return true;
    else
    {
        return false;
    }
}

//----------------------------------------------

void read_input(int &i, int &j) {
	cout << "Enter the number of tube to move top ball from and the number of tube to move ball to it : ";
	 cin >> i >> j;
	while(! Check_Move_Availability( i, j))
	cin >> i >> j;
	/*while (!Check_Move_Availability(i, j)) {
		cout << "Invalid Move Enter Valid one! ";
		cout << "Enter the number of tube to move top ball from and the number of tube to move ball to it : ";
	    cin >> i>> j;
	}*/

}


//----------------------------------------------
void Delete_Stack_elements(stack<char>& s)
{
    if(s.empty())
        return;
    while(!s.empty())
    {
        s.pop();
    }
}


//----------------------------------------------
void Clear_Tubes()
{
    Delete_Stack_elements(tube_1);
    Delete_Stack_elements(tube_2);
    Delete_Stack_elements(tube_3);
    Delete_Stack_elements(tube_4);
    Delete_Stack_elements(tube_5);

}


//MAIN FUNCTION
void play_game() {
	cout << "Ball Sort Puzzle Game!\n";
	cout << "Welcome...\n";
	cout << "============================\n";
	while (true) {
		//Prints the tubes
		print_tubes();
		//Read an input from the player
        read_input(i,j);
        //cout << "before input "<< i << ","<<j<<endl;
        //read_input(i,j);
		//Move Balls
        //cout << "after input "<< i << ","<<j<<endl;
        //cout << "before move "<< i << ","<<j<<endl;
		Move_Ball(i,j);
		 //cout << "after move "<< i << ","<<j<<endl;

            //cout << "after second "<< i << ","<<j<<endl;
		//Check if the grid has a win state
        if (Check_Win()) {
			//Prints the grid
			print_tubes();
			//Announcement of the final statement
			cout << "Congrats, You won!\n";
			break;
		}
		//cout << "after if "<< i << ","<<j<<endl;
	}
}

int main()

{

    while (true) {
            Clear_Tubes();
            set_Colors();
            play_game();
            char c;
            cout << "Play Again [Y/N] ";
            cin >> c;
            if (c != 'y' && c != 'Y')
                break;
        }
    return 0;
}
