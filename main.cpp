#include <iostream>
#include <fstream>
#include "point.h"
#include "SDL_Plotter.h"
using namespace std;

void draw(char [],SDL_Plotter&,point);

int main(int argc, char** argv)
{
    SDL_Plotter g(500,500);

    while(!g.getQuit()){
        draw("UI_stocking",g,point(200,200));
        g.update();
    }

    return 0;
}

void draw(char fileName[],SDL_Plotter& g,point p){
    ifstream file(fileName);
    char value;

    if(!file){
        cout << "Error File Not Open" << endl;
    }
    int row, col;
    file >> row >> col;
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            file >> value;
            if(value == '1') {
                    g.plotPixel(p.x + c, p.y + r,0,0,0);
            }
            if(value == '2') {
                    g.plotPixel(p.x + c, p.y + r,0,255,10);
            }
        }
    }

    file.close();

}

