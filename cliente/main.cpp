/* #include <gtkmm/main.h>
#include "pWindows.h"
*/

#include "cliente.h"

int main (int argc, char *argv[])
{
/*Gtk::Main kit(argc, argv);

HelloWorld helloworld;
//Shows the window and returns when it is closed.
Gtk::Main::run(helloworld);*/

Cliente cliente("127.0.0.1");
	while(true)
	{
		Word palavra;
		palavra = cliente.ouveConexao();
		std::string aux;
        aux = palavra.getCommand();
        std::transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
		aux.erase(std::remove_if(aux.begin(), aux.end(),
						 &IsUnexpectedCharacters), aux.end());
		if(aux.compare(u_sendM))
		{
			
		}
		else if(aux.compare(g_sendM))
		{
			
		}
		else if(aux.compare(erro))
		{
			
		}
	}
	return 0;
}