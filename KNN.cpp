#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double>> posicoes(12);
double raioRange;

bool KNN(int ID){
    double x1, y1, x2, y2, x0F, y0F, x1F, y1F, tot, fin;
    
    x1 = posicoes[ID].first;
    x2 = posicoes[6].first;
    y1 = posicoes[ID].second;
    y2 = posicoes[6].second;
    x0F = fabs(x2-x1);
    y0F = fabs(y2-y1);
    x1F = x0F*x0F;
    y1F = y0F*y0F;
    tot = x1F+y1F;
    fin = sqrt(tot);

    /*cout<<x1<<" - x1 || y1 - "<<y1<<endl;
    cout<<x2<<" - x2 || y2 - "<<y2<<endl;
    cout<<x0F<<" - x0F || y0F - "<<y0F<<endl;
    cout<<x1F<<" - x1F || y1F - "<<y1F<<endl;
    cout<<tot<<" - tot"<<endl;*/

    cout<<fin<<" - Distância do centro do Robô de ID "<<ID<<" até o centro do 'Range'"<<endl;
    cout<<raioRange+14<<" - Raio do Robô de ID "<<ID<<" somado ao raio do 'Range'"<<endl;
    cout<<endl;

    if(fin < raioRange+14){
        return true;
    }else{
        return false;
    }
}

