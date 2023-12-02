#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"rdv.h"


int x,x2;
void
on_treeview_nada_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *idrdv;
gchar *cin;
gchar *nom;
gchar *prenom;
gchar *telephone;
gchar *sexe;
gint  *daterdvjj;
gint  *daterdvmm;
gint  *daterdvaa;
gchar *cr;
gchar *type;
gchar *idetab;
gint  *dateprrdvjj;
gint  *dateprrdvmm;
gint  *dateprrdvaa;
rdv r;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{ gtk_tree_model_get(GTK_TREE_MODEL(model),&iter,0,idrdv,1,cin,2,nom,3,prenom,4,telephone,5,sexe,6,&daterdvjj,7,&daterdvmm,8,&daterdvaa,9,cr,10,type,11,idetab,12,&dateprrdvjj,13,&dateprrdvmm,14,&dateprrdvaa,-1);
strcpy(r.idrdv,idrdv);
strcpy(r.cin,cin);
strcpy(r.nom,nom);
strcpy(r.prenom,prenom);
strcpy(r.telephone,telephone);
strcpy(r.sexe,sexe);
r.daterdv.jj=*daterdvjj;
r.daterdv.mm=*daterdvmm;
r.daterdv.aa=*daterdvaa;
strcpy(r.cr,cr);
strcpy(r.type,type);
strcpy(r.idetab,idetab);
r.dateprrdv.jj=*dateprrdvjj;
r.dateprrdv.mm=*dateprrdvmm;
r.dateprrdv.aa=*dateprrdvaa;
afficher_rdv(treeview);}
}


void
on_chercher_nada_clicked               (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*j,*m,*a,*treeview,*label;
Date d;
int t=0;
treeview=lookup_widget(objet_graphique,"treeview_nada");
label=lookup_widget(objet_graphique,"resultatcherchelab");
j=lookup_widget(objet_graphique,"spinbuttonjaffich");
m=lookup_widget(objet_graphique,"spinbuttonmaffich");
a=lookup_widget(objet_graphique,"spinbuttonaaffich");
GtkTreeModel *model=gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
gtk_list_store_clear(GTK_LIST_STORE(model));
d.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
d.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
d.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));
t=chercherpardate(d);
if(t==0) gtk_label_set_text(GTK_LABEL(label),"pas disponnible");
else{
chercher_rdvpardate(GTK_TREE_VIEW(treeview),d);
gtk_label_set_text(GTK_LABEL(label),"disponnible");
}
}


void
on_cherchercrenau_clicked              (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*combo,*treeview,*label;
char cr[50];
int t=0;
treeview=lookup_widget(objet_graphique,"treeview_nada");
label=lookup_widget(objet_graphique,"resultatrecherchecrenau");
combo=lookup_widget(objet_graphique,"comboboxentryafffichnada");
GtkTreeModel *model=gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
gtk_list_store_clear(GTK_LIST_STORE(model));
strcpy(cr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
t=chercherparcr(cr);
if(t==0) gtk_label_set_text(GTK_LABEL(label),"pas disponnible");
else{
chercher_rdvparcr(GTK_TREE_VIEW(treeview),cr);
gtk_label_set_text(GTK_LABEL(label),"disponnible");
}
}


void
on_gotoajnada_clicked                  (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "affiche_nada");
p=lookup_widget(objet_graphique, "ajouter_nada");
p=  create_ajouter_nada();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_gotomadifnada_clicked               (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "affiche_nada");
p=lookup_widget(objet_graphique, "modifier_nada");
p=  create_modifier_nada();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_gotosuppr_clicked                   (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "affiche_nada");
p=lookup_widget(objet_graphique, "supprimer_nada");
p=  create_supprimer_nada();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_radiobuttonhmaj_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x=1;
}


void
on_radiobuttonfemaj_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x=2;
}


