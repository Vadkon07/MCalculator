#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MY_MAX_INPUT 256  // I decided to name is as MY_MAX_INPUT because with MAX_INPUT it will show some warnings

void remove_last_char(char *str);

char input_buffer[MY_MAX_INPUT] = "";

void on_button_click(GtkWidget *widget, gpointer data) {
	const char *button_label = gtk_button_get_label(GTK_BUTTON(widget));
	strncat(input_buffer, button_label, MY_MAX_INPUT - strlen(input_buffer) - 1);
	gtk_entry_set_text(GTK_ENTRY(data), input_buffer);
}

void on_ce_button_click(GtkWidget *widget, gpointer data) {
	gtk_entry_set_text(GTK_ENTRY(data), "0");
	memset(input_buffer, 0, sizeof(input_buffer));
}

void on_c_button_click(GtkWidget *widget, gpointer data) {
	remove_last_char(input_buffer);
	//memset(input_buffer, 0, sizeof(input_buffer));
	gtk_entry_set_text(GTK_ENTRY(data), input_buffer);
}

void remove_last_char(char *str) {
    size_t len = strlen(str);
    if (len > 0) {
        str[len - 1] = '\0';
    }
}

double evaluate_expression(const char *expression);
void on_equals_click(GtkWidget *widget, gpointer data) {
	double result = evaluate_expression(input_buffer);
	char result_str[MY_MAX_INPUT];
	snprintf(result_str, MY_MAX_INPUT, "%g", result);
	gtk_entry_set_text(GTK_ENTRY(data), result_str);
	strcpy(input_buffer, "");
}

double evaluate_expression(const char *expression) {
    double result = 0.0;
    double current_number = 0.0;
    char current_operator = '+';
    int i = 0;

    while (expression[i] != '\0') {
        if (isdigit(expression[i]) || expression[i] == '.') {
            char number_buffer[MY_MAX_INPUT];
            int j = 0;

            while (isdigit(expression[i]) || expression[i] == '.') {
                number_buffer[j++] = expression[i++];
            }
            number_buffer[j] = '\0';

            current_number = atof(number_buffer);

            switch (current_operator) {
                case '+':
                    result += current_number;
                    break;
                case '-':
                    result -= current_number;
                    break;
                case '*':
                    result *= current_number;
                    break;
                case '/':
                    if (current_number != 0.0) {
                        result /= current_number;
                    } else {
                        g_print("Division by zero error!\n");
                    }
                    break;
            }
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            current_operator = expression[i++];
        } else {
            i++;  // Skip any non-operator/non-digit character (e.g., spaces)
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

	const char *app_version = "0.1.0";

	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *display;
	GtkWidget *zero_button;
	GtkWidget *one_button;
	GtkWidget *two_button;
	GtkWidget *three_button;
	GtkWidget *four_button;
	GtkWidget *five_button;
	GtkWidget *six_button;
	GtkWidget *seven_button;
	GtkWidget *eight_button;
	GtkWidget *nine_button;
	GtkWidget *CE_button;
	GtkWidget *C_button;
	GtkWidget *equals_button;
	GtkWidget *plus_button;
	GtkWidget *minus_button;
	GtkWidget *divide_button;
	GtkWidget *multiply_button;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	char title[50];
	sprintf(title, "MCalculator %s", app_version);

	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_widget_set_size_request(window, 250, 250);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	grid = gtk_grid_new();
	gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
	gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);
	gtk_container_add(GTK_CONTAINER(window), grid);
	
	display = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), display, 0, 0, 4, 1);
	zero_button = gtk_button_new_with_label("0");
	one_button = gtk_button_new_with_label("1");
	two_button = gtk_button_new_with_label("2");
	three_button = gtk_button_new_with_label("3");
	four_button = gtk_button_new_with_label("4");
	five_button = gtk_button_new_with_label("5");
	six_button = gtk_button_new_with_label("6");
	seven_button = gtk_button_new_with_label("7");
	eight_button = gtk_button_new_with_label("8");
	nine_button = gtk_button_new_with_label("9");
	CE_button = gtk_button_new_with_label("CE");
	C_button = gtk_button_new_with_label("C");
	equals_button = gtk_button_new_with_label("=");
	plus_button = gtk_button_new_with_label("+");
	minus_button = gtk_button_new_with_label("-");
	divide_button = gtk_button_new_with_label("/");
	multiply_button = gtk_button_new_with_label("*");
	
	gtk_grid_attach(GTK_GRID(grid), seven_button, 0, 1, 1, 1);
       	gtk_grid_attach(GTK_GRID(grid), eight_button, 1, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), nine_button, 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), divide_button, 3, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), four_button, 0, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), five_button, 1, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), six_button, 2, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), multiply_button, 3, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), one_button, 0, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), two_button, 1, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), three_button, 2, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), minus_button, 3, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), zero_button, 0, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), CE_button, 1, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), C_button, 2, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), plus_button, 3, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), equals_button, 0, 5, 4, 1);

	g_signal_connect(zero_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(one_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(two_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(three_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(four_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(five_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(six_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(seven_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(eight_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(nine_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(plus_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(minus_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(divide_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(multiply_button, "clicked", G_CALLBACK(on_button_click), display);
	g_signal_connect(equals_button, "clicked", G_CALLBACK(on_equals_click), display);
	g_signal_connect(CE_button, "clicked", G_CALLBACK(on_ce_button_click), display);
	g_signal_connect(C_button, "clicked", G_CALLBACK(on_c_button_click), display);
	
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
