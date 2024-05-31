#include "LuisIZ.h"
#include <vector>

using namespace std;

int LuisIzaguirre::get_move(Board const& b, char turn_of)
{
    vector<int> memory(9,0);
    for (int i = 0; i < 9; ++i) // check table and update memory
        if (b[i] != ' '){
            memory[i] = -1;   
        }

    if (memory[4] == -1) { // based on what player remember: if the center is taken, then take one of the corners (if one of these is empty)
        vector<int> corners = {0, 2, 6, 8};
        for (int corner : corners) {
            if (memory[corner] == 0) {
                return corner;
            }
        }
    }

    for (int i = 0; i < 9; ++i) { // if player saw a empty space, fill it
        if (memory[i] == 0) {
            return i;
        }
    }
          
    return -1;
}