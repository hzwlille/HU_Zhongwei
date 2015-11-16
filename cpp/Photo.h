#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
using namespace std;



class Photo : public Multimedia {
private :

    float m_latitude;        // La latitude la photo
    float m_longitude;       // La longitude la photo

public :
    //Constructeur de l'objet vidéo
    Photo(string nom_multimedia="new_photo", string pathname="/new_project/", float latitude=100, float longitude=100):Multimedia(nom_multimedia,pathname){

        m_latitude=latitude;
        m_longitude=longitude;
    }




    //Destructeur de l'objet vidéo
    virtual ~Photo() {
        cout<<"Détruit de l'objet "<<getNom_multimedia()<<endl;
    }




    //Les getters et setters

    virtual unsigned int getLatitude() const {
        return m_latitude;
    }
    virtual unsigned int getLongitude() const {
        return m_longitude;
    }

    virtual void setLatitude(float latitude){
        m_latitude=latitude;
    }
    virtual void setLongitude(float longitude){
        m_longitude=longitude;
    }



    //Affichage des données
    virtual void affiche(ostream& s) const{
        s<<"Type_de_objet: "<<endl<<"photo"<<endl;
        Multimedia::affiche(s);
        s << "\nLatitude: "<<m_latitude<<"\nLongitude "<<m_longitude<<"\n";
    }



    //Jouer l'objet photo
    virtual void jouer() const{
        string file=this->getPathname();
        string commande="display "+file+"&";
        system(commande.c_str());
    }
    //Sérialisation




};
#endif // PHOTO_H
