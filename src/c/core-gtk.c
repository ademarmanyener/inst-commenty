#include <gtk/gtk.h>
#include "include/header.h"

GtkBuilder *builder;
GtkWidget *window;

void run_app(const char *username,
	     const char *password,
	     const char *address,
	     const char *message,
	     int count
	     )
{
  char cmd[250] = "python3 src/py/app.py --username ";
  strcat(cmd, username);
  strcat(cmd, " --password ");
  strcat(cmd, password);
  strcat(cmd, " --addr ");
  strcat(cmd, address);
  strcat(cmd, " --msg ");
  strcat(cmd, message);
  int i=0;
  for (;i< count;){
    printf("sending... (%d/%d)\n", i+1, count);
    system(cmd);
    i = i + 1;
  }
  printf("OK (%s)\n", address);
  return;
}

void on_window_main_destroy(){
  gtk_main_quit();
  return;
}

void on_btnSend_clicked(){
  const char *g_entryUsername = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "entry_username")));
  const char *g_entryPassword = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "entry_password")));
  const char *g_entryAddress = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "entry_address")));
  const char *g_entryMessage = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "entry_message")));
  int g_entryCount = atoi(gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "entry_count"))));
  run_app(g_entryUsername, g_entryPassword, g_entryAddress, g_entryMessage, g_entryCount);
  return;
}

int main(int argc, char *argv[]){
  gtk_init(&argc, &argv);
  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "src/ui/ui.glade", NULL);
  gtk_builder_connect_signals(builder, NULL);
  window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
  g_object_unref(window);
  gtk_widget_show(window);
  gtk_main();
  return 0;
}
