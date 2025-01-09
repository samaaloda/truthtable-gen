#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include "header.h"

static char phrase[100]="";

//returns the phrase to be output using the string sent in as an argument
char* activate(char print[1000]){
    //checks if syntax is correct
	int check = checkInput(strip(phrase));
	if(check ==0){
		return("Your syntax is incorrect. Please try again.\n"); 
    }
    
    //wraps expression with any necessary brackets
    char* wrappedExpr = wrapExpression(strip(phrase));
    //wraps variables with any necessary brackets
    char* formattedExpr = wrapVariables(wrappedExpr);
    
    //the unique variables used will be the basis of the possible variables
	char *var= findUniq(formattedExpr);

	int cols = strlen(var);
    int rows = power(2,cols);

    int (*t)[cols] = (int (*) [cols])truth_table_gen(cols);

    int output[rows];

    treenode* root = NULL;
    build(formattedExpr, &root);
    
    //below builds the table formatted to be printed on screen
	for(int row =0; row<rows; row++ )
    {   
        for(int col = 0; col<cols; col++)
        {
                update_leaf_value(root, var[col], (char) t[row][col] + '0');
        }
        
        output[row]=evaluate_tree(root);
        build(formattedExpr, &root);
	}
    int count=0;
    for(int i = 0; i<cols; i++){
            print[count]=var[i];
            count++;
            print[count]=' ';
            count++;
        } 
    print[count]=' ';
    count++;
	int space = strlen(formattedExpr)/2;
    
    for(int i=0;i<strlen(formattedExpr);i++){
        print[count]=formattedExpr[i];
        count++;
    }
    print[count]='\n';
    count++;
    
     for(int i =0; i<rows; i++)
    {
    
        for(int j=0; j<cols; j++)
		{
            print[count]=t[i][j]+'0';
			count++;
            print[count]=' ';
            count++;
        }
        
        print[count]='|';
        count++;
		for (int i =0 ; i < space ; i++){
            print[count]=' ';
       	 	count++;
       }
       print[count]=output[i]+'0';
       count++;

    print[count]='\n';
    count++;
    }
    return print;

}

//below functions operate based on whether either of these buttons are clicked
void and_clicked(GtkWidget *widget, gpointer label) {
    int len = strlen(phrase);
    phrase[len]='&';
    phrase[len+1]='\0';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}

void or_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)+1]='\0';
    phrase[strlen(phrase)]='|';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}

void not_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)+1]='\0';
    phrase[strlen(phrase)]='~';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}

void op_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)+1]='\0';
    phrase[strlen(phrase)]='(';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}

void clo_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)+1]='\0';
    phrase[strlen(phrase)]=')';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}

void p_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)+1]='\0';
    phrase[strlen(phrase)]='p';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}

void q_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)+1]='\0';
    phrase[strlen(phrase)]='q';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}

void r_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)+1]='\0';
    phrase[strlen(phrase)]='r';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}

void s_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)+1]='\0';
    phrase[strlen(phrase)]='s';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}

void t_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)+1]='\0';
    phrase[strlen(phrase)]='t';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}


void enter_clicked(GtkWidget *widget, gpointer label) {
    char str[1000];
    activate(str);
    gtk_label_set_text(GTK_LABEL(label), activate(str));
}

void del_clicked(GtkWidget *widget, gpointer label) {
    phrase[strlen(phrase)-1]='\0';
    gtk_label_set_text(GTK_LABEL(label), phrase);
}
    
int main(int argc, char *argv[]) {
    const char *title;

    gtk_init(&argc, &argv);

    GtkWidget *fixed=gtk_fixed_new();
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 700, 500);
    gtk_widget_set_size_request(window, 700, 500);//minimum size of the widget is 700x500 px

    //creates button for '(' and sets it into a place 
    GtkWidget *open=gtk_button_new_with_label("(");
    gtk_fixed_put(GTK_FIXED(fixed), open, 50,50);

    GtkWidget *closed=gtk_button_new_with_label(")");
    gtk_fixed_put(GTK_FIXED(fixed), closed, 100,50);

    GtkWidget *and=gtk_button_new_with_label("&");
    gtk_fixed_put(GTK_FIXED(fixed),and,150,50);
    
    GtkWidget *or=gtk_button_new_with_label("|");
    gtk_fixed_put(GTK_FIXED(fixed), or, 200,50);

    GtkWidget *not=gtk_button_new_with_label("~");
    gtk_fixed_put(GTK_FIXED(fixed), not, 250,50);

    GtkWidget *p=gtk_button_new_with_label("p");
    gtk_fixed_put(GTK_FIXED(fixed), p, 50,100);

    GtkWidget *q=gtk_button_new_with_label("q");
    gtk_fixed_put(GTK_FIXED(fixed), q, 100,100);

    GtkWidget *r=gtk_button_new_with_label("r");
    gtk_fixed_put(GTK_FIXED(fixed), r, 150,100);

    GtkWidget *s=gtk_button_new_with_label("s");
    gtk_fixed_put(GTK_FIXED(fixed), s, 200,100);

    GtkWidget *t=gtk_button_new_with_label("t");
    gtk_fixed_put(GTK_FIXED(fixed), t, 250,100);

    GtkWidget *enter=gtk_button_new_with_label("ENTER");
    gtk_fixed_put(GTK_FIXED(fixed), enter, 300,50);

    GtkWidget *delete=gtk_button_new_with_label("DELETE");
    gtk_fixed_put(GTK_FIXED(fixed), delete, 300,100);

    GtkWidget *label = gtk_label_new("Your statement goes here: ");
    gtk_fixed_put(GTK_FIXED(fixed), label, 50, 200);

    GtkWidget *answer = gtk_label_new("Your truth table goes here: ");
    gtk_fixed_put(GTK_FIXED(fixed), answer, 50, 250);
    
    g_signal_connect(and, "clicked", G_CALLBACK(and_clicked), label);
    g_signal_connect(or, "clicked", G_CALLBACK(or_clicked), label);
    g_signal_connect(not, "clicked", G_CALLBACK(not_clicked), label);
    g_signal_connect(open, "clicked", G_CALLBACK(op_clicked), label);
    g_signal_connect(closed, "clicked", G_CALLBACK(clo_clicked), label);

    g_signal_connect(p, "clicked", G_CALLBACK(p_clicked), label);
    g_signal_connect(q, "clicked", G_CALLBACK(q_clicked), label);
    g_signal_connect(r, "clicked", G_CALLBACK(r_clicked), label);
    g_signal_connect(s, "clicked", G_CALLBACK(s_clicked), label);
    g_signal_connect(t, "clicked", G_CALLBACK(t_clicked), label);

    g_signal_connect(enter, "clicked", G_CALLBACK(enter_clicked),answer);
    g_signal_connect(delete, "clicked", G_CALLBACK(del_clicked),label);


    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_add(GTK_CONTAINER(window), fixed);
    gtk_widget_show_all(window); //passes parent widget to show
    gtk_main();
    return 0;
}