//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "海藏");
set("long", @LONG
    
空荡荡的海藏中直立着一根铁柱子，金光闪闪
照得人睁不开眼。
LONG );


set("exits", ([
  "up"   : "/d/changan/eastseashore",
]));



set("objects", ([
  "/d/sea/npc/shuishen" : 1,
]));




setup();
}

void init() {
  object* jingubang;
  object shentie;
  if (present("shen tie",this_object())) return;
  jingubang=children(__DIR__"obj/jingubang");
//  write((string)sizeof(jingubang)+"\n");

  if (sizeof(jingubang)>1) return;
  shentie=new(__DIR__"obj/shentie");
  shentie->move(this_object());
}

int valid_leave(object me, string dir)
{
  object wang;
  string weapon,weapon_id;

  weapon = this_player()->query_temp("weapon");
  if (weapon)  weapon_id=weapon->query("id");

  if(this_player()->query("dntg/donghai")=="hua gan ji" && weapon_id=="jin gu bang")
  {
   wang = new (__DIR__"npc/announcer");
   wang->announce_success (this_player());
   message_vision("$N手持金箍棒向上一纵，一股巨浪随着$N冲天而起。\n",this_player());
  }
  return ::valid_leave(me, dir);
}

