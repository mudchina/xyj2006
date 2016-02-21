//take make it for CS ...1/30/2002.
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIR"CS休息室"NOR);
  set ("long", @long
  
  这里是ｃｓ大赛的休息室，大赛选手可以使用hp,skills,score,
指令察看自己的状态，以及使用chat聊天，如果需要武器和装备可
以使用list,yao指令索取自己需要的武器和装备。

long );

  set("exits", ([ /* sizeof() == 2 */

]));
        set("objects", 
        ([ //sizeof() == 1
     "/u/take/vikee" : 1,
        ]));

 set("outdoors", 1);

  setup();
}

void init()
{
	object ob;
        ob = this_player();
          add_action("block_cmd", "",1);
	call_out("greeting", 2, ob);
}

int block_cmd(string args)
{
         string verb,a,b;
	verb = query_verb();
         if ((verb == "chat") || (verb == "chat*") || (verb == "score") || (verb == "hp") || (verb == "skills") || (verb == "list") || (verb == "yao") || (wizardp(this_player()))) return 0;
	return 1;
}

void greeting(object ob)
{
          if( !ob||!userp(ob) ) return;
	        if (present("corpse"))
	        destruct (present("corpse"));
	        ob->set("eff_kee",ob->query("max_kee"));
                ob->set("eff_sen",ob->query("max_sen"));
                ob->set("kee",ob->query("max_kee"));
                ob->set("sen",ob->query("max_sen"));
                ob->set("force",ob->query("max_force"));
                ob->set("mana",ob->query("max_mana"));
}





