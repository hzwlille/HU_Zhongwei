#ifndef GROUP_H
#define GROUP_H
#include <list>
#include<memory>
#include "Film.h"
#include "Photo.h"
#include "Video.h"

class Group: public list<shared_ptr<Multimedia> >{

private:
    string m_nomDuGroupe;
public:

    //un constructeur

    Group(string nomDuGroupe):list<shared_ptr<Multimedia> >(){
        m_nomDuGroupe=nomDuGroupe;
    }

    //un accesseur qui renvoie le nom du groupe
    string getName(){
        return m_nomDuGroupe;
    }

    //une méthode d'affichage qui affiche les attributs de tous les objets de la liste
    void affiche(ostream& s){
        s<<"Le groupe: "<<m_nomDuGroupe<<":"<<endl<<endl;

        for (Group ::iterator myGroup= this->begin(); myGroup != this->end(); myGroup++){

            (*myGroup)->affiche(s);
            s<<"************************"<<endl;
        }


    }
    virtual ~Group() {
        cout<<"Détruit de l'objet "<<getName()<<endl;
    }

};



#endif // GROUP_H
