// standard home for players.
// by mon. 3/3/97

#include <ansi.h>
inherit ROOM;
inherit F_SAVE;

string *special_props = ({
	"short","long"});

int save_room();
int save_room_file(string yn,string file,string str);
int do_bed();

void create()
{
     set("short", "标准新房");
     set("long", @LONG

一切都设置好了，只等一些室内装修。 
LONG
     );
     set("valid_startroom",1);
     set("exits", ([
		"out": "/d/changan/phomes",
         ]));
     seteuid(getuid());
     setup();

}

void init()
{
	object me=this_player(), env=environment(me);
	string id,*home_host,*home_guest;

	id=(me->parse_command_id_list())[0];
	home_host=env->query("home_host");
	home_guest=env->query("home_guest");

	if (member_array(id,home_host)==-1
	    && member_array(id,home_guest)==-1) {
		tell_object(me, "啊哈！ 闯进来了！\n");
                tell_object(me, "某某飞起一脚，正好踢中你的屁股 。  \n");
                tell_object(me, "某某飞起一脚，正好踢中你的屁股 。  \n");
                me->move("/d/changan/phomes");
                message_vision("$N似乎被人一脚踢了出来，神色有点狼狈。\n", me);
	}
	add_action("do_bed", "gosleep");
	add_action("do_bed", "gobed" );
	add_action("do_bed", "bed");
        add_action("save_room","savehome");
}

int do_bed()
{       object me,env;
        string home_name;
        me=this_player();
	env=environment(me);
	home_name=file_name(env);
      	
	if(home_name) {
	  message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
  	  me->move(home_name+"_bed.c");
          message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
	  } else {
	  write("Can't find home_name! Tell a wiz please.\n");
	  }
        
        return 1;
}

string query_save_file()
{    string file;
     int i;
     file=file_name();
     write(file+"\n");
     i=strlen(file)-1;
     while((i>0)&&(file[i]!='/')) i--;
     if(i>0) {
       file=replace_string(file,file[0..i],"");
     }
     write(file+"\n");
     return DATA_DIR+"playerhomes/"+file;
}

int save_room()
{
	object env;
	string str, *name, file;
	mapping prop;
	int i;

	env = environment(this_player());
	file = file_name(env)+".c";
	str = "// Player home: " + file + @ROOM_CODE

inherit "/d/changan/playerhomes/home.c";

void create()
{
     ::create();
ROOM_CODE
	;
	str += sprintf("\tset(\"short\", %O);\n", env->query("short") );
	str += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", env->query("long") );
	prop = env->query_entire_dbase();
	name = keys(prop);
	for(i=0; i<sizeof(name); i++) {
		if( member_array(name[i], special_props)!=-1 ) continue;
		str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]] );
	}
	str += "\n\tsetup();\n";

	if( file_size(file)!=-1 ) {
		write("档案 " + file + " 已存在，要删除旧档吗？[y/n]");
		input_to("save_room_file", file, str);
		return 1;
	}

	return save_room_file("y", file, str);
}

int save_room_file(string yn, string file, string str)
{
	if( strlen(yn)<1 || yn[0]!='y' ) return 1;

        file="/data/playerhomes/h_mon.c";
//	rm(file);
	write("存档 " + file + "．．．．．\n");
//	if( write_file(file, str) ) {
	if( save() ) {
		write("Ok.\n");
		return 1;
	} else {
		write("你没有写入这个档案(" + file + ")的权利。\n");
                return 0;
        }
}

