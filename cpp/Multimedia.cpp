#include "Multimedia.h"


Multimedia:: Multimedia()
{

}

Multimedia:: Multimedia(string nom_multimedia, string pathname)
{
    m_nom_multimedia=nom_multimedia;
    m_pathname=pathname;

}

Multimedia:: ~Multimedia()
{

}

string Multimedia::  getNom_multimedia() const          //Récupérer le nom de multimédia
{
    return m_nom_multimedia;
}

string Multimedia::  getPathname() const                //Récupérer le nom du répertoire
{
    return m_pathname;
}

void   Multimedia::  setNom_multimedia(string nom_multimedia)
{
    m_nom_multimedia=nom_multimedia;
}

void   Multimedia::  setPathname(string pathname)
{
    m_pathname=pathname;
}


void   Multimedia::  affiche(ostream& s) const           //Afficher les informations sur l'objet multimédia
{
    s << "Nom_de_multimedia: "<< m_nom_multimedia <<"\nPathname: "<< m_pathname;
}

////Sérialisation
//bool   Multimedia:: save(const string & fileName)
//{

//}

//bool   Multimedia:: load(const string & fileName)
//{

//}
