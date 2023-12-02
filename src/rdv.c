#include "rdv.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum
{
	EID,
	ECIN,
	ENOM,
	EPRENOM,
	ETEL,
	ESEXE,
	EJJR,
	EMMR,
	EAAR,
	ECR,
	ETYPE,
	EIDETAB,
	EJJPR,
	EMMPR,
	EAAPR,
	COLUMNS
};
int ajouter_rdv(rdv r)
{
FILE* f=fopen("rdv.txt","a+");
 if(f!=NULL)
 {
  fprintf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,r.daterdv.jj,r.daterdv.mm,r.daterdv.aa,r.cr,r.type,r.idetab,r.dateprrdv.jj,r.dateprrdv.mm,r.dateprrdv.aa);
 fclose(f);
 return 1;
 }
 else return 0;
}


void chercher_rdvparcr(GtkTreeView *liste,char cr[])
{
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter ;
    GtkListStore *store;
    rdv r;
    store=NULL;
    FILE *f;
    store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
    if(store==NULL){

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("IDRDV",renderer,"text",EID,NULL);
        gtk_tree_view_append_column(liste,column);

        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",ECIN,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
        gtk_tree_view_append_column(liste,column); 

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Tel",renderer,"text",ETEL,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("JourRDV",renderer,"text",EJJR,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("MoisRDV",renderer,"text",EMMR,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("AnnéeRDV",renderer,"text",EAAR,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Creneau",renderer,"text",ECR,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",ETYPE,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("IDetab",renderer,"text",EIDETAB,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("JourPremier",renderer,"text",EJJPR,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("MoisPremier",renderer,"text",EMMPR,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Annéepremier",renderer,"text",EAAPR,NULL);
        gtk_tree_view_append_column(liste,column);



         
    }
          
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    f=fopen("rdv.txt","r");
    if(f==NULL){return;}
    else
    {
                 f=fopen("rdv.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,&r.daterdv.jj,&r.daterdv.mm,&r.daterdv.aa,r.cr,r.type,r.idetab,&r.dateprrdv.jj,&r.dateprrdv.mm,&r.dateprrdv.aa)!=EOF)
         {
		if(strcmp(r.cr,cr)==0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,0,r.idrdv,1,r.cin,2,r.nom,3,r.prenom,4,r.telephone,5,r.sexe,6,r.daterdv.jj,7,r.daterdv.mm,8,r.daterdv.aa,9,r.cr,10,r.type,11,r.idetab,12,r.dateprrdv.jj,13,r.dateprrdv.mm,14,r.dateprrdv.aa,-1);
         }}
     fclose(f);
     gtk_tree_view_set_model(liste,GTK_TREE_MODEL(store));
     g_object_unref(store);
    }

}

void chercher_rdvpardate(GtkTreeView *liste,Date d)
{
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter ;
    GtkListStore *store;
    rdv r;
    store=NULL;
    FILE *f;
    store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
    if(store==NULL){

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("IDRDV",renderer,"text",EID,NULL);
        gtk_tree_view_append_column(liste,column);

        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",ECIN,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
        gtk_tree_view_append_column(liste,column); 

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Tel",renderer,"text",ETEL,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("JourRDV",renderer,"text",EJJR,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("MoisRDV",renderer,"text",EMMR,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("AnnéeRDV",renderer,"text",EAAR,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Creneau",renderer,"text",ECR,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",ETYPE,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("IDetab",renderer,"text",EIDETAB,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("JourPremier",renderer,"text",EJJPR,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("MoisPremier",renderer,"text",EMMPR,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Annéepremier",renderer,"text",EAAPR,NULL);
        gtk_tree_view_append_column(liste,column);



         
    }
          
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    f=fopen("rdv.txt","r");
    if(f==NULL){return;}
    else
    {
                 f=fopen("rdv.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,&r.daterdv.jj,&r.daterdv.mm,&r.daterdv.aa,r.cr,r.type,r.idetab,&r.dateprrdv.jj,&r.dateprrdv.mm,&r.dateprrdv.aa)!=EOF)
         {
		if((d.jj==r.daterdv.jj)&&(d.mm==r.daterdv.mm)&&(d.aa==r.daterdv.aa)){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,0,r.idrdv,1,r.cin,2,r.nom,3,r.prenom,4,r.telephone,5,r.sexe,6,r.daterdv.jj,7,r.daterdv.mm,8,r.daterdv.aa,9,r.cr,10,r.type,11,r.idetab,12,r.dateprrdv.jj,13,r.dateprrdv.mm,14,r.dateprrdv.aa,-1);
         }}
     fclose(f);
     gtk_tree_view_set_model(liste,GTK_TREE_MODEL(store));
     g_object_unref(store);
    }

}



