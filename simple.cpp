#include<bits/stdc++.h>
#include <glib.h>
using namespace std;
int main()
{   gchar *str = "A hindi character: अ\n"; 
	setlocale(LC_ALL, "en_US.utf8"); 
	g_print(str); 
    return 0;
}