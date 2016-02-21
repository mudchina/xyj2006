// monitord.c
// by snowcat 6/20/97

#pragma optimize

#include <ansi.h>

inherit F_DBASE;

void create()
{
	seteuid(getuid());
	set("name", "¼à¿Ø¾«Áé");
	set("id", "monitord");
}

void report_system_msg (string msg)
{
	CHANNEL_D->do_channel(this_object(), "sys", msg);
	log_file("monitord","["+ctime(time())+"] "+msg+"\n");
}

void report_system_object_msg (object ob, string msg)
{
	CHANNEL_D->do_channel(this_object(), "sys",
		ob->name() + "(" + capitalize(ob->query("id")) + ")" + msg);
	log_file("monitord","["+ctime(time())+"] "+
	  ob->name()+"("+capitalize(ob->query("id"))+")"+msg+"\n");
}
