/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <glib.h>
#include <pthread.h>

#include "interface.h"
#include "support.h"
#include "search.h"
#include "savestate.h" /* Add support for save/restore config.ini */

GtkWidget *mainWindowApp = NULL; /* Holds pointer to the main window (global) */
gchar *gConfigFile = NULL; /* created by main(), destroyed by destroyGKeyFile() */

/*
 * Searchmonkey entry point
 */
int main (int argc, char *argv[])
{
  GdkPixbuf* pixBuf;
  gchar *tmpStr;
  
  /* Initiate threads */
  g_thread_init (NULL);
  gdk_threads_init ();
  gdk_threads_enter ();
  
#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  /* Handle GTK command line options and the locale settings */
  gtk_set_locale ();
  gtk_init (&argc, &argv);

  /* Create main window, and load (create) ini config file */
  add_pixmap_directory (PACKAGE_DATA_DIR "/pixmaps/" PACKAGE); /* New location for all pixmaps */
  add_pixmap_directory (PACKAGE_DATA_DIR "/pixmaps"); /* Gnome users /usr/share/pixmaps folder */
  mainWindowApp = create_window1 ();
  gConfigFile = g_build_filename(g_get_home_dir(), "." PACKAGE, SEARCHMONKEY_CONFIG, NULL); /* Create hidden directory to store searchmonkey data */
  createGKeyFile (G_OBJECT (mainWindowApp), MASTER_OPTIONS_DATA);

  /* Create pointer to the argv command line */
  g_object_set_data(G_OBJECT(mainWindowApp), "argvPointer", argv[0]);

  /* Set up global strings */
  tmpStr = g_strdup_printf(_("\nNo content searching performed for this file.\n\nPlease ensure containing search was enabled, and that an expression was entered prior to starting search.\n"));
  g_object_set_data_full(G_OBJECT(mainWindowApp), "noContextSearchString", tmpStr, g_free);
  tmpStr = g_strdup_printf(_("N/A"));
  g_object_set_data_full(G_OBJECT(mainWindowApp), "notApplicable", tmpStr, g_free);

  /* Show app, and start main loop */
  gtk_widget_show (mainWindowApp);
  gtk_main ();

  /* Clean exit */
  gdk_threads_leave ();
  return 0;
}

