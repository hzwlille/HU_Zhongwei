#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <map>
#include <fstream>
#include <regex>
#include <cstring>
#include "Multimedia.h"
#include "Film.h"
#include "Photo.h"
#include "Video.h"
#include "Group.h"
using namespace std;

typedef map<string, shared_ptr<Multimedia> > MultimediaMap;
typedef map<string, shared_ptr<Group> > GroupMap;
class Administrator{

private:
    MultimediaMap m_multimediaMap;
    GroupMap m_groupMap;

public:


    Administrator(){

    }


    //Afficher une synthèse de la bibliothèque
    void synthese(ostream& s){
        s<<"La bibliothèque contient:\n";
    }


    //Créér une Photo, une Vidéo, un Film, un Groupe
    shared_ptr<Photo> creatPhoto(string photoName="new_photo", string pathname="/new_project/", float latitude=100, float longitude=100){
        shared_ptr<Photo> myPhoto(new Photo(photoName,pathname,latitude,longitude));
        m_multimediaMap[photoName] =myPhoto;
        return myPhoto;
    }

    shared_ptr<Video> creatVideo(string videoName,  string pathname="/new_project/", unsigned int duree=10){
        shared_ptr<Video> myVideo(new Video(videoName, pathname,duree));
        m_multimediaMap[videoName] =myVideo;
        return myVideo;
    }

    shared_ptr<Film> creatFilm(string filmName, string pathname="/new_project/", unsigned int duree=10){
        shared_ptr<Film> myFilm(new Film(filmName, pathname, duree));
        m_multimediaMap[filmName] =myFilm;
        return myFilm;
    }

    shared_ptr<Group> creatGroup(string groupName){
        shared_ptr<Group> myGroup(new Group(groupName));
        m_groupMap[groupName]=myGroup;
        return myGroup;
    }







    //Supprimer un objet multimédia ou un groupe à partir de son nom, donné en argument
    void deleteObjet(string nomObjet){

        if(m_multimediaMap.find(nomObjet)!=m_multimediaMap.end()){                 //Le cas où c'est un objet multimedia

            MultimediaMap:: iterator myObjet=m_multimediaMap.find(nomObjet);
            shared_ptr<Multimedia> myObjetFind((*myObjet).second);
            for(GroupMap:: iterator it=m_groupMap.begin();it!=m_groupMap.end();++it){       //Itérer pour tous les groupes

                shared_ptr<Group> myGroupFind((*it).second);

                for(Group::iterator itrGroup=myGroupFind.get()->begin();itrGroup!=myGroupFind.get()->end();++itrGroup){
                    if(*itrGroup==myObjetFind){
                        myGroupFind->erase(itrGroup);
                        break;
                    }
                }

            }
            m_multimediaMap.erase(nomObjet);
        }


        else if(m_groupMap.find(nomObjet)!=m_groupMap.end()){
            m_groupMap.erase(nomObjet);
            cout<<"Le groupe "<<nomObjet<<" est effacée"<<endl;
        }


        else{
            cout<<"L'objet n'est pas trouver dans aucun tableau";
        }
    }







    //Rechercher un objet multimédia ou un groupe à partir de son nom, donné en argument
    void findObjet(string nomObjet, ostream& s){
        // s<<"give result"<<endl;
        if(m_multimediaMap.find(nomObjet)!=m_multimediaMap.end()){                 //Le cas où c'est un objet multimedia
            m_multimediaMap[nomObjet]->affiche(s);
        }
        else if(m_groupMap.find(nomObjet)!=m_groupMap.end()){                      //Le cas où c'est un objet group
            m_groupMap[nomObjet]->affiche(s);
        }
        else{
            s<<"L'objet n'est pas trouver dans aucun tableau\n";
        }
    }