void
on_retourajtoaffich_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ajouter_nada");
p=lookup_widget(objet_graphique, "affiche_nada");
p=  create_affiche_nada();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_confirmerajnada_clicked             (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*id,*cin,*nom,*prenom,*tel,*rj,*rm,*ra,*cr,*ty,*ietab,*prj,*prm,*praa,*label;
rdv r;
int t=0;
id=lookup_widget(objet_graphique, "entryidrdvaj");
cin=lookup_widget(objet_graphique, "entrycinaj");
nom=lookup_widget(objet_graphique, "entrynomaj");
prenom=lookup_widget(objet_graphique, "entryprenomaj");
tel=lookup_widget(objet_graphique, "entrytelaj");
rj=lookup_widget(objet_graphique, "spinbuttonjaj");
rm=lookup_widget(objet_graphique, "spinbuttonmaj");
ra=lookup_widget(objet_graphique, "spinbuttonaaj");
cr=lookup_widget(objet_graphique, "comboboxentrycrenaj");
ty=lookup_widget(objet_graphique, "comboboxentrytypeaj");
ietab=lookup_widget(objet_graphique, "entryidetabaj");
prj=lookup_widget(objet_graphique, "spinbuttonjpraj");
prm=lookup_widget(objet_graphique, "spinbuttonmpraj");
praa=lookup_widget(objet_graphique, "spinbuttonapraj");
label=lookup_widget(objet_graphique, "confirmationajnada");
strcpy(r.idrdv,gtk_entry_get_text(GTK_ENTRY(id))); 
strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(cin))); 
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom))); 
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom))); 
strcpy(r.telephone,gtk_entry_get_text(GTK_ENTRY(tel))); 
strcpy(r.idetab,gtk_entry_get_text(GTK_ENTRY(ietab)));
if(x==1)  strcpy(r.sexe,"homme");
else strcpy(r.sexe,"femme");

r.daterdv.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rj));
r.daterdv.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rm));
r.daterdv.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ra));

r.dateprrdv.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prj));
r.dateprrdv.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prm));
r.dateprrdv.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(praa));
strcpy(r.cr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cr)));
strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));

t=ajouter_rdv(r);
if(t==0) gtk_label_set_text(GTK_LABEL(label),"error");
else gtk_label_set_text(GTK_LABEL(label),"valider");
}


void
on_recherchermodif_clicked             (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*id,*cin,*nom,*prenom,*tel,*rj,*rm,*ra,*cr,*ty,*ietab,*prj,*prm,*praa,*label,*homme,*femme;
char chh[50];
rdv *r;
id=lookup_widget(objet_graphique, "entryidrmodif");
cin=lookup_widget(objet_graphique, "entrycinmodif");
nom=lookup_widget(objet_graphique, "entrynommodif");
prenom=lookup_widget(objet_graphique, "entryprenommodf");
tel=lookup_widget(objet_graphique, "entrytelephonemodif");
rj=lookup_widget(objet_graphique, "spinbuttonjrmodif");
rm=lookup_widget(objet_graphique, "spinbuttonmrmodif");
ra=lookup_widget(objet_graphique, "spinbuttonarmodif");
cr=lookup_widget(objet_graphique, "comboboxentrycrenmodif");
ty=lookup_widget(objet_graphique, "comboboxentrytypesang");
ietab=lookup_widget(objet_graphique, "entryidetabmodif");
prj=lookup_widget(objet_graphique, "spinbuttonjdateprmodif");
prm=lookup_widget(objet_graphique, "spinbuttonmprmodif");
praa=lookup_widget(objet_graphique, "spinbuttonaprmodif");

homme=lookup_widget(objet_graphique, "radiobuttonhommodif");
femme=lookup_widget(objet_graphique, "radiobuttonfemmodif");
label=lookup_widget(objet_graphique, "resultatrecherchemodif");
strcpy(chh,gtk_entry_get_text(GTK_ENTRY(id))); 
r=chercher_rdv(chh);
if(r==NULL) gtk_label_set_text(GTK_LABEL(label),"Not Found");
else{
gtk_label_set_text(GTK_LABEL(label),"Found");
gtk_entry_set_text(GTK_ENTRY(cin),r->cin);
gtk_entry_set_text(GTK_ENTRY(nom),r->nom);
gtk_entry_set_text(GTK_ENTRY(prenom),r->prenom);
gtk_entry_set_text(GTK_ENTRY(tel),r->telephone);
gtk_entry_set_text(GTK_ENTRY(ietab),r->idetab);


if(strcmp(r->sexe,"homme")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(homme),TRUE);
}
else{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femme),TRUE);
}

gtk_spin_button_set_value(GTK_SPIN_BUTTON(rj),r->daterdv.jj);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(rm),r->daterdv.mm);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(ra),r->daterdv.aa);

