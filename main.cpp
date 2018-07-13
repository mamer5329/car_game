

#include <SFML/Window.hpp>

#include "Menu.h"
#include "Numery.h"
#include "WindowGame.h"
#include "instrukcja.h"

using namespace sf;





int main() {


    //Menu menu(window.getSize().x,window.getSize().y);




    int punkty;
    int numer=1;

    //WindowGame windowGame(700, 800, &numer,&punkty);
    //windowGame.run();
    //Instrukcja instrukcja(700, 800,&numer);
    //instrukcja.run();

    //KoniecGry koniecGry(700,800,&numer, &punkty);
    //koniecGry.run();

    while(numer!=0)
    {
        if(numer==1)
        {
            Menu menu(700, 800,&numer);
            menu.run();
        }

        if(numer==2)
        {
            WindowGame windowGame(700, 800, &numer,&punkty);
            windowGame.run();
        }
        if(numer==3)
        {
            KoniecGry koniecGry(700,800,&numer, &punkty);
            koniecGry.run();
        }
        if(numer==4)
        {
            Instrukcja instrukcja(700, 800,&numer);
            instrukcja.run();
        }

    }

    return 0;
}