    //Jouer un objet multimédia (à partir de son nom, donné en argument)
    //A compléter*****************************
    void play(string nomObjet, ostream& s){
        if(m_multimediaMap.find(nomObjet)!=m_multimediaMap.end()){                 //Le cas où c'est un objet multimedia
            m_multimediaMap[nomObjet]->jouer();
            s<<"On démarre le jeux:)";
        }
        else
        {
            if(m_groupMap.find(nomObjet)!=m_groupMap.end()){                       //Le cas où c'est un objet group
                s<<"On ne peut pas jouer au groupe";
            }
            else{
                s<<"L'objet n'est pas trouver dans aucun tableau pour jouer";
            }
        }
    }

    //Charger une liste avec la commande
    void cLoad(string nomObjet, ostream& s){
        this->load(nomObjet);
        s<<"La nouvelle bibliothèque chargée!";
    }

    //Save une liste avec la commande
    void cSave(string nomObjet, ostream& s){
        cout<<"$$$"<<nomObjet<<"$$$ê";
        this->save(nomObjet);
        s<<"La bibliothèque sauvegardée!";
    }




    //Sérialisation

    void fabriqueObjet(ifstream &f ,string objet){

        if(objet=="photo"){

            string nom;
            getline(f,nom,' ');
            getline(f,nom);

            string pathName;
            getline(f,pathName,' ');
            getline(f,pathName);

            string slatitude;
            getline(f,slatitude,' ');
            getline(f,slatitude);
            long latitude=atol(slatitude.c_str());

            string slongitude;
            getline(f,slongitude,' ');
            getline(f,slongitude);
            long longitude=std::atol(slongitude.c_str());

            creatPhoto(nom,pathName,latitude,longitude);

        }
        if(objet=="video"){

            string nom;
            getline(f,nom,' ');
            getline(f,nom);

            string pathName;
            getline(f,pathName,' ');
            getline(f,pathName);

            string sduree_total;
            getline(f,sduree_total,' ');
            getline(f,sduree_total);
            int duree_total=atoi(sduree_total.c_str());

            creatVideo(nom,pathName,duree_total);

        }
        if(objet=="film"){
            cout<<"find film"<<endl;
            string nom;
            getline(f,nom,' ');
            getline(f,nom);

            string pathName;
            getline(f,pathName,' ');
            getline(f,pathName);

            string sduree_total;
            getline(f,sduree_total,' ');
            getline(f,sduree_total);
            int duree_total=atoi(sduree_total.c_str());

            string snumberDeChapitre;
            getline(f,snumberDeChapitre,' ');
            getline(f,snumberDeChapitre);
            int numberDeChapitre=atoi(snumberDeChapitre.c_str());
            unsigned int table[numberDeChapitre];
            string sDuree;
            for(int i=0;i<numberDeChapitre;i++){
                getline(f,sDuree,' ');
                getline(f,sDuree);
                table[i]=atoi(sDuree.c_str());
            }
            shared_ptr<Film> newFilm=creatFilm(nom,pathName,duree_total);
            newFilm->modify(table,numberDeChapitre);

        }
    }

    bool   save(const string & fileName)
    {
        ofstream f ;
        f.open(fileName);
        if (!f.is_open()) {
            cerr << "Can't open file " << fileName << endl;
            return false;
        }
        for (auto it : m_multimediaMap)
        {
            it.second->affiche(f);
            f<<"$$FIN_OF_THIS_OBJECT$$\n\n";
        }

        return true;
    }

    bool   load(const string & fileName)
    {
        ifstream f;
        f.open(fileName);
        if(!f.is_open()){
            cerr << "Can't open file " << fileName << endl;
            return false;
        }
        string myCommand;
        int i=1;
        while(std::getline(f,myCommand)){

            if(myCommand=="Type_de_objet: "){

                std::getline(f,myCommand);
                cout<<"Trouver l'objet: "<<i++<<" "<<myCommand<<endl;
                fabriqueObjet(f,myCommand);
            }
        }

        return true;
    }

};


#endif // ADMINISTRATOR_H
