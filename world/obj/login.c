#include <login.h>

#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;
inherit F_ENCODING;

void logon()
{
	call_out( "time_out", LOGIN_TIMEOUT );
	LOGIN_D->logon( this_object() );
}

// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
void net_dead()
{
	remove_call_out("time_out");
	call_out( "time_out", 1 );
}

void time_out()
{
        object ob,*body;
	string name;
	int i;
	if( objectp(query_temp("body_ob")) ) return;
	if( interactive(this_object()) )
		write("您花在连线进入手续的时间太久了，下次想好再来吧。\n");
//added by mon 3/12/97
        body=children(USER_OB);
	name=getuid(this_object());
	i=sizeof(body);
	while(i--) { // remove all duplicate copies.
	  ob=body[i];
	  if(clonep(ob)&&getuid(ob)==name
	    &&ob->query("max_gin")==0) {
	      destruct(ob);
            }
        }
	destruct(this_object());
}

// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
	string id;

	id = query("id", 1);
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}

void receive_message(string type, string str)
{
	if( type!= "write" ) return;
	
	str = CONVERT_D->output(str,this_object());

	receive(str);
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
}

// Protect login object's data against hackers.
nomask mixed set(string prop, mixed data)
{
        if(prop=="last_on" || prop=="last_from")
	    if(previous_object()->query_temp("link_ob")==this_object())
		return ::set(prop, data);
	// allow save last login data when a player disconnected.
	// mon 5/7/98

	if( geteuid(previous_object()) != ROOT_UID ) return 0;
	return ::set(prop, data);
}
