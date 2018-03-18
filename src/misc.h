/*
 * File: misc.c header
 * Description: Contains helpere functions, and everything that doesn't fit elsewhere
 */
#include <stdint.h>
#ifndef MISC_H
#define MISC_H

#define ICON_COLUMN_WIDTH 20

extern GtkWidget *mainWindowApp; /* Holds pointer to the main searchmonkey GUI. Declared in main.c */

void miscErrorDialog(GtkWidget *widget, const gchar* msg);
gchar *misc_combo_index_to_size_units(gint index);
gchar *misc_get_modified_after_search(gint index, gchar *str1, gchar *str2);
gchar *misc_get_modified(GKeyFile *keyString);
gint convertRegexGtk(size_t offset, const gchar *contents);
gchar *getFullFileName(GtkTreeView *treeView, gint columnNumber);
void initComboBox2(GtkWidget *comboBox);
void initComboBox(GtkWidget *comboBox);
void clearComboBox(GtkWidget *comboBox);
gboolean addUniqueRow(GtkWidget *comboBox, const gchar *entry);
gint g_strlen(const gchar *string);
void setExpertSearchMode (GtkWidget *widget, gboolean expertMode);
gboolean getExpertSearchMode (GtkWidget *widget);
void setResultsViewHorizontal(GtkWidget *widget, gboolean horizontal);
gboolean getResultsViewHorizontal (GtkWidget *widget);
void changeModel(GtkWidget *widget, const gchar *from, const gchar *to);
gchar * getDate(const gchar *curDate, GtkWidget *win);
gboolean test_regexp(gchar *regexp, guint flags, gchar *error);
gboolean validate_folder(const gchar *folderName);
uint16_t getshort(unsigned char *buffer,int offset);
int32_t getlong(unsigned char *buffer,int offset);
uint32_t getulong(unsigned char *buffer,int offset);
#endif /* MISC_H */