gtk_spin_button_set_value(GTK_SPIN_BUTTON(prj),r->dateprrdv.jj);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(prm),r->dateprrdv.mm);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(praa),r->dateprrdv.aa);



if(strcmp(r->cr,"9h")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(cr),0);
else if(strcmp(r->cr,"11h")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(cr),1);
else if(strcmp(r->cr,"13h")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(cr),2);
else if(strcmp(r->cr,"14h")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(cr),3);
else
gtk_combo_box_set_active(GTK_COMBO_BOX(cr),4);




if(strcmp(r->type,"A+")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(ty),0);
else if(strcmp(r->type,"A-")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(ty),1);
else if(strcmp(r->type,"O+")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(ty),2);
else if(strcmp(r->type,"O-")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(ty),3);
else if(strcmp(r->type,"B+")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(ty),4);
else if(strcmp(r->type,"B-")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(ty),5);
else if(strcmp(r->type,"AB+")==0)
gtk_combo_box_set_active(GTK_COMBO_BOX(ty),6);
else
gtk_combo_box_set_active(GTK_COMBO_BOX(ty),7);
}
}


void
on_radiobuttonhommodif_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x=1;
}


void
on_radiobuttonfemmodif_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
x=2;
}


void
on_gotoaffichonmodif_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "modifier_nada");
p=lookup_widget(objet_graphique, "affiche_nada");
p=  create_affiche_nada();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_confirmodifna_clicked               (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*id,*cin,*nom,*prenom,*tel,*rj,*rm,*ra,*cr,*ty,*ietab,*prj,*prm,*praa,*label;
rdv r;
int t=0;
id=lookup_widget(objet_graphique, "entryidrmodif");
cin=lookup_widget(objet_graphique, "entrycinmodif");
nom=lookup_widget(objet_graphique, "entrynommodif");
prenom=lookup_widget(objet_graphique, "entryprenommodf");
tel=lookup_widget(objet_graphique, "entrytelephonemodif");
rj=lookup_widget(objet_graphique, "spinbuttonjrmodif");
rm=lookup_widget(objet_graphique, "spinbuttonmrmodif");
ra=lookup_widget(objet_graphique, "spinbuttonarmodif");
cr=lookup_widget(objet_graphique, "comboboxentrycrenmodif");
ty=lookup_widget(objet_graphique, "comboboxentrytypesang");
ietab=lookup_widget(objet_graphique, "entryidetabmodif");
prj=lookup_widget(objet_graphique, "spinbuttonjdateprmodif");
prm=lookup_widget(objet_graphique, "spinbuttonmprmodif");
praa=lookup_widget(objet_graphique, "spinbuttonaprmodif");
label=lookup_widget(objet_graphique, "resultatmodif");

strcpy(r.idrdv,gtk_entry_get_text(GTK_ENTRY(id))); 
strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(cin))); 
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom))); 
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom))); 
strcpy(r.telephone,gtk_entry_get_text(GTK_ENTRY(tel))); 
strcpy(r.idetab,gtk_entry_get_text(GTK_ENTRY(ietab)));
if(x==1)  strcpy(r.sexe,"homme");
else strcpy(r.sexe,"femme");

r.daterdv.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rj));
r.daterdv.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rm));
r.daterdv.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ra));

r.dateprrdv.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prj));
r.dateprrdv.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prm));
r.dateprrdv.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(praa));
strcpy(r.cr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cr)));
strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));

t=modifier_rdv(r);
if(t==0) gtk_label_set_text(GTK_LABEL(label),"error");
else gtk_label_set_text(GTK_LABEL(label),"valider");
}


void
on_gotomenuonsupp_clicked              (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "supprimer_nada");
p=lookup_widget(objet_graphique, "affiche_nada");
p=  create_affiche_nada();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_suppnada_clicked                    (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget*id,*label;
char chh[50];
int t=0;
id=lookup_widget(objet_graphique, "entryidsupp");
label=lookup_widget(objet_graphique, "resultatsupp");
strcpy(chh,gtk_entry_get_text(GTK_ENTRY(id))); 
t=supprimer_rdv(chh);
if(t==0) gtk_label_set_text(GTK_LABEL(label),"error");
else gtk_label_set_text(GTK_LABEL(label),"valider");
}


void
on_actutreenada_clicked                (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *treeview;
treeview=lookup_widget(objet_graphique,"treeview_nada");
afficher_rdv(GTK_TREE_VIEW(treeview));
}

