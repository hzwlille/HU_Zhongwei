#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
using namespace std;



class Video : public Multimedia {
private :

    unsigned int m_duree;        // La durée de la vidéo

public :
    //Constructeur de l'objet vidéo
    Video(string nom_multimedia="new_video", string pathname="/new_project/", unsigned int duree=10):Multimedia(nom_multimedia,pathname){
        m_duree=duree;
    }




    //Destructeur de l'objet vidéo
    virtual ~Video(){
    }




    //Les getters et setters

    virtual unsigned int getDuree() const {
        return m_duree;
    }

    virtual void setDuree(unsigned int duree){
        m_duree=duree;
    }


    //Affichage des données
    virtual void affiche(ostream& s) const{
        s<<"Type_de_objet: "<<endl<<"video"<<endl;
        Multimedia::affiche(s);
        s<<"\nDurée_totale: "<<m_duree<<"\n";
    }

    //Jouer l'objet vidéo
    virtual void jouer() const{
        string file=this->getPathname();
        string commande="kmplayer "+file+"&";
        system(commande.c_str());
    }
};
#endif // VIDEO_H
