/*
  www/cgi-bin/board_h.c
  Created by Ammy@YSZZ
  2001/04/13
 */ 

#include <ansi.h>
#include <mudlib.h>


inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;
//inherit F_REMOVEANSI

string short();
string query_save_file();
string query_master();
string query_last_time();
void setup();

private mapping notes;

string gateway(string board,string flag) 
{
	string ret;
	set("board_id",board);
        setup();
 	if (flag=="num") {
 		ret=short();
 		return ret;}
 	if (flag=="master"){
 		ret=query_master();
 		return ret;}	
 	//if (flag="time"){
 		//ret=query_last_time();
 		//return ret;}			
        
}	

void create() {
        seteuid( geteuid() );
}

string query_save_file()
{
        string id;
        if( !stringp(id = query("board_id")) ) return 0;
        return DATA_DIR + "board/" + id;
}

void setup() {
        if( restore() )
                notes = query("notes");
        else
                notes = ([]);
}

string short()
{
        if( !pointerp(notes) || !sizeof(notes) )
                return "没有任何留言";
        return sprintf("共 %d 张留言", sizeof(notes) );
}

string query_master()
{
       	string master;
        if( master=query("master") )
                return sprintf("<a href=finger?id=%s>%s</a>",lower_case(master),master);
        else
                return "徵求中";
}

string query_last_time()
{
	string msg,time,time1,time2;
	int i,timet;
	i=sizeof(notes)-1;
	timet=notes[i]["time"]+30120;
//因为服务器有时间偏差，此处加以修正	
	time=ctime(timet);
//	time1=ctime(notes[i]["time"])[0..9];
//	time2=ctime(notes[i]["time"])[10..-1];
//	msg=time1+"<br>"+time2;
	msg=time;
	return msg;
}	