#include <gtk/gtk.h>
#include "include/dynamicStringList.h"
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array of integers
void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

// Global variables to hold the string list and text entry widget
StringList list;
GtkWidget *entry;
GtkWidget *result_label;

// Function to handle the button click
void on_button_clicked(GtkWidget *widget, gpointer data) {
    const char *amount_of_pieces_char = gtk_entry_get_text(GTK_ENTRY(entry));
    int amount_of_pieces = atoi(amount_of_pieces_char);

    if (amount_of_pieces <= 0 || amount_of_pieces > list.size) {
        gtk_label_set_text(GTK_LABEL(result_label), "Invalid input");
        return;
    }

    // Allocate memory for an array of indices
    int *indices = (int *)malloc(list.size * sizeof(int));
    if (indices == NULL) {
        gtk_label_set_text(GTK_LABEL(result_label), "Memory allocation failed");
        return;
    }

    // Initialize the array of indices
    for (int i = 0; i < list.size; i++) {
        indices[i] = i;
    }

    srand(time(NULL));
    shuffle(indices, list.size); // Shuffle the array of indices

    // Generate the result string
    char result[1024] = "Random Elements:\n";
    for (int i = 0; i < amount_of_pieces; i++) {
        strcat(result, list.data[indices[i]]);
        strcat(result, "\n");
    }

    // Set the result label text
    gtk_label_set_text(GTK_LABEL(result_label), result);

    // Free the memory allocated for the array of indices
    free(indices);
}

// Function to initialize the GTK application
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *button;

    // Create a new window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Random Gravytrax Piece Selector");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // Create a box container
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(box), 20);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Center-align the box
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

    // Create a label
    label = gtk_label_new("How many pieces?");
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);

    // Create a text entry
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), entry, TRUE, TRUE, 0);

    // Create a button
    button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

    // Create a result label
    result_label = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(box), result_label, TRUE, TRUE, 0);

    // Show all widgets
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    // Initialize the string list
    initStringList(&list);

    // Add parts to the list
    addString(&list, "Power Elevator");
    addString(&list, "Looping");
    addString(&list, "Trampoline");
    addString(&list, "Power Lift");
    addString(&list, "Jumper");
    addString(&list, "Catapult");
    addString(&list, "Transfer");
    addString(&list, "Lift");
    addString(&list, "Scoop");
    addString(&list, "Tunnel");
    addString(&list, "Bridges");
    addString(&list, "Magnetic Cannon");
    addString(&list, "Releaser");
    addString(&list, "Power Starter");
    addString(&list, "Power Finish");
    addString(&list, "Flextube");
    addString(&list, "Turnable");

    // Create a new GtkApplication
    app = gtk_application_new("com.tim.gravirandom", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Run the application
    status = g_application_run(G_APPLICATION(app), argc, argv);

    // Free the memory allocated for the list
    freeStringList(&list);
    g_object_unref(app);

    return status;
}
