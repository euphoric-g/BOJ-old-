#include <iostream>
#include <algorithm>

#define BOARD_LENGTH 10

#define NOT_FOUND -1

#define RIGHT 0
#define DOWN 1

#define TYPE_SINGLE 1
#define TYPE_WIDTH 2
#define TYPE_HEIGHT 3

class Pos {
    public:
    int x, y;
    Pos() {}
    Pos(int a, int b) { x = a; y = b; }
};

class Cell {
    public:
    Pos position;
    bool used;
    bool right_end;
    bool down_end;
    Cell *ptr_right;
    Cell *ptr_down;
    Cell() {}
    Cell(bool b) { used = b; }
    Cell(bool init, bool rend, bool dend) {
        used = init; right_end = rend; down_end = dend;
    }
    void set_pos(int x, int y) { position = Pos(x, y); }
    void set_ptr(Cell *pr, Cell *pd) {
        ptr_right = pr; ptr_down = pd;
    }
    bool move_check(int dir) {
        Cell *target;
        bool end;
        switch(dir) {
            case RIGHT:
            target = ptr_right;
            end = right_end;
            break;
            case DOWN:
            target = ptr_down;
            end = down_end;
            break;
        }
        if(target->used || end) return false;
        else return true;
    }
    Cell *move(int dir) {
        Cell *target;
        bool end;
        switch(dir) {
            case RIGHT:
            target = ptr_right;
            end = right_end;
            break;
            case DOWN:
            target = ptr_down;
            end = down_end;
            break;
        }
        if(target->used || end) return this;
        else {
            clear();
            target->set();
            return target;
        }
    }
    void clear() { used = false; }
    void set() { used = true; }
    void rev() { used = !used; }
};