int main(){

    sf::RenderWindow campo(sf::VideoMode(900,600), "KNN - K-Nearest Neighbors");

    sf::RectangleShape background(sf::Vector2f(900,600));
    background.setFillColor(sf::Color(0,98,51));
    background.setPosition(0,0);

    sf::Vertex fundoEsq[] = {
        sf::Vertex(sf::Vector2f(20, 25)),
        sf::Vertex(sf::Vector2f(20, 575))
    };

    sf::Vertex fundoDir[] = {
        sf::Vertex(sf::Vector2f(880, 25)),
        sf::Vertex(sf::Vector2f(880, 575))
    };

    sf::Vertex lateralCim[] = {
        sf::Vertex(sf::Vector2f(19, 25)),
        sf::Vertex(sf::Vector2f(880, 25))
    };
    
    sf::Vertex lateralBaix[] = {
        sf::Vertex(sf::Vector2f(19, 575)),
        sf::Vertex(sf::Vector2f(880, 575))
    };

    sf::Vertex meioCamp[] = {
        sf::Vertex(sf::Vector2f(450, 25)),
        sf::Vertex(sf::Vector2f(450, 575))
    };
    
    sf::CircleShape centro(48);
    centro.setOutlineThickness(1);
    centro.setOutlineColor(sf::Color(255, 255, 255));
    centro.setFillColor(sf::Color::Transparent);
    centro.setOrigin(-402,-252);

    sf::Vertex golCimE[] = {
        sf::Vertex(sf::Vector2f(20, 233)),
        sf::Vertex(sf::Vector2f(77, 233))
    };

    sf::Vertex golCimD[] = {
        sf::Vertex(sf::Vector2f(20, 363)),
        sf::Vertex(sf::Vector2f(77, 363))
    };

    sf::Vertex golCimB[] = {
        sf::Vertex(sf::Vector2f(77, 233)),
        sf::Vertex(sf::Vector2f(77, 363))
    };

    sf::Vertex golBaiE[] = {
        sf::Vertex(sf::Vector2f(823, 233)),
        sf::Vertex(sf::Vector2f(880, 233))
    };

    sf::Vertex golBaiD[] = {
        sf::Vertex(sf::Vector2f(823, 363)),
        sf::Vertex(sf::Vector2f(880, 363))
    };

    sf::Vertex golBaiB[] = {
        sf::Vertex(sf::Vector2f(823, 233)),
        sf::Vertex(sf::Vector2f(823, 363))
    };

    sf::CircleShape bola(8);
    bola.setFillColor(sf::Color::Red);
    bola.setPosition(443, 293);
    double bX = 443, bY = 293;

    sf::CircleShape range(8);
    range.setPointCount(100);
    range.setFillColor(sf::Color::Transparent);
    range.setOutlineThickness(2);
    range.setOutlineColor(sf::Color(0, 0, 0));
    range.setPosition(443, 293);

    sf::Font asman;
    asman.loadFromFile("ASMAN.TTF");

    sf::Text r1T("1", asman);
    r1T.setCharacterSize(30);
    r1T.setFillColor(sf::Color::Black);

    sf::Text r2T("2", asman);
    r2T.setCharacterSize(30);
    r2T.setFillColor(sf::Color::Black);

    sf::Text r3T("3", asman);
    r3T.setCharacterSize(30);
    r3T.setFillColor(sf::Color::Black);

    sf::Text r1M("1", asman);
    r1M.setCharacterSize(30);
    r1M.setFillColor(sf::Color::Black);

    sf::Text r2M("2", asman);
    r2M.setCharacterSize(30);
    r2M.setFillColor(sf::Color::Black);

    sf::Text r3M("3", asman);
    r3M.setCharacterSize(30);
    r3M.setFillColor(sf::Color::Black);

    sf::CircleShape robo1T(14);
    robo1T.setFillColor(sf::Color::White);
    robo1T.setPosition(338, 286);
    robo1T.setOutlineThickness(1);
    robo1T.setOutlineColor(sf::Color(0, 0, 0));
    double x1T = 338, y1T = 286;
    int id1T = 0;

    sf::CircleShape robo2T(14);
    robo2T.setFillColor(sf::Color::White);
    robo2T.setPosition(270, 200);
    robo2T.setOutlineThickness(1);
    robo2T.setOutlineColor(sf::Color(0, 0, 0));
    double x2T = 270, y2T = 200;
    int id2T = 1;

    sf::CircleShape robo3T(14);
    robo3T.setFillColor(sf::Color::White);
    robo3T.setPosition(270, 372);
    robo3T.setOutlineThickness(1);
    robo3T.setOutlineColor(sf::Color(0, 0, 0));
    double x3T = 270, y3T = 372;
    int id3T = 2;

    sf::CircleShape robo1M(14);
    robo1M.setFillColor(sf::Color::Green);
    robo1M.setPosition(530, 286);
    robo1M.setOutlineThickness(1);
    robo1M.setOutlineColor(sf::Color(0, 0, 0));
    double x1M = 530, y1M = 286; 
    int id1M = 3;

    sf::CircleShape robo2M(14);
    robo2M.setFillColor(sf::Color::Green);
    robo2M.setPosition(598, 200);
    robo2M.setOutlineThickness(1);
    robo2M.setOutlineColor(sf::Color(0, 0, 0));
    double x2M = 598, y2M = 200; 
    int id2M = 4;

    sf::CircleShape robo3M(14);
    robo3M.setFillColor(sf::Color::Green);
    robo3M.setPosition(598, 372);
    robo3M.setOutlineThickness(1);
    robo3M.setOutlineColor(sf::Color(0, 0, 0));
    double x3M = 598, y3M = 372; 
    int id3M = 5;

    posicoes[id1T].first = x1T; 
    posicoes[id1T].second = y1T;
    posicoes[id2T].first = x2T;
    posicoes[id2T].second = y2T;
    posicoes[id3T].first = x3T;
    posicoes[id3T].second = y3T; 
    posicoes[id1M].first = x1M;
    posicoes[id1M].second = y1M;
    posicoes[id2M].first = x2M;
    posicoes[id2M].second = y2M;
    posicoes[id3M].first = x3M;
    posicoes[id3M].second = y3M;
    
    raioRange = range.getRadius();

    double mouX, mouY;
    int flag, cont = 0;
    
    while(campo.isOpen()){
        sf::Event evento;
        while(campo.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                cout<<"Programa encerrado com sucesso"<<endl<<endl;
                campo.close();
            }
            if(evento.type == sf::Event::MouseMoved){
                mouX = sf::Mouse::getPosition().x;
                mouY = sf::Mouse::getPosition().y;
            }
            if(evento.type == sf::Event::MouseButtonPressed){
                if(evento.mouseButton.button == sf::Mouse::Left){
                    bola.setPosition(sf::Mouse::getPosition().x-37, sf::Mouse::getPosition().y-93);
                    range.setPosition(bola.getPosition().x-range.getRadius()+8, bola.getPosition().y-range.getRadius()+8);
                }
            }
            if(evento.type == sf::Event::MouseWheelScrolled){
                if(evento.mouseWheelScroll.delta > 0){
                    if(range.getRadius() <= 288){
                        range.setRadius(range.getRadius()+3);
                        range.setPosition(range.getPosition().x-3, range.getPosition().y-3);
                    }
                }
                else if(evento.mouseWheelScroll.delta < 0){
                    if(range.getRadius() >= 9){
                        range.setRadius(range.getRadius()-3);
                        range.setPosition(range.getPosition().x+3, range.getPosition().y+3);
                    }
                }
            }
        }
        bX = bola.getPosition().x;
        bY = bola.getPosition().y;
        posicoes[6].first = bX;
        posicoes[6].second = bY;
        posicoes[7].first = range.getPosition().x;
        posicoes[7].second = range.getPosition().y;
        raioRange = range.getRadius();

        /*cout<<raioRange<<" - Raio do 'Range'"<<endl;
        cout<<posicoes[7].first<<" - X || "<<posicoes[7].second<<" - Y"<<endl;*/

        campo.clear(sf::Color::Black);
        
        campo.draw(background);

        campo.draw(fundoEsq, 2, sf::Lines);
        campo.draw(fundoDir, 2, sf::Lines);

        campo.draw(lateralCim, 2, sf::Lines);
        campo.draw(lateralBaix, 2, sf::Lines);

        campo.draw(meioCamp, 2, sf::Lines);

        campo.draw(centro);
        
        campo.draw(golCimE, 2, sf::Lines);
        campo.draw(golCimD, 2, sf::Lines);
        campo.draw(golCimB, 2, sf::Lines);
        campo.draw(golBaiE, 2, sf::Lines);
        campo.draw(golBaiD, 2, sf::Lines);
        campo.draw(golBaiB, 2, sf::Lines);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            x1T += 0.5;
            posicoes[id1T].first = x1T;
            robo1T.setPosition(x1T, y1T);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            x1T -= 0.5;
            posicoes[id1T].first = x1T;
            robo1T.setPosition(x1T, y1T);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            y1T += 0.5;
            posicoes[id1T].second = y1T;
            robo1T.setPosition(x1T, y1T);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            y1T -= 0.5;
            posicoes[id1T].second = y1T;
            robo1T.setPosition(x1T, y1T);            
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
            cont++;
            if(cont <= 500){
                flag = 1;
            }else if((cont > 500) && (cont <= 1000)){
                flag = 0;
            }else if(cont == 1001){
                cont = 0;
            }

            if(flag == 1){
                x2T += 0.2;
                posicoes[id2T].first = x2T;
                robo2T.setPosition(x2T, y2T);
                y3T += 0.2;
                posicoes[id3T].second = y3T;
                robo3T.setPosition(x3T, y3T);    
                y2M -= 0.2;
                posicoes[id2M].second = y2M;
                robo2M.setPosition(x2M, y2M);
                x3M -= 0.2;
                posicoes[id3M].first = x3M;
                robo3M.setPosition(x3M, y3M);
            }else{
                x2T -= 0.2;
                posicoes[id2T].first = x2T;
                robo2T.setPosition(x2T, y2T); 
                y3T -= 0.2;
                posicoes[id3T].second = y3T;
                robo3T.setPosition(x3T, y3T);    
                y2M += 0.2;
                posicoes[id2M].second = y2M;
                robo2M.setPosition(x2M, y2M); 
                x3M += 0.2;
                posicoes[id3M].first = x3M;
                robo3M.setPosition(x3M, y3M);  
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            x1M += 0.5;
            posicoes[id1M].first = x1M;
            robo1M.setPosition(x1M, y1M);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            x1M -= 0.5;
            posicoes[id1M].first = x1M;
            robo1M.setPosition(x1M, y1M);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            y1M += 0.5;
            posicoes[id1M].second = y1M;
            robo1M.setPosition(x1M, y1M);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            y1M -= 0.5;
            posicoes[id1M].second = y1M;
            robo1M.setPosition(x1M, y1M);            
        }

        if(KNN(id1T)){
            sf::Vertex retaCentro1T[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(bX, bY+8))
            };
            campo.draw(retaCentro1T, 2, sf::Lines);
        }
        
        if(KNN(id2T)){
            sf::Vertex retaCentro2T[] = {
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14)),
                sf::Vertex(sf::Vector2f(bX, bY+8))
            };
            campo.draw(retaCentro2T, 2, sf::Lines);
        }

        if(KNN(id3T)){
            sf::Vertex retaCentro3T[] = {
                sf::Vertex(sf::Vector2f(posicoes[id3T].first+28, posicoes[id3T].second+14)),
                sf::Vertex(sf::Vector2f(bX, bY+8))
            };
            campo.draw(retaCentro3T, 2, sf::Lines);
        }

        if(KNN(id1M)){
            sf::Vertex retaCentro1M[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14)),
                sf::Vertex(sf::Vector2f(bX+16, bY+8))
            };
            campo.draw(retaCentro1M, 2, sf::Lines);
        }

        if(KNN(id2M)){
            sf::Vertex retaCentro2M[] = {
                sf::Vertex(sf::Vector2f(posicoes[id2M].first, posicoes[id2M].second+14)),
                sf::Vertex(sf::Vector2f(bX+16, bY+8))
            };
            campo.draw(retaCentro2M, 2, sf::Lines);
        }

        if(KNN(id3M)){
            sf::Vertex retaCentro3M[] = {
                sf::Vertex(sf::Vector2f(posicoes[id3M].first, posicoes[id3M].second+14)),
                sf::Vertex(sf::Vector2f(bX+16, bY+8))
            };
            campo.draw(retaCentro3M, 2, sf::Lines);
        }
    
        campo.draw(robo1T);
        campo.draw(robo2T);
        campo.draw(robo3T);
        campo.draw(robo1M);
        campo.draw(robo2M);
        campo.draw(robo3M);

        r1T.setPosition(robo1T.getPosition().x+10, robo1T.getPosition().y-5);
        campo.draw(r1T);
        r2T.setPosition(robo2T.getPosition().x+8, robo2T.getPosition().y-5);
        campo.draw(r2T);   
        r3T.setPosition(robo3T.getPosition().x+8, robo3T.getPosition().y-5);
        campo.draw(r3T);   
        r1M.setPosition(robo1M.getPosition().x+10, robo1M.getPosition().y-5);
        campo.draw(r1M);
        r2M.setPosition(robo2M.getPosition().x+8, robo2M.getPosition().y-5);
        campo.draw(r2M);
        r3M.setPosition(robo3M.getPosition().x+8, robo3M.getPosition().y-5);
        campo.draw(r3M);

        campo.draw(bola);
        campo.draw(range);

        campo.display();
    }

    return 0;
}