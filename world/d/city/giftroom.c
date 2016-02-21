inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create ()
{
  set ("short", "土地庙");
  set ("long", @LONG

这里是供奉土地的地方，土地爷正笑眯眯的看着你。
江湖传闻这里可以创建帮派，但究竟怎么创建就不
得而知了。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kezhan",
]));
   set("chat_room",1);
  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/zaoshen" : 1,
//"/d/wiz/obj/vote_ban" : 1,
"/d/city/npc/huangfeihong.c" : 1,
]));

   set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);
 setup();




}

void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    return 0;
}

int valid_leave(object me, string dir)
{

        if ( !me->query("wizgift/newbiegift") )
           tell_object(me, "你对灶王爷说道：“我还是下次再来领吧！\n 灶王爷点了点头。\n");

        return ::valid_leave(me, dir);
}