class Board {
    public:
    int score;
    Cell grid[BOARD_LENGTH][BOARD_LENGTH];
    Board() {
        score = 0;
        for(int i=0; i<BOARD_LENGTH; i++) {
            for(int j=0; j<BOARD_LENGTH; j++) {
                grid[i][j] = Cell(false, (j == BOARD_LENGTH - 1), (i == BOARD_LENGTH - 1));
                grid[i][j].set_pos(i, j);
                if(i != BOARD_LENGTH - 1) {
                    grid[i][j].ptr_down = &grid[i+1][j];
                }
                if(j != BOARD_LENGTH - 1) {
                    grid[i][j].ptr_right = &grid[i][j+1];
                }
            }
        }
    }
    int blocks() {
        int cnt = 0;
        for(int i=6; i<10; i++) {
            for(int j=0; j<4; j++) {
                if(grid[i][j].used) cnt++;
                if(grid[j][i].used) cnt++;
            }
        }
        return cnt;
    }
    void print() {
        for(int i=0; i<BOARD_LENGTH; i++) {
            for(int j=0; j<BOARD_LENGTH; j++) {
                if(i>3 && j>3) {
                    std::cout << " ";
                } else {
                    if(grid[i][j].used == true) {
                        std::cout << "O";
                    } else {
                        std::cout << "X";
                    }
                }
            }
            std::cout << std::endl;
        }
    }
    int check_upperband(int dir) {
        // dir ????????? 5, 6??? ??? ??? ??? ?????? ?????? ????????? ????????? ??????
        int cnt = 0;
        if(dir == DOWN) {
            for(int i=4; i<6; i++) {
                bool ret = false;
                for(int j=0; j<4; j++) {
                    ret = (grid[i][j].used == true) ? true : ret;
                }
                if(ret) cnt++;
            }
        }
        if(dir == RIGHT) {
            for(int i=4; i<6; i++) {
                bool ret = false;
                for(int j=0; j<3; j++) {
                    ret = (grid[j][i].used == true) ? true : ret;
                }
                if(ret) cnt++;
            }
        }
        return cnt;
    }
    void clear_band(int dir, int target) {
        // dir ????????? target ???, ??? ??????
        if(dir == DOWN) {
            for(int i=0; i<4; i++) {
                grid[target][i].clear();
            }
        }
        if(dir == RIGHT) {
            for(int i=0; i<4; i++) {
                grid[i][target].clear();
            }
        }
    }
    void clear_band_upper(int dir, int target) {
        // dir ????????? target ???, ?????? dir ????????? ?????? ????????? ??????
        for(int i=9; i>=target; i--) {
            clear_band(dir, i);
        }
    }
    void shift(int dir, int target, int val) {
        // dir ????????? target ?????? ??? ?????? ?????? ???????????? dir ???????????? val ??? ?????? ??????
        if(dir == DOWN) {
            for(int i=target; i>=4; i--) {
                for(int j=0; j<4; j++) {
                    Cell *og = &grid[i][j];
                    if(og->used) for(int k=0; k<val; k++) og = og->move(dir);
                }
            }
        }
        if(dir == RIGHT) {
            for(int i=target; i>=4; i--) {
                for(int j=0; j<4; j++) {
                    Cell *og = &grid[j][i];
                    if(og->used) for(int k=0; k<val; k++) og = og->move(dir);
                }
            }
        }
    }
    void band_check() {
        // RIGHT, DOWN ???????????? ????????? ?????? ?????? ??? ?????? ?????? ???????????? ????????? ??? ???, ????????? ?????? ?????? ??????
        // ????????? ?????? ?????? ????????? ??? 5, 6????????? ????????????.
        for(int i=0; i<2; i++) {
            int complete;
            while((complete = check_complete(i)) != NOT_FOUND) {
                // i ????????? complete ????????? ?????? ??????
                // ?????? ?????? ???????????? ?????? ????????? i ???????????? ?????? shift
                clear_band(i, complete);
                shift(i, complete, 1);
                score++;
            }
        }
        for(int i=0; i<2; i++) {
            // RIGHT, DOWN ?????? 5 6?????? ??????
            int temp = check_upperband(i);
            if(temp > 0) {
                clear_band_upper(i, 10-temp);
                shift(i, 10-temp, temp);
            }
        }
    }
    int check_complete(int dir) {
        // ?????? ???????????? ????????? ??? ????????? ?????? ????????? ????????? ????????? ???, ????????? ??????
        // ?????? ???????????? ????????? ?????? ????????? NOT_FOUND??? ??????
        if(dir == RIGHT) {
            for(int i=9; i>=6; i--) {
                bool f = true;
                for(int j=0; j<4; j++) {
                    f = (grid[j][i].used == true) ? f : false;
                }
                if(f) return i;
            }
        }
        if(dir == DOWN) {
            for(int i=9; i>=6; i--) {
                bool f = true;
                for(int j=0; j<4; j++) {
                    f = (grid[i][j].used == true) ? f : false;
                }
                if(f) return i;
            }
        }
        return NOT_FOUND;
    }
    void add(int type, int x, int y) {
        if(type == TYPE_SINGLE) {
            grid[x][y].set();
            Cell *og = &grid[x][y];
            while(1) {
                Cell *ptr = og->move(RIGHT);
                if(og == ptr) {
                    break;
                }
                og = ptr;
            }
            grid[x][y].set();
            og = &grid[x][y];
            while(1) {
                Cell *ptr = og->move(DOWN);
                if(og == ptr) break;
                og = ptr;
            }
        }
        if(type == TYPE_WIDTH) {
            grid[x][y].set();
            grid[x][y+1].set();
            Cell *og = &grid[x][y+1];
            while(1) {
                Cell *ptr = og->move(RIGHT);
                if(og == ptr) break;
                og = ptr;
            }
            og = &grid[x][y];
            while(1) {
                Cell *ptr = og->move(RIGHT);
                if(og == ptr) break;
                og = ptr;
            }
            // DOWN DIR
            grid[x][y].set();
            grid[x][y+1].set();
            Cell *left_og = &grid[x][y];
            Cell *right_og = &grid[x][y+1];
            while(1) {
                if(left_og->move_check(DOWN) && right_og->move_check(DOWN)) {
                    left_og = left_og->move(DOWN);
                    right_og = right_og->move(DOWN);
                } else break;
            }
        }
        if(type == TYPE_HEIGHT) {
            grid[x][y].set();
            grid[x+1][y].set();
            Cell *og = &grid[x+1][y];
            while(1) {
                Cell *ptr = og->move(DOWN);
                if(og == ptr) break;
                og = ptr;
            }
            og = &grid[x][y];
            while(1) {
                Cell *ptr = og->move(DOWN);
                if(og == ptr) break;
                og = ptr;
            }
            grid[x][y].set();
            grid[x+1][y].set();
            // RIGHT DIR
            Cell *up_og = &grid[x][y];
            Cell *down_og = &grid[x+1][y];
            while(1) {
                if(up_og->move_check(RIGHT) && down_og->move_check(RIGHT)) {
                    up_og = up_og->move(RIGHT);
                    down_og = down_og->move(RIGHT);
                } else break;
            }
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    Board b = Board();
    while(n-->0) {
        int t, x, y;
        std::cin >> t >> x >> y;
        b.add(t, x, y);
        b.band_check();
        // b.print();
    }

    std::cout << b.score << std::endl;
    std::cout << b.blocks() << std::endl;
}