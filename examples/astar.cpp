#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Position{
  Position() = default;
  Position(int row, int col) : r(row), c(col){}
  int r; //row
  int c; //col
  int g;

  Position* parent{nullptr};  
    
  bool operator == (const Position& other)
  {
      return (r == other.r && c == other.c);
  }
    
    
  friend std::ostream& operator << (std::ostream& o, const Position& p)
  {
    o << p.r << ", " << p.c;
    return o; 
  }
};

struct Comp
{
    Comp(Position& dest) : dest_(dest){}
    Position dest_;
    
    bool operator()(const Position& p1, const Position& p2)
    {
        const int h_p1 = std::abs(p1.r - dest_.r) + std::abs(p1.c - dest_.c);
        const int h_p2 = std::abs(p2.r - dest_.r) + std::abs(p2.c - dest_.c);

        const int f_p1 = p1.g + h_p1;
        const int f_p2 = p2.g + h_p2;

        return f_p1 > f_p2;        
    }
};

void readInput(Position& pcmanPos, Position& foodPos, Position& boardSize, std::vector<std::string>& board)
{
    std::cin >> pcmanPos.r;
    std::cin >> std::ws;
    std::cin >> pcmanPos.c;

    
    std::cin >> std::ws;
    std::cin >> foodPos.r;
    std::cin >> std::ws;
    std::cin >> foodPos.c;
    std::cin >> std::ws;
    
    std::cin >> boardSize.r;
    std::cin >> std::ws;
    std::cin >> boardSize.c;
    std::cin >> std::ws;
    
    
    for(int row = 0; row < boardSize.r; ++row)
    {
        std::string boardRow{};
        std::getline(std::cin, boardRow);
        board.push_back(boardRow);        
    }
    
}

void updateParentOrAddToList(Position& pos,
                            Position* parent,
                            std::priority_queue<Position, std::vector<Position>, Comp>& open, 
                            Position foodPos,
                            const std::vector<std::string>& board)
{
    std::priority_queue<Position, std::vector<Position>, Comp> openCopy{foodPos};
    
    if(open.empty())
    {
        pos.parent = parent;
        if(board[pos.r][pos.c]!='%')
        {
            pos.g = parent->g+1;
            openCopy.push(pos);
        }
    }
    else
    {
        bool posInOpenList = false;
        while(!open.empty())
        {
            Position inOpen = open.top();
            open.pop();
            if(inOpen == pos)
            {
                posInOpenList = true;
                //update parent conditionally
                if(inOpen.g+1 > parent->g+1)
                {
                    inOpen.parent = parent;
                    inOpen.g = parent->g + 1;
                }
            }
            openCopy.push(inOpen);
        }
        if(!posInOpenList)
        {
            pos.parent = parent;
            if(board[pos.r][pos.c]!='%')
            {
                pos.g = parent->g+1;
                openCopy.push(pos);
            }
        }
    
    }
    open = openCopy;
}
    
bool nodeInList(Position& pos, std::vector<Position*>& closed)
{
    for(Position* p : closed)
    {
        if((*p) == pos)
            return true;
    }
    return false;
}
    
Position* findFood(std::priority_queue<Position, std::vector<Position>, Comp>& open, 
             std::vector<Position*>& closed, 
             const std::vector<string>& board,
             const Position& foodPos)
{
    int nRows = board.size();
    int nCols = board[0].size();
    
    while(!open.empty())
    {
        Position* popped = new Position(open.top());
        open.pop();
        closed.push_back(popped);
        
        if((*popped) == foodPos)
            return popped;
        
        if(popped->r-1 >= 0)//up
        {
          Position up(popped->r-1, popped->c); 
          if(!nodeInList(up, closed))
              updateParentOrAddToList(up, popped, open, foodPos, board);
        }

        if(popped->c -1 >= 0)//left
        {
          Position left(popped->r, popped->c-1);
          if(!nodeInList(left, closed))
              updateParentOrAddToList(left, popped, open, foodPos, board);
        }

        if(popped->c + 1 < nCols)//right
        {
          Position right(popped->r, popped->c+1);
          if(!nodeInList(right, closed))
              updateParentOrAddToList(right, popped, open, foodPos, board);              
        }

        if(popped->r + 1 < nRows)//down
        {
          Position down(popped->r+1, popped->c);
          if(!nodeInList(down, closed))
              updateParentOrAddToList(down, popped, open, foodPos, board);              
        }
    }
    
    return nullptr;
}



int main(void) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Position pcmanPos, foodPos, boardSize;
    std::vector<string> board;
    readInput(pcmanPos, foodPos, boardSize, board);

    
    pcmanPos.g = 0; //cost of source is 0
    std::priority_queue<Position, std::vector<Position>, Comp> open{foodPos};
    open.push(pcmanPos);
   
    std::vector<Position*> closed;
    
    Position* result = findFood(open, closed, board, foodPos); 
    if(result == nullptr)
    {
        std::cout << "No path found!" << std::endl;
    }
    else
    {
        while(result != nullptr)
        {
            int row = result->r;
            int col = result->c;
            board[row][col] = '@';
            result = result->parent;
        }
    }
    
    for(const auto& row : board)
        std::cout << row << std::endl;
    
    return 0;
}