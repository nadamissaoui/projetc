#include <gtk/gtk.h>


void
on_treeview_nada_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercher_nada_clicked               (GtkWidget *objet_graphique, gpointer user_data);

void
on_cherchercrenau_clicked              (GtkWidget *objet_graphique, gpointer user_data);

void
on_gotoajnada_clicked                  (GtkWidget *objet_graphique, gpointer user_data);

void
on_gotomadifnada_clicked               (GtkWidget *objet_graphique, gpointer user_data);

void
on_gotosuppr_clicked                   (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobuttonhmaj_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfemaj_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_retourajtoaffich_clicked            (GtkWidget *objet_graphique, gpointer user_data);

void
on_confirmerajnada_clicked             (GtkWidget *objet_graphique, gpointer user_data);

void
on_recherchermodif_clicked             (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobuttonhommodif_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfemmodif_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gotoaffichonmodif_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_confirmodifna_clicked               (GtkWidget *objet_graphique, gpointer user_data);

void
on_gotomenuonsupp_clicked              (GtkWidget *objet_graphique, gpointer user_data);

void
on_suppnada_clicked                    (GtkWidget *objet_graphique, gpointer user_data);

void
on_actutreenada_clicked                (GtkWidget *objet_graphique, gpointer user_data);