void afficher_rdv(GtkTreeView *liste)
{
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter ;
    GtkListStore *store;
    rdv r;
    store=NULL;
    FILE *f;
    store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
    if(store==NULL){

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("IDRDV",renderer,"text",EID,NULL);
        gtk_tree_view_append_column(liste,column);

        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",ECIN,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
        gtk_tree_view_append_column(liste,column); 

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Tel",renderer,"text",ETEL,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("JourRDV",renderer,"text",EJJR,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("MoisRDV",renderer,"text",EMMR,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("AnnéeRDV",renderer,"text",EAAR,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Creneau",renderer,"text",ECR,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",ETYPE,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("IDetab",renderer,"text",EIDETAB,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("JourPremier",renderer,"text",EJJPR,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("MoisPremier",renderer,"text",EMMPR,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Annéepremier",renderer,"text",EAAPR,NULL);
        gtk_tree_view_append_column(liste,column);



         
    }
          
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    f=fopen("rdv.txt","r");
    if(f==NULL){return;}
    else
    {
                 f=fopen("rdv.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,&r.daterdv.jj,&r.daterdv.mm,&r.daterdv.aa,r.cr,r.type,r.idetab,&r.dateprrdv.jj,&r.dateprrdv.mm,&r.dateprrdv.aa)!=EOF)
         {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,0,r.idrdv,1,r.cin,2,r.nom,3,r.prenom,4,r.telephone,5,r.sexe,6,r.daterdv.jj,7,r.daterdv.mm,8,r.daterdv.aa,9,r.cr,10,r.type,11,r.idetab,12,r.dateprrdv.jj,13,r.dateprrdv.mm,14,r.dateprrdv.aa,-1);
         }
     fclose(f);
     gtk_tree_view_set_model(liste,GTK_TREE_MODEL(store));
     g_object_unref(store);
    }

}


 //fonction modifer
int modifier_rdv(rdv r2)
{
    rdv r;
    FILE * f=fopen("rdv.txt", "r");
    FILE * f2 =fopen("autre.txt", "a+");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,&r.daterdv.jj,&r.daterdv.mm,&r.daterdv.aa,r.cr,r.type,r.idetab,&r.dateprrdv.jj,&r.dateprrdv.mm,&r.dateprrdv.aa)!=EOF)
{
if(strcmp(r2.idrdv,r.idrdv)==0)
        
	fprintf(f2,"%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r2.idrdv,r2.cin,r2.nom,r2.prenom,r2.telephone,r2.sexe,r2.daterdv.jj,r2.daterdv.mm,r2.daterdv.aa,r2.cr,r2.type,r2.idetab,r2.dateprrdv.jj,r2.dateprrdv.mm,r2.dateprrdv.aa);
else

  	fprintf(f2,"%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,r.daterdv.jj,r.daterdv.mm,r.daterdv.aa,r.cr,r.type,r.idetab,r.dateprrdv.jj,r.dateprrdv.mm,r.dateprrdv.aa);

}
        fclose(f);
        fclose(f2);
remove("rdv.txt");
rename("autre.txt", "rdv.txt");
        return 1;
    }

}

//fonctioh supprimer
int supprimer_rdv(char id[])
{
    rdv r;
    int t=0;
    FILE * f=fopen("rdv.txt", "r");
    FILE * f2 =fopen("autre.txt", "a+");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,&r.daterdv.jj,&r.daterdv.mm,&r.daterdv.aa,r.cr,r.type,r.idetab,&r.dateprrdv.jj,&r.dateprrdv.mm,&r.dateprrdv.aa)!=EOF)
{
if(strcmp(r.idrdv,id)==0)
	t=1;
else
fprintf(f2,"%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,r.daterdv.jj,r.daterdv.mm,r.daterdv.aa,r.cr,r.type,r.idetab,r.dateprrdv.jj,r.dateprrdv.mm,r.dateprrdv.aa);
}
        fclose(f);
        fclose(f2);
remove("rdv.txt");
rename("autre.txt", "rdv.txt");
if(t==1)
        return 1;
else
	return 0;
    }
}


rdv* chercher_rdv(char id[]) {
    rdv* r = malloc(sizeof(rdv));
    int t = 0;
    FILE* f = fopen("rdv.txt", "r");

    if (f == NULL)
        return NULL;
    else {
        while (fscanf(f, "%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r->idrdv,r->cin,r->nom,r->prenom,r->telephone,r->sexe,&r->daterdv.jj,&r->daterdv.mm,&r->daterdv.aa,r->cr,r->type,r->idetab,&r->dateprrdv.jj,&r->dateprrdv.mm,&r->dateprrdv.aa) != EOF) {
            if (strcmp(r->idrdv, id) == 0){
                t = 1;
		break;}
        }

        fclose(f);

        if (t == 1)
            return r;
        else {
            free(r);  
            return NULL;
        }
 
    }}
int chercherpardate(Date d){
rdv r;
int t = 0;
FILE* f = fopen("rdv.txt", "r");
if (f == NULL)
        return 0;
    else {
        while (fscanf(f, "%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,&r.daterdv.jj,&r.daterdv.mm,&r.daterdv.aa,r.cr,r.type,r.idetab,&r.dateprrdv.jj,&r.dateprrdv.mm,&r.dateprrdv.aa) != EOF) {
            if ((d.jj==r.daterdv.jj)&&(d.mm==r.daterdv.mm)&&(d.aa==r.daterdv.aa)){
                t = 1;
		break;}
        }

        fclose(f);

        if (t == 1)
            return 1;
        else { 
            return 0;
        }
 
    }
}
int chercherparcr(char cr[]){
rdv r;
int t = 0;
FILE* f = fopen("rdv.txt", "r");
if (f == NULL)
        return 0;
    else {
        while (fscanf(f, "%s %s %s %s %s %s %d %d %d %s %s %s %d %d %d\n",r.idrdv,r.cin,r.nom,r.prenom,r.telephone,r.sexe,&r.daterdv.jj,&r.daterdv.mm,&r.daterdv.aa,r.cr,r.type,r.idetab,&r.dateprrdv.jj,&r.dateprrdv.mm,&r.dateprrdv.aa) != EOF) {
            if (strcmp(r.cr, cr) == 0){
                t = 1;
		break;}
        }

        fclose(f);

        if (t == 1)
            return 1;
        else { 
            return 0;
        }
 
    }
}


